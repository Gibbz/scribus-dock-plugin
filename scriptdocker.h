#ifndef SCRIPTDOCKER_H
#define SCRIPTDOCKER_H

#include <QObject>
#include "scribusapi.h"
#include "ui/scdockpalette.h"
#include "ui_scriptdocker.h"

class QString;
class ScribusDoc;
class ScribusMainWindow;

// https://forum.qt.io/topic/80898/expected-class-name-before-token-error/3
class SCRIBUS_API ScriptDocker : public ScDockPalette, Ui::ScriptDocker
{
	Q_OBJECT
	public:
		ScriptDocker(QWidget* parent);
		~ScriptDocker() {};
		bool run(const QString & target, ScribusDoc* doc=0);
		void setPaletteShown(bool visible);
		void setMainWindow(ScribusMainWindow *mw);

	protected:
		//Ui::ScriptDocker ui;
		QWidget* containerWidget;
		ScribusMainWindow* m_MainWindow;
};

#endif // scriptdocker_h
