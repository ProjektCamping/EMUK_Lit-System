#include "Table.h"

Table::Table(/* args */)
{

//TODO: Following Block is not dynamic!!! Change to an dynamic solution 
    stems[FrontLeft] = new Stem(2,0,FrontLeft);
    stems[FrontRight] = new Stem(4,16,FrontRight);
    stems[BackLeft] = new Stem(17,5,BackLeft);
    stems[BackRight] = new Stem(18,19,BackRight);

}

Table::~Table()
{
}



void Table::driveAllUP(short t_ms){
    for(int i = 0;i< NUM_OF_STEMS;i++){
        stems[i]->driveUp();
    }
    delay(t_ms);
        for(int i = 0;i< NUM_OF_STEMS;i++){
        stems[i]->driveSTOP();
    }
}


void Table::driveAllDOWN(short t_ms){
    for(int i = 0;i< NUM_OF_STEMS;i++){
        stems[i]->driveDown();
    }
    delay(t_ms);
        for(int i = 0;i< NUM_OF_STEMS;i++){
        stems[i]->driveSTOP();
    }
}

   void Table::driveStemUP4(Stem_Pos pos, short t_ms){
    stems[pos]->driveUp4(t_ms);
   }
   void Table::driveStemDOWN4(Stem_Pos pos,short t_ms){
    stems[pos]->driveDown4(t_ms); 
   }