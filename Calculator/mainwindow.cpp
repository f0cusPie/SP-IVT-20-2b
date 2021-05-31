#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mnogochlen.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    selectedLineEdit = ui->lineEdit;
    connect(ui->lineEdit, &QLineEdit::selectionChanged, this , &MainWindow::SelText);
    connect(ui->lineEdit_2, &QLineEdit::selectionChanged, this , &MainWindow::SelText);
    connect(ui->lineEdit_3, &QLineEdit::selectionChanged, this , &MainWindow::SelText);
    connect(ui->lineEdit_4, &QLineEdit::selectionChanged, this , &MainWindow::SelText);
    connect(ui->lineEdit_5, &QLineEdit::selectionChanged, this , &MainWindow::SelText);
    connect(ui->lineEdit_6, &QLineEdit::selectionChanged, this , &MainWindow::SelText);
    connect(ui->lineEdit_7, &QLineEdit::selectionChanged, this , &MainWindow::SelText);
    connect(ui->lineEdit_8, &QLineEdit::selectionChanged, this , &MainWindow::SelText);
    connect(ui->lineEdit_9, &QLineEdit::selectionChanged, this , &MainWindow::SelText);

    connect(ui->lineEdit_10, &QLineEdit::selectionChanged, this , &MainWindow::SelText);
    connect(ui->lineEdit_11, &QLineEdit::selectionChanged, this , &MainWindow::SelText);
    connect(ui->lineEdit_12, &QLineEdit::selectionChanged, this , &MainWindow::SelText);
    connect(ui->lineEdit_13, &QLineEdit::selectionChanged, this , &MainWindow::SelText);
    connect(ui->lineEdit_14, &QLineEdit::selectionChanged, this , &MainWindow::SelText);
    connect(ui->lineEdit_15, &QLineEdit::selectionChanged, this , &MainWindow::SelText);
    connect(ui->lineEdit_16, &QLineEdit::selectionChanged, this , &MainWindow::SelText);
    connect(ui->lineEdit_17, &QLineEdit::selectionChanged, this , &MainWindow::SelText);
    connect(ui->lineEdit_18, &QLineEdit::selectionChanged, this , &MainWindow::SelText);
    connect(ui->lineEdit_20, &QLineEdit::selectionChanged, this , &MainWindow::SelText);

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(Znak()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(Znak()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(Znak()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(Znak()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(Znak()));

    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(Ochistit()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(Vichislit()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::Znak() {
    try {
        QPushButton* button = (QPushButton*) qApp->focusWidget();
        if (button != nullptr)
            ui->lineEdit_19->setText(button->text());
    }
    catch (...) {

    }

}

void MainWindow::SelText() {
    try {
        QLineEdit* edit = (QLineEdit*) qApp->focusWidget();
        QString s = edit->metaObject()->className();


        if (edit != nullptr && s.contains("ineEdit"))
            selectedLineEdit = edit;
    }

    catch (...) {

    }
}

void MainWindow::Ochistit() {
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_7->setText("");
    ui->lineEdit_8->setText("");
    ui->lineEdit_9->setText("");
    ui->lineEdit_10->setText("");

    ui->lineEdit_11->setText("");
    ui->lineEdit_12->setText("");
    ui->lineEdit_13->setText("");
    ui->lineEdit_14->setText("");
    ui->lineEdit_15->setText("");
    ui->lineEdit_16->setText("");
    ui->lineEdit_17->setText("");
    ui->lineEdit_18->setText("");
    ui->lineEdit_19->setText("");
    ui->lineEdit_20->setText("");

    ui->lineEdit_21->setText("");
    ui->lineEdit_22->setText("");

    selectedLineEdit->setFocus();
}

void MainWindow::Vichislit()
{
    int count1 = 9, count2 = 9;
    double *coefs1 = ReadNumbers(count1, 1), *coefs2 = ReadNumbers(count2, 2);

    Mnogochlen m1(count1, coefs1);
    Mnogochlen m2(count2, coefs2);
    Mnogochlen res(count1, coefs1);

    switch (ui->lineEdit_19->text().toLatin1()[0])
    {
    case '+':
        res = m1 + m2;
        break;

    case '-':
        res = m1 - m2;
        break;

    case '*':
        res = m1 * m2;
        break;

    case '/':
        res = m1 / m2;
        break;

    case '^':
        res = m1.Stepen(m2);
        ui->lineEdit_10->setText("");
        ui->lineEdit_11->setText("");
        ui->lineEdit_12->setText("");
        ui->lineEdit_13->setText("");
        ui->lineEdit_14->setText("");
        ui->lineEdit_15->setText("");
        ui->lineEdit_16->setText("");
        ui->lineEdit_17->setText("");
        ui->lineEdit_18->setText("");
        break;
    }

    ui->lineEdit_21->setText(res.ToString());
    ui->lineEdit_22->setText(QString::number(res.F(ui->lineEdit_20->text().toDouble())));
}

double* MainWindow::ReadNumbers(int& count, int n) {
    QVector<int> coefs1;
    bool nol = true;

    if (n == 1) {
        if (ui->lineEdit->text().toDouble() == 0 && nol)
            count--;
        else {
            nol = false;
            coefs1.push_back(ui->lineEdit->text().toDouble());
        }

        if (ui->lineEdit_2->text().toDouble() == 0 && nol)
            count--;
        else {
            nol = false;
            coefs1.push_back(ui->lineEdit_2->text().toDouble());
        }

        if (ui->lineEdit_3->text().toDouble() == 0 && nol)
            count--;
        else {
            nol = false;
            coefs1.push_back(ui->lineEdit_3->text().toDouble());
        }

        if (ui->lineEdit_4->text().toDouble() == 0 && nol)
            count--;
        else {
            nol = false;
            coefs1.push_back(ui->lineEdit_4->text().toDouble());
        }

        if (ui->lineEdit_5->text().toDouble() == 0 && nol)
            count--;
        else {
            nol = false;
            coefs1.push_back(ui->lineEdit_5->text().toDouble());
        }

        if (ui->lineEdit_6->text().toDouble() == 0 && nol)
            count--;
        else {
            nol = false;
            coefs1.push_back(ui->lineEdit_6->text().toDouble());
        }

        if (ui->lineEdit_7->text().toDouble() == 0 && nol)
            count--;
        else {
            nol = false;
            coefs1.push_back(ui->lineEdit_7->text().toDouble());
        }

        if (ui->lineEdit_8->text().toDouble() == 0 && nol)
            count--;
        else {
            nol = false;
            coefs1.push_back(ui->lineEdit_8->text().toDouble());
        }

        coefs1.push_back(ui->lineEdit_9->text().toDouble());

        double* data = new double[count];
        for (int i = 0; i < count; i++)
            data[i] = coefs1[count - i - 1];

        return data;
    }

    else {
        if (ui->lineEdit_10->text().toDouble() == 0 && nol)
            count--;
        else {
            nol = false;
            coefs1.push_back(ui->lineEdit_10->text().toDouble());
        }

        if (ui->lineEdit_11->text().toDouble() == 0 && nol)
            count--;
        else {
            nol = false;
            coefs1.push_back(ui->lineEdit_11->text().toDouble());
        }

        if (ui->lineEdit_12->text().toDouble() == 0 && nol)
            count--;
        else {
            nol = false;
            coefs1.push_back(ui->lineEdit_12->text().toDouble());
        }

        if (ui->lineEdit_13->text().toDouble() == 0 && nol)
            count--;
        else {
            nol = false;
            coefs1.push_back(ui->lineEdit_13->text().toDouble());
        }

        if (ui->lineEdit_14->text().toDouble() == 0 && nol)
            count--;
        else {
            nol = false;
            coefs1.push_back(ui->lineEdit_14->text().toDouble());
        }

        if (ui->lineEdit_15->text().toDouble() == 0 && nol)
            count--;
        else {
            nol = false;
            coefs1.push_back(ui->lineEdit_15->text().toDouble());
        }

        if (ui->lineEdit_16->text().toDouble() == 0 && nol)
            count--;
        else {
            nol = false;
            coefs1.push_back(ui->lineEdit_16->text().toDouble());
        }

        if (ui->lineEdit_17->text().toDouble() == 0 && nol)
            count--;
        else {
            nol = false;
            coefs1.push_back(ui->lineEdit_17->text().toDouble());
        }

        coefs1.push_back(ui->lineEdit_18->text().toDouble());

        double* data = new double[count];
        for (int i = 0; i < count; i++)
            data[i] = coefs1[count - i - 1];

        return data;
    }
}
