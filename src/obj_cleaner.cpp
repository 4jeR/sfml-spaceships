#include "obj_cleaner.h"


void ObjectCleaner::DeleteThis(Object* obj)noexcept{
    delete obj;
}

ObjectCleaner::~ObjectCleaner(){

}


