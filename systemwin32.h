
#ifndef SYSTEMWIN32_H
#define SYSTEMWIN32_H

#include <windows.h>
#include <w32api.h>
#include <tlhelp32.h>
#include <QMap>
#include <QString>
#include <QMessageBox>
#include <iostream>

class sWin32
{
    public:
    sWin32();
    QStringList getAllWindow();
    BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam);
    private:
    QMap <int,QString> win32map;
    QString copyToQString(WCHAR array[MAX_PATH]);

};

#endif
