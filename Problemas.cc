/** @file Problemas.cc
    @brief Codigo de la clase Problemas
*/

#include "Problemas.hh"
// Se ha debido de eliminar los .find() ya que
Problemas::Problemas() {
    nproblemas = 0;
}

int Problemas::getNproblemas() const {
    return nproblemas;
}

bool Problemas::existe_problema(const string& p) const {
    return listado_problemas.find(p) != listado_problemas.end();
}

void Problemas::leer() {
    int problemas_iniciales;
    cin >> problemas_iniciales;
    for (int i=0; i < problemas_iniciales; ++i) {
        string identificador_problema;
        cin >> identificador_problema;
        listado_problemas[identificador_problema];
    }
    nproblemas += problemas_iniciales;
}

bool Problemas::agregar(const string& p) {
    auto it = listado_problemas.insert({p, Problema()});
    if (it.second)
        ++nproblemas;
    return it.second;
}

void Problemas::listar_problemas() {
    set <pair<string, Problema>, Comparador> listado_problemas_ordenado;   // NOTA: Se ha considerado usar otra estructura de datos para su ordenación debido a la eficiencia y a que la implementación
                                                                        // de un comparador en el map no permitia la ordenacion por ratio ya que se trata de un valor y solo permite la ordenación por clave.
    auto it = listado_problemas.begin();
    while (it != listado_problemas.end()){
        it->second.ratio = (double) (1+it->second.intentos)/(1+it->second.aciertos);
        listado_problemas_ordenado.insert(make_pair(it->first, it->second));
        ++it;
    }
    auto it2 = listado_problemas_ordenado.begin();
    while (it2 != listado_problemas_ordenado.end()){
        cout << it2->first << '(' << it2->second.intentos<< ',' << it2->second.aciertos << ',' << (it2->second.ratio) << ')' << endl;
        ++it2;
    }
}

bool Problemas::escribir_problema(const string& p) const {
    auto it = listado_problemas.begin();
    while (it != listado_problemas.end()) {
        if (it->first == p){
            cout << it->first << '(' << it->second.intentos<< ',' << it->second.aciertos << ',' << (double) (1+it->second.intentos)/(1+it->second.aciertos) << ')' << endl;
            return true;
        }
        ++it;
    }
    return false;

}

void Problemas::agregar_envio(const string &p, const int &r) {
    Problema& envio = listado_problemas.at(p);
    ++envio.intentos;
    if (r==1)
        ++envio.aciertos;
}

