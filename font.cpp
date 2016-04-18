#include "font.h"
#include "ui_font.h"
#include <QDebug>
Font::Font(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Font)
{
    ui->setupUi(this);
    QListWidgetItem * item;
    ui->fontComboBox->hide();
    for (int i = 0, count = ui->fontComboBox->count(); i < count; i++){
        item = new QListWidgetItem();
        QString fname = ui->fontComboBox->itemData(i,0).toString();
        item->setText(fname);
        f.setFamily(fname);
        item->setFont(f);
        ui->fontList->addItem(item);
    }
    connect(ui->fontList,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(fontFamilyChanged()));
    connect(ui->fontStyleList,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(fontStyleChanged()));
    connect(ui->fontSizeList,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(fontSizeChanged()));
}

Font::~Font()
{
    delete ui;
}

void Font::setFont(QFont f){
    this->f = f;
    this->_f = f;
}

QFont Font::getFont(){
    return this->_f;
}

void Font::fontFamilyChanged(){
    f.setFamily(ui->fontList->currentItem()->data(0).toString());
    ui->label->setFont(f);
}
void Font::fontStyleChanged(){
    QString style = ui->fontStyleList->currentItem()->data(0).toString();
    if(style == "Normal")
        {
            f.setBold(false);
            f.setItalic(false);
        }
    else if(style == "Bold")
        {
            f.setBold(true);
            f.setItalic(false);
        }
    else if(style ==  "Italic")
        {
            f.setItalic(true);
            f.setBold(false);
        }
    else if(style ==  "Bold Italic")
        {
            f.setBold(true);
            f.setItalic(true);
        }
    ui->label->setFont(f);
}
void Font::fontSizeChanged(){
    f.setPointSize(ui->fontSizeList->currentItem()->data(0).toInt());
    ui->label->setFont(f);
}

void Font::on_btnOK_clicked()
{
    this->_f = this->f;
    this->close();
}

void Font::on_btnCan_clicked()
{
    this->close();
}
