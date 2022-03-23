#ifndef CELL_H
#define CELL_H

#include <vector>
#include <math.h>
#include "deepptr.cpp"

class Cell
{
public:
    int state;
    bool hasHoney;

    static const int IS_FREE=0;
    static const int IS_FREE_OR_HAS_HONEY=1;
    static const int HAS_HONEY=2;
    static const int HAS_BEE=3;

    static const int FREE_CELL_ID=5;
    static const int HONEY_CELL_ID=6;

    Cell();
    bool isFree(int) const;
    void changeState(int selected);
    static std::vector<int>* getAdjacentCells(int i);
};

#endif // CELL_H
