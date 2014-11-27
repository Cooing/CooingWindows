#ifndef FORGOTPASSWORD_H
#define FORGOTPASSWORD_H

#include <QWidget>

namespace Ui {
	class ForgotPassword;
}

class ForgotPassword : public QWidget {
    Q_OBJECT

	protected:
		void closeEvent(QCloseEvent *event);

	public:
		explicit ForgotPassword(QWidget *parent = 0);
		~ForgotPassword();

	private:
		Ui::ForgotPassword *ui;

	public slots:
		void doReset();
};

#endif // FORGOTPASSWORD_H
