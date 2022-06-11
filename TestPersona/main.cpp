#include <iostream>
#include <fstream>
#include "../Persona/PersonaBuilder.h"
#include "../Persona/Persona.h"
#include "../Persona/PersonaExc.h"
#include "../Cadena/FueraDeRangoExc.h"
#include "../Persona/AlumnoBuilder.h"
#include <locale.h>

using namespace std;


int main()
{
    setlocale(LC_CTYPE, "spanish");
    PersonaBuilder builder;

    try
    {
        builder
            .setDni("M12345678")
            .setNombre("Juan")
            .setApellido("Perez")
            .setFechaNacimiento(Fecha(1, 1, 2020))
            .setSexo('M');
    }
    catch (PersonaExc& e)
    {
        cout << e.getMensaje() << endl;
        return 1;
    }
    catch(FueraDeRangoExc& e)
    {
        cout << e.getMensaje() << endl;
        return 2;
    }

    Persona persona = builder.build();

    cout << "DNI: " << persona.getDni() << endl;

    // Alumno

    AlumnoBuilder alumnoBuilder;
    try
    {
        alumnoBuilder
            .setPromedio(7.5)
            .setCantMatAprob(20)
            .setDni("M23456789")
            .setNombre("Pedro")
            .setApellido("Ramirez")
            .setSexo('M');
    }
    catch(PersonaExc& e)
    {
        cout << e.getMensaje() << endl;
        return 1;
    }
    catch(FueraDeRangoExc& e)
    {
        cout << e.getMensaje() << endl;
        return 2;
    }

    Alumno alumno = alumnoBuilder.build();

    cout << "DNI: " << alumno.getDni() << endl;
    cout << "Nombre: " << alumno.getNombre() << endl;
    cout << "Promedio: " << alumno.getPromedio() << endl;
    cout << "Cant Mat Aprob: " << alumno.getCantMatAprob() << endl;

/*
    fstream archivoPersonas("Personas.txt", ios::out);

    archivoPersonas << persona << endl;
    archivoPersonas << alumno << endl;

    archivoPersonas.close();
*/
    fstream archivoPersonas2("Personas.txt", ios::in);

    PersonaBuilder builder2;
    Persona persona2 = builder2.build();

    cout << "Leyendo el archivo de Personas" << endl;

    while(!archivoPersonas2.eof())
    {
        archivoPersonas2 >> persona2;
        cout << persona2 << endl;
    }

    return 0;
}
