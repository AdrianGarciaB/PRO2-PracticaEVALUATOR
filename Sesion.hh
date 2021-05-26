/** @file Sesion.hh
    @brief Especificación de la clase Sesion
*/

#ifndef PRO2_EVALUATOR_SESION_HH
#define PRO2_EVALUATOR_SESION_HH

#include "Usuario.hh"
#include "Cjt_identificadores.hh"

#ifndef NO_DIAGRAM
#include <string>
#include <iostream>
#include <set>
#include "BinTree.hh"
#endif

using namespace std;

/** @class Sesion
    @brief Representa una sesion en la que se incluye diversos Problemas

    Se pueden agregar, leer y escribir problemas de la sesion, ademas de hacer un listado completo.
 */
class Sesion {
private:
    /** @brief Estructura de prerequisitos de los problemas */
    BinTree<string> prerequisitos_problemas;

    /** @brief Numero de problemas que contiene la sesion */
    int nproblemas;

    /** @brief Operación de lectura

        \pre <em>Los problemas no estan repetidos y pertenecen a la colección</em>
        \post Se lee una lista de prerequisitos de cada problema en preorden
    */
    void leer_prerequisitos_problema(BinTree<string> &arbol, const string& problema_valor);

    /** @brief Agrega los identificadores de Problema

          \pre <em>El usuario existe y el curso al que pertenece tiene a esta sesion en la lista de sesiones.</em>
          \post Al usuario se le asignan los problemas que pueden enviar a partir de la estructura de prerequisitos
     */
    void agregar_problemas_enviables(const BinTree<string> &arbol, Usuario& usuario) const;

    /** @brief Agrega los identificadores de Problema

          \pre <em>El usuario existe y el curso al que pertenece tiene a esta sesion en la lista de sesiones.</em>
          \post Al usuario se le asignan los problemas que pueden enviar a partir de los prerequisitos del problema P,
                se retorna cierto si se ha añadido al menos un Problema, en otro caso retorna falso
     */
    bool agregar_problemas_enviables(const BinTree<string> &arbol, Usuario& usuario, const string& p) const;

    /** @brief Agrega los identificadores que relaciona cada problema (De la estructura de prerequisitos) con su sesion al conjunto de identificadores

         \pre <em>cierto</em>
         \post Se agrega al conjunto de identificadores los identificadores de los problemas con el identificador de esta sesion.
    */
    bool agregar_problemas(Cjt_identificadores& ids, const string& s, const BinTree<string> &arbol) const;

    /** @brief Comprueba si el problema existe en los prerequisitos.

        \pre <em>cierto</em>
        \post Retorna cierto si el problema se encuentra en la sesion, en caso contrario falso.
    */
    bool existe_problema(const string &s, const BinTree<string> &prerequisitos) const;

    /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Se escribe por el canal estandar de salida su estructura de prerequisitos en postorden
    */
    void escribir_prerequisitos(const BinTree<string> &arbol) const;


public:
    // Constructora
    /** @brief Creadora por defecto.

        \pre <em>cierto</em>
        \post El resultado es una sesion vacia.
    */
    Sesion();


    // Consultoras
    /** @brief Obtiene el numero de problemas de la sesion

        \pre <em>cierto</em>
        \post Retorna el numero de problemas de la sesion
    */
    int obtener_nproblemas() const;

    /** @brief Comprueba si el problema existe en la sesion.

        \pre <em>cierto</em>
        \post Retorna cierto si el problema se encuentra en la sesion, en caso contrario falso.
    */
    bool existe_problema(const string &s) const;


    // Modificadoras
    /** @brief Agrega los problemas que el usuario puede enviar

          \pre <em>El usuario existe y el curso al que pertenece tiene a esta sesion en su lista de sesiones.</em>
          \post Al usuario se le asignan los problemas que pueden enviar
     */
    void agregar_problemas_enviables(Usuario &usuario) const;

    /** @brief Agrega los problemas que el usuario puede enviar

          \pre <em>El usuario existe y el curso al que pertenece tiene a esta sesion en la lista de sesiones.</em>
          \post Al usuario se le asignan los problemas que pueden enviar a partir de los prerequisitos del problema P
     */
    void agregar_problemas_enviables(Usuario &usuario, const string& P) const;

    /** @brief Agrega los identificadores que relaciona cada problema con su sesion al conjunto de identificadores

          \pre <em>cierto</em>
          \post Se agrega al conjunto de identificadores los identificadores de los problemas con el identificador de esta sesion.
     */
    bool agregar_problemas(Cjt_identificadores &identificadores, const string& s) const;

    // Entrada / Salida
    /** @brief Operación de lectura

        \pre <em>Los problemas no estan repetidos y pertenecen a la colección</em>
        \post Se lee una lista de prerequisitos de cada problema en preorden
    */
    void leer();

    /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Se escribe por el canal estandar de salida el numero de problemas que la forman y su estructura de prerequisitos en postorden
    */
    void escribir() const;

};

#endif //PRO2_EVALUATOR_SESION_HH
