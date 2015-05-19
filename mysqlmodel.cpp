#include "mysqlmodel.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlError>

QSqlDatabase MySqlModel::m_db;

MySqlModel::MySqlModel(QObject *parent) : QSqlTableModel(parent)
{
    createConnection();
}

MySqlModel::~MySqlModel()
{
    closeConnection();

}

QHash<int, QByteArray> MySqlModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Id] = "id";
    roles[Name] = "name";
    roles[Author] = "author";
    roles[Year] = "year";
    return roles;
}

//QVariant MySqlModel::data(const QModelIndex &index, int role) const
//{
//    if (!index.isValid())
//        return QVariant();

//    QString fieldName;
//    switch (role) {
//        case Id: fieldName = QStringLiteral("id"); break;
//        case Name: fieldName = QStringLiteral("name"); break;
//        case Author: fieldName = QStringLiteral("author"); break;
//        case Year: fieldName = QStringLiteral("year"); break;
//     }
//    if (!this->record().isGenerated(fieldName))
//        return QVariant();
//    else {
//        QModelIndex item = indexInQuery(index);
//        if ( !this->query().seek(item.row()) )
//            return QVariant();
//        return this->query().value(fieldName);
//    }
//    return QVariant();
//}

QVariant MySqlModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch(role) {
        case Id: {
            return record(index.row()).value(0).toString();
        }
        case Name : {
            return record(index.row()).value(1).toString();
        }
        case Author : {
            return record(index.row()).value(2).toString();
        }
        case Year : {
            return record(index.row()).value(3).toString();
        }
    }
    return QSqlQueryModel::data(index, role);
}

bool MySqlModel::initialize()
{
     QSqlQuery query;
     bool bExe = false;    

    //Judge whether the table exists.
    if(!m_db.tables().contains("Book"))
    {

        bExe = query.exec("create table Book (id INTEGER, "
                                "name TEXT, "
                                "author TEXT, "
                                "year TEXT)");

        if(!bExe)
        {
            QSqlError err(query.lastError());
            QString str(QString("SqLite error:%1").arg(err.text()));

            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText(str);
            msgBox.setWindowTitle("Error");
            msgBox.exec();
            return false;
        }
    }

    setTable("Book");

//    query.prepare("INSERT INTO Book (name,author,year) VALUES (?,?,?)");

//    query.addBindValue("BookName1");
//    query.addBindValue("Tom");
//    query.addBindValue("1998");
//    bExe = query.exec();

//    query.addBindValue("BookName2");
//    query.addBindValue("Peter");
//    query.addBindValue("2000");
//    bExe = query.exec() && bExe;

//    query.addBindValue("BookName3");
//    query.addBindValue("Jack");
//    query.addBindValue("2010");
//    bExe = query.exec()&& bExe;

//    if(!bExe)
//    {
//        QSqlError err(query.lastError());
//        QString str(QString("SqLite error:%1").arg(err.text()));

//        QMessageBox msgBox;
//        msgBox.setIcon(QMessageBox::Critical);
//        msgBox.setText(str);
//        msgBox.setWindowTitle("Error");
//        msgBox.exec();
//        return false;
//    }

    model();


    return true;
}

void MySqlModel::createConnection()
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    bool b = m_db.isValid();
    if(!b)
    {
        return;
    }

    m_db.setDatabaseName("sqlite");
    if (!m_db.open())
    {
        QSqlError err(m_db.lastError());
        QString str(QString("SqLite error:%1").arg(err.text()));

        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText(str);
        msgBox.setWindowTitle("Error");
        msgBox.exec();
        return;
    }

    return;

}

void MySqlModel::closeConnection()
{
    if (m_db.isOpen())
    {
        m_db.close();
    }
}

MySqlModel* MySqlModel::model()
{
    QVariant var0;
    QVariant var1;

    QString strQuery("SELECT * FROM Book");

    //method1
    setQuery(QSqlQuery(strQuery));
    var0 = record(0).value(0); //Invalid
    var1 = record(0).value(1); //Invalid

    //method2
    QSqlQueryModel model;
    model.setQuery("SELECT * FROM Book");
    var0 = model.record(0).value(0);  //1
    var1 = model.record(0).value(1);  //BookName1

    //method3
    QSqlQuery sq;
    sq.prepare(strQuery);
    sq.exec();
    bool b = sq.isActive();
    setQuery(sq);
    var0 = record(0).value(0); //Invalid
    var1 = record(0).value(1); //Invalid

    return this;
}

MySqlModel* MySqlModel::updateModel()
{
    return this;
}


