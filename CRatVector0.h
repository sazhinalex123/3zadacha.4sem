#pragma once
#include "CRatVector.h"

class CRatVector0 : public CRatVector {
public:
	using CRatVector::CRatVector;
	using CRatVector::operator=;
	friend CRatVector0 operator+(const CRatVector0& right, const CRatVector& left);
	friend CRatVector0 operator-(const CRatVector0& right, const CRatVector& left);
	CRatVector0() = default;
	CRatVector0(const CRatVector& r) : CRatVector(r) {}
	CRatVector0(CRatVector&& r) noexcept : CRatVector(std::move(r)) {}
	void setFilename(const char* FileName) override;
	const char* getFilename() const override;
	int output(const char* FileName = nullptr) override;
};
