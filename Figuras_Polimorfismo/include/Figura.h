#ifndef FIGURA_H
#define FIGURA_H

#include <string>

using namespace std;


class Figura
{
	private:
		string nombre;
		
	public:
		Figura(string nombre);
		
		virtual double perimetro() const = 0; ///( = 0 ) -> Método virtual puro (No tiene código en esta clase).
		virtual double area() const = 0;
		const string& getNombre() const;
};


#endif // FIGURA_H
