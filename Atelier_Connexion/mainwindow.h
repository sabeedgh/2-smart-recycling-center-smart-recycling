#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"employe.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajout_clicked();
    void on_afficher_clicked();
    void on_supprimer_clicked();
    void on_modifier_clicked();
    void on_trier_clicked();
    void on_chercher_clicked();



    void on_PDF_clicked();

    void on_pushButton_8_clicked();

    void on_selectii_currentIndexChanged(QString);

private:

    Ui::MainWindow *ui;
    Employe Emp;
};







#endif // MAINWINDOW_H
