#ifndef HIVEBEETLE_H
#define HIVEBEETLE_H

#include "insect.h"

class HiveBeetle : public Insect
{
private:
    int honeyEaten;
public:
    HiveBeetle(int index);
    int getHoneyEaten() const;
    bool operator==(const HiveBeetle&) const;
    void play(std::vector<Cell*>, Swarm<DeepPtr<Insect>>*) override;
    static const int ID=3;
    std::string getMainStat() const override;
};

#endif // HIVEBEETLE_H
