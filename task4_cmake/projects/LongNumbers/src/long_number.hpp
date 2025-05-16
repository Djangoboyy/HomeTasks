#pragma once

#include <iostream>

namespace biv {
	class LongNumber {
		private:
			int* numbers;
			int length;
			int sign;
		
		public:
			LongNumber();
			LongNumber(const char* const str);
			LongNumber(const LongNumber& x);
			LongNumber(LongNumber&& x);
			
			~LongNumber();
			
			LongNumber& operator = (const char* const str);
			LongNumber& operator = (const LongNumber& x);
			LongNumber& operator = (LongNumber&& x);
			
			bool operator == (const LongNumber& x) const;
			bool operator != (const LongNumber& x) const;
			bool operator > (const LongNumber& x) const;
			bool operator < (const LongNumber& x) const;

			LongNumber add_abs(const LongNumber& x, const LongNumber& y, const int sign) const;
			LongNumber sub_abs(const LongNumber& x, const LongNumber& y) const;
			LongNumber multiply_abs(const LongNumber& x, const LongNumber& y) const;
			
			LongNumber operator + (const LongNumber& x) const;
			LongNumber operator - (const LongNumber& x) const;
			LongNumber operator * (const LongNumber& x) const;
			LongNumber operator / (const LongNumber& x) const;
			LongNumber operator % (const LongNumber& x) const;
			
			int get_digits_number() const noexcept;
			int get_rank_number(const int rank) const;
			bool is_negative() const noexcept;
			bool compare_abs(const LongNumber& x) const;
			bool abs_equal(const LongNumber& x) const;
			LongNumber abs(const LongNumber& x) const;
			
			friend std::ostream& operator << (std::ostream &os, const LongNumber& x);
			
		private:
			int get_length(const char* const str) const noexcept;
	};
}
