#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "_common_dic.h"

namespace gui {
    class Button {
        public:
            typedef void OnClickedHandle();
            typedef std::function<OnClickedHandle> handleFunction;

        public:
            Button(const double _width, const double _height, const double top, const double left, handleFunction&& _handle);
            ~Button();

            bool checkPressed(double xPos, double yPos);

            double getWidth();
            double getHeight();
            double getTop();
            double getLeft();

        private:
            double m_width;
            double m_height;
            double m_top;
            double m_left;
            handleFunction m_handleFunc;
    };
}

#endif