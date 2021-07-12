#include "principal.h"
#include "ui_principal.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    //LISTA DE PRODUCTOS
    m_producto.append(new Producto(1, "Leche", 0.85));
    m_producto.append(new Producto(2, "Pan", 0.15));
    m_producto.append(new Producto(3, "Queso", 2.00));
    //Mostrar la lista en la venta
    for (int i = 0; i < m_producto.size(); ++i){
        ui->inProducto->addItem(m_producto.at(i)->producto());
    }
    //Colocar cabecera de la tabla
    QStringList cabecera = {"Cantidad", "Producto", "SubTotal"};
    ui->outDetalle->setColumnCount(3);
    ui->outDetalle->setHorizontalHeaderLabels(cabecera);
    //Inicializar el subtotal
    m_subtotal = 0;
}

Principal::~Principal()
{
    delete ui;
}


void Principal::on_cmdAgregar_released()
{
    //Obtener datos de la GUI
    int cantidad = ui->inCantidad->value();
    //Validar que no se agregen productos con 0 cantidad
    if (cantidad == 0){
        return;
    }
    int index = ui->inProducto->currentIndex();
    Producto *p = m_producto.at(index);
    //Calcular el subtotal del producto
    float subtotal = cantidad * p->precio();

    //Agregar datos a la tabla
    int fila = ui->outDetalle->rowCount();
    ui->outDetalle->insertRow(fila);
    ui->outDetalle->setItem(fila,0,new QTableWidgetItem(QString::number(cantidad)));
    ui->outDetalle->setItem(fila,1,new QTableWidgetItem(p->producto()));
    ui->outDetalle->setItem(fila,2,new QTableWidgetItem(QString::number(subtotal)));
    //limpiar datos
    ui->inCantidad->setValue(0);
    ui->inProducto->setFocus();
    //invocar calcular
    calcular(subtotal);
}

void Principal::on_inProducto_currentIndexChanged(int index)
{
    //Obtener el precio del producto
    float precio = m_producto.at(index)->precio();
    //mostrar precio
    ui->outPrecio->setText("$ " + QString::number(precio, 'f', 2));
}

void Principal::calcular(float subTProducto)
{
    m_subtotal += subTProducto;
    float iva = m_subtotal * 0.01 * IVA;
    float total = m_subtotal + iva;

    ui->outSubtotal->setText(QString::number(m_subtotal, 'f',2));
    ui->outIVA->setText(QString::number(iva, 'f',2));
    ui->outTotal->setText(QString::number(total, 'f',2));
}
