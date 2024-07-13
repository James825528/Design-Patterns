#include "WindowsButton.h"
#include<iostream> 
using namespace std;

WindowsButton::WindowsButton()
{
    cout<<"Windows Button Constructor Called\n";
}
void WindowsButton::show()
{
    cout<<"This is a windows Button\n";
}
WindowsButton::~WindowsButton()
{
    cout<<"Windows Button Destructor Called\n";
}

