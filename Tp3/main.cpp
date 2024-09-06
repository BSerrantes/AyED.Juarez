#include "menu.hpp"

using namespace std;

int main() {

    menu app;
    app.dar_bienvenida();
    while(app.opcion() != SALIR_MINUS && app.opcion() != SALIR_MAYUS){
        app.pedir_opcion();
    }

    return 0;
}