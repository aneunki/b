#include <stdlib.h>
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include "set.cpp"


int main(void) {
	set<int> new_set;
	std::cout << "adas d ad " << std::endl;

	while (1) {
		int a = 0;

		std::cin >> a;

		new_set.insert(a);
		//new_set.show_contents(1);

		std::cout << "   " << std::endl;
	}
	return 0;
}
