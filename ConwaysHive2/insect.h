#ifndef INSECT_H
#define INSECT_H

#include <utility>
#include <vector>
#include <math.h>
#include "cell.h"
#include "Swarm.cpp"
#include <string>

class Insect
{
protected:
    int age;
    int cellIndex;
public:
    Insect(int index);
    virtual ~Insect()=default;
    virtual bool operator==(const Insect&) const;
    int getIndex() const;
    virtual void play(std::vector<Cell*>, Swarm<DeepPtr<Insect>>*)=0; //metodo virtuale puro ---> Insect classe astratta
    virtual std::string getMainStat() const=0;
};

#endif // INSECT_H
