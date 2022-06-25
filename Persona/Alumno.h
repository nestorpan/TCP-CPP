#ifndef ALUMNO_H
#define ALUMNO_H

#include "Persona.h"


class Alumno : public Persona
{
private:
    int cantMatAprob;
    float promedio;

    Alumno(const Cadena& dni, const Cadena& nombre, const Cadena& apellido, const Fecha& fechaNacimiento, char sexo, int cantMatAprob, float promedio);

    /// Hacer operador de asignacion
    /// Hacer destructor

public:
    int getCantMatAprob() const;
    void setCantMatAprob(int cantMatAprob);

    float getPromedio() const;
    void setPromedio(float promedio);
    void imprimir() const;
//    void imprimir(ostream& sal) const;

    friend ostream& operator <<(ostream& sal, const Alumno& alumno);
    friend istream& operator >>(istream& is, Alumno& alumno);
    friend class AlumnoBuilder;
};


#endif // ALUMNO_H
