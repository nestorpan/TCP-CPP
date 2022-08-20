#ifndef FECHA_H
#define FECHA_H

// La fecha base es 1/1/1601.

#define ANIO_BASE 1601


class Fecha
{
private:
    int diaRel;

    int dmaADiaRel(int dia, int mes, int anio) const;
    
public:
    Fecha();
    Fecha(int dia, int mes, int anio);
    
    Fecha sumarDias(int dias) const;
    Fecha restarDias(int dias) const;
    int diferenciaEnDias(Fecha fecha) const;
    int diaDeLaSemana() const;
};


#endif // FECHA_H
