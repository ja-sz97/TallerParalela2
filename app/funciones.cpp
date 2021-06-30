#include <iostream>
#include <stdio.h>
#include <fstream> //Libreria para lectura y escritura en archivos
#include <sstream> //Libreria para lectura y asignacion a variables de datos de archivos
#include <cstring>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include <cmath>
#include <math.h>
using namespace std;
/* 
El nombramiento de las funciones y de las variables se hará con el formato 
camelCase especificamente con lowerCamelCase y en español
*/


// Esta funcion resuelve un sistema de ecuacion 2x2
void resolverSistema(float m[][3]){
      cout << "dato [0][0]: " << m[0][0] << " dato [0][1]: " << m[0][1]<< " dato [0][2]: " << m[0][2]<< " dato [1][0]: " << m[1][0]<< " dato [1][1]: " << m[1][1]<< " dato [1][2]: " << m[1][2] << endl;

     float x,y;
     int i,ii,j;
      for(i=0;i<2;i++)
      {
          for (ii=0;ii<2;ii++)
          {
               if (ii!=i)
               {
                x = - m[i][i];
                y=  m[ii][i];
                for (j=0;j<2+1;j++)
                    m[ii][j]=m[ii][j]/y*x+m[i][j];
                }
          }
      }
      //cout << "dato [0][0]: " << m[0][0] << " dato [0][1]: " << m[0][1]<< " dato [0][2]: " << m[0][2]<< " dato [1][0]: " << m[1][0]<< " dato [1][1]: " << m[1][1]<< " dato [1][2]: " << m[1][2] << endl;

}
void exponencial(Datos Ventas[]){
    // Ecuacion exponencial de la forma Y=AB^(KX) / aplicar logaritmo
    // Quedando Logb (y) = KX + Logb (A)
    // Reemplazando V = KX + L 
    // Ecuacion 1 -> Sumatoria V = K*Sumatoria X + N*L
    float Sv=0; // Sumatoria del logaritmo natural de la variable "y" (SUMATORIA V)
    int Sx=0; // Sumatoria de los periodos (VARIABLE K) 
    int Sl=0; // Sumatoria de la cantidad de datos (VARIABLE L)
    // Ecuacion 2 
    float Sxv=0; // Sumatoria de los valores de x*v
    float Sxx=0; // Sumatoria de los periodos^2 (VARIABLE K)
    float Slx=0; // Sumatoria de la cantidad de datos * los periodos (VARIABLE L)
    float matriz[2][3];
    //Resultados
    float K=0; // Valor K de la ecuacion original
    float L=0; // Valor L -> L=Ln(A)
    float A=0; // Valor A de la ecuacion original
    //Variables
    float Euler = 2.71828;

    for (int i=1; i<200; i++){
        //Ecuacion 1
        Sv += log(Ventas[i-1].ventasTotales);
        Sx += i;
        Sl++;
    }   
    matriz[0][0]=Sx;
    matriz[0][1]=Sl;
    matriz[0][2]=Sv;
    for (int i=1; i<200; i++){
        //Ecuacion 2
        Sxv += i * log(Ventas[i-1].ventasTotales);
        Sxx += i * i; 
        Slx += i;
    }   
    matriz[1][0]=Sxx;
    matriz[1][1]=Slx;
    matriz[1][2]=Sxv;
    cout << "Sv : " << Sv << " Sx : " << Sx << " Sl : " << Sl << " Sxv: " << Sxv << " Sxx : " << Sxx << " Slx : "<< Slx << endl;

    //Se obtiene ahora las variables K Y L

    resolverSistema(matriz);
    K = matriz[0][2]/matriz[0][0];
    L = matriz[1][2]/matriz[1][1];


    cout << "Valor de K: "<< K << " Valor de L: "<< L <<  endl;

    // Se obtiene el valor de A
    A = pow(Euler,L);

    cout << "Ecuacion exponencial: Y=" << A << "^(" << K << "X)" << endl;  


}


void regresionLineal(Datos Ventas[]){
    float promedioPeriodos = 0;
    float promedioVentas = 0;
    int i=1;
    float pendiente; //b
    float Sxy = 0; //sumatoria de periodos*ventas
    float Sx = 0; //sumatoria de periodos
    float Sy = 0; //sumatoria de ventas
    float Sxx = 0; //sumatoria de periodos^2
    float alfa = 0; //a
    while(Ventas[i-1].created !=""){
        Sx += i;
        Sy += Ventas[i-1].ventasTotales;
        
        i++;
    }
    promedioPeriodos = Sx / (i-1);
    promedioVentas = Sy/ (i-1);
    for (int j = 1; j<200 ; j++ ){
        //Sxy += ((i)*promedioPeriodos) * (Ventas[i-1].ventasTotales * promedioVentas);
        //Sxx += ((i)*promedioPeriodos)*((i)*promedioPeriodos);
        Sxy += j * Ventas[j-1].ventasTotales;
        Sxx += j*j;
    } 
    pendiente = (((i-1)*Sxy) - (Sx*Sy)) / (((i-1)*Sxx) - (Sx*Sx));
    alfa = promedioVentas - (pendiente * promedioPeriodos);
    //cout<< "pendiente : "<<pendiente<<endl;
    //cout<<"alfa : "<<alfa<<endl; 
    //cout << " Ventas = "<< alfa <<" + "<<pendiente<<"Periodo"<<endl;
    }


/*
Función que retorna un string normalizado de las variables, removiendo caracteres no deseados
*/
string normalizar(string palabra)
{

    //Variables
    char caracterIndeseado[] = {'"'};
    string palabranueva;
    int aux = palabra.length();

    for (int i = 0; i < aux; i++)
    {
        if (palabra[i] != caracterIndeseado[0])
        {
            palabranueva += palabra[i];
        }
    }
    return palabranueva;
}

string separarFecha(string created)
{   
    
    string fecha;

    for (int i = 0; i <= 10; i++)
    {
        fecha += created[i];

        if (created[i] == ' ')
        {
            i=10;
        }
    }
    return fecha;
}

void rellenarStruct(Datos Ventas[], string fecha){
    for(int i=0; i<20000 ; i++){
    if(Ventas[i].created == ""){
        Ventas[i].created = fecha;
        Ventas[i].ventasTotales += 1;
        i = 20000;
    }
    else{
        if(Ventas[i].created == fecha){
            Ventas[i].ventasTotales += 1 ;
            i = 20000;
        }
    }
    }
}

void mostrarStruct(Datos Ventas[]){
    for(int i= 0 ; i<20000; i++){
        if(Ventas[i].created!=""){
            cout << "dia : "<< i+1 << endl;
            cout << "fecha : "<< Ventas[i].created << endl;
            cout << "ventas : "<<Ventas[i].ventasTotales << endl;}
    }
}

/*
Funcion para leer el archivo .csv mediante el us2020-10-14o de librería ifstream.
Se asignan los valores obtenidos a los atributos de la clase Persona()
*/
void leerArchivo(Datos Ventas[])
{
    //Declaracion de variables
    ifstream archivo;
    string linea, hora, created, fecha, name, _sku, _quantity, _amount;
    int sku, quantity, amount;

    //Abrir archivo .csv con permiso de lectura
    archivo.open("datos.csv", ios::in);
    if (archivo.fail())
    {
        cout << "error al intentar leer el archivo" << endl;
        exit(1);
    }
    while (!archivo.eof())
    {
        int i = 1;
        while (getline(archivo, linea))
        {   
            if(i >1  ){
            //Lectura linea por linea, separando por ";" y asignando a variables
            stringstream stream(linea);
            getline(stream, created, ';');
            getline(stream, _sku, ';');
            getline(stream, _quantity, ';');
            getline(stream, _amount, ';');
            getline(stream, name, ';');

            //Normalizar las variables para quitar formato con comillas
            created = normalizar(created);
            fecha =  separarFecha(created);
            rellenarStruct(Ventas,fecha);

            _sku = normalizar(_sku);
            _quantity = normalizar(_quantity);
            _amount = normalizar(_amount);
            name = normalizar(name);

            //Cambiamos el tipo de variable de los datos, de string a int o floar
            sku = atoi(_sku.c_str());
            quantity = atoi(_quantity.c_str());
            amount = atoi(_amount.c_str());}

            i++;
        }
    }
    archivo.close();
}