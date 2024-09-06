#include "gestor_archivos.hpp"

gestor_archivos::gestor_archivos(){

}

gestor_archivos::gestor_archivos(std::string nombre_archivo){

    this ->nombre_archivo =  nombre_archivo;
}

void gestor_archivos::abrir(){
    
    archivo.open(nombre_archivo, std::ios::out | std::ios::app);
    std::cout << "Registro creado!" << std::endl;

}

void gestor_archivos::cerrar(){
    archivo.close();
}

void gestor_archivos::agregar_datos(salto salto_generado){

    if(archivo.is_open()){
        archivo << salto_generado << std::endl;
    }
    else{
        std::cout << "No se abrió el archivo o este no existe." << std::endl;
    }
}