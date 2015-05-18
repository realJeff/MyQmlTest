#include "mycppclass.h"

MyCppClass::MyCppClass()
{
    mySqlModel = new MySqlModel;
    mySqlModel->initialize();
}

MyCppClass::~MyCppClass()
{

}

QObject* MyCppClass::model()
{
    return mySqlModel->model();
}

void MyCppClass::remove(const int idx)
{
    mySqlModel->removeRow(idx);
}
