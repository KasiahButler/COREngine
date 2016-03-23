#include "Assets.h"
#include "sfwdraw.h"
#include "Window.h"
#include "Matrix4.h"
#include <assert.h>

void Asset::loadTexture(const std::string & name, const char * path)
{
	assert(Window::instance().isInitialized() && "Window is not initialized!");

	Texture temp;

	temp._handle = sfw::loadTextureMap(path);
	temp.height = sfw::getTextureHeight(temp._handle);
	temp.width = sfw::getTextureWidth(temp._handle);

	textures[name] = temp;
}

Asset::Texture Asset::getTexture(const std::string & name) { return textures[name]; }

void Asset::drawTexture(const std::string & name, const COR::Mat3 &m)
{
	sfw::drawTextureMatrix(getTexture(name)._handle, 0, WHITE, COR::M3toM4(m, 0).cell);
}