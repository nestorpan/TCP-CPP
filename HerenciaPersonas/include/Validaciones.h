#ifndef VALIDACIONES_H
#define VALIDACIONES_H


class Validaciones
{
public:
	static unsigned mayorACero(unsigned, const Cadena& mensaje);
	static const Cadena& letrasYEspacios(const Cadena&, const Cadena& mensaje);
	static char sexo(char, const Cadena& mensaje);
	static const Fecha& fecha(const Fecha& desde, const Fecha& hasta, const Cadena& mensaje);
};

#endif // VALIDACIONES_H
