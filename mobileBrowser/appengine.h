#ifndef APPENGINE_H
#define APPENGINE_H

#include <QObject>

class AppEngine : public QObject
{
    Q_OBJECT
public:
    static AppEngine &init(){
            static AppEngine initialization;
            return initialization;
        }


public slots:
    void pages();
    void mainWindow();

signals:
    void goToPages();
    void goToMainWindow();

private:
    explicit AppEngine(QObject *parent = nullptr);
    AppEngine(AppEngine const&);


};

#endif // APPENGINE_H
