#pragma once
#include "CRatVector.h"

class CRatVector1 : public CRatVector {
public:
	using CRatVector::CRatVector;
	using CRatVector::operator=;
	friend CRatVector1 operator+(const CRatVector1& right, const CRatVector& left);
	friend CRatVector1 operator-(const CRatVector1& right, const CRatVector& left);
	CRatVector1() = default;
	CRatVector1(const CRatVector& r) : CRatVector(r) {}
	CRatVector1(CRatVector&& r) noexcept : CRatVector(std::move(r)) {}
	void setFilename(const char* FileName) override;
	const char* getFilename() const override;
	int output(const char* FileName = nullptr) override;
};
