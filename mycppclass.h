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
    Q_INVOKABLE void remove(const int idx);

private:
    MySqlModel *mySqlModel;
};

#endif // MYCPPCLASS_H
