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
#ifndef PAIR_H_
#define PAIR_H_
#include <iostream>

namespace sdds {
	template <typename V, typename K>
	class Pair {
		V v;
		K k;
	public:
		Pair() {};
		Pair(const K& key, const V& value) {
			k = key;
			v = value;
		};
		const V& value() const {
			return v;
		};
		const K& key() const {
			return k;
		};
		virtual void display(std::ostream& os) const {
			os << k << " : " << v << std::endl;
		};
	};
	template <typename V, typename K>
	std::ostream& operator << (std::ostream& os, const Pair<V, K>& pair) {
		pair.display(os);
		return os;
	};
}

#endif