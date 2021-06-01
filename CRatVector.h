#pragma once
#include <iostream>
#include <cstdint>
#include <cstring>
#include <fstream>
#include <string>
#include <exception>
#include <vector>

struct CRationalNumber {
	int div;
	int den;
	CRationalNumber(int re = 0, int im = 0);
	void normalize();
	CRationalNumber& operator+=(const CRationalNumber& right);
	CRationalNumber operator+(const CRationalNumber& right) const;
	CRationalNumber& operator-=(const CRationalNumber& right);
	CRationalNumber operator-(const CRationalNumber& right) const;
	CRationalNumber& operator*=(const CRationalNumber& right);
	CRationalNumber operator*(const CRationalNumber& right) const;
	CRationalNumber& operator/=(const CRationalNumber& right);
	CRationalNumber operator/(const CRationalNumber& right) const;
};

class CRatVector {
public:
	CRatVector(int size);
	CRatVector(const CRatVector &other);
	CRatVector(CRatVector &&other) noexcept;
	~CRatVector();
	int size() const;
	CRatVector &operator=(const CRatVector &other);
	CRatVector &operator=(CRatVector &&other) noexcept;
	CRationalNumber &operator[](int i);
	const CRationalNumber &operator[](int i) const;
	CRatVector &operator+=(const CRatVector &right);
	CRatVector &operator-=(const CRatVector &right);
	friend CRationalNumber operator*(const CRatVector& left, const CRatVector& right);

	virtual int output(const char* FileName = nullptr) = 0;
	virtual void setFilename(const char* FileName) = 0;
	virtual const char* getFilename() const = 0;

protected:
	std::vector<CRationalNumber> data;
	std::string FileName = "";
	int vecsize = 0;
};
