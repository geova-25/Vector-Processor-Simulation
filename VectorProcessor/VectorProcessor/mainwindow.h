#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <unistd.h>
#include <pthread.h>
#include "vectorProcessor.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void newValue();
    static void* threadTest(void*);
    VectorProcessor* processor;
    void setProcessor(VectorProcessor* newProc);
    int ciclo;


private slots:
    void on_labelFetch_linkActivated(const QString &link);

    void getFetchData();

    void getCicloMasUno();

    void on_pushButton_Exe_clicked();

    void on_pushButton_Fetch_clicked();

    void on_pushButton_Deco_clicked();

    void on_pushButton_Mem_clicked();

    void on_pushButton_WB_clicked();

private:
    Ui::MainWindow *ui;
    int i;
    bool fetchVisibility;
    bool decoVisibility;
    bool exeVisibility;
    bool memVisibility;
    bool wbVisibility;


};

#endif // MAINWINDOW_H
