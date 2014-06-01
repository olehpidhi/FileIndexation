#include "mainwindow.h"
#include "ui_mainwindow.h"

QLabel* currentDirLabel;
IndexatorRunnable indexatorRunnable;
Thread* indexatorThread ;
FilesTableModel model;

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    currentDirLabel = new QLabel();
    currentDirLabel->setWordWrap(true);
    currentDirLabel->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    ui->statusBar->addWidget(currentDirLabel);
    ui->statusBar->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    connect(&model,SIGNAL(dataChanged(QModelIndex,QModelIndex)), ui->tableView, SLOT(dataChanged(QModelIndex,QModelIndex)));
    connect(&indexatorRunnable, SIGNAL(textChanged(QString)), currentDirLabel, SLOT(setText(QString)));
    connect(&indexatorRunnable, SIGNAL(indexationCompleted(bool)), ui->findButton, SLOT(setEnabled(bool)));
    connect(&indexatorRunnable, SIGNAL(indexationCompleted(bool)), ui->startButton, SLOT(setEnabled(bool)));
}

MainWindow::~MainWindow()
{
    delete currentDirLabel;
    delete indexatorThread;
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    ui->findButton->setEnabled(false);
    ui->startButton->setEnabled(false);
    indexatorThread = new Thread(&indexatorRunnable);
    indexatorThread->start();
}

void MainWindow::on_pauseButton_clicked()
{
    ui->findButton->setEnabled(true);
    indexatorThread->suspend();
    indexatorRunnable.textChanged("Pasued");
}

void MainWindow::on_stopButton_clicked()
{
    ui->findButton->setEnabled(true);
    ui->startButton->setEnabled(true);
    indexatorRunnable.terminate();
    indexatorRunnable.textChanged("Stopped");
}

void MainWindow::on_resumeButton_clicked()
{
    ui->findButton->setEnabled(true);
    indexatorThread->start();
}

void MainWindow::on_findButton_clicked()
{
    ui->tableView->setModel(nullptr);
    if(ui->searchLineEdit->text() != "")
    {
        model.filesList.clear();

        QString toFind = ui->searchLineEdit->text();

        if(ui->dateRadioButton->isChecked())
        {
            for (FileInfo i : indexatorRunnable.filesData)
            {
                if(SystemTimeToQDateTime(i.getDate()).toString() == toFind)
                {
                    model.filesList.push_back(i);
                }
            }
        }

        else if(ui->sizeRadioButton->isChecked())
        {
            for (FileInfo i : indexatorRunnable.filesData)
            {
                if(i.getSize() == toFind.toUInt())
                {
                    model.filesList.push_back(i);
                }
            }
        }

        else if(ui->extensionRadioButton->isChecked())
        {
            for (FileInfo i : indexatorRunnable.filesData)
            {

                std::wstring extension = i.getName();
                extension.erase(extension.begin(), extension.begin() + extension.find('.'));
                if(extension == toFind.toStdWString())
                {
                    model.filesList.push_back(i);
                }
            }
        }

        else if(ui->nameRadioButton->isChecked())
        {
            for (FileInfo i : indexatorRunnable.filesData)
            {
                if(i.getName().find(toFind.toStdWString().c_str()) != std::string::npos)
                {
                    model.filesList.push_back(i);
                }
            }
        }
        ui->tableView->setModel(&model);

    }
    else
    {
        currentDirLabel->setText("Specify search criteria");
    }

}
