#include "_button.h"

namespace gui {
    Button::Button(const double _width, 
                    const double _height, 
                    const double _top, 
                    const double _left, 
                    handleFunction&& _handle) :
                    m_width(_width),
                    m_height(_height),
                    m_top(_top),
                    m_left(_left),
                    m_handleFunc(_handle)
                    {
                    }

    Button::~Button(){}

    double Button::getWidth(){
        return m_width;
    }

    double Button::getHeight() {
        return m_height;
    }

    double Button::getTop() {
        return m_top;
    }

    double Button::getLeft() {
        return m_left;
    }

    bool Button::checkPressed(double xPos, double yPos) {
        if (xPos >= m_left && xPos <= m_left + m_width && yPos >= m_top && yPos <= m_top + m_height) {
            this->m_handleFunc;
        }
    }
}