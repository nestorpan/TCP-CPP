#ifndef ALUMNO_H
#define ALUMNO_H

#include "Persona.h"


class Alumno : public Persona
{
private:
    int cantMatAprob;
    float promedio;

    Alumno(const Cadena& dni, const Cadena& nombre, const Cadena& apellido, const Fecha& fechaNacimiento, char sexo, int cantMatAprob, float promedio);
//    Alumno(Persona& persona, int cantMatAprob, float promedio);

public:
    int getCantMatAprob() const;
    void setCantMatAprob(int cantMatAprob);

    float getPromedio() const;
    void setPromedio(float promedio);

    friend class AlumnoBuilder;
};


#endif // ALUMNO_H
