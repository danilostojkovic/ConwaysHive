#include "controller.h"

Controller::Controller(QObject *parent) : QObject(parent), partita(new Game(11, 16)), startingState(std::vector<std::pair<int, int>>())
{

}

void Controller::changeCellState(int index, int newState) const
{
    partita->setCellState(index, newState);
}

int Controller::getCellState(int index) const
{
    return partita->getCellState(index);
}

void Controller::next() const
{
    partita->playTurn();
}

bool Controller::playPause() const
{
    return partita->pause();
}

void Controller::restart() const
{
    partita->clear();
    for(auto i=startingState.begin(); i<startingState.end(); i++)
        partita->setCellState((*i).first, (*i).second);
}

void Controller::clear()
{
    startingState=std::vector<std::pair<int, int>>();
    partita->clear();
}

std::vector<std::pair<int, int> > Controller::getGameState() const
{
    return partita->getState();
}

void Controller::updateStartingState()
{
    if(startingState.size()==0)
        startingState=getGameState();
}

int Controller::countHoney() const
{
    return partita->countAllTheHoney();
}

int Controller::getTurn() const
{
    return partita->turn;
}

std::string Controller::getMainStatOf(int index) const
{
    return partita->getStatOf(index);
}

std::vector<int> Controller::getNumbersOf() const
{
    return partita->getNumersOfInsects();
}
