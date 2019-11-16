#ifndef INTERCAMBIAR_H
#define INTERCAMBIAR_H


template<class T>
void intercambiar(T& v1, T& v2)
{
	T aux = v1;
	v1 = v2;
	v2 = aux;
}


#endif // INTERCAMBIAR_H
