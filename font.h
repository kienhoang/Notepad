#ifndef FONT_H
#define FONT_H

#include <QDialog>
#include <QFont>

namespace Ui {
class Font;
}

class Font : public QDialog
{
    Q_OBJECT

public:
    explicit Font(QWidget *parent = 0);
    ~Font();
    void setFont(QFont f);
    QFont getFont();
public slots:
    void fontFamilyChanged();
    void fontStyleChanged();
    void fontSizeChanged();
private slots:
    void on_btnOK_clicked();

    void on_btnCan_clicked();

private:
    Ui::Font *ui;
    QFont f,_f;
};

#endif // FONT_H
