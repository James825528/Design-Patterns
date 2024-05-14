
#include <iostream>
using namespace std;
// Key components of Strategy Design Pattern
// 1. Context
// 2. Strategy Interface
// 3. Concrete Strategies

class SortStrategy{
    // Strategy Interface
    public:
    virtual void sort()=0; // abstract class
};
class ConcreteStrategy1: public SortStrategy{
    // Concrete Strategy 
    public:
    void sort()
    {
        cout<<"This is Concrete Strategy 1\n";
    }
    
};
class ConcreteStrategy2: public SortStrategy{
    // Concrete Strategy 
    public:
    void sort()
    {
        cout<<"This is Concrete Strategy 2\n";
    }
    
};
class ConcreteStrategy3: public SortStrategy{
    // Concrete Strategy 
    public:
    void sort()
    {
        cout<<"This is Concrete Strategy 3\n";
    }
    
};
class ContextAlgo{
    
    SortStrategy* sortMethod;
    public:
    void setSortStrategy(SortStrategy* mStrategy)
    {
        this->sortMethod=mStrategy;
    }
    void executeStrategy()
    {
        sortMethod->sort();
    }
};



int main()
{
    ContextAlgo algo1;
    ConcreteStrategy1 s1;
    algo1.setSortStrategy(&s1);
    algo1.executeStrategy();
    
    ContextAlgo algo2;
    ConcreteStrategy2 s2;
    algo2.setSortStrategy(&s2);
    algo2.executeStrategy();
    
    ContextAlgo algo3;
    ConcreteStrategy3 s3;
    algo3.setSortStrategy(&s3);
    algo3.executeStrategy();
    
    return 0;
}
