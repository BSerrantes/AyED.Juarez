#include <fstream>
#include  "salto.hpp"
#include <iostream>

class gestor_archivos{

    private:

    std::string nombre_archivo;
    std::ofstream archivo;

    public:

    //constructores
    gestor_archivos();
    gestor_archivos(std::string nombre_archivo);

    //Pre: 
    //Post: Abre el archivo o lo crea si no existe.
    void abrir();

    //Pre: 
    //Post: Cierra el archivo
    void cerrar();

    //Pre: El archivo debe estar abierto.
    //Post: Agrega los datos al final del archivo sin sobreescribir lo existente.
    void agregar_datos(salto salto_generado);

};  
