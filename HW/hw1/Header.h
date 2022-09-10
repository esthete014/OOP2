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

template <typename N1, typename N2>
class Coordinates {
private:

	N1 first;
	N2 second;
	
public:

	///
	/// Constructions
	/// 
	//po umolchaniyu
	Coordinates(); 
	//inicialisation
	Coordinates(N1 first, N2 second);
	//copy
	Coordinates(const Coordinates<N1, N2>& ref_Point);

	/// <summary>
	/// OPERATORS
	/// </summary>
	//friend std::ostream& operator<<(std::ostream& output, Coordinates<N>& data);
	friend std::ostream& operator<<(std::ostream& output, Coordinates<N1, N2>& other) {
		output << "(" << other.first << "; " << other.second << ")\n";
		return output;
	}
	Coordinates<N1, N2> operator+(Coordinates<N1, N2>& other) {
		return Coordinates(other.first + this->first, other.second + N2(this->second));
	}
	Coordinates<N1, N2> operator=(const Coordinates<N1, N2>& other) {
		this->first = other.first;
		this->second = other.second;
		return Coordinates<int, int>(this->first, this->second);
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
		Coordinates<N1, N2> temp = Coordinates<N1, N2>();
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
		N2 temp;
		temp = N2(this->first);
		this->first = N1(this->second);
		this->second = temp;
		return Coordinates(this->first, this->second);
	}
};

//template <typename N>
//std::ostream& operator<<(std::ostream& output, Coordinates<N>& other) {
//	output << "(" << other.first << "; " << other.second << ")\n";
//	return output;
//}

template <typename N1, typename N2>
Coordinates<N1, N2>::Coordinates() {
	first = 0;
	second = 0;
}
template <typename N1, typename N2>
Coordinates<N1, N2>::Coordinates(N1 _first, N2 _second) {
	first = _first;
	second = _second;
}
template <typename N1, typename N2>
Coordinates<N1, N2>::Coordinates(const Coordinates<N1, N2>& ref_Point) {
	first = ref_Point.first;
	second = ref_Point.second;
}