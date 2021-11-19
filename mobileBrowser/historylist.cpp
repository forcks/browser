#include "historylist.h"
#include <QStandardPaths>
#include <QFile>
#include <QDebug>

bool historyList::setItemAt(int index, const HistoryItem &item)
{
    if (index < 0 || index >= mItems.size())
        return false;

    const HistoryItem &oldItem = mItems.at(index);
    if (item.id == oldItem.id
            && item.addr == oldItem.addr)
        return false;

    mItems[index] = item;
    return true;
}

/*
saving the history to a file after the user navigated to a new url
*/
void historyList::saveHistory(QString addr)
{
    QString fileName = getStandartFileNameToSaveHistory();
    auto pathToDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QFile fileSaveHistory(pathToDir+"/"+fileName);
    if(fileSaveHistory.open(QIODevice::Append)){
        QTextStream out(&fileSaveHistory);
        out<<addr<<";";
    }else{
        qDebug()<<"history dont work";
    }
    fileSaveHistory.close();
}

/*
reads mItems and saves its addresses to history
*/
void historyList::saveHistory()
{
    QString fileName = getStandartFileNameToSaveHistory();
    auto pathToDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QFile fileSaveHistory(pathToDir+"/"+fileName);
    if(fileSaveHistory.open(QIODevice::WriteOnly)){
        QTextStream out(&fileSaveHistory);
        if(!mItems.isEmpty()){
            for(int i = 0;i<mItems.count();i++){
                out<<mItems[i].addr<<";";
            }
        }else{
            out<<"";
        }
    }else{
        qDebug()<<"history dont work";
    }
    fileSaveHistory.close();
}

/*
read history from the file and load it
*/
void historyList::loadHistory()
{
    mItems.clear();
    QString fileName = getStandartFileNameToSaveHistory();
    auto pathToDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QFile fileSaveHistory(pathToDir+"/"+fileName);
    if(fileSaveHistory.open(QIODevice::ReadOnly)){
        QStringList historyAddr = QString::fromUtf8(fileSaveHistory.readAll()).split(";");
        for(int i = 0;i<historyAddr.count() - 1;i++){
            HistoryItem item;
            item.id = i;
            item.addr = historyAddr[i];
            mItems.append(item);
        }
    }
    changeValue();
}

/*
delete one addresses from the history
*/
void historyList::deleteSelectedAddrHistory(int id)
{
    for(int i = 0;i<mItems.count();i++){
        if(mItems[i].id == id){
            mItems.remove(i);
            saveHistory();
            loadHistory();
        }
    }
}

/*
clear all history
*/
void historyList::clearAllHistory()
{
    mItems.clear();
    saveHistory();
    loadHistory();
}

QVector<HistoryItem> historyList::items() const{
    return mItems;
}


historyList::historyList(QObject *parent) : QObject(parent)
{

}

QString historyList::getStandartFileNameToSaveHistory()
{
    return "history.txt";
}
