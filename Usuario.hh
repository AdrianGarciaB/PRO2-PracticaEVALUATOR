/** @file Usuario.hh
    @brief Especificación de la clase Usuario
*/

#ifndef PRO2_EVALUATOR_USUARIO_HH
#define PRO2_EVALUATOR_USUARIO_HH

#ifndef NO_DIAGRAM
#include <string>
#include <map>
#include <iostream>
#endif

using namespace std;

/** @class Usuario
    @brief Representa un usuario

    Se puede consultar al curso al que pertenece, si esta inscrito en un curso, agregar envios y listar sus problemas resueltos o enviables.
 */
class Usuario {
private:
  /** @brief Identificador del curso. */
  int id_curso;

  /** @brief Numero de envios realizados. */
  int nenvios_realizados;

  /** @brief Numero de problemas resueltos. */
  int nproblemas_intentados;

  /** @brief Numero de problemas resueltos. */
  int nproblemas_resueltos;

  /** @brief Estructura de Problema. */
  struct Envio {
      /** @brief Numero de intentos. */
      int intentos;

      /** @brief Numero de fallos. */
      int fallidos;
  };

  /** @brief Colección de problemas enviables. */
  map<string, Envio> problemas_enviables;

    /** @brief Colección de problemas resueltos. */
  map<string, Envio> problemas_resueltos;


public:
  // Constructora
  /** @brief Creadora por defecto.

      Se ejecuta automáticamente al declarar el usuario.
      \pre <em>cierto</em>
      \post El resultado es un usuario vacio.
  */
    Usuario();


    // Consultora
    /** @brief Consultora del curso al que esta inscrito el usuario

        \pre <em>El usuario esta inscrito a un curso</em>
        \post Retorna cierto si el usuario pertenece algun curso, en caso contrario retorna falso.
    */
    int curso_inscrito() const;

    /** @brief Consultora si el usuario esta inscrito a un curso.

        \pre <em>cierto</em>
        \post Retorna cierto si el usuario pertenece algun curso, en caso contrario retorna falso.
    */
    bool pertenece_curso() const;

    /** @brief Consultora del numero de envios realizados

        \pre <em>cierto</em>
        \post Retorna el numero de envios que ha realizado el usuario
    */
    int obtener_nenviosrealizados() const;

    /** @brief Consultora del numero de problemas resueltos

        \pre <em>cierto</em>
        \post Retorna el numero de problemas resueltos del usuario
    */
    int obtener_nproblemasresueltos() const;

    /** @brief Consultora del numero de problemas resueltos

        \pre <em>cierto</em>
        \post Retorna el numero de problemas intentados del usuario que aun no ha resuelto
    */
    int obtener_nproblemas_intentados() const;

    /** @brief Consultora si el usuario ha resuelto el Problema P

        \pre <em>cierto</em>
        \post Retorna cierto si el usuario ha resuelto el Problema, en caso contrario falso.
    */
    bool problema_resuelto(const string &P) const;

    /** @brief Consultora si el usuario tiene problemas que puede realizar envios

        \pre <em>cierto</em>
        \post Retorna cierto si el usuario tiene problemas al que puede realizar envios, en caso contrario falso
    */
    bool tiene_problemas_enviables() const;

    // Modificadora
    /** @brief Inscribe al usuario al curso C

        \pre El usuario no pertenece a ningun curso
        \post El usuario es incrito al curso C
    */
    void inscribir_curso(const int& C);

    /** @brief Da de baja al usuario del curso

        \pre cierto
        \post El usuario se da de baja del curso
    */
    void baja_curso();

    /** @brief Agrega al usuario el identificador del Problema P al que puede realizar envios.

        \pre El usuario no ha resuelto el problema P y cumple todos los prerequisitos
        \post Se le agrega al usuario el problema P al que puede realizar envios
    */
    void agregar_problema_enviable(const string& p);

    /** @brief Agrega al usuario un envio de un problema.

        \pre El usuario puede realizar un envio a P
        \post El usuario realiza un envio a P y se incrementa su numero de intentos,
            si el envio es exitoso pasa a estar resuelto y se retorna cierto en caso contrario se incrementa su numero de fallos en una unidad y se retorna falso.
    */
    bool agregar_envio(const string& p, const int& r);


    // Escritura de Usuario
    /** @brief Operación de escritura

        \pre <em>cierto</em>
        \post Se escribe por el canal estandar de salida el listado de los problemas resueltos en orden creciente por su identificador.
        Se listan todos los problemas que ha resuelto el usuario en el curso inscrito y en otros cursos anteriores junto a su numero de envios realizados a cada uno de ellos.
    */
    void escribir_problemas_resueltos() const;

    /** @brief Operación de escritura

        \pre <em>cierto</em>
        \post Se escribe por el canal estandar de salida el listado de los problemas que puede enviar el usuario en orden creciente por su identificador.
        Se listan todos los problemas que el usuario aun no ha resuelto en el curso que esta inscrito y cumple los prerequisitos para resolverlo.
    */
    void escribir_problemas_enviables() const;


    /** @brief Operación de escritura

        \pre <em>El curso existe</em>
        \post Assigna al usuario el identificador del curso al que esta inscrito.
    */


};

#endif //PRO2_EVALUATOR_USUARIO_HH
