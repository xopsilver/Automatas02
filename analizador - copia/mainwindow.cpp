#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <string.h>
#include <fstream>
#include <iostream>
#include <QDebug>
#include <QFileInfo>
#include <QList>
#include  <QCoreApplication>
#include <QStack>
#include <QStandardItemModel>
#include <QCoreApplication>
#include <QStack>
#include <vector>


using namespace std;
using std::string;

//void MainWindow::analiza();
std::string cadena();
char leerCaracter();
int Relaciona(char c);
static int cont=0;
static int pasada=0;
static int edo, col;

static char car;
static bool pausa=false;
static std::string cadenita;
static std::string cadenota;
static std::string token="";
static std::string elemento="";
static std::string tipo="";
static bool band2=0;
static bool bandopdor=0;
static bool banfor=0;
//Semantico
QList<QString>ENombre;
QList<QString>EValor;
QStack <QString> pila_ores;
QStack <QString> pila_op;
QStack <int> pila_saltos;
QStack <int> pila_errores;
std::vector<QString> pilaTiposid;
std::vector<int> pilaTiposdatok;
int varControl = 0;
int contadorVariables = 0;
static int contadorSem=0;
QList<QString> posibleCiclo;
QString opdorFor ;
QString varfor;
static int contCuad=1;
static int contR=1;
static void generarCuadruplo(QString op1,QString op2, QString oper);
static bool ban1=0;
static bool banwhile= 0;
static int auxP1=1,auxP2=1,auxP3=1,auxP4=1,auxP5=1;

QString matriz [25][12] ={ {"20","20","20","21","x","x","x","24","24","24","24","20"},
                           {"21","21","21","21","x","x","x","24","24","24","24","x"},
                           {"x","x","x","x","x","x","x","x","x","x","x","x"},
                           {"x","x","x","x","x","x","x","x","x","x","x","x"},
                           {"x","x","x","x","x","x","x","x","x","x","x","x"},
                           {"21","21","21","21","x","x","x","24","24","24","24","21"},
                           {"21","21","21","21","x","x","x","24","24","24","24","21"},
                           {"x","x","x","x","x","x","x","x","x","x","x","x"},
                           {"x","x","x","x","x","x","x","x","x","x","x","x"},
                           {"x","x","x","x","x","x","x","x","x","x","x","x"},
                           {"x","x","x","x","x","x","x","x","x","x","x","x"},
                           {"x","x","x","x","x","x","x","x","x","x","x","x"},
                           {"x","x","x","x","x","x","x","24","24","24","24","23"},
                           {"x","x","x","x","x","x","x","24","24","24","24","x"},
                           {"x","x","x","x","x","x","x","x","x","x","x","x"},
                           {"x","x","x","x","x","x","x","x","x","x","x","x"},
                           {"x","x","x","x","x","x","x","x","x","x","x","x"},
                           {"x","x","x","x","x","x","x","24","24","24","24","x"},
                           {"x","x","x","x","x","x","x","24","24","24","24","22"},
                           {"x","x","x","x","x","x","x","x","x","x","x","x"},
                           {"x","x","x","x","x","x","x","x","x","x","x","x"},
                           {"x","x","x","x","x","x","x","x","x","x","x","x"},
                           {"x","x","x","x","x","x","x","x","x","x","x","x"},
                           {"x","x","x","x","x","x","x","x","x","x","x","x"},
                           {"x","x","x","x","24","24","x","24","24","24","24","24"}
};
;





/////////////////
static QStack<std::string> pili;


static void limpiar();
static void cheki();
//static void pilacion();
static void pila();
static void guardaTokens(int edo, std::string valor);
//static void dame_token();
static void producciones();
static int numero(QString p);
static int relacionC(std::string tip);
static int relacionF(std::string tip);
static bool checarPV(std::string token);
static bool archi;
static bool ultimo=false;

static QList <int>tokenEdo;
static QList<std::string> tokenValor;


//semantico

void MainWindow::exe(){
    {
        //Metodo de ejecución
        qDebug() <<"*********Son" <<ui->tabla->rowCount() <<"filas";

         //perrito

       int i=0;
        while (i<ui->tabla->rowCount())
        {
             qDebug()<<"Valor de i : "<<i;
            if(i==ui->tabla->rowCount()){
                break;
            }
           // if(i==5){break;}





          int j=0;
            while (j<ui->tabla->columnCount())
            {


            ui->tablaExe->setItem(i,j,new QTableWidgetItem(ui->tabla->model()->data(ui->tabla->model()->index(i,j)).toString())); //num
           if(j==4){
               QString oper=ui->tabla->model()->data(ui->tabla->model()->index(i,1)).toString();

////Perro1
               if(oper=="sv"){
                   qDebug()<<"Entro a un SALTO Verdadero";
                  // QString check=ui->tabla->model()->data(ui->tabla->model()->index(i-1,4)).toString();

                   QString antes=ui->tablaExe->model()->data(ui->tablaExe->model()->index(i,2)).toString();
                   antes=EValor.at(ENombre.indexOf(antes));
                   qDebug()<<"Antes: "<<antes;

                   bool ciclo=0;
                   QString nombre=ui->tabla->model()->data(ui->tabla->model()->index(i,2)).toString();
                   for (int q=0;q<posibleCiclo.length();++q) {
                       if(nombre==posibleCiclo.at(q)){
                           ciclo=1;
                           break;
                       }
                      }
                   qDebug()<<"Nombre: "<<nombre;
                   qDebug()<<"Indice de valor: "<< ENombre.indexOf(nombre);
                   qDebug()<<"Ciclo: "<<ciclo;


                   ui->tablaExe->setItem(i,2,new QTableWidgetItem(EValor.at(ENombre.indexOf(nombre)))); //QUITAR COMENTARIO

                       if(ui->tablaExe->model()->data(ui->tabla->model()->index(i,2)).toString()=="V"){
                                  int ii=i;
                                 i=ui->tabla->model()->data(ui->tabla->model()->index(i,4)).toInt()-2;
                                 qDebug()<<"Se dio un sv de "<<ii+1<<" a "<<i+i;
                                  ii++;
                               while (ii<ui->tabla->rowCount())
                               {
                                     int jj=0;
                                   while(jj<ui->tabla->columnCount()){
                                  if(!ciclo){
                                      ui->tablaExe->setItem(ii,jj,new QTableWidgetItem(ui->tabla->model()->data(ui->tabla->model()->index(ii,jj)).toString())); //num
                                      ui->tablaExe->item(ii,jj)->setBackground(Qt::gray);
                                  } else{
                                      ui->tablaExe->item(ii,jj)->setBackground(Qt::magenta);
                                  }
                                   jj++;
                                   }
                                    ii++;
                               }

                       }
               }
/// perro2




               if(oper=="sf"){
                   qDebug()<<"Entro a un SALTO EN FALSO";
                  // QString check=ui->tabla->model()->data(ui->tabla->model()->index(i-1,4)).toString();

                   QString antes=ui->tablaExe->model()->data(ui->tablaExe->model()->index(i,2)).toString();
                   antes=EValor.at(ENombre.indexOf(antes));
                   qDebug()<<"Antes: "<<antes;

                   bool ciclo=0;
                   QString nombre=ui->tabla->model()->data(ui->tabla->model()->index(i,2)).toString();
                   for (int q=0;q<posibleCiclo.length();++q) {
                       if(nombre==posibleCiclo.at(q)){
                           ciclo=1;
                           break;
                       }
                      }
                   qDebug()<<"Nombre: "<<nombre;
                   qDebug()<<"Indice de valor: "<< ENombre.indexOf(nombre);
                   qDebug()<<"Ciclo: "<<ciclo;


                   ui->tablaExe->setItem(i,2,new QTableWidgetItem(EValor.at(ENombre.indexOf(nombre)))); //QUITAR COMENTARIO

                       if(ui->tablaExe->model()->data(ui->tabla->model()->index(i,2)).toString()=="F"){
                                  int ii=i;
                                 i=ui->tabla->model()->data(ui->tabla->model()->index(i,4)).toInt()-2;
                                 qDebug()<<"Se dio un sf de "<<ii+1<<" a "<<i+i;
                                  ii++;
                               while (ii<ui->tabla->rowCount())
                               {
                                     int jj=0;
                                   while(jj<ui->tabla->columnCount()){
                                  if(!ciclo){
                                      ui->tablaExe->setItem(ii,jj,new QTableWidgetItem(ui->tabla->model()->data(ui->tabla->model()->index(ii,jj)).toString())); //num
                                      ui->tablaExe->item(ii,jj)->setBackground(Qt::gray);
                                  } else{
                                      //ui->tablaExe->setItem(ii,jj,new QTableWidgetItem(ui->tabla->model()->data(ui->tabla->model()->index(ii,jj)).toString())); //num
                                      ui->tablaExe->item(ii,jj)->setBackground(Qt::magenta);
                                  }
                                   jj++;
                                   }
                                    ii++;
                               }

                       }
               }

               if(oper=="si"){
                    QString ch=ui->tabla->model()->data(ui->tabla->model()->index(i,4)).toString();
                    if(ch.toInt()>ui->tabla->rowCount()){

                        int ii=i;
                        i=ui->tabla->model()->data(ui->tabla->model()->index(i,4)).toInt()-2;
                        qDebug()<<"Se dio un sf de "<<ii+1<<" a "<<i+i;
                      ii++;
                      while (ii<ui->tabla->rowCount())
                      {
                          int jj=0;
                          while(jj<ui->tabla->columnCount()){
                          ui->tablaExe->setItem(ii,jj,new QTableWidgetItem(ui->tabla->model()->data(ui->tabla->model()->index(ii,jj)).toString())); //num
                          ui->tablaExe->item(ii,jj)->setBackground(Qt::gray);
                          jj++;
                          }
                           ii++;
                      }
                        i=ui->tabla->rowCount();
                        break;
                     } else {
                        i=ch.toInt()-2;
                    }

               }

               if(oper=="="){
                   qDebug()<<"%%ENTRO A GUARDAD VARIABLES!!!!!!!!";

                   //veamos si existe
                   QString nom=ui->tabla->model()->data(ui->tabla->model()->index(i,2)).toString();
        //Aqui debe de analizar las Rn también
                   int e=0;
                   while(e<ENombre.count())
                   {
                       if(nom==ENombre.at(e)){
                           //yayo
                           qDebug()<<nom<< "Ya existia";
                           //vamos a hacer una exepcion para una asignacion de una que ya existía
                            QString valor=ui->tabla->model()->data(ui->tabla->model()->index(i,4)).toString();
                            int s=0;
                           while (s<ENombre.length()) {
                               if(ENombre.at(s)==valor){
                                   QString vNuevo=ui->tablaExe->model()->data(ui->tablaExe->model()->index(i,4)).toString();
                                   qDebug()<<"Todo bien";
                                   qDebug()<<"vNuevo:"<<vNuevo;
                                   vNuevo=EValor.at(ENombre.indexOf(vNuevo));
                                   qDebug()<<"El nuevo valor será:"<<vNuevo;
                                   QString r=ui->tabla->model()->data(ui->tabla->model()->index(i,4)).toString();

                                    ui->tablaExe->setItem(i,4,new QTableWidgetItem(EValor.at(ENombre.indexOf(r))));
                                    EValor.replace(e,vNuevo);

                                   break;
                               }
                               s++;
                           }
                           if(s==ENombre.count()){
                               ui->tablaExe->setItem(i,4,new QTableWidgetItem(valor));
                               EValor.replace(e,valor);
                           }

                           break;
                       }
                       e++;
                   }
                   if(e==ENombre.count()){
                        qDebug()<<nom<< "Es nuevecito";
                      ENombre.append(ui->tabla->model()->data(ui->tabla->model()->index(i,2)).toString());
                      EValor.append(ui->tabla->model()->data(ui->tabla->model()->index(i,4)).toString());
                   }


               }

             if( oper=="*" || oper=="/" || oper=="-" || oper=="+" ){

                 qDebug()<<"%%ENTRO A UNA Operacion!!!!!!!!!!!!!!!";
                 QString aux1=ui->tabla->model()->data(ui->tabla->model()->index(i,2)).toString();
                  float n1,n2;
                 QRegExp re("\\d*");  // a digit (\d), zero or more times (*)
                 if (re.exactMatch(aux1)){
                      qDebug() << "all digits";
                       n1=aux1.toFloat();
                 } else {
                     n1=ENombre.indexOf(aux1);
                     n1=EValor.at(n1).toFloat();
                 }



                 aux1=ui->tabla->model()->data(ui->tabla->model()->index(i,3)).toString();
                 if (re.exactMatch(aux1)){
                      qDebug() << "all digits";
                       n2=aux1.toFloat();
                 } else {
                     n2=ENombre.indexOf(aux1);
                     n2=EValor.at(n2).toFloat();
                 }
                 qDebug()<<"Hara operacion";
                 qDebug()<<n1<<oper<<n2;



                 float resu;

                 if(oper=="+"){
                     resu=n1+n2;
                 }
                 if(oper=="-"){
                     resu=n1-n2;
                 }
                 if(oper=="*"){
                     resu=n1*n2;
                 }
                 if(oper=="/"){
                     resu=n1+n2;
                 }
                 qDebug()<<"Resu:"<<resu;

                 //chequemos sí ya exisita
                 //checar si exite antes de insertar
                                    //anclii
                                     QString nom=ui->tabla->model()->data(ui->tabla->model()->index(i,4)).toString();
                                     int e=0;
                                     while(e<ENombre.count())
                                     {
                                         if(nom==ENombre.at(e)){
                                             qDebug()<<nom<< "Ya existia";
                                             //aqui va otra cosa
                                            ui->tablaExe->setItem(i,4,new QTableWidgetItem(QString::number(resu)));
                                            QString vNuevo=ui->tablaExe->model()->data(ui->tablaExe->model()->index(i,4)).toString();
                                            EValor.replace(e,vNuevo);

                                             //ay wey
                                             break;
                                         }
                                         e++;
                                     }
                                     if(e==ENombre.count()){
                                          qDebug()<<nom<< "Es nuevecito";

                                        ENombre.append(ui->tabla->model()->data(ui->tabla->model()->index(i,4)).toString());
                                       ui->tablaExe->setItem(i,4,new QTableWidgetItem(QString::number(resu)));
                                        EValor.append(ui->tablaExe->model()->data(ui->tablaExe->model()->index(i,4)).toString());

                                        //por favor DIos :'v

                                     }









             }
             /////////////
               if(oper=="<" || oper=="<=" || oper==">" || oper==">=" || oper=="==" || oper=="!="  ){

                   qDebug()<<"%%ENTRO A UNA COMPARACION!!!!!!!!!!!!!!!";
                   QString aux1=ui->tabla->model()->data(ui->tabla->model()->index(i,2)).toString();
                   float n1;

                   QRegExp re("\\d*");  // a digit (\d), zero or more times (*)
                   if (re.exactMatch(aux1)){
                       //es numero
                       n1=aux1.toFloat();
                   } else{
                       n1=ENombre.indexOf(aux1);
                       n1=EValor.at(n1).toFloat();
                   }

                   aux1=ui->tabla->model()->data(ui->tabla->model()->index(i,3)).toString();
                   float n2;
                   if (re.exactMatch(aux1)){
                       qDebug()<<"es numero";
                       n2=aux1.toFloat();
                   } else{
                       n2=ENombre.indexOf(aux1);
                       n2=EValor.at(n2).toFloat();
                   }


                 bool res;
                   if(oper=="<"  ){
                      res=n1<n2;
                   }
                   if( oper=="<="  ){
                        res=n1<=n2;
                   }
                   if(oper==">" ){
                        res=n1>n2;
                   }
                   if(oper==">="){
                        res=n1>=n2;
                   }
qDebug()<<n1<<"oper"<<n2<<"="<<res;
                //Aqui vamos a agregar
                   //checar si exite antes de insertar
                                      //anclii
                                       QString nom=ui->tabla->model()->data(ui->tabla->model()->index(i,4)).toString();
                                       int e=0;
                                       while(e<ENombre.count())
                                       {
                                           if(nom==ENombre.at(e)){
                                               qDebug()<<nom<< "Ya existia";
                                               //wewe
                                               //
                                               posibleCiclo.append(nom);
                                               if(res==0){
                                                   ui->tablaExe->setItem(i,4,new QTableWidgetItem("F"));
                                              } else {
                                                   ui->tablaExe->setItem(i,4,new QTableWidgetItem("V"));
                                              }

                                               QString vNuevo=ui->tablaExe->model()->data(ui->tablaExe->model()->index(i,4)).toString();
                                               EValor.replace(e,vNuevo);

                                               //ay wey
                                               break;
                                           }
                                           e++;
                                       }
                                       if(e==ENombre.count()){
                                            qDebug()<<nom<< "Es nuevecito";

                                          ENombre.append(ui->tabla->model()->data(ui->tabla->model()->index(i,4)).toString());
                                        if(res==0){
                                            ui->tablaExe->setItem(i,4,new QTableWidgetItem("F"));
                                       } else {
                                            ui->tablaExe->setItem(i,4,new QTableWidgetItem("V"));
                                       }
                                       EValor.append(ui->tablaExe->model()->data(ui->tablaExe->model()->index(i,4)).toString());

                                          //por favor DIos :'v

                                       }

                   //fin de agregar


               } //fin de comparacion
               QString pilita;
               for(int i=0;i<ENombre.length();i++){
                    pilita+="  "+(ENombre.at(i));
               }

               qDebug() <<+"|"+pilita+"|";
               QString pilita2;
               for(int i=0;i<EValor.length();i++){
                    pilita2+="  "+(EValor.at(i));
               }
               qDebug() <<+"|"+pilita2+"|";
               qDebug() <<"--------------------------------------------------------------------------------";

           }
           j++;
            }
    i++;

        }
    // continuar

    }

}

void MainWindow::ejecutarSemantico(){
    qDebug() << "Iniciar Semantico";
    qDebug() << "tamaño" << tokenEdo.size();

    while(contadorSem<tokenEdo.size()){
        qDebug() << "edo: " << tokenEdo.at(contadorSem) << " token: "<< QString::fromStdString(tokenValor.at(contadorSem));
        qDebug() << "vuelta: " << contadorSem;
        semantico(tokenEdo.at(contadorSem));

        contadorSem++;
    }
     for(int i=0;i<ui->tabla->rowCount();++i){
         ui->tablaExe->insertRow(ui->tablaExe->rowCount());
     }
    MainWindow::exe();

}

QString busquedaMatriz()
{
    QString p="@";
for(int i=0;i<pilaTiposid.size();i++){
    qDebug() << QString::fromStdString(tokenValor.at(contadorSem)) << " = " << pilaTiposid.at(i);
    if(QString::fromStdString(tokenValor.at(contadorSem))==pilaTiposid.at(i)){
     p="a";
     break;
    }
}
qDebug()<<"Tiene que regresar esto: "<<p;
    return p;
}

int getTipoDato(QString op)
{
    int tipoDato =0;
    for(int i=0;i<pilaTiposid.size();i++)
    {
        if(pilaTiposid.at(i) == op)
        {
            tipoDato = pilaTiposdatok.at(i);
            break;
        }
    }
    return tipoDato;
}

QString getValorMatriz(QString op1,QString op2, QString oper)
{
    QString tipoDato = "";
    int fila = 0;
    int tipo = getTipoDato(op1);
    qDebug() << "tipo dato1" << tipo;
    int tipo2 = getTipoDato(op2);
    qDebug() << "tipo dato2" << tipo2;
    // Entero 20  Float 21  Char  22  String 23  Boolean 24
     if (tipo == 20 && tipo2 == 20 )
     {
      fila = 0;
     }
     if (tipo == 20 && tipo2 == 21 )
     {
       fila = 1;
     }
     if (tipo == 20 && tipo2 == 23 )
     {
         fila = 2;
     }
     if (tipo == 20 && tipo2 == 22 )
     {
         fila = 3;
     }
     if (tipo == 20 && tipo2 == 24 )
     {
         fila = 4;
     }


             if (tipo == 21 && tipo2 == 20 )
             {
               fila = 5;
             }
             if (tipo == 21 && tipo2 == 21 )
             {
                 fila = 6;
             }
             if (tipo == 21 && tipo2 == 23 )
             {
                 fila = 7;
             }
             if (tipo == 21 && tipo2 == 22 )
             {
                 fila = 8;
             }
             if (tipo == 21 && tipo2 == 24 )
             {
                fila = 9;
             }

               if (tipo == 23 && tipo2 == 20 )
               {
                   fila = 10;
               }
               if (tipo == 23 && tipo2 == 21 )
               {
                   fila = 11;
               }
               if (tipo == 23 && tipo2 == 23 )
               {
                   fila = 12;
               }
               if (tipo == 23 && tipo2 == 22 )
               {
                   fila = 13;
               }
               if (tipo == 23 && tipo2 == 24 )
               {
                   fila = 14;
               }

                       if (tipo == 22 && tipo2 == 20 )
               {
                   fila = 15;
               }
               if (tipo == 22 && tipo2 == 21 )
               {
                   fila = 16;
               }
               if (tipo == 22 && tipo2 == 23 )
               {
                   fila = 17;
               }
               if (tipo == 22 && tipo2 == 22 )
               {
                   fila = 18;
               }
               if (tipo == 22 && tipo2 == 24 )
               {
                   fila = 19;
               }

                       if (tipo == 24 && tipo2 == 20 )
                       {
                           fila = 20;
                       }
                       if (tipo == 24 && tipo2 == 21 )
                       {
                        fila = 21;
                       }
                       if (tipo == 24 && tipo2 == 23 )
                       {
                           fila = 22;
                       }
                       if (tipo == 24 && tipo2 == 22 )
                       {
                           fila = 23;
                       }
                       if (tipo == 24 && tipo2 == 24 )
                       {
                           fila = 24;
                       }

        qDebug() << "Fila: "<< fila;
     if(oper == "+")
     {
         tipoDato = matriz [fila][0];
     }
     if(oper == "-")
     {
        tipoDato = matriz [fila][1];
     }
     if(oper == "*")
     {
          tipoDato = matriz [fila][2];
     }
     if(oper == "/")
     {
          tipoDato = matriz [fila][3];
     }
     if(oper == "||")
     {
          tipoDato = matriz [fila][4];
     }
     if(oper == "&&")
     {
       tipoDato = matriz [fila][5];
     }
     if(oper == "%")
     {
          tipoDato = matriz [fila][6];
     }
     if(oper == "<")
     {
          tipoDato = matriz [fila][7];
     }
     if(oper == "<=")
     {
          tipoDato = matriz [fila][8];
     }
     if(oper == ">")
     {
          tipoDato = matriz [fila][9];
     }
     if(oper == ">=")
     {
          tipoDato = matriz [fila][10];
     }
     if(oper == "=")
     {
          tipoDato = matriz [fila][11];
     }

     return tipoDato;

}

void MainWindow::metodoBonis()
{

                QString op2=pila_op.pop();
                QString op1=pila_op.pop();
                QString oper=pila_ores.pop();
                QString res=getValorMatriz(op1,op2,oper);// este es verdadero analizador semantico

                if(res!="x"){
                    if(band2)
                    {
                       varfor = op1;
                       band2=0;
                    }
                    if(bandopdor)
                    {
                        //dsi es verdadero, guarda el operador de la operacion semantica
                            //for(i < 10)
                        //bandera de for despues e ejecutar la operacion relacional y obtener el operador de la operacion para saber si es sv o sf
                        opdorFor=oper;
                        bandopdor=0;
                    }
                    generarCuadruplo(op1,op2,oper,res);
                } else {

                    pila_errores.push(303); //aqui es error entre tipos
                    if(band2)
                    {
                       varfor = op1;
                       band2=0;
                    }
                    if(bandopdor)
                    {
                        opdorFor=oper;
                        bandopdor=0;
                    }
                    generarCuadruplo(op1,op2,oper,res);
                    ui->txtErrores->appendPlainText("Error 303 Error entre tipos (Cuadrupo "+QString::number(contCuad-1)+")");
                }
}

void MainWindow::cuadruploAsignacion()
{
    QString op2=pila_op.pop();
    qDebug() << "op2" << op2;
    QString op1=pila_op.pop();
     qDebug() << "op1" << op1;
    QString oper=pila_ores.pop();
     qDebug() << "oper" << oper;
    QString res=getValorMatriz(op1,op2,oper); // esta es la verficacion semantica
    qDebug() << res;

    if(res!="x"){
        qDebug() << "Hizo cuadruplo Asignacion";
       // Este es el cuadruplo de asignacion
        ui->tabla->insertRow(ui->tabla->rowCount());
        QString num=QString::number(contCuad);
         ui->tabla->setItem(contCuad-1,0,new QTableWidgetItem(num)); //num
          ui->tabla->setItem(contCuad-1,1,new QTableWidgetItem(oper)); //oper
           ui->tabla->setItem(contCuad-1,2,new QTableWidgetItem(op1)); //op1


             ui->tabla->setItem(contCuad-1,4,new QTableWidgetItem(op2)); //res
        contCuad++; //agregar a la pila el resultado





    } else {
        qDebug() << "Hizo cuadruplo Asignacion";
       // Este es el cuadruplo de asignacion
        ui->tabla->insertRow(ui->tabla->rowCount());
        QString num=QString::number(contCuad);
         ui->tabla->setItem(contCuad-1,0,new QTableWidgetItem(num)); //num
          ui->tabla->setItem(contCuad-1,1,new QTableWidgetItem(oper)); //oper
           ui->tabla->setItem(contCuad-1,2,new QTableWidgetItem(op1)); //op1


             ui->tabla->setItem(contCuad-1,4,new QTableWidgetItem(op2)); //res
        contCuad++; //agregar a la pila el resultado
         ui->txtErrores->appendPlainText("Error 303 Error entre tipos (Cuadrupo "+QString::number(contCuad-1)+")");
        pila_errores.push(303); //aqui es error entre tipos

    }
}

void MainWindow::cuadrupoSaltoFalso()
{
    QString op = pila_op.pop();// saca operando para el sf

    ui->tabla->insertRow(ui->tabla->rowCount());
    QString num=QString::number(contCuad);
        //crea en la tabla el cuadruplo del salto en falso
      ui->tabla->setItem(contCuad-1,0,new QTableWidgetItem(num)); //num
      ui->tabla->setItem(contCuad-1,1,new QTableWidgetItem("sf")); //oper
      ui->tabla->setItem(contCuad-1,2,new QTableWidgetItem(op)); //op1
      ui->tabla->setItem(contCuad-1,4,new QTableWidgetItem("")); //res

    contCuad++; //agregar a la pila el resultado

    qDebug() << "aqui hizo el salto";
    pila_saltos.push(contCuad-1); // ignorar

}
void  MainWindow::cuadrupoSaltoVerdadero()
{
    QString op = pila_op.pop();

    ui->tabla->insertRow(ui->tabla->rowCount());
    QString num=QString::number(contCuad);

      ui->tabla->setItem(contCuad-1,0,new QTableWidgetItem(num)); //num
      ui->tabla->setItem(contCuad-1,1,new QTableWidgetItem("sv")); //oper
      ui->tabla->setItem(contCuad-1,2,new QTableWidgetItem(op)); //op1
      ui->tabla->setItem(contCuad-1,4,new QTableWidgetItem("")); //res

    contCuad++; //agregar a la pila el resultado

    pila_saltos.push(contCuad-1);
}
void  MainWindow::cuadruploSaltoIncondicional()
{

    ui->tabla->insertRow(ui->tabla->rowCount());
    QString num=QString::number(contCuad);

      ui->tabla->setItem(contCuad-1,0,new QTableWidgetItem(num)); //num
      ui->tabla->setItem(contCuad-1,1,new QTableWidgetItem("si")); //oper
      //ui->tabla->setItem(contCuad-1,2,new QTableWidgetItem(op)); //op1
      ui->tabla->setItem(contCuad-1,4,new QTableWidgetItem("")); //res

    contCuad++; //agregar a la pila el resultado
    qDebug() << "si lo metio";
    pila_saltos.push(contCuad-1);
}

void  MainWindow::llenarSaltoTope()
{
    imprimeSem();
int aux=pila_saltos.pop();
qDebug() << "Tope de saltos"<< aux;
 QString num;
 if(banwhile)
 {
     qDebug() << "Llenando SI while";
    int numa=(contCuad);
    int aux2=pila_saltos.pop();

    qDebug() << "auxiliar2"<< aux2 << "{"<<contCuad << "},{"<<4<<"}";

     ui->tabla->setItem(contCuad-2,4,new QTableWidgetItem(QString::number(aux2)));
     banwhile=0;
 }
     if(banfor)
     {

         qDebug() << "Llenando SI for";
         imprimeSem();
        int numa=(contCuad);
        qDebug ()<< "pila saltos" << pila_saltos.size();
        int aux2=pila_saltos.pop();
        qDebug() << pila_saltos.size();


        qDebug() << "este es el cuadruplo a llenar";
        qDebug() << "auxiliar2"<< aux2 << "{"<<aux << "},{"<<4<<"}";

         ui->tabla->setItem(aux-1,4,new QTableWidgetItem(QString::number(aux2)));
         banfor=0;
     }else
if(ban1){
     num=QString::number(contCuad+1);
     ui->tabla->setItem(aux-1,4,new QTableWidgetItem(num));
     ban1=0;
} else{
    num=QString::number(contCuad);
    ui->tabla->setItem(aux-1,4,new QTableWidgetItem(num));
}


}

//Realizar un metodo que convierte palabra RESERVADA A TOKEN
int pr_token(){
   //weon
   QString valor=QString::fromStdString(tokenValor.at(contadorSem));

   if(valor=="P.R begin")  {
       return 16;}

   else if(valor=="P.R end")  {
       return 17;}

   else if(valor=="P.R def")  {
        return 18;}

   else if(valor=="P.R as")  {
        return 19;}

   else if(valor=="P.R integer")  {
       return 20;}

   else if(valor=="P.R float")  {
        return 21;}

   else if(valor=="P.R char")  {
        return 22;}

   else if(valor=="P.R string")  {
         return 23;}

   else if(valor=="P.R boolean")  {
         return 24;}

   else if(valor=="P.R if")  {
        return 25;}

   else if(valor=="P.R else")  {
        return 26;}

   else if(valor=="P.R elseif")  {
         return 27;}

   else if(valor=="P.R endif")  {
         return 28;}

   else if(valor=="P.R for")  {
        return 29;}

   else if(valor=="P.R do")  {
         return 30;}

   else if(valor=="P.R endfor")  {
        return 41;}

   else if(valor=="P.R while")  {
        return 31;}

   else if(valor=="P.R function")  {
       return 33;}

   else if(valor=="P.R endfunction")  {
       return 34;}

   else if(valor=="P.R import")  {
        return 35;}

   else if(valor=="P.R class")  {
       return 15;}

   else if(valor=="P.R null")  {
       return 36;}

   else if(valor=="P.R read")  {
        return 37;}

   else if(valor=="P.R write")  {
        return 38;}

   else if(valor=="P.R enter")  {
        return 39;}

   else if(valor=="P.R endwhile")  {
        return 32;}

    else {
       return 999;
   }


}

void MainWindow::semantico(int token)

{
    imprimeSem();

    qDebug () << "semantco token "<< token;
    qDebug () << "Var Control: "<<varControl;
    if(token==100){
        token=pr_token();
         qDebug () << "token nuevo: "<<token;
    }
/*
     case 102:
          return fila.indexOf("cteEntera");

     case 103:
          return fila.indexOf("cteReal");

     case 104:
          return fila.indexOf("cteNotacion");

     case 105:
          return fila.indexOf("cteCaracter");

     case 106:
          return fila.indexOf("cteString");

*/
    if(token == 102)
    {
        //este es constante entera
        pilaTiposid.push_back(QString::fromStdString(tokenValor.at(contadorSem)));
        pilaTiposdatok.push_back(20);
        pila_op.push(QString::fromStdString(tokenValor.at(contadorSem)));
      // pilaTiposid.push_back(tokenValor.at(contadorSem));
    }
    if(token == 103)
    {
        //este es constante real
        qDebug() << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% entro a cte ";
        pilaTiposid.push_back(QString::fromStdString(tokenValor.at(contadorSem)));
        pilaTiposdatok.push_back(21);
        pila_op.push(QString::fromStdString(tokenValor.at(contadorSem)));
      // pilaTiposid.push_back(tokenValor.at(contadorSem));
    }
    if(token == 105)
    {
        //caracter
        pilaTiposid.push_back(QString::fromStdString(tokenValor.at(contadorSem)));
        pilaTiposdatok.push_back(22);
        pila_op.push(QString::fromStdString(tokenValor.at(contadorSem)));
      // pilaTiposid.push_back(tokenValor.at(contadorSem));
    }
    if(token == 106)
    {
        //String
        pilaTiposid.push_back(QString::fromStdString(tokenValor.at(contadorSem)));
        pilaTiposdatok.push_back(23);
        pila_op.push(QString::fromStdString(tokenValor.at(contadorSem)));
      // pilaTiposid.push_back(tokenValor.at(contadorSem));
    }
    if(token == 101)
    {

        if(varControl == 20) //Significa que esta en modo de def (por que encontró la variable def
        {
            qDebug() << "entro aqui";
        if(busquedaMatriz()=="@")
        {
            pilaTiposid.push_back(QString::fromStdString(tokenValor.at(contadorSem)));
            pilaTiposdatok.push_back(666);
            contadorVariables++;
        }else{
            ui->txtErrores->appendPlainText("Error 302: Varaible Duplicada:  "+QString::fromStdString(tokenValor.at(contadorSem)));
           qDebug() << "#############################################Variable duplicada";
        }

        }
        else if(busquedaMatriz()!= "@")
        {
         qDebug()<<"VEAMOS SI EXISTE: "<<QString::fromStdString(tokenValor.at(contadorSem));
         pila_op.push(QString::fromStdString(tokenValor.at(contadorSem))); // es de los dos Pila operandos
        }else
        {
            if(varControl==31){
                varControl=0;
            }else{
             qDebug() << "..............................Entro a error 301";
              ui->txtErrores->appendPlainText("Error 301: Variable no declarada: "+QString::fromStdString(tokenValor.at(contadorSem)));
            pilaTiposid.push_back(QString::fromStdString(tokenValor.at(contadorSem)));
            pilaTiposdatok.push_back(20);
            pila_op.push(QString::fromStdString(tokenValor.at(contadorSem)));
          pila_errores.push(301);
            }
        }

    }

    //listo, ya se terminó lo de lo IDs

    // 107 suma, 108 resta, 110 division, 109 multiplicacion
    if(token == 107 || token == 108 || token == 110  || token == 109 || token== 118 || token== 120 || token== 121 || token == 119 ||token==117  )
    {
        qDebug() << "entro al operadores";
        if(pila_ores.top() == "+" || pila_ores.top() == "-" || pila_ores.top()== "*"|| pila_ores.top() == "/" || pila_ores.top() == "<" ||  pila_ores.top() == "<=" ||  pila_ores.top() == ">" ||  pila_ores.top() == ">=" ||  pila_ores.top() == "==" )
        {
            //COmo en el tope de la pila si existe un operador se realiza la operación semántica
            //Porque tiene una operación pendiente
            metodoBonis();
            pila_ores.push(QString::fromStdString(tokenValor.at(contadorSem)));
        }else
        {
           //solo se va a meter sin analizar nada
            pila_ores.push(QString::fromStdString(tokenValor.at(contadorSem)));
        }
    }
    if(token == 15)
    {
        //este es el class
        varControl= 31;
        //en tal caso en la parte de arriba cambia a cero para que no se cree una variable sin declarar
    }
    // es el ;
    if(token ==  123)
    {
        /*
         Se realizand dos funciones
         1: Hace la función de un operador para verificar si en el top de pila_ores exite un +,-,*,/,logicos
         2: Checa si exite una asignacion en la pila de operadores.
*/
        qDebug() << "entro al metodo ;";
        if(pila_ores.size()>0){ //esto es para que no se detenga el programa por los metodos de la pila
        if(pila_ores.back() == "+" || pila_ores.back() == "-" || pila_ores.back()== "*"|| pila_ores.back() == "/" )
            //checa si hay operacion pendiente
        {
            metodoBonis(); //se realiza verificacion semantica
        }
        qDebug() << "hizo cuadruplo";
        //imprimeSem();
        if(pila_ores.back()=="=")
        {
            cuadruploAsignacion();
            //ancla

        }
        //imprimeSem();
        }
    }
    // este es el =
    if(token == 129)
    {
        qDebug() << "entro al igual";
        pila_ores.push("=");
    }
    //este es el if
    if(token == 25)
    {
        varControl = 15;
        //para saber que es if despues
    }
    // es el de (
    if(token == 125)
    {
        pila_ores.push("#");
    }
    //este es el )
    if(token == 126 )
        {
            if(varControl == 15) // encontro un if
            {
                metodoBonis(); //se hace op semantico
                cuadrupoSaltoFalso(); //cuando de hce una operacion, se insetta un sf (despues del resultado bool)
                //nene

                pila_ores.pop(); //fondo falso
            }
            if(varControl == 17) // while
            {
                metodoBonis(); //hace la verifiacion semantica

                pila_saltos.push(contCuad-1);
                cuadrupoSaltoFalso();
                pila_ores.pop(); //fondo falso
            }
            //for
            if(varControl == 16)
            {
                bandopdor = 1;
                metodoBonis();
                pila_saltos.push(contCuad-1);
                if(opdorFor == "<")
                {
                    cuadrupoSaltoFalso();
                }else
                {
                    cuadrupoSaltoVerdadero();
                }

                 pila_ores.pop(); //fondo falso
            }
            //write
            if(varControl == 19)
            {
                metodoBonis();
                 pila_ores.pop(); //fondo falso
            }
            //read
            if(varControl == 18)
            {
                metodoBonis();
                 pila_ores.pop(); //fondo falso
            }
            varControl = 0;
        }
    // este es el else
        if(token == 26)
            {
            //llena el salto en falso pendiente del if y genera el salto incondicional hasta el elseif
            ban1=1;
                llenarSaltoTope();//llena el ultimo salto pendiente
                cuadruploSaltoIncondicional();
            }
        // endif
            if(token == 28)
            {
                llenarSaltoTope();// llena el salto en el tope de la fila de saltos con el contador de l semantico
                varControl =0;
            }
        // endwhile
            if(token == 32)
                //notita
            {
                ban1=1;
                llenarSaltoTope();
                cuadruploSaltoIncondicional();
                banwhile=1;
                llenarSaltoTope();
                varControl =0;



            }
            //while
            if(token==31){
                varControl=17;
                //perrito

            }
            //este es el for
            if(token == 29)
            {
                varControl = 16;
            }
            //conejo
            //Este es el dos puntos
            if(token == 122)
            {
               // band2= 1;
                cuadruploAsignacion();


            }
            if(token == 41) //endfor
            {

                     qDebug() << "Salto for";
                     ban1=1;
                     qDebug() << "antes del sv/sf";
                     imprimeSem();
                    llenarSaltoTope();
                    qDebug() << "antes de salto Incondicional";
                     imprimeSem();
                    cuadruploSaltoIncondicional();
                    banfor=1;

                   llenarSaltoTope();

                varControl =0;
            }
            if(token == 38)
            {
                varControl = 19;
            }
            if(token == 37)
            {
                varControl = 18;
            }
            if(token == 18) //def
            {
                qDebug() << "Modo definir";
                varControl = 20;
            }
            //def a as integer|
            if(token == 20 || token == 21|| token == 22 || token == 23 || token == 24 )
                //busca en a pila  tipo de dato todos los marcas y las remplaza por el tipo de dato que recibe o token
                //el tipo de dato solo se utiliza en modo definir es decir cuando encuentra un def
                    {
                qDebug() << "entra aqui";
                        for(int i=0;i<pilaTiposdatok.size();i++)
                        {
                            //recorre la pila de tipo de datos
                            if(pilaTiposdatok.at(i) == 666) // encontro la marca que significa que una variable aun no tiene asignada el tipo de dato
                            {
                               pilaTiposdatok.at(i) = token; // lo reemplaza por el tipo de dato recibido
                            }
                        }
                        varControl =0;
                    }
} ///errores



static void imprimeTokens();


static QList <QList<QString> >prod;
static QList<QString> fila=
{
    "Prog",	//0
    "Est",	//1
    "EstA",	//2
    "Dec",	//3
    "DecA",	//4
    "DecB",	//5
    "DecB'",	//6
    "Tipo",	//7
    "EstIf",	//8
    "EstIfA",	//9
    "EstWhile",	//10
    "EstFor",	//11
    "Exp",	//12
    "Exp'",	//13
    "Exp2",	//14
    "Exp2'",	//15
    "Exp3",	//16
    "Exp4",	//17
    "Exp4'",	//18
    "Exp5",	//19
    "Exp5'",	//20
    "Term",	//21
    "Term'",	//22
    "Fact",	//23
    "DecLib",	//24
    "DecLibA",	//25
    "Opr",	//26
    "EstEnter",	//27
    "EstAsig",	//28
    "EstWrite",	//29
    "EstWriteA",	//30
    "EstWriteA'",	//31
    "EstRead",	//32
    "EstReadA",	//33
    "EstReadA'",	//34
    "vacio", //35

    "class", //36
    "import", //37
    "if",
    "while",
    "for",
    "read",
    "write",
    "enter",
    "def",
    "integer","float","char","string","boolean","else","!",
    "id",
    "cteEntera",
    "cteReal",
    "cteNotacion",
    "cteCaracter",
    "cteString",
    "(",")",
    ",",
    ";",
    ":",
    "&&","||",
    "==","!=",
    "<","<=",
    ">",">=",
    "+","-",
    "*","/","%",
    "end","endif","endwhile","endfor",
    "as",
    "begin",
    "idLib",
    "=",
    "$"
};
static QList<QString> columna={
    "class",
    "import",
    "if",
    "while",
    "for",
    "read",
    "write",
    "enter",
    "def",
    "integer",
    "float",
    "char",
    "string",
    "boolean",
    "else",
    "!",
    "id",
    "cteEnterta",
    "cteReal",
    "cteNotacion",
    "cteCaracter",
    "cteString",
    "(",
    ")",
    ",",
    ";",
    ":",
    "&&",
    "||",
    "==",
    "!=",
    "<",
    "<=",
    ">",
    ">=",
    "+",
    "-",
    "*",
    "/",
    "%",
    "end",
    "endif",
    "endwhile",
    "endfor",
    "as",
    "begin",
    "idLib",
    "=",
    "$"
};



static int primera=1;

static int ms[40][50]=
{{1,1,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600,600},
{601,601,2,2,2,2,2,2,601,601,601,601,601,601,3,601,2,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,3,3,3,3,601,601,601,601,601},
{601,601,5,6,7,8,9,10,601,601,601,601,601,601,601,601,4,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601,601},
{602,602,12,12,12,12,12,12,11,602,602,602,602,602,602,602,12,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,12,602,602,602,602,602,602,602,602},
{602,602,602,602,602,602,602,602,13,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602,602},
{603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,14,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603,603},
{604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,15,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,604,16,604,604,604,604},
{605,605,605,605,605,605,605,605,605,17,18,19,20,21,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605,605},
{606,606,22,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606,606},
{607,607,607,607,607,607,607,607,607,607,607,607,607,607,23,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,607,24,607,607,607,607,607,607,607},
{608,608,608,25,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608,608},
{609,609,609,609,26,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609,609},
{610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,27,27,27,27,27,27,27,27,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610},
{610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,29,29,29,29,610,28,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610},
{610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,30,30,30,30,30,30,30,30,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610},
{610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,32,32,32,32,31,32,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610},
{610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,33,34,34,34,34,34,34,34,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610},
{610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,35,35,35,35,35,35,35,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610},
{610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,37,37,37,37,37,37,36,36,36,36,36,36,610,610,610,610,610,610,610,610,610,610,610,610,610,610},
{610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,38,38,38,38,38,38,38,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610},
{610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,610,41,41,41,41,41,41,41,41,41,41,41,41,39,40,610,610,610,610,610,610,610,610,610,610,610,610},
{611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,42,42,42,42,42,42,42,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611},
{611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,611,46,46,46,46,46,46,46,46,46,46,46,46,46,46,43,44,45,611,611,611,611,611,611,611,611,611},
{612,612,612,612,612,612,612,612,612,612,612,612,612,612,612,612,47,48,49,50,51,52,53,612,612,612,612,612,612,612,612,612,612,612,612,612,612,612,612,612,612,612,612,612,612,612,612,612,612},
{55,54,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613},
{613,56,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613,613},
{614,614,614,614,614,614,614,614,614,614,614,614,614,614,614,614,614,614,614,614,614,614,614,614,614,614,614,614,614,57,58,59,60,61,62,614,614,614,614,614,614,614,614,614,614,614,614,614,614},
{615,615,615,615,615,615,615,63,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615,615},
{616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,64,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616,616},
{617,617,617,617,617,617,65,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617,617},
{618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,66,66,66,66,66,66,66,66,66,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618},
{618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,68,67,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618,618},
{619,619,619,619,619,69,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619,619},
{620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,70,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620},
{620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,72,71,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620,620}};


static int m[25][33]=
{{1,2,4,501,501,0,0,0,124,2,1,107,108,108,13,10,12,11,16,17,18,19,20,21,122,123,127,129,125,126,130,1,1},
 {1,2,2,3,100,100,100,100,22,2,1,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,100,1,1},
 {2,2,2,3,101,101,101,101,22,2,1,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,101,2,2},
 {2,2,2,501,501,501,501,501,501,2,1,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,501,2,2},
 {102,102,4,102,102,102,102,102,5,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102},
 {502,502,6,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502,502},
 {103,103,6,103,103,103,103,103,103,7,7,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103,103},
 {503,503,9,503,503,503,503,503,503,503,503,8,8,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503,503},
 {504,504,9,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504,504},
 {104,104,9,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104,104},
 {11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,505,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11,11},
 {506,506,506,506,506,506,506,506,506,506,506,506,506,506,506,105,506,506,506,506,506,506,506,506,506,506,506,506,506,506,506,506,506},
 {12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,106,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12,12},
 {110,110,110,110,110,110,110,110,110,110,110,110,110,14,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110,110},
 {14,14,14,14,14,14,14,14,14,14,14,14,14,15,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14},
 {14,14,14,14,14,14,14,14,14,14,14,14,14,15,112,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14,14},
 {507,507,507,507,507,507,507,507,507,507,507,507,507,507,507,507,507,507,113,507,507,507,507,507,507,507,507,507,507,507,507,507,507},
 {508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,508,114,508,508,508,508,508,508,508,508,508,508,508,508,508},
 {115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,115,116,115,115,115,115,115,115,115,115,115,115,115},
 {129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,129,117,129,129,129,129,129,129,129,129,129,129,129},
 {118,118,118,118,118,118,118,118,118,118,118,118,118,118,118,118,118,118,118,118,118,119,118,118,118,118,118,118,118,118,118,118,118},
 {120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,120,121,120,120,120,120,120,120,120,120,120,120,120},
 {509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,23,509},
 {509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,24},
 {509,509,509,509,509,509,509,509,509,509,131,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509,509}};



//aqui ya va el Sintactico


void MainWindow::generarCuadruplo(QString op1,QString op2, QString oper,QString res)
{
ui->tabla->insertRow(ui->tabla->rowCount());
QString num=QString::number(contCuad);
 ui->tabla->setItem(contCuad-1,0,new QTableWidgetItem(num)); //num
  ui->tabla->setItem(contCuad-1,1,new QTableWidgetItem(oper)); //oper
   ui->tabla->setItem(contCuad-1,2,new QTableWidgetItem(op1)); //op1
    ui->tabla->setItem(contCuad-1,3,new QTableWidgetItem(op2)); //op2
    QString r=QString("R%1").arg(contR);
     ui->tabla->setItem(contCuad-1,4,new QTableWidgetItem(r)); //res

     qDebug() << "Esto es r" << r;
     pila_op.push(r);

     pilaTiposid.push_back(r);
     pilaTiposdatok.push_back(res.toInt());
contCuad++; //agregar a la pila el resultado
contR++;
}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
     producciones();
     pila();





}





void pila(){
    pili.push("$");
    pili.push("Prog");

}

void guardaTokens(int edo, std::string valor){
    tokenEdo.append(edo);
    tokenValor.append(valor);
    imprimeTokens();
}

void imprimeTokens(){
  qDebug()<<"****TOKENS HASTA EL MOMENTO*****";
   qDebug()<<"|EDO||Valor|";
//haha
  for(int i=0;i<tokenEdo.size();i++){
      qDebug()<<"|"<<tokenEdo.at(i)<<"|"<<QString::fromStdString(tokenValor.at(i))<<"|";

  }
 qDebug()<<"-------------";

}

MainWindow::~MainWindow()
{
    delete ui;
    //setWindowTitle("Samantha Celis Carrillo");


}

void MainWindow::on_btnAbrir_clicked()
{
    limpiar();
    QString archivo = QFileDialog::getOpenFileName(
                this,"Escoge tu codigo Eyement",QDir::homePath(),"Eyement (*.eye)");
    QFile texto(archivo);


    if(!texto.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::information(this,"Lo siento","No se abrió el archivo");
    }
    QTextStream in(&texto);
    QString textito= in.readAll();
    ui ->txtTexto->setPlainText(textito);
    cadenota=textito.toStdString();

    texto.close();



}

void MainWindow::on_pushButton_2_clicked()
{
    qDebug() <<"boton";
    //agarrar texto de txt
    //QString clipSel2 =  QPlainTextEdit::copy()->text (QPlainTextEdit::copy);
    cadenota =(ui->txtTexto->toPlainText()).toStdString();
    analizaS();


    archi=0;
}

std::string cadena(){
    return cadenota;
}


int relacionC(std::string tip){
    int tipo=std::stoi(tip);
    //gato
    switch(tipo){
    case 100:
        if(elemento=="P.R begin")  {
            return columna.indexOf("begin");}

        else if(elemento=="P.R end")  {
            return columna.indexOf("end");}

        else if(elemento=="P.R def")  {
            return columna.indexOf("def");}

        else if(elemento=="P.R as")  {
            return columna.indexOf("as");}

        else if(elemento=="P.R integer")  {
            return columna.indexOf("integer");}

        else if(elemento=="P.R float")  {
            return columna.indexOf("float");}

        else if(elemento=="P.R char")  {
            return columna.indexOf("char");}

        else if(elemento=="P.R string")  {
            return columna.indexOf("string");}

        else if(elemento=="P.R boolean")  {
            return columna.indexOf("boolean");}

        else if(elemento=="P.R if")  {
            return columna.indexOf("if");}

        else if(elemento=="P.R else")  {
            return columna.indexOf("else");}

        else if(elemento=="P.R elseif")  {
            return columna.indexOf("elseif");}

        else if(elemento=="P.R endif")  {
            return columna.indexOf("endif");}

        else if(elemento=="P.R for")  {
            return columna.indexOf("for");}

        else if(elemento=="P.R do")  {
            return columna.indexOf("do");}

        else if(elemento=="P.R endfor")  {
            return columna.indexOf("endfor");}

        else if(elemento=="P.R while")  {
            return columna.indexOf("while");}

        else if(elemento=="P.R function")  {
            return columna.indexOf("function");}

        else if(elemento=="P.R endfunction")  {
            return columna.indexOf("endfuction");}

        else if(elemento=="P.R import")  {
            return columna.indexOf("import");}

        else if(elemento=="P.R class")  {
            return columna.indexOf("class");}

        else if(elemento=="P.R null")  {
            return columna.indexOf("null");}

        else if(elemento=="P.R read")  {
            return columna.indexOf("read");}

        else if(elemento=="P.R write")  {
            return columna.indexOf("write");}

        else if(elemento=="P.R enter")  {
            return columna.indexOf("enter");}

        else if(elemento=="P.R endwhile")  {
            return columna.indexOf("endwhile");}
//melon
        break;
    case 101:
         return columna.indexOf("id");

    case 102:
         return columna.indexOf("cteEnterta");

    case 103:
         return columna.indexOf("cteReal");

    case 104:
         return columna.indexOf("cteNotacion");

    case 105:
         return columna.indexOf("cteCaracter");

    case 106:
         return columna.indexOf("cteString");

    case 107:
         return columna.indexOf("+");

    case 108:
         return columna.indexOf("-");

    case 109:
         return columna.indexOf("*");

    case 110:
         return columna.indexOf("/");

    case 111:
         return columna.indexOf("%");

    case 112:
         return columna.indexOf("comentario");

    case 113:
         return columna.indexOf("&&");

    case 114:
         return columna.indexOf("||");

    case 115:
         return columna.indexOf("!");

    case 116:
         return columna.indexOf("!=");

    case 117:
         return columna.indexOf("==");

    case 118:
         return columna.indexOf(">");

    case 119:
         return columna.indexOf(">=");

    case 120:
         return columna.indexOf("<");

    case 121:
         return columna.indexOf("<=");

    case 122:
         return columna.indexOf(":");

    case 123:
         return columna.indexOf(";");

    case 124:
         return columna.indexOf(".");

    case 125:
         return columna.indexOf("(");

    case 126:
         return columna.indexOf(")");

    case 127:
         return columna.indexOf("[");

    case 128:
         return columna.indexOf("]");

    case 129:
         return columna.indexOf("=");

    case 130:
         return columna.indexOf(",");

    case 131:
         return columna.indexOf("idLib ");
    case 132:
             return columna.indexOf("$");

      }
}

 int relacionF(std::string tip){
     int tipo=std::stoi(tip);
     //gato
     switch(tipo){
     case 100:
         if(elemento=="P.R begin")  {
             return fila.indexOf("begin");}

         else if(elemento=="P.R end")  {
             return fila.indexOf("end");}

         else if(elemento=="P.R def")  {
             return fila.indexOf("def");}

         else if(elemento=="P.R as")  {
             return fila.indexOf("as");}

         else if(elemento=="P.R integer")  {
             return fila.indexOf("integer");}

         else if(elemento=="P.R float")  {
             return fila.indexOf("float");}

         else if(elemento=="P.R char")  {
             return fila.indexOf("char");}

         else if(elemento=="P.R string")  {
             return fila.indexOf("string");}

         else if(elemento=="P.R boolean")  {
             return fila.indexOf("boolean");}

         else if(elemento=="P.R if")  {
             return fila.indexOf("if");}

         else if(elemento=="P.R else")  {
             return fila.indexOf("else");}

         else if(elemento=="P.R elseIf")  {
             return fila.indexOf("elseIf");}

         else if(elemento=="P.R endif")  {
             return fila.indexOf("endif");}

         else if(elemento=="P.R for")  {
             return fila.indexOf("for");}

         else if(elemento=="P.R do")  {
             return fila.indexOf("do");}

         else if(elemento=="P.R endfor")  {
             return fila.indexOf("endfor");}

         else if(elemento=="P.R while")  {
             return fila.indexOf("while");}

         else if(elemento=="P.R function")  {
             return fila.indexOf("function");}

         else if(elemento=="P.R endfunction")  {
             return fila.indexOf("endfuction");}

         else if(elemento=="P.R import")  {
             return fila.indexOf("import");}

         else if(elemento=="P.R class")  {
             return fila.indexOf("class");}

         else if(elemento=="P.R null")  {
             return fila.indexOf("null");}

         else if(elemento=="P.R read")  {
             return fila.indexOf("read");}

         else if(elemento=="P.R write")  {
             return fila.indexOf("write");}

         else if(elemento=="P.R enter")  {
             return fila.indexOf("enter");}

         else if(elemento=="P.R endwhile")  {
             return fila.indexOf("endwhile");}
 //melon
         break;
     case 101:
          return fila.indexOf("id");

     case 102:
          return fila.indexOf("cteEntera");

     case 103:
          return fila.indexOf("cteReal");

     case 104:
          return fila.indexOf("cteNotacion");

     case 105:
          return fila.indexOf("cteCaracter");

     case 106:
          return fila.indexOf("cteString");

     case 107:
          return fila.indexOf("+");

     case 108:
          return fila.indexOf("-");

     case 109:
          return fila.indexOf("*");

     case 110:
          return fila.indexOf("/");

     case 111:
          return fila.indexOf("%");

     case 112:
          return fila.indexOf("comentario");

     case 113:
          return fila.indexOf("&&");

     case 114:
          return fila.indexOf("||");

     case 115:
          return fila.indexOf("!");

     case 116:
          return fila.indexOf("!=");

     case 117:
          return fila.indexOf("==");

     case 118:
          return fila.indexOf(">");

     case 119:
          return fila.indexOf(">=");

     case 120:
          return fila.indexOf("<");

     case 121:
          return fila.indexOf("<=");

     case 122:
          return fila.indexOf(":");

     case 123:
          return fila.indexOf(";");

     case 124:
          return fila.indexOf(".");

     case 125:
          return fila.indexOf("(");

     case 126:
          return fila.indexOf(")");

     case 127:
          return fila.indexOf("[");

     case 128:
          return fila.indexOf("]");

     case 129:
          return fila.indexOf("=");

     case 130:
          return fila.indexOf(",");

     case 131:
          return fila.indexOf("idLib");
     case 132:
         return fila.indexOf("$");
       }


 }



 void imprime(){
     QStack<std::string> aux=pili;
     QString pilita;
     //miau
     for(int i=0;i<aux.length();i++){
          pilita+="  "+QString::fromStdString(aux.at(i));
     }
     qDebug() <<+"|"+pilita+"|";
 }

 void MainWindow::imprimeSem(){

     ui->txtPilas->appendPlainText("---Vuelta "+QString::number(contadorSem+1)+"---");
     QStack<QString> aux=pila_op;
     QString pilita;
     for(int i=0;i<aux.length();i++){
          pilita+="  "+(aux.at(i));
     }

     qDebug() <<"Pila operando:";
     qDebug() <<+"|"+pilita+"|";
     qDebug()<<pila_op.size();

     ///////////////
     aux=pila_ores;
     QString pilita3;
     for(int i=0;i<aux.length();i++){
          pilita3+="  "+(aux.at(i));
     }
     qDebug() <<"Pila operadores:";
     qDebug() <<+"|"+pilita3+"|";



      qDebug()<<pila_ores.size();
      qDebug() <<"---------------";
     /////////////
    QString pilita4;
      for(int i=0;i<pilaTiposid.size();i++){
           pilita4+="  "+(pilaTiposid.at(i));
      }
      qDebug() <<"Pila tipos id:";
      qDebug() <<+"|"+pilita4+"|";



       qDebug()<<pilaTiposid.size();
       qDebug() <<"---------------";
      /////////////
       /////////////
QString pilita2;
        for(int i=0;i<pilaTiposdatok.size();i++){
             pilita2+="  "+QString::number(pilaTiposdatok.at(i));
        }
        qDebug() <<"Pila tipos dato:";
        qDebug() <<+"|"+pilita2+"|";

         qDebug()<<pilaTiposdatok.size();
         qDebug() <<"---------------";
        /////////////
         ///////////////
         QStack<int>auxa=pila_saltos;
         QString pilita34;
         for(int i=0;i<auxa.length();i++){
              pilita34+="  "+QString::number(auxa.at(i));
         }
         qDebug() <<"Pila saltos:";
         qDebug() <<+"|"+pilita34+"|";

          qDebug()<<pila_saltos.size();
          qDebug() <<"---------------";
         /////////////


           if(pilita.size()!=auxP1 || pilita3.size()!=auxP3 || pilita4.size()!=auxP4 || pilita2.size()!=auxP2 || pilita2.size()!=auxP2){

               ui->txtPilas->appendPlainText("Pila tipos id:");
             ui->txtPilas->appendPlainText("|"+pilita4+"|");
             auxP4=pilita4.size();

              ui->txtPilas->appendPlainText("Pila tipo dato:");
               ui->txtPilas->appendPlainText("|"+pilita2+"|");
               auxP2=pilita2.size();



               ui->txtPilas->appendPlainText("Pila operando:");
               ui->txtPilas->appendPlainText("|"+pilita+"|");
                auxP1=pilita.size();

                 ui->txtPilas->appendPlainText("Pila operadores:");
                        ui->txtPilas->appendPlainText("|"+pilita3+"|");
                        auxP3=pilita3.size();

                        ui->txtPilas->appendPlainText("Pila salto:");
                            ui->txtPilas->appendPlainText("|"+pilita34+"|");
                            auxP5=pilita34.size();

           }
            ui->txtPilas->appendPlainText("////////////////////");

 }

void MainWindow::pilacion(){

    imprime();
    qDebug()<<"{{{{{{{{{{{{{{{TOKEN "<<primera<<"}}}}}}}}}}}}}}}}}}}}}";
    qDebug()<<"Elemento"<<QString::fromStdString(elemento);
    qDebug()<<"Tipo"<<QString::fromStdString(tipo);

    qDebug()<<"Tope de fila"<<  QString::fromStdString(pili.top());
    int fila=numero(QString::fromStdString(pili.pop()));
    qDebug()<<"Fila: "<<fila;
    if(fila<=34){
        qDebug()<<"Es un no terminal";
        int col=relacionC(tipo);
        qDebug()<<"Columna: "<<col;
        int edi=ms[fila][col];
        qDebug()<<"estado: "<<edi;
        if(edi<599){
            edi--;
            //bebe
            qDebug()<<"Numero de producciones: "<<prod.size();
            qDebug()<<"Numero de elementos de la produccion: "<<prod.at(edi).size();
            for (int i=prod.at(edi).size()-1;i>=0;i--) {
                // qDebug()<<"Entro al primer FOR";
                // qDebug()<<"va a meter:" <<prod.at(edi).at(i);
                pili.push((prod.at(edi).at(i)).toStdString());
                //qDebug()<< "Se metio correctamente";
                imprime();
            }
            pilacion();
             qDebug()<<"°°°°°°°°°°°ANALIZADO°°°°°°°°°°°";
            primera++;


        } else {

            qDebug()<<"Es un error";
            QMessageBox msgBox;
            msgBox.setText("Dio un error, jaja: ");
            msgBox.exec();
            limpiar();

        }

    } else {
        qDebug()<<"Es UN terminal";
        if(fila==35){
            qDebug()<<"La produccion tiene un vacio";
             qDebug()<<"°°°°°°°°°°°ANALIZADO°°°°°°°°°°°";
            pilacion();
            primera++;
            imprime();
        }else {
            qDebug()<<"Es momento de saber si es el mismo";
            //ñeñe

            qDebug()<<"El del token: "<<relacionF(tipo);
            qDebug()<<"El de la pila: "<<fila;
            if(relacionF(tipo)==fila){
                if(tipo=="132"){
                    //se acabo
                    QMessageBox msgBox;
                    msgBox.setText("Analisís Sintáctico terminado. No hubo errores");
                    msgBox.exec();
                    ejecutarSemantico();
                    qDebug() << "Termino semantico";
                    qDebug() << pila_errores.size();


                    limpiar();
                } else {
                    qDebug()<<"°°°°°°°°°°°COINCIDIO, ES CORRECTO°°°°°°°°°°°";
                    qDebug()<<"°°°°°°°°°°°ANALIZADO°°°°°°°°°°°";
                    std::string c=elemento;
                    int b = atoi(tipo.c_str());
                    guardaTokens(b,c);

                    dame_token();


                    pausa=false;
                    primera++;

                    pilacion();

                }
            } else{
                qDebug()<<"SE MURIO";
                QMessageBox msgBox;
                msgBox.setText("Dio un error, jaja: ");
                msgBox.exec();
                limpiar();
            }
        }
    }
}



void MainWindow::analizaS(){
    //crear producciones (creo que es mejor en el main)
    analiza(); //este es el lexico (mas bien inicializa cosillas de el)



    dame_token(); //tecnimanete este es el verdadero léxico (porque analiza el codigo y saca los tokens)
    pausa=false;
    //limpiar();
    pilacion();




}

void producciones(){
    QList<QString>	 p1	 = {"DecLib","class","id","begin","Dec","Est","end"};
    QList<QString>	 p2	 = {"EstA",";","Est"};
    QList<QString>	 p3	 = {"vacio"};
    QList<QString>	 p4	 = {"EstAsig"};
    QList<QString>	 p5	 = {"EstIf"};
    QList<QString>	 p6	 = {"EstWhile"};
    QList<QString>	 p7	 = {"EstFor"};
    QList<QString>	 p8	 = {"EstRead"};
    QList<QString>	 p9	 = {"EstWrite"};
    QList<QString>	 p10	 = {"EstEnter"};
    QList<QString>	 p11	 = {"DecA","Dec"};
    QList<QString>	 p12	 = {"vacio"};
    QList<QString>	 p13	 = {"def","DecB","as","Tipo",";"};
    QList<QString>	 p14	 = {"id","DecB'"};
    QList<QString>	 p15	 = {",","DecB"};
    QList<QString>	 p16	 = {"vacio"};
    QList<QString>	 p17	 = {"integer"};
    QList<QString>	 p18	 = {"float"};
    QList<QString>	 p19	 = {"char"};
    QList<QString>	 p20	 = {"string"};
    QList<QString>	 p21	 = {"boolean"};
    QList<QString>	 p22	 = {"if","(","Exp",")","Est","EstIfA","endif"};
    QList<QString>	 p23	 = {"else","Est"};
    QList<QString>	 p24	 = {"vacio"};
    QList<QString>	 p25	 = {"while","(","Exp",")","Est","endwhile"};
    QList<QString>	 p26	 = {"for","(","EstAsig",":","Exp",")","Est","endfor"};
    QList<QString>	 p27	 = {"Exp2","Exp'"};
    QList<QString>	 p28	 = {"||","Exp"};
    QList<QString>	 p29	 = {"vacio"};
    QList<QString>	 p30	 = {"Exp3","Exp2'"};
    QList<QString>	 p31	 = {"&&","Exp2"};
    QList<QString>	 p32	 = {"vacio"};
    QList<QString>	 p33	 = {"!","Exp4"};
    QList<QString>	 p34	 = {"Exp4"};
    QList<QString>	 p35	 = {"Exp5","Exp4'"};
    QList<QString>	 p36	 = {"Opr","Exp5"};
    QList<QString>	 p37	 = {"vacio"};
    QList<QString>	 p38	 = {"Term","Exp5'"};
    QList<QString>	 p39	 = {"+","Exp5"};
    QList<QString>	 p40	 = {"-","Exp5"};
    QList<QString>	 p41	 = {"vacio"};
    QList<QString>	 p42	 = {"Fact","Term'"};
    QList<QString>	 p43	 = {"*","Term"};
    QList<QString>	 p44	 = {"/","Term"};
    QList<QString>	 p45	 = {"%","Term"};
    QList<QString>	 p46	 = {"vacio"};
    QList<QString>	 p47	 = {"id"};
    QList<QString>	 p48	 = {"cteEntera"};
    QList<QString>	 p49	 = {"cteReal"};
    QList<QString>	 p50	 = {"cteNotacion"};
    QList<QString>	 p51	 = {"cteCaracter"};
    QList<QString>	 p52	 = {"cteString"};
    QList<QString>	 p53	 = {"(","Exp",")"};
    QList<QString>	 p54	 = {"DecLibA","DecLib"};
    QList<QString>	 p55	 = {"vacio"};
    QList<QString>	 p56	 = {"import","idLib",";"};
    QList<QString>	 p57	 = {"=="};
    QList<QString>	 p58	 = {"!="};
    QList<QString>	 p59	 = {"<"};
    QList<QString>	 p60	 = {"<="};
    QList<QString>	 p61	 = {">"};
    QList<QString>	 p62	 = {">="};
    QList<QString>	 p63	 = {"enter"};
    QList<QString>	 p64	 = {"id","=","Exp"};
    QList<QString>	 p65	 = {"write","(","EstWriteA",")"};
    QList<QString>	 p66	 = {"Exp","EstWriteA'"};
    QList<QString>	 p67	 = {",","EstWriteA"};
    QList<QString>	 p68	 = {"vacio"};
    QList<QString>	 p69	 = {"read","(","EstReadA",")"};
    QList<QString>	 p70	 = {"id","EstReadA'"};
    QList<QString>	 p71	 = {",","EstReadA"};
    QList<QString>	 p72	 = {"vacio"};

    prod.append(	p1	); prod.append(	p2	);
    prod.append(	p3	);prod.append(	p4	);
    prod.append(	p5	);prod.append(	p6	);
    prod.append(	p7	);
    prod.append(	p8	);prod.append(	p9	);
    prod.append(	p10	);prod.append(	p11	);
    prod.append(	p12	);prod.append(	p13	);
    prod.append(	p14	);prod.append(	p15	);
    prod.append(	p16	);prod.append(	p17	);
    prod.append(	p18	);prod.append(	p19	);
    prod.append(	p20	);prod.append(	p21	);
    prod.append(	p22	);prod.append(	p23	);
    prod.append(	p24	);prod.append(	p25	);
    prod.append(	p26	);prod.append(	p27	);
    prod.append(	p28	);prod.append(	p29	);
    prod.append(	p30	);prod.append(	p31	);
    prod.append(	p32	);prod.append(	p33	);
    prod.append(	p34	);prod.append(	p35	);
    prod.append(	p36	);prod.append(	p37	);
    prod.append(	p38	);prod.append(	p39	);
    prod.append(	p40	);prod.append(	p41	);
    prod.append(	p42	);prod.append(	p43	);
    prod.append(	p44	);prod.append(	p45	);
    prod.append(	p46	);prod.append(	p47	);
    prod.append(	p48	);prod.append(	p49	);
    prod.append(	p50	);prod.append(	p51	);
    prod.append(	p52	);prod.append(	p53	);
    prod.append(	p54	);prod.append(	p55	);
    prod.append(	p56	);prod.append(	p57	);
    prod.append(	p58	);prod.append(	p59	);
    prod.append(	p60	);prod.append(	p61	);
    prod.append(	p62	);prod.append(	p63	);
    prod.append(	p64	);prod.append(	p65	);
    prod.append(	p66	);prod.append(	p67	);
    prod.append(	p68	);prod.append(	p69	);
    prod.append(	p70	);prod.append(	p71	);
    prod.append(	p72	);


}

void MainWindow::dame_token(){
    cadenita=cadenota;
    qDebug()<<"%%%%%%%%%%%%%%%%%%%%%Pausa1: "<<pausa<<endl;

    //qDebug()<<"************Tamaño de cadena antes del while:"<<cadenita.length()<<endl;
    bool check= pasada<cadenita.length();
   // qDebug()<<"Pasada: "<<pasada<<endl;
    //qDebug()<<"La Pasada es menor?: "<<check<<endl;

      if(pasada>=cadenita.length() && pausa==false){
         qDebug()<<"YA ES EL FINALLLLL Y ENTRO EXITOSAMENTE 8888888888888888888888888888888888";
          tipo="132";
         elemento="$";
     }

    while(pasada<cadenita.length() && pausa==false ){
       // qDebug()<<"ENTRO AL CLICLO PRINCIPAL";
        qDebug()<<"%%%%%%%%%%%%%%%%%%%%%Pausa dentro: "<<pausa<<endl;
        int dentro=0;
        bool check=pasada<=cadenita.length();
       // qDebug()<<"Pasada: "<<pasada<<endl;
       // qDebug()<<"La Pasada es mayor?: "<<check<<endl;
        //qDebug()<<"Pausa dentro: "<<pausa<<endl;

        edo=0;
        //qDebug()<<"Edo inicial antes de nuevo while: "<<edo<<endl;

        while(edo<=32 || car!='\0'){

            //qDebug()<<"=============Dentro del while: "<<dentro<<endl;
            dentro++;

            col=Relaciona(car);
           // qDebug()<<"Colmuna: "<<col<<endl;
            edo=m[edo][col];
           // qDebug() <<"edo!!!!!: "<< edo << endl;

            if(car!=' ' && car!='\n' && car!='\t' && edo!=102
                    && edo!=100 && edo!=101 && edo!=103
                    && edo!=104 && edo!=110 && edo!=115
                    && edo!=129 && edo!=118 && edo!=120){
                token+=car;
            }
            else if(edo==12){
                token+=car;
            }

            //}
            if(car!='\0')
                if(edo==102 || edo==100 || edo==101
                        || edo==103 || edo==104|| edo==110
                        || edo==115 || edo==129 || edo==118
                        || edo==120){
                    pasada--;
                }


            car=leerCaracter();
           // qDebug() <<"caracter agarrado: '"<<car<<"'"<<endl;
            if(edo>29)
                break;

            if(pasada>=cadenita.length() && edo==12){
                break;


            }


        }
        if(edo>=100 && edo<=199){
            cheki();
            if(edo==100){
                bool si=checarPV(token);
                bool memato=QString::fromStdString(token)=="endif";
                qDebug()<<"########PERROOROROROR:"<<memato;
                if(token=="endif"){si=1;}
                if(si==0){
                    edo=101;}
                else {
                    token="P.R " + token;
                }
            }

           // qDebug() <<"$$$$$Token: "<<QString::fromStdString(token) << endl;
            ui->txtTokens->appendPlainText(QString::fromStdString(token)+" -> ");
            elemento=token;
            token="";
            Token(edo);
        }
        else{
            if(edo!=12){
               // qDebug() <<"xxxxxxxxxError: "<<QString::fromStdString(token) << endl;
                ui->txtErrores->appendPlainText(QString::fromStdString(token)+" ");
                token="";
                Error(edo);
            }
        }


        //qDebug()<<"Pasada: "<<pasada<<", largo: "<<cadenita.length()<<endl;
        bool mayor=((unsigned)pasada>=cadenita.length());
        //qDebug()<<"Pasada >=largo="<<mayor<<endl;
        if(pasada>=cadenita.length()){

            qDebug()<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
            qDebug()<<"%%%%%%%%%%%%%%%%%%%%%%%%%FIN%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
             ultimo=true;
//veve

            break;

        }

    } //fin de while

}

void cheki(){
    bool mamon=token=="endif";
    qDebug()<<"Me voy a matar;"<<mamon;
    qDebug()<<QString::fromStdString(token)<<"="<<"endif";
    if(mamon){
        edo=100;
    }
    if(token=="endfor"){
        edo=100;
    }
}

void MainWindow::analiza(){
    qDebug() <<"Entro a analizar"<<endl;
    if(cadenota!=" "){
        ui->txtErrores->clear();
        ui->txtTokens->clear();



        edo=0;
        car=leerCaracter();
        qDebug() <<"caracter agarrado: '"<<car<<"'"<<endl;
        qDebug() <<"edo inicial: "<<edo<<endl;


        qDebug()<<"************Tamaño de cadena:"<<cadenita.length()<<endl;




        // limpiar();
    }

    else {

        //mensaje de error
        QMessageBox::information(this,"Error","No se abrió el archivo");
    }
}

int numero(QString p){
    return fila.indexOf(p);

}
bool checarPV(std::string token){

    if(        token=="class"
            || token=="begin"
            || token=="end"
            || token=="def"
            || token=="as"
            || token== "integer"
            || token== "float"
            || token=="char"
            || token== "string"
            || token== "boolean"
            || token== "if"
            || token=="else"
            || token== "elseIf"
            || token== "endif"
            || token== "for"
            || token== "do"
            || token== "endfor"
            || token== "while"
            || token== "endwhile"
            || token== "function"
            || token== "endFunction"
            || token== "import"
            || token== "null"
            || token== "read"
            || token== "write"
            || token== "enter"){
        return 1;
    } else return 0;

}

char leerCaracter(){
   // qDebug()<<"Entro a leer caracter";
    // 1.2
    //pasada=0
    if(cont==0){
        cadenita=cadena();
        //qDebug()<<"************Tamaño de cadena:"<<cadenita.length()<<endl;
        cont++;
        //qDebug() <<"pasada"<<pasada;
       // qDebug() <<"Caracter a punto de mandar: "<<cadenita[pasada]<<endl;
        return cadenita[pasada];

    } else{
        pasada++;
        //qDebug()<<"************Tamaño de cadena:"<<cadenita.length()<<endl;
       // qDebug() <<"pasada"<<pasada;
       // qDebug() <<"Caracter a punto de mandar: "<<cadenita[pasada]<<endl;
        return cadenita[pasada];

    }

}

//return '1';

void limpiar(){
    pasada=0;
    cadenita="";
    cadenota="";
    cont=0;
    token="";

    tokenValor.clear();
   tokenEdo.clear();

    while (!pili.isEmpty()){
        qDebug() <<QString::fromStdString(pili.pop());
    }
    pila();
    ultimo=false;
    primera=1;
 }

int Relaciona (char c){
    if(c>='a' && c<='z' && c!='e' && c!='l'&& c!='y' )
        return 0;
    if(c>='A' && c<='Z' && c!='E')
        return 1;
    
    if(c>='0' && c<='9')
        return 2;
    
    switch(c){
    case '_': return 3;
    case ' ':return 5;
    case '\n':return 6 ;
    case '\t':return 7;
    case '.': return 8;
    case 'E':return 9;
    case 'e':return 10;
    case '+':return 11;
    case '-':return 12;
    case '*':return 13;
    case '/':return 14;
    case '\'':return 15;
    case '"':return 16;
    case '%':return 17;
    case '&':return 18;
    case '|':return 19;
    case '!':return 20;
    case '=':return 21;
    case '>':return 22;
    case '<':return 23;
    case ':':return 24;
    case ';':return 25;
    case '[':return 26;
    case ']':return 27;
    case '(':return 28;
    case ')':return 29;
    case ',':return 30;
    case 'l':return 31;
    case 'y':return 32;
    default: return 4; // desigual
    }

}

void MainWindow::Token(int e){
    //tipo="perro";
    qDebug()<<"Edo que recibió:"<<e<<endl;
    QString p;
    switch(e){

    //Estos edos se logran por el desigual
    case 100: p="Es una palabra reservada";break;
    case 101: p="Es un identificador";break;
    case 102: p="Es una costante entera"; break;
    case 103: p="Es una costante real" ; break;
    case 104: p="Es una costante de notación científica";  break;
    case 110:p="Caracter de división";  break;
    case 115:p="operador not";  break;
    case 129:p="Operador Asignación";  break;
    case 118:p="operador mayor que";  break;
    case 120:p="operador menor que";  break;

        //////
    case 105:p="Es una costante de caracter";  break;
    case 106:p="Es una costante de String";  break;
    case 107:p="Caracter de suma";  break;
    case 108:p="Caracter de Resta";  break;
    case 109:p="Caracter de multiplicación";  break;
    case 111:p="Caracter de módulo";  break;
    case 112:p="Es un Comentario";  break;
    case 113:p="Operador and";  break;
    case 114:p="Operador or";  break;
    case 116:p="Operador diferente";  break;
    case 117:p="Operador igual";  break;
    case 119:p="operador mayor igual que";  break;
    case 121:p="operador menor igual que";  break;
    case 122:p="dos puntos";  break;
    case 123:p="punto y coma";  break;
    case 124:p="punto";  break;
    case 125:p="Abertura de parentesis";  break;
    case 126:p="Cerradura de parentesis";  break;
    case 127:p="Abertura de corchete";  break;
    case 128:p="Cerradura de corchete";  break;
    case 130:p="coma"; break;
    case 131:p="libreria"; break;
  //case 132:P="Fin"; break;


    }
    tipo=to_string(e);
    ui->txtTokens->insertPlainText(p);
    pausa=true;
    //  ui->txtTokens->appendPlainText(QString::fromStdString(token)+" -> ");
}

void MainWindow::Error(int e){
    qDebug()<<endl<<"###";
    QString p;
    switch(e){
    case 501:  p="Error 501, No es un identificador ni palabra reservada"; break;
    case 500:  p="Error 500, Caracter no identificado"; break;
    case 502:  p="Error 502, Esperaba digito despues de \". \" " ;  break;
    case 503:  p="Error 503, Esperaba digito, +, -" ;  break;
    case 504:  p="Error 504, Esperaba un digito despues de un + o -" ;  break;
    case 505:  p="Error 505, Esperaba un caracter diferente a la misma apóstrofe" ;  break;
    case 506:  p="Error 506, Esperaba un apóstrofe para encapsular caracter" ;  break;
    case 507:  p="Error 507, Esperaba otro &" ;  break;
    case 508:  p="Error 508, Esperaba otro |" ;  break;
    case 509:  p="Error 509, se esperaba  completar la libreria \".lye \"" ; break;


    }
    ui->txtErrores->insertPlainText(p);
}

void MainWindow::on_btnAbrir_2_clicked()
{

    QString archivoNuevo = QFileDialog::getSaveFileName(this, tr("Guardar código Eyement"), QDir::homePath(),tr("Eyement (*.eye)"));
    if (archivoNuevo != "") {
        QFile archivin(QFileInfo(archivoNuevo).absoluteFilePath());
        //esta cosa obtiene info del archivo, se verifica que se cree

        if (archivin.exists())
        {
            QMessageBox::StandardButton op
                    = QMessageBox::warning(this, tr("Archivo existente"), tr("¿Desea sobreescribir?"),
                                           QMessageBox::Ok | QMessageBox::No,
                                           QMessageBox::Cancel);
            if (op != QMessageBox::Ok){
                return; //no hace nada
            }
        }
        if (!archivin.open(QIODevice::WriteOnly))
        {
            QMessageBox::critical(this, tr("Error"), tr("No se logró guardar"));
            return; //nada
        }
        //listo
        QString texto = ui->txtTexto2->toPlainText();
        QTextStream out(&archivin);
        out << texto;
        archivin.close();
    }

}


void MainWindow::on_pushButton_3_clicked()
{
    qDebug() <<"boton";
    //agarrar texto de txt
    //QString clipSel2 =  QPlainTextEdit::copy()->text (QPlainTextEdit::copy);
    cadenota =(ui->txtTexto2->toPlainText()).toStdString();
    analizaS();


    archi=0;
}



void MainWindow::on_pushButton_clicked()
{

    qDebug() << pilaTiposid.size();
}
