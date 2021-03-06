#ifndef __TOOLSET_H__
#define __TOOLSET_H__

#include "cocos2d.h"
#include "tinyxml2/tinyxml2.h"
#include "FairyGUI.h"

NS_FGUI_BEGIN

class ToolSet
{
public:
    static void splitString(const std::string &s, char delim, std::vector<std::string> &elems);
    static void splitString(const std::string &s, char delim, cocos2d::Vec2& value, bool intType = false);
    static void splitString(const std::string &s, char delim, cocos2d::Vec4& value, bool intType = false);
    static void splitString(const std::string &s, char delim, std::string& str1, std::string str2);
    static ssize_t findInStringArray(const std::vector<std::string>& arr, const std::string& str);

    static cocos2d::Color4B convertFromHtmlColor(const char* str);

    static PackageItemType parsePackageItemType(const char * p);
    static cocos2d::TextHAlignment parseAlign(const char *p);
    static cocos2d::TextVAlignment parseVerticalAlign(const char *p);
    static int parseGearIndex(const char* p);
    static LoaderFillType parseFillType(const char *p);
    static ButtonMode parseButtonMode(const char*p);
    static OverflowType parseOverflowType(const char*p);
    static ScrollType parseScrollType(const char*p);
    static ScrollBarDisplayType parseScrollBarDisplayType(const char*p);
    static ProgressTitleType parseProgressTitleType(const char*p);
    static ListLayoutType parseListLayoutType(const char*p);
    static ListSelectionMode parseListSelectionMode(const char*p);
    static ChildrenRenderOrder parseChildrenRenderOrder(const char*p);
    static GroupLayoutType parseGroupLayoutType(const char*p);
    static PopupDirection parsePopupDirection(const char*p);
    static TextAutoSize parseTextAutoSize(const char*p);
    static FlipType parseFlipType(const char*p);
    static cocos2d::tweenfunc::TweenType parseEaseType(const char*p);
};


NS_FGUI_END

#endif
