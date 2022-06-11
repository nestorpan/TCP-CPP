#ifndef ALUMNOBUILDER_H
#define ALUMNOBUILDER_H

#include "Alumno.h"
#include "PersonaBuilder.h"


class AlumnoBuilder : public PersonaBuilder
{
private:
    int cantMatAprob;
    float promedio;

public:
    AlumnoBuilder();

    AlumnoBuilder& setCantMatAprob(int cantMatAprob);
    AlumnoBuilder& setPromedio(float promedio);

    Alumno build();
};


#endif // ALUMNOBUILDER_H
