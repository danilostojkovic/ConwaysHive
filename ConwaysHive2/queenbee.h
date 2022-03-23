#ifndef QUEENBEE_H
#define QUEENBEE_H

#include "larva.h"

class QueenBee : public Bee
{
private:
    int beesBirthed;
    int TurnsSinceLastChildBirth;
public:
    QueenBee(int index);
    int getBeesBirthed() const;
    bool operator==(const QueenBee&) const;
    void play(std::vector<Cell*>, Swarm<DeepPtr<Insect>>*) override;
    static const int ID=1;
    std::string getMainStat() const override;
};

#endif // QUEENBEE_H
