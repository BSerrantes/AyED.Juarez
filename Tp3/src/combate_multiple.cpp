#include "combate_multiple.hpp"
#include <iostream>

using namespace std;


combate_multiple::combate_multiple(){
    total_combates = 0;
}

void combate_multiple::agregar_combate(combate combate_a_agregar){
    if(combates.tamanio() >= MAX_COMBATES){
        cout << "No se pueden agregar más de 6 combates!" << endl;
    }
    else{
        combates.alta(combate_a_agregar);
        total_combates++;
    }
}

size_t combate_multiple::pelear(){
    return pelear_recursivo();
}

size_t combate_multiple::cantidad_combates(){
    return total_combates;
}

size_t combate_multiple::pelear_recursivo(){

    if(combates.vacio()){
        cout << "No hay combates pendientes." << endl;
        return 0;
    }
    cout << "====================================" << endl;
    combate combate_peleado = combates.baja();
    total_combates--;
    cout << combate_peleado << endl;
    cout << "Combates restantes: " << combates.tamanio() << endl; 
    cout << "====================================" << endl;

    return combate_peleado.obtener_poder_gastado() + pelear_recursivo();
}
 