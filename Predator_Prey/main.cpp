#include "colony.h"

int main()
{
//    Colony Exodus(27,40); //optimum screen size
    srand(time(NULL)); //libraries included in grid.h
    Colony Exodus(30,40);
    Exodus.randomize();
    Exodus.buildWalls();
    Exodus.print();

    bool done = false;
    while(!done) {
        cin.get();
        Exodus.mainPhase();
        Exodus.print();
    }
    return 0;
}

