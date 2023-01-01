#ifndef STUDENT_H
#define STUDENT_H
#include <QString>

struct student {
    QString sID;
    QString sFirst_Name;
    QString sLast_Name;
    QString sAge;
    QString sMobile;
    QString sEmail;
    QString sGrade;
    QString scourses  [100];

};
int scounter=0;
student s [100];
#endif // STUDENT_H
