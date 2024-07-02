#include "DerivedSingleton.h"


DerivedSingleton *DerivedSingleton::getInstance()
{
    return static_cast<DerivedSingleton *>(Singleton::getInstance());
}

// Initialize the static member
DerivedSingleton *DerivedSingleton::derivedInstance = nullptr;

void DerivedSingleton::someMethod()
{
    cout << "Hello Nezer" << endl;
    this->name = "Nezer";
}

string DerivedSingleton::getName() const
{
    return this->name;
}