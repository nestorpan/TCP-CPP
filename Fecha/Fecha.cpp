#include "Fecha.h"

string Fecha::vectorDiaSemana[7] = {"LU", "MA", "MI", "JU", "VI", "SA", "DO"};

Fecha::Fecha()
{
    this->diaRel = 1;
}


Fecha::Fecha(int dia, int mes, int anio)
{
    diaRel = dmaADiaRel(dia, mes, anio);
}

Fecha Fecha::sumarDias(int dias) const
{
    Fecha fechaSuma;
    fechaSuma.diaRel = this->diaRel + dias;

    return fechaSuma;
}


Fecha Fecha::restarDias(int dias) const
{
    Fecha fechaResta;
    fechaResta.diaRel = diaRel - dias;
    return fechaResta;
}


int Fecha::diferenciaEnDias(Fecha fecha) const
{
    return diaRel - fecha.diaRel;
}

// Día de la semana, el primer día es el lunes y el último es el domingo. La fecha base es 1/1/1601.
int Fecha::diaDeLaSemana() const
{
    // LU = 0 - DO = 6
    return (diaRel - 1) % 7;
}

string Fecha::diaDeLaSemanaStr() const
{
    // LU = 0 - DO = 6
    return vectorDiaSemana[diaDeLaSemana()];
}

int Fecha::dmaADiaRel(int dia, int mes, int anio) const
{
    return 1; // TODO: Implementar.
}
