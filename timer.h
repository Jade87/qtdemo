#ifndef TIMER_H
#define TIMER_H
#include "chekos.h"
class showWin : public QLabel
{
    private :
            bool t_show;
            QString strings;
            QString time;
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
            strings ="";
            clearList();
        }
    public :
            showWin(const QString& strText,
                    int nInterval = 200,
                    QWidget* pwgt = 0)
            : QLabel(strText,pwgt)
            , t_show(true)
            , strings()
            , time()

    {
        startTimer(nInterval);
    }

};


#endif // TIMER_H
