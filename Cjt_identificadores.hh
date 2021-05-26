/** @file Cjt_identificadores.hh
    @brief Especificación de la clase Cjt_identificadores
*/

#ifndef PRO2_EVALUATOR_CJT_IDENTIFICADORES_HH
#define PRO2_EVALUATOR_CJT_IDENTIFICADORES_HH

#ifndef NO_DIAGRAM
#include <string>
#include <map>
#endif

using namespace std;

/** @class Cjt_identificadores
    @brief Representa un conjunto de parejas de identificadores

    En este conjunto, se pueden agregar pares, obtener los elementos y consultar su volumen.
 */
class Cjt_identificadores {
private:
    /** @brief Colección de parejas de identificadores */
    map<string, string> cjt;

public:
    // Constructora
    /** @brief Constructora por defecto

        \pre <em>cierto</em>
        \post El resultado es una colección de identificadores vacia.
    */
    Cjt_identificadores();


    // Consultoras
    /** @brief Consultora del valor de un identificador

        \pre <em>cierto</em>
        \post Retorna si K pertenece al conjunto, el segundo identificador con el cual esta relacionado,
              en caso contrario se retorna un identificador vacio.
    */
    string obtener_elemento(const string& K) const;

    /** @brief Consultora del tamaño del conjunto de identificadores.

        \pre <em>cierto</em>
        \post Retorna el numero de pares que hay en el conjunto.
    */
    int obtener_volumen() const;


    // Modificadoras
    /** @brief Consulta sobre el numero de usuarios.

        \pre <em>El numero de usuarios se encuentra inicializado</em>
        \post Retorna el numero de usuarios actuales.
    */
    bool insertar(pair<string, string> p);

};


#endif //PRO2_EVALUATOR_CJT_IDENTIFICADORES_HH
