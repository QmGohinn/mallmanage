#include "mallmanagemainform.h"
#include "ui_mallmanagemainform.h"

#include <QMessageBox>
#include <_BK/mallGlobal.h>
#include <QDateTime>

mallmanageMainForm::mallmanageMainForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::mallmanageMainForm)
{
    ui->setupUi(this);
    ui->toolBox->setCurrentIndex(0);

    for(auto _it : mallGloval::g_currentGood){
        this->GoodsIntoTable(_it);
    }

    ui->tableWidget->horizontalHeader()->show();

    for(auto _it : mallGloval::g_eatGood){
        ui->comboBox_3->addItem(_it.m_name);
        ui->lineEdit_4->setText(QString("%1").arg(_it.m_sellPrice));
        ui->lineEdit_5->setText(QString("%1").arg(_it.m_num));
    }
}

mallmanageMainForm::~mallmanageMainForm()
{
    delete ui;
}

void mallmanageMainForm::GoodsIntoTable(Goods _good)
{
    ui->tableWidget->insertRow(0);

    ui->tableWidget->setItem(0, 0, new QTableWidgetItem(_good.m_name));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem(QString("%1").arg(_good.m_inputPrice)));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem(QString("%1").arg(_good.m_sellPrice)));
    ui->tableWidget->setItem(0, 3, new QTableWidgetItem(QString("%1").arg(_good.m_num)));
}

void mallmanageMainForm::updateCombox()
{
    ui->comboBox_3->clear();
    switch (ui->comboBox_2->currentIndex()) {
    case 0:
        for(auto _it : mallGloval::g_eatGood){
            ui->comboBox_3->addItem(_it.m_name);
        }
        break;
    case 1:
        for(auto _it : mallGloval::g_phoneGood){
            ui->comboBox_3->addItem(_it.m_name);
        }
        break;
    case 2:
        for(auto _it : mallGloval::g_clothGood){
            ui->comboBox_3->addItem(_it.m_name);
        }
        break;
    }
}

void mallmanageMainForm::updateTable()
{
    while (ui->tableWidget->rowCount()) {
        ui->tableWidget->removeRow(0);
    }

    for(auto& _it : mallGloval::g_currentGood){
        GoodsIntoTable(_it);
    }
}


void mallmanageMainForm::on_pushButton_clicked()
{
    if(ui->lineEdit->text().compare("") == 0
            || ui->lineEdit_2->text().compare("") == 0
            || ui->lineEdit_3->text().compare("") == 0)
    {
        QMessageBox::critical(this, "提 示", "请补全商品信息!", "知道了");
        return;
    }

    if(ui->spinBox->text() == "0"){
        QMessageBox::critical(this, "提 示", "数量不能为零!", "知道了");
        return;
    }

    Goods _newGood(ui->lineEdit_3->text(),
                   ui->lineEdit->text().toFloat(),
                   ui->lineEdit_2->text().toFloat(),
                   ui->spinBox->text().toInt());
    this->GoodsIntoTable(_newGood);
    //    QMessageBox::information(this, "提 示", "入库完成!", "知道了");
    mallGloval::g_currentGood.push_back(_newGood);
    switch (ui->comboBox->currentIndex()) {
    case 0:
        mallGloval::g_eatGood.push_back(_newGood);
        break;
    case 1:
        mallGloval::g_phoneGood.push_back(_newGood);
        break;
    case 2:
        mallGloval::g_clothGood.push_back(_newGood);
        break;
    }
    updateCombox();
    return;
}

void mallmanageMainForm::on_pushButton_2_clicked()
{
    while (ui->tableWidget->rowCount()) {
        ui->tableWidget->removeRow(0);
    }

    ui->spinBox_2->setValue(0);
    ui->lineEdit_7->clear();

    mallGloval::g_currentGood.clear();
    mallGloval::g_eatGood.clear();
    mallGloval::g_clothGood.clear();
    mallGloval::g_phoneGood.clear();
    updateCombox();
}

void mallmanageMainForm::on_comboBox_2_currentIndexChanged(int index)
{
    ui->comboBox_3->clear();
    switch (index) {
    case 0:
        for(auto _it : mallGloval::g_eatGood){
            ui->comboBox_3->addItem(_it.m_name);
        }
        break;
    case 1:
        for(auto _it : mallGloval::g_phoneGood){
            ui->comboBox_3->addItem(_it.m_name);
        }
        break;
    case 2:
        for(auto _it : mallGloval::g_clothGood){
            ui->comboBox_3->addItem(_it.m_name);
        }
        break;
    }
}

void mallmanageMainForm::on_comboBox_3_currentTextChanged(const QString &arg1)
{
    ui->spinBox_2->setValue(0);
    ui->lineEdit_7->setText("");
    for(auto _it : mallGloval::g_currentGood){
        if(_it.m_name.compare(arg1) == 0){
            ui->lineEdit_4->setText(QString("%1").arg(_it.m_sellPrice));
            ui->lineEdit_5->setText(QString("%1").arg(_it.m_num));
            return;
        }
    }
}

void mallmanageMainForm::on_spinBox_2_textChanged(const QString &arg1)
{
    if(arg1.toInt() > ui->lineEdit_5->text().toInt()){
        QMessageBox::critical(this, "提 示", "库存不足", "知道了");
        ui->spinBox_2->setValue(ui->lineEdit_5->text().toInt());
        return;
    }

    ui->lineEdit_7->setText(QString("%1").arg(ui->lineEdit_4->text().toFloat() * ui->spinBox_2->text().toInt()));
    return;
}
#include <QDebug>
void mallmanageMainForm::on_pushButton_3_clicked()
{
    if(ui->spinBox_2->text().compare("0") == 0){
        QMessageBox::critical(this, "提 示", "数量不能为零!", "知道了");
        return;
    }

    QString _str = "";
    _str = QString("%1 售出: %2\n         数量: %3 单价: %4￥ 总价: %5￥\n------------------------------------------\n")
            .arg(QTime::currentTime().toString())
            .arg(ui->comboBox_3->currentText())
            .arg(ui->spinBox_2->text())
            .arg(ui->lineEdit_7->text().toFloat() / ui->spinBox_2->text().toInt())
            .arg(ui->lineEdit_7->text());
    mallGloval::g_sellTotal += ui->lineEdit_7->text().toFloat();
    ui->textEdit->setText(ui->textEdit->toPlainText() + _str);

    for(auto &_it : mallGloval::g_currentGood){
        if(_it.m_name.compare(ui->comboBox_3->currentText()) == 0){
            _it.m_num = _it.m_num - ui->spinBox_2->value();
            ui->lineEdit_5->setText(QString("%1").arg(_it.m_num));
            ui->spinBox_2->setValue(0);
            ui->lineEdit_7->clear();
        }
    }
    updateTable();
    ui->pushButton_4->setEnabled(true);
}

void mallmanageMainForm::on_pushButton_4_clicked()
{
    QString _str = "";
    _str = QString("------------------------------------------\n日 期:%1\n订 单 号:%2\n付款总金额:%3\n下单成功!\n\n\n")
            .arg(QDateTime::currentDateTime().toString())
            .arg(QString("%1").arg(mallGloval::g_orderID))
            .arg(QString("%1").arg(mallGloval::g_sellTotal));
    ui->textEdit->setText(ui->textEdit->toPlainText() + _str);

    mallGloval::g_orderID += 1;
    mallGloval::g_sellTotal = 0;
    ui->pushButton_4->setEnabled(false);
}
