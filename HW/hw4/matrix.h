// / ============================= \
// | -------  esthete014  -------- |
// | ============================= |
// |     || copyright 2022 ||      |
// |     || Nikolay        ||      |
// |     || Kochetov       ||      |
// | _____________________________ |
// | https://github.com/esthete014 |
// \ ============================= /

#pragma once
#include <iostream>
#include <vector>
#include "engine.h"

struct ENGINE;

class MATRIX {
	friend ENGINE;
	std::vector<std::vector<long long>> matrix;

	MATRIX();
	MATRIX(const MATRIX& other);
	int maxsize();
	
	MATRIX operator+=(MATRIX& other);
	MATRIX operator-=(MATRIX& other);
	MATRIX operator*=(MATRIX& other);
	MATRIX operator*=(std::vector<long long>& other);
	void transpose();

};
MATRIX::MATRIX() {
	for (int i = 0; i < this->matrix.size(); i++) {
		for (int j = 0; j < this->matrix[i].size(); j++) {
			this->matrix[i][j] = getRandom();
		}
	}
}
MATRIX::MATRIX(const MATRIX& other) {
	for (int i = 0; i < this->matrix.size(); i++) {
		for (int j = 0; j < this->matrix[i].size(); j++) {
			this->matrix[i][j] = other.matrix[i][j];
		}
	}
}
int MATRIX::maxsize() { return this->matrix[0].size(); }
MATRIX MATRIX::operator+=(MATRIX& other) {
	for (int i = 0; i < this->matrix.size(); i++) {
		for (int j = 0; j < this->matrix[i].size(); j++) {
			this->matrix[i][j] += other.matrix[i][j];
		}
	}
	return *this;
}
MATRIX MATRIX::operator-=(MATRIX& other) {
	for (int i = 0; i < this->matrix.size(); i++) {
		for (int j = 0; j < this->matrix[i].size(); j++) {
			this->matrix[i][j] -= other.matrix[i][j];
		}
	}
	return *this;
}
MATRIX MATRIX::operator*=(MATRIX& other) {
	for (int i = 0; i < this->matrix.size(); i++) {
		for (int j = 0; j < this->matrix[i].size(); j++) {
			this->matrix[i][j] *= other.matrix[i][j];
		}
	}
	return *this;
}
MATRIX MATRIX::operator*=(std::vector<long long>& other) {
	for (int i = 0; i < this->matrix.size(); i++) {
		for (int j = 0; j < this->matrix[i].size(); j++) {
			this->matrix[i][j] *= other[j];
		}
	}
	return *this;
}
void MATRIX::transpose() {
	MATRIX temp;
	temp.matrix = this->matrix;
	for (int i = 0; i < this->matrix.size(); i++) {
		for (int j = i; j < this->matrix[i].size(); j++) {
			this->matrix[i][j] = temp.matrix[j][i];
		}
	}
}
