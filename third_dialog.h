#ifndef THIRD_DIALOG_H
#define THIRD_DIALOG_H

#include <QDialog>

namespace Ui {
class Third_Dialog;
}

class Third_Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Third_Dialog(QWidget *parent = nullptr);
    ~Third_Dialog();

private:
    Ui::Third_Dialog *ui;
};

#endif // THIRD_DIALOG_H
