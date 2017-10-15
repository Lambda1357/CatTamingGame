#pragma once

#include "stdafx.h"
class StartScene : Scene
{
private:
	enum SceneState
	{
		DEFAULT,
		HOWTO
	};
	enum BackgroundTheme
	{
		HOUSE,
		FOREST,
		PARK,
		AMUSEMENT,
		HALLOWEEN,
		SCHOOL
	};

	SceneState currentState;
	BackgroundTheme currentTheme;
public:

};
