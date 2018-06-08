#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    srand(time(0));
    PutValues();
    Initialize();
    setImages();
    ui->textBrowser->installEventFilter(this);
    ui->label->setScaledContents(true);
    ui->label->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
    ui->label->setPixmap( QPixmap( ":/res/Fifteen Materials/PLAYER.png" ) );
    ui->score->setText("Moves: " + toString(moves) );
}
QString MainWindow::toString(int x)
{
    int rem = 10;
    int len=0;
    int rem_ = rem;
    int x_ = x;
    while(x_ > 0){x_ /= rem_;len++;}
    char array[len];
    int i = 0;
    while(x > 0)
    {
        int z = (x%rem);
        char c = (char)(z+48);
        array[len-i-1] = c;
        x /= rem;
        i++;
    }
    array[len] = '\0';
    return array;
}
MainWindow::~MainWindow()
{
    delete ui;
}
Point MainWindow::getPoint()
{
    for(int x = 0; x < 4; x++)
    {
        for(int y = 0; y < 4 ; y++)
        {
            if( Map[x][y].Data == ' ' )
            {
                Point p;
                p.x = x;
                p.y = y;
                return p;
            }
        }
    }
}

void MainWindow::checkIfWin()
{
    for(int y = 0; y < 4; y++)
    {
        for(int x = 0; x < 4 ; x++)
        {
            if( Copy[y][x].Data != Map[y][x].Data )
                return;
        }
    }
    w = new Win();
    this->hide();
    w->show();
}
void MainWindow::PutValues()
{
    char startChars[4][4] = {{'1','2','3','4'},{'5','6','7','8'},{'9','A','B','C'},{'D','E','F',' '}};
    QPixmap startImages[4][4];
    startImages[0][0] = QPixmap(":/res/Fifteen Materials/1-filled-xl.png");
    startImages[1][0] = QPixmap(":/res/Fifteen Materials/2-filled-xl.png");
    startImages[2][0] = QPixmap(":/res/Fifteen Materials/3-filled-xl.png");
    startImages[3][0] = QPixmap(":/res/Fifteen Materials/4-filled-xl.png");
    startImages[0][1] = QPixmap(":/res/Fifteen Materials/5-filled-xl.png");
    startImages[1][1] = QPixmap(":/res/Fifteen Materials/6-filled-xl.png");
    startImages[2][1] = QPixmap(":/res/Fifteen Materials/7-filled-xl.png");
    startImages[3][1] = QPixmap(":/res/Fifteen Materials/8-filled-xl.png");
    startImages[0][2] = QPixmap(":/res/Fifteen Materials/9-filled-xl.png");
    startImages[1][2] = QPixmap(":/res/Fifteen Materials/A.png");
    startImages[2][2] = QPixmap(":/res/Fifteen Materials/B.png");
    startImages[3][2] = QPixmap(":/res/Fifteen Materials/C.png");
    startImages[0][3] = QPixmap(":/res/Fifteen Materials/D.png");
    startImages[1][3] = QPixmap(":/res/Fifteen Materials/E.png");
    startImages[2][3] = QPixmap(":/res/Fifteen Materials/F.png");
    startImages[3][3] = QPixmap();
    for(int x = 0; x < 4; x++)
    {
        for(int y = 0; y < 4 ; y++)
        {
            Map[x][y].Data  = startChars[x][y];
            Map[x][y].image = startImages[x][y];
            Copy[x][y].Data = startChars[x][y];
            Copy[x][y].image= startImages[x][y];
        }
    }
    for(int x = 0; x < 4; x++)
    {
        for(int y = 0; y < 4 ; y++)
        {
            int _x = rand()%4;
            int _y = rand()%4;
            Icon Temp = Map[x][y];
            Map[x][y] = Map[_x][_y];
            Map[_x][_y] = Temp;
        }
    }
}
void MainWindow::Initialize()
{
    labels = new QLabel**[4];
    for(int i = 0; i < 4; i++)
    {
        labels[i] = new QLabel*[4];
    }
    labels[0][0] = ui->label1;
    labels[1][0] = ui->label2;
    labels[2][0] = ui->label3;
    labels[3][0] = ui->label4;
    labels[0][1] = ui->label5;
    labels[1][1] = ui->label6;
    labels[2][1] = ui->label7;
    labels[3][1] = ui->label8;
    labels[0][2] = ui->label9;
    labels[1][2] = ui->label10;
    labels[2][2] = ui->label11;
    labels[3][2] = ui->label12;
    labels[0][3] = ui->label13;
    labels[1][3] = ui->label14;
    labels[2][3] = ui->label15;
    labels[3][3] = ui->label16;


    for(int x = 0; x < 4; x++)
    {
        for(int y = 0; y < 4 ; y++)
        {
            labels[x][y]->setScaledContents(true);
            labels[x][y]->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
        }
    }
}
void MainWindow::setImages()
{
    for(int x = 0; x < 4; x++)
    {
        for(int y = 0; y < 4 ; y++)
        {
            labels[x][y]->setPixmap( Map[x][y].image );
        }
    }
    moves++;
    ui->score->setText("Moves: " + toString(moves) );
    checkIfWin();
}

void MainWindow::on_up_clicked()
{
    Point p = getPoint();
    int y = p.y;
    int x = p.x;
    int y2 = (y+1);
    Icon q = Map[x][y];
    if(y2 <= 3){
        Map[x][y] = Map[x][y2];
        Map[x][y2] = q;
        setImages();
    }
}

void MainWindow::on_left_clicked()
{
    Point p = getPoint();
    int y = p.y;
    int x = p.x;
    int x2 = (x+1);
    Icon q = Map[x][y];
    if(x2 <= 3){
        Map[x][y] = Map[x2][y];
        Map[x2][y] = q;
        setImages();

    }
}

void MainWindow::on_right_clicked()
{
    Point p = getPoint();
    int y = p.y;
    int x = p.x;
    int x2 = (x-1);
    Icon q = Map[x][y];
    if(x2 >= 0){
        Map[x][y] = Map[x2][y];
        Map[x2][y] = q;
        setImages();

    }
}

void MainWindow::on_down_clicked()
{
    Point p = getPoint();
    int y = p.y;
    int x = p.x;
    int y2 = (y-1);
    Icon q = Map[x][y];
    if(y2 >= 0){
        Map[x][y] = Map[x][y2];
        Map[x][y2] = q;
        setImages();

    }
}
void MainWindow::setName(QString n)
{
    ui->name->setText( "Name: " + n );
}

bool MainWindow::eventFilter(QObject* obj, QEvent *event)
{
    if (obj == ui->textBrowser)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
            if (keyEvent->key() == Qt::Key_Up)
            {
                 on_up_clicked();
                 return true;
            }
            else if(keyEvent->key() == Qt::Key_Down)
            {
                on_down_clicked();
                return true;
            }
            else if(keyEvent->key() == Qt::Key_Right)
            {
                on_right_clicked();
                return true;
            }
            else if(keyEvent->key() == Qt::Key_Left)
            {
                on_left_clicked();
                return true;
            }
        }
        return false;
    }
    return QMainWindow::eventFilter(obj, event);
}
