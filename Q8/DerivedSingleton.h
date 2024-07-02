#ifndef DERIVEDSINGLETON_H
#define DERIVEDSINGLETON_H

#include <iostream>
#include "Singleton.h"

using namespace std;

class DerivedSingleton : public Singleton {
public:
    static DerivedSingleton* getInstance();

    void someMethod(); // Example method for the derived class

    string getName() const;

protected:
    DerivedSingleton() = default; // Protected constructor

private:
    static DerivedSingleton* derivedInstance;
    string name;
};

#endif // DERIVEDSINGLETON_H
