#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include "producto.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

private slots:
    void on_cmdAgregar_released();

    void on_inProducto_currentIndexChanged(int index);

private:
    Ui::Principal *ui;
    QList<Producto*> m_producto;
    float m_subtotal;
    void calcular(float subTProducto);
};
#endif // PRINCIPAL_H
