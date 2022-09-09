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


class Coordinates {
private:

	int first;
	int second;
	
public:

	///
	/// Constructions
	/// 
	//po umolchaniyu
	Coordinates(); 
	//inicialisation
	Coordinates(int first, int second);
	//copy
	Coordinates(const Coordinates& ref_Point);

	/// <summary>
	/// OPERATORS
	/// </summary>
	friend std::ostream& operator<<(std::ostream& output, Coordinates& data);
	Coordinates operator+(Coordinates& other) {
		return Coordinates(other.first + this->first, other.second + this->second);
	}
	Coordinates operator=(const Coordinates& other) {
		this->first = other.first;
		this->second = other.second;
		return Coordinates(this->first, this->second);
	}
	

	/// <summary>
	/// function to output
	/// </summary>
	void Display() {
		std::cout
			<< "(" << first << "; " << second << ")"
			<< std::endl;
	}

	/// <summary>
	/// Method to swap two of your coordinates
	/// </summary>
	/// <param name="other coordinates that you want to swap with"></param>
	/// <returns>your coordinate which you gave last</returns>
	Coordinates Swap(Coordinates& next) {
		Coordinates temp = Coordinates();
		temp.first = this->first;
		temp.second = this->second;

		this->first = next.first;
		this->second = next.second;
		return next;
	}

	/// <summary>
	/// Method to swap first and second in coordinate
	/// </summary>
	/// <param name="NONE"></param>
	/// <returns>your coordinates which you swap inside</returns>
	Coordinates Swap() {
		int temp;
		temp = this->first;
		this->first = this->second;
		this->second = temp;
		return Coordinates(this->first, this->second);
	}
};


std::ostream& operator<<(std::ostream& output, Coordinates& other) {
	output << "(" << other.first << "; " << other.second << ")\n";
	return output;
}
Coordinates::Coordinates() {
	first = 0;
	second = 0;
}

Coordinates::Coordinates(int _first, int _second) {
	first = _first;
	second = _second;
}

Coordinates::Coordinates(const Coordinates& ref_Point) {
	first = ref_Point.first;
	second = ref_Point.second;
}