#ifndef PERSONAEXCEPTION_H
#define PERSONAEXCEPTION_H


class PersonaException
{
	private:
		string mensaje;
		
	public:
		PersonaException(const string& mensaje);
		
		const string& getMensaje() const;
};


#endif // PERSONAEXCEPTION_H
