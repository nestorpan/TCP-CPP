#include <iostream>
#include <fstream>

#include <PersonaBuilder.h>
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
		
		sal << pers << endl;
		
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
	
	Persona pers2 = pBuilder2.build();
	
	ent >> pers2;
	
	cout << "Persona leída:" << endl
		 << pers2 << endl;
    
    fbEnt.close();
    
    return 0;
}
