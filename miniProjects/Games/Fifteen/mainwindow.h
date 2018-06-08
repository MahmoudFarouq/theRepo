#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <QLabel>
#include <time.h>
#include <QDebug>
#include "win.h"

namespace Ui {
class MainWindow;
}

struct Icon
{
    char Data;
    QPixmap image;
};
struct Point
{
    int x;
    int y;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setName(QString n);


private slots:
    void on_up_clicked();

    void on_left_clicked();

    void on_right_clicked();

    void on_down_clicked();

private:
    Ui::MainWindow *ui;
    Icon Map[4][4];
    Icon Copy[4][4];
    QLabel ***labels;
    void Initialize();
    void setImages();
    Point getPoint();
    void PutValues();
    void Print();
    void checkIfWin();
    QString toString(int x);
    int moves = -1;
    Win *w;
    bool eventFilter(QObject* obj, QEvent *event);
};

#endif // MAINWINDOW_H
