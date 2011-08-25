#include <QtGui/QApplication>
#include <QtDeclarative>
#include <QtGui/QPushButton>
#include "qmlapplicationviewer.h"
#include "dbmanager.h"
#include "qmltaskmodel.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    DbManager *dbManager = new DbManager;
    dbManager->createConnection();
    dbManager->LoadData();

    QmlTaskModel model;

    QDeclarativeView view;
    QDeclarativeContext *ctxt = view.rootContext();
    ctxt->setContextProperty("sqlModel", &model);
    view.setSource(QUrl("../Resources/qml/ZoomFileManager/main.qml"));
    view.show();

    return app.exec();
}
