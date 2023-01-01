#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "student.h"
#include "course.h"
#include "professor.h"
#include <QPixmap>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//pic log in
    QPixmap login("C:/Users/Sara/Desktop/porject/copy/sign-in.png");
    ui->label_pic->setPixmap(login.scaled(300,300,Qt::KeepAspectRatio));
//pic background
    QPixmap back("C:/Users/Sara/Desktop/porject/copy/back.png");
    ui->background->setPixmap(back.scaled(1531,800,Qt::KeepAspectRatio));

    QPixmap search("C:/Users/Sara/Desktop/porject/copy/search.png");
    ui->search->setPixmap(search.scaled(300,300,Qt::KeepAspectRatio));

    QPixmap addst("C:/Users/Sara/Desktop/porject/copy/add.png");
    ui->addst->setPixmap(addst.scaled(350,350,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//--------------------------------------------------------------------------------------------------------
void MainWindow::on_pushButton_clicked()
{
    ui->stackedwidget->setCurrentWidget(ui->list);

}


void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedwidget->setCurrentWidget(ui->studenticon);

}


void MainWindow::on_pushButton_login_clicked()                       //for login screen
{
    QString username= ui->lineEdit_username->text();
    QString pass= ui->lineEdit_pass->text();
    if(username=="test"&& pass=="test"){

        QMessageBox::information(this,"login","usernameand pass is correct");
        ui->stackedwidget->setCurrentWidget(ui->list);

    }
    else{
        QMessageBox::warning(this,"login","usernameand pass is not correct");
    }

}


void MainWindow::on_pushButton_stu_clicked()
{
    ui->stackedwidget->setCurrentWidget(ui->studenticon);

}


void MainWindow::on_pushButton_ser_clicked()
{
    ui->stackedwidget->setCurrentWidget(ui->searchstudent);

}


void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedwidget->setCurrentWidget(ui->studenticon);

}


void MainWindow::on_pushButton_add_clicked()
{
    ui->stackedwidget->setCurrentWidget(ui->addstudent);

}

//-------------------------------------------------------------------------------------------------------------
void MainWindow::on_pushButton_addstu_clicked()         //add student

{




    s[scounter].sFirst_Name=ui->stackedwidget->findChild<QLineEdit*>("lineEdit_stufirstname")->text();
    s[scounter].sLast_Name=ui->stackedwidget->findChild<QLineEdit*>("stulastname")->text();
    s[scounter].sID=ui->stackedwidget->findChild<QLineEdit*>("lineEdit_stuid")->text();
    s[scounter].sAge=ui->stackedwidget->findChild<QLineEdit*>("lineEdit_stuage")->text();
    s[scounter].sMobile=ui->stackedwidget->findChild<QLineEdit*>("lineEdit_stumobile")->text();
    s[scounter].sEmail=ui->stackedwidget->findChild<QLineEdit*>("lineEdit_stuemail")->text();
    s[scounter].sGrade=ui->stackedwidget->findChild<QLineEdit*>("lineEdit_stugrade")->text();
    scounter++;
    QMessageBox::information(this,"","Student Added");

    ui->stackedwidget->findChild<QLineEdit*>("lineEdit_stufirstname")->clear(); // to clear the input
    ui->stackedwidget->findChild<QLineEdit*>("stulastname")->clear();
    ui->stackedwidget->findChild<QLineEdit*>("lineEdit_stuid")->clear();
    ui->stackedwidget->findChild<QLineEdit*>("lineEdit_stuage")->clear();
    ui->stackedwidget->findChild<QLineEdit*>("lineEdit_stumobile")->clear();
    ui->stackedwidget->findChild<QLineEdit*>("lineEdit_stugrade")->clear();
    ui->stackedwidget->findChild<QLineEdit*>("lineEdit_stuemail")->clear();

}


void MainWindow::on_pushButton_2_clicked()        //for searching a student
{



    //------------------------------------------
    // removing the previous table

for(int i=0; i<ui->tableWidget_stu_info->rowCount(); i++)
{
    ui->tableWidget_stu_info->removeRow(i);

}

for(int i=0; i<ui->tableWidget_stu_info->columnCount(); i++)
{
    ui->tableWidget_stu_info->removeColumn(i);

}
ui->tableWidget_stu_info->removeRow(0);
ui->tableWidget_stu_info->removeRow(0);
ui->tableWidget_stu_info->removeRow(0);

ui->tableWidget_stu_info->removeColumn(0);

    //---------------------------------------




    int flag=0;
    for (int j = 0; j < scounter ; j++) {

        if (ui->stackedwidget->findChild<QLineEdit*>("lineEdit_searchstuID")->text() == s[j].sID) {
            flag=1;
            ui->tableWidget_stu_info->insertColumn(0);
            ui->tableWidget_stu_info->insertColumn(1);

             ui->tableWidget_stu_info->insertRow(0);
             ui->tableWidget_stu_info->insertRow(1);
             ui->tableWidget_stu_info->insertRow(2);
             ui->tableWidget_stu_info->insertRow(3);
             ui->tableWidget_stu_info->insertRow(4);
             ui->tableWidget_stu_info->insertRow(5);
             ui->tableWidget_stu_info->insertRow(6);

            //set horizontal labels

             QTableWidgetItem * hlabel;

             hlabel = new QTableWidgetItem("Name");
             ui->tableWidget_stu_info->setVerticalHeaderItem(0,hlabel);

             hlabel = new QTableWidgetItem("ID");
             ui->tableWidget_stu_info->setVerticalHeaderItem(1,hlabel);


             hlabel = new QTableWidgetItem("Age");
             ui->tableWidget_stu_info->setVerticalHeaderItem(2,hlabel);


             hlabel = new QTableWidgetItem("Mobile");
             ui->tableWidget_stu_info->setVerticalHeaderItem(3,hlabel);


             hlabel = new QTableWidgetItem("E-mail");
             ui->tableWidget_stu_info->setVerticalHeaderItem(4,hlabel);


             hlabel = new QTableWidgetItem("Grade");
             ui->tableWidget_stu_info->setVerticalHeaderItem(5,hlabel);


             QTableWidgetItem * vlabel;             //to set vertical label

             vlabel = new QTableWidgetItem("data");
             ui->tableWidget_stu_info->setHorizontalHeaderItem(0,vlabel);

//-------------------------------------------------
             QTableWidgetItem * item;
             QString namee = s[j].sFirst_Name +"  "+ s[j].sLast_Name;
             item = new QTableWidgetItem(namee);
             ui->tableWidget_stu_info->setItem(0,0,item);

             item = new QTableWidgetItem(s[j].sID);
             ui->tableWidget_stu_info->setItem(1,0,item);

             item = new QTableWidgetItem(s[j].sAge);
             ui->tableWidget_stu_info->setItem(2,0,item);

             item = new QTableWidgetItem(s[j].sMobile);
             ui->tableWidget_stu_info->setItem(3,0,item);

             item = new QTableWidgetItem(s[j].sEmail);
             ui->tableWidget_stu_info->setItem(4,0,item);

             item = new QTableWidgetItem(s[j].sGrade);
             ui->tableWidget_stu_info->setItem(5,0,item);

             QString s_id =s[j].sID;
             for (int i = 0; i < scounter; i++) {
                 if (s_id == s[i].sID) {
                     for (int k = 0; k <= scounter; k++) {
                         if(c[k].Code==s[i].scourses[k]){
                            item = new QTableWidgetItem(s[i].scourses[k]);
                            ui->tableWidget_stu_info->setItem(k,1,item);

                     }
                 }

             }
        }
        }

}
    if(flag==0){
        QMessageBox::information(this," ","Student doesn't exist");

    }
}
//----------------------------------------------------------------------------------------------------------------

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedwidget->setCurrentWidget(ui->list);

}



void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedwidget->setCurrentWidget(ui->professoricon);

}


void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedwidget->setCurrentWidget(ui->professoricon);

}



void MainWindow::on_pushButton_SER_clicked()
{
    ui->stackedwidget->setCurrentWidget(ui->searchprofessor);

}


void MainWindow::on_pushButton_ADD_clicked()
{
    ui->stackedwidget->setCurrentWidget(ui->addprofessor);

}


void MainWindow::on_pushButton_9_clicked()            //add prof
{



    p[pcounter].First_Name=ui->stackedwidget->findChild<QLineEdit*>("lineEdit_profirstname")->text();
    p[pcounter].Last_Name=ui->stackedwidget->findChild<QLineEdit*>("lineEdit_prolastname")->text();
    p[pcounter].ID=ui->stackedwidget->findChild<QLineEdit*>("lineEdit_proid")->text();
    p[pcounter].Age=ui->stackedwidget->findChild<QLineEdit*>("lineEdit_proage")->text();
    p[pcounter].Email=ui->stackedwidget->findChild<QLineEdit*>("lineEdit_proemail")->text();
    p[pcounter].Mobile=ui->stackedwidget->findChild<QLineEdit*>("lineEdit_promobile")->text();
    p[pcounter].Title=ui->stackedwidget->findChild<QLineEdit*>("lineEdit_protitle")->text();
    pcounter++;

    QMessageBox::information(this," ","Professor added");

    ui->stackedwidget->findChild<QLineEdit*>("lineEdit_profirstname")->clear(); // to clear the input
    ui->stackedwidget->findChild<QLineEdit*>("lineEdit_prolastname")->clear();
    ui->stackedwidget->findChild<QLineEdit*>("lineEdit_proid")->clear();
    ui->stackedwidget->findChild<QLineEdit*>("lineEdit_proage")->clear();
    ui->stackedwidget->findChild<QLineEdit*>("lineEdit_proemail")->clear();
    ui->stackedwidget->findChild<QLineEdit*>("lineEdit_promobile")->clear();
    ui->stackedwidget->findChild<QLineEdit*>("lineEdit_protitle")->clear();

}



void MainWindow::on_pushButton_7_clicked()       //for prof search
{
    for(int i=0; i<ui->tableWidget_profinfo->rowCount(); i++)
    {
        ui->tableWidget_profinfo->removeRow(i);

    }
    for(int i=0; i<ui->tableWidget_profinfo->columnCount(); i++)
    {
        ui->tableWidget_profinfo->removeColumn(i);

    }
    ui->tableWidget_profinfo->removeRow(0);
    ui->tableWidget_profinfo->removeRow(0);
    ui->tableWidget_profinfo->removeRow(0);

    ui->tableWidget_profinfo->removeColumn(0);


    int flag=0;
    for (int j = 0; j < pcounter ; j++) {

        if (ui->stackedwidget->findChild<QLineEdit*>("lineEdit_searchprofessor")->text() == p[j].ID) {
            flag=1;


            ui->tableWidget_profinfo->insertColumn(0);
            ui->tableWidget_profinfo->insertColumn(1);
             ui->tableWidget_profinfo->insertRow(0);
             ui->tableWidget_profinfo->insertRow(1);
             ui->tableWidget_profinfo->insertRow(2);
             ui->tableWidget_profinfo->insertRow(3);
             ui->tableWidget_profinfo->insertRow(4);
             ui->tableWidget_profinfo->insertRow(5);
             ui->tableWidget_profinfo->insertRow(6);

             QTableWidgetItem * item;
             QString namee = p[j].First_Name +"  "+ p[j].Last_Name;
             item = new QTableWidgetItem(namee);
             ui->tableWidget_profinfo->setItem(0,0,item);

             item = new QTableWidgetItem(p[j].ID);
             ui->tableWidget_profinfo->setItem(1,0,item);

             item = new QTableWidgetItem(p[j].Age);
             ui->tableWidget_profinfo->setItem(2,0,item);

             item = new QTableWidgetItem(p[j].Mobile);
             ui->tableWidget_profinfo->setItem(3,0,item);

             item = new QTableWidgetItem(p[j].Email);
             ui->tableWidget_profinfo->setItem(4,0,item);

             item = new QTableWidgetItem(p[j].Title);
             ui->tableWidget_profinfo->setItem(5,0,item);


             QTableWidgetItem * hlabel;          //to set horizontal labels

             hlabel = new QTableWidgetItem("Name");
             ui->tableWidget_profinfo->setVerticalHeaderItem(0,hlabel);

             hlabel = new QTableWidgetItem("ID");
             ui->tableWidget_profinfo->setVerticalHeaderItem(1,hlabel);

             hlabel = new QTableWidgetItem("Age");
             ui->tableWidget_profinfo->setVerticalHeaderItem(2,hlabel);

             hlabel = new QTableWidgetItem("Mobile");
             ui->tableWidget_profinfo->setVerticalHeaderItem(3,hlabel);

             hlabel = new QTableWidgetItem("E-mail");
             ui->tableWidget_profinfo->setVerticalHeaderItem(4,hlabel);

             hlabel = new QTableWidgetItem("title");
             ui->tableWidget_profinfo->setVerticalHeaderItem(5,hlabel);



             QString p_id =p[j].ID;
             for (int i = 0; i <= pcounter; i++) {
                 if (p_id == p[i].ID) {
                     for (int k = 0; k <= pcounter; k++) {
                         if(c[k].Code==p[i].procourses[k]){
                            item = new QTableWidgetItem(p[i].procourses[k]);
                            ui->tableWidget_profinfo->setItem(k,1,item);

                     }
                 }

             }
        }
        }

}
    if(flag==0){
        QMessageBox::information(this," ","Professor doesn't exist");

    }
}

//--------------------------------------------------------------------------------------
void MainWindow::on_pushButton_pro_clicked()
{
    ui->stackedwidget->setCurrentWidget(ui->professoricon);

}


void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedwidget->setCurrentWidget(ui->list);

}


void MainWindow::on_pushButton_course_clicked()
{
    ui->stackedwidget->setCurrentWidget(ui->courseicon);

}


void MainWindow::on_pushButton_14_clicked()
{
    ui->stackedwidget->setCurrentWidget(ui->courseicon);

}

//-----------------------------------------------------------------------------------------------
void MainWindow::on_pushButton_12_clicked()                        //add course
{




    c[counter].Name=ui->stackedwidget->findChild<QLineEdit*>("lineEdit_coursename")->text();
    c[counter].Code=ui->stackedwidget->findChild<QLineEdit*>("lineEdit_coursecose")->text();
    c[counter].Lecture_Hall=ui->stackedwidget->findChild<QLineEdit*>("lineEdit_lechall")->text();
    c[counter].Time=ui->stackedwidget->findChild<QLineEdit*>("lineEdit_coursetime")->text();
    counter++;
    QMessageBox::information(this," ","Course Added");


    ui->stackedwidget->findChild<QLineEdit*>("lineEdit_coursename")->clear(); // to clear the input
    ui->stackedwidget->findChild<QLineEdit*>("lineEdit_coursecose")->clear();
    ui->stackedwidget->findChild<QLineEdit*>("lineEdit_lechall")->clear();
    ui->stackedwidget->findChild<QLineEdit*>("lineEdit_coursetime")->clear();
}


void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedwidget->setCurrentWidget(ui->courseicon);

}



    void MainWindow::on_pushButton_15_clicked()                      //search course
    {


        ui->tableWidget_courseinfo->clear();
        ui->tableWidget_profofcourse->clear();
        ui->tableWidget_stuofcourse->clear();


        bool flag = 0;
           for (int i = 0; i < counter; i++) {
               if (ui->stackedwidget->findChild<QLineEdit*>("lineEdit_searchcourse")->text() == c[i].Code) {
                    flag=1;

                    ui->tableWidget_courseinfo->insertColumn(0);
                    ui->tableWidget_courseinfo->insertColumn(1);
                    ui->tableWidget_courseinfo->insertColumn(2);
                    for(int j =0 ; j<100 ; j++){
                        ui->tableWidget_courseinfo->insertRow(j);
                     }

                    QTableWidgetItem * item;                //to desplay the course data

                      item = new QTableWidgetItem(c[i].Name);
                      ui->tableWidget_courseinfo->setItem(0,0,item);

                       item = new QTableWidgetItem(c[i].Code);
                       ui->tableWidget_courseinfo->setItem(1,0,item);

                       item = new QTableWidgetItem(c[i].Lecture_Hall);
                       ui->tableWidget_courseinfo->setItem(2,0,item);

                      item = new QTableWidgetItem(c[i].Time);
                      ui->tableWidget_courseinfo->setItem(3,0,item);









                       //------------------------------------------
                      ui->tableWidget_profofcourse->insertColumn(0);
                      ui->tableWidget_profofcourse->insertColumn(1);
                      ui->tableWidget_profofcourse->insertColumn(2);

                      for (int j = 0; j <pcounter; j++)  {       //to display the data of the prof.s regertered in that course
                          if(p[j].ID == c[i].pro[j]){
                              int row =ui->tableWidget_profofcourse->rowCount();
                              ui->tableWidget_profofcourse->insertRow(row);
                            QTableWidgetItem * name = new QTableWidgetItem(p[j].First_Name);
                              ui->tableWidget_profofcourse->setItem(row,0,name);
                             QTableWidgetItem * lname = new QTableWidgetItem(p[j].Last_Name);
                              ui->tableWidget_profofcourse->setItem(row,1,lname);
                             QTableWidgetItem * id = new QTableWidgetItem(p[j].ID);
                              ui->tableWidget_profofcourse->setItem(row,2,id);

                          }
                      }
                      ui->tableWidget_stuofcourse->insertColumn(0);
                      ui->tableWidget_stuofcourse->insertColumn(1);
                      ui->tableWidget_stuofcourse->insertColumn(2);
                      ui->tableWidget_stuofcourse->insertColumn(3);



                      for (int j = 0; j <scounter; j++)  {       //to display the data of the students regertered in that course
                          if(s[j].sID == c[i].student[j]){
                              int row =ui->tableWidget_stuofcourse->rowCount();
                              ui->tableWidget_stuofcourse->insertRow(row);

                            QTableWidgetItem * fname= new QTableWidgetItem(s[j].sFirst_Name);
                              ui->tableWidget_stuofcourse->setItem(row,0,fname);
                            QTableWidgetItem * lname= new QTableWidgetItem(s[j].sLast_Name);
                              ui->tableWidget_stuofcourse->setItem(row,1,lname);
                            QTableWidgetItem * id= new QTableWidgetItem(s[j].sID);
                              ui->tableWidget_stuofcourse->setItem(row,2,id);
                            QTableWidgetItem * grade= new QTableWidgetItem(s[j].sGrade);
                              ui->tableWidget_stuofcourse->setItem(row,3,grade);

                          }
                      }


                         }


     }


            if(flag==0)
                QMessageBox::information(this," ","Course not found");
     }

//--------------------------------------------------------------------------------------
void MainWindow::on_pushButton_creat_clicked()
{
    ui->stackedwidget->setCurrentWidget(ui->addcourse);

}


void MainWindow::on_pushButton_search3_clicked()
{
    ui->stackedwidget->setCurrentWidget(ui->serchcourse);

}


void MainWindow::on_pushButton_17_clicked()
{
    ui->stackedwidget->setCurrentWidget(ui->courseicon);

}


void MainWindow::on_pushButton_18_clicked()            //add student to course
{





    int flag = 0;
    int flag1 = 0;
        for (int i = 0; i < counter; i++) {
            if (ui->stackedwidget->findChild<QLineEdit*>("lineEdit_coursecodeforstu")->text() == c[i].Code) {
                for (int j = 0; j < scounter; j++) {
                    if (ui->stackedwidget->findChild<QLineEdit*>("lineEdit_addstudenttocourse")->text() == s[j].sID) {
                        s[j].scourses[i] = ui->stackedwidget->findChild<QLineEdit*>("lineEdit_coursecodeforstu")->text();
                        c[i].student[j] = ui->stackedwidget->findChild<QLineEdit*>("lineEdit_addstudenttocourse")->text();
                        QMessageBox::information(this," ","Student has been registerd");



                    }
                }
            }
        }
        for (int i = 0; i < counter; i++) {
            if (ui->stackedwidget->findChild<QLineEdit*>("lineEdit_coursecodeforstu")->text() == c[i].Code) {
                flag = 1;
            }
        }
            for (int j = 0; j < scounter; j++) {
                if (ui->stackedwidget->findChild<QLineEdit*>("lineEdit_addstudenttocourse")->text() == s[j].sID) {
                    flag1 = 1;
                }
            }
                if (flag == 0)
                    QMessageBox::information(this," ","This course doesn't exxist");


                if (flag1==0)
                    QMessageBox::information(this," ","This student doesn't exist");

    ui->stackedwidget->findChild<QLineEdit*>("lineEdit_coursecodeforstu")->clear(); // to clear the input
    ui->stackedwidget->findChild<QLineEdit*>("lineEdit_addstudenttocourse")->clear();
}


void MainWindow::on_pushButton_addstu_2_clicked()
{
    ui->stackedwidget->setCurrentWidget(ui->addstudenttocourse);

}


void MainWindow::on_pushButton_20_clicked()
{
    ui->stackedwidget->setCurrentWidget(ui->courseicon);

}


void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedwidget->setCurrentWidget(ui->addprofessortocourse);
}


void MainWindow::on_pushButton_19_clicked()      //add prof to course
{
    int flag1 = 0;
    int flag = 0;
        for (int i = 0; i < counter; i++) {
            if (ui->stackedwidget->findChild<QLineEdit*>("lineEdit_courseIDforprof")->text() == c[i].Code) {
                for (int j = 0; j < pcounter; j++) {
                    if (ui->stackedwidget->findChild<QLineEdit*>("lineEdit_profIDtocourse")->text() == p[j].ID) {
                        p[j].procourses[i] = ui->stackedwidget->findChild<QLineEdit*>("lineEdit_courseIDforprof")->text();
                        c[i].pro[j] = ui->stackedwidget->findChild<QLineEdit*>("lineEdit_profIDtocourse")->text();
                        QMessageBox::information(this," ","Professor has been registered");

                    }
                }
            }
        }
        for (int i = 0; i < counter; i++) {
            if (ui->stackedwidget->findChild<QLineEdit*>("lineEdit_courseIDforprof")->text() == c[i].Code) {
                flag = 1;
            }
        }
        for (int j = 0; j < pcounter; j++) {
            if (ui->stackedwidget->findChild<QLineEdit*>("lineEdit_profIDtocourse")->text() == p[j].ID) {
                flag1 = 1;
            }
        }
        if (flag == 0)
            QMessageBox::information(this," ","This course doesn't exist");
        if (flag1==0)
            QMessageBox::information(this," ","This professor doesn't exist");


}

int saggan_test=0;

void MainWindow::on_pushButton_22_clicked()
{

    fstream student_file;
    student_file.open("students info.csv",ios::out) ;
    student_file << "frist name"<< ","<< "last name"<< ","<<"ID"<< ","<<"Email"<< ","<<"Age"<< ","<<"Grade"<< ","<<"mobile"<<endl;
              //fname<<Sname<<endl;
            for (int i=0 ; i < scounter ; i++){
               //student_file.write(fname);
                student_file << s[i].sFirst_Name.toStdString()<< ","<<s[i].sLast_Name.toStdString()<< ","<< s[i].sID.toStdString()<< ","<< s[i].sEmail.toStdString()<< ","<< s[i].sAge.toStdString()<< "," <<s[i].sGrade.toStdString()<< ","<< s[i].sMobile.toStdString();
//                saggan_test=sizeof(s[i].scourses);
//                for(int j = 0 ; j<sizeof(s[i].scourses); j++){
//                    if(s[i].scourses[j] == nullptr)
//                        break;

////                    if(j==s[i].scourses->size()-1)
////                    int var=s[i].scourses->size();
//                    student_file<<","<<s[i].scourses[j].toStdString();
//                }
                student_file<<endl;
                //fname<<Sname<<endl;
            }
    //student_file.open("test.csv" , ios::out);
    student_file.close();




//    fstream student_file;
//    student_file.open("students info.csv",ios::out) ;
//    student_file << "frist name"<< ","<< "last name"<< ","<<"ID"<< ","<<"Email"<< ","<<"Age"<< ","<<"Grade"<< ","<<"mobile"<<endl;
//              //fname<<Sname<<endl;
//            for (int i=0 ; i < scounter ; i++){
//               //student_file.write(fname);
//                student_file << s[i].sFirst_Name.toStdString()<< ","<<s[i].sLast_Name.toStdString()<< ","<< s[i].sID.toStdString()<< ","<< s[i].sEmail.toStdString()<< ","<< s[i].sAge.toStdString()<< "," <<s[i].sGrade.toStdString()<< ","<< s[i].sMobile.toStdString();
//                saggan_test=sizeof(s[i].scourses);
//                for(int j = 0 ; j<sizeof(s[i].scourses); j++){
//                    if(s[i].scourses[j] == nullptr)
//                        break;

////                    if(j==s[i].scourses->size()-1)
////                    int var=s[i].scourses->size();
//                    student_file<<","<<s[i].scourses[j].toStdString();
//                }
//                student_file<<endl;
//                //fname<<Sname<<endl;
//            }
//    //student_file.open("test.csv" , ios::out);
//    student_file.close();


    fstream professor_file;
    professor_file.open("professors info.csv",ios::out) ;
    professor_file << "frist name"<< ","<< "last name"<< ","<<"ID"<< ","<<"Email"<< ","<<"Age"<< ","<<"Title"<< ","<<"mobile"<<endl;

            for (int i=0 ; i < pcounter ; i++){
               //professor_file.write(fname);
                professor_file << p[i].First_Name.toStdString()<< ","<<p[i].Last_Name.toStdString()<< ","<< p[i].ID.toStdString()<< ","<< p[i].Email.toStdString()<< ","<< p[i].Age.toStdString()<< "," <<p[i].Title.toStdString()<< ","<< p[i].Mobile.toStdString()<< ","<<endl;//fname<<Sname<<endl;
            }
    professor_file.close();


    fstream course_file;
    course_file.open("courses info.csv",ios::out) ;
    course_file << "name"<< ","<< "code"<< ","<<"lecture hall"<< ","<<"time"<< ","<<"size"<< ","<<endl;

            for (int i=0 ; i < counter ; i++){
               //course_file.write(fname);
                course_file << c[i].Name.toStdString()<< ","<<c[i].Code.toStdString()<< ","<< c[i].Lecture_Hall.toStdString()<< ","<< c[i].Time.toStdString()<< ","<< c[i].Size<< "," <<endl;
            }
    course_file.close();



}
