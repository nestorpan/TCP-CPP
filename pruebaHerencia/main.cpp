#include <iostream>
#include <fstream>

#include <PersonaBuilder.h>
#include <ValidacionesException.h>

#define ERR_VALIDACION 1;


using namespace std;

int main()
{
    /*
    PersonaBuilder pBuilder;

    pBuilder.setDni(24004600);
    pBuilder.setNombre("Garcia");
    pBuilder.setApellido("Juana");
    pBuilder.setSexo('F');
    pBuilder.setFNac(Fecha(25, 10, 2020));

    try
    {
		Persona pers = pBuilder.build();

		filebuf fbSal;
		fbSal.open("Personas.txt", ios::out);
		ostream sal(&fbSal);

		sal << pers << endl;

		fbSal.close();
    }
    catch(ValidacionesException& ex)
    {
		cout << "Se produjo el sig error: " << ex.getMensaje() << endl;
		return ERR_VALIDACION;
    }
*/
	filebuf fbEnt;
	fbEnt.open("Personas.txt", ios::in);
	istream ent(&fbEnt);

	PersonaBuilder pBuilder2;
	Persona pers2 = pBuilder2.build();

    try
    {
        pers2.setDni(2);
    }
    catch(ValidacionesException& ex)
    {
		cout << "Se produjo el sig error: " << ex.getMensaje() << endl;
		return ERR_VALIDACION;
    }


//	cout << pers2 << endl;


	PersonaBuilder pBuilder3;
	Persona pers3 = pBuilder3.build();
	ent >> pers3;

	cout << "Persona leída:" << endl
		 << pers3 << endl;

    fbEnt.close();

    return 0;
}
