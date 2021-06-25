#include <iostream>
#include <stdio.h>
#include <fstream> //Libreria para lectura y escritura en archivos
#include <sstream> //Libreria para lectura y asignacion a variables de datos de archivos
#include <cstring>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

using namespace std;
/* 
El nombramiento de las funciones y de las variables se hará con el formato 
camelCase especificamente con lowerCamelCase y en español
*/

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
            cout << i << endl;
            cout << Ventas[i].created << endl;
            cout << Ventas[i].ventasTotales << endl;}
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