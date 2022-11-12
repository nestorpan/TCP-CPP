#ifndef FECHA_H
#define FECHA_H

// La fecha base es 1/1/1601.

#define ANIO_BASE 1601
#define FECHA_INVALIDA 1

#include <iostream>
#include "../Serializable/Serializable.h"

using namespace std;

class Cadena;

class Fecha : public Serializable
{
private:
    int diaRel;

    static const int cdm[13];
    static const int acumDiasMes[14];
    static const int acumDiasMesBisiesto[14];

    static inline bool esBisiesto(int anio) { return (anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0; };

    static inline int cantDiaMes(int mes, int anio) { return mes == 2 && esBisiesto(anio) ? 29 : cdm[mes]; };

    static inline bool esFechaValida(int dia, int mes, int anio)
    { return anio >= ANIO_BASE && mes >= 1 && mes <= 12 && dia >= 1 && dia <= cantDiaMes(mes, anio); };

    static int diaDelAnio(int dia, int mes, int anio)
    { return (esBisiesto(anio) ? acumDiasMesBisiesto[mes] : acumDiasMes[mes]) + dia; };

    static void diaDelAnioADiaMes(int diaDelAnio, int anio, int& dia, int& mes);

public:
    Fecha();
    Fecha(int dia, int mes, int anio);
    Fecha(const Cadena& cad);

    Fecha operator +(int dias) const;
    Fecha& operator ++(); // Preincremento
    Fecha operator ++(int); // Posincremento
    int operator -(const Fecha& fecha) const;
    Fecha operator -(int dias) const;
    // TODO
    // Fecha& operator --(); // Predecremento
    // Fecha operator --(int); // Posdecremento
    // Fecha& operator +=(int dias);
    // Fecha& operator -=(int dias);
    // bool operator ==(const Fecha& fecha) const;
    // bool operator !=(const Fecha& fecha) const;
    // bool operator <(const Fecha& fecha) const;
    // bool operator <=(const Fecha& fecha) const;
    // bool operator >(const Fecha& fecha) const;
    // bool operator >=(const Fecha& fecha) const;

    int diaDeLaSemana() const;
    void getDma(int& dia, int& mes, int& anio) const;
    void setDma(int dia, int mes, int anio);

    void serializar(ostream& out, bool serializaNombre = false) const;
    Serializable* deserializarDin(istream& in);
    void deserializar(istream& in);
};


ostream& operator <<(ostream& os, const Fecha& fecha);
istream& operator >>(istream& is, Fecha& fecha);


#endif // FECHA_H
