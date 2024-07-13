#pragma once
#include <memory>
#include "Button.h"
#include "WindowsButton.h"
#include "MacButton.h"
#include <iostream>
using namespace std;
class ButtonFactory{
    public:
    ButtonFactory();
    unique_ptr<Button> createButton(int type);
    ~ButtonFactory();
};

