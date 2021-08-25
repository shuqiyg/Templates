/* Workshop 3 - Templates
   Name: Shuqi Yang
   Std ID: 132162207
   Email: syang136@myseneca.ca
   Date: 06-08-2021
   -------------------------------------------------------
   I have done all the coding by myself and only copied the
   code that my professor provided to complete my workshops
   and assignments.
 */
#ifndef PAIRSUMMABLE_H_
#define PAIRSUMMABLE_H_
#include <iomanip>
#include <string>
#include "Pair.h"

namespace sdds {
	template <typename V, typename K>
	class PairSummable : public Pair<V, K> {
		static V initial;
		static size_t f_width;
	public:
		PairSummable() {};
		PairSummable(const K& key, const V& value = initial) : Pair<V, K>(key, value) {
			if (key.size() > f_width) f_width = key.size();
		};
		bool isCompatibleWith(const PairSummable<V, K>& b)const {
			return this->key() == b.key();
		};
		PairSummable& operator+=(const PairSummable& b) {
			/*this->v += b.v;*/
			PairSummable temp(this->key(), this->value() + b.value());
			*this = temp;
			return *this;
		};
		void display(std::ostream& os) const {
			os << std::left << std::setw(f_width);
			Pair<V, K>::display(os);
			os << std::right;
		};	
	};

	template <typename V, typename K>
	size_t PairSummable<V, K>::f_width;

	template <typename V, typename K>
	V PairSummable<V, K>::initial {};

	template <>
	PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable& b) {
		std::string str{};
		if (this->value() != "\0") {
			
			str += ", ";
			//this->v += ", ";
		}
		str += b.value();
		PairSummable temp(this->key(), this->value() + str);
		*this = temp;
		//this->v += b.v;
		return *this;
	}
}
#endif