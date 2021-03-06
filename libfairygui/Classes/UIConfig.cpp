#include "UIConfig.h"

NS_FGUI_BEGIN
USING_NS_CC;

std::string UIConfig::defaultFont = "";
std::string UIConfig::buttonSound = "";
float UIConfig::buttonSoundVolumeScale = 1;
int UIConfig::defaultScrollStep = 25;
float UIConfig::defaultScrollDecelerationRate = 0.967f;
bool UIConfig::defaultScrollTouchEffect = true;
bool UIConfig::defaultScrollBounceEffect = true;
ScrollBarDisplayType UIConfig::defaultScrollBarDisplay = ScrollBarDisplayType::DEFAULT;
std::string UIConfig::verticalScrollBar = "";
std::string UIConfig::horizontalScrollBar = "";
int UIConfig::touchDragSensitivity = 10;
int UIConfig::clickDragSensitivity = 2;
int UIConfig::touchScrollSensitivity = 20;
int UIConfig::defaultComboBoxVisibleItemCount = 10;
std::string UIConfig::globalModalWaiting = "";
std::string UIConfig::tooltipsWin = "";
Color4F UIConfig::modalLayerColor = Color4F::WHITE;
bool UIConfig::bringWindowToFrontOnClick = true;
std::string UIConfig::windowModalWaiting = "";

std::unordered_map<std::string, UIConfig::FontNameItem> UIConfig::_fontNames;

void UIConfig::registerFont(const std::string& aliasName, const std::string& realName)
{
    FontNameItem fi;
    fi.name = realName;
    fi.ttf = FileUtils::getInstance()->isFileExist(realName);
    _fontNames[aliasName] = fi;
}

const std::string& UIConfig::getRealFontName(const std::string& aliasName, bool& isTTF)
{
    auto it = _fontNames.find(aliasName);
    if (it != _fontNames.end())
    {
        isTTF = it->second.ttf;
        return it->second.name;
    }
    else
        return aliasName;
}

NS_FGUI_END

