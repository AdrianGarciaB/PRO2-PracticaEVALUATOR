/** @file Usuarios.hh
    @brief Especificación de la clase Usuarios
*/
#ifndef PRO2_EVALUATOR_USUARIOS_HH
#define PRO2_EVALUATOR_USUARIOS_HH


#include "Usuario.hh"

#ifndef NO_DIAGRAM
#include <string>
#include <map>
#include <iostream>
#endif


using namespace std;

/** @class Usuarios
    @brief Representa una colección de Usuario

    Se pueden dar de alta, baja, leer, obtener usuarios, ademas de obtener un listado de estos.
 */
class Usuarios {
private:
    /** @brief Colección de Usuarios */
    map<string, Usuario> usuarios;

    /** @brief Usuario vacio */
    Usuario usuario_vacio;

    /** @brief Numero de usuarios registrados */
    int nregistrados;

public:
    Usuarios();
    // Consultoras
    /** @brief Consulta sobre un usuario

        \pre <em>El usuario existe</em>
        \post Retorna el usuario U
    */
    Usuario& obtener_usuario(const string& U);

    /** @brief Consulta sobre un usuario

       \pre <em>Cierto</em>
       \post Retorna el usuario con el identificador U en caso de que exista, de ser asi el parametro control sera cierto, en caso contrario falso.
   */
    Usuario& obtener_usuario(const string& U, bool& existe);

    /** @brief Consulta sobre el numero de usuarios.

        \pre <em>El numero de usuarios se encuentra inicializado</em>
        \post Retorna el numero de usuarios actuales.
    */
    int obtener_nusuariosregistrados() const;


    // Modificadoras
    /** @brief Da de alta a un usuario

        \pre <em>Cierto</em>
        \post Retorna cierto si el usuario ha sido dado de alta, si este ya existia retorna falso.
    */
    bool alta(const string&);

    /** @brief Da de baja a un usuario de un curso

        \pre <em>Cierto</em>
        \post Retorna cierto si el usuario ha sido dado de baja del curso y C valdra el identificador del curso al que pertenecia el usuario, si este no existe o no pertenece a un curso retorna falso.
    */
    bool baja(const string&, int& C);


    // Entrada / Salida
    /** @brief Agregar un conjunto de usuarios

        \pre <em>Los usuarios se encuentran registrados</em>
        \post Se leen un conjunto de usuarios provenientes del canal estandar de entrada
    */
    void leer();

    /** @brief Se listan los usuarios de la colección

        \pre <em>cierto</em>
        \post Se escribe por el canal estandar de salida el listado de usuarios en orden creciente por su nombre,
        Para cada usuario se indica su numero de envios totales, problemas resueltos y su identificador del curso al que pertenece, se indicara un 0 en caso de no estar inscrito en ningun curso.
    */
    void listar_usuarios() const;

    /** @brief Se listan los usuarios de la colección

        \pre <em>cierto</em>
        \post Se escribe por el canal estandar de salida la información de un usuario con identificador s,
        Se indica su numero de envios totales, problemas resueltos y su identificador del curso al que pertenece, se indicara un 0 en caso de no estar inscrito en ningun curso.
    */
    bool escribir_usuario(const string& s) const;

};


#endif //PRO2_EVALUATOR_USUARIOS_HH
