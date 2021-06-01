#pragma once
#include <memory>
#include "CRatVector.h"
#include "CRatVector0.h"
#include "CRatVector1.h"

class Creator {
public:
    virtual CRatVector* create(size_t size) = 0;
};

class CreatorVector0 : public Creator {
public:
    CRatVector* create(size_t size) override;
};

class CreatorVector1 : public Creator {
public:
    CRatVector* create(size_t size) override;
};