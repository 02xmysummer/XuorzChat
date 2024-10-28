#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "global.h"
#include <QRegularExpression>
#include <QDebug>
RegisterDialog::RegisterDialog(QWidget *parent) : QDialog(parent), ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    ui->password_edit->setEchoMode(QLineEdit::Password);
    ui->confirm_edit->setEchoMode(QLineEdit::Password);
    ui->err_tip->setProperty("state", "normal");
    repolish(ui->err_tip);
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}
void RegisterDialog::showTip(QString str, bool b_ok)
{
    ui->err_tip->setText(str);
    if (b_ok)
        ui->err_tip->setProperty("state", "normal");
    else
        ui->err_tip->setProperty("state", "err");

    repolish(ui->err_tip);
}
void RegisterDialog::on_get_code_clicked()
{
    auto email = ui->email_edit->text();
    QRegularExpression regex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
    bool match = regex.match(email).hasMatch();
    if (match) {
        qDebug() << email;
    } else {
        //提示邮箱不正确
        showTip(tr("邮箱地址不正确"), false);
    }
}
