#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DiscFunctions.h"
#include "Serializer.h"

std::list<std::string> discLetters;
std::list<FileInfo> filesData;
uintptr_t threadHandle;

uintptr_t __stdcall threadFunction(void* labelPtr);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    discLetters = getDiscsLetters();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    ui->currentDirectoryLabel->setText("ABCD");
    threadHandle = _beginthreadex(NULL, 0, &threadFunction, (void*)(ui->currentDirectoryLabel), NULL, NULL);
}

void MainWindow::on_pauseButton_clicked()
{
    SuspendThread((HANDLE) threadHandle);
}

void MainWindow::on_stopButton_clicked()
{
    ResumeThread((HANDLE) threadHandle);
}

void MainWindow::on_findButton_clicked()
{

}

uintptr_t __stdcall threadFunction(void* labelPtr)
{
    for(std::list<std::string>::iterator i = discLetters.begin(); i != discLetters.end(); ++i)
    {
        findAllFilesInDirectory((*i).c_str(), filesData, (QLabel*)labelPtr);
    }
    Serializer<std::list<FileInfo>> xmlFile("D:\\res.xml");
    xmlFile.serialize(filesData);
}
