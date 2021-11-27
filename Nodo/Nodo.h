#include "../TDAPila/PilaImplDinamica.h"

// Forward declaration para poder declarar la clase PilaImplDinamica<T> como friend de Nodo<T>.
template <class T>
class PilaImplDinamica;


template <class T>
class Nodo
{
private:
    T elem;
    Nodo<T>* sig;
    
    friend class PilaImplDinamica<T>;
};
