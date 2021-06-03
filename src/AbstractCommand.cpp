#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


class AbstractCommand
{
    public:
    
        virtual bool application() = 0;
        virtual void resolveIssue() = 0;

        void initialize(bool g)              //initialization
        {
            go = g;                 //go
        }
        bool executed(bool s)
        {
            //finds where application finishes by stopping on finish condition
            go = !s;                //stop
        }
        bool errorChecker(bool c)
        {
            check = c;              //checks for error
                                    //error if true
                                    //initialized false (no error at beginning)
        }

    
    protected:
    
        bool go;
        bool check;
        int errorType;
    
};


class ExtLinAct: public AbstractCommand
{

    public:

                                        //will not recognize as function until
                                        //public brackets are established due to inheritance
        bool application()                   
        {
            
            if(go)
            {
                //input conditions to be met
                /*if(LinActPos != MAX)
                {
                    cout << "ExtLinAct is being applied\n\n" << endl;
                    LinActPos = Max;
                    LinActPosMsg.data = LinActPos;
                    Publisher.publish(LinActPosMsg);
                }*/
            }
            if(!go) //&& LinActPos == MAX)
            {
                //conditions have been met
                cout << "ExtLinAct has been executed\n\n" << endl;

            }
            if(!go) //&& LinActPos != MAX) 
                    //if an error occurs, check becomes true
                    //errorType becomes uniquely identified by an int
            {
                check = true;
                errorType = 1;
            }
            
        }

        void resolveIssue()
        {
            if(errorType == 1)              //buffers out other errors
            {
                //LinActPos = Max;          //resolves the issue

                check = false;              //resets the checker to find more
                                            //unique errors
            }
        }   
};

int main(void)
{
    ExtLinAct ela;

    ela.errorChecker(false);        //initializing error checkers

    
    ela.initialize(true);          
    ela.application();              //where errors occur
    ela.executed(true);
    ela.resolveIssue();             //assess errors after each command
}