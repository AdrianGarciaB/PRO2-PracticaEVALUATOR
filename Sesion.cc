/** @file Sesion.cc
    @brief Codigo de la clase Sesion
*/

#include "Sesion.hh"

Sesion::Sesion() {
    nproblemas=0;
}


void Sesion::leer() {
    string problema_inicial;
    cin >> problema_inicial;
    leer_prerequisitos_problema(prerequisitos_problemas, problema_inicial);
}

void Sesion::leer_prerequisitos_problema(BinTree<string> &arbol, const string& problema_valor) {
    if (problema_valor != "0"){
        ++nproblemas;
        string valor;
        cin >> valor;
        BinTree<string> l;
        leer_prerequisitos_problema(l,valor);
        BinTree<string> r;
        cin >> valor;
        leer_prerequisitos_problema(r,valor);
        arbol=BinTree<string>(problema_valor, l,r);
    }
}


bool Sesion::existe_problema(const string &p) const{
    return existe_problema(p, prerequisitos_problemas);
}

bool Sesion::existe_problema(const string &p, const BinTree<string> &arbol) const {
    if (not arbol.empty()) {
        if (arbol.value() == p)
            return true;
        return existe_problema(p, arbol.left()) or existe_problema(p, arbol.right());
    }
    return false;
}

int Sesion::obtener_nproblemas() const {
    return nproblemas;
}



void Sesion::escribir_prerequisitos(const BinTree<string> &arbol) const {
    if (not arbol.empty()) {
        cout << "(";
        escribir_prerequisitos(arbol.left());
        escribir_prerequisitos(arbol.right());
        cout << arbol.value() << ")";
    }
}

void Sesion::agregar_problemas_enviables(Usuario &usuario) const {
    agregar_problemas_enviables(prerequisitos_problemas, usuario);
}

void Sesion::agregar_problemas_enviables(Usuario &usuario, const string &p) const {
    agregar_problemas_enviables(prerequisitos_problemas, usuario, p);
}

void Sesion::agregar_problemas_enviables(const BinTree<string> &arbol, Usuario& usuario) const{
    if (not arbol.empty()) {
        if (not usuario.problema_resuelto(arbol.value())) {
            usuario.agregar_problema_enviable(arbol.value());
        }
        else
            agregar_problemas_enviables(arbol, usuario, arbol.value());
    }
}

bool Sesion::agregar_problemas_enviables(const BinTree<string> &arbol, Usuario &usuario, const string &p) const{
    if (not arbol.empty()) {
        if (arbol.value() == p) {
            bool nuevo_problema = false;
            if (not usuario.problema_resuelto(p)){
                usuario.agregar_problema_enviable(p);
                nuevo_problema = true;
            }
            else {
                    if (not arbol.left().empty()) {
                        nuevo_problema = agregar_problemas_enviables(arbol.left(), usuario, arbol.left().value());
                    }
                    if (not arbol.right().empty()) {
                        nuevo_problema = agregar_problemas_enviables(arbol.right(), usuario, arbol.right().value()) or nuevo_problema;
                    }
            }
            return nuevo_problema;
        }
        else
            return agregar_problemas_enviables(arbol.left(), usuario, p) or agregar_problemas_enviables(arbol.right(), usuario, p);
    }
    return false;
}

bool Sesion::agregar_problemas(Cjt_identificadores &identificadores, const string& s) const {
    return agregar_problemas(identificadores, s, prerequisitos_problemas);
}

bool Sesion::agregar_problemas(Cjt_identificadores &ids, const string& s, const BinTree<string> &arbol) const{
    if (not arbol.empty()){
        bool existe_problema = not ids.insertar({arbol.value(), s});

        if (existe_problema)
            return false;

        return agregar_problemas(ids, s, arbol.left()) and agregar_problemas(ids, s, arbol.right());

    }
    return true;
}

void Sesion::escribir() const {
    cout << nproblemas << " ";
    escribir_prerequisitos(prerequisitos_problemas);
    cout << endl;
}

