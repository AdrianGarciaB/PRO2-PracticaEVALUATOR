//
// Created by Usuario on 30/04/2021.
//

#include "Problema.hh"

Problema::Problema() {
    id_problema = "";
    intentos = aciertos = 0;
    ratio = 1;
}

void Problema::calcular_ratio() {
    ratio = (double) (1+intentos)/(1+aciertos);
}

Problema::Problema(const string &id_problema, const int &intentos, const int &aciertos, const double &ratio) {
    this->id_problema = id_problema;
    this->intentos = intentos;
    this->aciertos = aciertos;
    this->ratio = ratio;
}

Problema::Problema(const string &id_problema) {
    this->id_problema = id_problema;
    intentos = aciertos = 0;
    ratio = 1;
}

int Problema::obtener_intentos() const {
    return intentos;
}

int Problema::obtener_aciertos() const {
    return aciertos;
}

double Problema::obtener_ratio() const {
    return ratio;
}

string Problema::obtener_idproblema() const {
    return id_problema;
}

void Problema::aumentar_intentos() {
    ++intentos;
    calcular_ratio();
}

void Problema::aumentar_aciertos() {
    ++aciertos;
    calcular_ratio();
}
