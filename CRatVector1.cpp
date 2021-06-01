#include "CRatVector1.h"

CRatVector1 operator+(const CRatVector1& left, const CRatVector& right) {
	CRatVector1 a(std::max(left.vecsize, CRatVector1(right).vecsize));
	std::copy(left.data.begin(), left.data.end(), a.data.begin());
	a += right;
	return a;
}

CRatVector1 operator-(const CRatVector1& left, const CRatVector& right) {
	CRatVector1 a(std::max(left.vecsize, CRatVector1(right).vecsize));
	std::copy(left.data.begin(), left.data.end(), a.data.begin());
	a -= right;
	return a;
}

void CRatVector1::setFilename(const char* FileName) {
	this->FileName = FileName;
}

const char* CRatVector1::getFilename() const {
	return this->FileName.c_str();
}

int CRatVector1::output(const char* FileName) {
	if (FileName == nullptr) {
		std::cout << "Error occured while working with file!" << std::endl;
		return 1;
	}
	std::ofstream out(FileName, std::ios::app);
	for (int i = 0; i < vecsize; i++) {
		if (data[i].div < 0) {
			out << "-" << -data[i].div;
		}
		else {
			out << data[i].div;
		}
		out << "/" << data[i].den << " ";
	}
	out << std::endl << std::endl;
	out.close();
	return 0;
}
