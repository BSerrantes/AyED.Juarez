#ifndef AYED_TP3_1C2024_COLA_HPP
#define AYED_TP3_1C2024_COLA_HPP

#include <exception>
#include "nodo.hpp"

class cola_exception : public std::exception {
    // Excepción especifica y exclusiva para errores dentro de la cola.
    // Usar de la forma "throw cola_exception();" cuando una precondición no se cumple.

    // Ejemplo:
    //     if (condición_de_error) {
    //         throw cola_exception();
    //     }
};

template<typename T>
class cola {
private:
    nodo<T>* primer_nodo;
    nodo<T>* ultimo_nodo;
    size_t cantidad_datos;
public:
    // Constructor.
    cola();

    // Pre: -
    // Post: Agrega el dato al final de la cola.
    void alta(T dato);

    // Pre: La cola no puede estar vacía.
    // Post: Devuelve el primer dato de la cola.
    T primero();

    // Pre: La cola no puede estar vacía.
    // Post: Elimina y devuelve el primer dato de la cola.
    T baja();

    // Pre: -
    // Post: Devuelve la cantidad de datos de la cola.
    size_t tamanio();

    // Pre: -
    // Post: Devuelve true si la cola esta vacía.
    bool vacio();

    // El constructor de copia está deshabilitado.
    cola(const cola& c) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const cola& c) = delete;

    // Destructor.
    ~cola();
};

template<typename T>
cola<T>::cola() {
    primer_nodo = nullptr;
    ultimo_nodo = nullptr;
    cantidad_datos = 0;
}

template<typename T>
void cola<T>::alta(T dato) {
    if(cantidad_datos == 0){
        nodo<T>* nuevo_nodo = new nodo<T>(dato);
        primer_nodo = nuevo_nodo;
        ultimo_nodo = nuevo_nodo;
    }
    else{
        nodo<T>* nuevo_nodo = new nodo<T>(dato);
        ultimo_nodo->siguiente = nuevo_nodo;
        ultimo_nodo = nuevo_nodo;
    }
    cantidad_datos++;
}

template<typename T>
T cola<T>::primero() {
    if(cantidad_datos == 0){
        throw cola_exception();
    }
    else{
        return primer_nodo->dato;
    }
}

template<typename T>
T cola<T>::baja() {
    
    T dato_eliminado;

    if(cantidad_datos == 0){
        throw cola_exception();
    }
    else{
        nodo<T>* nodo_eliminado = primer_nodo;
        dato_eliminado = primer_nodo->dato;
        primer_nodo = primer_nodo->siguiente;
        delete nodo_eliminado;
        cantidad_datos--;
    }
    return dato_eliminado;
}

template<typename T>
size_t cola<T>::tamanio() {
    return cantidad_datos;
}

template<typename T>
bool cola<T>::vacio() {
    return (cantidad_datos == 0);
}

template<typename T>
cola<T>::~cola() {
    while(cantidad_datos != 0){
        baja();
    }
}

#endif