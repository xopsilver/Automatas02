/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPlainTextEdit *txtTokens;
    QLabel *label;
    QPlainTextEdit *txtErrores;
    QLabel *label_2;
    QLabel *label_3;
    QTabWidget *tabWidget;
    QWidget *hola;
    QPushButton *btnAbrir;
    QPlainTextEdit *txtTexto;
    QPushButton *pushButton_2;
    QWidget *tab_2;
    QPlainTextEdit *txtTexto2;
    QPushButton *btnAbrir_2;
    QPushButton *pushButton_3;
    QTableWidget *tabla;
    QLabel *label_4;
    QPlainTextEdit *txtPilas;
    QLabel *label_5;
    QTableWidget *tablaExe;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1607, 760);
        QFont font;
        font.setPointSize(5);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0.170455, y1:0.465909, x2:0.977273, y2:0.438, stop:0 rgba(97, 0, 146, 255), stop:1 rgba(0, 0, 127, 255));"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        txtTokens = new QPlainTextEdit(centralWidget);
        txtTokens->setObjectName(QString::fromUtf8("txtTokens"));
        txtTokens->setGeometry(QRect(350, 50, 361, 161));
        txtTokens->setStyleSheet(QString::fromUtf8("background-color: rgb(203, 190, 255);\n"
"color:rgb(85, 0, 127);"));
        txtTokens->setReadOnly(true);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(630, 250, 71, 16));
        label->setStyleSheet(QString::fromUtf8("font: 11pt \"Century Gothic\";\n"
"color: rgb(85, 255, 255);\n"
"\n"
"text-decoration: underline;"));
        txtErrores = new QPlainTextEdit(centralWidget);
        txtErrores->setObjectName(QString::fromUtf8("txtErrores"));
        txtErrores->setGeometry(QRect(350, 280, 361, 171));
        txtErrores->setStyleSheet(QString::fromUtf8("background-color: rgb(203, 190, 255);\n"
"color:rgb(85, 0, 127);\n"
"border-color: rgb(255, 255, 255);"));
        txtErrores->setReadOnly(true);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(640, 20, 81, 16));
        label_2->setStyleSheet(QString::fromUtf8("font: 11pt \"Century Gothic\";\n"
"color: rgb(85, 255, 255);\n"
"\n"
"text-decoration: underline;"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 0, 461, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 16pt \"Cooper Black\";\n"
"color: white;"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 50, 331, 401));
        tabWidget->setStyleSheet(QString::fromUtf8("color:rgb(85, 0, 127);\n"
"border-color: rgb(85, 0, 127);\n"
"background-color: rgb(85, 0, 127);\n"
"font: 75 9pt \"Century Gothic\";\n"
"border:0;\n"
"background: rgb(85, 0, 127);"));
        hola = new QWidget();
        hola->setObjectName(QString::fromUtf8("hola"));
        hola->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 0, 127);\n"
"color: rgb(85, 0, 127);"));
        btnAbrir = new QPushButton(hola);
        btnAbrir->setObjectName(QString::fromUtf8("btnAbrir"));
        btnAbrir->setGeometry(QRect(10, 10, 81, 21));
        btnAbrir->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Segoe UI\";\n"
"color:rgb(92, 92, 92);\n"
"background-color: rgb(85, 170, 255);\n"
"alternate-background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"\n"
""));
        txtTexto = new QPlainTextEdit(hola);
        txtTexto->setObjectName(QString::fromUtf8("txtTexto"));
        txtTexto->setGeometry(QRect(10, 40, 291, 331));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Century Gothic"));
        font1.setPointSize(9);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(9);
        txtTexto->setFont(font1);
        txtTexto->setStyleSheet(QString::fromUtf8("background-color: rgb(213, 235, 255);"));
        txtTexto->setReadOnly(true);
        pushButton_2 = new QPushButton(hola);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 10, 111, 21));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Segoe UI\";\n"
"color:rgb(92, 92, 92);\n"
"background-color: rgb(170, 170, 255);\n"
"selection-background-color: rgb(255, 85, 127);"));
        tabWidget->addTab(hola, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tab_2->setStyleSheet(QString::fromUtf8("color: rgb(85, 0, 127);\n"
"background-color: rgb(85, 0, 127);"));
        txtTexto2 = new QPlainTextEdit(tab_2);
        txtTexto2->setObjectName(QString::fromUtf8("txtTexto2"));
        txtTexto2->setGeometry(QRect(10, 50, 301, 311));
        txtTexto2->setFont(font1);
        txtTexto2->setStyleSheet(QString::fromUtf8("background-color: rgb(213, 235, 255);"));
        txtTexto2->setReadOnly(false);
        btnAbrir_2 = new QPushButton(tab_2);
        btnAbrir_2->setObjectName(QString::fromUtf8("btnAbrir_2"));
        btnAbrir_2->setGeometry(QRect(10, 10, 91, 21));
        btnAbrir_2->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Segoe UI\";\n"
"color:rgb(92, 92, 92);\n"
"background-color: rgb(85, 170, 255);\n"
"alternate-background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"\n"
""));
        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(140, 10, 91, 21));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Segoe UI\";\n"
"color:rgb(92, 92, 92);\n"
"background-color: rgb(170, 170, 255);\n"
"selection-background-color: rgb(255, 85, 127);"));
        tabWidget->addTab(tab_2, QString());
        tabla = new QTableWidget(centralWidget);
        if (tabla->columnCount() < 5)
            tabla->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tabla->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tabla->setObjectName(QString::fromUtf8("tabla"));
        tabla->setGeometry(QRect(750, 30, 401, 411));
        tabla->setStyleSheet(QString::fromUtf8("background-color: rgb(203, 190, 255);\n"
"color:rgb(85, 0, 127);"));
        tabla->horizontalHeader()->setDefaultSectionSize(74);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(770, 10, 121, 16));
        label_4->setStyleSheet(QString::fromUtf8("font: 11pt \"Century Gothic\";\n"
"color: rgb(85, 255, 255);\n"
"\n"
"text-decoration: underline;"));
        txtPilas = new QPlainTextEdit(centralWidget);
        txtPilas->setObjectName(QString::fromUtf8("txtPilas"));
        txtPilas->setGeometry(QRect(160, 520, 821, 171));
        txtPilas->setStyleSheet(QString::fromUtf8("background-color: rgb(203, 190, 255);\n"
"color:rgb(85, 0, 127);\n"
"border-color: rgb(255, 255, 255);"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(160, 480, 221, 21));
        label_5->setStyleSheet(QString::fromUtf8("font: 11pt \"Century Gothic\";\n"
"color: rgb(85, 255, 255);\n"
"\n"
"text-decoration: underline;"));
        tablaExe = new QTableWidget(centralWidget);
        if (tablaExe->columnCount() < 5)
            tablaExe->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tablaExe->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tablaExe->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tablaExe->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tablaExe->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tablaExe->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        tablaExe->setObjectName(QString::fromUtf8("tablaExe"));
        tablaExe->setGeometry(QRect(1170, 30, 401, 411));
        tablaExe->setStyleSheet(QString::fromUtf8("background-color: rgb(203, 190, 255);\n"
"color:rgb(85, 0, 127);"));
        tablaExe->horizontalHeader()->setDefaultSectionSize(74);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1607, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Analizadores y generado de c\303\263digo", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Errores", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Tokens", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Analizadores y generador de c\303\263digo", nullptr));
        btnAbrir->setText(QCoreApplication::translate("MainWindow", "Abrir", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Analizar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(hola), QCoreApplication::translate("MainWindow", "Archivo", nullptr));
        btnAbrir_2->setText(QCoreApplication::translate("MainWindow", "Guardar", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Analizar", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Editor", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tabla->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Num", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tabla->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Operador", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tabla->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Oper 1", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tabla->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Oper 2", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tabla->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Res", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Cu\303\241druplos", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Impresion de pilas", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tablaExe->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Num", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tablaExe->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Operador", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tablaExe->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Oper 1", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tablaExe->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Oper 2", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tablaExe->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Res", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
