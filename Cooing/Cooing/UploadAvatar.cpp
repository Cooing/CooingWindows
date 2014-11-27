#include "Global.h"
#include "ui_UploadAvatar.h"

UploadAvatar::UploadAvatar(QWidget *parent) : QWidget(parent), ui(new Ui::UploadAvatar), camera(0), imageCapture(0)
{
    ui->setupUi(this);
	setUpCamera();

	QObject::connect(ui->captureBtn, SIGNAL(clicked()),this, SLOT(doCapture()));
	QObject::connect(ui->retryBtn, SIGNAL(clicked()),this, SLOT(doStart()));
	QObject::connect(ui->submitBtn, SIGNAL(clicked()),this, SLOT(doSubmit()));
	QObject::connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(doProcessCapturedImage(int,QImage)));
}

void UploadAvatar::closeEvent(QCloseEvent *event)
{
	Global::registerForm->setEnabled(true);
}

void UploadAvatar::setUpCamera()
{
	QByteArray cameraDevice;
	// ----------------- Scan Camera Devices ------------------
	foreach(const QByteArray &deviceName, QCamera::availableDevices()) {
        QString description = camera->deviceDescription(deviceName);
        if (cameraDevice.isEmpty())
			cameraDevice = deviceName;
		ui->deviceList->addItem(deviceName, QVariant(deviceName));
    }
	// --------------------- Check Empty ----------------------
	if (cameraDevice.isEmpty())
		camera = new QCamera;
	else
		camera = new QCamera(cameraDevice);
	// -------------------- Display Camera --------------------
	imageCapture = new QCameraImageCapture(camera);
	cameraDisplay = new QVideoWidget();
	cameraDisplay->setAspectRatioMode(Qt::KeepAspectRatioByExpanding);
	layout = new QHBoxLayout();
	layout->addWidget(cameraDisplay);
	ui->cameraDisplayWidget->setLayout(layout);
	camera->setViewfinder(cameraDisplay);
	// ----------------- Update Mode Capture ------------------
	if (camera->isCaptureModeSupported(QCamera::CaptureStillImage))
		camera->setCaptureMode(QCamera::CaptureStillImage);
	doStart();
}

void UploadAvatar::doCapture()
{
	ui->avatar->setVisible(true);
	ui->cameraDisplayWidget->setVisible(false);
	ui->captureBtn->setVisible(false);
	ui->retryBtn->setVisible(true);	
	imageCapture->capture("CooingAvatar");
}

void UploadAvatar::doStart()
{
	ui->avatar->clear();
	ui->avatar->setVisible(false);
	ui->cameraDisplayWidget->setVisible(true);
	ui->captureBtn->setVisible(true);
	ui->retryBtn->setVisible(false);
	camera->start();
}

void UploadAvatar::doSubmit()
{

}

void UploadAvatar::doProcessCapturedImage(int requestId, const QImage& img)
{
	Q_UNUSED(requestId);
	capturedImage = new QImage();
	*capturedImage = QPixmap::fromImage(img).scaledToHeight(ui->avatar->height(), Qt::SmoothTransformation).toImage();
    ui->avatar->setPixmap(QPixmap::fromImage(*capturedImage));
	ui->avatar->setAlignment(Qt::AlignHCenter);
	camera->stop();
}

UploadAvatar::~UploadAvatar()
{
	delete layout;
	delete capturedImage;
	delete cameraDisplay;
	delete imageCapture;
    delete camera;
    delete ui;
}
