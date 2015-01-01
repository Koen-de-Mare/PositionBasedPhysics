#include "worldstate.h"

worldstate::worldstate() {
    //ctor
}

worldstate::~worldstate() {
    //delete the data referenced to by softForcePool and constraintPool as these arrays contain pointers
    //...

    delete[] &particlePool;
    delete[] &softForcePool;
    delete[] &constraintPool;

    delete &particlePoolSize;
    delete &softForcePoolSize;
    delete &constraintPoolSize;
}
