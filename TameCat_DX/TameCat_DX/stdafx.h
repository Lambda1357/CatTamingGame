#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN

// Windows
#include <windows.h>
#include <crtdbg.h>

// C
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <timeapi.h>

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "msimg32.lib")

// DirectX9
#include <d3d9.h>
#include <d3dx9.h>

#pragma comment(lib, "./x86/d3d9.lib")
#pragma comment(lib, "./x86/d3dx9.lib")

// Custom
#include "SimpleFunction.h"
#include "ImageManager.h"

#include "MainProc.h"
#include "WinMain.h"

extern HWND hWnd;
extern LPDIRECT3DDEVICE9 lpd3dDevice;