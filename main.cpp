#include "main.h"




int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    QLabel *label = new QLabel;

    bool ok;

    systemWin32 processesInWin;

    int ret = QMessageBox::information(0, "Question", "Do you want see all list of process?", QMessageBox::Ok | QMessageBox::Cancel);

    if (ret == QMessageBox::Ok)
    {
        QStringList list(processesInWin.getAllProcessList());
        QString strings;

        for (int i = 0; i < list.size(); i++)
        {
            strings += list[i] + "\n";
        }

        label->setText(strings);
        label->show();
    }


    return app.exec();
}
