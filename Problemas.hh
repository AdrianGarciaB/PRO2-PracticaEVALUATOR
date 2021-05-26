/** @file Problemas.hh
    @brief Especificación de la clase Problemas
*/

#ifndef PRO2_EVALUATOR_PROBLEMAS_HH
#define PRO2_EVALUATOR_PROBLEMAS_HH

#ifndef NO_DIAGRAM
#include <string>
#include <iostream>
#include <map>
#include <set>
#endif


using namespace std;

/** @class Problemas
    @brief Representa una colección de Problema

    Se pueden agregar, leer y escribir problemas ademas de hacer un listado completo.
 */
class Problemas {
private:
    /** @brief Representación de un Problema */
    struct Problema {
        int intentos, aciertos;
        double ratio;
    };

    /** @brief Comparador para la ordenación de Problema */
    struct Comparador {
        /** @brief Comparador de Problema
            \pre <em>cierto</em>
            \post Se comparan los problemas por ratio ascendente, si estos son iguales se ordena por el identificador en orden ascendiente
        */
        bool operator()(const pair<string,Problema>& a, const pair<string,Problema>& b) const{
            if (a.second.ratio != b.second.ratio)
                return a.second.ratio < b.second.ratio;
            return a.first < b.first;
        }
    };

    /** @brief Conjunto de problemas */
    map<string, Problema> listado_problemas;

    /** @brief Numero de problemas de la colección */
    int nproblemas;

public:
    // Constructoras
    /** @brief Creadora por defecto.

        Se ejecuta automáticamente al declarar los Problemas.
        \pre <em>cierto</em>
        \post El resultado es una colección de problemas vacia.
    */
    Problemas();


    // Consultoras
    /** @brief Consultora del numero de Problemas de la colección

        \pre <em>El parámetro implícito está inicializado</em>
        \post Devuelve el numero de problemas.
    */
    int getNproblemas() const;

    /** @brief Consultora que comprueba si existe un problema en la colección

        \pre <em>cierto</em>
        \post Devuelve cierto si este problema existe, en caso contrario devuelve falso.
    */
    bool existe_problema(const string& p) const;


    // Modificadoras
    /** @brief Agrega un problema a la colección

        \pre <em>cierto</em>
        \post Devuelve cierto cuando se agrega el problema a la colección si este no existia, en caso de que exista devuelve falso.
    */
    bool agregar(const string& p);

    /** @brief Agrega un envio a un problema

       \pre <em>El problema se encuentra en la colección</em>
       \post Agrega un envio al problema.
   */
    void agregar_envio(const string& p, const int& r);


    // Entrada y Salida
    /** @brief Agregar un conjunto de problemas

        \pre <em>Conjunto de problemas sin repeticiones</em>
        \post Se leen un conjunto de problemas provenientes del canal estandar de entrada
    */
    void leer();

    /** @brief Se listan los problemas de la colección

        \pre <em>cierto</em>
        \post Se escribe por el canal estandar de salida el listado de problemas en orden creciente por el ratio actualizado,
        en caso de empate se lista por identificador en orden creciente.
        Para cada problema se indica su numero de envios totales junto al numero de envios con exito y el ratio (envios_totales+1/envios_exito+1)
    */
    void listar_problemas();

    /** @brief Se escribe un problema de la colección

        \pre <em>cierto</em>
        \post Retorna cierto si el problema existe y se escribe por el canal estandar de salida la información del problema
        sobre su numero de envios totales junto al numero de envios con exito y el ratio (envios_totales+1/envios_exito+1).

        Si el problema no existe devuelve falso.
    */
    bool escribir_problema(const string& p) const;

};
#endif
