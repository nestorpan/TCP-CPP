#include <Nodo.h>


template <class T>
Nodo<T>::Nodo(const T& dato)
: dato(dato), sig(NULL)
{}


template class Nodo<int>;
