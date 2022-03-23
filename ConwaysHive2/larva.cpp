#include "larva.h"

Larva::Larva(int index):Bee(index), turnsSinceBirth(0) { }

void Larva::play(std::vector<Cell*> grid, Swarm<DeepPtr<Insect>>* s)
{
    if(turnsSinceBirth++==2){
        HoneyBee* hb=new HoneyBee(cellIndex);
        for(auto i=s->begin(); i!=s->end(); i++)
            if(i->info->getIndex()==cellIndex)
                s->remove(*i);
        grid[cellIndex]->changeState(HoneyBee::ID);
        s->insert(new DeepPtr<Insect>(hb));
    }
}

std::string Larva::getMainStat() const
{
    std::string ret="this larva has been alive for ";
    ret+=std::to_string(turnsSinceBirth);
    ret+=" turns";
    return ret;
}
