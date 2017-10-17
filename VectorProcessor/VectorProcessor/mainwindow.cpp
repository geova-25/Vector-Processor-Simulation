#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

int counter;

void* MainWindow::threadTest(void* i)
{
    while(true)
    {
        Fetch* iNew = (Fetch*)i;
        //cout << processor.fetch.Do << "\n";

    }
    return NULL;
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->fetchLabelVisibility = false;
    ui->setupUi(this);
    //Execute each 1000 seconds this code
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(getFetchData()));
    timer->start(10);
    i = 0;
    pthread_t t;
    pthread_create(&t,NULL,threadTest,&processor);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newValue()
{
    counter = counter++;

}

void MainWindow::on_labelFetch_linkActivated(const QString &link)
{

}

void MainWindow::getFetchData()
{

    //QString s = QString::number(i); //Para numeros
    QString qstr = QString::fromStdString(processor->fetch.Do);  //Para strings
    //cout << processor->fetch.Do << "\n";
    this->ui->labelFetch->setText(qstr);
    //this->ui->labelFetch->setText(s);
    //cout << "fetch.Do" << "\n";
    //printf("aaaaaaaaaa");
    //i++;
    this->ui->labelFetch->repaint();
}

void MainWindow::setProcessor(VectorProcessor* newProc)
{
    processor = newProc;
}


void MainWindow::on_pushButton_clicked()
{
   this->ui->labelFetch->setVisible(this->fetchLabelVisibility);
   this->fetchLabelVisibility = !this->fetchLabelVisibility;
}
