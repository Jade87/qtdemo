#ifndef WIN32SYS_H
#define WIN32SYS_H


#include <windows.h>
#include <psapi.h>		// NT only!
#include <iostream>
#include <QString>
#include <QMap>
#include <QStringList>

using namespace std;


QMap <int,QString> win32map;
QString copyToQString(WCHAR array[MAX_PATH])
{
    QString string;
    int i = 0;

    while (array[i] != 0)
    {
        string[i] = array[i];
        i++;
    }
    return string;
}

BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam) {
     DWORD dwThreadId, dwProcessId;
     HINSTANCE hInstance;
     TCHAR String[255];
     HANDLE hProcess;

    if (!hWnd)
        return TRUE;
    if (!::IsWindowVisible(hWnd))
        return TRUE;
    if (!SendMessage(hWnd, WM_GETTEXT, sizeof(String), (LPARAM)String))
        return TRUE;
    hInstance = (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE);
    dwThreadId = GetWindowThreadProcessId(hWnd, &dwProcessId);
    hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessId);

    win32map[dwProcessId]=copyToQString(String);
    CloseHandle(hProcess);

    return true;
}

QStringList getAllWindow()
{
    return win32map.values();
}
void clearList()
{
   win32map.clear();
}
BOOL init()
{
    return EnumWindows(EnumWindowsProc, NULL);
}

#endif // WIN32SYS_H
