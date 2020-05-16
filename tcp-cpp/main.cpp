#include <iostream>
#include <fstream>
#include "Fecha.h"
#include "FechaException.h"
#include <Cadena.h>

using namespace std;


#define ARG_ARCH_ENT 1
#define ARG_ARCH_SAL 2


int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		cout << "Cantidad de parámetros incorrecta" << endl;
		return 1;
	}
	
/**    
    float a;
    
    cin >> a;
    
    cout << "El valor de a es: " << a << endl;
*/
/**	
	try
	{
		Fecha fHoy(18, 4, 2020);
	}
	catch(FechaException& ex)
	{
		cout << ex.getMensaje() << endl;
		
		return 1;
	}
	
	Fecha fManiana(19, 4, 2020);
	
///	fHoy.sumarDias(30);
	
	int d, m, a;
	
///	(fHoy += 30).getDma(d, m, a);
	
///	fHoy.operator +=(30);
	
///	fHoy.getDma(d, m, a);
	
	cout << "Fecha + 30: " << d << '/' << m << '/' << a << endl;
	
	Fecha fFinMayo(31, 5, 2020);
	
	fFinMayo.getDma(d, m, a);
	
	cout << "Fecha Fin Mayo: " << d << '/' << m << '/' << a << endl;
	
	Fecha fFinAnio(31, 12, 2020);
	fFinAnio.getDma(d, m, a);
	cout << "Fecha Fin Anio: " << d << '/' << m << '/' << a << endl;
	
	Fecha fSuma = fFinMayo + 30;
	
	fSuma.getDma(d, m, a);
	
	cout << "Fecha fin Mayo + 30: " << d << '/' << m << '/' << a << endl;
	
//	int dif = fHoy.diferencia(fManiana);
	
//	cout << "Dia de la semana de hoy: " << fHoy.diaDeLaSemana() << endl;
	
///	fHoy.sumarDias(30);

	
	
	const Fecha fConst(25, 4, 2020);
	
	fConst.sumarDias(30);
*/	

///	try
///	{

	/**	
		Fecha fHoy(2, 5, 2020);
		
		Fecha fsuma = fHoy + 30;
		
		cout << fHoy << " + 30: " << fsuma << endl;
		
		fsuma = 30 + fHoy;
		
		cout << fHoy << " + 30: " << fsuma << endl;
		
		cout << "Ingrese una fecha:" << endl;
		cin >> fHoy;
	
		cout << "fHoy: " << fHoy << endl;
	*/
/**		
		filebuf fb;
		if(fb.open(argv[ARG_ARCH_ENT], ios::in) == NULL)
		{
			cout << "No se pudo abrir el archivo" << endl;
			return 3;
		}
		
		filebuf fbSal;
		if(fbSal.open(argv[ARG_ARCH_SAL], ios::out) == NULL)
		{
			cout << "No se pudo abrir el archivo" << endl;
			return 3;
		}
		
		Fecha fLect;
		
		istream fechasA(&fb);
		ostream fechasSalA(&fbSal);
		
		cout << "Leyendo archivo " << argv[ARG_ARCH_ENT] << ": " << endl;
		
		char peek;
		while((peek = fechasA.peek()) != EOF)
		{
			cout << "Peek: " << peek << endl;
			fechasA >> fLect;
			fechasA.ignore(1); ///Saca un carácter (enter) del buffer.
			fechasSalA << fLect << endl;
		}
		
		fb.close();
		fbSal.close();
	}
	catch(FechaException& ex)
	{
		cout << ex.getMensaje() << endl;
		return 2;
	}
*/	

	Cadena hola("Hola"), que("que"), tal("tal");
	
	Cadena concat = hola + ", " + que;/// + ' ' + tal + '?';
	
	cout << concat << endl;

	
	
	
	
    return 0;
}
