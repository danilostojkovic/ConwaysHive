#ifndef LARVA_H
#define LARVA_H

#include "honeybee.h"

class Larva : public Bee
{
private:
    int turnsSinceBirth;
public:
    Larva(int index);
    void play(std::vector<Cell*>, Swarm<DeepPtr<Insect>>*) override;
    static const int ID=2;
    std::string getMainStat() const override;
};

#endif // LARVA_H
