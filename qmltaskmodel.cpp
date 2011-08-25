#include "qmltaskmodel.h"
#include <QtSql/QSqlTableModel>
#include <QtDebug>
#include <QtSql/QSqlRecord>

QmlTaskModel::QmlTaskModel(QObject *parent)
    : QSqlTableModel(parent)
{
    _roles[ActiveRole] = "active";
    _roles[DescriptionRole] = "description";
    _roles[CommandsRole] = "commands";
    setRoleNames(_roles);
    setTable("tblTask");
    select();
}

QVariant QmlTaskModel::data(const QModelIndex & index, int role) const {
    if (!index.isValid())
           return QVariant();

    if (role >= ActiveRole) {
        QSqlRecord r = record(index.row());
        return r.value(QString(_roles.value(role)));
    }
    return QSqlTableModel::data(index, role);
}
