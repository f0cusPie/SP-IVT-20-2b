#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QLineEdit* selectedLineEdit;
    QString DeleteLastSymbol(QString zhertva);
    double* ReadNumbers(int& count, int n);

private slots:
    void Znak();
    void SelText();
    void Ochistit();
    void Vichislit();
};
#endif // MAINWINDOW_H
