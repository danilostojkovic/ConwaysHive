#ifndef WASP_H
#define WASP_H

#include "insect.h"

class Wasp : public Insect
{
private:
    int beesKilled;
    int lastMove;
public:
    Wasp(int index);
    int getBeesKilled() const;
    bool operator==(const Wasp&) const;
    void play(std::vector<Cell*>, Swarm<DeepPtr<Insect>>*) override;
    static const int ID=4;
    std::string getMainStat() const override;
};

#endif // WASP_H
