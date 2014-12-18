#ifndef HELPER_H
#define HELPER_H

#include <QtCore/qstring.h>
#include <QtCore/qobject.h>

class Helper : public QObject
{
    Q_OBJECT

public:

    Q_INVOKABLE bool reset(const QString &sRepo, const QString &qKey) const noexcept;

    Q_INVOKABLE void success() const noexcept;

    Q_INVOKABLE QString getiso() const noexcept;

    Q_INVOKABLE bool setiso() const noexcept;

    Q_INVOKABLE void loadPage(const QString &url) const noexcept;

private:

    void showError(const QString &value) const noexcept;

    TBool del() const noexcept;

    void CRep4All() const noexcept;

    void error() const noexcept;

};

#endif // HELPER_H
