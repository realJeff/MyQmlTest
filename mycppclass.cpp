#include "mycppclass.h"

MyCppClass::MyCppClass()
{
    mySqlModel = new MySqlModel;
    mySqlModel->initialize();
}

MyCppClass::~MyCppClass()
{

}

void MyCppClass::remove(const int idx)
{
//    int c = mySqlModel->rowCount();
    bool b = mySqlModel->removeRow(idx);
    mySqlModel->select();
//    c = mySqlModel->rowCount();
}

QObject* MyCppClass::updateModel()
{
    return mySqlModel->updateModel();
}
