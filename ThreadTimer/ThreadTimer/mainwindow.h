#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QThread>

class Worker : public QObject
{
    Q_OBJECT
public:
    Worker();
    ~Worker();
private:
    QTimer t;
public slots:
    void process();
    void startWorker();
    //void stopProcess();
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
   QThread workerThread;
   Worker wt;
};

#endif // MAINWINDOW_H
