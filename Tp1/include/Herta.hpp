#ifndef TP1_1C2024_HERTA_HPP
#define TP1_1C2024_HERTA_HPP

#include <string>
#include <random>
#include <iostream>

const int TOPE_PACIENCIA = 5;

class Herta{
    private:
    
        int paciencia;
        int rand_num;

        //Pre: Debe recibir dos numeros enteros, la cota inferior y la cota superior.
        //Post: Devuelve un nuevo número entero que va a estar entre las dos cotas dadas.
        int rand_machine(int cota_inf, int cota_sup);

        //Pre: Debe recibir un texto cualquiera.
        //Post: Devuelve el mismo texto pero convertido todo a minúscula.
        std::string convertir_msj(std::string mensaje_nuevo);

        //Pre: Debe recibir un mensaje que ya haya sido convertido a minúsculas.
        //Post: Muestra por pantalla una respuesta según el mensaje ingresado.
        void asignar_respuesta(std::string mensaje_adaptado);

    public:
        //Constructor
        Herta();

        //Pre: Debe recibir un mensaje del usuario.
        //Post: Muestra por pantalla una respuesta al mensaje recibido.
        void responder(std::string mensaje);
};


#endif