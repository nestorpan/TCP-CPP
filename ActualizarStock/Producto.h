#ifndef PRODUCTO_H
#define PRODUCTO_H


class Producto
{
private:
	Cadena codigo;
	Cadena descripcion;
	int stock;
	
public:
	Producto(const Cadena& codigo = Cadena(), const Cadena& descripcion = Cadena(), int stock = 0);
	
	const Cadena& getCodigo() const;
	void setCodigo(const Cadena& codigo);
	const Cadena& getDescripcion() const;
	void setDescripcion(const Cadena& descripcion);
	int getStock() const;
	void setStock(int stock);
};


#endif // PRODUCTO_H
