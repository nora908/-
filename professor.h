#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <QString>
struct professor {
    QString ID;
    QString First_Name;
    QString Last_Name;
    QString Age;
    QString Mobile;
    QString Email;
    QString Title;
    QString procourses  [100];

};



int pcounter = 0;
professor p[100];
#endif // PROFESSOR_H
