#ifndef STYLE_FORM_H
#define STYLE_FORM_H

#include <QWidget>

namespace Ui {
class StyleForm;
}

class StyleForm : public QWidget
{
    Q_OBJECT

public:
    explicit StyleForm(QWidget *parent = nullptr);
    ~StyleForm();

signals:
    void styleChanged(bool bold, bool italic, bool underline);

private slots:
    void onStyleClicked();

private:
    Ui::StyleForm *ui;
};

#endif // STYLE_FORM_H
