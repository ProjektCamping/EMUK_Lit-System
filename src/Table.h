#include "Stem.h"
#define NUM_OF_STEMS 4

class Table
{
private:
    Stem* stems[NUM_OF_STEMS];

public:
    Table(/* args */);

   void driveAllUP(short t_ms);
   void driveAllDOWN(short t_ms);
   void driveStemUP4(Stem_Pos pos, short t_ms);
   void driveStemDOWN4(Stem_Pos pos,short t_ms);
   

    ~Table();
};

