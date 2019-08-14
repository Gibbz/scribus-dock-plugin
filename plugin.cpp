#include "plugin.h"
#include "scriptdocker.h"
#include "scribuscore.h"
#include "scribusdoc.h"

// Please don't implement the functionality of your plugin here; do that
// in ScriptDocker.h and ScriptDocker.cpp .

Plugin::Plugin() : ScActionPlugin()
{
	// Set action info in languageChange, so we only have to do
	// it in one place.
	languageChange();
}

Plugin::~Plugin() {};

void Plugin::languageChange()
{
	// Action name
    m_actionInfo.name = "Script Docker";
	// Action text for menu, including &accel
    m_actionInfo.text = tr("&Script Docker");
	// Menu
    m_actionInfo.menu = "Extras";
	m_actionInfo.enabledOnStartup = true;
}

const QString Plugin::fullTrName() const
{
    return QObject::tr("Script Docker");
}

const ScActionPlugin::AboutData* Plugin::getAboutData() const
{
	AboutData* about = new AboutData;
	Q_CHECK_PTR(about);
	return about;
}

void Plugin::deleteAboutData(const AboutData* about) const
{
	Q_ASSERT(about);
	delete about;
}


bool Plugin::run(ScribusDoc* doc, const QString& target)
{
    ScribusMainWindow* scmw=(doc==0)?ScCore->primaryMainWindow():doc->scMW();
    ScriptDocker *docker = new ScriptDocker(scmw);
    docker->setMainWindow(scmw);

    Q_CHECK_PTR(docker);
    bool result = docker->run(target, doc);
    delete docker;
    return result;
}


// Low level plugin API
int script_docker_getPluginAPIVersion()
{
	return PLUGIN_API_VERSION;
}

ScPlugin* script_docker_getPlugin()
{
    Plugin* plug = new Plugin();
	Q_CHECK_PTR(plug);
	return plug;
}

void script_docker_freePlugin(ScPlugin* plugin)
{
    Plugin* plug = dynamic_cast<Plugin*>(plugin);
	Q_ASSERT(plug);
	delete plug;
}
