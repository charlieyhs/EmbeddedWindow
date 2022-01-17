#include "windowcontrollerform.h"
#include "ui_windowcontrollerform.h"
#include "dialog.h"

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWindow>
WindowControllerForm::WindowControllerForm(Dialog *dialog_parent) :
    QWidget(nullptr),
    ui(new Ui::WindowControllerForm)
{
    ui->setupUi(this);
    setWindowTitle("Ventana de Control");
    m_dialog_parent = dialog_parent;
    setAttribute(Qt::WA_DeleteOnClose);

    m_label = new QLabel(tr("Window ID"),this);
    m_window_id_lineedit = new QLineEdit(this);
    m_embed_pushbutton = new QPushButton(tr("Empotrar"),this);
    m_layout = new QHBoxLayout;

    m_layout->addWidget(m_label);
    m_layout->addWidget(m_window_id_lineedit);
    m_layout->addWidget(m_embed_pushbutton);

    setLayout(m_layout);

    resize(sizeHint());

    connect(m_embed_pushbutton, &QPushButton::clicked, this, [&](){
        unsigned long long window_id = m_window_id_lineedit->text().toULongLong(nullptr,16);
        QWidget *widget = nullptr;
        QWindow *window = nullptr;
        QVBoxLayout *vbox = nullptr;

        window = QWindow::fromWinId(window_id);
        window->setFlag(Qt::FramelessWindowHint);

        widget = QWidget::createWindowContainer(window);

        vbox = new QVBoxLayout;
        vbox->addWidget(widget);

        m_dialog_parent->setLayout(vbox);
    });
}

WindowControllerForm::~WindowControllerForm()
{
    delete ui;
}
