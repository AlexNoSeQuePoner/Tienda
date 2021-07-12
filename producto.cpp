#include "producto.h"

int Producto::codigo() const
{
    return m_codigo;
}

void Producto::setCodigo(int codigo)
{
    m_codigo = codigo;
}

QString Producto::producto() const
{
    return m_producto;
}

void Producto::setProducto(const QString &producto)
{
    m_producto = producto;
}

float Producto::precio() const
{
    return m_precio;
}

void Producto::setPrecio(float precio)
{
    m_precio = precio;
}

Producto::Producto(QObject *parent) : QObject(parent)
{

}

Producto::Producto(int codigo, QString producto, float precio)
{
    m_codigo = codigo;
    m_producto = producto;
    m_precio = precio;
}
