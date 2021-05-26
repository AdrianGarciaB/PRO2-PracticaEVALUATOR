/**
 * @mainpage Evaluator: Pagina principal.


La plataforma EVALUATOR integra: <br> - Una colección de Problemas de programación <br> - Un repositorio de Sesiones compuestas por problemas de dicha colección <br> - Un conjunto de Cursos formados por una o más sesiones <br> - Un conjunto de Usuarios registrados.


*/

/** @file program.cc
    @brief Programa principal

    <em>Aplicación para la gestion de problemas de programación </em>.
*/

#include "Usuarios.hh"
#include "Cursos.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#endif

int main() {
    Problemas problemas;
    Sesiones sesiones;
    Cursos cursos;
    Usuarios usuarios;

    problemas.leer();
    sesiones.leer();
    cursos.leer(sesiones);
    usuarios.leer();



    string comando;
    cin >> comando;
    while (comando != "fin"){
        if (comando == "nuevo_problema" or comando == "np") {
            string p;
            cin >> p;
            cout << "#" << comando << " " << p << endl;
            if (problemas.agregar(p))
                cout << problemas.getNproblemas() << endl;
            else
                cout << "error: el problema ya existe" << endl;
        }
        else if (comando == "nueva_sesion" or comando == "ns") {
            string s;
            cin >> s;
            cout << "#" <<comando << " " << s << endl;

            if (sesiones.agregar(s))
                cout << sesiones.getNsesiones() << endl;
            else
                cout << "error: la sesion ya existe" << endl;
        }
        else if (comando == "nuevo_curso" or comando == "nc") {
            cout << "#" <<comando  << endl;
            if (cursos.agregar(sesiones))
                cout << cursos.volumen() << endl;
            else
                cout << "error: curso mal formado" << endl;
        }
        else if (comando == "alta_usuario" or comando == "a") {
            string u;
            cin >> u;
            cout << "#" << comando << " " << u << endl;
            if (usuarios.alta(u))
                cout << usuarios.obtener_nusuariosregistrados() << endl;
            else
                cout << "error: el usuario ya existe" << endl;
        }
        else if (comando == "baja_usuario" or comando == "b") {
            string u;
            cin >> u;
            cout << "#" << comando << " " << u << endl;
            int id_curso;

            if (usuarios.baja(u, id_curso)) {
                cursos.baja(id_curso);
                cout << usuarios.obtener_nusuariosregistrados() << endl;
            }
            else cout << "error: el usuario no existe" << endl;
        }
        else if (comando == "inscribir_curso" or comando == "i") {
            string u;
            int c;
            cin >> u >> c;
            cout << "#" << comando << " " << u << " " << c << endl;
            bool existe_usuario;
            Usuario& usuario = usuarios.obtener_usuario(u, existe_usuario);
            if (existe_usuario){
                if (cursos.existe_curso(c)) {
                    if (not usuario.pertenece_curso()) {
                        usuario.inscribir_curso(c);
                        cursos.alta(sesiones, usuario);
                        if (not usuario.tiene_problemas_enviables()) { // El usuario ya ha resuelto el curso
                            cursos.baja(c);
                            cursos.nuevo_superado(c);
                            usuario.baja_curso();
                        }
                    }
                    else cout << "error: usuario inscrito en otro curso" << endl;
                }
                else cout << "error: el curso no existe" << endl;
            }
            else cout << "error: el usuario no existe" << endl;

        }
        else if (comando == "curso_usuario" or comando == "cu") {
            string u;
            cin >> u;
            cout << "#" << comando << " " << u << endl;
            bool existe_usuario;
            Usuario& usuario = usuarios.obtener_usuario(u, existe_usuario);
            if (existe_usuario) {
                cout << usuario.curso_inscrito() << endl;
            }
            else
                cout << "error: el usuario no existe" << endl;
        }
        else if (comando == "sesion_problema" or comando == "sp") {
            int c;
            string p;
            cin >> c >> p;
            cout << "#" << comando << " " << c << " " << p << endl;

            if (cursos.existe_curso(c)) {
                if (problemas.existe_problema(p)) {
                    string id_sesion;
                    if (cursos.obtener_nombre_sesion(c, p, id_sesion))
                        cout << id_sesion << endl;
                    else
                        cout << "error: el problema no pertenece al curso" << endl;
                }
                else cout << "error: el problema no existe" << endl;
            }
            else cout << "error: el curso no existe" << endl;
        }
        else if (comando == "problemas_resueltos" or comando == "pr") {
            string u;
            cin >> u;
            cout << "#" << comando << " " << u << endl;

            bool existe_usuario;
            Usuario& usuario = usuarios.obtener_usuario(u, existe_usuario);
            if (existe_usuario)
                usuario.escribir_problemas_resueltos();
            else
                cout << "error: el usuario no existe" << endl;
        }
        else if (comando == "problemas_enviables" or comando == "pe") {
            string u;
            cin >> u;
            cout << "#" << comando << " " << u << endl;

            bool existe_usuario;
            Usuario& usuario = usuarios.obtener_usuario(u, existe_usuario);
            if  (not existe_usuario)
                cout << "error: el usuario no existe" << endl;
            else if (not usuario.pertenece_curso())
                cout << "error: usuario no inscrito en ningun curso" << endl;
            else usuario.escribir_problemas_enviables();

        }
        else if (comando == "envio" or comando == "e") {
            string u, p;
            int r = 0;
            cin >> u >> p >> r;
            cout << "#" <<comando << " " << u << " " << p << ' '<< r << endl;

            problemas.agregar_envio(p, r);
            Usuario& usuario = usuarios.obtener_usuario(u);

            if (usuario.agregar_envio(p, r)){
                int c = usuario.curso_inscrito();
                string id_sesion;
                cursos.obtener_nombre_sesion(c, p, id_sesion);
                sesiones.agregar_problemas_enviables(usuario, id_sesion, p);

                if (not usuario.tiene_problemas_enviables()) {
                    cursos.baja(c);
                    cursos.nuevo_superado(c);
                    usuario.baja_curso();
                }
            }
        }
        else if (comando == "listar_problemas" or comando == "lp") {
            cout << "#" << comando << endl;
            problemas.listar_problemas();
        }
        else if (comando == "escribir_problema" or comando == "ep") {
            string p;
            cin >> p;
            cout << "#" << comando << " " << p << endl;
            if (not problemas.escribir_problema(p))
                cout << "error: el problema no existe" << endl;
        }
        else if (comando == "listar_sesiones" or comando == "ls") {
            cout << "#" << comando << endl;
            sesiones.listar_sesiones();
        }
        else if (comando == "escribir_sesion" or comando == "es") {
            string s;
            cin >> s;
            cout << "#" << comando << " " << s << endl;
            if (not sesiones.escribir_sesion(s))
                cout << "error: la sesion no existe" << endl;
        }
        else if (comando == "listar_cursos" or comando == "lc") {
            cout << "#" << comando << endl;
            cursos.listar_cursos();
        }
        else if (comando == "escribir_curso" or comando == "ec") {
            int c;
            cin >> c;
            cout << "#" << comando << " " << c << endl;
            if (not cursos.escribir_curso(c))
                cout << "error: el curso no existe" << endl;
        }
        else if (comando == "listar_usuarios" or comando == "lu") {
            cout << "#" << comando << endl;
            usuarios.listar_usuarios();
        }
        else if (comando == "escribir_usuario" or comando == "eu") {
            string u;
            cin >> u;
            cout << "#" << comando << " " << u << endl;

            if (not usuarios.escribir_usuario(u))
                cout << "error: el usuario no existe" << endl;
        }
        cin >> comando;
    }
}
