#include "gacha.hpp"
#include "generador_salto.hpp"
#include <random>

const int LIMITE_5_ESTRELLAS = 89;
const int LIMITE_4_ESTRELLAS = 9;
const int SALTOS_INICIO = 0;
const int SALTOS_MULTIPLES = 10;
const std::string REGISTRO_SALTOS = "registro_saltos.csv";

gacha::gacha() {
    cant_saltos_4_estrellas = 0;
    cant_saltos_5_estrellas = 0;
}

double gacha::rand_double_gen(int cota_inf, int cota_sup){
    double rand_num;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double>dist(cota_inf, cota_sup);
    rand_num = dist(gen);
    return rand_num;
}

int gacha::buscar_indice_ganador(double vector[MAX_RAREZAS], int tope, double dato){
    int posicion;
    int i = 0;
    bool encontrado = false;
    while(i < tope && !encontrado){
        if(vector[i] > dato){
            posicion = i;
            encontrado = true;
        }
        i++;
    }
    return posicion;
}

int gacha::buscar_ganador(int vector[MAX_RAREZAS], int tope, int indice){
    int ganador;
    for(int i = 0; i < tope; i++){
        if(i == indice){
            ganador = vector[i];
        }
    }
    return ganador;
}

salto gacha::generar_salto() {

    generador_salto salto_gen;
    double nro_generado;
    int indice;
    int nro_ganador;
    int tope_rarezas = 3;

    nro_generado = rand_double_gen(0,1);
    indice = buscar_indice_ganador(proba_acumulada,tope_rarezas,nro_generado);
    nro_ganador = buscar_ganador(nros_ganadores, tope_rarezas, indice);

    if (nro_ganador == SALTO_3_ESTRELLAS){

        if(cant_saltos_4_estrellas >= LIMITE_4_ESTRELLAS){

            if(cant_saltos_5_estrellas>=LIMITE_5_ESTRELLAS){
                salto_generado = salto_gen.generar_salto_5_estrellas();
                cant_saltos_5_estrellas = 0;
                cant_saltos_4_estrellas++;
            }
            else{
                salto_generado = salto_gen.generar_salto_4_estrellas();
                cant_saltos_4_estrellas = 0;
                cant_saltos_5_estrellas++;
            }

        }
        else if(cant_saltos_5_estrellas >= LIMITE_5_ESTRELLAS){
            salto_generado = salto_gen.generar_salto_5_estrellas();
            cant_saltos_5_estrellas = 0;
            cant_saltos_4_estrellas++;
        }
        else{
            salto_generado = salto_gen.generar_salto_3_estrellas();
            cant_saltos_4_estrellas++;
            cant_saltos_5_estrellas++;
        }
    }

    else if(nro_ganador  == SALTO_4_ESTRELLAS){
        salto_generado = salto_gen.generar_salto_4_estrellas();
        cant_saltos_4_estrellas = 0;
        cant_saltos_5_estrellas++;
    }

    else{
        salto_generado = salto_gen.generar_salto_5_estrellas();
        cant_saltos_5_estrellas = 0;
        cant_saltos_4_estrellas++;
    }

    return salto_generado;
}

vector<salto> gacha::generar_salto_multiple(){
     return generar_salto_multiple(SALTOS_MULTIPLES);
}

  


vector<salto> gacha::generar_salto_multiple(size_t cantidad){

    for(size_t i = 0; i < cantidad;i++){
        salto_generado = generar_salto();
        saltos.alta(salto_generado);
    }
    return saltos;
}

void gacha::exportar_saltos(){
    gestor_archivos gestor(REGISTRO_SALTOS);
    gestor.abrir();
    for(size_t i = 0; i < saltos.tamanio(); i++){
        gestor.agregar_datos(saltos[i]);
    }
    gestor.cerrar();
}