#include "Stem.h"

Stem::Stem(unsigned uppin, unsigned downpin, Stem_Pos pos)
{
    this->UP_PIN = uppin;
    this->DOWN_PIN = downpin;
    this->stemPos = pos;
    this->inProgress =  false;

    pinMode(DOWN_PIN, OUTPUT); 
    pinMode(UP_PIN, OUTPUT); 
    pinMode(INPROGRESS_PIN, OUTPUT);
    digitalWrite(UP_PIN, HIGH);
    digitalWrite(DOWN_PIN, HIGH);

}

    void Stem::driveUp4(int t_ms){
    setProgressStatus(true);
        digitalWrite(UP_PIN, LOW);
        delay(t_ms);
        digitalWrite(UP_PIN, HIGH);
    setProgressStatus(false);
    }
    void Stem::driveDown4(int t_ms){
    setProgressStatus(true);
        digitalWrite(DOWN_PIN, LOW);
        delay(t_ms);
        digitalWrite(DOWN_PIN, HIGH);
    setProgressStatus(false);
    }


    void Stem::driveUp(){
        digitalWrite(UP_PIN, LOW);
        setProgressStatus(true);
    }
    void Stem::driveDown(){
        digitalWrite(DOWN_PIN, LOW);
        setProgressStatus(true);
    }
   void Stem::driveSTOP(){
        digitalWrite(UP_PIN, HIGH);
        digitalWrite(DOWN_PIN, HIGH);
        setProgressStatus(false);
   }



void Stem::setProgressStatus(bool st){
    if(st){
        this->inProgress = true;
        digitalWrite(INPROGRESS_PIN, true);
    }else{
        this->inProgress = false;
        digitalWrite(INPROGRESS_PIN, false);
    }

}



Stem::~Stem()
{
}
