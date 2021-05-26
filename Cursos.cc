/** @file Cursos.cc
    @brief Código de la clase Cursos
*/

#include "Cursos.hh"

Cursos::Cursos() {
    ncursos = 0;
}

int Cursos::volumen() const {
    return ncursos;
}

bool Cursos::existe_curso(const int& c) const {
    return c > 0 and c <= ncursos;
}

bool Cursos::obtener_nombre_sesion(const int& c, const string& p, string& s) const{
    return cursos.at(c).obtener_nombre_sesion(p, s);
}



void Cursos::alta(const Sesiones& sesiones, Usuario& usuario) {
    cursos[usuario.curso_inscrito()].alta(sesiones, usuario);
    cout << cursos[usuario.curso_inscrito()].obtener_inscritos() << endl;
}

void Cursos::baja(const int& c) {
    cursos[c].baja();
}

void Cursos::nuevo_superado(const int& c) {
    cursos[c].nuevo_superado();
}

void Cursos::leer(const Sesiones& sesiones) {
    int cursos_iniciales;
    cin >> cursos_iniciales;

    cursos = vector<Curso>(cursos_iniciales+1);
    cursos[0]; // Inicializamos el curso vacio.

    for (int i = 1; i <= cursos_iniciales; ++i) {
         cursos[i].leer(sesiones);
    }
    ncursos += cursos_iniciales;
}

bool Cursos::agregar(const Sesiones& sesiones) {
    Curso curso;
    bool repetido = not curso.leer(sesiones);

    if (not repetido) {
        cursos.push_back(curso);
        ++ncursos;
    }
    return not repetido;
}


void Cursos::listar_cursos() const{
    for (int i=1;i<=ncursos;++i){
        Curso curso = cursos[i];
        cout << i << ' ' << curso.obtener_superados() << ' ' << cursos[i].obtener_inscritos() << " " << cursos[i].obtener_nsesiones() << " (";
        cursos[i].escribir_sesiones();
        cout << ")" << endl;
    }
}

bool Cursos::escribir_curso(const int& c) const {
    if (existe_curso(c)) {
        cout << c << ' ' << cursos[c].obtener_superados() << ' ' << cursos[c].obtener_inscritos() << " " << cursos[c].obtener_nsesiones() <<" (";
        cursos[c].escribir_sesiones();
        cout << ")" << endl;
        return true;
    }
    return false;
}
