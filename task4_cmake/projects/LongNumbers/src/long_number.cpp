#include <cstring>
#include "long_number.hpp"

using biv::LongNumber;
		
LongNumber::LongNumber() : length(1), sign(1) {
	numbers = new int[length];
	numbers[0] = 0;
}

LongNumber::LongNumber(const char* const str) {
	int str_length = std::strlen(str);
	if (str[0] == '-') {
		sign = -1;
		length = str_length - 1;
	} else {
		sign = 1;
		length = str_length;
	}

	numbers = new int[length];
	for(int i = 0; i < length; i++) {
		numbers[i] = str[str_length-i-1] - '0';
	}

}

LongNumber& LongNumber::operator = (const char* const str) {
	int str_length = std::strlen(str);
	if (str[0] == '-') {
		sign = -1;
		length = str_length - 1;
	} else {
		sign = 1;
		length = str_length;
	}

	delete [] numbers;
	numbers = new int[length];
	for(int i = 0; i < length; i++) {
		numbers[i] = str[str_length-i-1] - '0';
	}

	return *this;
}

LongNumber::LongNumber(const LongNumber& x) {
	length = x.length;
	sign = x.sign;
	numbers = new int[length];
	for(int i = 0; i < length; i++){
		numbers[i] = x.numbers[i];
	}
}

LongNumber::LongNumber(LongNumber&& x) {
	length = x.length;
	sign = x.sign;
	numbers = x.numbers;
	x.numbers = nullptr;
}


LongNumber& LongNumber::operator = (const LongNumber& x) {
	if (this == &x ) return *this;

	length = x.length;
	sign = x.sign;

	delete [] numbers;
	numbers = new int[length];
	for(int i = 0; i < length; i++){
		numbers[i] = x.numbers[i];
	}

	return *this;
}

LongNumber& LongNumber::operator = (LongNumber&& x) {
	length = x.length;
	sign = x.sign;

	delete [] numbers;
	numbers = x.numbers;
	x.numbers = nullptr;

	return *this;
}

LongNumber::~LongNumber() {
	length = 0;
	delete [] numbers;
	numbers = nullptr;
}


// bool LongNumber::operator == (const LongNumber& x) const {
// 	// TODO
// }
//
// bool LongNumber::operator != (const LongNumber& x) const {
// 	// TODO
// }
//
// bool LongNumber::operator > (const LongNumber& x) const {
// 	// TODO
// }
//
// bool LongNumber::operator < (const LongNumber& x) const {
// 	// TODO
// }
//
// LongNumber LongNumber::operator + (const LongNumber& x) const {
// 	// TODO
// }
//
// LongNumber LongNumber::operator - (const LongNumber& x) const {
// 	// TODO
// }
//
// LongNumber LongNumber::operator * (const LongNumber& x) const {
// 	// TODO
// }
//
// LongNumber LongNumber::operator / (const LongNumber& x) const {
// 	// TODO
// }
//
// LongNumber LongNumber::operator % (const LongNumber& x) const {
// 	// TODO
// }
//
// int LongNumber::get_digits_number() const noexcept {
// 	// TODO
// }
//
// int LongNumber::get_rank_number(int rank) const {
// 	// TODO
// }
//
// bool LongNumber::is_negative() const noexcept {
// 	// TODO
// }
//
// // ----------------------------------------------------------
// // PRIVATE
// // ----------------------------------------------------------
// int LongNumber::get_length(const char* const str) const noexcept {
// 	// TODO
// }
//
// // ----------------------------------------------------------
// // FRIENDLY
// // ----------------------------------------------------------
// namespace biv {
// 	std::ostream& operator << (std::ostream &os, const LongNumber& x) {
// 		// TODO
// 	}
// }
