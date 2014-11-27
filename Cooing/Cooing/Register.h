#ifndef REGISTER_H
#define REGISTER_H

#include <QWidget>

namespace Ui {
	class Register;
}

class Register : public QWidget {
    Q_OBJECT

	protected:
		void closeEvent(QCloseEvent *event);

	public:
		explicit Register(QWidget *parent = 0);
		~Register();

	private:
		Ui::Register *ui;
		bool registerSucceeded;

	public slots:
		void doRegister();
		void doCameraAvatar();
		void doUploadAvatar();
};

#endif // REGISTER_H
