#include "armamento_artefactos.hpp"
#include <iostream>
using namespace std;

bool armamento_artefactos::esta_en_armamento(artefacto artefacto_a_agregar){

    bool result_busqueda = false;

    for(size_t i = 0; i < armamento.tamanio(); i++){
        if (artefacto_a_agregar == armamento.actual()){
            result_busqueda = true;
        }
        armamento.avanzar(); 
    }

    return result_busqueda;
}

int armamento_artefactos::rand_int_gen(int cota_inf, int cota_sup){
    int rand_num;
    random_device rd;
    uniform_int_distribution<int> dist(cota_inf,cota_sup);
    rand_num = dist(rd);
    return rand_num;
}

void armamento_artefactos::avances_aleatorios(){

    int cantidad_avances = rand_int_gen(1,6);

    for (int i = 0; i < cantidad_avances; i++){
        armamento.avanzar();
    }
}

armamento_artefactos::armamento_artefactos(){

}

armamento_artefactos::armamento_artefactos(string path_archivo){
    armamento_importado = path_archivo;
}

void armamento_artefactos::agregar_artefacto(artefacto artefacto_a_agregar){
    if(armamento.tamanio() == MAX_ARTEFACTOS){
        cout << "No se pueden agregar más artefactos!" << endl;
        cout << "\n";
    }
    else if(esta_en_armamento(artefacto_a_agregar)){
        cout << "No se puede agregar un elemento que ya está" << endl;
        cout << "\n";
    }
    else{
        //primero muevo el cursor y luego agrego.
        avances_aleatorios();
        armamento.alta(artefacto_a_agregar);
    }
}

void armamento_artefactos::mostrar_artefacto_actual(){
    if(armamento.vacio()){
        cout << "El armamento está vacío, no hay nada para mostrar..." << endl;
        cout << "\n";
    }
    else{
        cout << armamento.actual() << endl;
        cout << "\n";
    }
}

void armamento_artefactos::mostrar_artefacto_siguiente(){
    if(armamento.vacio()){
        cout << "El armamento está vacío, no hay nada para mostrar..." << endl;
        cout << "\n";
    }
    else{
        armamento.avanzar();
        cout << armamento.actual() << endl;
        cout << "\n";
    }
}

void armamento_artefactos::mostrar_artefacto_anterior(){
    if(armamento.vacio()){
        cout << "El armamento está vacío, no hay nada para mostrar..." << endl;
        cout << "\n";
    }
    else{
        armamento.retroceder();
        cout << armamento.actual() << endl;
        cout << "\n";
    }
}

void armamento_artefactos::mostrar_artefactos(){
    if(armamento.vacio()){
        cout << "El armamento está vacío, no hay nada para mostrar..." << endl;
        cout << "\n";
    }
    else{
        size_t i = 0;
        while(!armamento.vacio() && i < armamento.tamanio()){
            if(i == 0){
                //este sería el primer artefacto a mostrar.
                avances_aleatorios();
                cout << armamento.actual() << endl;
                cout << "\n";
            }
            else{
                armamento.avanzar();
                cout << armamento.actual() << endl;
                cout << "\n";
            }
            i++;
        }
    }
}

void armamento_artefactos::quitar_artefacto(){
    if(armamento.vacio()){
        cout << "El armamento está vacío, no hay nada para borrar..." << endl;
        cout << "\n";
    }
    else{
        armamento.baja();
    }    
}

void armamento_artefactos::exportar_armamento(){

    if(armamento.vacio()){
        cout << "El armamento está vacío, no hay nada para exportar!" << endl;
    }
    else{
        //formato del archivo ID,SET,TIPO,NIVEL,RAREZA -> cada línea es un artefacto
        cout << "Ingrese un Nombre para su Armamento (sin espacios):" << endl;
        cin >> nombre_armamento;
        string nombre_archivo = UUID + "-" + nombre_armamento +".csv";
        
        ofstream archivo; 
        archivo.open(nombre_archivo, ios::out | ios::app);   
        cout << "Registro Creado!" << endl;
        for (size_t i = 0; i < armamento.tamanio(); i++){
            if(archivo.is_open()){
                archivo << armamento.actual() << endl;
            }
            else{
                cout << "No se abrió el archivo o este no existe." << endl;
            }
            armamento.avanzar();
        }
        archivo.close();
    }
}

void armamento_artefactos::importar_armamento(){
    //el archivo a recibir tiene el formato  ID,SET,TIPO,NIVEL,RAREZA -> cada línea es un artefacto

    if( armamento.tamanio() > 0){
        cout << "\n";
        cout << "Ya existen artefactos en el armamento actual, por lo tanto no se puede importar otro." << endl;
        cout << "\n";
    }
    else{
        ifstream archivo;
        string  nombre_archivo = armamento_importado;
        archivo.open(nombre_archivo, ios::in);
        if (archivo.is_open()){

            string id;
            string set;
            string _tipo;
            string nivel;
            string _rareza;

            while(getline(archivo,id,',')){
                getline(archivo,set,',');
                getline(archivo,_tipo,',');
                getline(archivo,nivel,',');
                getline(archivo,_rareza);

                int num_id = stoi(id);
                int num_tipo = stoi(_tipo);
                tipo tipo_asignado = asignar_tipo_artefacto(num_tipo);
                int num_nivel = stoi(nivel);
                int num_rareza = stoi(_rareza);
                rareza rareza_asignada = asignar_rareza_artefacto(num_rareza);

                artefacto importado( num_id , set , tipo_asignado , (size_t)num_nivel , rareza_asignada);
                agregar_artefacto(importado);

            }
        }
        else{
            cout << "No se abrió el archivo o este no existe." << endl;       
        }
    }
}

rareza armamento_artefactos::asignar_rareza_artefacto(int dato){

    rareza rareza_obtenida;

    if(dato == TRES_ESTRELLAS){
        rareza_obtenida = TRES_ESTRELLAS;
    }
    else if(dato == CUATRO_ESTRELLAS){
        rareza_obtenida = CUATRO_ESTRELLAS;
    }
    else if(dato == CINCO_ESTRELLAS){
        rareza_obtenida = CINCO_ESTRELLAS;
    }
    else{
        rareza_obtenida = RAREZA_INDEFINIDA;
    }

    return rareza_obtenida;
}

tipo armamento_artefactos::asignar_tipo_artefacto(int dato){

    tipo tipo_obtenido;

    if(dato == CABEZA){
        tipo_obtenido = CABEZA;
    }
    else if(dato == MANOS){
        tipo_obtenido = MANOS;
    }
    else if(dato == TORSO){
        tipo_obtenido = TORSO;
    }
    else if(dato == PIERNAS){
        tipo_obtenido = PIERNAS;
    }
    else if(dato == ESFERA_PLANAR){
        tipo_obtenido = ESFERA_PLANAR;
    }
    else if(dato == PISTA_DE_LUZ){
        tipo_obtenido = PISTA_DE_LUZ;
    }
    else{
        tipo_obtenido = TIPO_INDEFINIDO;
    }
    return tipo_obtenido;
}
