#include <Arduino.h>


#define DRIVE_TIME_COMP 500 //ms
#define INPROGRESS_PIN 14

enum Stem_Status{
    undefinded, 
    bottom, 
    top,
    moving
};

enum Stem_Pos{
    FrontLeft, 
    FrontRight, 
    BackLeft,
    BackRight
};

class Stem
{
private:
    bool inProgress;
    unsigned UP_PIN;
    unsigned DOWN_PIN;
    int drivenTime;
    Stem_Status status = undefinded;
    Stem_Pos stemPos;
    void setProgressStatus(bool st);

    
    
public:
    Stem(unsigned uppin, unsigned downpin, Stem_Pos pos);
    void driveUp4(int t_ms);
    void driveDown4(int t_ms);

    void driveUp();
    void driveDown();
    void driveSTOP();



    ~Stem();
};

