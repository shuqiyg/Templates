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
#ifndef SET_H_
#define SET_H_

namespace sdds {
	template <size_t N, typename T>
	class Set {
		T collection[N]{};
		size_t noEle = 0;
	public:
		size_t size() const {
			return noEle;
		};
		const T& get(size_t idx) const {
			return collection[idx];
		};
		void operator+=(const T& item) {
			if (noEle < N) {
				collection[noEle] = item;
				noEle++;
			}
		};
	};
}
#endif