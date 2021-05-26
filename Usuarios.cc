/** @file Usuarios.cc
    @brief Codigo de la clase Usuarios
*/

#include "Usuarios.hh"

Usuarios::Usuarios() {
    nregistrados = 0;
}


int Usuarios::obtener_nusuariosregistrados() const {
    return nregistrados;
}

Usuario& Usuarios::obtener_usuario(const string& u) {
    return usuarios.at(u);
}

Usuario& Usuarios::obtener_usuario(const string& u, bool& existe) {
    auto it = usuarios.find(u);
    if (it != usuarios.end()){
        existe = true;
        return it->second;
    }
    existe = false;
    return usuario_vacio;
}

void Usuarios::leer() {
    int usuarios_iniciales;
    cin >> usuarios_iniciales;

    string usuario;
    for (int i=0; i<usuarios_iniciales; ++i){
        cin >> usuario;
        // Inicializa el usuario;
        usuarios[usuario];
    }
    nregistrados += usuarios_iniciales;
}

bool Usuarios::alta(const string& u) {
    auto it = usuarios.insert({u, Usuario()});
    if (it.second)
        ++nregistrados;
    return it.second;
}

bool Usuarios::baja(const string& u, int &c) {
    auto it = usuarios.find(u);
    if (it != usuarios.end()) {
        c = it->second.curso_inscrito();
        usuarios.erase(it);
        --nregistrados;
        return true;
    }
    return false;
}

void Usuarios::listar_usuarios() const {
    auto it = usuarios.begin();
    while (it != usuarios.end()){
        cout << it->first << '(' << it->second.obtener_nenviosrealizados() << ',' << it->second.obtener_nproblemasresueltos() << ',' << it->second.obtener_nproblemas_intentados() << ',' << it->second.curso_inscrito() << ")" << endl;
        ++it;
    }
}

bool Usuarios::escribir_usuario(const string& s) const {
    auto it = usuarios.find(s);
    if (it != usuarios.end()) {
        cout << it->first << '(' << it->second.obtener_nenviosrealizados() << ',' << it->second.obtener_nproblemasresueltos() << ',' << it->second.obtener_nproblemas_intentados() << ',' << it->second.curso_inscrito() << ")" << endl;
        return true;
    }
    return false;
}

