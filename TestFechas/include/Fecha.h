#ifndef FECHA_H
#define FECHA_H


class Fecha
{
    public:
        Fecha();
        Fecha(int dia, int mes, int anio);
        Fecha sumarDias(int dias) const;
        int getDiaRel() const;
        //void setDiaRel(int diaRel);

    private:
        unsigned long diaRel;
};

#endif // FECHA_H
