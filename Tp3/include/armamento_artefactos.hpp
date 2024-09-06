#ifndef AYED_TP3_1C2024_ARMAMENTO_ARTEFACTOS_HPP
#define AYED_TP3_1C2024_ARMAMENTO_ARTEFACTOS_HPP

#include "lista_circular.hpp"
#include "artefacto.hpp"
#include <fstream>
#include <random>

const size_t MAX_ARTEFACTOS = 6;

class armamento_artefactos {
    private:

    lista_circular<artefacto> armamento;
    std::string nombre_armamento;
    std::string armamento_importado;
    std::string UUID = "18122022";
    artefacto artefacto_importado;

    //Pre: La lista de artefactos (armamento) 
    //Post: Comprueba si el artefacto nuevo ya está en la lista o no.
    bool esta_en_armamento(artefacto artefacto_a_agregar);

    //Pre: Necesita de dos cotas, una inferior y una superior.
    //Post: Devuelve un numero entero que va a estar entre las dos cotas dadas.
    int rand_int_gen(int cota_inf, int cota_sup);

    //Pre: -
    //Post: Avanza el cursor del armamento una cantidad aleatoria de veces.
    void avances_aleatorios();

    //Pre: Recibe un entero que ya está validado por venir en un archivo con datos válidos.
    //Post: Devuelve la rareza del artefacto según el número recibido.
    rareza asignar_rareza_artefacto(int dato);

    //Pre: Recibe un entero que ya está validado por venir en un archivo con datos válidos.
    //Post: Devuelve el tipo del artefacto según el número recibido.
    tipo asignar_tipo_artefacto(int dato);

    public:

    //Constructor
    armamento_artefactos();
    
    //Sobrecarga del constructor que va a recibir una ruta de un archivo *.csv
    armamento_artefactos(std::string path_archivo);

    //Pre:No se podrá agregar un artefacto que ya esté en el armamento ni superar los 6 artefactos.
    //Post:Agrega un artefacto al armamento.
    void agregar_artefacto(artefacto artefacto_a_agregar);

    //Pre: Debe haber al menos un artefacto en el armamento.
    //Post: Muestra el artefacto actual por pantalla.
    void mostrar_artefacto_actual();

    //Pre: Debe haber al menos un artefacto en el armamento.
    //Post: Muestra el artefacto siguiente al acutal por pantalla.
    void mostrar_artefacto_siguiente();

    //Pre: Debe haber al menos un artefacto en el armamento.Debe haber al menos un artefacto en el armamento.
    //Post: Muestra el artefacto anterior al actual por pantalla.
    void mostrar_artefacto_anterior();

    //Pre: Debe haber al menos un artefacto en el armamento.
    //Post: Muestra todos los artefactos por pantalla.
    void mostrar_artefactos();

    //Pre: Debe haber al menos un artefacto en el armamento.
    //Post: Elimina el artefacto actual del armamento.
    void quitar_artefacto();

    //Pre: Debe haber al menos un artefacto en el armamento.
    //Post: Guarda el armamento en un archivo UUID-NOMBRE_ARMAMENTO.csv
    void exportar_armamento();

    //Pre: No debe haber artefactos en el armamento actual.
    //Post: Toma la lista de artefactos de un archivo ingresado y crea un armamento con esos artefactos.
    void importar_armamento();

};

#endif