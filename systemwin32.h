// systemwin32.h
#ifndef SYSTEMWIN32_H
#define SYSTEMWIN32_H

#include <windows.h>
#include <w32api.h>
#include <tlhelp32.h>

#include <QMap>
#include <QString>
#include <QMessageBox>

class systemWin32
{
public:
    systemWin32();
    bool findProcess(QString findProcName);
    QString getProcessName(int idProcess);
    QStringList getAllProcessList();
private:
    QMap <int, QString> win32sysMap;
    QString copyToQString(WCHAR array[MAX_PATH]);

};

#endif // SYSTEMWIN32_H
