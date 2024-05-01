#include<iostream>
#include<QString>
#include<QVector>
#include"UIDgenerator.h"

using namespace std;

QString generateUID(QVector<QString> uids){
    QString uid;
    for (int i = 0; i < 6; i++){
        uid += QString::fromStdString(to_string(rand()%10));
    }
    for (QString currentUID : uids){
        if (uid == currentUID){
            return generateUID(uids);
        }
    }
    return uid;
}
