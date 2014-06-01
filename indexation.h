#ifndef INDEXATION_H
#define INDEXATION_H
#include "threading.h"
#include <QObject>
#include <list>
#include <string>
#include <FileInfo.h>
#include <sstream>
#include <deque>


class IndexatorRunnable: public QObject, public Runnable
{
    Q_OBJECT
public:
    std::list<std::wstring> drivesLetters;
    std::deque<FileInfo> filesData;
    bool canTerminate;

    IndexatorRunnable();

    ~IndexatorRunnable();

    void* run();

    void iterateAllFilesInDirectory(const wchar_t* directoryPath);

    void getDrivesLetters();

    void terminate();

signals:
    void textChanged(QString);
    void indexationCompleted(bool);

};


#endif // INDEXATION_H
