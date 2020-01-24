#include "qlogvirtualtable.h"

QLogVirtualTable::QLogVirtualTable(QObject *parent) :
    QObject(parent),
    m_iKeyCount(0),
    m_iFieldCount(0)
{

}


bool QLogVirtualTable::addFieldDefs(const bool &bKey, const QString &sFieldName, enumFieldDefs ftFieldType, const int &iSize, const bool &bRequired)
{
    if ((ftFieldType == ftInt) || (ftFieldType == ftUInt)) {
        if ((iSize != 1) && (iSize != 2) && (iSize != 4) && (iSize != 8)) {
            return false;
        }
    }
    if (ftFieldType == ftBool) {
        if (iSize !=0 )
            return false;
    }
    m_iFieldCount++;
    m_vFieldDefs.resize(m_iFieldCount);
    if (bKey) {
        m_iKeyCount++;
    }
    m_vFieldDefs[m_iFieldCount].m_sFieldName = sFieldName;
    m_vFieldDefs[m_iFieldCount].m_ftFieldType = ftFieldType;
    m_vFieldDefs[m_iFieldCount].m_iSize = iSize;
    m_vFieldDefs[m_iFieldCount].m_bRequired = bRequired;
    return true;
}

bool QLogVirtualTable::insertEditPost(int iAction, int iParamNum, ...)
{
//#include <stdio.h>
//#include <stdarg.h>

    int result = 0;
    va_list factor;         //указатель va_list
    va_start(factor, iParamNum);    // устанавливаем указатель
    for(int i=0; i<iParamNum; i++)
    {
        if (m_vFieldDefs[i].m_ftFieldType == ftInt)
            result += va_arg(factor, int);  // получаем значение текущего параметра типа int
        else if (m_vFieldDefs[i].m_ftFieldType == ftUInt)
            result += va_arg(factor, unsigned int);  // получаем значение текущего параметра типа int
        else if (m_vFieldDefs[i].m_ftFieldType == ftDouble)
            result += va_arg(factor, double);  // получаем значение текущего параметра типа int
    }
    va_end(factor); // завершаем обработку параметров
//    return result;




    return true;
}
