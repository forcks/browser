#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QtWebView>

#include <QQmlContext>

#include "searchengine.h"
#include "appengine.h"

#include "pagelist.h"
#include "pagemodel.h"

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


    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    SearchEngine *searchEngine = &SearchEngine::init();
    engine.rootContext()->setContextProperty("searchEngine",searchEngine);

    AppEngine *appEngine = &AppEngine::init();
    engine.rootContext()->setContextProperty("appEngine",appEngine);



    engine.load(url);

    return app.exec();
}
