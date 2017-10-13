#include "GearBase.h"
#include "GearDisplay.h"
#include "GComponent.h"
#include "Controller.h"
#include "utils/ToolSet.h"

NS_FGUI_BEGIN
USING_NS_CC;

bool GearBase::disableAllTweenEffect = false;

GearBase::GearBase(GObject * owner)
{
    _owner = owner;
}

GearBase::~GearBase()
{
}

void GearBase::setController(Controller * value)
{
    if (value != _controller)
    {
        _controller = value;
        if (_controller != nullptr)
            init();
    }
}

void GearBase::init()
{
}

void GearBase::addStatus(const std::string&  pageId, const std::string& value)
{
}

void GearBase::apply()
{
}

void GearBase::updateState()
{
}

void GearBase::updateFromRelations(float dx, float dy)
{
}

void GearBase::setup(tinyxml2::XMLElement * xml)
{
    const char* p = xml->Attribute("controller");
    if (p)
    {
        _controller = _owner->getParent()->getController(std::string(p));
        if (_controller == nullptr)
            return;
    }

    init();

    tween = xml->BoolAttribute("tween");
    /*
    str = xml.GetAttribute("ease");
    if (str != null)
        easeType = FieldTypes.ParseEaseType(str);*/

    tweenTime = xml->FloatAttribute("duration");
    delay = xml->FloatAttribute("delay");

    std::vector<std::string> pages;
    p = xml->Attribute("pages");
    if (p)
        ToolSet::splitString(p, ',', pages);

    if (dynamic_cast<GearDisplay*>(this))
    {
        ((GearDisplay*)this)->pages = pages;
    }
    else
    {
        if (pages.size() > 0)
        {
            std::vector<std::string> values;
            p = xml->Attribute("values");
            if (p)
                ToolSet::splitString(p, '|', values);

            int cnt1 = pages.size();
            int cnt2 = values.size();
            std::string str;
            for (int i = 0; i < cnt1; i++)
            {
                if (i < cnt2)
                    str = values[i];
                else
                    str = STD_STRING_EMPTY;
                addStatus(pages[i], str);
            }
        }

        p = xml->Attribute("default");
        if (p)
            addStatus(STD_STRING_EMPTY, p);
    }
}

NS_FGUI_END