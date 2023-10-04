#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    QPixmap kuva("C:/Users/Reina/Desktop/Risu/koirakoodi.png");
    ui->label_4->setPixmap(kuva);
    connect(ui->pushButton_1,SIGNAL(clicked(bool)),this,SLOT(numberClickedHandler()));
    connect(ui->pushButton_2,SIGNAL(clicked(bool)),this,SLOT(numberClickedHandler()));
    connect(ui->pushButton_3,SIGNAL(clicked(bool)),this,SLOT(numberClickedHandler()));
    connect(ui->pushButton_4,SIGNAL(clicked(bool)),this,SLOT(numberClickedHandler()));
    connect(ui->pushButton_5,SIGNAL(clicked(bool)),this,SLOT(numberClickedHandler()));
    connect(ui->pushButton_6,SIGNAL(clicked(bool)),this,SLOT(numberClickedHandler()));
    connect(ui->pushButton_7,SIGNAL(clicked(bool)),this,SLOT(numberClickedHandler()));
    connect(ui->pushButton_8,SIGNAL(clicked(bool)),this,SLOT(numberClickedHandler()));
    connect(ui->pushButton_9,SIGNAL(clicked(bool)),this,SLOT(numberClickedHandler()));
    connect(ui->pushButton_0,SIGNAL(clicked(bool)),this,SLOT(numberClickedHandler()));
    connect(ui->pushButton_Clear,SIGNAL(clicked(bool)),this,SLOT(resetLineEdits()));
    connect(ui->pushButton_Enter,SIGNAL(clicked(bool)),this,SLOT(clearAndEnterClickHandler()));
    connect(ui->pushButton_Jako,SIGNAL(clicked(bool)),this,SLOT(addSubMulDivClickHandler()));
    connect(ui->pushButton_Kerto,SIGNAL(clicked(bool)),this,SLOT(addSubMulDivClickHandler()));
    connect(ui->pushButton_Minus,SIGNAL(clicked(bool)),this,SLOT(addSubMulDivClickHandler()));
    connect(ui->pushButton_Plus,SIGNAL(clicked(bool)),this,SLOT(addSubMulDivClickHandler()));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickedHandler()
{

    QPushButton * button = qobject_cast<QPushButton*>(sender());
    if(button)
       {
           QLineEdit *currentEdit = (operand == -1) ? ui->Num1EditKentta : ui->Num2EditKentta;
           currentEdit->setText(currentEdit->text().append(button->text()));
       }
   // qDebug() <<"Button name:" << nimi;
}

void MainWindow::clearAndEnterClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());

    float n1 = ui->Num1EditKentta->text().toFloat();
    float n2 = ui->Num2EditKentta->text().toFloat();
        qDebug()<<"number 1=" <<n1 << "and number 2 = "<<n2<<Qt::endl;
    switch(operand){

    case 0:
        result = n1+n2;
        break;
    case 1:
        result = n1-n2;
        break;
    case 2:
        result = n1*n2;
        break;
    case 3:
        if (n2!=0){
        result = n1/n2;
        }
        else{
            ui->ResultKentta->setText("error");
            return;
        }
        break;
    default:
        ui->ResultKentta->setText("vituiks men");
        return;

    }
    ui->ResultKentta->setText(QString::number(result));
}

void MainWindow::addSubMulDivClickHandler()
{

    QPushButton * button = qobject_cast<QPushButton*>(sender());

    if (button->objectName()=="pushButton_Plus")
    {
        operand = 0;
    }
    else if (button->objectName()=="pushButton_Minus")
        {
        operand = 1;
        }
    else if (button->objectName()=="pushButton_Kerto")
        {
        operand = 2;
        }
    else if (button->objectName()=="pushButton_Jako")
            {
        operand = 3;
        }



 //ui->Num2EditKentta->setFocus();
}

void MainWindow::resetLineEdits()
{

    ui->Num1EditKentta->clear();
    ui->Num2EditKentta->clear();
    ui->ResultKentta->clear();
    operand = -1;
}

