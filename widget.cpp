#include "widget.h"
#include "ui_widget.h"
#include <QTabBar>
#include "stylehelper.h"
#include <QFontDatabase>
#include <QDebug>
#include <QGridLayout>
#include <time.h>

Widget::Widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    configurationTabWidget();
    setInterfaceStyle();
    addFonts();
    configurationGameAreaButtons();

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::onComputerSlot);

}

Widget::~Widget()
{
    delete ui;
}

//MARK: Assigning QSS rules for interface elements
void Widget::setInterfaceStyle()
{
    this->setStyleSheet(StyleHelper::getMainWudgetStyle());

    QPixmap pic = QPixmap(":/resourses/images/names.png").scaled(ui->nameLabel->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    ui->nameLabel->setPixmap(pic);
    ui->nameLabel->setScaledContents(true);

    ui->startButton->setStyleSheet(StyleHelper::getStartButtonsStyle());
    ui->aboutButton->setStyleSheet(StyleHelper::getStartButtonsStyle());
    ui->leftButton->setStyleSheet(StyleHelper::getLeftButtonActiveStyle());
    ui->rightButton->setStyleSheet(StyleHelper::getRightButtonStyle());
    ui->tabWidget->setStyleSheet(StyleHelper::getTabWidgetStyle());
    ui->tab->setStyleSheet(StyleHelper::getTabStyle());

    setGameAreaButtonsStyle();

    ui->messageLabel->setText("Crosses go first");
    ui->messageLabel->setStyleSheet(StyleHelper::getLostMessageStyle());

    ui->aboutTextLabel->setStyleSheet(StyleHelper::getAboutTextStyle());
}

//MARK: Switching the choice of who we will play(X/O)
void Widget::changeButtonStatus(int num)
{
    if (num == 1) {
        ui->leftButton->setStyleSheet(StyleHelper::getLeftButtonActiveStyle());
        ui->rightButton->setStyleSheet(StyleHelper::getRightButtonStyle());
    } else {
        ui->leftButton->setStyleSheet(StyleHelper::getLeftButtonStyle());
        ui->rightButton->setStyleSheet(StyleHelper::getRightButtonActiveStyle());
    }
}

//MARK: If the player chose X
void Widget::on_leftButton_clicked()
{
    changeButtonStatus(1);
    player = 'X';
}

//MARK: If the player chose O
void Widget::on_rightButton_clicked()
{
    changeButtonStatus(2);
    player = '0';
}

//Widget settings
void Widget::configurationTabWidget()
{
    ui->tabWidget->tabBar()->hide();
    ui->tabWidget->setMaximumHeight(320);
    ui->tabWidget->setCurrentIndex(0);
}

//MARK: Adding fonts from resourses to the font database
void Widget::addFonts()
{
    QFontDatabase::addApplicationFont(":/resourses/fonts/Comic_CAT.otf");
    QFontDatabase::addApplicationFont(":/resourses/fonts/nexa-script-light-1.ttf");
    QFontDatabase::addApplicationFont(":/resourses/fonts/kraft-mono-regular.ttf");

    //Find out the font name
    int id = QFontDatabase::addApplicationFont(":/resourses/fonts/kraft-mono-regular.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    qDebug() << family;
}

//MARK: Changing the QSS of the one button on the playing field
void Widget::changeButtonStyle(int row, int colum, QString style)
{
    QGridLayout *grid = qobject_cast <QGridLayout*>(ui->tab->layout());
    QPushButton * button = qobject_cast <QPushButton*>(grid->itemAtPosition(row, colum)->widget());
    button->setStyleSheet(style);
}

//MARK: Neutral style for all buttons on the playing field
void Widget::setGameAreaButtonsStyle()
{
    QString style = StyleHelper::getBlankButtonStyle();
    for(int row=0; row<3; row++) {
        for(int column=0; column<3; column++) {
            changeButtonStyle(row,column, style);
        }
    }
}

void Widget::configurationGameAreaButtons()
{
    QGridLayout *grid = qobject_cast <QGridLayout*>(ui->tab->layout());
    for(int row=0; row<3; row++) {
        for(int column=0; column<3; column++) {
            QPushButton *button = qobject_cast <QPushButton*>(grid->itemAtPosition(row, column)->widget());
            button->setProperty("row", row);
            button->setProperty("column", column);
            connect(button, &QPushButton::clicked, this, &Widget::onGameAreaButonClicked);
        };
    }
}

// Click on the play/give up button
void Widget::on_startButton_clicked()
{
    ui->tabWidget->setCurrentIndex(0);

    if(gameStart) {
        playerLocked = true;
        ui->startButton->setText("Play");
        ui->startButton->setStyleSheet(StyleHelper::getStartButtonsStyle());
        ui->leftButton->setDisabled(false);
        ui->rightButton->setDisabled(false);
        gameStart = false;
        ui->messageLabel->setText("You've lost");
        ui->messageLabel->setStyleSheet(StyleHelper::getLostMessageStyle());
    } else {
        ui->messageLabel->setText("The game has started");
        ui->messageLabel->setStyleSheet(StyleHelper::getNormalMessageStyle());
        start();
        lockPlayer();
        ui->startButton->setText("Give up");
        ui->startButton->setStyleSheet(StyleHelper::getStartButtonGameStyle());
        ui->leftButton->setDisabled(true);
        ui->rightButton->setDisabled(true);
    }
}

//MARK: The beginning of the game
void Widget::start()
{
    ui->tabWidget->setCurrentIndex(0);
    makeGameBoardActive();
    setGameAreaButtonsStyle();

    for(int r=0; r<3; r++) {
        for(int c=0; c<3; c++) {
            gameArea[r][c] = '-';
        }
    }

    progress = 0;
    gameStart = true;
    stop = false;

    if(player != 'X') {
        computerInGame();
    }
}

//MARK: Block player actions
void Widget::lockPlayer()
{
    if(player == 'X') {
        playerLocked = false;
    } else {
        playerLocked = true;
    }
}

//MARK: Player's move
void Widget::onGameAreaButonClicked()
{
    if(stop) {
        playerLocked = true;
        return;
    }

    if(playerLocked != true) {

        QPushButton *button = qobject_cast<QPushButton*>(sender());
        int row = button->property("row").toInt();
        int column = button->property("column").toInt();
        QString style;

        if(player == 'X') {
            style = StyleHelper::getCrossNormalStyle();
            gameArea[row][column] = 'X';
        } else {
            style = StyleHelper::getZeroNormalStyle();
            gameArea[row][column] = '0';
        }

        changeButtonStyle(row,column,style);
        button->setDisabled(true);
        playerLocked = true;
        progress++;

        checkGameStop();
        endGame();
        computerInGame();
    }
}


void Widget::computerInGame()
{
    if(stop) {
        playerLocked = true;
        return;
    }
    srand(time(0));
    int index = rand() % 3;
    QStringList list = {"My move!", "Wait a minute", "Let me think..."};
    ui->messageLabel->setText(list.at(index));
    timer->start(2000);
}

void Widget::checkGameStop()
{
    winner = '-';
    QString style;

    char symbols[2] = {'X', '0'};
    // Horizontal match
    for(int i=0; i<2; i++) {
        for(int row=0; row<3; row++) {
            if((gameArea[row][0] == symbols[i] and (gameArea[row][1] == symbols[i] and (gameArea[row][2] == symbols[i])))) {
                stop = true;
                winner = symbols[i];
                endGameStyle(row,0,style);
                endGameStyle(row,1,style);
                endGameStyle(row,2,style);
                return;
            }
        }
        // Vertical match
        for(int column=0; column<3; column++) {
            if((gameArea[0][column] == symbols[i] and (gameArea[1][column] == symbols[i] and (gameArea[2][column] == symbols[i])))) {
                stop = true;
                winner = symbols[i];
                endGameStyle(0,column,style);
                endGameStyle(1,column,style);
                endGameStyle(2,column,style);
                return;
            }
        }
        // Diagonal matching
        if ((gameArea[0][0] == symbols[i]) and (gameArea[1][1] == symbols[i]) and (gameArea[2][2] == symbols[i])) {
            stop = true;
            winner = symbols[i];
            endGameStyle(0,0,style);
            endGameStyle(1,1,style);
            endGameStyle(2,2,style);
            return;
        }

        if ((gameArea[0][2] == symbols[i]) and (gameArea[1][1] == symbols[i]) and (gameArea[2][0] == symbols[i])) {
            stop = true;
            winner = symbols[i];
            endGameStyle(0,2,style);
            endGameStyle(1,1,style);
            endGameStyle(2,0,style);
            return;
        }
    }
    //There are no winners
    if(progress == 9) {
        stop = true;
    }
}

//MARK: End of the game
void Widget::endGame()
{
    if(stop) {
        if(winner == player) {
            ui->messageLabel->setText("You have won!");
            ui->messageLabel->setStyleSheet(StyleHelper::getVictoryMessageStyle());

        } else if(winner == '-') {
            ui->messageLabel->setText("There is no winner!");

        } else  {
            ui->messageLabel->setText("You've lost!");
            ui->messageLabel->setStyleSheet(StyleHelper::getLostMessageStyle());
        }

        playerLocked = true;
        ui->startButton->setText("Play");
        ui->startButton->setStyleSheet(StyleHelper::getStartButtonsStyle());
        ui->leftButton->setDisabled(false);
        ui->rightButton->setDisabled(false);
        gameStart = false;
    }
}

//MARK: Computer running
void Widget::onComputerSlot()
{
    char comp;
    QString style;

    if(player == 'X') {
        comp = '0';
        style = StyleHelper::getZeroNormalStyle();
    } else {
        comp = 'X';
        style = StyleHelper::getCrossNormalStyle();
    }

    timer->stop();

    while(true) {
        int row = rand() % 3;
        int column = rand() % 3;

        if(gameArea[row][column] == '-') {
            gameArea[row][column] = comp;
            changeButtonStyle(row, column, style);
            ui->messageLabel->setText("Your move!");
            progress++;
            checkGameStop();
            endGame();
            playerLocked = false;

            //Lock the computer's progress button
            QGridLayout *grid = qobject_cast <QGridLayout*>(ui->tab->layout());
            QPushButton *button = qobject_cast <QPushButton*>(grid->itemAtPosition(row,column)->widget());
            button->setDisabled(true);
            break;
        }
    }
}

void Widget::endGameStyle(int row, int colum, QString style)
{
    if(winner == player) {
        if(player == 'X') {
            style = StyleHelper::getCrossVictoryStyle();
        } else {
            style = StyleHelper::getZeroVictoryStyle();
        }
    } else {

        if(player == '0') {
            style = StyleHelper::getCrossLostStyle();
        } else {
            style = StyleHelper::getZeroLostStyle();
        }
    }

    playerLocked = true;
    changeButtonStyle(row, colum, style);
    changeButtonStyle(row, colum, style);
    changeButtonStyle(row, colum, style);
    return;
}

void Widget::makeGameBoardActive()
{
    QGridLayout *grid = qobject_cast <QGridLayout*>(ui->tab->layout());
    for(int row=0; row<3; row++) {
        for(int column=0; column<3; column++) {
            QPushButton *button = qobject_cast <QPushButton*>(grid->itemAtPosition(row, column)->widget());
            button->setDisabled(false);
        };
    }
}

//About the game tab
void Widget::on_aboutButton_clicked()
{
    ui->tabWidget->setCurrentIndex(1);
}


