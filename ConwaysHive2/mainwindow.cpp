#include "mainwindow.h"

QString MainWindow::paths_cells[7]=
    {":/Images/ape.png",
     ":/Images/regina.png",
     ":/Images/larva.png",
     ":/Images/coleottero.png",
     ":/Images/vespa.png",
     ":/Images/cella.png",
     ":/Images/cellaMiele.png",};              //tag=posizione nell'array
QString MainWindow::paths_select[5]=
    {":/Images/BW_ape.png",
     ":/Images/BW_regina.png",
     ":/Images/BW_larva.png",
     ":/Images/BW_coleottero.png",
     ":/Images/BW_vespa.png"};           //foto in bianco e nero per la selezione
QString MainWindow::paths_controls[4]=
    {":/Images/next.png",
     ":/Images/start.png",
     ":/Images/restart.png",
     ":/Images/clear.png"};          //percorsi immagini dei controlli

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , c(new Controller(this))
    , timer(new QTimer())
{
    //sfondo
    QPixmap bkgnd(":/Images/sfondo.jpg");
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    //creazione e riempimento QBoxLayout principali
    QWidget* widg=new QWidget();

    QHBoxLayout* mainLayout = new QHBoxLayout;
    QVBoxLayout* leftSide = new QVBoxLayout;
    QVBoxLayout* rightSide = new QVBoxLayout;

    addTopBar(leftSide);
    makeGrid(leftSide);
    addControls(rightSide);
    addSelections(rightSide);
    addStats(rightSide);

    rightSide->setContentsMargins(0, 0, 0, 0);
    leftSide->setContentsMargins(0, 0, 0, 0);
    mainLayout->setContentsMargins(0, 0, 0, 0);

    mainLayout->addLayout(leftSide);
    mainLayout->addLayout(rightSide);
    widg->setLayout(mainLayout);
    setCentralWidget(widg);

    selected=-1;
    //connessione timer al suo metodo
    connect(timer, SIGNAL(timeout()), this, SLOT(timerAction()));
}

void MainWindow::addControls(QVBoxLayout* main){
    QFrame* controls = new QFrame(this);
    std::pair<int, int> pos[4] = {{5, 75},
                                  {120, 155},
                                  {240, 137},
                                  {360, 205}};
    for(int i=0; i<4; i++){
        menuCells[i]=new QPushButton(controls);
        menuCells[i]->setGeometry((QRect(pos[i].first, pos[i].second, 120, 120)));
        menuCells[i]->setIcon(QPixmap(paths_controls[i]));
        menuCells[i]->setIconSize(QSize(120, 120));
        menuCells[i]->setStyleSheet("border: 0");
        menuCells[i]->setProperty("tag", i);
    }
    connect(menuCells[0], SIGNAL(clicked()), this, SLOT(nextButton()));
    connect(menuCells[1], SIGNAL(clicked()), this, SLOT(playPauseButton()));
    connect(menuCells[2], SIGNAL(clicked()), this, SLOT(restartButton()));
    connect(menuCells[3], SIGNAL(clicked()), this, SLOT(clearButton()));
    QPushButton* close=new QPushButton(controls);
    close->setGeometry((QRect(345, 0, 120, 120)));
    close->setIcon(QPixmap(":/Images/cross.png"));
    close->setIconSize(QSize(300, 100));
    close->setStyleSheet("border: 0");
    connect(close, SIGNAL(clicked()), qApp, SLOT(quit()));

    controls->setMinimumWidth(475);
    main->addWidget(controls);
}

void MainWindow::addSelections(QVBoxLayout* main){
    QFrame* selections = new QFrame(this);
    std::pair<int, int> pos[5] = {{0, 0},
                                  {150, 0},
                                  {300, 0},
                                  {75, 130},
                                  {225, 130} };
    for(int i=0; i<5; i++){
        menuCells[i]=new QPushButton(selections);
        menuCells[i]->setGeometry((QRect(pos[i].first, pos[i].second, 150, 175)));
        menuCells[i]->setIcon(QPixmap(paths_select[i]));
        menuCells[i]->setIconSize(QSize(160, 175));
        menuCells[i]->setStyleSheet("border: 0");
        connect(menuCells[i], SIGNAL(clicked()), this, SLOT(menuCellIsClicked()));
        menuCells[i]->setProperty("tag", i);
    }
    selections->setMinimumWidth(475);
    main->addWidget(selections);
}
void MainWindow::makeGrid(QVBoxLayout* leftSide){
    QHBoxLayout* gridContainer = new QHBoxLayout;
    QFrame* grid = new QFrame(this);
    int a=0;
    for(int j=0; j<11; j++){
        for(int i=0; i<16; i++){
            gridCells.push_back(new QPushButton(grid));
            gridCells.back()->setGeometry(QRect(i*86+(j%2==0?0:43),j*75,86,100));
            gridCells.back()->setIcon(QPixmap(paths_cells[5]));
            gridCells.back()->setIconSize(QSize(86, 100));
            gridCells.back()->setStyleSheet("border: 0");
            gridCells.back()->setProperty("tag", a++);
            connect(gridCells.back(), SIGNAL(clicked()), this, SLOT(cellIsClicked()));
        }
    }
    gridContainer->addSpacerItem(new QSpacerItem(10, 10, QSizePolicy::Fixed));
    gridContainer->addWidget(grid);
    leftSide->addLayout(gridContainer);
}

void MainWindow::addTopBar(QVBoxLayout* leftSide){
    QHBoxLayout* topBar = new QHBoxLayout;

    QLabel* title = new QLabel(this);
    title->setPixmap(QPixmap(":/Images/titolo.png"));
    title->setScaledContents(true);
    title->setMaximumSize(800, 190);

    QPushButton* rules = new QPushButton(this);
    rules->setMinimumSize(190, 190);
    rules->setIcon(QPixmap(":/Images/regole.png"));
    rules->setIconSize(QSize(190, 190));
    rules->setFont(QFont("Times", 30, QFont::Normal));
    rules->setStyleSheet("border: 0");
    connect(rules, SIGNAL(clicked()), this, SLOT(rulesIsClicked()));

    QPushButton* funfacts = new QPushButton(this);
    funfacts->setMinimumSize(190, 190);
    funfacts->setIcon(QPixmap(":/Images/FunFacts.png"));
    funfacts->setIconSize(QSize(190, 190));
    funfacts->setFont(QFont("Times", 30, QFont::Normal));
    funfacts->setStyleSheet("border: 0");
    connect(funfacts, SIGNAL(clicked()), this, SLOT(funfactsIsClicked()));

    topBar->setContentsMargins(0, 0, 0, 0);
    topBar->addWidget(title);
    topBar->addWidget(rules);
    topBar->addWidget(funfacts);
    topBar->addSpacerItem(new QSpacerItem(10, 10, QSizePolicy::Expanding));
    leftSide->addLayout(topBar);
}
void MainWindow::addStats(QVBoxLayout* rightSide){
    QFrame* extractor = new QFrame(this);
    QLabel* title = new QLabel(extractor);
    title->setPixmap(QPixmap(":/Images/stats.png"));
    title->setScaledContents(true);
    title->setMaximumSize(450, 300);
    int pos[6]={226, 182, 193, 256, 199, 225};
    for(int i=0; i<6; i++){
        statLabels[i]=new QLabel("0", extractor);
        statLabels[i]->setGeometry(QRect(pos[i], 115+i*31, 60, 20));
        statLabels[i]->setFont(QFont("Times", 15, QFont::Bold));
    }
    rightSide->addWidget(extractor);
}

void MainWindow::updateStats()
{
    //aggiornamento tabella statistiche
    statLabels[0]->setText(QString::number(c->getTurn()));
    std::vector<int> numerosita=c->getNumbersOf();
    for(int i=0; i<(int)numerosita.size(); i++)
        statLabels[i+1]->setText(QString::number(numerosita[i]));
    statLabels[5]->setText(QString::number(c->countHoney()));
}

void MainWindow::paint(std::vector<std::pair<int,int>> state)
{
    if(state.size()==0)
        state=c->getGameState();
    for(auto i=state.begin(); i<state.end(); i++){
        gridCells[(*i).first]->setIcon(QPixmap(paths_cells[(*i).second]));
    }
    updateStats();
}

void MainWindow::cellIsClicked(){
    if(selected==-1)
        return;
    QPushButton* cell = qobject_cast<QPushButton*>(sender());
    try{
        int index = cell->property("tag").toInt();
        if(c->getTurn()==0){
            c->changeCellState(index, selected);
            int newState=c->getCellState(index);
            cell->setIcon(QPixmap(paths_cells[newState]));
            updateStats();
        }
        else{
            QMessageBox m;
            QString qs=QString::fromStdString(c->getMainStatOf(index));
            if(qs!=""){
                m.setText(qs);
                m.exec();
            }
        }
    }
    catch(int a){
        if(a==1){
            QMessageBox m;
            m.setText("C'è già una regina nel campo da gioco.");
            m.exec();
        }
    }
}
void MainWindow::menuCellIsClicked(){
    QPushButton* pressed = qobject_cast<QPushButton*>(sender());
    int tag=pressed->property("tag").toInt();
    if(selected!=tag){
        if(selected!=-1)
            menuCells[selected]->setIcon(QPixmap(paths_select[selected]));
        selected=tag;
        pressed->setIcon(QPixmap(paths_cells[selected]));
    }
}

void MainWindow::nextButton(){
    c->updateStartingState();
    c->next();
    paint();
}

void MainWindow::playPauseButton()
{
    QPushButton* pressed = qobject_cast<QPushButton*>(sender());
    if(c->playPause()){
        timer->stop();
        pressed->setIcon(QPixmap(":/Images/start.png"));
    }
    else{
        timer->start(750);
        pressed->setIcon(QPixmap(":/Images/pause.png"));
    }
}

void MainWindow::restartButton(){
    c->restart();
    paint(c->startingState);
}

void MainWindow::clearButton(){
    c->clear();
    paint();
}

void MainWindow::timerAction()
{
    nextButton();
}

void MainWindow::rulesIsClicked(){
    RulesDialog r;
    r.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    r.setModal(true);
    r.setFixedSize(1200, 675);
    r.exec();
}

void MainWindow::funfactsIsClicked(){
    FunFactsDialog f;
    f.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    f.setModal(true);
    f.setFixedSize(1200, 675);
    f.exec();
}

MainWindow::~MainWindow()
{
    delete c;
    delete timer;
}

