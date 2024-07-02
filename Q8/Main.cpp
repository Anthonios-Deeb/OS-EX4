#include <iostream>
#include "DerivedSingleton.h"
#include "Guard.h"

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void* threadFunction(void* arg) {
    Guard guard(mtx); // Automatically locks mtx upon construction

    // Critical section
    std::cout << "Thread " << pthread_self() << " is in the critical section." << std::endl;
    
    // mtx will be automatically unlocked when guard goes out of scope
    return nullptr;
}

int main() {
    DerivedSingleton* instance = DerivedSingleton::getInstance();
    instance->someMethod();

    cout << instance->getName() << endl;

    DerivedSingleton* instance2 = DerivedSingleton::getInstance();

    cout << instance2->getName() << endl;

    pthread_t thread1, thread2;

    pthread_create(&thread1, nullptr, threadFunction, nullptr);
    pthread_create(&thread2, nullptr, threadFunction, nullptr);

    pthread_join(thread1, nullptr);
    pthread_join(thread2, nullptr);

    return 0;
}
