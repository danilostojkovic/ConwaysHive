#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QTimer>
#include <utility>
#include <vector>

#include "game.h"

class Controller : public QObject
{
    Q_OBJECT
private:
    Game* partita;
public:
    explicit Controller(QObject *parent = nullptr);
    void changeCellState(int index, int newState) const;
    int getCellState(int index) const;
    bool playPause() const;
    void next() const;
    void restart() const;
    void clear();
    std::vector<std::pair<int, int>> getGameState() const;
    std::vector<std::pair<int, int>> startingState;
    void updateStartingState();
    int countHoney() const;
    int getTurn() const;
    std::string getMainStatOf(int index) const;
    std::vector<int> getNumbersOf() const;
};

#endif // CONTROLLER_H
