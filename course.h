#ifndef COURSE_H
#define COURSE_H
#include <QString>

struct course {

    QString Name;
    QString Code;
    QString Lecture_Hall;
    QString Time;
    int Size;
    QString pro [100];
    QString student[100];

};
int counter = 0;
course c [100];
#endif // COURSE_H
