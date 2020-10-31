#include <iostream>
#include <fstream>

#include <PersonaBuilder.h>
#include <EmpleadoBuilder.h>
#include <ValidacionesException.h>

#define ERR_VALIDACION 1;

#ifdef _WIN32
#define TAM_CAR_FIN_LINEA 2
#else
#define TAM_CAR_FIN_LINEA 1
#endif

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

//    while(ent.peek()!=EOF)
    {
        ent >> pers3;
        ent.ignore(1);
//        cout << pers3 << endl;
    }

    fbEnt.close();


    /*************************************************************
    ***						Empleados						   ***
    *************************************************************/
    EmpleadoBuilder eBuilder;

    eBuilder.setNombre("Pepe");
    eBuilder.setApellido("Perez");
    eBuilder.setFNac(Fecha(1, 1, 2000));
    eBuilder.setLegajo(1234567);
    eBuilder.setFIngr(Fecha(2, 2, 2020));

    try
    {
		Empleado empl = eBuilder.build();

		filebuf fbSal;
		fbSal.open("Empleados.txt", ios::out);
		ostream sal(&fbSal);

		eBuilder.setDni(11222333);
		eBuilder.setNombre("Rodriguez");
		eBuilder.setApellido("Roberto");
		eBuilder.setFNac(Fecha(2, 2, 2002));
		eBuilder.setLegajo(3456789);
		eBuilder.setSueldo(50000);

		Empleado empl2 = eBuilder.build();

		sal << empl << endl;
		sal << empl2 << endl;

		fbSal.close();
    }
    catch(ValidacionesException& ex)
    {
		cout << "Se produjo el sig error: " << ex.getMensaje() << endl;
		return ERR_VALIDACION;
    }

	fbEnt.open("Empleados.txt", ios::in);
	istream ent2(&fbEnt);

	EmpleadoBuilder eBuilder2;

	Empleado empl = eBuilder2.build();

	cout << "Leyendo Empleados:" << endl;

//	while((c = ent2.peek()) != EOF)
	{
		ent2 >> empl;
		ent2.ignore(TAM_CAR_FIN_LINEA);
		cout << empl << endl;
    }

    fbEnt.close();

    return 0;
}
