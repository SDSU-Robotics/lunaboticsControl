#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <list>
#include "ros/ros.h"

using namespace std;

class Command
{
    public:
        virtual ~Command(){}
        virtual bool SpecificApplication() = 0;
};

class Initialize : public Command
{
    public:
        ~Initialize(){}
        bool SpecificApplication()
        {
            ROS_INFO("Initialize called");

            // write code to satisfy initialization requirements
            ros::Duration(0.5).sleep();         // placeholder time constant to show
                                                // time elapse between beginning and end
                                                // of function call

            ROS_INFO("Initialize completed");
        }
};

class NavToExcavate : public Command
{
    public:
        ~NavToExcavate(){}
        bool SpecificApplication()
        {
            ROS_INFO("NavToExcavate called");

            // write code to satisfy navigation requirements
            ros::Duration(0.5).sleep();         // placeholder time constant to show
                                                // time elapse between beginning and end
                                                // of function call

            ROS_INFO("NavToExcavate completed");
        }
};

class Excavate : public Command
{
    public:
        ~Excavate(){}
        bool SpecificApplication()
        {
            ROS_INFO("Excavate called");

            // write code to satisfy excavation requirements
            ros::Duration(0.5).sleep();         // placeholder time constant to show
                                                // time elapse between beginning and end
                                                // of function call

            ROS_INFO("Excavate completed");
        }
};

class NavToSieve : public Command
{
    public:
        ~NavToSieve(){}
        bool SpecificApplication()
        {
            ROS_INFO("NavToSieve called");

            // write code to satisfy navigation requirements
            ros::Duration(0.5).sleep();         // placeholder time constant to show
                                                // time elapse between beginning and end
                                                // of function call

            ROS_INFO("NavToSieve completed");
        }
};

class Sieve : public Command
{
    public:
        ~Sieve(){}
        bool SpecificApplication()
        {
            ROS_INFO("Sieve called");

            // write code to satisfy material dumping requirements
            ros::Duration(0.5).sleep();         // placeholder time constant to show
                                                // time elapse between beginning and end
                                                // of function call

            ROS_INFO("Sieve completed");
        }
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Autonomy");
    ros::NodeHandle n;
    ros::Rate loop_rate(100);

    std::list<Command*> commands;                   // list of command object pointers

    Initialize *initialize=new Initialize();            // dynamically allocating memory
    NavToExcavate *navtoexcavate=new NavToExcavate();   // for command objects that will
    Excavate *excavate=new Excavate();                  // be pointed to
    NavToSieve *navtosieve=new NavToSieve();
    Sieve *sieve=new Sieve();

    commands.push_back( initialize );               // adding object pointers to the
    commands.push_back( navtoexcavate );            // commands list
    commands.push_back( excavate );
    commands.push_back( navtosieve );
    commands.push_back( sieve );

    while (ros::ok())
    {
        for(std::list<Command*>::iterator itr=commands.begin(); itr!=commands.end();)
        {
            (*itr)->SpecificApplication();          // each iteration will point to
                                                    // the current instance of the 
                                                    // SpecificApplication function
                                                    // until the function terminates

            (*itr)->~Command();                     // destruct the instance of the
                                                    // command when finished

            itr++;              // increment iterator to move onto the next command

            if(itr==commands.end())         // check if at the end of the command cycle
                itr=commands.begin();       // restart the cycle if at the end of cycle
        }
    }

    return 0;
}