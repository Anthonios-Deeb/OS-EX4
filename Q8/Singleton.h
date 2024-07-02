#ifndef SINGLETON_H
#define SINGLETON_H

#include <pthread.h>

class Singleton
{
public:
    Singleton(const Singleton &) = delete; // Delete copy constructor and assignment operator to ensure singleton properties
    Singleton &operator=(const Singleton &) = delete;

    static Singleton *getInstance(); // Provide a method to get the singleton instance

protected:
    Singleton() = default; // Protected constructor

private:
    static Singleton *instance;
    static pthread_mutex_t mutex;
};

#endif // SINGLETON_H
