#include "menu.hpp"

using namespace std;

const int CANT_ARTEFACTOS = 18;

menu::menu(){
 
}

int menu::rand_int_gen(int cota_inf, int cota_sup){
    int rand_num;
    random_device rd;
    uniform_int_distribution<int> dist(cota_inf,cota_sup);
    rand_num = dist(rd);
    return rand_num;
}

tipo menu::generar_tipo(){

    int nro_tipo_generado = rand_int_gen(1,6);
    tipo tipo_generado;

    if(nro_tipo_generado == CABEZA){
        tipo_generado = CABEZA;
    }
    else if(nro_tipo_generado == MANOS){
        tipo_generado = MANOS;
    }
    else if(nro_tipo_generado == TORSO){
        tipo_generado = TORSO;
    }
    else if(nro_tipo_generado == PIERNAS){
        tipo_generado = PIERNAS;
    }
    else if(nro_tipo_generado == ESFERA_PLANAR){
        tipo_generado = ESFERA_PLANAR;
    }
    else if(nro_tipo_generado == PISTA_DE_LUZ){
        tipo_generado = PISTA_DE_LUZ;
    }
    else{
        tipo_generado = TIPO_INDEFINIDO;
    }
    return tipo_generado;
}

rareza menu::generar_rareza(){

    rareza rareza_generada;
    int nro_rareza_generada = rand_int_gen(3,5);

    if(nro_rareza_generada == TRES_ESTRELLAS){
        rareza_generada = TRES_ESTRELLAS;
    }
    else if(nro_rareza_generada == CUATRO_ESTRELLAS){
        rareza_generada = CUATRO_ESTRELLAS;
    }
    else if(nro_rareza_generada == CINCO_ESTRELLAS){
        rareza_generada = CINCO_ESTRELLAS;
    }
    else{
        rareza_generada = RAREZA_INDEFINIDA;
    }

    return rareza_generada;
}

string menu::generar_set(){

    int rand_pos = rand_int_gen(0,17);

    string set_artefactos[CANT_ARTEFACTOS] = {"Banda del trueno crepitante"
                                            ,"Buceadora pionera del agua muerta"
                                            ,"Campeona de boxeo callejero"
                                            ,"Cazador del bosque glacial"
                                            ,"Discípula longeva"
                                            ,"Forjador de lava"
                                            ,"Genio de las estrellas relucientes"
                                            ,"Gran duque incinerador"
                                            ,"Guardia de la nieve borrascosa"
                                            ,"Habitante del yermo de los bandidos"
                                            ,"Ladrón del rastro meteórico"
                                            ,"Mensajero del espacio hackeado"
                                            ,"Paladina de la iglesia de la Corte Inmaculada"
                                            ,"Pistolera de la espiga silvestre"
                                            ,"Prisionero aislado"
                                            ,"Relojero de maquinaciones oníricas"
                                            ,"Transeúnte de la nube pasajera"
                                            ,"Águila del crepúsculo"};


    string set_generado = set_artefactos[rand_pos];

    return set_generado;
}

string menu::gen_descripcion_combate(){

    int rand_pos = rand_int_gen(0,6);

    string descripciones[7] = {"Cuańtico"
                              ,"Físico"
                              ,"Fuego"
                              ,"Hielo"
                              ,"Imaginario"
                              ,"Rayo"
                              ,"Viento"};

    string descripcion = descripciones[rand_pos];

    return descripcion;
}

void menu::mostrar_opciones(){
    cout << "\n";
    cout << "[0] Agregar artefacto." << endl;
    cout << "[1] Mostrar artefacto actual." << endl;
    cout << "[2] Mostrar artefacto siguiente." << endl;
    cout << "[3] Mostrar artefacto anterior." << endl;
    cout << "[4] Mostrar todos los artefactos." << endl;
    cout << "[5] Quitar artefacto del armamento." << endl;
    cout << "[6] Exportar armamento." << endl;
    cout << "[7] Importar armamento." << endl;
    cout << "[8] Agregar combate." << endl;
    cout << "[9] Pelear." << endl;
    cout << "[s/S] Salir." << endl;
    cout << "\n";
}

void menu::salir(){
    cout << "Saliendo..." << endl;
}

void menu::dar_bienvenida(){ 
    cout << "Bienvenido!" << endl;
    cout << "\n";
}

void menu::pedir_opcion(){
    cout << "Elija una de las siguientes opciones:" << endl;
    mostrar_opciones();
    cout << "Recuerde que para elegir la opción se debe ingresar el número que aparece al lado." << endl;
    cout <<"Cualquier otra elección se alertará." << endl;
    cin >> opcion_elegida;

    if (opcion_elegida == AGREGAR_ARTEFACTO){

        int id_generado = rand_int_gen(1,99);

        string set_generado = generar_set();

        tipo tipo_generado = generar_tipo();

        size_t nivel_generado = (size_t)rand_int_gen(1,20);

        rareza rareza_generada = generar_rareza();

        artefacto artefacto_generado(id_generado, set_generado, tipo_generado, nivel_generado, rareza_generada);

        armamento_nuevo.agregar_artefacto(artefacto_generado);
    }
    else if(opcion_elegida == MOSTRAR_ACTUAL){
        cout << endl;
        armamento_nuevo.mostrar_artefacto_actual();
    }
    else if(opcion_elegida == MOSTRAR_SIGUIENTE){
        cout << endl;
        armamento_nuevo.mostrar_artefacto_siguiente();
    }
    else if(opcion_elegida == MOSTRAR_ANTERIOR){
        cout << endl;
        armamento_nuevo.mostrar_artefacto_anterior();
    }
    else if(opcion_elegida == MOSTRAR_TODOS){
        cout << endl;
        armamento_nuevo.mostrar_artefactos();
    }
    else if(opcion_elegida == QUITAR_ARTEFACTO){
        armamento_nuevo.quitar_artefacto();
    }
    else if(opcion_elegida == EXPORTAR_ARMAMENTO){
        armamento_nuevo.exportar_armamento();
    }
    else if(opcion_elegida == IMPORTAR_ARMAMENTO){

        string nombre_archivo;
        cout << "Ingrese el nombre del archivo a importar." << endl;
        cout << "(Debe ser un archivo *.csv existente)." << endl;
        cin >> nombre_archivo;
        armamento_artefactos armamento_importado(nombre_archivo);
        armamento_importado.importar_armamento();
        armamento_importado.mostrar_artefactos();
        opcion_elegida = SALIR_MINUS;
        
    }
    else if(opcion_elegida == AGREGAR_COMBATE){

        string descripcion = gen_descripcion_combate();

        size_t cantidad_enemigos = (size_t)rand_int_gen(5,25);

        size_t trazacaminos_gastado = (size_t)rand_int_gen(15,30);

        combate combate_generado(descripcion, cantidad_enemigos, trazacaminos_gastado);

        combates.agregar_combate(combate_generado);
        
        cout << "\n";
        cout << "Combates en la lista : " << combates.cantidad_combates() << endl;
        cout << "\n";
    }
    else if(opcion_elegida == PELEAR){
        size_t poder_gastado = combates.pelear();
        cout << "Total de poder de Trazacaminos gastado: "<< poder_gastado << endl;
        cout << "\n";
    }
    else if(opcion_elegida == SALIR_MINUS || opcion_elegida == SALIR_MAYUS){
        salir();
    }
    else{      
        cout << "Opción inválida." << endl;
        cout << "\n";
    }
}

char menu::opcion(){
    return opcion_elegida;
}

