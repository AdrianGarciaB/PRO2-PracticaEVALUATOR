/** @file Sesiones.cc
    @brief Codigo de la clase Sesiones
*/

#include "Sesiones.hh"

Sesiones::Sesiones() {
    nsesiones=0;
}

int Sesiones::getNsesiones() const {
    return nsesiones;
}

void Sesiones::agregar_problemas_enviables(Usuario& usuario, const string& s) const{
    sesiones.at(s).agregar_problemas_enviables(usuario);
}

void Sesiones::agregar_problemas_enviables(Usuario &usuario, const string &s, const string &p) const {
    sesiones.at(s).agregar_problemas_enviables(usuario, p);
}

bool Sesiones::agregar_problemas(Cjt_identificadores& identificadores, const string& s) const {
    return sesiones.at(s).agregar_problemas(identificadores, s);
}


void Sesiones::leer() {
    int sesiones_iniciales;
    cin >> sesiones_iniciales;
    string sesion;
    for (int i=0;i<sesiones_iniciales;++i) {
        cin >> sesion;
        sesiones[sesion].leer();
    }
    nsesiones += sesiones_iniciales;
}

bool Sesiones::agregar(string s) {
    Sesion sesion;
    sesion.leer();
    auto par = sesiones.insert({s,sesion});
    if (par.second)
        ++nsesiones;
    return par.second;
}

void Sesiones::listar_sesiones() const {
    auto it = sesiones.begin();
    while (it != sesiones.end()) {
        cout << it->first << " ";
        it->second.escribir();
        ++it;
    }
}

bool Sesiones::escribir_sesion(const string& s) const {
    auto it = sesiones.find(s);
    if (it != sesiones.end()){
        cout << s << " ";
        it->second.escribir();
        return true;
    }
    return false;
}




