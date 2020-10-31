#include <iostream>
#include <fstream>

#include <Defs.h>
#include <PersonaBuilder.h>
#include <EmpleadoBuilder.h>
#include <ValidacionesException.h>

#define ERR_VALIDACION 1;


using namespace std;

int main()
{
    PersonaBuilder pBuilder;
    
    pBuilder.setNombre("Pepe");
    pBuilder.setApellido("Perez");
    pBuilder.setFNac(Fecha(1, 1, 2000));
    
    try
    {
		Persona pers = pBuilder.build();
		
		filebuf fbSal;
		fbSal.open("Personas.txt", ios::out);
		ostream sal(&fbSal);
		
		pBuilder.setDni(11222333);
		pBuilder.setNombre("Rodriguez");
		pBuilder.setApellido("Roberto");
		pBuilder.setFNac(Fecha(2, 2, 2002));
				
		Persona pers2 = pBuilder.build();
		
		sal << pers << endl;
		sal << pers2 << endl;
		
		fbSal.close();
    }
    catch(ValidacionesException& ex)
    {
		cout << "Se produjo el sig error: " << ex.getMensaje() << endl;
		return ERR_VALIDACION;
    }
    
	filebuf fbEnt;
	fbEnt.open("Personas.txt", ios::in);
	istream ent(&fbEnt);
	
	PersonaBuilder pBuilder2;
	
	Persona pers = pBuilder2.build();
	
	cout << "Leyendo Personas:" << endl;
	char c;
	while((c = ent.peek()) != EOF)
	{
		ent >> pers;
		ent.ignore(TAM_CAR_FIN_LINEA);
		cout << pers << endl;
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
	
	while((c = ent2.peek()) != EOF)
	{
		ent2 >> empl;
		ent2.ignore(TAM_CAR_FIN_LINEA);
		cout << empl << endl;
    }
    
    fbEnt.close();
	
    return 0;
}
