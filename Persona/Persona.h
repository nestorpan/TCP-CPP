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

protected:
    Persona(const Cadena& dni, const Cadena& nombre, const Cadena& apellido, const Fecha& fechaNacimiento, char sexo);

public:
    const Cadena& getDNI() const;
    void setDNI(const Cadena& dni);

    const Cadena& getNombre() const;
    void setNombre(const Cadena& nombre);

    const Cadena& getApellido() const;
    void setApellido(const Cadena& apellido);

    const Fecha& getFechaNacimiento() const;
    void setFechaNacimiento(const Fecha& fechaNacimiento);

    char getSexo() const;
    void setSexo(char sexo);
    
    friend class PersonaBuilder;
};


ostream& operator<<(ostream& sal, const Persona& persona);
istream& operator>>(istream& is, Persona& persona);


#endif // PERSONA_H
