#include "MacButton.h"
#include<iostream> 
using namespace std;
MacButton:: MacButton()
{
    cout<<"Mac Button Constructor Called\n";
}
void MacButton::show()
{
    cout<<"This is a Mac Button\n";
}
MacButton::~MacButton()
{
    cout<<"Mac Button Desctructor Called\n";
}
