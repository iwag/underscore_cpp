
#include <iostream>
#include <vector>
#include <map>
#include "underscore.hpp"

int main() {
	std::vector<int>	a{1,2,3,4};	
	std::vector<int> b(a.size());
	
	std::cout << "each" << std::endl;
	underscore::each(a, 
			[&](int i){std::cout << i << " ";} );
	std::cout << std::endl;

	std::cout << "map" << std::endl;
	underscore::map(a, b.begin(),
			[](int i){ return i*2; });
	underscore::each(b, 
			[&](int i){ std::cout << i << " "; } );
	std::cout << std::endl;

	std::cout << "reduce" << std::endl;
	auto sum = underscore::reduce(a,
			[](int i, int j){ return i+j; }, 0);
	std::cout << "sum=" << sum << std::endl; 

	std::cout << "reduceRight" << std::endl;

	std::cout << "find" << std::endl;
	auto found = underscore::find(a, 2);
	std::cout << "find? " << (found? *found:0) << std::endl;

	b = {0,0}; // FIXME
	std::cout << "filter" << std::endl;
	underscore::filter(a, b.begin(),
			[](int i) { return (i%2)==0; } );
	underscore::each(b, 
			[&](int i){ std::cout << i << " "; } );
	std::cout << std::endl;

	std::cout << "all even?" 
		<< underscore::all(a, [](int i){ return i%2==0;}) << std::endl;
	std::cout << "all >=0?" 
		<< underscore::all(a, [](int i){ return i>=0;}) << std::endl;

	b.reserve(a.size());
	std::cout << "reject even ";
	underscore::reject(a, b.begin(),
			[](int i) { return (i%2)==0; } );
	underscore::each(b, 
			[&](int i){ std::cout << i << " "; } );
	std::cout << std::endl;

	std::cout << "any 0? " 
		<< underscore::all(a, [](int i){ return i==0;}) << std::endl;
	std::cout << "any >3 " 
		<< underscore::all(a, [](int i){ return i>3;}) << std::endl;

	std::cout << "contains 1 " 
		<< underscore::contains(a, 1) << std::endl;


	std::vector<int> c(10);
	underscore::initial(c.begin(), 10, 1);
	std::cout << "initial 1 ";
	underscore::each(c, 
			[&](int i){ std::cout << i << " "; } );
	std::cout << std::endl;

	std::multimap<int,int> mm;
	underscore::groupBy(a, mm, [](int i){ return (i%2)==0;});
	std::cout << "groupBy odd/even=";
	underscore::each(mm, 
			[&](std::pair<int,int> i){ std::cout << i.first << "," << i.second << " "; } );
	std::cout << std::endl;

	std::map<int,int> m;
	underscore::countBy(a, m, [](int i){ return i%2==0;});
	std::cout << "countBy odd/even=";
	underscore::each(m, 
			[&](std::pair<int,int> i){ std::cout << i.first << "," << i.second << " "; } );
	std::cout << std::endl;

}

