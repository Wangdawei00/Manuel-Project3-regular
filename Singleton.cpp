//
// Created by Wangdawei on 2018/11/23.
//

#include "Singleton.h"

Singleton::Singleton() = default;

Singleton::~Singleton() = default;

Singleton *Singleton::getInstance() {
    static Singleton *s = nullptr;
    if (s == nullptr) s = new Singleton();
    return s;
}

void Singleton::deleteInstance() {
    Singleton *s = getInstance();
    delete s;
//    s= nullptr;
}

Singleton &Singleton::operator=(Singleton const &) = default;

Singleton::Singleton(Singleton const &) = default;
