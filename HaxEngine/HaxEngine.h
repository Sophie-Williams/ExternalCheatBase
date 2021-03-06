#pragma once

// Including SDKDDKVer.h defines the highest available Windows platform.

// If you wish to build your application for a previous Windows platform, include WinSDKVer.h and
// set the _WIN32_WINNT macro to the platform you wish to support before including SDKDDKVer.h.

#include <SDKDDKVer.h>

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#define _CRT_NON_CONFORMING_SWPRINTFS

#include "HaxApp.h"
#include "../Hax_App/Hax_ROS_Esp.h"

extern std::shared_ptr <CHaxApp> g_haxApp;

static enum EGameCodes
{
	GAME_CODE_NULL,
	GAME_CODE_ROS,
};

class CHaxEngine
{
	public:
		CHaxEngine(EGameCodes eGameCode);
		~CHaxEngine() = default;

		void RegisterHaxApp(const std::shared_ptr <CHaxApp> & haxApp);
		void OnAppNotification(bool bCreated);

	private:
		EGameCodes m_eGameCode;

		std::shared_ptr <CROS_ESP_Hax> m_pRosHaxMgr;
};

