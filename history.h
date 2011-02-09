#ifndef HISTORY_H
#define HISTORY_H

#include "chekos.h"
#include <QString>
//#include <QLabel>
#include <QStringList>

struct hist
{
    HWND hWnd;
    QString date;
};
QMap <int,hist> list;
bool saveHist(int key,HWND hW,QString dT)
{
    list[key].hWnd = hW;
    list[key].date = dT;
    return true;
}
QString showHist(HWND hW)
{
   QString result;
    for (int i =0;i<sizeof(list.size()-1);i++) {
    if(list[i].hWnd == hW){
        result += list[i].date;
        //result = list[i].date;
    }
   }
    return result;

}

QString countTime(HWND hW)
{
    //while(hs);
}



#endif // HISTORY_H
