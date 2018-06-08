#include "start.h"
#include "ui_start.h"

Start::Start(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Start)
{
    ui->setupUi(this);
}

Start::~Start()
{
    delete ui;
}

void Start::on_pushButton_clicked()
{
    if( ui->lineEdit->text() == "" ) return;

    w = new MainWindow();
    w->show();
    w->setName( ui->lineEdit->text() );
    this->hide();
}

void Start::on_pushButton_2_clicked()
{
    exit(1);
}
