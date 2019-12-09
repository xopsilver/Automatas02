#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_btnAbrir_clicked();

    void on_pushButton_2_clicked();
    void analiza();
    void analizaS();
    void dame_token();
    void pilacion();
    void generarCuadruplo(QString op1,QString op2, QString oper,QString res);
    void Token(int e);
    void Error(int e);
    void cuadruploAsignacion();
    void cuadrupoSaltoFalso();
    void cuadrupoSaltoVerdadero();
    void cuadruploSaltoIncondicional();
    void llenarSaltoTope();
    void semantico(int token);
    void ejecutarSemantico();
    void metodoBonis();
    void imprimeSem();
    void exe();



    void on_btnAbrir_2_clicked();

    void on_pushButton_3_clicked();

    //void on_txtTexto2_textChanged();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    //QStandarItemModel *tabla;
};

#endif // MAINWINDOW_H
