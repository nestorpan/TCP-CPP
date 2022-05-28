#ifndef PERSONA_H
#define PERSONA_H

#include "../Cadena/Cadena.h"
#include "../Fecha/Fecha.h"


class Persona
{
private:
    Cadena dni;
    Cadena nombre;
    Cadena apellido;
    Fecha fechaNacimiento;
    char sexo;

    static void validarDNI(const Cadena& dni);

public:
    Persona();
    Persona(const Cadena& dni, const Cadena& nombre, const Cadena& apellido, const Fecha& fechaNacimiento, char sexo);

    const Cadena& getDni() const;
    void setDni(const Cadena& dni);

    const Cadena& getNombre() const;
    void setNombre(const Cadena& nombre);

    const Cadena& getApellido() const;
    void setApellido(const Cadena& apellido);

    const Fecha& getFechaNacimiento() const;
    void setFechaNacimiento(const Fecha& fechaNacimiento);

    char getSexo() const;
    void setSexo(char sexo);
};


ostream& operator<<(ostream& sal, const Persona& persona);
istream& operator>>(istream& is, Persona& persona);


#endif // PERSONA_H
