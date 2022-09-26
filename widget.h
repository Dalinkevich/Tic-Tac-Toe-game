#ifndef WIDGET_H
#define WIDGET_H

#include <QMainWindow>
#include <QTimer>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QMainWindow
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_leftButton_clicked();
    void on_rightButton_clicked();
    void on_startButton_clicked();
    void onGameAreaButonClicked();
    void onComputerSlot();
    void on_aboutButton_clicked();

private:
    Ui::Widget *ui;
    void setInterfaceStyle();
    void changeButtonStatus(int num);

    void configurationTabWidget();
    void addFonts();
    void changeButtonStyle(int row, int colum, QString style);
    void setGameAreaButtonsStyle();
    void start();
    void configurationGameAreaButtons();
    void lockPlayer();
    void computerInGame();
    void checkGameStop();
    void endGame();
    void endGameStyle(int row, int colum, QString style);
    void makeGameBoardActive();

    char gameArea[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}
    };

    char player = 'X'; // x or 0
    int progress = 0;
    bool gameStart = false;
    bool playerLocked = true;
    bool stop;
    bool checkStopGame = false;
    char winner;

    QTimer *timer;

};
#endif // WIDGET_H
