#include "FechaInvalidaException.h"
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
    setDma(dia, mes, anio);
}


Fecha Fecha::operator +(int dias) const
{
    Fecha fechaSuma(*this); // Disponible por defecto, NO es necesario implementarlo.
    fechaSuma.diaRel += dias;

//    Fecha fechaSuma;
//    fechaSuma.diaRel = this->diaRel + dias;

    return fechaSuma;
}


Fecha Fecha::operator -(int dias) const
{
    Fecha fechaResta(*this);
    fechaResta.diaRel -= dias;

    if(fechaResta.diaRel < 1)
        throw FechaInvalidaException("Fecha inválida: Quiere restar más días de los permitidos.");

    return fechaResta;
}


int Fecha::operator -(const Fecha& fecha) const
{
    return this->diaRel - fecha.diaRel;
}


Fecha& Fecha::operator ++() // Preincremento
{
    ++this->diaRel;
    return *this;
}


Fecha Fecha::operator ++(int) // Posincremento
{
    Fecha fechaAnterior(*this);
    ++this->diaRel;
    return fechaAnterior;
}


// Día de la semana, el primer día es el lunes y el último es el domingo. La fecha base es 1/1/1601.
int Fecha::diaDeLaSemana() const
{
    return (diaRel - 1) % 7;
}


void Fecha::setDma(int dia, int mes, int anio)
{
    if(!esFechaValida(dia, mes, anio))
         throw FechaInvalidaException("Fecha inválida");

    int cantAnios = anio - ANIO_BASE;
    int diasAniosCompl = cantAnios * 365 + cantAnios / 4 - cantAnios / 100 + cantAnios / 400;
    this->diaRel = diasAniosCompl + diaDelAnio(dia, mes, anio);
}


void Fecha::getDma(int& dia, int& mes, int& anio) const
{
    int cantAniosComplCalc = this->diaRel / 365;

    int diasAniosComplCalc;

    diasAniosComplCalc =
        cantAniosComplCalc * 365 + cantAniosComplCalc / 4 - cantAniosComplCalc / 100 + cantAniosComplCalc / 400;

    while(diasAniosComplCalc >= this->diaRel)
    {
        cantAniosComplCalc--;
        diasAniosComplCalc =
            cantAniosComplCalc * 365 + cantAniosComplCalc / 4 - cantAniosComplCalc / 100 + cantAniosComplCalc / 400;
    }

    anio = cantAniosComplCalc + ANIO_BASE;

    int diaDelAnio = this->diaRel - diasAniosComplCalc;

    diaDelAnioADiaMes(diaDelAnio, anio, dia, mes);
}


void Fecha::diaDelAnioADiaMes(int diaDelAnio, int anio, int& dia, int& mes)
{
    const int* acumDiasMes = esBisiesto(anio) ? acumDiasMesBisiesto : Fecha::acumDiasMes;

    int m = 1;
    while(diaDelAnio > acumDiasMes[m])
        m++;

    m--;
    mes = m;

    dia = diaDelAnio - acumDiasMes[m];
}


ostream& operator <<(ostream& os, const Fecha& fecha)
{
    int dia, mes, anio;
    fecha.getDma(dia, mes, anio);
    os << dia << '/' << mes << '/' << anio;
    return os;
}
