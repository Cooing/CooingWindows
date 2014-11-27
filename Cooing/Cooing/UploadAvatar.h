#ifndef UPLOADAVATAR_H
#define UPLOADAVATAR_H

#include <QCamera>
#include <QCameraImageCapture>
#include <QWidget>
#include <QVideoWidget>
#include <QLayout>

namespace Ui {
	class UploadAvatar;
}

class UploadAvatar : public QWidget {
    Q_OBJECT

	protected:
		void closeEvent(QCloseEvent *event);

	public:
		explicit UploadAvatar(QWidget *parent = 0);
		~UploadAvatar();

	private:
		Ui::UploadAvatar *ui;

		QLayout *layout;
		QCamera *camera;
		QImage *capturedImage;
		QCameraImageCapture *imageCapture;
		QVideoWidget *cameraDisplay;

		void setUpCamera();

	public slots:
		void doCapture();
		void doStart();
		void doSubmit();
		void doProcessCapturedImage(int requestId, const QImage& img);
};

#endif // UPLOADAVATAR_H
