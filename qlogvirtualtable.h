#ifndef QLOGVIRTUALTABLE_H
#define QLOGVIRTUALTABLE_H

#include <QObject>
#include <QMap>
#include <QVector>

enum enumFieldDefs {ftInt,ftUInt,ftDouble,ftBool,ftString};

struct FieldDefs
{
    bool bKey;
    QString m_sFieldName;
    enumFieldDefs m_ftFieldType;
    int m_iSize;
    bool m_bRequired;
};

class QLogVirtualTable : public QObject
{
    Q_OBJECT
public:
    explicit QLogVirtualTable(QObject *parent = nullptr);

    bool addFieldDefs(const bool &bKey, const QString &sFieldName, enumFieldDefs ftFieldType, const int &iSize, const bool &bRequired);
    bool insertEditPost(int iAction,int iParamNum, ...);// iAction == 0 то добавить запись если её нет и редактировать если запись с таким ключом есть
                                                    // iAction == 1 только добавлять запись с таким ключом, если есть запись с таким ключом то ничего не делать
                                                    // iAction == 2 только редактировать

    bool insert();
    bool edit();
    bool post();
    bool deleteRecord(int iParamNum,...); //Удаление записи по ключу
    bool deleteRecord(int iRecordNum);    // Удаление записи по номеру
    bool deleteRecord(); // Удалить текущую запись
    void clear();        // Удалитьвсе записи

    QString getFieldByName(QString sFiledName, bool *bOk = nullptr);
    bool setFieldByName(QString sFiledName,QString sValue);

    bool FieldByName(QString sFiledName,quint8 quint8Data);
    bool FieldByName(QString sFiledName,quint16 quint16Data);

    QString getField(int iFieldNum);
    bool setField(int iFieldNum,QString sValue);

    bool FindKey(int iKey,...);
    bool Locate(QString sLocate);  // Строка по правилам упрощенного SQL
    bool LocateF(QString sLocate);  // Строка по правилам упрощенного SQL где вместо имен полей номер поля в фигурных скобках

    bool setFilter(QString sLocate); // Строка по правилам упрощенного SQL
    bool filterActivate(bool bActive);
    bool isFilterActive();

    int getFieldCount();
    int getKeyCount();

    int getRecCount();
    int getRecNo();
    bool gotoRecord(int iRecNo);

    bool next();
    bool previous();
    bool last();
    bool first();
    bool bof();
    bool eof();

signals:

public slots:

private:
    QMap <QByteArray,QByteArray> m_Map;
    QByteArray m_baKey;
    QByteArray m_baValue;
    QVector <FieldDefs> m_vFieldDefs;
    int m_iKeyCount;
    int m_iFieldCount;
};

#endif // QLOGVIRTUALTABLE_H
