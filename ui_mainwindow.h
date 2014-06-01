/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QTableView *tableView;
    QGroupBox *controlsGroupBox;
    QHBoxLayout *controlsHorizontalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *startButton;
    QPushButton *pauseButton;
    QPushButton *resumeButton;
    QPushButton *stopButton;
    QGroupBox *searchGroupBox;
    QGridLayout *gridLayout;
    QHBoxLayout *searchOptionsHorizontalLayout;
    QRadioButton *nameRadioButton;
    QRadioButton *extensionRadioButton;
    QRadioButton *dateRadioButton;
    QRadioButton *sizeRadioButton;
    QPushButton *findButton;
    QLineEdit *searchLineEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(431, 401);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setDockNestingEnabled(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));

        verticalLayout_2->addWidget(tableView);

        controlsGroupBox = new QGroupBox(centralWidget);
        controlsGroupBox->setObjectName(QStringLiteral("controlsGroupBox"));
        controlsHorizontalLayout = new QHBoxLayout(controlsGroupBox);
        controlsHorizontalLayout->setSpacing(6);
        controlsHorizontalLayout->setContentsMargins(11, 11, 11, 11);
        controlsHorizontalLayout->setObjectName(QStringLiteral("controlsHorizontalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        startButton = new QPushButton(controlsGroupBox);
        startButton->setObjectName(QStringLiteral("startButton"));

        horizontalLayout->addWidget(startButton);

        pauseButton = new QPushButton(controlsGroupBox);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));

        horizontalLayout->addWidget(pauseButton);

        resumeButton = new QPushButton(controlsGroupBox);
        resumeButton->setObjectName(QStringLiteral("resumeButton"));

        horizontalLayout->addWidget(resumeButton);

        stopButton = new QPushButton(controlsGroupBox);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setFlat(false);

        horizontalLayout->addWidget(stopButton);


        controlsHorizontalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addWidget(controlsGroupBox);

        searchGroupBox = new QGroupBox(centralWidget);
        searchGroupBox->setObjectName(QStringLiteral("searchGroupBox"));
        gridLayout = new QGridLayout(searchGroupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        searchOptionsHorizontalLayout = new QHBoxLayout();
        searchOptionsHorizontalLayout->setSpacing(6);
        searchOptionsHorizontalLayout->setObjectName(QStringLiteral("searchOptionsHorizontalLayout"));
        nameRadioButton = new QRadioButton(searchGroupBox);
        nameRadioButton->setObjectName(QStringLiteral("nameRadioButton"));
        nameRadioButton->setChecked(true);

        searchOptionsHorizontalLayout->addWidget(nameRadioButton);

        extensionRadioButton = new QRadioButton(searchGroupBox);
        extensionRadioButton->setObjectName(QStringLiteral("extensionRadioButton"));

        searchOptionsHorizontalLayout->addWidget(extensionRadioButton);

        dateRadioButton = new QRadioButton(searchGroupBox);
        dateRadioButton->setObjectName(QStringLiteral("dateRadioButton"));

        searchOptionsHorizontalLayout->addWidget(dateRadioButton);

        sizeRadioButton = new QRadioButton(searchGroupBox);
        sizeRadioButton->setObjectName(QStringLiteral("sizeRadioButton"));

        searchOptionsHorizontalLayout->addWidget(sizeRadioButton);


        gridLayout->addLayout(searchOptionsHorizontalLayout, 3, 0, 1, 2);

        findButton = new QPushButton(searchGroupBox);
        findButton->setObjectName(QStringLiteral("findButton"));

        gridLayout->addWidget(findButton, 0, 1, 1, 1);

        searchLineEdit = new QLineEdit(searchGroupBox);
        searchLineEdit->setObjectName(QStringLiteral("searchLineEdit"));

        gridLayout->addWidget(searchLineEdit, 0, 0, 1, 1);


        verticalLayout_2->addWidget(searchGroupBox);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setAutoFillBackground(true);
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        controlsGroupBox->setTitle(QApplication::translate("MainWindow", "Controls", 0));
        startButton->setText(QApplication::translate("MainWindow", "Start", 0));
        pauseButton->setText(QApplication::translate("MainWindow", "Pause", 0));
        resumeButton->setText(QApplication::translate("MainWindow", "Resume", 0));
        stopButton->setText(QApplication::translate("MainWindow", "Stop", 0));
        searchGroupBox->setTitle(QApplication::translate("MainWindow", "Search", 0));
        nameRadioButton->setText(QApplication::translate("MainWindow", "by Name", 0));
        extensionRadioButton->setText(QApplication::translate("MainWindow", "by Extension", 0));
        dateRadioButton->setText(QApplication::translate("MainWindow", "by Date", 0));
        sizeRadioButton->setText(QApplication::translate("MainWindow", "by Size", 0));
        findButton->setText(QApplication::translate("MainWindow", "Find", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
