#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_login_clicked();

    void on_pushButton_stu_clicked();

    void on_pushButton_ser_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_addstu_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_SER_clicked();

    void on_pushButton_ADD_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_pro_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_course_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_creat_clicked();

    void on_pushButton_search3_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_addstu_2_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_19_clicked();







   // void on_tableWidget_profofcourse_itemClicked(QTableWidgetItem *item);

    void on_pushButton_22_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
