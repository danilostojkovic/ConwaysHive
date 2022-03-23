#ifndef HONEYBEE_H
#define HONEYBEE_H

#include "bee.h"

class HoneyBee : public Bee
{
private:
    int honeyMade;
public:
    HoneyBee(int index);
    void play(std::vector<Cell*>, Swarm<DeepPtr<Insect>>*) override;
    int getHoneyMade() const;
    bool operator==(const HoneyBee&) const;
    static const int ID=0;
    std::string getMainStat() const override;
};

#endif // HONEYBEE_H
