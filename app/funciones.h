#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

using namespace std;

//Definicion del struct
struct Datos {
    string created;
    float ventasTotales = 0;
};

typedef Datos Ventas[20000];

//Funciones compartidas
void mostrarIntegrantes();
void leerArchivo(Datos Ventas []);
void mostrarStruct(Datos Ventas []);
void regresionLineal(Datos Ventas[]);
void exponencial(Datos Ventas[]);
void suavizacionExponencial(Datos Ventas[]);

#endif //APP_FUNCIONES_H