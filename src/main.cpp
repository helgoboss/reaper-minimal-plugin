#define REAPERAPI_IMPLEMENT

#include <reaper_plugin.h>
#include <reaper_plugin_functions.h>

extern "C" {
REAPER_PLUGIN_DLL_EXPORT int REAPER_PLUGIN_ENTRYPOINT(REAPER_PLUGIN_HINSTANCE hInstance, reaper_plugin_info_t* rec) {
  if (!rec) {
    return 0;
  }
  if (rec->caller_version != REAPER_PLUGIN_VERSION || !rec->GetFunc) {
    return 0;
  }
  REAPERAPI_LoadAPI(rec->GetFunc);
  ShowConsoleMsg("Loaded reaper-minimal-plugin");
  MessageBox(nullptr, "Hello from reaper-minimal-plugin", "reaper-minimal-plugin", 0);
  return 1;
}
};
