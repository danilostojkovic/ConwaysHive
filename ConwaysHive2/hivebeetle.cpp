#include "hivebeetle.h"

HiveBeetle::HiveBeetle(int index) : Insect(index), honeyEaten(0) { }
int HiveBeetle::getHoneyEaten() const{
    return honeyEaten;
}
bool HiveBeetle::operator==(const HiveBeetle& h) const{
    return Insect::operator==(h) && honeyEaten==h.honeyEaten;
}

void HiveBeetle::play(std::vector<Cell*> grid, Swarm<DeepPtr<Insect>>*)
{
    int newIndex=-1, stop=0;
    std::vector<int> o={Cell::HAS_HONEY, Cell::IS_FREE};
    std::vector<int>* pos=Cell::getAdjacentCells(cellIndex);
    for(int i=0; i<(int)o.size() && newIndex==-1; i++)
        for(auto k=pos->begin(); k<pos->end()&&newIndex==-1; k++)
            if(grid[*k]->isFree(o[i])){
                newIndex=*k;
                stop=i;
            }
    if(o[stop]==Cell::HAS_HONEY)
        honeyEaten++;
    if(newIndex!=-1){
        grid[cellIndex]->changeState(Cell::FREE_CELL_ID);
        cellIndex=newIndex;
        grid[cellIndex]->changeState(HiveBeetle::ID);
    }
}

std::string HiveBeetle::getMainStat() const
{
    std::string ret="this hivebeetle has eaten ";
    ret+=std::to_string(honeyEaten);
    ret+=" units of honey";
    return ret;
}
