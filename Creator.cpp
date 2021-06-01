#include "Creator.h"

CRatVector* CreatorVector0::create(size_t size) {
    return new CRatVector0(size);
}

CRatVector* CreatorVector1::create(size_t size) {
    return new CRatVector1(size);
}
