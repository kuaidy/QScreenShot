#ifndef USERTOKENINFO_H
#define USERTOKENINFO_H
#include <QString>
#include <QList>

class UserTokenInfo
{
public:
    UserTokenInfo();
    QString token;
    QString user_email;
    QString user_nicename;
    QString user_display_name;
    int user_id;
    QString user_roles;
    QList<QString> user_meta_name;
};

#endif // USERTOKENINFO_H
