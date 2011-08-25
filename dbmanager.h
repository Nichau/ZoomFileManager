#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QtSql/QSqlDatabase>
#include <QObject>
#include <QtCore/QString>

class DbManager : public QObject
{
public:
    DbManager(QObject *parent = 0);
    bool createConnection();
    void LoadData();
    QSqlDatabase db;

private:

        QString task;

};

#endif // DBMANAGER_H
