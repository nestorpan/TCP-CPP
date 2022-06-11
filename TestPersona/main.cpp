#include <iostream>
#include <fstream>
#include "../Persona/PersonaBuilder.h"
#include "../Persona/Persona.h"
#include "../Persona/PersonaExc.h"
#include "../Cadena/FueraDeRangoExc.h"
#include "../Persona/AlumnoBuilder.h"


using namespace std;


int main()
{
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

    cout << "DNI: " << persona.getDNI() << endl;


    // Alumno

    AlumnoBuilder alumnoBuilder;
    try
    {
        alumnoBuilder
            .setDni("M23456789")
            .setNombre("Pedro")
            .setApellido("Ramirez")
            .setSexo('M');
        alumnoBuilder
            .setPromedio(9.5)
            .setCantMatAprob(20);
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

    cout << "DNI: " << alumno.getDNI() << endl;
    cout << "Nombre: " << alumno.getNombre() << endl;
    cout << "Cant Mat Aprob: " << alumno.getCantMatAprob() << endl;

    fstream archivoPersonas("Personas.txt", ios::out);

    archivoPersonas << persona << endl;
    archivoPersonas << alumno << endl;

    archivoPersonas.close();

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
