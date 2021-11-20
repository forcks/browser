#include "searchengine.h"
#include "pagelist.h"
#include "appengine.h"
#include "historylist.h"

#include <QStandardPaths>
#include <QFile>


pageList *pageList = &pageList::init();
historyList *historyList = &historyList::init();

SearchEngine::SearchEngine(QObject *parent) : QObject(parent)
{
    pageList->loadPage(getStandartFileNameToSavePage());
    //QObject::connect(app, SIGNAL(aboutToQuit()), this, SLOT(savePage()));

    /*
    is temporary decision
    */

    QTimer *timerForSavePage = new QTimer(this);
    connect(timerForSavePage,&QTimer::timeout,this,&SearchEngine::savePageInFile);
    timerForSavePage->start(1000);

}
SearchEngine::~SearchEngine()
{
    //savePage();
}

/*
is search
*/
void SearchEngine::compliteAddress(QString addr)
{
    addr = correctAddress(addr);
    emit search(addr);
    emit getNumberPages(pageList->getNumberPages());
}

/*
is search when page is creating
*/
void SearchEngine::compliteAddress(QString addr,int activeId){
    addr = correctAddress(addr);
    emit changeActiveId(activeId);
    emit search(addr);
    AppEngine *appEngine = &AppEngine::init();
    appEngine->mainWindow();
}

void SearchEngine::compliteAddress()
{
    QVector<PageItem> item = pageList->getPages();
    QString addr = item[item.count() - 1].addr;
    int activeId = item[item.count() - 1].id;
    addr = correctAddress(addr);
    emit changeActiveId(activeId);
    emit search(addr);
    AppEngine *appEngine = &AppEngine::init();
    appEngine->mainWindow();
}


/*
create new page
*/
void SearchEngine::createPage(QString addr)
{
    pageList->addPage(addr);
    emit getNumberPages(pageList->getNumberPages());
}

/*
save page in temporary memory
*/

void SearchEngine::savePage(QString addr,int activeId,QString title)
{
    pageList->changeAddress(addr,activeId,title);
}

/*
save pages in permanently memory
*/

void SearchEngine::savePageInFile()
{
    qDebug()<<"save";
    emit pageList->savePage(getStandartFileNameToSavePage());
}


/*
delete page in temporary memory
*/
void SearchEngine::deletePage(int activeId)
{
    pageList->deletePage(activeId);
    emit getNumberPages(pageList->getNumberPages());
}

/*
save history to a file
*/
void SearchEngine::saveHistory(QString addr)
{
    historyList->saveHistory(addr);
}

/*
load history from the file
*/
void SearchEngine::loadHistory()
{
    historyList->loadHistory();
    emit getNumberPages(pageList->getNumberPages());
}

/*
delete one addresses from history
*/
void SearchEngine::deleteSelectedAddrHistory(int id)
{
    historyList->deleteSelectedAddrHistory(id);
}

/*
clear all history
*/
void SearchEngine::clearAllHistory()
{
    historyList->clearAllHistory();
}


bool SearchEngine::checkHttps(QString addr)
{
    return addr.contains("https://") || addr.contains("http://");
}

bool SearchEngine::checkSiteOrGlobalSearch(QString addr)
{
    return addr.contains(".");
}

QString SearchEngine::correctAddress(QString addr)
{
    if(checkSiteOrGlobalSearch(addr)){
        addr = checkHttps(addr) ? addr : "https://"+addr;
    }
    else{
        QStringList addrWords;
        addrWords = addr.split(" ");
        addr = "https://www.google.ru/search?q=";
        for(int i = 0;i<addrWords.count()-1;i++){
            addr+=addrWords[i]+"+";
        }
        addr+=addrWords[addrWords.count()-1];
    }
    return addr;
}

QString SearchEngine::getActiveSearcher()
{
    return "google.com";
}

void SearchEngine::startApp()
{
    emit getNumberPages(pageList->getNumberPages());
}

QString SearchEngine::getStandartFileNameToSavePage()
{
    return "pages.txt";
}





