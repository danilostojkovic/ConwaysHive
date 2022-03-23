#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QPushButton>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <vector>
#include <utility>
#include <QMessageBox>
#include <QTimer>
#include <QVariant>
#include <QApplication>

#include "controller.h"
#include "insect.h"
#include "hivebeetle.h"
#include "honeybee.h"
#include "queenbee.h"
#include "larva.h"
#include "bee.h"
#include "wasp.h"

#include "rulesdialog.h"
#include "funfactsdialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    Controller* c;
    static QString paths_cells[];
    static QString paths_select[];
    static QString paths_controls[];
    int selected;
    std::vector<QPushButton*> gridCells;
    QPushButton* menuCells[5];
    QLabel* statLabels[6];
    QTimer* timer;

    void addControls(QVBoxLayout*);
    void addSelections(QVBoxLayout*);
    void addTopBar(QVBoxLayout*);
    void makeGrid(QVBoxLayout*);
    void addStats(QVBoxLayout*);

    void updateStats();
    void paint(std::vector<std::pair<int,int>> state=std::vector<std::pair<int,int>>());

private slots:
    void cellIsClicked();
    void menuCellIsClicked();
    void nextButton();
    void playPauseButton();
    void restartButton();
    void clearButton();
    void timerAction();
    void rulesIsClicked();
    void funfactsIsClicked();
};
#endif // MAINWINDOW_H
