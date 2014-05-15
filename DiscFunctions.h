#ifndef DISKFUNCTIONS_H
#define DISKFUNCTIONS_H
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <strsafe.h>
#include "FileInfo.h"
#include <list>
#include <QLabel>

void DisplayErrorBox(LPTSTR lpszFunction);

void findAllFilesInDirectory(const CHAR* directoryPath, std::list<FileInfo>& filesData, QLabel* directoryLabel);

std::list<std::string> getDiscsLetters();

#endif // DISKFUNCTIONS_H
