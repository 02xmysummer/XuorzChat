#pragma once
#include <QWidget>
#include <functional>
#include "QStyle"
/*
 * @brief repolish : 用来刷新qss
*/
extern std::function<void(QWidget *)> repolish;
