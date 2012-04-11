#include <Windows.h>
#include <D3D10.h>
#include <D3DX10.h>

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#define SCREENWIDTH (1024)
#define _SCREENHEIGHT (768)

#define SAFE_DELETE(x) if(x) { delete(x); (x) = NULL; }