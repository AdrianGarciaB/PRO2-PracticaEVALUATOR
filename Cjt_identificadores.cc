/** @file Cjt_identificadores.cc
    @brief Codigo de la clase Cjt_identificadores
*/

#include "Cjt_identificadores.hh"

Cjt_identificadores::Cjt_identificadores() {

}

string Cjt_identificadores::obtener_elemento(const string &p) const {
    string valor;
    auto it = cjt.find(p);
    if (it != cjt.end())
        valor = it->second;
    return valor;
}

int Cjt_identificadores::obtener_volumen() const {
    return cjt.size();
}


bool Cjt_identificadores::insertar(pair<string, string> p) {
    return cjt.insert(p).second;
}
