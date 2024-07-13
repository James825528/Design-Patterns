#pragma once
#include<iostream>
using namespace std;
class Button{
    public:
    Button()
    {
        cout<<"Button Constructor Called\n";
    }
    virtual void show()=0;
    ~Button()
    {
        cout<<"Button Destructor Called\n";
    }
};