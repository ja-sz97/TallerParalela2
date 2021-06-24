#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

using namespace std;

struct Datos {
    string created;
    int ventasTotales;
};

typedef Datos Ventas[20000];


void leerArchivo(Datos Ventas []);


#endif //APP_FUNCIONES_H