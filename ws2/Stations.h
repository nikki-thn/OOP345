#ifndef W2_STATIONS_H
#define W2_STATIONS_H
#include "Station.h"

namespace w2 {

	class Stations {

		char* m_fileName;
		int m_numStations;
		Station* m_stations;

	public:
		Stations(const char* filename); //constructor
		~Stations(); //destructor
		
		void update() const; //accepts num of passes sold and update data for each station
		void restock() const; //accepts num of passes added and ....
		void report() const;// reports current number of passes avail at each station
	
	};
}

#endif
