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
    mySqlModel->removeRow(idx);
}

QObject* MyCppClass::updateModel()
{
    return mySqlModel->updateModel();
}
