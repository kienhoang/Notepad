#include "notepad.h"
#include "ui_notepad.h"
#include <QDateTime>
#include <font.h>
#include <QFileDialog>
#include <QDebug>

Notepad::Notepad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Notepad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->text);
    ui->text->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->text->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    // WrapMode
    connect(ui->actionLine_wrap,SIGNAL(changed()),this,SLOT(wrap()));
    wrap();
    connect(ui->actionStatus_bar,SIGNAL(changed()),this,SLOT(status()));
    status();
    connect(ui->actionTool_bar,SIGNAL(changed()),this,SLOT(toolbar()));
    toolbar();
    isSave = true;
    filename="";
    connect(ui->text,SIGNAL(textChanged()),this,SLOT(textchanged()));
    ui->text->setFont(mFont);
}

void Notepad::setArg(int argc, char *argv[]) const {

}

Notepad::~Notepad()
{
    delete ui;
}

void Notepad::wrap(){
    if(ui->actionLine_wrap->isChecked()){
        ui->text->setLineWrapMode(QPlainTextEdit::WidgetWidth);
    }else{
        ui->text->setLineWrapMode(QPlainTextEdit::NoWrap);
    }
}
void Notepad::status(){
    if(ui->actionStatus_bar->isChecked()){
        ui->statusBar->show();
    }else{
        ui->statusBar->hide();
    }
}
void Notepad::toolbar(){
    if(ui->actionTool_bar->isChecked()){
        ui->mainToolBar->show();
    }else{
        ui->mainToolBar->hide();
    }
}

void Notepad::textchanged(){
    this->isSave = false;
}

void Notepad::closeEvent(QCloseEvent * e){

}

void Notepad::on_actionUndo_triggered()
{
    ui->text->undo();
}

void Notepad::on_actionRedo_triggered()
{
    ui->text->redo();
}

void Notepad::on_actionCopy_triggered() {
    ui->text->copy();
}

void Notepad::on_actionCut_triggered()
{
    ui->text->cut();
}

void Notepad::on_actionPaste_triggered()
{
    ui->text->paste();
}

void Notepad::on_actionSelect_All_triggered()
{
    ui->text->selectAll();
}

void Notepad::on_actionDate_time_triggered()
{
    ui->text->textCursor().insertText(QDateTime::currentDateTime().toString("HH:mm dd/MM/yyyy"));
}

void Notepad::on_actionDelete_triggered()
{
    ui->text->textCursor().removeSelectedText();
}

void Notepad::on_actionFont_triggered()
{
    Font fontdlg(this);
    fontdlg.setFont(mFont);
    fontdlg.exec();
    this->mFont = fontdlg.getFont();
    ui->text->setFont(mFont);
}

void Notepad::on_actionOpen_triggered()
{
    filename = QFileDialog::getOpenFileName(this,"Open",".","Text file (*.txt);;All file (*.*)");
    if(filename!=""){
        f.setFileName(filename);
        if(f.open(QFile::ReadOnly|QFile::Text)){
            QTextStream stream(&f);
            ui->text->textCursor().insertText(stream.readAll());
        }
        f.close();
    }
}

void Notepad::on_actionSave_triggered()
{
    if(filename == ""){
        filename = QFileDialog::getSaveFileName(this,"Save",".","Text file (*.txt);;All file (*.*)");
        if(filename!=""){
            f.setFileName(filename);
            if(f.open(QFile::WriteOnly|QFile::Text)){
                QTextStream stream(&f);
                stream << ui->text->toPlainText();
            }
            f.close();
        }
    }else{
        f.setFileName(filename);
        if(f.open(QFile::WriteOnly|QFile::Text)){
            QTextStream stream(&f);
            stream << ui->text->toPlainText();
        }
        f.close();
    }
}
