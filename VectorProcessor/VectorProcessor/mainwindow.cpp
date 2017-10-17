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




    //----------------------------------------------------------------------Exe

    QString exeSelReg = QString::number(processor->execute.selRegType);
    QString exeSelData = QString::number(processor->execute.selData);
    QString exeSelMem = QString::number(processor->execute.selWriteMem);
    QString exeRg = QString::number(processor->execute.RgOutExe);
    QString exeDirA = QString::number(processor->execute.AddrA);

    this->ui->label_exeSelReg->setText(exeSelReg);
    this->ui->label_exeSelData->setText(exeSelData);
    this->ui->label_exeSelMem->setText(exeSelMem);
    this->ui->label_exeRg->setText(exeRg);
    this->ui->label_exeDir->setText(exeDirA);

    QString exeDinDataMem_0 = QString::number(processor->execute.DinMD[0]);
    QString exeDinDataMem_1 = QString::number(processor->execute.DinMD[1]);
    QString exeDinDataMem_2 = QString::number(processor->execute.DinMD[2]);
    QString exeDinDataMem_3 = QString::number(processor->execute.DinMD[3]);
    QString exeDinDataMem_4 = QString::number(processor->execute.DinMD[4]);
    QString exeDinDataMem_5 = QString::number(processor->execute.DinMD[5]);
    QString exeDinDataMem_6 = QString::number(processor->execute.DinMD[6]);
    QString exeDinDataMem_7 = QString::number(processor->execute.DinMD[7]);


    this->ui->label_exeSave_0->setText(exeDinDataMem_0);
    this->ui->label_exeSave_1->setText(exeDinDataMem_1);
    this->ui->label_exeSave_2->setText(exeDinDataMem_2);
    this->ui->label_exeSave_3->setText(exeDinDataMem_3);
    this->ui->label_exeSave_4->setText(exeDinDataMem_4);
    this->ui->label_exeSave_5->setText(exeDinDataMem_5);
    this->ui->label_exeSave_6->setText(exeDinDataMem_6);
    this->ui->label_exeSave_7->setText(exeDinDataMem_7);


    QString exeAluResult_0 = QString::number(processor->execute.result[0]);
    QString exeAluResult_1 = QString::number(processor->execute.result[1]);
    QString exeAluResult_2 = QString::number(processor->execute.result[2]);
    QString exeAluResult_3 = QString::number(processor->execute.result[3]);
    QString exeAluResult_4 = QString::number(processor->execute.result[4]);
    QString exeAluResult_5 = QString::number(processor->execute.result[5]);
    QString exeAluResult_6 = QString::number(processor->execute.result[6]);
    QString exeAluResult_7 = QString::number(processor->execute.result[7]);

    this->ui->LabelAluResult_0->setText(exeAluResult_0);
    this->ui->LabelAluResult_1->setText(exeAluResult_1);
    this->ui->LabelAluResult_2->setText(exeAluResult_2);
    this->ui->LabelAluResult_3->setText(exeAluResult_3);
    this->ui->LabelAluResult_4->setText(exeAluResult_4);
    this->ui->LabelAluResult_5->setText(exeAluResult_5);
    this->ui->LabelAluResult_6->setText(exeAluResult_6);
    this->ui->LabelAluResult_7->setText(exeAluResult_7);





    /*QString exeOpAVector_0 = QString::number(processor->decoder_execute_register.[0]);
    QString exeOpAVector_1 = QString::number(processor->decoder.DoVB[1]);
    QString exeOpAVector_2 = QString::number(processor->decoder.DoVB[2]);
    QString exeOpAVector_3 = QString::number(processor->decoder.DoVB[3]);
    QString exeOpAVector_4 = QString::number(processor->decoder.DoVB[4]);
    QString exeOpAVector_5 = QString::number(processor->decoder.DoVB[5]);
    QString exeOpAVector_6 = QString::number(processor->decoder.DoVB[6]);
    QString exeOpAVector_7 = QString::number(processor->decoder.DoVB[7]);
    */

    //----------------------------------------------------------------------Fetch

    QString fetchDo = QString::fromStdString(processor->fetch.Do);  //Para strings
    this->ui->labelFetch->setText(fetchDo);
    this->ui->labelFetch->repaint();

    //-----------------------------------------------------------------------Decoder

    //----A
    QString decoDOAVector_0 = QString::number(processor->decoder.DoVA[0]);
    QString decoDOAVector_1 = QString::number(processor->decoder.DoVA[1]);
    QString decoDOAVector_2 = QString::number(processor->decoder.DoVA[2]);
    QString decoDOAVector_3 = QString::number(processor->decoder.DoVA[3]);
    QString decoDOAVector_4 = QString::number(processor->decoder.DoVA[4]);
    QString decoDOAVector_5 = QString::number(processor->decoder.DoVA[5]);
    QString decoDOAVector_6 = QString::number(processor->decoder.DoVA[6]);
    QString decoDOAVector_7 = QString::number(processor->decoder.DoVA[7]);
    //----B
    QString decoDOBVector_0 = QString::number(processor->decoder.DoVB[0]);
    QString decoDOBVector_1 = QString::number(processor->decoder.DoVB[1]);
    QString decoDOBVector_2 = QString::number(processor->decoder.DoVB[2]);
    QString decoDOBVector_3 = QString::number(processor->decoder.DoVB[3]);
    QString decoDOBVector_4 = QString::number(processor->decoder.DoVB[4]);
    QString decoDOBVector_5 = QString::number(processor->decoder.DoVB[5]);
    QString decoDOBVector_6 = QString::number(processor->decoder.DoVB[6]);
    QString decoDOBVector_7 = QString::number(processor->decoder.DoVB[7]);


    QString decoDOAScalar = QString::number(processor->decoder.DoSA);
    QString decoDOBScalar = QString::number(processor->decoder.DoSB);
    QString decoRg = QString::number(processor->decoder.RgDecoOut); //Para numeros
    QString decoRs = QString::number(processor->fetch_decoder_register.RvsDo); //Para numeros
    QString decoRp = QString::number(processor->fetch_decoder_register.RvpDo);


    //cout << processor->fetch.Do << "\n";


    this->ui->labelRs->setText(decoRs);
    this->ui->labelRp->setText(decoRp);
    this->ui->labelRg->setText(decoRg);
    //-------OUT REGISTERS
    //---Scalar
    this->ui->LabelDoAScalar->setText(decoDOAScalar);
    this->ui->LabelDoBScalar->setText(decoDOBScalar);
    //------Vectors
    //----A
    this->ui->LabelDoAVector_0->setText(decoDOAVector_0);
    this->ui->LabelDoAVector_1->setText(decoDOAVector_1);
    this->ui->LabelDoAVector_2->setText(decoDOAVector_2);
    this->ui->LabelDoAVector_3->setText(decoDOAVector_3);
    this->ui->LabelDoAVector_4->setText(decoDOAVector_4);
    this->ui->LabelDoAVector_5->setText(decoDOAVector_5);
    this->ui->LabelDoAVector_6->setText(decoDOAVector_6);
    this->ui->LabelDoAVector_7->setText(decoDOAVector_7);
    //----B
    this->ui->LabelDoBVector_0->setText(decoDOBVector_0);
    this->ui->LabelDoBVector_1->setText(decoDOBVector_1);
    this->ui->LabelDoBVector_2->setText(decoDOBVector_2);
    this->ui->LabelDoBVector_3->setText(decoDOBVector_3);
    this->ui->LabelDoBVector_4->setText(decoDOBVector_4);
    this->ui->LabelDoBVector_5->setText(decoDOBVector_5);
    this->ui->LabelDoBVector_6->setText(decoDOBVector_6);
    this->ui->LabelDoBVector_7->setText(decoDOBVector_7);

    this->ui->labelRs->repaint();
    this->ui->labelRg->repaint();
    this->ui->labelRp->repaint();
    this->ui->LabelDoAScalar->repaint();
    this->ui->LabelDoBScalar->repaint();

    this->ui->LabelDoAVector_0->repaint();
    this->ui->LabelDoAVector_1->repaint();
    this->ui->LabelDoAVector_2->repaint();
    this->ui->LabelDoAVector_3->repaint();
    this->ui->LabelDoAVector_4->repaint();
    this->ui->LabelDoAVector_5->repaint();
    this->ui->LabelDoAVector_6->repaint();
    this->ui->LabelDoAVector_7->repaint();

    this->ui->LabelDoBVector_0->repaint();
    this->ui->LabelDoBVector_1->repaint();
    this->ui->LabelDoBVector_2->repaint();
    this->ui->LabelDoBVector_3->repaint();
    this->ui->LabelDoBVector_4->repaint();
    this->ui->LabelDoBVector_5->repaint();
    this->ui->LabelDoBVector_6->repaint();
    this->ui->LabelDoBVector_7->repaint();

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
