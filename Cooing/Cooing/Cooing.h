#ifndef COOING_H
#define COOING_H

#include <QtWidgets/QMainWindow>
#include <QtWebKitWidgets>
#include <QWebView> 
#include "ui_Cooing.h"
using namespace std;

class Cooing : public QMainWindow {
	Q_OBJECT

	public:
		Cooing(QWidget *parent = 0);
		~Cooing();

		// void receiveMessage(string message, string from);

	private:
		Ui::Cooing ui;
		void createNewChat(string fileName);

	public slots:
		void doSend();
		void receiveMessage(QString message, QString from);
		void loadfinish();
};

#endif // COOING_H
