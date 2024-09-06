#include "gacha.hpp"
#include <stdlib.h>

const char SALTO_SIMPLE = '1';
const char DIEZ_SALTOS = '2';
const char SALTO_MULTIPLE = '3';
const char REGISTRO = '4';
const char SALIR = '5';


class menu{

    private:
    
    vector<salto> saltos;
    salto salto_generado;
    gacha jugada;

    char opcion_elegida;
    size_t cantidad_saltos;

    //Pre: -
    //Post: Imprime por pantalla las opciones del programa.
    void mostrar_opciones();

    //Pre:  -
    //Post:Muestra todos los saltos realizados durante la ejecución del programa.
    void mostrar_saltos(vector<salto> vector);

    //Pre: -
    //Post: Genera un salto simple haciendo uso de la clase gacha.   
    void opcion_salto_simple();

    //Pre: -
    //Post: Genera diez saltos haciendo uso de la clase gacha.
    void opcion_diez_saltos();

    //Pre:  -
    //Post: Genera la cantidad de saltos que el usuario desee haciendo uso de la clase gacha.
    void opcion_salto_multiple();

    //Pre: -
    //Post: Añade al archivo registro_saltos.csv todos los saltos generados durante la ejecución si así lo deseara el usuario.
    void opcion_registro();

    //Pre:-
    //Post:Muestra un mensaje de salida.
    void salir();

    public:

    //Constructor
    menu();

    //Pre: -
    //Post:Saluda al usuario cuando ejecuta por primera vez el programa.
    void dar_bienvenida();

    //Pre: -
    //Post: Muestra las opciones disponibles y las da a elegir al usuario.
    void pedir_opcion();

    //Pre: -
    //Post: devuelve la opción elegida durante la ejecución del menú.
    char opcion();

};