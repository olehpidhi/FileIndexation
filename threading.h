#ifndef THREADING_H
#define THREADING_H


#include <windows.h>
#include <process.h>
#include <memory>
#include <cassert>
#include <QErrorMessage>
#include <QString>

class Runnable
{
public:
    virtual void* run() = 0;
    virtual ~Runnable();
};

class Thread
{
private:
    HANDLE threadHandle;
    unsigned threadId;

    std::unique_ptr<Runnable> runnable;

    Thread(const Thread&);

    const Thread& operator=(const Thread&);

    void setCompleted();

    void* result;

    void* run();

    static unsigned WINAPI startThreadRunnable(LPVOID pVoid);

    static unsigned WINAPI startThread(LPVOID pVoid);
public:
    Thread(Runnable* run);
    Thread();
    ~Thread();

    void start();
    void suspend();
    void terminate();
    void* join();
    void printError(const QString& message);
};

#endif // THREADING_H
