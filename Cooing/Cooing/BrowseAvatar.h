#ifndef BROWSEAVATAR_H
#define BROWSEAVATAR_H

#include <QWidget>
#include <QFileDialog>
#include <QScrollArea>

namespace Ui {
	class BrowseAvatar;
}

class BrowseAvatar : public QWidget {
    Q_OBJECT

	protected:
		void closeEvent(QCloseEvent *event);

	public:
		explicit BrowseAvatar(QWidget *parent = 0);
		~BrowseAvatar();

	private:
		Ui::BrowseAvatar *ui;

	public slots:
		void doSubmit();
		void doBrowse();
};

#endif // BROWSEAVATAR_H
