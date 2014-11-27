#include "Global.h"
#include "ui_BrowseAvatar.h"

BrowseAvatar::BrowseAvatar(QWidget *parent) : QWidget(parent), ui(new Ui::BrowseAvatar) {
    ui->setupUi(this);
	QObject::connect(ui->submitBtn, SIGNAL(clicked()),this, SLOT(doSubmit()));
	QObject::connect(ui->browseBtn, SIGNAL(clicked()),this, SLOT(doBrowse()));
}

void BrowseAvatar::closeEvent(QCloseEvent *event)
{
	Global::registerForm->setEnabled(true);
}

void BrowseAvatar::doSubmit() {
}

void BrowseAvatar::doBrowse() {
	ui->address->setText(QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("JPEG Images (*.jpg *.jpeg);;PNG Images (*.png);;Bitmap Image (*.bmp);;All File (*.*)")));
	QPixmap loadedImage = QPixmap(ui->address->text());
	ui->avatar->setPixmap(loadedImage);
	ui->avatar->resize(loadedImage.size());
	// ui->displayWidget->grab().save("huan.png");
}

BrowseAvatar::~BrowseAvatar() {
    delete ui;
}