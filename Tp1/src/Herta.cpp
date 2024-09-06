#include "Herta.hpp"

using namespace std;

// Otras const
const int OPCION_1 = 1;
const int OPCION_2 = 2;
const string VACIO = " ";

//Respuestas fijas
const string RESP_AUTO = "[Respuesta automatica] Hola. En este momento no estoy disponible, y no me pondre en contacto contigo mas tarde.";
const string KURU = "KURU";
const string KURUKURU = "KURU KURU";
const string KURURIN = "KURURIN";
const string SALUDO = "Hola.";
const string PROBLEMA = "No te preocupes. Ya esta solucionado.";
const string PREOCUPACION = "De que te preocupas si yo estoy aqui?";
const string SIMULACION = "La actualizacion del Universo Simulado ya esta lista, ven a probarla.";
const string SELFIE = "Quieres una selfie para demostrartelo o que?";
const string MARIONETA = "Vaya, parece que la perdi. No me extrania que no la encuentre.";
const string LIBRE_1 = "Oh.";
const string LIBRE_2 = "...";

//Preguntas fijas
const string MSJ_FIJO_1 = "eres herta?";
const string MSJ_FIJO_2 = "y tu marioneta?";

//Mensajes fijos
const string LOW_KURU = "kuru";
const string LOW_KURURIN = "kururin";
const string LOW_SALUDO = "hola";
const string LOW_PRBLM = "problema";
const string LOW_PREOC_1 = "preocupado";
const string LOW_PREOC_2 = "preocupada";
const string LOW_SIM = "simulado";


Herta::Herta(){
    paciencia = 0;
}

int Herta::rand_machine(int cota_inf, int cota_sup){
    random_device rd;
    uniform_int_distribution<int> dist(cota_inf,cota_sup);
    rand_num = dist(rd);
    return rand_num;
}

string Herta::convertir_msj(string mensaje_nuevo){
    for(int i = 0; i < int(mensaje_nuevo.length()); i++){
        mensaje_nuevo[i] = char(tolower(mensaje_nuevo[i])); 
    }
    return mensaje_nuevo;
}

void Herta::asignar_respuesta(std::string mensaje_adaptado){

    string respuesta = VACIO;

    if(paciencia == 0){
        respuesta = RESP_AUTO;
        cout << respuesta << endl;
        paciencia++;
    }
    else{
        if(mensaje_adaptado.contains(LOW_KURU) || mensaje_adaptado.contains(LOW_KURURIN)){
            rand_num = rand_machine(1,3);
            if(rand_num == OPCION_1){
                respuesta = KURU;
                cout << respuesta << endl;
            }
            else if(rand_num == OPCION_2){
                respuesta = KURUKURU;
                cout << respuesta << endl;
            }
            else{
                respuesta = KURURIN;
                cout << respuesta << endl;
            }
        }   
        else if(mensaje_adaptado.contains(LOW_SALUDO)){
            respuesta = SALUDO;
            cout << respuesta << endl;
        }
        else if(mensaje_adaptado.contains(LOW_PRBLM)){
            respuesta = PROBLEMA;
            cout << respuesta << endl;
        }
        else if(mensaje_adaptado.contains(LOW_PREOC_1) || mensaje_adaptado.contains(LOW_PREOC_2)){
            respuesta = PREOCUPACION;
            cout << respuesta << endl;
        }
        else if(mensaje_adaptado.contains(LOW_SIM)){
            respuesta = SIMULACION;
            cout << respuesta <<endl;
        }
        else if(mensaje_adaptado == MSJ_FIJO_1){
            respuesta = SELFIE;
            cout << respuesta << endl;
        }
        else if(mensaje_adaptado == MSJ_FIJO_2){
            respuesta = MARIONETA;
            cout << respuesta << endl;
        }
        else{
            rand_num = rand_machine(1,2);
            if(rand_num == OPCION_1){
                respuesta = LIBRE_1;
                cout << respuesta << endl;
            }
            else{
                respuesta = LIBRE_2;
                cout << respuesta << endl;
            }
        }
        paciencia++;      
    } 
}

void Herta::responder(string mensaje) { 
    
    string msj_adaptado = convertir_msj(mensaje);

    if(paciencia <= TOPE_PACIENCIA){
        asignar_respuesta(msj_adaptado);
    }
    else{
        paciencia-=(TOPE_PACIENCIA+1);
        asignar_respuesta(msj_adaptado);
    }
}
