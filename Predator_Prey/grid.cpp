#include "grid.h"


grid::grid(): creature(NULL)
{
}

grid::grid(Organism *newCreature) : creature(newCreature)
{
}

void grid::RandomBreed()
{
    if(rand() % 2 == 0) // 0 for Prey, 1 for Predator
        PreyBreed();
    else
        PredatorBreed();
}

void grid::PreyBreed()
{
    if(creature)
        qDebug() << "Error : Hey, there is creature here.\n";
    else
        creature = new Prey;
}

void grid::PredatorBreed()
{
    if(creature)
        qDebug() << "Error : Hey, there is creature here.\n";
    else
        creature = new Predator;
}

void grid::kill()
{
    if(creature) {
        delete creature;
        creature = NULL;
    }
}

bool grid::isOccupied() const { return creature ? true : false;}
void grid::print()
{
    if(creature)
        creature->print();
    else
        cout << "No creature in this cell";
    cout << endl;
}

grid grid::operator<<(grid &from)
{
    from.creature->move(this->creature); //move pointer memory from "from" to "this"
                                        //this-> creature memory will get deleted
    from.creature = NULL;
}

const Organism &grid::operator *()
{
    return *creature;
}

grid::~grid()
{
    delete creature;
}
