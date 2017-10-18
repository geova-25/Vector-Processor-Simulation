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
    this->fetchVisibility = false;
    this->decoVisibility = false;
    this->exeVisibility = false;
    this->memVisibility = false;
    this->wbVisibility = false;
    this->ciclo = 1;


    ui->setupUi(this);
    //Execute each 1000 seconds this code
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(getFetchData()));
    timer->start();

    QTimer *cimer = new QTimer(this);
    connect(cimer, SIGNAL(timeout()), this, SLOT(getCicloMasUno()));
    cimer->start(7000);
    i = 0;
    pthread_t t;
    pthread_create(&t,NULL,threadTest,&processor);

}

void MainWindow::getCicloMasUno()
{
    ciclo++;
    QString cicloLabel = QString::number(ciclo);
    this->ui->label_ciclo->setText(cicloLabel);
    this->ui->label_ciclo->repaint();
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

    QString exeImm = QString::number(processor->execute.Imm);
    this->ui->label_exeImm->setText(exeImm);
    this->ui->label_exeImm->repaint();

    QString exeOpSA = QString::number(processor->execute.OpSA);
    QString exeOpSB = QString::number(processor->execute.OpSB);

    this->ui->label_exeOpAScalar->setText(exeOpSA);
    this->ui->label_exeOpBScalar->setText(exeOpSB);

    this->ui->label_exeOpAScalar->repaint();
    this->ui->label_exeOpBScalar->repaint();

    QString exeOpVA_0 = QString::number(processor->execute.OpVA[0]);
    QString exeOpVA_1 = QString::number(processor->execute.OpVA[1]);
    QString exeOpVA_2 = QString::number(processor->execute.OpVA[2]);
    QString exeOpVA_3 = QString::number(processor->execute.OpVA[3]);
    QString exeOpVA_4 = QString::number(processor->execute.OpVA[4]);
    QString exeOpVA_5 = QString::number(processor->execute.OpVA[5]);
    QString exeOpVA_6 = QString::number(processor->execute.OpVA[6]);
    QString exeOpVA_7 = QString::number(processor->execute.OpVA[7]);


    QString exeOpVB_0 = QString::number(processor->execute.OpVB[0]);
    QString exeOpVB_1 = QString::number(processor->execute.OpVB[1]);
    QString exeOpVB_2 = QString::number(processor->execute.OpVB[2]);
    QString exeOpVB_3 = QString::number(processor->execute.OpVB[3]);
    QString exeOpVB_4 = QString::number(processor->execute.OpVB[4]);
    QString exeOpVB_5 = QString::number(processor->execute.OpVB[5]);
    QString exeOpVB_6 = QString::number(processor->execute.OpVB[6]);
    QString exeOpVB_7 = QString::number(processor->execute.OpVB[7]);

    this->ui->LabelOpAVector_0->setText(exeOpVA_0);
    this->ui->LabelOpAVector_1->setText(exeOpVA_1);
    this->ui->LabelOpAVector_2->setText(exeOpVA_2);
    this->ui->LabelOpAVector_3->setText(exeOpVA_3);
    this->ui->LabelOpAVector_4->setText(exeOpVA_4);
    this->ui->LabelOpAVector_5->setText(exeOpVA_5);
    this->ui->LabelOpAVector_6->setText(exeOpVA_6);
    this->ui->LabelOpAVector_7->setText(exeOpVA_7);

    this->ui->LabelOpAVector_0->repaint();
    this->ui->LabelOpAVector_1->repaint();
    this->ui->LabelOpAVector_2->repaint();
    this->ui->LabelOpAVector_3->repaint();
    this->ui->LabelOpAVector_4->repaint();
    this->ui->LabelOpAVector_5->repaint();
    this->ui->LabelOpAVector_6->repaint();
    this->ui->LabelOpAVector_7->repaint();

    this->ui->LabelOpBVector_0->setText(exeOpVB_0);
    this->ui->LabelOpBVector_1->setText(exeOpVB_1);
    this->ui->LabelOpBVector_2->setText(exeOpVB_2);
    this->ui->LabelOpBVector_3->setText(exeOpVB_3);
    this->ui->LabelOpBVector_4->setText(exeOpVB_4);
    this->ui->LabelOpBVector_5->setText(exeOpVB_5);
    this->ui->LabelOpBVector_6->setText(exeOpVB_6);
    this->ui->LabelOpBVector_7->setText(exeOpVB_7);


    this->ui->LabelOpBVector_0->repaint();
    this->ui->LabelOpBVector_1->repaint();
    this->ui->LabelOpBVector_2->repaint();
    this->ui->LabelOpBVector_3->repaint();
    this->ui->LabelOpBVector_4->repaint();
    this->ui->LabelOpBVector_5->repaint();
    this->ui->LabelOpBVector_6->repaint();
    this->ui->LabelOpBVector_7->repaint();



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



    //-----------------------------------------------------------------------Mem

    QString memAddr = QString::number(processor->mem.Addr);
    QString memSelMem = QString::number(processor->mem.selWriteMem);
    QString memSelReg = QString::number(processor->mem.selRegType);
    QString memSelData = QString::number(processor->mem.selData);
    QString memAluResultScalar = QString::number(processor->mem.AluResultScalar);
    QString memRg = QString::number(processor->mem.RgOutMemory);


    this->ui->label_memAddr->setText(memAddr);
    this->ui->label_memRg->setText(memRg);
    this->ui->label_memSelMem->setText(memSelMem);
    this->ui->label_memSelData->setText(memSelData);
    this->ui->label_memSelReg->setText(memSelReg);
    this->ui->label_AluResultScalar->setText(memAluResultScalar);

    this->ui->label_memRg->repaint();
    this->ui->label_memAddr->repaint();
    this->ui->label_memAddr->repaint();
    this->ui->label_memSelData->repaint();
    this->ui->label_memSelReg->repaint();
    this->ui->label_AluResultScalar->repaint();

    QString memDin_0 = QString::number(processor->mem.DinMem[0]);
    QString memDin_1 = QString::number(processor->mem.DinMem[1]);
    QString memDin_2 = QString::number(processor->mem.DinMem[2]);
    QString memDin_3 = QString::number(processor->mem.DinMem[3]);
    QString memDin_4 = QString::number(processor->mem.DinMem[4]);
    QString memDin_5 = QString::number(processor->mem.DinMem[5]);
    QString memDin_6 = QString::number(processor->mem.DinMem[6]);
    QString memDin_7 = QString::number(processor->mem.DinMem[7]);

    this->ui->label_MemDin_0->setText(memDin_0);
    this->ui->label_MemDin_1->setText(memDin_1);
    this->ui->label_MemDin_2->setText(memDin_2);
    this->ui->label_MemDin_3->setText(memDin_3);
    this->ui->label_MemDin_4->setText(memDin_4);
    this->ui->label_MemDin_5->setText(memDin_5);
    this->ui->label_MemDin_6->setText(memDin_6);
    this->ui->label_MemDin_7->setText(memDin_7);


    this->ui->label_MemDin_0->repaint();
    this->ui->label_MemDin_1->repaint();
    this->ui->label_MemDin_2->repaint();
    this->ui->label_MemDin_3->repaint();
    this->ui->label_MemDin_4->repaint();
    this->ui->label_MemDin_5->repaint();
    this->ui->label_MemDin_6->repaint();
    this->ui->label_MemDin_7->repaint();


    QString memDo_0 = QString::number(processor->mem.Do[0]);
    QString memDo_1 = QString::number(processor->mem.Do[1]);
    QString memDo_2 = QString::number(processor->mem.Do[2]);
    QString memDo_3 = QString::number(processor->mem.Do[3]);
    QString memDo_4 = QString::number(processor->mem.Do[4]);
    QString memDo_5 = QString::number(processor->mem.Do[5]);
    QString memDo_6 = QString::number(processor->mem.Do[6]);
    QString memDo_7 = QString::number(processor->mem.Do[7]);

    this->ui->label_MemDo_0->setText(memDo_0);
    this->ui->label_MemDo_1->setText(memDo_1);
    this->ui->label_MemDo_2->setText(memDo_2);
    this->ui->label_MemDo_3->setText(memDo_3);
    this->ui->label_MemDo_4->setText(memDo_4);
    this->ui->label_MemDo_5->setText(memDo_5);
    this->ui->label_MemDo_6->setText(memDo_6);
    this->ui->label_MemDo_7->setText(memDo_7);


    this->ui->label_MemDo_0->repaint();
    this->ui->label_MemDo_1->repaint();
    this->ui->label_MemDo_2->repaint();
    this->ui->label_MemDo_3->repaint();
    this->ui->label_MemDo_4->repaint();
    this->ui->label_MemDo_5->repaint();
    this->ui->label_MemDo_6->repaint();
    this->ui->label_MemDo_7->repaint();



    QString memAluResult_0 = QString::number(processor->mem.Alu_result[0]);
    QString memAluResult_1 = QString::number(processor->mem.Alu_result[1]);
    QString memAluResult_2 = QString::number(processor->mem.Alu_result[2]);
    QString memAluResult_3 = QString::number(processor->mem.Alu_result[3]);
    QString memAluResult_4 = QString::number(processor->mem.Alu_result[4]);
    QString memAluResult_5 = QString::number(processor->mem.Alu_result[5]);
    QString memAluResult_6 = QString::number(processor->mem.Alu_result[6]);
    QString memAluResult_7 = QString::number(processor->mem.Alu_result[7]);


    this->ui->LabelMemAluResult_0->setText(memAluResult_0);
    this->ui->LabelMemAluResult_1->setText(memAluResult_1);
    this->ui->LabelMemAluResult_2->setText(memAluResult_2);
    this->ui->LabelMemAluResult_3->setText(memAluResult_3);
    this->ui->LabelMemAluResult_4->setText(memAluResult_4);
    this->ui->LabelMemAluResult_5->setText(memAluResult_5);
    this->ui->LabelMemAluResult_6->setText(memAluResult_6);
    this->ui->LabelMemAluResult_7->setText(memAluResult_7);

    this->ui->LabelMemAluResult_0->repaint();
    this->ui->LabelMemAluResult_1->repaint();
    this->ui->LabelMemAluResult_2->repaint();
    this->ui->LabelMemAluResult_3->repaint();
    this->ui->LabelMemAluResult_4->repaint();
    this->ui->LabelMemAluResult_5->repaint();
    this->ui->LabelMemAluResult_6->repaint();
    this->ui->LabelMemAluResult_7->repaint();



    //---------------------------------------------------------------------WriteBack

    QString wbRg = QString::number(processor->write_back.Rg);
    QString wbSelReg = QString::number(processor->write_back.selRegType);
    QString wbSelData = QString::number(processor->write_back.selData);
    QString wbDinScalar = QString::number(processor->write_back.AluResultScalar);

    this->ui->label_RgWB->setText(wbRg);
    this->ui->label_SelDataWB->setText(wbSelData);
    this->ui->label_selRegWB->setText(wbSelReg);
    this->ui->label_DinScalarWB->setText(wbDinScalar);

    this->ui->label_RgWB->repaint();
    this->ui->label_SelDataWB->repaint();
    this->ui->label_selRegWB->repaint();
    this->ui->label_DinScalarWB->repaint();


    QString wbDinVector_0 = QString::number(processor->write_back.AluResult[0]);
    QString wbDinVector_1 = QString::number(processor->write_back.AluResult[1]);
    QString wbDinVector_2 = QString::number(processor->write_back.AluResult[2]);
    QString wbDinVector_3 = QString::number(processor->write_back.AluResult[3]);
    QString wbDinVector_4 = QString::number(processor->write_back.AluResult[4]);
    QString wbDinVector_5 = QString::number(processor->write_back.AluResult[5]);
    QString wbDinVector_6 = QString::number(processor->write_back.AluResult[6]);
    QString wbDinVector_7 = QString::number(processor->write_back.AluResult[7]);

    this->ui->label_DinWbVector_0->setText(wbDinVector_0);
    this->ui->label_DinWbVector_1->setText(wbDinVector_1);
    this->ui->label_DinWbVector_2->setText(wbDinVector_2);
    this->ui->label_DinWbVector_3->setText(wbDinVector_3);
    this->ui->label_DinWbVector_4->setText(wbDinVector_4);
    this->ui->label_DinWbVector_5->setText(wbDinVector_5);
    this->ui->label_DinWbVector_6->setText(wbDinVector_6);
    this->ui->label_DinWbVector_7->setText(wbDinVector_7);

    this->ui->label_DinWbVector_0->repaint();
    this->ui->label_DinWbVector_1->repaint();
    this->ui->label_DinWbVector_2->repaint();
    this->ui->label_DinWbVector_3->repaint();
    this->ui->label_DinWbVector_4->repaint();
    this->ui->label_DinWbVector_5->repaint();
    this->ui->label_DinWbVector_6->repaint();
    this->ui->label_DinWbVector_7->repaint();



    //----------------------------------------------------------------------Fetch

    QString fetchDo = QString::fromStdString(processor->fetch.Do);  //Para strings
    this->ui->labelFetch->setText(fetchDo);
    this->ui->labelFetch->repaint();

    //-----------------------------------------------------------------------Decoder
    //-----------------------Vector Registers
    //-------0
    QString decoRegV0_0 = QString::number(processor->decoder.getVectorRegisterA(0)[0]);
    QString decoRegV0_1 = QString::number(processor->decoder.getVectorRegisterA(0)[1]);
    QString decoRegV0_2 = QString::number(processor->decoder.getVectorRegisterA(0)[2]);
    QString decoRegV0_3 = QString::number(processor->decoder.getVectorRegisterA(0)[3]);
    QString decoRegV0_4 = QString::number(processor->decoder.getVectorRegisterA(0)[4]);
    QString decoRegV0_5 = QString::number(processor->decoder.getVectorRegisterA(0)[5]);
    QString decoRegV0_6 = QString::number(processor->decoder.getVectorRegisterA(0)[6]);
    QString decoRegV0_7 = QString::number(processor->decoder.getVectorRegisterA(0)[7]);

    this->ui->label_RegV0_0->setText(decoRegV0_0);
    this->ui->label_RegV0_1->setText(decoRegV0_1);
    this->ui->label_RegV0_2->setText(decoRegV0_2);
    this->ui->label_RegV0_3->setText(decoRegV0_3);
    this->ui->label_RegV0_4->setText(decoRegV0_4);
    this->ui->label_RegV0_5->setText(decoRegV0_5);
    this->ui->label_RegV0_6->setText(decoRegV0_6);
    this->ui->label_RegV0_7->setText(decoRegV0_7);

    this->ui->label_RegV0_0->repaint();
    this->ui->label_RegV0_1->repaint();
    this->ui->label_RegV0_2->repaint();
    this->ui->label_RegV0_3->repaint();
    this->ui->label_RegV0_4->repaint();
    this->ui->label_RegV0_5->repaint();
    this->ui->label_RegV0_6->repaint();
    this->ui->label_RegV0_7->repaint();


    //-------1
    QString decoRegV1_0 = QString::number(processor->decoder.getVectorRegisterA(1)[0]);
    QString decoRegV1_1 = QString::number(processor->decoder.getVectorRegisterA(1)[1]);
    QString decoRegV1_2 = QString::number(processor->decoder.getVectorRegisterA(1)[2]);
    QString decoRegV1_3 = QString::number(processor->decoder.getVectorRegisterA(1)[3]);
    QString decoRegV1_4 = QString::number(processor->decoder.getVectorRegisterA(1)[4]);
    QString decoRegV1_5 = QString::number(processor->decoder.getVectorRegisterA(1)[5]);
    QString decoRegV1_6 = QString::number(processor->decoder.getVectorRegisterA(1)[6]);
    QString decoRegV1_7 = QString::number(processor->decoder.getVectorRegisterA(1)[7]);

    this->ui->label_RegV1_0->setText(decoRegV1_0);
    this->ui->label_RegV1_1->setText(decoRegV1_1);
    this->ui->label_RegV1_2->setText(decoRegV1_2);
    this->ui->label_RegV1_3->setText(decoRegV1_3);
    this->ui->label_RegV1_4->setText(decoRegV1_4);
    this->ui->label_RegV1_5->setText(decoRegV1_5);
    this->ui->label_RegV1_6->setText(decoRegV1_6);
    this->ui->label_RegV1_7->setText(decoRegV1_7);

    this->ui->label_RegV1_0->repaint();
    this->ui->label_RegV1_1->repaint();
    this->ui->label_RegV1_2->repaint();
    this->ui->label_RegV1_3->repaint();
    this->ui->label_RegV1_4->repaint();
    this->ui->label_RegV1_5->repaint();
    this->ui->label_RegV1_6->repaint();
    this->ui->label_RegV1_7->repaint();

    //-------2
    QString decoRegV2_0 = QString::number(processor->decoder.getVectorRegisterA(2)[0]);
    QString decoRegV2_1 = QString::number(processor->decoder.getVectorRegisterA(2)[1]);
    QString decoRegV2_2 = QString::number(processor->decoder.getVectorRegisterA(2)[2]);
    QString decoRegV2_3 = QString::number(processor->decoder.getVectorRegisterA(2)[3]);
    QString decoRegV2_4 = QString::number(processor->decoder.getVectorRegisterA(2)[4]);
    QString decoRegV2_5 = QString::number(processor->decoder.getVectorRegisterA(2)[5]);
    QString decoRegV2_6 = QString::number(processor->decoder.getVectorRegisterA(2)[6]);
    QString decoRegV2_7 = QString::number(processor->decoder.getVectorRegisterA(2)[7]);

    this->ui->label_RegV2_0->setText(decoRegV2_0);
    this->ui->label_RegV2_1->setText(decoRegV2_1);
    this->ui->label_RegV2_2->setText(decoRegV2_2);
    this->ui->label_RegV2_3->setText(decoRegV2_3);
    this->ui->label_RegV2_4->setText(decoRegV2_4);
    this->ui->label_RegV2_5->setText(decoRegV2_5);
    this->ui->label_RegV2_6->setText(decoRegV2_6);
    this->ui->label_RegV2_7->setText(decoRegV2_7);

    this->ui->label_RegV2_0->repaint();
    this->ui->label_RegV2_1->repaint();
    this->ui->label_RegV2_2->repaint();
    this->ui->label_RegV2_3->repaint();
    this->ui->label_RegV2_4->repaint();
    this->ui->label_RegV2_5->repaint();
    this->ui->label_RegV2_6->repaint();
    this->ui->label_RegV2_7->repaint();

    //-------3
    QString decoRegV3_0 = QString::number(processor->decoder.getVectorRegisterA(3)[0]);
    QString decoRegV3_1 = QString::number(processor->decoder.getVectorRegisterA(3)[1]);
    QString decoRegV3_2 = QString::number(processor->decoder.getVectorRegisterA(3)[2]);
    QString decoRegV3_3 = QString::number(processor->decoder.getVectorRegisterA(3)[3]);
    QString decoRegV3_4 = QString::number(processor->decoder.getVectorRegisterA(3)[4]);
    QString decoRegV3_5 = QString::number(processor->decoder.getVectorRegisterA(3)[5]);
    QString decoRegV3_6 = QString::number(processor->decoder.getVectorRegisterA(3)[6]);
    QString decoRegV3_7 = QString::number(processor->decoder.getVectorRegisterA(3)[7]);

    this->ui->label_RegV3_0->setText(decoRegV3_0);
    this->ui->label_RegV3_1->setText(decoRegV3_1);
    this->ui->label_RegV3_2->setText(decoRegV3_2);
    this->ui->label_RegV3_3->setText(decoRegV3_3);
    this->ui->label_RegV3_4->setText(decoRegV3_4);
    this->ui->label_RegV3_5->setText(decoRegV3_5);
    this->ui->label_RegV3_6->setText(decoRegV3_6);
    this->ui->label_RegV3_7->setText(decoRegV3_7);

    this->ui->label_RegV3_0->repaint();
    this->ui->label_RegV3_1->repaint();
    this->ui->label_RegV3_2->repaint();
    this->ui->label_RegV3_3->repaint();
    this->ui->label_RegV3_4->repaint();
    this->ui->label_RegV3_5->repaint();
    this->ui->label_RegV3_6->repaint();
    this->ui->label_RegV3_7->repaint();


    //-------4
    QString decoRegV4_0 = QString::number(processor->decoder.getVectorRegisterA(4)[0]);
    QString decoRegV4_1 = QString::number(processor->decoder.getVectorRegisterA(4)[1]);
    QString decoRegV4_2 = QString::number(processor->decoder.getVectorRegisterA(4)[2]);
    QString decoRegV4_3 = QString::number(processor->decoder.getVectorRegisterA(4)[3]);
    QString decoRegV4_4 = QString::number(processor->decoder.getVectorRegisterA(4)[4]);
    QString decoRegV4_5 = QString::number(processor->decoder.getVectorRegisterA(4)[5]);
    QString decoRegV4_6 = QString::number(processor->decoder.getVectorRegisterA(4)[6]);
    QString decoRegV4_7 = QString::number(processor->decoder.getVectorRegisterA(4)[7]);

    this->ui->label_RegV4_0->setText(decoRegV4_0);
    this->ui->label_RegV4_1->setText(decoRegV4_1);
    this->ui->label_RegV4_2->setText(decoRegV4_2);
    this->ui->label_RegV4_3->setText(decoRegV4_3);
    this->ui->label_RegV4_4->setText(decoRegV4_4);
    this->ui->label_RegV4_5->setText(decoRegV4_5);
    this->ui->label_RegV4_6->setText(decoRegV4_6);
    this->ui->label_RegV4_7->setText(decoRegV4_7);

    this->ui->label_RegV4_0->repaint();
    this->ui->label_RegV4_1->repaint();
    this->ui->label_RegV4_2->repaint();
    this->ui->label_RegV4_3->repaint();
    this->ui->label_RegV4_4->repaint();
    this->ui->label_RegV4_5->repaint();
    this->ui->label_RegV4_6->repaint();
    this->ui->label_RegV4_7->repaint();


    //-------5
    QString decoRegV5_0 = QString::number(processor->decoder.getVectorRegisterA(5)[0]);
    QString decoRegV5_1 = QString::number(processor->decoder.getVectorRegisterA(5)[1]);
    QString decoRegV5_2 = QString::number(processor->decoder.getVectorRegisterA(5)[2]);
    QString decoRegV5_3 = QString::number(processor->decoder.getVectorRegisterA(5)[3]);
    QString decoRegV5_4 = QString::number(processor->decoder.getVectorRegisterA(5)[4]);
    QString decoRegV5_5 = QString::number(processor->decoder.getVectorRegisterA(5)[5]);
    QString decoRegV5_6 = QString::number(processor->decoder.getVectorRegisterA(5)[6]);
    QString decoRegV5_7 = QString::number(processor->decoder.getVectorRegisterA(5)[7]);

    this->ui->label_RegV5_0->setText(decoRegV5_0);
    this->ui->label_RegV5_1->setText(decoRegV5_1);
    this->ui->label_RegV5_2->setText(decoRegV5_2);
    this->ui->label_RegV5_3->setText(decoRegV5_3);
    this->ui->label_RegV5_4->setText(decoRegV5_4);
    this->ui->label_RegV5_5->setText(decoRegV5_5);
    this->ui->label_RegV5_6->setText(decoRegV5_6);
    this->ui->label_RegV5_7->setText(decoRegV5_7);

    this->ui->label_RegV5_0->repaint();
    this->ui->label_RegV5_1->repaint();
    this->ui->label_RegV5_2->repaint();
    this->ui->label_RegV5_3->repaint();
    this->ui->label_RegV5_4->repaint();
    this->ui->label_RegV5_5->repaint();
    this->ui->label_RegV5_6->repaint();
    this->ui->label_RegV5_7->repaint();


    //-------6
    QString decoRegV6_0 = QString::number(processor->decoder.getVectorRegisterA(6)[0]);
    QString decoRegV6_1 = QString::number(processor->decoder.getVectorRegisterA(6)[1]);
    QString decoRegV6_2 = QString::number(processor->decoder.getVectorRegisterA(6)[2]);
    QString decoRegV6_3 = QString::number(processor->decoder.getVectorRegisterA(6)[3]);
    QString decoRegV6_4 = QString::number(processor->decoder.getVectorRegisterA(6)[4]);
    QString decoRegV6_5 = QString::number(processor->decoder.getVectorRegisterA(6)[5]);
    QString decoRegV6_6 = QString::number(processor->decoder.getVectorRegisterA(6)[6]);
    QString decoRegV6_7 = QString::number(processor->decoder.getVectorRegisterA(6)[7]);

    this->ui->label_RegV6_0->setText(decoRegV6_0);
    this->ui->label_RegV6_1->setText(decoRegV6_1);
    this->ui->label_RegV6_2->setText(decoRegV6_2);
    this->ui->label_RegV6_3->setText(decoRegV6_3);
    this->ui->label_RegV6_4->setText(decoRegV6_4);
    this->ui->label_RegV6_5->setText(decoRegV6_5);
    this->ui->label_RegV6_6->setText(decoRegV6_6);
    this->ui->label_RegV6_7->setText(decoRegV6_7);

    this->ui->label_RegV6_0->repaint();
    this->ui->label_RegV6_1->repaint();
    this->ui->label_RegV6_2->repaint();
    this->ui->label_RegV6_3->repaint();
    this->ui->label_RegV6_4->repaint();
    this->ui->label_RegV6_5->repaint();
    this->ui->label_RegV6_6->repaint();
    this->ui->label_RegV6_7->repaint();


    //-------7
    QString decoRegV7_0 = QString::number(processor->decoder.getVectorRegisterA(7)[0]);
    QString decoRegV7_1 = QString::number(processor->decoder.getVectorRegisterA(7)[1]);
    QString decoRegV7_2 = QString::number(processor->decoder.getVectorRegisterA(7)[2]);
    QString decoRegV7_3 = QString::number(processor->decoder.getVectorRegisterA(7)[3]);
    QString decoRegV7_4 = QString::number(processor->decoder.getVectorRegisterA(7)[4]);
    QString decoRegV7_5 = QString::number(processor->decoder.getVectorRegisterA(7)[5]);
    QString decoRegV7_6 = QString::number(processor->decoder.getVectorRegisterA(7)[6]);
    QString decoRegV7_7 = QString::number(processor->decoder.getVectorRegisterA(7)[7]);

    this->ui->label_RegV7_0->setText(decoRegV7_0);
    this->ui->label_RegV7_1->setText(decoRegV7_1);
    this->ui->label_RegV7_2->setText(decoRegV7_2);
    this->ui->label_RegV7_3->setText(decoRegV7_3);
    this->ui->label_RegV7_4->setText(decoRegV7_4);
    this->ui->label_RegV7_5->setText(decoRegV7_5);
    this->ui->label_RegV7_6->setText(decoRegV7_6);
    this->ui->label_RegV7_7->setText(decoRegV7_7);

    this->ui->label_RegV7_0->repaint();
    this->ui->label_RegV7_1->repaint();
    this->ui->label_RegV7_2->repaint();
    this->ui->label_RegV7_3->repaint();
    this->ui->label_RegV7_4->repaint();
    this->ui->label_RegV7_5->repaint();
    this->ui->label_RegV7_6->repaint();
    this->ui->label_RegV7_7->repaint();


    //-----------------------Vector Registers
    QString decoRegS_0 = QString::number(processor->decoder.getScalarRegister(0));
    QString decoRegS_1 = QString::number(processor->decoder.getScalarRegister(1));
    QString decoRegS_2 = QString::number(processor->decoder.getScalarRegister(2));
    QString decoRegS_3 = QString::number(processor->decoder.getScalarRegister(3));
    QString decoRegS_4 = QString::number(processor->decoder.getScalarRegister(4));
    QString decoRegS_5 = QString::number(processor->decoder.getScalarRegister(5));
    QString decoRegS_6 = QString::number(processor->decoder.getScalarRegister(6));
    QString decoRegS_7 = QString::number(processor->decoder.getScalarRegister(7));

    this->ui->label_RegScalar0->setText(decoRegS_0);
    this->ui->label_RegScalar1->setText(decoRegS_1);
    this->ui->label_RegScalar2->setText(decoRegS_2);
    this->ui->label_RegScalar3->setText(decoRegS_3);
    this->ui->label_RegScalar4->setText(decoRegS_4);
    this->ui->label_RegScalar5->setText(decoRegS_5);
    this->ui->label_RegScalar6->setText(decoRegS_6);
    this->ui->label_RegScalar7->setText(decoRegS_7);

    this->ui->label_RegScalar0->repaint();
    this->ui->label_RegScalar1->repaint();
    this->ui->label_RegScalar2->repaint();
    this->ui->label_RegScalar3->repaint();
    this->ui->label_RegScalar4->repaint();
    this->ui->label_RegScalar5->repaint();
    this->ui->label_RegScalar6->repaint();
    this->ui->label_RegScalar7->repaint();


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
    QString decoImm = QString::number(processor->decoder.Imm);
    QString decoRg = QString::number(processor->decoder.RgDecoOut); //Para numeros
    QString decoRs = QString::number(processor->fetch_decoder_register.RvsDo); //Para numeros
    QString decoRp = QString::number(processor->fetch_decoder_register.RvpDo);


    //cout << processor->fetch.Do << "\n";


    this->ui->labelRs->setText(decoRs);
    this->ui->labelRp->setText(decoRp);
    this->ui->labelRg->setText(decoRg);
    this->ui->LabelImmDeco->setText(decoImm);
    this->ui->LabelImmDeco->repaint();
    //-------OUT REGISTERS
    //---Scalar
    this->ui->label_decoDoAScalar->setText(decoDOAScalar);
    this->ui->label_decoDoBScalar->setText(decoDOBScalar);
    //------Vectors
    //Input

    //----OpA
    this->ui->LabelOpAVector_0->setText(decoDOAVector_0);
    this->ui->LabelOpAVector_1->setText(decoDOAVector_1);
    this->ui->LabelOpAVector_2->setText(decoDOAVector_2);
    this->ui->LabelOpAVector_3->setText(decoDOAVector_3);
    this->ui->LabelOpAVector_4->setText(decoDOAVector_4);
    this->ui->LabelOpAVector_5->setText(decoDOAVector_5);
    this->ui->LabelOpAVector_6->setText(decoDOAVector_6);
    this->ui->LabelOpAVector_7->setText(decoDOAVector_7);
    //----OpB
    this->ui->label_DoBV_0->setText(decoDOBVector_0);
    this->ui->label_DoBV_1->setText(decoDOBVector_1);
    this->ui->label_DoBV_2->setText(decoDOBVector_2);
    this->ui->label_DoBV_3->setText(decoDOBVector_3);
    this->ui->label_DoBV_4->setText(decoDOBVector_4);
    this->ui->label_DoBV_5->setText(decoDOBVector_5);
    this->ui->label_DoBV_6->setText(decoDOBVector_6);
    this->ui->label_DoBV_7->setText(decoDOBVector_7);

    //Output
    //----A
    this->ui->label_DoAV_0->setText(decoDOAVector_0);
    this->ui->label_DoAV_1->setText(decoDOAVector_1);
    this->ui->label_DoAV_2->setText(decoDOAVector_2);
    this->ui->label_DoAV_3->setText(decoDOAVector_3);
    this->ui->label_DoAV_4->setText(decoDOAVector_4);
    this->ui->label_DoAV_5->setText(decoDOAVector_5);
    this->ui->label_DoAV_6->setText(decoDOAVector_6);
    this->ui->label_DoAV_7->setText(decoDOAVector_7);
    //----B
    this->ui->label_DoBV_0->setText(decoDOBVector_0);
    this->ui->label_DoBV_1->setText(decoDOBVector_1);
    this->ui->label_DoBV_2->setText(decoDOBVector_2);
    this->ui->label_DoBV_3->setText(decoDOBVector_3);
    this->ui->label_DoBV_4->setText(decoDOBVector_4);
    this->ui->label_DoBV_5->setText(decoDOBVector_5);
    this->ui->label_DoBV_6->setText(decoDOBVector_6);
    this->ui->label_DoBV_7->setText(decoDOBVector_7);

    this->ui->labelRs->repaint();
    this->ui->labelRg->repaint();
    this->ui->labelRp->repaint();
    this->ui->label_decoDoAScalar->repaint();
    this->ui->label_decoDoBScalar->repaint();


}

void MainWindow::setProcessor(VectorProcessor* newProc)
{
    processor = newProc;
}


void MainWindow::on_pushButton_Fetch_clicked()
{
    this->ui->widget_fetch->setVisible(this->fetchVisibility);
    this->fetchVisibility = !this->fetchVisibility;
}

void MainWindow::on_pushButton_Deco_clicked()
{
    this->ui->widget_DecoAll->setVisible(this->decoVisibility);
    this->decoVisibility = !this->decoVisibility;
}

void MainWindow::on_pushButton_Exe_clicked()
{
    this->ui->widget_exe->setVisible(this->exeVisibility);
    this->exeVisibility = !this->exeVisibility;
}


void MainWindow::on_pushButton_Mem_clicked()
{
    this->ui->widget_mem->setVisible(this->memVisibility);
    this->memVisibility = !this->memVisibility;
}

void MainWindow::on_pushButton_WB_clicked()
{
    this->ui->widget_wb->setVisible(this->wbVisibility);
    this->wbVisibility = !this->wbVisibility;
}
