ifndef W2_STATION_H
#define W2_STATION_H

#include<iostream>

namespace w2 {

	class Station{
		enum PassType { Student, Adult };
		char* m_stationName;
		unsigned int m_numStudentPass;
		unsigned int m_numAdultPass;

	public:
		Station();
		~Station();
		void set(const std::string&, unsigned, unsigned);
		void update(PassType, int);
		unsigned inStock(PassType) const;
		const std::string& getName() const;

	};
}

#endif
