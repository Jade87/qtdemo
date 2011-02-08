#ifndef TIMER_H
#define TIMER_H
#include "chekos.h"
#include <QTimer>
#include <QTextEdit>
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

/*class wTimer
{
    public:
    wTimer();
    QString strings;
    QString time;
    protected :
    
}
void updateWinList()
{
    
    QLabel *lab1=new QLabel();

    QStringList list(getAllWindow());
    init();
    for (int i = 0; i < list.size(); i++)
    {
    strings += list[i] + "\n";
    }
    lab1->setText(strings);
    QRect rec(200,200,400,150);
    lab1->setGeometry(rec);
    lab1->show();
    strings ="";
    clearList();
}*/



#endif // TIMER_H
