#ifndef QLOGVIRTUALTABLE_H
#define QLOGVIRTUALTABLE_H

#include <QObject>
#include <QMap>
#include <QVector>

enum enumFieldDefs {ftInt,ftUInt,ftBool,ftString};

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
    bool insert();


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
