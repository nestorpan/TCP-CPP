#ifndef FECHA_H
#define FECHA_H


class Fecha
{
    private:
        int diaRel;// Cant. de días que pasaron desde 01/01/1601

    public:
        Fecha();
        Fecha(int dia, int mes, int anio);

        Fecha sumarDias(int dias) const;
        int difEnDias(const Fecha* otraFecha) const;

        Fecha operator +(int dias) const;
        int operator -(const Fecha* otraFecha) const; //const al final indica que no se modifica el objeto llamador

        //int getDiaRel() const;
};

#endif // FECHA_H
