#include "menu.hpp"

int main() {

    menu menu;

    menu.dar_bienvenida();
    while(menu.opcion() != SALIR){
        menu.pedir_opcion();
    }

    return 0;
}