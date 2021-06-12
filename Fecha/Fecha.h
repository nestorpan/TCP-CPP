#ifndef FECHA_H
#define FECHA_H

#include <iostream>

using namespace std;

class Fecha
{
    private:
        unsigned long diaRel;
        char separador = '/';

        static const int acumuladoMesesNoBisiesto[13];
        static const int acumuladoMesesBisiesto[13];

        static int diaDelAnio(int dia, int mes, int anio);
        static void diaDelAnioADiaMes(int diaDelAnio, int anio, int& d, int& m);
        static int cantDiasMes(int mes, int anio);
        static bool esFechaValida(int dia, int mes, int anio);

    public:
        Fecha();
        Fecha(char separdor);
        Fecha(int dia, int mes, int anio);
        Fecha(int dia, int mes, int anio, char separdor);

        Fecha sumarDias(int dias) const;

        char getSeparador() const;
        void getDMA(int& d, int& m, int& a) const;
        void setDMA(int d, int m, int a);

        static bool esBisiesto(int anio);
        static Fecha hoy();

        Fecha operator +(int dias) const;	///	Fecha sumarDias(int dias) const; // +
        Fecha& operator +=(int dias);

        Fecha& operator ++();	/// Pre
        Fecha operator ++(int);	/// Pos

        Fecha& operator --();	/// Pre
        Fecha operator --(int);	/// Pos

        /* TODO
        bool operator <(const Fecha& f2) const;
        bool operator >(const Fecha& f2) const;
        bool operator >=(const Fecha& f2) const;

        void restarDias(int dias);
        Fecha restarDias(int dias) const;
        int operator -(const Fecha& f2) const;
        int difEnAnios(const Fecha& f2) const;
        int diaSemana() const;
        int difDias(Fecha)  // Diferencia en días entre dos fechas

        */

        Fecha sumarMeses(int cantmeses)const;
        int difEnAnios(const Fecha& f2) const;

        friend Fecha operator +(int dias, const Fecha& f);
        //friend istream& operator >>(istream& ent, Fecha& f);
};

ostream& operator <<(ostream& sal, const Fecha& f);
istream& operator >>(istream& ent, Fecha& f);

#endif // FECHA_H
