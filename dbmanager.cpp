#include "dbmanager.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtCore/QVariant>
#include <QtCore/QtDebug>

DbManager::DbManager(QObject *parent)
    : QObject(parent)
{
}

bool DbManager::createConnection()

{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/Users/draz63/Code/QtQuick/ZoomFileManager/ZoomFileManager/dbtasks.db");
    return db.open();
}

void DbManager::LoadData()
{
    QSqlQuery query1 ("select * from tblTask" );
    while (query1.next()) {
        QString task = query1.value(1).toString();
        qDebug() << task;
    }
}
