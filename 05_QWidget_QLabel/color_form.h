#ifndef COLOR_FORM_H
#define COLOR_FORM_H

#include <QWidget>
#include <QButtonGroup>

namespace Ui {
class ColorForm;
}

class ColorForm : public QWidget
{
    Q_OBJECT

public:
    explicit ColorForm(QWidget *parent = nullptr);
    ~ColorForm();

signals:
    void colorChanged(int id);

private slots:
    void onColorClicked(int id);

private:
    Ui::ColorForm *ui;

    QButtonGroup *colorGroup;
};

#endif // COLOR_FORM_H
