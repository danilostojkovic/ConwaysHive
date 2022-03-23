#include "game.h"

Game::Game(int h, int w): isPaused(true), queenPresent(false),turn(0), height(h), width(w), s(Swarm<DeepPtr<Insect>>())
{
    for(int i=0; i<h*w; i++)
        grid.push_back(new Cell());
}

void Game::addInsect(Insect* a){
    s.insert(new DeepPtr<Insect>(a));
}

void Game::removeInsectAt(int index){
    for(auto i=s.begin(); i!=s.end(); i++)
        if(i->info->getIndex()==index)
            s.remove(*i);
}

void Game::setCellState(int index, int newState)
{
    if(isPaused&&turn==0){
        if(grid[index]->state==Cell::FREE_CELL_ID){
            if(newState==QueenBee::ID){
                if(queenPresent)
                    throw 1;
                queenPresent=true;
            }
            switch(newState){
                case HoneyBee::ID: addInsect(new HoneyBee(index)); break;
                case QueenBee::ID: addInsect(new QueenBee(index)); break;
                case Larva::ID: addInsect(new Larva(index)); break;
                case HiveBeetle::ID: addInsect(new HiveBeetle(index)); break;
                case Wasp::ID: addInsect(new Wasp(index)); break;
            }
            grid[index]->changeState(newState);
        }
        else{
            if(grid[index]->state==QueenBee::ID)
                queenPresent=false;
            grid[index]->changeState(Cell::FREE_CELL_ID);
            removeInsectAt(index);
        }
    }
}

int Game::getCellState(int index) const
{
    return grid[index]->state;
}

bool Game::pause()
{
    return isPaused=!isPaused;
}

void Game::clear()
{
    turn=0;
    for(int i=0; i<(int)grid.size(); i++)
        setCellState(i, Cell::FREE_CELL_ID);
}

void Game::playTurn()
{
    turn++;
    for(auto i=s.begin(); i!=s.end(); i++)
        (*i)->info->play(grid, &s);
}

std::vector<std::pair<int, int>> Game::getState() const
{
    std::vector<std::pair<int, int>> daRet;
    for(int i=0; i<(int)grid.size(); i++)
        daRet.push_back(std::pair<int,int>(i, grid[i]->state));
    return daRet;
}

int Game::countAllTheHoney() const
{
    int tot=0;
    for(auto i=s.begin(); i!=s.end(); i++){
        if(HoneyBee* b=dynamic_cast<HoneyBee*>(&(*i->info)))
            tot+=b->getHoneyMade();
        else if(HiveBeetle* h=dynamic_cast<HiveBeetle*>(&(*i->info)))
            tot-=h->getHoneyEaten();
    }
    return tot;
}

std::string Game::getStatOf(int index) const
{
    for(auto i=s.begin(); i!=s.end(); i++)
        if(i->info->getIndex()==index)
            return (*i)->info->getMainStat();
    return "";
}

std::vector<int> Game::getNumersOfInsects() const
{
    std::vector<int> numb={0,0,0,0};
    for(auto i=s.begin(); i!=s.end(); i++){
        Insect *ins=i->info;
        if(typeid(*ins)==typeid(Larva))
            numb[1]++;
        else if(Bee* b=dynamic_cast<Bee*>(ins))
            numb[0]++;
        else if(typeid(*ins)==typeid(HiveBeetle))
            numb[2]++;
        else if(typeid(*ins)==typeid(Wasp))
            numb[3]++;
    }
    return numb;
}

