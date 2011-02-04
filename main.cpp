#define STRICT  1
#include <QApplication>
#include <windows.h>
#include <psapi.h>		// NT only!
#include <iostream>
#include <QTextEdit>
#include <QtGui>
using namespace std;

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
 QMap <int,QString> win32map;
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

int main(int argc, char *argv[]) {
QApplication a(argc,argv);
QLabel *lab1 = new QLabel();

EnumWindows(EnumWindowsProc, NULL);
QStringList list(getAllWindow());
    QString strings;
    for (int i = 0; i < list.size(); i++)
        {
            strings += list[i] + "\n";
        }
    lab1->setText(strings);
lab1 -> show();
return a.exec();
}
