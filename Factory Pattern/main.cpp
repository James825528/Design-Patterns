#include<iostream>

#include "ButtonFactory.h"

using namespace std;

int main()
{
    {
        ButtonFactory myButtonFactory;
    
        auto b1=myButtonFactory.createButton(0);
        b1->show();

        auto b2=myButtonFactory.createButton(1);
        b2->show();
    }

    cin.get();
}
