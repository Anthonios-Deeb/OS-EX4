#include "Singleton.h"

Singleton *Singleton::instance = nullptr;
pthread_mutex_t Singleton::mutex = PTHREAD_MUTEX_INITIALIZER;

Singleton *Singleton::getInstance()
{
    if (instance == nullptr)
    {
        pthread_mutex_lock(&mutex);
        instance = new Singleton();
        pthread_mutex_unlock(&mutex);
    }
    return instance;
}
