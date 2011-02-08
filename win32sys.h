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
QMap <int,QString> hist;


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
QString countTime(QTime curTime)
{

    QString t;
    t.setNum(curTime.elapsed());
    return t;

}

BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam) {
     DWORD dwThreadId, dwProcessId;
     HINSTANCE hInstance;
     TCHAR String[255];
     HANDLE hProcess;
     QString active;

    QString timeHour,timeMin,timeSec,tiMs;
    FILETIME ProcessStartTime, ProcessEndTime, KernelTime, UserTime;
    SYSTEMTIME LocalCreationTime,LocalExitTime;
    SYSTEMTIME Stime,Etime;


    if (!hWnd)
        return TRUE;
    if (!::IsWindowVisible(hWnd))
        return TRUE;
    if (!SendMessage(hWnd, WM_GETTEXT, sizeof(String), (LPARAM)String))
        return TRUE;

    hInstance = (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE);
    dwThreadId = GetWindowThreadProcessId(hWnd, &dwProcessId);
    hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessId);
    GetProcessTimes(hProcess, &ProcessStartTime, &ProcessEndTime, &KernelTime, &UserTime);
    FileTimeToSystemTime(&ProcessStartTime,&Stime);
    FileTimeToSystemTime(&ProcessEndTime,&Etime);
    SystemTimeToTzSpecificLocalTime(NULL,&Stime,&LocalExitTime);


    if (hWnd == GetForegroundWindow())
    {
        GetLocalTime(&LocalCreationTime);
        active = "Set Focus";

        timeHour.setNum((((LocalCreationTime.wHour*60)-(LocalExitTime.wHour*60))+(LocalCreationTime.wMinute-LocalExitTime.wMinute)));
        //timeMin.setNum();
        timeSec.setNum(LocalCreationTime.wSecond);
        tiMs = "   runtime : ["+timeHour+"m "+timeSec+"s]";
        win32map[dwProcessId]=copyToQString(String)+tiMs;
    }
    else
    {

        active = "";

    }


    CloseHandle(hProcess);
   // hist[dwProcessId]=copyToQString(String)+" - "+active+" - "+timeHour+"h "+timeMin+"m "+timeSec+"s;||";

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
QStringList showHist()
{
    return hist.values();
}


#endif // WIN32SYS_H
