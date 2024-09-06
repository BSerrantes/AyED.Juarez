#ifndef AYED_TP3_1C2024_COMBATE_MULTIPLE_HPP
#define AYED_TP3_1C2024_COMBATE_MULTIPLE_HPP

#include "combate.hpp"
#include "cola.hpp"

const int MAX_COMBATES = 6;

class combate_multiple {
    private:

    cola<combate> combates;

    size_t total_combates;

    //Pre: -
    //Post: Resuelve recursivamente los combates pendientes, y devuelve la cantidad total de poder de trazacamino gastado. Si ya no quedan combates ,devuelve cero.
    // Es de tipo de recursividad es de cola ya que el llamado a si misma es al final de la función y no se realiza otra operación más que sumar su resultado al poder_gastado del combate realizado.
    // Su modo de invocación es directa porque llamo a la función dentro de si misma.
    // Y es simple porque la llamo una sola vez.
    size_t pelear_recursivo();

    public:

    //constructor
    combate_multiple();

    //Pre: Debe recibir un combate.
    //Post: Si en la lista  hay menos de 6 combates se agrega el combate al final de la lista.
    void agregar_combate(combate combate_a_agregar);

    //Pre: -
    //Post: Resuelve los combates agregados a la cola, y devuelve la cantidad total de poder de trazacamino gastado. Si ya no quedan combates, devuelve cero. 
    size_t pelear();

    //Pre: -
    //Post: Devuelve la cantidad de combates en la lista.
    size_t cantidad_combates();

};

#endif