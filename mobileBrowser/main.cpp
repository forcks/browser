#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QtWebView>

#include <QQmlContext>

#include <QObject>

#include "searchengine.h"
#include "appengine.h"

#include "pagelist.h"
#include "pagemodel.h"

#include "historylist.h"
#include "historymodel.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QtWebView::initialize();

    QQmlApplicationEngine engine;

    qmlRegisterType<pageModel>("page",1,0,"Pagemodel");
    qmlRegisterUncreatableType<pageList>("page",1,0,"PageList",
                                            QStringLiteral("not"));


    pageList *pageList = &pageList::init();
    engine.rootContext()->setContextProperty(QStringLiteral("pagelist"),pageList);


    qmlRegisterType<historyModel>("history",1,0,"Historymodel");
    qmlRegisterUncreatableType<historyList>("history",1,0,"HistoryList",
                                            QStringLiteral("not"));


    historyList *historylist = &historyList::init();
    engine.rootContext()->setContextProperty(QStringLiteral("historylist"),historylist);


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    SearchEngine *searchEngine = &SearchEngine::init();
    engine.rootContext()->setContextProperty("searchEngine",searchEngine);
    //searchEngine->app = &app;

    AppEngine *appEngine = &AppEngine::init();
    engine.rootContext()->setContextProperty("appEngine",appEngine);

    //QObject::connect(&app, SIGNAL(onStop()), searchEngine, SLOT(savePageInFile()));

    engine.load(url);

    int ret = app.exec();
    qDebug() << "It works!";
    qDebug() << "It works!";
    qDebug() << "It works!";
    qDebug() << "It works!";
    qDebug() << "It works!";
    qDebug() << "It works!";
    qDebug() << "It works!";
    qDebug() << "It works!";
    return ret;
}
