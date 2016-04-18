#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>
#include <QFile>
#include <QFont>

class QWidget;

namespace Ui {
class Notepad;
}

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    explicit Notepad(QWidget *parent = 0);
    ~Notepad();

    void setArg(int argc, char *argv[]) const;
public slots:
    void wrap();
    void status();
    void toolbar();
    void textchanged();
	

protected:
    void closeEvent(QCloseEvent * e);

private slots:
    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionSelect_All_triggered();

    void on_actionDate_time_triggered();

    void on_actionDelete_triggered();

    void on_actionFont_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

private:
    Ui::Notepad *ui;
    bool isSave;
    QString filename;
    QFile f;
    QFont mFont;
};

#endif // NOTEPAD_H
