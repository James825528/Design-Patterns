#include <memory>
#include "Button.h"
#include "WindowsButton.h"
#include "MacButton.h"
#include <iostream>
#include "ButtonFactory.h"
using namespace std;
ButtonFactory::ButtonFactory()
{
    cout<<"Button Factory Constructor Called\n";
}
unique_ptr<Button> ButtonFactory:: createButton(int type)
{
    
    cout<<"---1\n";
    if(type==0)
    {
        return unique_ptr<Button> (new WindowsButton);
    }
    else if(type==1)
    {
        
        return unique_ptr<Button> (new MacButton);


    }
    return NULL;
}
ButtonFactory::~ButtonFactory()
{
    cout<<"Button Factory Destructor Called\n";
}
