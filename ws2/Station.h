#ifndef W2_STATION_H
#define W2_STATION_H

#include<iostream>
#include <string>


namespace w2 {

	class Station{

	protected:
		std::string m_stationName;
		unsigned int m_numStudentPass;
		unsigned int m_numAdultPass;

	public:
		enum PassType { Student, Adult };
		Station();
		~Station();
		void set(const std::string&, unsigned, unsigned);//set station name, adult and student pass
		void update(PassType, int);//update pass num depends on type
		unsigned inStock(PassType) const;//returns pass num depends on type
		const std::string& getName() const;//returns station name

		void display() const;
		unsigned int studentPass() const { return m_numStudentPass; }
		unsigned int adultPass() const { return m_numAdultPass; }
	};
}

#endif
