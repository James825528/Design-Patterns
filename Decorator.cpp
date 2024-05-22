#include<iostream>
#include<string>
using namespace std;
/*
Key Concepts of Decorator Pattern
1.Base Component Interface : Base Component on which Dcorators would be used.
2.Concrete Component : They are the basic object which implement the concrete components
3.Decorator : This is an abstract class , they are responsible for adding new functionality to the base component.
It implements the component Interface and also has a reference to   Base component.
4. Concrete Decorator : They add specific functionality to Component.



*/

// Base Component
class BasePizza{
	public:
		virtual int cost()=0;
		virtual string getDescription()=0;
};

// Concrete Component 1

class MargheritaPizza: public BasePizza{
	public:
	int cost(){
		return 100;		
	}
	string getDescription(){
		return " MargheritaPizza ";
	}
};

// Concrete Component 2

class VegPizza: public BasePizza{
	int cost(){
		return 150;		
	}
	string getDescription(){
		return " VegPizza ";
	}
};
// Abstract Decorator Class
class ToppingDecorator : public BasePizza{
	// I want this class to be a Pizza as well so that I can put more 
	// topping on it.
	protected:
		BasePizza * BP;
	public:
		// This method of initialisation is called Member List Initialisation
		ToppingDecorator(BasePizza *bp) :BP(bp)
		{
			
		}
		string getDescription(){
			return BP->getDescription();
		}
		int cost(){
			return BP->cost();
		}
};

// Concrete Decorator Class
class MushroomDecorator:public  ToppingDecorator{
	// Because I am inheriting ToppingDecorator , I also have access to 
	//	BasePizza
	public:
		MushroomDecorator(BasePizza * bp) : ToppingDecorator(bp){
			
		}
		
		int cost(){
			return BP->cost()+50;
		}
		string getDescription(){
			return BP->getDescription()+" with Mushroom ";
		}
	
	
};

class ExtraCheeseDecorator: public ToppingDecorator{
	// Because I am inheriting ToppingDecorator , I also have access to 
	//	BasePizza
	public:
		ExtraCheeseDecorator(BasePizza * bp) : ToppingDecorator(bp){
			
		}
		
		int cost(){
			return BP->cost()+75;
		}
		string getDescription(){
			return BP->getDescription()+" with Extra Cheese ";
		}
	
	
};



int main()
{
	
	BasePizza *bp_vegPizza,*bp_mar;
	// Base Pizza's
	bp_vegPizza=new VegPizza();
	bp_mar=new MargheritaPizza();
	
	cout<<"Base Veg Pizza:";
	cout<<bp_vegPizza->getDescription()<<endl;
	cout<<bp_vegPizza->cost()<<endl;
	
	cout<<"Base Mar Pizza:";
	cout<<bp_mar->getDescription()<<endl;
	cout<<bp_mar->cost()<<endl;
	
	
	// Add Toppings / Decorators
	BasePizza *mushroom_vegPizza=new MushroomDecorator(bp_vegPizza);
	cout<<"Mushroom Veg Pizza:";
	cout<<mushroom_vegPizza->getDescription()<<endl;
	cout<<mushroom_vegPizza->cost()<<endl;
	
	BasePizza *extra_cheese_mar=new ExtraCheeseDecorator(bp_mar);
	cout<<"Extra Chesse Mar Pizza:";
	cout<<extra_cheese_mar->getDescription()<<endl;
	cout<<extra_cheese_mar->cost()<<endl;
	
	//	Topping on Top of Toppings
	
	BasePizza * pizza3=new ExtraCheeseDecorator(mushroom_vegPizza);
	cout<<"Extra Cheese Mushroom Veg Pizza:";
	cout<<pizza3->getDescription()<<endl;
	cout<<pizza3->cost()<<endl;
	
	
	return 0;
}
