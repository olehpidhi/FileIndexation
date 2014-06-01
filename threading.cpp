#include "threading.h"

Thread::Thread(Runnable* run):
    runnable(run)
{
    if(!runnable.get())
    {
        printError("Pointer creation failed");
    }
    threadHandle = (HANDLE)_beginthreadex(NULL, 0, Thread::startThreadRunnable,(LPVOID)this, CREATE_SUSPENDED | THREAD_SUSPEND_RESUME, &threadId);
    if(!threadHandle)
    {
       printError("Thread creation failed");
    }

}

Thread::Thread()
{
    threadHandle = (HANDLE)_beginthreadex(NULL, 0, Thread::startThread,(LPVOID)this, CREATE_SUSPENDED, &threadId);
    if(!threadHandle)
    {
        printError("Thread creation failed");
    }
}


unsigned WINAPI Thread::startThreadRunnable(LPVOID pVoid)
{
    Thread* runnableThread = static_cast<Thread*>(pVoid);
    runnableThread->result = runnableThread->runnable->run();
    runnableThread->setCompleted();
    return reinterpret_cast<unsigned>(runnableThread->result);
}

unsigned WINAPI Thread::startThread(LPVOID pVoid)
{
    Thread* suspendedThread = static_cast<Thread*>(pVoid);
    suspendedThread->result = suspendedThread->run();
    suspendedThread->setCompleted();
    return reinterpret_cast<unsigned>(suspendedThread->result);
}

Thread::~Thread()
{
    if(threadId != GetCurrentThreadId())
    {
        WaitForSingleObject(threadHandle, INFINITE);
        DWORD closeResult = CloseHandle(threadHandle);
        if(!closeResult)
        {
            printError("Thread handle close failed");
        }
    }
}

void Thread::start()
{
    assert(threadHandle);
    ResumeThread(threadHandle);
}

void* Thread::join()
{
    return result;
}

void* Thread::run(){return 0;}

void Thread::terminate()
{
    TerminateThread(threadHandle, NULL);
}

void Thread::setCompleted()
{

}

void Thread::suspend()
{
    SuspendThread(threadHandle);
}

void Thread::printError(const QString& message)
{
    TCHAR szBuf[256];
    LPSTR lpErrorBuf;
    DWORD errorCode = GetLastError();
    FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER || FORMAT_MESSAGE_FROM_SYSTEM,
                  NULL, errorCode, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                  (LPTSTR)&lpErrorBuf, 0, NULL);
    QErrorMessage msg;
    msg.showMessage(lpErrorBuf);
    LocalFree(lpErrorBuf);
    exit(errorCode);
}

Runnable::~Runnable(){}
