#ifndef TIMER_H
#define TIMER_H
#include "chekos.h"
#include <QTimer>
#include <QTextEdit>
#include <QFile>
class showWin : public QLabel
{
    private :
            bool t_show;
            QString strings;
            QString time;
            QFile file;
            char a[1024];

    protected:
         virtual void timerEvent(QTimerEvent*)
         {

            init();
            QStringList list(getAllWindow());
            for (int i = 0; i < list.size(); i++)
             {
                 strings += list[i] + "\n";
             }
            setText(strings);
            if(file.exists()){

            }

            file.open(QIODevice::WriteOnly);
            file.flush();
            file.write((char*)&strings,sizeof((char*)&strings));
            strings ="";
            clearList();
            file.close();
        }
    public :
            showWin(const QString& strText,
                    int nInterval = 1000,
                    QWidget* pwgt = 0)
            : QLabel(strText,pwgt)
            , t_show(true)
            , strings()
            , time()
            //, history()

    {
        startTimer(nInterval);
    file.setFileName("test.txt");
    QTextStream st(&file);
    }


};

#endif // TIMER_H
