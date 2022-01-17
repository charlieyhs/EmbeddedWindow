#include "dialog.h"
#include "ui_dialog.h"
#include "windowcontrollerform.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    setWindowTitle(tr("Ventana de Destino"));
    WindowControllerForm *window_controller_form = new WindowControllerForm(this);
    window_controller_form->show();
}

Dialog::~Dialog()
{
    delete ui;
}

