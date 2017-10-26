#pragma once
#include <d3d11.h>
#include <DirectXColors.h>
#include "DXERR/dxerr.h"

#pragma comment (lib, "d3d11.lib")

#ifdef _DEBUG
#ifndef HR
#define HR(x) \
{\
	HRESULT hr = x; \
	if(FAILED(hr))\
	{\
	DXTraceW(__FILEW__, __LINE__, hr, L#x, TRUE);\
	}\
}
#endif
#ifndef HR
#define HR(x) x;
#endif
#endif // !HR


namespace Memory
{
	template <class T> void SafeDelete(T& t)
	{
		if (t)
		{
			delete t;
			t = nullptr;
		}
	}

	template <class T> void SafeDeleleArr(T& t)
	{
		if (t)
		{
			delete[] t;
			t = nullptr;
		}
	}

	template <class T> void SafeRelease(T& t)
	{
		if (t)
		{
			t->Release();
			t = nullptr;
		}
	}

}

namespace Utility
{
	void GetTextureDim(ID3D11Resource* res, UINT* width, UINT* height);
}

namespace Directions
{
	enum Direction 
	{ 
		LEFT	= 0, 
		RIGHT	= 1, 
		UP		= 2, 
		DOWN	= 3
	};
}
