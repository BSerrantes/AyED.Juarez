#include "armamento_artefactos.hpp"
#include "combate_multiple.hpp"
#include <iostream>
#include <string>


const char AGREGAR_ARTEFACTO = '0';
const char MOSTRAR_ACTUAL = '1';
const char MOSTRAR_SIGUIENTE = '2';
const char MOSTRAR_ANTERIOR = '3';
const char MOSTRAR_TODOS = '4';
const char QUITAR_ARTEFACTO = '5';
const char EXPORTAR_ARMAMENTO  = '6';
const char IMPORTAR_ARMAMENTO = '7';
const char AGREGAR_COMBATE = '8';
const char PELEAR = '9';
const char SALIR_MINUS = 's';
const char SALIR_MAYUS = 'S';

class menu{
    private:


    armamento_artefactos armamento_nuevo;

    combate_multiple combates;

    artefacto artefacto_generado;

    combate combate_generado;

    char opcion_elegida;

    //Pre: Necesita de dos cotas, una inferior y una superior.
    //Post: Devuelve un numero entero que va a estar entre las dos cotas dadas.
    int rand_int_gen(int cota_inf, int cota_sup);

    //Pre:-
    //Post: Devuelve el tipo de artefacto según un número generado aleatoriamente.
    tipo generar_tipo();

    //Pre: -
    //Post: Devuelve la rareza del artefacto según un número generado aleatoriamente. 
    rareza generar_rareza();

    //Pre: -
    //Post: Devuelve aleatoriamente el set al que pertenece el artefacto.
    std::string generar_set();

    //Pre: -
    //Post: Devuelve aleatoriamente una descripción de un combate.
    std::string gen_descripcion_combate();

    //Pre:
    //Post: Imprime por pantalla las opciones del programa.
    void mostrar_opciones();

    //Pre:
    //Post: Muestra un mensaje de salida por pantalla.
    void salir();
    
    public:

    //Constructor
    menu();

    //Pre: -
    //Post: Saluda al usuario cuando ejecuta por primera vez el programa.
    void dar_bienvenida();

    //Pre: -
    //Post: Muestra todas las opciones disponibles y las da a elegir al usuario.
    void pedir_opcion();

    //Pre: -
    //Post: Devuelve la opción que elegida durante la ejecución del menú. 
    char opcion();
    
};


