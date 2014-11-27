#include "Global.h"
#include "ui_Register.h"

Register::Register(QWidget *parent) : QWidget(parent), ui(new Ui::Register) {
    ui->setupUi(this);
	QObject::connect(ui->registerBtn, SIGNAL(clicked()),this, SLOT(doRegister()));
	QObject::connect(ui->cameraAvatarBtn, SIGNAL(clicked()),this, SLOT(doCameraAvatar()));
	QObject::connect(ui->uploadAvatarBtn, SIGNAL(clicked()),this, SLOT(doUploadAvatar()));
	registerSucceeded = false;
}

void Register::closeEvent(QCloseEvent *event)
{
	if (!registerSucceeded)
		Global::signinForm->show();
}

void Register::doRegister() {
	
}

void Register::doCameraAvatar() {
	this->setDisabled(true);
	Global::uploadavatarForm = new UploadAvatar();
	Global::uploadavatarForm->show();
}

void Register::doUploadAvatar() {
	this->setDisabled(true);
	Global::browseavatarForm = new BrowseAvatar();
	Global::browseavatarForm->show();
}

Register::~Register() {
    delete ui;
}