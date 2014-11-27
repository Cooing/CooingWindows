#include "Global.h"
#include "ui_ForgotPassword.h"

ForgotPassword::ForgotPassword(QWidget *parent) : QWidget(parent), ui(new Ui::ForgotPassword)
{
    ui->setupUi(this);
	QObject::connect(ui->resetBtn, SIGNAL(clicked()),this, SLOT(doReset()));
}

void ForgotPassword::closeEvent(QCloseEvent *event)
{
	Global::signinForm->show();
}

void ForgotPassword::doReset()
{

}

ForgotPassword::~ForgotPassword()
{
    delete ui;
}
