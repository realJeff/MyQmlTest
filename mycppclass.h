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

    Q_INVOKABLE void remove(const int idx);
    Q_INVOKABLE QObject* updateModel();

private:
    MySqlModel *mySqlModel;
};

#endif // MYCPPCLASS_H
