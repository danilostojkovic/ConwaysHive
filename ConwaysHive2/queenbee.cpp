#include "queenbee.h"

QueenBee::QueenBee(int index):Bee(index), beesBirthed(0), TurnsSinceLastChildBirth(0) { }
int QueenBee::getBeesBirthed() const{
    return beesBirthed;
}
bool QueenBee::operator==(const QueenBee& q) const{
    return Insect::operator==(q)&&beesBirthed==q.beesBirthed;
}

void QueenBee::play(std::vector<Cell*> grid, Swarm<DeepPtr<Insect>>* s)
{
    if(TurnsSinceLastChildBirth++%5==0){
        std::vector<int>* pos=Cell::getAdjacentCells(cellIndex);
        std::vector<int> o={Cell::IS_FREE, Cell::HAS_HONEY};
        for(int k=0; k<(int)o.size(); k++){
            for(auto i=pos->begin(); i<pos->end(); i++){
                if(grid[*i]->isFree(o[k])){
                    Larva* offspring=new Larva(*i);
                    grid[offspring->getIndex()]->changeState(Larva::ID);
                    s->insert(new DeepPtr<Insect>(offspring));
                    beesBirthed++;
                    return;
                }
            }
        }
    }
}

std::string QueenBee::getMainStat() const
{
    std::string ret="this queen bee has given birth to ";
    ret+=std::to_string(beesBirthed);
    ret+=" bees";
    return ret;
}


