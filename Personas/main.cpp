#include <fstream>
#include <iostream>
#include <algorithm>

#include "Empleado.h"
#include "EmpleadoBuilder.h"
#include "Intercambiar.h"


#define ARG_TXT_ENT 1
#define ARG_TXT_SAL 2


using namespace std;


int main(int argc, char* argv[])
{
/**
    Empleado emp;
    
    filebuf fbEnt;
    fbEnt.open(argv[ARG_TXT_ENT], ios::in);
    istream empleadosAEnt(&fbEnt);
    
    filebuf fbSal;
    fbSal.open(argv[ARG_TXT_SAL], ios::out);
    ostream empleadosASal(&fbSal);
    
	while(empleadosAEnt.peek() != EOF)
	{
		empleadosAEnt >> emp;
		emp.setSueldo(emp.getSueldo() * 1.30);
		empleadosASal << emp << endl;
	}
	
	fbEnt.close();
	fbSal.close();
*/    
 
 
    EmpleadoBuilder builder;
    
    builder.setDni(22333444);
    builder.setSexo('M');
    builder.setFechaNac(Fecha(7, 6, 2003));
    builder.setApellido("Perez");
    builder.setNombres("Juan Jose");
    builder.setSueldo(45777.23);
    
    Empleado emp = builder.build();
    
///    cout << emp.getApellido() << ", " << emp.getNombres() << " tiene " << emp.getEdad(Fecha::hoy()) << " anios." << endl;
	
    builder.setDni(40666777);
    builder.setSexo('F');
    builder.setFechaNac(Fecha(1, 8, 2004));
    builder.setApellido("Gonzalez");
    builder.setNombres("Juana Josefa");
    builder.setSueldo(65998.43);
    
    Empleado emp2 = builder.build();
		
	cout << "Emp1: " << emp << endl;
	cout << "Emp2: " << emp2 << endl;
	
	intercambiar<Empleado>(emp, emp2);
	
	cout << "Invertidos:" << endl;
	cout << "Emp1: " << emp << endl;
	cout << "Emp2: " << emp2 << endl;
	
	
/**	
    Empleado emp;
    vector<Empleado> vEmp;
    
    filebuf fbEnt;
    fbEnt.open(argv[ARG_TXT_ENT], ios::in);
    istream empleadosAEnt(&fbEnt);
    
    filebuf fbSal;
    fbSal.open(argv[ARG_TXT_SAL], ios::out);
    ostream empleadosASal(&fbSal);
    
	while(empleadosAEnt.peek() != EOF)
	{
		empleadosAEnt >> emp;
		vEmp.push_back(emp);
	}
	
	for(vector<Empleado>::iterator i = vEmp.begin(); i < vEmp.end(); ++i)
        i->setSueldo(i->getSueldo() * 1.30);
	
	sort(vEmp.begin(), vEmp.end());
	
	for(vector<Empleado>::iterator i = vEmp.begin(); i < vEmp.end(); ++i)
        empleadosASal << *i << endl;
	
    fbEnt.close();
	fbSal.close();
*/	
	
    return 0;
}
