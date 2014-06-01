#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "indexation.h"
#include <memory>
#include <QAbstractListModel>
#include <Serializer.h>
#include "FileInfo.h"
#include "filestablemodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_startButton_clicked();

    void on_pauseButton_clicked();

    void on_stopButton_clicked();

    void on_findButton_clicked();

    void on_resumeButton_clicked();

private:
    Ui::MainWindow *ui;
};


extern QLabel* currentDirLabel;
extern IndexatorRunnable indexatorRunnable;
extern Thread* indexatorThread;
extern FilesTableModel model;
#endif // MAINWINDOW_H
