#ifndef TIMESHOW_H
#define TIMESHOW_H
#include "chekos.h"
#include <QTimer>
#include <QTextEdit>
class showTime : public QLabel
{
    private :
            bool t_show;

            int time;
    protected:
         virtual void timerEvent(QTimerEvent*)
         {
            time++;
            str.setNum(time);
        }
    public :
            QString str;
            showTime(const QString& strText,
                    int nInterval = 1000,
                    QWidget* pwgt = 0)
            : QLabel(strText,pwgt)
            , str()
            , time()

    {
        startTimer(nInterval);
    }

};

#endif // TIMESHOW_H
