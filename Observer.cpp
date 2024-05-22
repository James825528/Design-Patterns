#include<iostream>
#include<vector>
using namespace std;
// Key Concepts in Observer Pattern
/*
1. Subject : This is the object that is being Observed. It Maintains a list of everyone who wants to observe it and notifies them if their
is any change in its state.

2. Observer: This is the entity which wants to be notified / informed if there is any change to the subject.

3. Concrete Subject: It inherits from the Subject Class. For Example , there could be different products that should have the notify me 
functionality. So whenever that product has any change in its state it would notify the Observers.

4. Concrete Observer: It implements the Observer interface. Like there could be different Observers.

*/

class Observer{
	// Observer Base Class / Interface
	public:
		virtual void update(int arg1,int arg2 ,int arg3)=0;
};


class Subject{
	
	public:
		vector<Observer*> obsList;
		int arg1,arg2,arg3;
		
		void add(Observer* obs)
		{
			// Register the observer
			obsList.push_back(obs);
		}
		
//		void remove(Observer* obs)
//		{
////			Remove Observer
////			obsList.erase(obs);
//		}
		void notify()
		{
			for(int i=0;i<obsList.size();i++)
			{
				Observer* x=obsList[i];
				x->update(arg1,arg2,arg3);
			}
		}
		void updateState(int arg1,int arg2,int arg3)
		{
			this->arg1=arg1;
			this->arg2=arg2;
			this->arg3=arg3;
			notify();
		}
		
		
};


class ConcreteObserver1 : public Observer{
	void update(int arg1,int arg2 ,int arg3)
	{
		cout<<"In Observer 1:"<<arg1<<" "<<arg2<<" "<<arg3<<endl;
	}	
};
class ConcreteObserver2 : public Observer{
	void update(int arg1,int arg2 ,int arg3)
	{
		cout<<"In Observer 2:"<<arg1<<" "<<arg2<<" "<<arg3<<endl;
	}	
};

int main()
{
	ConcreteObserver1 cb1,cb2;
	ConcreteObserver2 cb3;
	
	Subject product;
	product.add(&cb1); product.add(&cb2);
	product.add(&cb3);
	
	product.updateState(1,2,3);
	
	product.updateState(4,5,6);
	return 0;
}

