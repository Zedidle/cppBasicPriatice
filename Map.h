#include <iostream>
#include <algorithm>
#include "string"
#include "map"
using namespace std;


namespace Map
{




	void Test()
	{
		map<int, bool> record;
		map<int, int> record2;

		record.emplace(1, false);
		record.emplace(1, true);
		record.insert_or_assign(2, false);
		record.insert_or_assign(3, false);
		record.insert_or_assign(4, false);
		record.insert_or_assign(5, true);

		record2.emplace(1, 2);
		record2.emplace(1, 2);

		//cout << record.size() << endl;

		cout << record2[1] << endl;


		cout << endl;


		typedef map<string, double> MakeMap_sd;
		MakeMap_sd Map_sd;
		Map_sd.insert(make_pair("A", 10));
		Map_sd.insert(make_pair("B", 11));
		Map_sd.insert(make_pair("C", 12));
		Map_sd.insert(make_pair("D", 13));
		MakeMap_sd::iterator pos;
		for (pos = Map_sd.begin(); pos != Map_sd.end(); pos++) {
			cout << pos->first << "," << pos->second << endl;
		}

		cout << endl;
		typedef multimap<string, double> MakeMultimap_sd;
		MakeMultimap_sd Multimap_sd;
		Multimap_sd.insert(make_pair("A", 10));
		Multimap_sd.insert(make_pair("A", 10));
		Multimap_sd.insert(make_pair("B", 11));
		Multimap_sd.insert(make_pair("B", 11));
		Multimap_sd.insert(make_pair("C", 12));
		Multimap_sd.insert(make_pair("C", 12));
		Multimap_sd.insert(make_pair("D", 13));
		Multimap_sd.insert(make_pair("D", 14));
		MakeMultimap_sd::iterator pos2;
		for (pos2 = Multimap_sd.begin(); pos2 != Multimap_sd.end(); pos2++) {
			cout << pos2->first << "," << pos2->second << endl;
		}

	}
}
