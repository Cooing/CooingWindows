#include "Global.h"
// #include "Adapter.h"
#include <fstream>

Cooing::Cooing(QWidget *parent)	: QMainWindow(parent) {
	ui.setupUi(this);
	QObject::connect(ui.sendBtn, SIGNAL(clicked()),this, SLOT(doSend()));
	ui.webView->load(QUrl(QString(("file:///" + QDir::currentPath() + "/BubbleChat/user1.html"))));
	bool rtn = QObject::connect(ui.webView, SIGNAL(loadFinished(bool)),this, SLOT(loadfinish()));
	QObject::connect(Global::adapter, SIGNAL(ReceiveMsgSignal(QString, QString)),this, SLOT(receiveMessage(QString, QString)));
	createNewChat("user1");
}

void Cooing::loadfinish()
{
	ui.webView->page()->mainFrame()->setScrollBarValue(Qt::Vertical, ui.webView->page()->mainFrame()->scrollBarMaximum(Qt::Vertical));
}

void Cooing::createNewChat(string fileName) {
	ofstream file;
	file.open ("E://" + fileName + ".html");
	file << "<head>\n";
	file << "<link rel='stylesheet' type='text/css' href='style.css'>\n";
	file << "</head>\n";
	file.close();
}

void Cooing::receiveMessage(QString message, QString from) {
	ui.typeBox->setPlainText(QDir::currentPath() + "\n" + message);
	// ui.webView->load(QUrl(QString(("file:///E:/" + QString(from) + ".html"))));
	// ui.webView->load(QUrl(QString(("../BubbleChat/" + QString(from) + ".html"))));
	ui.webView->load(QUrl(QString(("file:///" + QDir::currentPath() + "/BubbleChat/user1.html"))));
	
	// ui.webView->load(QUrl(QString(("file:///C:/Users/vknguyen1992/Desktop/BubbleChat/BubbleChat.html"))));
}

void Cooing::doSend() {
	//string sendTo = "user1";
	//string message = ui.typeBox->toPlainText().toStdString();
	//// -------------------- Update HTML -----------------------
	//ofstream file;
	//file.open("E://" + sendTo + ".html", std::fstream::app);
	//file << "<div class='bubbledRight me'>\n";
	//file << ui.typeBox->toPlainText().toStdString() + "\n";
	//file << "</div>\n";
	//file.close();
	//// ---------------------- Update -----------------------
	//ui.typeBox->setPlainText("");
	//Global::chat->SendMsg("user1", message);
	//ui.webView->load(QUrl(QString(("file:///E:/" + QString(sendTo.c_str()) + ".html"))));
	//ui.webView->page()->mainFrame()->setScrollBarValue(Qt::Vertical, ui.webView->page()->mainFrame()->scrollBarMaximum(Qt::Vertical));
}

Cooing::~Cooing() {

}