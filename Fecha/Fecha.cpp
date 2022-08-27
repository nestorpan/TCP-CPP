#include "Fecha.h"


const int Fecha::cdm[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const int Fecha::acumDiasMes[14] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};

const int Fecha::acumDiasMesBisiesto[14] = {0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366};


Fecha::Fecha()
{
    this->diaRel = 1;
}


Fecha::Fecha(int dia, int mes, int anio)
{
    this->diaRel = dmaADiaRel(dia, mes, anio);
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
    return (diaRel - 1) % 7;
}


int Fecha::dmaADiaRel(int dia, int mes, int anio)
{
    if(!esFechaValida(dia, mes, anio))
         throw FECHA_INVALIDA;

    int cantAnios = anio - ANIO_BASE;
    int diasAniosCompl = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios / 400;
    int diaRel = diasAniosCompl + diaDelAnio(dia, mes, anio);

    return diaRel;
}


void Fecha::diaRelADma(int diaRel, int* dia, int* mes, int* anio)
{
    int cantAniosComplCalc = diaRel / 365;

    int diasAniosComplCalc;

    diasAniosComplCalc =
        cantAniosComplCalc * 365 + cantAniosComplCalc / 4 - cantAniosComplCalc / 100 + cantAniosComplCalc / 400;

    while(diasAniosComplCalc >= diaRel)
    {
        cantAniosComplCalc--;
        diasAniosComplCalc =
            cantAniosComplCalc * 365 + cantAniosComplCalc / 4 - cantAniosComplCalc / 100 + cantAniosComplCalc / 400;
    }

    *anio = cantAniosComplCalc + ANIO_BASE;

    int diaDelAnio = diaRel - diasAniosComplCalc;

    diaDelAnioADiaMes(diaDelAnio, *anio, dia, mes);
}


void Fecha::diaDelAnioADiaMes(int diaDelAnio, int anio, int* dia, int* mes)
{

    // const int Fecha::acumDiasMes[14] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
    const int* acumDiasMes = esBisiesto(anio) ? acumDiasMesBisiesto : Fecha::acumDiasMes;

    int m = 1;
    while(diaDelAnio > acumDiasMes[m])
        m++;

    m--;
    *mes = m;

    *dia = diaDelAnio - acumDiasMes[m];
}


void Fecha::getDma(int* dia, int* mes, int* anio) const
{
    diaRelADma(diaRel, dia, mes, anio);
}
