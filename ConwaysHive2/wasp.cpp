#include "wasp.h"
#include <iostream>

Wasp::Wasp(int index) : Insect(index), beesKilled(0), lastMove(0) { }

int Wasp::getBeesKilled() const{
    return beesKilled;
}
bool Wasp::operator==(const Wasp & w) const{
    return Insect::operator==(w)&&beesKilled==w.beesKilled;
}

void Wasp::play(std::vector<Cell*> grid, Swarm<DeepPtr<Insect>>* s)
{
    lastMove=(lastMove+1)%5;
    int newIndex=-1, stop=0;
    std::vector<int> o={Cell::HAS_BEE, Cell::IS_FREE_OR_HAS_HONEY};
    std::vector<int>* pos=Cell::getAdjacentCells(cellIndex);
    std::cout<<pos->size()<<std::endl;
    for(int i=0; i<(int)o.size() && newIndex==-1; i++){
        for(int k=lastMove; k<static_cast<int>(pos->size())&&newIndex==-1; k++)
            if(grid[(*pos)[k]]->isFree(o[i])){
                newIndex=(*pos)[k];
                stop=i;
            }
        for(int k=0; k<lastMove&&newIndex==-1; k++)
            if(grid[(*pos)[k]]->isFree(o[i])){
                newIndex=(*pos)[k];
                stop=i;
            }
    }
    std::cout<<newIndex<<std::endl;
    if(newIndex!=-1){
        if(o[stop]==Cell::HAS_BEE){
            beesKilled++;
            for(auto i=s->begin(); i!=s->end(); i++)
                if(i->info->getIndex()==newIndex)
                    s->remove(*i);
        }
        grid[cellIndex]->changeState(Cell::FREE_CELL_ID + static_cast<int>(grid[cellIndex]->hasHoney));
        cellIndex=newIndex;
        grid[cellIndex]->changeState(Wasp::ID);
    }
}

std::string Wasp::getMainStat() const
{
    std::string ret="this wasp has killed ";
    ret+=std::to_string(beesKilled);
    ret+=" bees";
    return ret;
}


