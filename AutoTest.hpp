#pragma once
#include <chrono>

int AutoTest() {
	CRatVector0 a(2);
	a[0] = CRationalNumber(1, 1);
	a[1] = CRationalNumber(1, 1);
	CRatVector0 b(3);
	b[0] = CRationalNumber(1, 1);
	b[1] = CRationalNumber(1, 1);
	b[2] = CRationalNumber(1, 1);
	CRatVector0 c = a + b;
	if (c.size() != 3) {
		return 0;
	}
	if (c[0].div != 2 || c[0].den != 1) {
		return 0;
	}
	if (c[1].div != 2 || c[1].den != 1) {
		return 0;
	}
	if (c[2].div != 1 || c[2].den != 1) {
		return 0;
	}
	c = a - b;
	if (c.size() != 3) {
		return 0;
	}
	if (c[0].div != 0 || c[0].den != 1) {
		return 0;
	}
	if (c[1].div != 0 || c[1].den != 1) {
		return 0;
	}
	if (c[2].div != -1 || c[2].den != 1) {
		return 0;
	}
	a[0] = CRationalNumber(1, 2);
	a[1] = CRationalNumber(1, 1);
	b[0] = CRationalNumber(2, 1);
	b[1] = CRationalNumber(1, 1);
	b[2] = CRationalNumber(1, 1);
	CRationalNumber kost = (a * b);
	kost.normalize();
	if (kost.div != 2 || kost.den != 1) {
		return 0;
	}
	for (int i = 0; i < 1; i++) {
		CRatVector0 vect1(100000000);
		CRatVector0 vect2(100000000);
		std::cout << "Started" << std::endl;
		std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
		vect1 += vect2;
		std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
		int elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
		std::cout << "Addition operator runtime is " << elapsed_ms << " ms\n";
		std::cout << "Started 2: Return of End" << std::endl;
		start = std::chrono::system_clock::now();
		CRationalNumber num = vect1 * vect2;
		end = std::chrono::system_clock::now();
		elapsed_ms = static_cast<int>(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
		std::cout << "Scalar mult operator runtime is " << elapsed_ms << " ms\n";
	}
	return 1;
}