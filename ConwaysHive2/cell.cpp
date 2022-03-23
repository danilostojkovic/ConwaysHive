#include "cell.h"

Cell::Cell():state(5), hasHoney(false){
}

void Cell::changeState(int selected){
    state=selected;
    if(selected==6)
        hasHoney=true;
    else if(selected==3)
        hasHoney=false;
}

std::vector<int>* Cell::getAdjacentCells(int i)
{
    std::vector<int>* pos=new std::vector<int>();
    int a=std::floor(i/16);
    if(a%2==0){
        if(i%16!=0)
            pos->push_back(i-1);
        if(i%16!=0&&i>16)
            pos->push_back(i-17);
        if(i>16)
            pos->push_back(i-16);
        if((i+1)%16!=0)
            pos->push_back(i+1);
        if(i<10*16)
            pos->push_back(i+16);
        if(i%16!=0&&i<10*16)
            pos->push_back(i+15);
    }
    else{
        if(i%16!=0)
            pos->push_back(i-1);
        pos->push_back(i-16);
        if((i+1)%16!=0){
            pos->push_back(i-15);
            pos->push_back(i+1);
            pos->push_back(i+17);
        }
        pos->push_back(i+16);
    }
    return pos;
}

bool Cell::isFree(int sel) const{
    switch(sel){
        case IS_FREE: return state==5; break;                         //sel=0 -> se è libera
        case IS_FREE_OR_HAS_HONEY: return state==5||state==6; break;  //sel=1 -> se è libera o ha miele
        case HAS_HONEY: return state==6; break;                       //sel=2 -> se ha miele
        default: return state==0; break;                              //sel=3 -> se ha un'ape
    }
}
