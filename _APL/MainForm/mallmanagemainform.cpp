#include "mallmanagemainform.h"
#include "ui_mallmanagemainform.h"

mallmanageMainForm::mallmanageMainForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mallmanageMainForm)
{
    ui->setupUi(this);

    ui->toolBox->setCurrentIndex(0);
}

mallmanageMainForm::~mallmanageMainForm()
{
    delete ui;
}

