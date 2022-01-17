#ifndef WINDOWCONTROLLERFORM_H
#define WINDOWCONTROLLERFORM_H

#include <QWidget>
class Dialog;
class QLabel;
class QLineEdit;
class QPushButton;
class QHBoxLayout;

namespace Ui {
class WindowControllerForm;
}

class WindowControllerForm : public QWidget
{
    Q_OBJECT

public:
    explicit WindowControllerForm(Dialog *dialog_parent = nullptr);
    ~WindowControllerForm();

private:
    Ui::WindowControllerForm *ui;
    Dialog *m_dialog_parent;
    QLabel *m_label;
    QLineEdit *m_window_id_lineedit;
    QPushButton *m_embed_pushbutton;
    QHBoxLayout *m_layout;
};

#endif // WINDOWCONTROLLERFORM_H
