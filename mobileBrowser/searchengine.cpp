#include "searchengine.h"
#include "pagelist.h"
#include "appengine.h"



pageList *pageList = &pageList::init();

SearchEngine::SearchEngine(QObject *parent) : QObject(parent)
{
    pageList->loadPage(getStandartFileNameToSavePage());
    //QObject::connect(app, SIGNAL(aboutToQuit()), this, SLOT(savePage()));
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


/*
create new page
*/
void SearchEngine::createPage()
{
    QString addr = correctAddress(getActiveSearcher());
    //compliteAddress(addr);

    pageList->addPage(addr);
}

/*
save page in temporary memory
*/

void SearchEngine::savePage(QString addr,int activeId)
{
    pageList->changeAddress(addr,activeId);
}

/*
save pages in permanently memory
*/

void SearchEngine::savePageInFile()
{
    qDebug()<<"save";
    pageList->savePage(getStandartFileNameToSavePage());
}


/*
delete page in temporary memory
*/
void SearchEngine::deletePage(int activeId)
{
    pageList->deletePage(activeId);

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

QString SearchEngine::getStandartFileNameToSavePage()
{
    return "pages.txt";
}



