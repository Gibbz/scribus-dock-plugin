#include "scriptdocker.h"
#include "scribusdoc.h"
#include "ui/scmessagebox.h"

#include <QString>
#include <QMessageBox>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>

// Initialize members here, if any
/*
ScriptDocker::ScriptDocker() : QObject(0)
{
}*/


ScriptDocker::ScriptDocker(QWidget* parent, const char* name, Qt::WindowFlags f) : ScDockPalette(parent, name, f)
{
    //	resize( 220, 240 );
    setMinimumSize( QSize( 220, 240 ) );
    setObjectName(QString::fromLocal8Bit("Tree"));
    setSizePolicy( QSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum));
    containerWidget = new QWidget(this);


    QLabel *filterLabel = new QLabel( tr("Filter:") );

    QGridLayout* layout = new QGridLayout;
    layout->addWidget( filterLabel, 0, 0 );

    layout->setContentsMargins( 3, 3, 3, 3);
    containerWidget->setLayout( layout );
    setWidget( containerWidget );


    // signals and slots connections
}


void ScriptDocker::setPaletteShown(bool visible)
{
    ScDockPalette::setPaletteShown(visible);
    if (visible)
        qDebug() << "Visible!";
}



bool ScriptDocker::run(const QString & target, ScribusDoc* doc)
{
    setPaletteShown(true);

    /*
	// Do the bulk of your work here
	ScMessageBox::information(
			(QWidget*)doc->scMW(),
			tr("Scribus - My Plugin"),
			tr("The plugin worked!"),
			QMessageBox::Ok|QMessageBox::Default|QMessageBox::Escape,
			QMessageBox::NoButton);
	return true;
    */
}

void ScriptDocker::setMainWindow(ScribusMainWindow *mw)
{
    m_MainWindow=mw;
    //if (m_MainWindow==nullptr)
        //clearPalette();
}
