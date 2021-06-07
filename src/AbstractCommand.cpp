#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


class AbstractCommand
{
    public:
    
        virtual bool application() = 0;
        virtual void resolveIssue() = 0;

        void initialize(bool g)              //initialization logice
        {
            go = g;                          //tells application to go or not
        }
        bool executed(bool s)
        {
                                             //finds where application finishes by 
                                             //stopping it on the finish condition

            go = !s;                         //tells application to not go if stop
        }
        bool errorChecker(bool c)
        {
            check = c;                       //checks for errors
                                             //error if true
                                             //initialized false (no error at beginning)
        }
        int errorTyper(bool t)
        {
            errorType = t;
        }
        int numError(int n)
        {
            numErrors = n;
        }
    
    
    
        bool go;                             //variables to be modified by all classes
        bool check;                          //that inherit AbstractCommand
        int errorType;
        int numErrors;
    
};


class ExampleCommand: public AbstractCommand
{

    public:

                                        //will not recognize this as pure vital function 
                                        // until inheritance is established
        bool application()                   
        {
            
            if(go)
            {
                //input conditions to be met
                /*if(Goal_of_Application != satisfied)
                {
                    cout << "Example Command is being applied\n\n" << endl;
                    Goal_of_Application = satisfied;
                    satisfiedMsg.data = satisfied;
                    ExamplePublisher.publish(satisfiedMsg);
                }*/
            }
            if(!go && !check) 
            {
                //conditions have been met
                cout << "ExtLinAct has been executed\n\n" << endl;

            }
            

            //specific error case 1
            if(!go) //&& Goal_of_Application != satisfied) 
                    //if an error occurs, check becomes true
                    //errorType becomes uniquely identified by an int
            {
                check = true;
                errorType = 1;
            }
            
        }

        void resolveIssue()
        {
            if(check)                           //if error(s) occurred
            {
                if(errorType == 1)              //buffers out other errors
                {
                    //Goal = satisfied;          //resolves the issue(s)
                    //Goal2 = satisfied;

                                 
                }

                check = false;                  //after all error types are resolve,
                                                //reset checker for next application
            }
        }   
};

int main()
{
    ExampleCommand ExCmd;                  //list of class instances

    ExCmd.errorChecker(false);        //list of initializing error checkers
                                    //*can be a list since each time resolveIssue is 
                                    //instantiated it chooses the correct command 
                                    // resolution; (this is accomplished by the errorType 
                                    // set in the application's instance and the check in
                                    //each resolveIssue instance)

    
    //command process*******************************************************************
    ExCmd.initialize(true);         //sets go to true
    ExCmd.application();            //runs logic of application function
    
    if(ExCmd.errorChecker(true))                 //resolves only if error(s) detected
    {
        ExCmd.resolveIssue();           //checks for and resolves the issues
                                        //(check = false)
        ExCmd.application();            //retry application without issues 


                                //*************************************
                                // it may be necessary at sometime to
                                // resolve the issue by abandoning it 
                                // temporarily, or by initiating manual 
                                // control (not functional in current
                                // state)
                                //*************************************
    };

    ExCmd.numError(ExCmd.errorType);
    ExCmd.executed(true);                         //tells the application to stop after
                                                  //a good run (go = false)
    ExCmd.application();                          //exits application with !check &&
                                                  //!go 
};                              
    //**********************************************************************************
    
