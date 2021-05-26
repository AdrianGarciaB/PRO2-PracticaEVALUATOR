/** @file Curso.hh
    @brief Especificación de la clase Curso
*/

#ifndef PRO2_EVALUATOR_CURSO_HH
#define PRO2_EVALUATOR_CURSO_HH

#ifndef NO_DIAGRAM
#include <string>
#include <vector>
#endif


#include "Sesiones.hh"
#include "Usuario.hh"
#include "Cjt_identificadores.hh"

using namespace std;

/** @class Curso
    @brief Representa un curso con un subconjunto de sesiones.

    Se puede consultar una sesion, el numero de participantes de un curso y procesar una baja de usuario.
 */
class Curso {
private:
    /** @brief Conjunto de identificadores de las sesiones */
    vector<string> sesiones;

    /** @brief Conjunto de identificadores que relaciona un problema -> sesion */
    Cjt_identificadores problema_sesion;

    /** @brief Numero de sesiones del curso */
    int nsesiones;

    /** @brief Numero de usuarios inscritos al curso */
    int usuarios_inscritos;

    /** @brief Numero de usuarios que han superado el curso */
    int usuarios_superados;

public:
    // Constructora
    /** @brief Creadora por defecto

        \pre <em>cierto</em>
        \post El resultado es un curso vacio
    */
    Curso();


    // Consultoras
    /** @brief Consultora de una sesion

        \pre <em>El identificador del problema existe y el problema unicamente aparece en una sesion.</em>
        \post Retorna cierto si el programa pertenece a una sesion del subconjunto y identificador_problema se modifica con el identificador de la sesion encontrada, si no existe retorna falso y identificador_problema no se altera.
    */
    bool obtener_nombre_sesion(const string& id_problema, string& identificador_sesion) const;

    /** @brief Consultora del numero de inscritos al curso

        \pre <em>El numero de inscritos se encuentra inicializado</em>
        \post Retorna el numero de usuarios que estan inscritos al curso
    */
    int obtener_inscritos() const;

    /** @brief Consultora del numero de superados del curso

        \pre <em>cierto</em>
        \post Retorna el numero de usuarios que han superado el curso
     */
    int obtener_superados() const;

    /** @brief Consultora del numero de sesiones del curso

        \pre <em>cierto</em>
        \post Retorna el numero de sesiones del curso
     */
    int obtener_nsesiones() const;


    // Modificadoras

    /** @brief Agrega los problemas enviables del curso a un usuario y da de alta al usuario

        \pre <em>El usuario pertenece al curso</em>
        \post Se agregan los problemas que puede resolver el usuario y se incrementa los usuarios inscritos al curso en una unidad.
    */
    void alta(const Sesiones& sesionesparametro, Usuario& usuario);

    /** @brief Da de baja a un usuario del curso.

        \pre <em>cierto</em>
        \post El numero de usuarios inscritos se decrementa una unidad.
    */
    void baja();

    /** @brief Aumenta el numero de usuarios que han superado el curso

        \pre <em>cierto</em>
        \post El numero de usuarios que han pasado el curso se incrementa una unidad.
    */
    void nuevo_superado();

    // Entrada / Salida

    /** @brief Operación de lectura

        \pre <em>Numero de sesiones iniciales>0, las sesiones no contienen problemas en comun</em>
        \post Se leen un conjunto de identificadores de sesiones provenientes del canal estandar de entrada
    */
    bool leer(const Sesiones& sesiones);

    /** @brief Operación de Escritura

        \pre <em>cierto</em>
        \post Se escribe por el canal estandar de salida los identificadores del conjunto de sesiones del curso, en el mismo orden que se leyeron cuando se creó este.
    */
    void escribir_sesiones() const;

};

#endif //PRO2_EVALUATOR_CURSO_HH
