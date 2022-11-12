#include <iostream>
#include <fstream>
#include "../Persona/Alumno.h"
#include "../Persona/AlumnoBuilder.h"
#include "../Persona/PersonaException.h"

using namespace std;


int main()
{
   AlumnoBuilder builder;

    try
    {
        builder
            .setDni(22333444)
            .setApellido("Gonzalez")
            .setNombre("Nico")
            .setFechaNacimiento(Fecha(1, 1, 1990));

        builder
            .setFechaIngreso(Fecha(1, 1, 2010))
            .setCarrera("ING_INF")
            .setCantMatAprob(23)
            .setPromedio(7);
    }
    catch(PersonaException& e)
    {
        cerr << e.getMensaje() << endl;
        return 1; // Error validación.
    }

    Alumno alu = builder.buildEstatica();

    fstream archAlus("Alumnos.dat", ios::out | ios::binary);

    alu.serializar(archAlus, true);

    alu.setDni(33444555);
    alu.setApellido("Perez");
    alu.setNombre("Enzo");
    alu.setCarrera("ING_IND");
    alu.setFechaIngreso(Fecha(1, 1, 2011));

    alu.serializar(archAlus, true);

    alu.setApellido("Gomez");
    alu.setNombre("Papu");
    alu.setFechaNacimiento(Fecha(23, 8, 1995));

    alu.serializar(archAlus, true);

    archAlus.close();

    fstream archAlusLectura("Alumnos.dat", ios::in | ios::binary);

    vector<Alumno*> alumnos;
    Alumno* alumno;
    while(archAlusLectura.peek() != EOF)
    {
        alumno = (Alumno*)Serializable::deserializarStatic(archAlusLectura);
        alumnos.push_back(alumno);
    }

    for(Alumno* alu : alumnos)
    {
        cout << *alu << endl;
        delete alu;
    }

    return 0;
}
