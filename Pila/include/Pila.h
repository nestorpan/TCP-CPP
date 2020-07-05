#ifndef PILA_H
#define PILA_H


template<class T>
class Pila
{
	private:
		T* vPila;
		int capacidad;
		int tope;
		
		
		void redimensionarPila(int nuevaCapacidad)
		{
			T* nuevoVPila = new T[nuevaCapacidad];
			
			for(int i = 0; i <= this->tope; i++)
				nuevoVPila[i] = this->vPila[i];
			
			delete [] this->vPila;
			
			this->vPila = nuevoVPila;
			this->capacidad = nuevaCapacidad;
		}
		
		
	public:
		Pila()
		{
			this->capacidad = 16;
			int tamElem = sizeof(T);
			printf("tamElem: %d\n", tamElem);
			this->vPila = new T[this->capacidad];
			this->tope = -1;
		}
		
		
		~Pila()
		{
			delete [] this->vPila;
		}
		
		
		void apilar(const T& elem)
		{
			this->tope++;
			
			if(this->tope == this->capacidad)
				redimensionarPila(this->capacidad * 2);
			
			this->vPila[this->tope] = elem;
		}
		
		
		bool desapilar(T& elem)
		{
			if(this->tope == -1)
				return false;
			
			elem = this->vPila[this->tope];
			
			this->tope--;
			
			if(this->capacidad > 16 && this->tope < this->capacidad / 4)
				redimensionarPila(this->capacidad / 2);
			
			return true;
		}
		
		
		bool verTope(T& elem)
		{
			if(this->tope == -1)
				return false;
			
			elem = this->vPila[this->tope];
			
			return true;
		}
		
		
		bool vacia()
		{
			return this->tope == -1;
		}
};

#endif // PILA_H
