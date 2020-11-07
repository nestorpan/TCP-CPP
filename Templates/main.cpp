#include <iostream>

using namespace std;

template <class T>
void intercambiar(T& a, T& b);


int main()
{
    int a = 5, b = 8;
    float c = 5.5, d = 8.8;
    
    intercambiar<int>(a, b);
    cout << "a: " << a << ", b: " << b << endl;
    
    intercambiar<float>(c, d);
    cout << "c: " << c << ", d: " << d << endl;
    
    return 0;
}


template <class T>
void intercambiar(T& a, T& b)
{
	T aux;
	aux = a;
	a = b;
	b = aux;
}
