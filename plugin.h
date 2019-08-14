
#ifndef Plugin_H
#define Plugin_H

#include "pluginapi.h"
#include "scplugin.h"

/*! \brief See scplugin.h and pluginmanager.{cpp,h} for detail on what these methods do.
That documentatation is not duplicated here.
Please don't implement the functionality of your plugin here; do that
in Pluginimpl.h and Pluginimpl.cpp. */
class PLUGIN_API Plugin : public ScActionPlugin
{
	Q_OBJECT

	public:
        Plugin();
        virtual ~Plugin();
        virtual bool run(ScribusDoc* doc, const QString& target = QString());
		virtual const QString fullTrName() const;
		virtual const AboutData* getAboutData() const;
		virtual void deleteAboutData(const AboutData* about) const;
		virtual void languageChange();
		virtual void addToMainWindowMenu(ScribusMainWindow *) {};

		// Special features (none)
};

extern "C" PLUGIN_API int script_docker_getPluginAPIVersion();
extern "C" PLUGIN_API ScPlugin* script_docker_getPlugin();
extern "C" PLUGIN_API void script_docker_freePlugin(ScPlugin* plugin);

#endif
