/** @file Curso.cc
    @brief Codigo de la clase Curso
*/

#include "Curso.hh"

Curso::Curso() {
    nsesiones = 0;
    usuarios_inscritos = 0;
    usuarios_superados = 0;
}

bool Curso::obtener_nombre_sesion(const string& id_problema, string &identificador_sesion) const {
    identificador_sesion = problema_sesion.obtener_elemento(id_problema);
    return not identificador_sesion.empty();
}

int Curso::obtener_inscritos() const {
    return usuarios_inscritos;
}

void Curso::baja() {
    --usuarios_inscritos;
}

bool Curso::leer(const Sesiones& sesiones) {
    int sesiones_iniciales;
    cin >> sesiones_iniciales;

    bool repetido;
    string id_sesion;
    repetido = false;
    for (int i = 0; i < sesiones_iniciales; ++i) {
        cin >> id_sesion;
        if (not repetido){
            repetido = not sesiones.agregar_problemas(problema_sesion, id_sesion);
            this->sesiones.push_back(id_sesion);
        }
    }
    nsesiones+=sesiones_iniciales;
    return not repetido;
}

void Curso::escribir_sesiones() const{
    for (int i=0;i<nsesiones;++i) {
        if (i<nsesiones-1)
            cout << sesiones[i] << " ";
        else cout << sesiones[i];
    }
}

void Curso::alta(const Sesiones& sesionesparametro, Usuario& usuario) {
    for (const string& sesion : this->sesiones) {
        sesionesparametro.agregar_problemas_enviables(usuario, sesion);
    }
    ++usuarios_inscritos;
}

int Curso::obtener_nsesiones() const {
    return nsesiones;
}

int Curso::obtener_superados() const{
    return usuarios_superados;
}

void Curso::nuevo_superado(){
    ++usuarios_superados;
}

