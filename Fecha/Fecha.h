#ifndef FECHA_H
#define FECHA_H

#define ANIO_BASE 1601


class Fecha
{
    private:
        unsigned int diaRel;

        static const int acumDiasIniMes[2][14];

        static int diaDelAnio(int d, int m, int a);
        static int cantDiasMes(int m, int a);
        static bool esBisiesto(int a);

    public:
        Fecha();
        Fecha(int d, int m, int a);

        static bool esFechaValida(int d, int m, int a);


        Fecha sumarDias(int dias) const;
        Fecha restarDias(int dias) const;
        void sumarDias(int dias);
        void restarDias(int dias);
        int difDias(const Fecha* f2) const;
        int diaSemana() const;
        void getDMA(int* d, int* m, int* a) const;
        void setDMA(int d, int m, int a);
};


#endif // FECHA_H
