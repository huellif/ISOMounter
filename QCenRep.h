#ifndef QCenRep_H
#define QCenRep_H

#include <QtCore/qstring.h>

class QCenRep
{

public:

    static TInt reset(const QString &repo, const QString &key) noexcept;
    static TInt ChangeValStr(const TUid &KUidRepository, const TUint32 &key, const QString &newkeyvalue) noexcept;
    static TInt ReadValStr(const TUid &KUidRepository, const TUint32 &key, QString* retval) noexcept;
};

#endif // QCenRep_H
