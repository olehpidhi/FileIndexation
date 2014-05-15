#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <list>
#include <string>

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

private:
    Ui::MainWindow *ui;
};

extern std::list<std::string> discLetters;

#endif // MAINWINDOW_H
