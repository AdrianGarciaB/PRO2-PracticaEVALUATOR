/** @file Usuario.cc
    @brief Codigo de la clase Usuario
*/

#include "Usuario.hh"

Usuario::Usuario() {
    id_curso = 0;
    nenvios_realizados = 0;
    nproblemas_resueltos = 0;
    nproblemas_intentados = 0;
}

int Usuario::curso_inscrito() const {
    return id_curso;
}

bool Usuario::pertenece_curso() const {
    return id_curso != 0;
}

/*bool Usuario::agregar_envio(int p, int r) const {
    return false;
}*/

void Usuario::escribir_problemas_resueltos() const{
    auto it = problemas_resueltos.begin();
    while (it != problemas_resueltos.end()){
        cout << it->first << '(' << it->second.intentos << ')' << endl;
        ++it;
    }
}

void Usuario::escribir_problemas_enviables() const {
    auto it = problemas_enviables.begin();
    while (it != problemas_enviables.end()) {
        cout << it->first << '(' << it->second.intentos << ')' << endl;
        ++it;
    }

}

void Usuario::inscribir_curso(const int& c) {
    id_curso = c;
}

void Usuario::agregar_problema_enviable(const string& p) {
    problemas_enviables[p] = Envio();
}

bool Usuario::agregar_envio(const string& p, const int& r) {
    auto it = problemas_enviables.find(p);
    Envio& envio = it->second;

    if (envio.intentos == 0)
        ++nproblemas_intentados;

    ++nenvios_realizados;
    ++envio.intentos;
    if (r==0) {
        ++envio.fallidos;
        return false;
    }
    else {
        ++nproblemas_resueltos;
        problemas_resueltos.insert({it->first, envio});
        problemas_enviables.erase(it);
        return true;
    }
}

void Usuario::baja_curso() {
    id_curso = 0;
}

int Usuario::obtener_nenviosrealizados() const {
    return nenvios_realizados;
}

int Usuario::obtener_nproblemasresueltos() const {
    return nproblemas_resueltos;
}

int Usuario::obtener_nproblemas_intentados() const {
    return nproblemas_intentados;
}

bool Usuario::problema_resuelto(const string &p) const{
    return problemas_resueltos.find(p) != problemas_resueltos.end();
}

bool Usuario::tiene_problemas_enviables() const{
    return problemas_enviables.size() > 0;
}


