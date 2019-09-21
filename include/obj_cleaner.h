#pragma once
#include "object.h"
#include "state.h"
#include <stack>

class ObjectCleaner{
public:
    static void DeleteThis(Object* obj)noexcept;

    ~ObjectCleaner();
};