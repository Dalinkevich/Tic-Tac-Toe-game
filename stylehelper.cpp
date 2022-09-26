#include "stylehelper.h"

QString StyleHelper::getMainWudgetStyle()
{
    return "QWidget{"
            "background-image: url(:resourses/images/bg.png);"
           "}";
}

QString StyleHelper::getStartButtonsStyle()
{
    return "QPushButton{"
           "color:#fff;"
            "background: none;"
            "border: none;"
            "border-radius: 19px;"
            "font-family: 'Comic CAT';"
            "font-size: 18px;"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0.139785 rgba(89, 156, 208, 255), stop:1 rgba(0, 108, 243, 255));"
            "}"
    "QPushButton::hover{"
    "background-color: qlineargradient(spread:pad, x1:0.022, y1:0.966091, x2:0.0212473, y2:0.034, stop:0 rgba(0, 158, 249, 255), stop:1 rgba(65, 170, 211, 255));"
           "}"
    "QPushButton::pressed{"
    "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0.139785 rgba(89, 156, 208, 255), stop:1 rgba(0, 108, 243, 255));"
    "}";
}

QString StyleHelper::getStartButtonGameStyle()
{
    return "QPushButton{"
           "color:#fff;"
            "background: none;"
            "border: none;"
            "border-radius: 19px;"
            "font-family: 'Comic CAT';"
            "font-size: 18px;"
            "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 178, 102, 255), stop:0.473118 rgba(255, 137, 124, 255), stop:0.98 rgba(219, 57, 99, 255), stop:1 rgba(0, 0, 0, 0));"
            "}"
    "QPushButton::hover{"
    "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 218, 182, 255), stop:0.473118 rgba(255, 137, 124, 255), stop:0.98 rgba(219, 57, 99, 255), stop:1 rgba(0, 0, 0, 0));"
           "}"
    "QPushButton::pressed{"
    "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(255, 178, 102, 255), stop:0.473118 rgba(255, 137, 124, 255), stop:0.98 rgba(219, 57, 99, 255), stop:1 rgba(0, 0, 0, 0));"
    "}";
}

QString StyleHelper::getLeftButtonStyle()
{
    return "QPushButton{"

            "background-color: qlineargradient(spread:pad, x1:0.022, y1:0.966091, x2:0.0212473, y2:0.034, stop:0 rgba(43, 61, 80, 255), stop:1 rgba(133, 133, 133, 255));"
            "background-image: url(:/resourses/images/cross_small.png);"
            "background-repeat: no-repeat;"
            "background-position: center center;"
            "border: 1px solid #333;"
            "border-top-left-radius: 5px;"
            "border-bottom-left-radius: 5px;"
            "}";
}

QString StyleHelper::getRightButtonStyle()
{
    return "QPushButton{"
            "background-color: qlineargradient(spread:pad, x1:0.022, y1:0.966091, x2:0.0212473, y2:0.034, stop:0 rgba(43, 61, 80, 255), stop:1 rgba(133, 133, 133, 255));"
            "background-image: url(:/resourses/images/zero_small.png);"
            "background-repeat: no-repeat;"
            "background-position: center center;"
            "border: 1px solid #333;"
            "border-left: none;"
            "border-top-right-radius: 5px;"
            "border-bottom-right-radius: 5px;"
            "}";
}

QString StyleHelper::getLeftButtonActiveStyle()
{
    return "QPushButton{"
            "background-color: #272d39;"
            "background-image: url(:/resourses/images/cross_small.png);"
            "background-repeat: no-repeat;"
            "background-position: center center;"
            "border: 1px solid #333;"
            "border-top-left-radius: 5px;"
            "border-bottom-left-radius: 5px;"
            "}";
}

QString StyleHelper::getRightButtonActiveStyle()
{
    return "QPushButton{"
            "background-color: #272d39;"
            "background-image: url(:/resourses/images/zero_small.png);"
            "background-repeat: no-repeat;"
            "background-position: center center;"
            "border: 1px solid #333;"
            "border-left: none;"
            "border-top-right-radius: 5px;"
            "border-bottom-right-radius: 5px;"
           "}";
}

QString StyleHelper::getTabWidgetStyle()
{
    return "QTabWidget{"
            "border:none;"
            "}"
            "QTabWidget::pane{"
            "border:1px solid #222;"
            "border-radius:3px;"
           "}";
}

QString StyleHelper::getTabStyle()
{
    return "QWidget#tab{"
           "background: rgb(33, 40, 50);"
           "}";
}

QString StyleHelper::getBlankButtonStyle()
{
    return "QPushButton{"
            "border:none;"
            "background: #272D39;"
            "}"
            "QPushButton::hover{"
            "background: #373D49;"
            "}";
}

QString StyleHelper::getCrossNormalStyle()
{
    return "QPushButton{"
            "border:none;"
            "background: #272D39 url(:/resourses/images/cross_large.png) no-repeat center center;"
            "}"
            "QPushButton::hover{"
            "background-color: #373D49;"
            "}";
}

QString StyleHelper::getCrossVictoryStyle()
{
    return "QPushButton{"
            "border:none;"
            "background: #20401B;"
            "background-image: url(:/resourses/images/cross_large.png);"
            "background-repeat: no-repeat;"
            "background-position: center center;"
            "}";
}

QString StyleHelper::getCrossLostStyle()
{
    return "QPushButton{"
            "border:none;"
            "background: #aa444c;"
            "background-image: url(:/resourses/images/cross_large.png);"
            "background-repeat: no-repeat;"
            "background-position: center center;"
           "}";
}

QString StyleHelper::getZeroNormalStyle()
{
    return "QPushButton{"
            "border:none;"
            "background: #272D39 url(:/resourses/images/zero_large.png) no-repeat center center;"
            "}"
            "QPushButton::hover{"
            "background-color: #373D49;"
            "}";
}

QString StyleHelper::getZeroVictoryStyle()
{
    return "QPushButton{"
            "border:none;"
            "background: #20401B;"
            "background-image: url(:/resourses/images/zero_large.png);"
            "background-repeat: no-repeat;"
            "background-position: center center;"
            "}";
}

QString StyleHelper::getZeroLostStyle()
{
    return "QPushButton{"
            "border:none;"
            "background: #aa444c;"
            "background-image: url(:/resourses/images/zero_large.png);"
            "background-repeat: no-repeat;"
            "background-position: center center;"
           "}";
}

QString StyleHelper::getNormalMessageStyle()
{
    return "QLabel{"
            "font-family: 'Comic CAT';"
            "font-size: 18px;"
            "background: none;"
            "color: #ff867b;"
            "}";
}

QString StyleHelper::getVictoryMessageStyle()
{
    return "QLabel{"
            "font-family: 'Comic CAT';"
            "font-size: 18px;"
            "background: #20401B;"
            "border: 1px solid #ffffff;"
            "color: #ffffff;"
            "}";
}

QString StyleHelper::getLostMessageStyle()
{
    return "QLabel{"
            "font-family: 'Comic CAT';"
            "font-size: 18px;"
            "background: #aa444c;"
            "border: 1px solid #ffffff;"
            "color: #ffffff;"
            "}";
}

QString StyleHelper::getAboutTextStyle()
{
    return "QLabel{"
            "font-family: 'Kraft Mono';"
            "font-size: 19px;"
            "color: #ffffff;"
            "font-style:italic;"
            "}";
}





