#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


class AbstractCommand
{
    public:

        void runAutoCommand()
        {
            int commandID = 1;

            if(!done)
            {
                command = commandID;
            }

            else
            {
                commandID++;
                done = false;
            }

            if(commandID > numCommands)
            {
                ROS_INFO("\n\nThere are no remaining commands to perform. 
                \n\nUse ctrl+c to kill this node.");
            }
        }

        int commandCount()
        {

        }

        void runManualCommand();
        {

        }

        int solveProblem()
        {
            
            if(problem == 1)
            {
                control = manual;
            }
            else if(problem == 2)
            {
                control = autonomous;
            }
            else if(problem == 3)
            {
                ROS_INFO("\n\nAn error requiring system shutdown has occurred.
                \n\nUse ctrl+c to kill this node.");
            }
        }

        //initializations
        bool manual = true;
        bool autonomous = false;
        bool done = false; 

        //variables for manipulating commands
        bool control;
        int problem, command;

}

class FirstCommand: public AbstractCommand
{

    public:

        int FirstCommand()                   
        {   
            
            if(command == 1)            //checks for command being run
            {
                //first publish relevent motor values until success


                //then continue executing the command line in order once successful
                if()
                done = true;        `   //lets command number increment
            }
        }


        
};