#include "Herta.hpp"

using namespace std;

const string SALIDA_CHAT = "chau";

int main() {

    string mensaje = " ";
    Herta herta;

    while (mensaje != SALIDA_CHAT){
        cout << "Ingrese un mensaje para Herta o chau para salir: ";
        getline(cin, mensaje);
        if( mensaje !=SALIDA_CHAT){
            herta.responder(mensaje);
        }
        cout << endl;
    }
    
    return 0;
}