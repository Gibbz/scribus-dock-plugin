#ifndef SCRIPTDOCKER_H
#define SCRIPTDOCKER_H

#include <QObject>
#include "scribusapi.h"
#include "ui/scdockpalette.h"

class QString;
class ScribusDoc;
class ScribusMainWindow;

class SCRIBUS_API ScriptDocker : public ScDockPalette
{
	Q_OBJECT
	public:
        ScriptDocker(QWidget* parent = 0, const char* name = "Script Docker", Qt::WindowFlags f = 0);
        ~ScriptDocker() {};
        bool run(const QString & target, ScribusDoc* doc=0);
        void setPaletteShown(bool visible);
        void setMainWindow(ScribusMainWindow *mw);

    protected:
        QWidget* containerWidget;
        ScribusMainWindow* m_MainWindow;
};

#endif
