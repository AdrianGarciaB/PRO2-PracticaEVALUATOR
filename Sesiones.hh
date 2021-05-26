/** @file Sesiones.hh
    @brief Especificación de la clase Sesiones
*/
#ifndef PRO2_EVALUATOR_SESIONES_HH
#define PRO2_EVALUATOR_SESIONES_HH

#include "Sesion.hh"
#include "Problemas.hh"

#ifndef NO_DIAGRAM
#include <string>
#include "Cjt_identificadores.hh"
#endif


using namespace std;

/** @class Sesiones
    @brief Representa una colección de Sesion, donde cada sesion se relaciona con determinados Problemas

    Se pueden agregar, leer y escribir sesiones ademas de hacer un listado completo.
 */
class Sesiones {
private:
    /** @brief Conjunto de sesiones */
    map<string, Sesion> sesiones;

    /** @brief Numero de sesiones en el conjunto */
    int nsesiones;

public:
    // Constructoras
    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar las sesiones.
        \pre <em>cierto</em>
        \post El resultado es una coleción de sesiones vacia.
    */
    Sesiones();

    // Consultoras

    /** @brief Consultora del numero de sesiones

        \pre <em>Numero de sesiones>0, conjunto de sesiones sin repeticiones</em>
        \post Se leen un conjunto de sesiones provenientes del canal estandar de entrada
    */
    int getNsesiones() const;


    // Modificadoras
    /** @brief Agrega los problemas que el usuario puede enviar de una sesion S

          \pre <em>El usuario existe y el curso al que pertenece tiene a esta en la lista de sesiones.</em>
          \post Al usuario se le asignan los problemas que pueden enviar
     */
    void agregar_problemas_enviables(Usuario &usuario,const string& S) const;

    /** @brief Agrega los problemas que el usuario puede enviar de una sesion S

          \pre <em>El usuario existe y el curso al que pertenece tiene a esta en la lista de sesiones.</em>
          \post Al usuario se le asignan los problemas que pueden enviar a partir de los prerequisitos del problema P
     */
    void agregar_problemas_enviables(Usuario &usuario,const string& S, const string& P) const;

    /** @brief Agrega los identificadores que relaciona cada problema con su sesion S al conjunto de identificadores

          \pre <em>cierto</em>
          \post Se agrega al conjunto de identificadores los identificadores de los problemas con el identificador de esta sesion.
     */
    bool agregar_problemas(Cjt_identificadores& identificadores, const string& S) const;


    // Entrada y salida
    /** @brief Lectura del conjunto de sesiones

      \pre <em>Numero de sesiones>0, conjunto de sesiones con identificadores validos y sin repeticiones</em>
      \post Se leen un conjunto de sesiones provenientes del canal estandar de entrada
    */
    void leer();

    /** @brief Se lee una sesion predefinida con los identificadores de los problemas.

          \pre <em>Los identificadores corresponden a problemas existentes y no estan repetidos.</em>
          \post Devuelve cierto cuando se agrega el problema a la colección si este no existia, en caso de que exista devuelve falso.
     */
    bool agregar(string s);

    /** @brief Operación de escritura

        \pre <em>cierto</em>
        \post Se escribe por el canal estandar de salida el listado de las sesiones en orden creciente por su identificador.
        Para cada sesion se muestra el numero de problemas que la forman y sus identificadores, seguido de su estructura de prerequisitos en postorden.
    */
    void listar_sesiones() const;

    /** @brief Operación de escritura

      \pre <em>cierto</em>
      \post Retorna cierto si la sesion existe y se escribe por el canal estandar de salida
      el numero de problemas que la forman y sus identificadores, seguido de su estructura de prerequisitos en postorden. Si la sesion no existe devuelve falso.
    */
    bool escribir_sesion(const string& s) const;


};

#endif //PRO2_EVALUATOR_SESIONES_HH
