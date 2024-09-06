#include "menu.hpp"
#include <iostream>

using namespace std;

menu::menu(){

}

void menu::dar_bienvenida(){
    cout << "Bienvenido al generador de saltos!" << endl;
    cout <<"\n";
}

void menu::mostrar_saltos(vector<salto> vector){
    cout <<"Se muestra la totalidad de saltos realizados durante la ejecución del programa:" <<endl;
    cout << "\n";
    for(size_t i = 0; i < vector.tamanio(); i++){
        cout << vector[i] << endl;
    }
    cout << endl;
}

void menu::opcion_salto_simple(){
    salto_generado = jugada.generar_salto();
    saltos.alta(salto_generado);
    mostrar_saltos(saltos);
}

void menu::opcion_diez_saltos(){
    saltos = jugada.generar_salto_multiple();
    mostrar_saltos(saltos);
}

void menu::opcion_salto_multiple(){
    saltos = jugada.generar_salto_multiple(cantidad_saltos);
    mostrar_saltos(saltos);
}

void menu::opcion_registro(){
    cout << "Exportando..." << endl;
    jugada.exportar_saltos();
}

void menu::mostrar_opciones(){
    cout << "[1] Generar salto simple." << endl;
    cout << "[2] Generar diez saltos." << endl;
    cout << "[3] Generar salto múltiple. (debe ingresar una cantidad)" << endl;
    cout << "[4] Generar registro de los saltos obtenidos." << endl;
    cout << "[5] Salir." << endl;
}

void menu::pedir_opcion(){
    cout << "Elija una de las siguientes opciones:" << endl;
    mostrar_opciones();
    cout << "Recuerde que para elegir la opción se debe ingresar el número que aparece al lado." << endl;
    cout <<"Cualquier otra elección se alertará." << endl;
    cin >> opcion_elegida;
    if (opcion_elegida == SALTO_SIMPLE){
        system("clear");
        opcion_salto_simple();
    }
    else if(opcion_elegida == DIEZ_SALTOS){
        system("clear");
        opcion_diez_saltos();
    }
    else if(opcion_elegida == SALTO_MULTIPLE){
        system("clear");
        cout << "Cuántos saltos quiere realizar?" << endl;
        cin >> cantidad_saltos;
        opcion_salto_multiple();
    }
    else if(opcion_elegida == REGISTRO){
        opcion_registro();
    }
    else if(opcion_elegida == SALIR){
        salir();
    }
    else{
        cout << "Opcion inválida." << endl;
        cout << "\n";
    }
}

char menu::opcion(){
    return opcion_elegida;
}

void menu::salir(){
    cout << "Saliendo..." << endl;
}