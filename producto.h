#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <QObject>

#define IVA 12.0;

class Producto : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int codigo READ codigo WRITE setCodigo)
    Q_PROPERTY(QString producto READ producto WRITE setProducto)
    //Q_PROPERTY(int cantidad READ cantidad WRITE setCantidad)
    Q_PROPERTY(float precio READ precio WRITE setPrecio)
private:
    int m_codigo;
    QString m_producto;
    //int m_cantidad;
    float m_precio;
public:
    explicit Producto(QObject *parent = nullptr);
    Producto (int codigo, QString producto, float precio);
    int codigo() const;
    void setCodigo(int codigo);

    QString producto() const;
    void setProducto(const QString &producto);

    float precio() const;
    void setPrecio(float precio);

signals:

};

#endif // PRODUCTO_H
