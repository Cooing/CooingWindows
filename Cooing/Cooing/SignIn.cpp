#include "Global.h"
#include "Adapter.h"
#include "ui_SignIn.h"

SignIn::SignIn(QWidget *parent) : QWidget(parent), ui(new Ui::SignIn) {
	ui->setupUi(this);
	QObject::connect(ui->signinBtn, SIGNAL(clicked()),this, SLOT(doSignIn()));
	QObject::connect(ui->registerBtn, SIGNAL(clicked()),this, SLOT(doRegister()));
	QObject::connect(ui->forgotPasswordBtn, SIGNAL(clicked()),this, SLOT(doForgotPassword()));
}

void SignIn::doSignIn() {
	Global::chat = new SecureChat::XmppChatProcess();
	// Adapter *adapter = new Adapter();
	Global::adapter = new Adapter();
	Global::chat->SetXmppAdapter((SecureChat::XmppGeneralChatAdapter *)Global::adapter);

	bool isLoginSucceeded = Global::chat->Login(Global::server, Global::host, ui->username->text().toStdString(), ui->password->text().toStdString());
	if (isLoginSucceeded) {
		this->hide();
		Global::mainForm = new Cooing();
		Global::mainForm->show();
	}
}

void SignIn::doRegister() {
	this->hide();
	Global::registerForm = new Register();
	Global::registerForm->show();
}

void SignIn::doForgotPassword() {
	this->hide();
	Global::forgotpasswordForm = new ForgotPassword();
	Global::forgotpasswordForm->show();
}

SignIn::~SignIn()
{
	delete ui;
	delete Global::chat;
	delete Global::mainForm;
	delete Global::registerForm;
	delete Global::uploadavatarForm;
	delete Global::browseavatarForm;
	delete Global::forgotpasswordForm;
}
