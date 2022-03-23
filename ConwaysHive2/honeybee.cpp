#include "honeybee.h"

HoneyBee::HoneyBee(int index) : Bee(index), honeyMade(0) { }

void HoneyBee::play(std::vector<Cell*> grid, Swarm<DeepPtr<Insect>>*)
{
    int newIndex=-1;
    std::vector<int> o={Cell::IS_FREE, Cell::HAS_HONEY};   //controllo prima se ci sono celle libere e successivamente se ce ne sono con miele
    std::vector<int>* pos=Cell::getAdjacentCells(cellIndex);
    for(int i=0; i<(int)o.size() && newIndex==-1; i++)
        for(auto k=pos->begin(); k<pos->end()&&newIndex==-1; k++)
            if(grid[*k]->isFree(o[i]))
                newIndex=*k;
    if(newIndex!=-1){
        if(!grid[cellIndex]->hasHoney)    //l'ape si è spostata da una cella senza miele -> ha creato nuovo miele
            honeyMade++;
        grid[cellIndex]->changeState(Cell::HONEY_CELL_ID);   //svuoto la cella precedente
        cellIndex=newIndex;
        grid[cellIndex]->changeState(HoneyBee::ID);            //aggiungo un'ape in newIndex
    }
}

int HoneyBee::getHoneyMade() const{
    return honeyMade;
}

bool HoneyBee::operator==(const HoneyBee & h) const{
    return Insect::operator==(h)&&honeyMade==h.honeyMade;
}

std::string HoneyBee::getMainStat() const
{
    std::string ret="this bee has made ";
    ret+=std::to_string(honeyMade);
    ret+=" units of honey";
    return ret;
}
