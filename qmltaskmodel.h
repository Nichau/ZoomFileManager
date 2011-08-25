#ifndef TASKTABLEMODEL_H
#define TASKTABLEMODEL_H
#include <QtSql/QSqlTableModel>

class QmlTaskModel : public QSqlTableModel
{
    Q_OBJECT
public:
    enum TaskRoles {
        ActiveRole = Qt::UserRole,
        DescriptionRole,
        CommandsRole
    };

    QmlTaskModel(QObject *parent = 0);

    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

private:
    QHash<int, QByteArray> _roles;

};

#endif // TASKTABLEMODEL_H
