#ifndef AYED_TP2_1C2024_GACHA_HPP
#define AYED_TP2_1C2024_GACHA_HPP

#include "salto.hpp"
#include "vector.hpp"
#include "gestor_archivos.hpp"

const int MAX_RAREZAS = 3;
const int SALTO_3_ESTRELLAS = 18;
const int SALTO_4_ESTRELLAS = 12;
const int SALTO_5_ESTRELLAS = 9;

class gacha {

private:

    //Los numeros ganadores van por orden de probabilidad de aparición de menor a mayor.
    int nros_ganadores[MAX_RAREZAS] = {SALTO_5_ESTRELLAS,SALTO_4_ESTRELLAS,SALTO_3_ESTRELLAS};
    double probabilidades[MAX_RAREZAS] = {0.01, 0.1, 0.89 };
    double proba_acumulada[MAX_RAREZAS] = {0.01 , 0.11, 1};
    int cant_saltos_4_estrellas;
    int cant_saltos_5_estrellas;

    salto salto_generado;
    vector<salto> saltos;
    gestor_archivos gestor;

    //Pre: Necesita de dos cotas enteras, la primera es la inferior y la segunda es la superior.
    //Post: Devuelve un numero real con decimales que va a estar entre las dos cotas recibidas.
    double rand_double_gen(int cota_inferior, int cota_superior);

    //Pre: el vector debe estar cargado y debe ser de tipo double, al igual que el dato.
    //Post: devuelve la posición del primer elemento en el vector que sea mayor al dato.
    int buscar_indice_ganador(double vector[MAX_RAREZAS],int tope, double dato);

    //Pre: Deber recibir un vector cargado, su tope y el índice del elemento a encontrar. Con indice < tope.
    //Post: Devuelve un elemento del vector según su índice
    int buscar_ganador(int vector[MAX_RAREZAS], int tope, int indice);

public:
    gacha();

    //Pre: -
    //Post: Genera y devuelve un salto en base al sistema de Pity.
    salto generar_salto();

    //Pre: -
    //Post: Genera y devuelve diez saltos dentro de un vector. Equivale a  ejecutar generar_salto() diez veces.
    vector<salto> generar_salto_multiple();

    //Pre: -
    //Post: Genera y devuelve cantidad de saltos dentro de un vector. Equivale a ejecutar generar_salto() cantidad de veces.
    vector<salto> generar_salto_multiple(size_t cantidad);

    //Pre: -
    //Post: Guarda a modo de registro, la información de todos los saltos generados en un archivo registro_saltos.csv, donde cada línea es un salto.
    void exportar_saltos();
};

#endif