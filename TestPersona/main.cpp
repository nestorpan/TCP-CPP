#include <iostream>
#include <fstream>
#include "../Persona/PersonaBuilder.h"
#include "../Persona/PersonaException.h"
#include "../Persona/AlumnoBuilder.h"

using namespace std;


int main()
{
    system("chcp 1252 > nul");

    // PersonaBuilder personaBuilder;

    // try
    // {
    //     personaBuilder
    //         .setDni(22333444)
    //         .setApellido("Gonzalez")
    //         .setNombre("Juan")
    //         .setFechaNacimiento(Fecha(1, 1, 1990));
    // }
    // catch(PersonaException& e)
    // {
    //     cerr << e.getMensaje() << endl;
    //     return 1; // Error validación.
    // }

    // Persona gonzalezJuan = personaBuilder.buildEstatica();

    // cout << gonzalezJuan.getApellido() << ", " << gonzalezJuan.getNombre() << endl;

    // Persona* gonzalezJuan2 = personaBuilder.buildDinamica();

    // cout << gonzalezJuan2->getApellido() << ", " << gonzalezJuan2->getNombre() << endl;


    // Grabo en archivo.

    // fstream archivo("Personas.txt", ios::out);

    // archivo << *gonzalezJuan2 << endl;

    // delete gonzalezJuan2;


    // try
    // {
    //     personaBuilder
    //         .setDni(33444555)
    //         .setApellido("Pérez")
    //         .setNombre("Rodrigo")
    //         .setFechaNacimiento(Fecha(10, 10, 1991));
    // }
    // catch(PersonaException& e)
    // {
    //     cerr << e.getMensaje() << endl;
    //     return 1; // Error validación.
    // }

    // Persona* perezRodrigo = personaBuilder.buildDinamica();

    // archivo << *perezRodrigo << endl;

    // delete perezRodrigo;

    // archivo.close();


    //  Leo de archivo.

    // fstream archivoLectura("Personas.txt", ios::in);

    // vector<Persona*> personas;

    // while(archivoLectura.peek() != EOF)
    // {
    //     Persona* persona = new Persona();
    //     archivoLectura >> *persona;
    //     personas.push_back(persona);
    // }

    // for(Persona* pers : personas)
    // {
    //     cout << pers->getApellido() << ", " << pers->getNombre() << endl;
    //     delete pers;
    // }


    AlumnoBuilder builder;

    try
    {
        builder
            .setDni(22333444)
            .setApellido("Gonzalez")
            .setNombre("Juan")
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

    fstream archAlus("Alumnos.txt", ios::out);

    archAlus << alu << endl;

    alu.setApellido("Perez");
    alu.setNombre("Rodrigo");
    archAlus << alu << endl;

    alu.setApellido("Gomez");
    alu.setNombre("Maria");
    archAlus << alu << endl;

    archAlus.close();

    fstream archAlusLectura("Alumnos.txt", ios::in);

    vector<Alumno*> alumnos;

    while(archAlusLectura.peek() != EOF)
    {
        Alumno* alumno = new Alumno();
        archAlusLectura >> *alumno;
        alumnos.push_back(alumno);
    }

    for(Alumno* alu : alumnos)
    {
        cout << *alu << endl;
        delete alu;
    }

    return 0;
}
