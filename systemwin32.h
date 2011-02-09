// systemwin32.h
#ifndef SYSTEMWIN32_H
#define SYSTEMWIN32_H

#include <windows.h>
#include <w32api.h>
#include <tlhelp32.h>
#include <QStringList>

#include <QMap>
#include <QString>
QMap <int, QString> win32sysMap;
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

BOOL CALLBACK EnumWindowsProc(HWND hWnd,LPARAM lParam)
{
   DWORD dwThreadId, dwProcessId;
    HINSTANCE hInstance;
    TCHAR String[255];
    HANDLE hProcess;



     HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hSnap == NULL)
    {

        return false;
    }

    PROCESSENTRY32 proc = { sizeof(proc) };

    if (Process32First(hSnap, &proc))
    {
        QString filename,procId,procModule;

        filename = copyToQString(proc.szExeFile);
        win32sysMap[proc.th32ProcessID] = filename;

        while (Process32Next(hSnap, &proc))
        {

    //if (!hWnd)
    //    return TRUE;
   // if (!::IsWindowVisible(hWnd))
    //    return TRUE;
   if (!SendMessage(hWnd, WM_GETTEXT, sizeof(String), (LPARAM)String))
     // return TRUE;

    hInstance = (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE);
    dwThreadId = GetWindowThreadProcessId(hWnd, &dwProcessId);
    hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessId);
     filename = copyToQString(proc.szExeFile);
            procId.setNum(proc.th32ProcessID);
            procModule.setNum(proc.cntThreads);

    if (hWnd == GetForegroundWindow())
    {
        GetWindowText(hWnd,String,sizeof(String));
        win32sysMap[proc.th32ProcessID] = "Process name-|"+filename +"|-ProcessId-|"+procId+"|-Threads-|"+procModule+"|-Window-|"+copyToQString(String);


    }

    CloseHandle(hProcess);

        }
    }
    return true;
}





QStringList getAllWindow()
{
    return win32sysMap.values();
}
void clearList()
{
   win32sysMap.clear();
}
BOOL init()
{
    return EnumWindows(EnumWindowsProc, NULL);
}

#endif // SYSTEMWIN32_H
