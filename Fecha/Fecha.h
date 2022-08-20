#ifndef FECHA_H
#define FECHA_H
#include <string>

// La fecha base es 1/1/1601.

#define ANIO_BASE 1601

using namespace std;

class Fecha
{
private:
    int diaRel;

    int dmaADiaRel(int dia, int mes, int anio) const;

    static string vectorDiaSemana[7];

public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    Fecha sumarDias(int dias) const;
    Fecha restarDias(int dias) const;
    int diferenciaEnDias(Fecha fecha) const;
    int diaDeLaSemana() const;
    string diaDeLaSemanaStr() const;
};


#endif // FECHA_H
