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
#ifndef SETSUMMABLE_H_
#define SETSUMMABLE_H_
#include <string>
#include "Set.h"

namespace sdds {
	template <size_t N, typename T>
	class SetSummable : public Set<N, T>{
	public:
		T accumulate(const std::string& filter) const {
			T accumulator(filter);
			for (size_t i = 0; i < this->size(); i++) {
				if (accumulator.isCompatibleWith(this->get(i))) {
					accumulator += this->get(i);
				}
			}
			return accumulator;
		}
	};
}
#endif