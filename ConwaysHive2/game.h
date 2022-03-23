#ifndef GAME_H
#define GAME_H

#include <vector>

#include "insect.h"
#include "cell.h"
#include "honeybee.h"
#include "queenbee.h"
#include "larva.h"
#include "hivebeetle.h"
#include "wasp.h"

class Game
{
private:
    bool isPaused;
public:
    bool queenPresent;
    int turn, height, width;
    Swarm<DeepPtr<Insect>> s;
    std::vector<Cell*> grid;
    Game(int h, int w);
    void addInsect(Insect*);
    void removeInsectAt(int index);
    void setCellState(int index, int newState);     //può lanciare l'errore: regina presente
    int getCellState(int index) const;
    bool pause();
    void clear();
    void playTurn();
    std::vector<std::pair<int, int>> getState() const;
    int countAllTheHoney() const;
    std::string getStatOf(int index) const;
    std::vector<int> getNumersOfInsects() const;
};

#endif // GAME_H
