#ifndef FECHA_H
#define FECHA_H


class Fecha
{
    private:
        int diaRel;

    public:
        Fecha();
        Fecha(int d, int m, int a);

        Fecha sumarDias(int dias) const;
        void sumarDias(int dias);

        int difDias(const Fecha* f2) const;
        void getDMA(int* d, int* m, int* a) const;
        void setDMA(int d, int m, int a);
};

#endif // FECHA_H
