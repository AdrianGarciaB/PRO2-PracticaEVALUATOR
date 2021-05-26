/** @file Cursos.hh
    @brief Especificación de la clase Cursos
*/
#ifndef PRO2_EVALUATOR_CURSOS_HH
#define PRO2_EVALUATOR_CURSOS_HH

#include "Curso.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#endif


/** @class Cursos
    @brief Representa una colección de Curso donde cada curso se relaciona con una determinada cantidad de Sesiones

    Se pueden agregar, leer, escribir y obtener cursos ademas de hacer un listado completo.
 */
class Cursos {
private:
    /** @brief Numero de cursos de la colección */
    int ncursos;
    /** @brief Colección de Curso donde el primer elemento es el curso vacio y los siguientes inesimos cursos hasta ncursos son los de la colección. */
    vector<Curso> cursos;

public:
    // Constructora
    /** @brief Creadora por defecto.
        \pre cierto
        \post El resultado es una coleción de cursos vacia.
    */
    Cursos();


    // Consultoras
    /** @brief Consultora del numero de cursos de la colección
        \pre cierto</em>
        \post Retorna el numero de cursos de la colección
    */
    int volumen() const;

    /** @brief Consultora Si el curso esta en el conjunto

        \pre <em>El parámetro implícito C está inicializado</em>
        \post Se escribe por el canal estandar de salida la información sobre el curso
        De este se muestra el numero de usuarios que ha completado el curso, usuarios inscritos actualmente, el numero de sesiones que lo forman junto a sus identificadores en el mismo orden que se leyeron cuando se creó el curso.
    */
    bool existe_curso(const int& C) const;

    /** @brief Consultora a que problema pertenece la sesion del curso especificado.

        \pre <em>El parámetro implícito C está inicializado</em>
        \post El resultado indica si el problema se encuentra en las sesiones del curso, de ser asi el parametro implicito s pasa a tener el identificador de la sesion donde pertenece el problema, en otro caso se retorna falso.
    */
    bool obtener_nombre_sesion(const int& C, const string& p, string& s) const;


    // Modificadoras
        /** @brief Agrega los problemas enviables del curso a un usuario y da de alta al usuario al curso.

        \pre <em>El usuario pertenece a un curso</em>
        \post Se agregan los problemas que puede resolver el usuario
    */
    void alta(const Sesiones& sesiones, Usuario& usuario);

    /** @brief Da de baja a un usuario del curso C.

        \pre <em>cierto</em>
        \post El numero de usuarios inscritos se decrementa una unidad.
    */
    void baja(const int& C);

    /** @brief Aumenta el numero de usuarios que han superado el curso C

        \pre <em>cierto</em>
        \post El numero de usuarios que han pasado el curso C se incrementa una unidad.
    */
    void nuevo_superado(const int& C);


    // Entrada / Salida
    /** @brief Operación de lectura

        \pre <em>Numero de curso iniciales>0, por cada curso, sus conjuntos de sesiones no contienen problemas en comun</em>
        \post Se leen un conjunto de cursos provenientes del canal estandar de entrada
    */
    void leer(const Sesiones& sesiones);

    /** @brief Operación de lectura

        \pre <em>Cada sesion del conjunto sesiones a leer y problema existen en sus respectivos conjuntos y no se encuentran repetidos.</em>
        \post Retorna cierto si agrega el curso a la colección
         En otro caso retorna falso.
    */
    bool agregar(const Sesiones& sesiones);

    /** @brief Operación de escritura

        \pre <em>cierto</em>
        \post Se escribe por el canal estandar de salida el listado de cursos en orden creciente por su identificador.
        Para cada curso se muestra el numero de usuarios que ha completado el curso, usuarios inscritos actualmente, el numero de sesiones que lo forman junto a sus identificadores en el mismo orden que se leyeron cuando se creó el curso.
    */
    void listar_cursos() const;

    /** @brief Operación de escritura

        \pre <em>cierto</em>
        \post Se escribe por el canal estandar de salida la información sobre el curso C
        Se escribe el numero de usuarios que ha completado el curso, usuarios inscritos actualmente, el numero de sesiones que lo forman junto a sus identificadores en el mismo orden que se leyeron cuando se creó el curso.
    */
    bool escribir_curso(const int& C) const;

};
#endif //PRO2_EVALUATOR_CURSOS_HH
