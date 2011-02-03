#include "systemwin32.h"

systemWin32::systemWin32()
{
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (hSnap == NULL)
    {
        QMessageBox::critical(0, "Error!", "Error Load ToolHelp", QMessageBox::Close);
        return;
    }

    PROCESSENTRY32 proc = { sizeof(proc) };

    if (Process32First(hSnap, &proc))
    {
        QString filename;

        filename = copyToQString(proc.szExeFile);
        win32sysMap[proc.th32ProcessID] = filename;

        while (Process32Next(hSnap, &proc))
        {
            filename = copyToQString(proc.szExeFile);
            win32sysMap[proc.th32ProcessID] = filename;
        }
    }
}

// ��������� ��� ��������, ���������� true, ���� ������� �������
bool systemWin32::findProcess(QString findProcName)
{
    QMapIterator<int, QString> i(win32sysMap);
    while (i.hasNext())
    {
        i.next();
        if (i.value() == findProcName) return true;
    }

    return false;
}

// �������� ��� �������� �� ID-�
QString systemWin32::getProcessName(int idProcess)
{
    return win32sysMap[idProcess];
}

// ����� ��������� WinAPI ������������ ��� ������ WCHAR. ��� �������� - ������� � QString
// ���, ����� ���-���� �� ������� ����� �������
QString systemWin32::copyToQString(WCHAR array[MAX_PATH])
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

// �������� ������ ���� ���������
QStringList systemWin32::getAllProcessList()
{
    return win32sysMap.values();
}

