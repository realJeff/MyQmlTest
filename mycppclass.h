#ifndef MYCPPCLASS_H
#define MYCPPCLASS_H

#include <QObject>
#include "mysqlmodel.h"

class MyCppClass : public QObject
{
    Q_OBJECT

public:
    MyCppClass();
    ~MyCppClass();

    Q_INVOKABLE QObject* model();

private:
    MySqlModel *mySqlModel;
};

#endif // MYCPPCLASS_H
