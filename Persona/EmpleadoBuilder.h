#ifndef EMPLEADOBUILDER_H
#define EMPLEADOBUILDER_H

#include "../Cadena/Cadena.h"
#include "../Fecha/Fecha.h"
#include "PersonaBuilder.h"
#include "Empleado.h"

class EmpleadoBuilder : public PersonaBuilder
{
    private:
        long legajo;
        Cadena puesto;
        float sueldo;
        Fecha fIngr;

    public:
        EmpleadoBuilder();

        void setLegajo(long legajo);
        void setPuesto(Cadena puesto);
        void setSueldo(float sueldo);
        void setFIngr(Fecha fIngr);

        Empleado build() const;
        Empleado* buildDin() const;
};

#endif // EMPLEADOBUILDER_H
