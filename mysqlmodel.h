#ifndef MYSQLMODEL_H
#define MYSQLMODEL_H

#include <QSqlQueryModel>
//#include <QSqlTableModel>

class MySqlModel : public QSqlQueryModel
{
public:
    MySqlModel(QObject *parent = 0);
    ~MySqlModel();

    bool initialize();

    enum Roles {
        Id = Qt::UserRole + 1,
        Name,
        Author,
        Year
    };

    QHash<int, QByteArray> roleNames() const;
    QVariant data(const QModelIndex &index, int role) const;

    MySqlModel* model();
    MySqlModel* updateModel();

protected:
    static void createConnection();
    static void closeConnection();

private:
    static QSqlDatabase m_db;
};

#endif // MYSQLMODEL_H
