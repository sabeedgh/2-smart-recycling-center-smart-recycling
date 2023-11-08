/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H
//
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *cd;
    QLineEdit *le_mail;
    QLineEdit *le_adresse;
    QLineEdit *le_date_1er_contact;
    QPushButton *le_ajouter;
    QPushButton *pb_modifier;
    QWidget *tab_2;
    QTableView *tab_client;
    QWidget *tab_3;
    QPushButton *pb_supprimer;
    QLabel *label;
    QLineEdit *le_supp_code;
    QWidget *tab_4;
    QLabel *label_2;
    QLineEdit *le_email;
    QPushButton *pushButton;
    QLineEdit *le_code;
    QLineEdit *le_ad;
    QLineEdit *le_date;
    QLineEdit *le_add;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(601, 446);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(30, 50, 541, 311));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 20, 391, 221));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 60, 71, 16));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 100, 56, 16));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 140, 56, 16));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 180, 101, 16));
        cd = new QLineEdit(groupBox_2);
        cd->setObjectName(QStringLiteral("cd"));
        cd->setGeometry(QRect(130, 60, 113, 22));
        le_mail = new QLineEdit(groupBox_2);
        le_mail->setObjectName(QStringLiteral("le_mail"));
        le_mail->setGeometry(QRect(130, 100, 113, 22));
        le_adresse = new QLineEdit(groupBox_2);
        le_adresse->setObjectName(QStringLiteral("le_adresse"));
        le_adresse->setGeometry(QRect(130, 140, 113, 22));
        le_date_1er_contact = new QLineEdit(groupBox_2);
        le_date_1er_contact->setObjectName(QStringLiteral("le_date_1er_contact"));
        le_date_1er_contact->setGeometry(QRect(130, 180, 113, 22));
        le_ajouter = new QPushButton(groupBox_2);
        le_ajouter->setObjectName(QStringLiteral("le_ajouter"));
        le_ajouter->setGeometry(QRect(280, 90, 93, 28));
        pb_modifier = new QPushButton(groupBox_2);
        pb_modifier->setObjectName(QStringLiteral("pb_modifier"));
        pb_modifier->setGeometry(QRect(280, 140, 93, 28));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tab_client = new QTableView(tab_2);
        tab_client->setObjectName(QStringLiteral("tab_client"));
        tab_client->setGeometry(QRect(5, 11, 491, 261));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        pb_supprimer = new QPushButton(tab_3);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(150, 160, 93, 28));
        label = new QLabel(tab_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 80, 101, 16));
        le_supp_code = new QLineEdit(tab_3);
        le_supp_code->setObjectName(QStringLiteral("le_supp_code"));
        le_supp_code->setGeometry(QRect(250, 80, 113, 22));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        label_2 = new QLabel(tab_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 40, 211, 16));
        le_email = new QLineEdit(tab_4);
        le_email->setObjectName(QStringLiteral("le_email"));
        le_email->setGeometry(QRect(310, 40, 113, 22));
        pushButton = new QPushButton(tab_4);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(370, 130, 93, 28));
        le_code = new QLineEdit(tab_4);
        le_code->setObjectName(QStringLiteral("le_code"));
        le_code->setGeometry(QRect(120, 90, 113, 22));
        le_ad = new QLineEdit(tab_4);
        le_ad->setObjectName(QStringLiteral("le_ad"));
        le_ad->setGeometry(QRect(120, 130, 113, 22));
        le_date = new QLineEdit(tab_4);
        le_date->setObjectName(QStringLiteral("le_date"));
        le_date->setGeometry(QRect(120, 180, 113, 22));
        le_add = new QLineEdit(tab_4);
        le_add->setObjectName(QStringLiteral("le_add"));
        le_add->setGeometry(QRect(120, 230, 113, 22));
        tabWidget->addTab(tab_4, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 601, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Ajout", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Code_fiscale", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Mail", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Adresse", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Date_1er_contact", Q_NULLPTR));
        le_ajouter->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        pb_modifier->setText(QApplication::translate("MainWindow", "modifier", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Ajouter un client", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Afficher les clients", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "code fiscale", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Supprimer un client", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "rechercher selon l'adresse mail", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "chercher", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Page", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
