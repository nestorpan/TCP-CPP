#ifndef FECHA_H
#define FECHA_H


class Fecha
{
    private:
        unsigned long diaRel;

        static const int acumuladoMesesNoBisiesto[13];
        static const int acumuladoMesesBisiesto[13];

        static int diaDelAnio(int dia, int mes, int anio);
        static bool esBisiesto(int anio);
        static void diaDelAnioADiaMes(int diaDelAnio, int anio, int* d, int* m);

    public:
        Fecha();
        Fecha(int dia, int mes, int anio);

        Fecha sumarDias(int dias) const;
        // TODO Fecha sumarMeses(int cantMeses) const;

        void getDMA(int* d, int* m, int* a) const;
        unsigned long getDiaRel();

        // TODO int diaDeLaSemana
        // TODO string nombreDiaDeLaSemana
        unsigned long diferenciaEnDias(const Fecha otraFecha) const;


};

#endif // FECHA_H
