#ifndef ALGO_H
#define ALGO_H

#include <string>
#include <memory>

using namespace std;


class Algo
{
private:
	string nombre;
	shared_ptr<Algo> sig;
	weak_ptr<Algo> sigWeak;
	
public:
	Algo(const string& nombre, const shared_ptr<Algo>& sig = nullptr);
	~Algo();
	
	const string& getNombre() const;
	const shared_ptr<Algo>& getSig() const;
	void setSig(const shared_ptr<Algo>& sig);
	void setSigWeak(const weak_ptr<Algo>& sigWeak);
};


#endif // ALGO_H
