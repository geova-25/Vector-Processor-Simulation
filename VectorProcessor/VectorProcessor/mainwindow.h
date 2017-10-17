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


private slots:
    void on_labelFetch_linkActivated(const QString &link);
    void getFetchData();
    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    int i;
    bool fetchLabelVisibility;
    bool decodeLabelVisibility;
    bool executeLabelVisibility;
    bool writeBackLabelVisibility;


};

#endif // MAINWINDOW_H
