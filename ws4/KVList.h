#ifndef W4_KVLIST_H
#define W4_KVLIST_H
#include <iostream>

template<typename K, typename V, int N>
class KVList {

	K arrK[N];
	V arrV[N];
	int m_numPair;

	public:
		//default constructor to set safety state
		KVList() : m_numPair(0) {}

		//return number of pairs
		size_t size() const { return m_numPair; }

		//returns an unmodifiable reference to the key of element i in the list
		const K& key(int i) const {return arrK[i];}

		//returns an unmodifiable reference to the value of element i in the list
		const V& value(int i) const {return arrV[i];}
		
		//adds a new element to the list if room exists and returns a reference to the current object, does nothing if no room exists
		KVList& add(const K& k, const V& v) {
			if (m_numPair < N) {
				arrK[m_numPair] = k;
				arrV[m_numPair] = v;
				m_numPair++;
			}
			return *this;
		}
		
		//returns the index of the first element in the list with a key equal to k - defaults to 0	
		int find(const K& k) const {
			int index = 0;
			for (int i = 0; i < m_numPair; i++) {
				if (arrK[i] == k) {
					index = i;
				}
			}
				return index;
		}
		
		//replaces element i in the list with the key and value received and returns a reference to the current object
		KVList& replace(int i, const K& k, const V& v) {
			if (i < m_numPair && i >= 0) {
				arrK[i] = k;
				arrV[i] = v;
			}
			return *this;
		}


};


#endif
