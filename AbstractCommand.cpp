#include <stdio.h>
#include <stdlib.h>

class AbstractCommand

    public:
    {
        virtual bool application() = 0;
        virtual void onFinish() = 0;
        virtual void interrupt() = 0;

        void initialize(bool g)              //initialization
        {
            go = g;
        }
        bool executed(bool s)
        {
            //finds where application finishes by stopping on finish condition
            go = !s;
        }
        void whenFinished(float r)
        {
            reset = r;
        }
        void interrupt(int e)
        {
            error = e;
        }

    protected:
    {
        bool go;
        bool stop;
        float reset;
        int error;
    }
class ExtLinAct: public AbstractCommand
{

    public:

                                        //will not recognize as function until
    {                                   //class brackets are established
        bool application()                   
        {
            if(go)
            {
                //input conditions to be met
                if(LinActPos != MAX)
                {
                    cout << "ExtLinAct is being applied\n\n" << endl;
                    LinActPos = Max;
                    LinActPosMsg.data = LinActPos;
                    Publisher.publish(LinActPosMsg);
                }
            }
            if(!go)
            {
                //conditions have been met
                cout << "ExtLinAct has been executed\n\n" << endl

            }
        }
        void whenFinished()
        {

        }
    }
}



int main(void)
{


    ExtLinAct ela;

    
    ela.initialize(true);
    ela.application();
    ela.executed(true);

    



}