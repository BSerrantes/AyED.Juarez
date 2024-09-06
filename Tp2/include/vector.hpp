#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <exception>

const int TAMANIO_INICIAL = 1;

class vector_exception : public std::exception {
    // Excepción especifica y exclusiva para errores dentro del vector.
    // Usar de la forma "throw vector_exception();" cuando una precondición no se cumpla.

    // Ejemplo:
    //     if (condición_de_error){
    //         throw vector_exception();
    //     }
};

template<typename T>
class vector {
private:
    T* datos;

    size_t cantidad_datos;
    // Tamaño del arreglo "datos".
    size_t tamanio_maximo;

    //Pre:-
    //Post: Duplica el tamaño del vector o, si no existe, crea un vector con un tamaño_maximo de 1.
    void expandir();

    //Pre:-
    //Post: Reduce el tamaño del vector a la mitad o lo elimina si estamos borrando el último elemento del vector.
    void reducir();

public:
    // Constructor.
    vector();

    // Pre: El índice debe ser menor o igual que la cantidad de datos.
    // Post: Agrega el dato antes del dato en la posición indicada, moviendo todos los elementos siguientes.
    void alta(T dato, size_t indice);

    // Pre: -
    // Post: Agrega el dato al final del vector. Equivale a alta(dato, cantidad_datos).
    void alta(T dato);

    // Pre: El vector no puede estar vacío. El índice debe ser menor que la cantidad de datos.
    // Post: Elimina el dato en la posición indicada, moviendo todos los elementos siguientes, y lo devuelve.
    T baja(size_t indice);

    // Pre: El vector no puede estar vacío.
    // Post: Elimina el ultimo dato y lo devuelve. Equivale a baja(cantidad_datos - 1).
    T baja();

    // Pre: -
    // Post: Devuelve true si el vector está vacío (es decir, si no hay datos).
    bool vacio();

    // Pre: -
    // Post: Devuelve la cantidad de datos del vector.
    size_t tamanio();

    // Pre: El vector no puede estar vacío. El índice debe ser menor que la cantidad de datos.
    // Post: Devuelve una referencia al dato deseado.
    T& operator[](size_t indice);

    // Constructor de copia (ya implementado).
    vector(const vector<T>& vector);

    // Operador de asignación (ya implementado).
    vector<T>& operator=(const vector<T>& vector);

    // Destructor.
    ~vector();
};

template<typename T>
vector<T>::vector(){
    datos = nullptr;
    cantidad_datos = 0;
    tamanio_maximo = 0;
}

template<typename T>
void vector<T>::expandir(){
     
    if(cantidad_datos == 0){
        datos = new T[TAMANIO_INICIAL];
        tamanio_maximo = TAMANIO_INICIAL;
    }
    else{

        size_t nuevo_tope = tamanio_maximo*2;
        T* vec_temp = new T[nuevo_tope];
        for(size_t i = 0; i < cantidad_datos; i++){
            vec_temp[i] = datos[i];
        }
        delete[] datos;
        datos = nullptr;
        datos = vec_temp;
        tamanio_maximo = nuevo_tope;
    }
    
}

template<typename T>
void vector<T>::reducir(){

    size_t nuevo_tope = tamanio_maximo/2;
    T* vec_temp = new T[nuevo_tope];
    for(size_t i = 0; i < cantidad_datos;i++){
        vec_temp[i] = datos[i];
    }
    delete[] datos;
    datos = nullptr;
    datos = vec_temp;
    tamanio_maximo = nuevo_tope;

    if(tamanio_maximo == TAMANIO_INICIAL){
        delete[]datos;
        datos = nullptr;
        tamanio_maximo = 0;
    }
}

template<typename T>
void vector<T>::alta(T dato, size_t indice) {

    if(indice > cantidad_datos){
        throw vector_exception();
    }

    else if(cantidad_datos == tamanio_maximo){
        expandir();
    }

    for(size_t i = cantidad_datos; i > indice; i--){
        datos[i] = datos[i - 1];
    }
    datos[indice] = dato;
    cantidad_datos++;
    
}

template<typename T>
void vector<T>::alta(T dato) {
    alta(dato, cantidad_datos);
}

template<typename T>
T vector<T>::baja(size_t indice) {

    T dato_eliminado;
    if(vacio() || indice >= cantidad_datos){
        throw vector_exception();
    }
    else{
        dato_eliminado = datos[indice];
        size_t mitad_vec = tamanio_maximo / 2;

        if(cantidad_datos <= mitad_vec){
        
            //si itero hasta cantidad de datos, al reasignar datos[] entraría a una posición inválida.
            for(size_t i = indice; i < cantidad_datos - 1; i++){
            datos[i] = datos[i+1]; //esto va desde indice hasta cantidad_datos
            }
            reducir();
            cantidad_datos--;
        }
        else{

            for(size_t i = indice; i < cantidad_datos - 1; i++){
                datos[i] = datos[i+1]; //esto va desde indice hasta cantidad_datos
            }
            cantidad_datos--;      
        }
    }
    return dato_eliminado;
}

template<typename T>
T vector<T>::baja() {
    T dato_eliminado = baja(cantidad_datos-1);
    return dato_eliminado;
}

template<typename T>
bool vector<T>::vacio(){
        return cantidad_datos == 0;
    }

template<typename T>
size_t vector<T>::tamanio() {
    return cantidad_datos;
}

template<typename T>
T& vector<T>::operator[](size_t indice){
    
    if(cantidad_datos == 0 || indice >= cantidad_datos){
        throw vector_exception();
    }

    return datos[indice];
}

template<typename T>
vector<T>::~vector() {
    delete [] datos;
}

// Estos dos métodos ya están implementados. No hace falta modificarlos.
template<typename T>
vector<T>::vector(const vector& vector) {
    datos = nullptr;
    cantidad_datos = vector.cantidad_datos;
    tamanio_maximo = vector.tamanio_maximo;
    if (tamanio_maximo) {
        datos = new T[tamanio_maximo];
        for (size_t i = 0; i < cantidad_datos; i++) {
            datos[i] = vector.datos[i];
        }
    }
}

template<typename T>
vector<T>& vector<T>::operator=(const vector& vector) {
    if (this != &vector) {
        delete[] datos;
        datos = nullptr;
        cantidad_datos = vector.cantidad_datos;
        tamanio_maximo = vector.tamanio_maximo;
        if (tamanio_maximo) {
            datos = new T[tamanio_maximo];
            for (size_t i = 0; i < cantidad_datos; i++) {
                datos[i] = vector.datos[i];
            }
        }
    }
    return *this;
}

#endif