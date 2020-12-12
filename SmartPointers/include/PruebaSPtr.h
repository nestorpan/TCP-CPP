#ifndef PRUEBASPTR_H
#define PRUEBASPTR_H

#include <string>
#include <memory>


using namespace std;


class PruebaSPtr
{
private:
	string nombre;
	weak_ptr<PruebaSPtr> otro;
	
public:
	PruebaSPtr(const string& nombre);
	~PruebaSPtr();
	
	const string& getNombre();
	void setOtro(shared_ptr<PruebaSPtr> otro);
};


#endif // PRUEBASPTR_H
