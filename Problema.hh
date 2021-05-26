//
// Created by Usuario on 30/04/2021.
//

#ifndef PRO2_EVALUATOR_PROBLEMA_HH
#define PRO2_EVALUATOR_PROBLEMA_HH

#include <string>

using namespace std;

class Problema {
private:
    string id_problema;
    int intentos, aciertos;
    double ratio;

    void calcular_ratio();

public:
    Problema();

    Problema(const string& id_problema, const int& intentos, const int& aciertos, const double& ratio);

    Problema(const string& id_problema);

    int obtener_intentos() const;

    int obtener_aciertos() const;

    double obtener_ratio() const;

    string obtener_idproblema() const;

    void aumentar_intentos();

    void aumentar_aciertos();

};


#endif //PRO2_EVALUATOR_PROBLEMA_HH
