#include "set.h"
#include <cstdlib>
#include <algorithm>
#include <iostream>

template <class Item>
set<Item>::set() {
	data_count = 0;
	child_count = 0;
}

template <class Item>
set<Item>::~set() {
	;
}

template <class Item>
bool set<Item>::insert(const Item& entry) {
	if (!loose_insert(entry)) {
		return false;
	}

	if (data_count > MAXIMUM) {
		
		set<Item> new_set;
		
		for (int i = 0; i < (int)data_count; i++) {
			new_set.data[i] = data[i];
		}
		if (child_count != 0) {
			for (int i = 0; i < (int)child_count; i++) {
				new_set.subset[i] = subset[i];
			}
		}
		new_set.child_count = child_count;
		new_set.data_count = data_count;
		data_count = 0;
		child_count = 1;
		subset[0] = &new_set;
		new_set.show_contents(0);
		fix_excess(0);
		
		std::cout << "ccsubset.0data" << subset[0]->data_count << std::endl;
		std::cout << "subset.1data" << subset[1]->data_count << std::endl;
	}
	return true;
}

template <class Item>
std::size_t set<Item>::erase(const Item& target) {
	;
}

template <class Item>
std::size_t set<Item>::count(const Item& target) const {
	int i = 0;
	for (i = 0; i < data_count; i++) {
		if (data[i] >= target) {
			break;
		}
	}
	if (data[i] < target) {
		i = data_count;
	}
	if (data[i] == target) {
		return 1;
	}
	else if (child_count == 0) {
		return 0;
	}
	else {
		return subset[i].count(target);
	}
}

template <class Item>
bool set<Item>::loose_insert(const Item& entry) {
	int i = 0;
	for (i = 0; i < (int)data_count; i++) {
		if (data[i] < entry) {
			continue;
		}
		else if (data[i] == entry) {
			return false;
		}
		else {
			break;
		}
	}
	if (data[i] < entry) {
		i = data_count;
	}
	if (child_count == 0) {
		for (int j = data_count; j > i; j--) {
			data[j] = data[j-1];
		}
		data[i] = entry;
		data_count++;
		
		return true;
	}

	bool b = subset[i]->loose_insert(entry);
	if (subset[i]->data_count > MAXIMUM) {
		fix_excess(i);
	}
	return b;
}

template <class Item>
bool set<Item>::loose_erase(const Item& target) {
	;
}

template <class Item>
void set<Item>::remove_biggest(Item& removed_entry) {
	;
}

template <class Item>
void set<Item>::fix_excess(std::size_t i) {
	set<Item> fix_set;
	Item a = subset[i]->data[MINIMUM];
	int k = 0;

	for (int j = MINIMUM + 1; j <= MAXIMUM; j++) {
		fix_set.data[k] = subset[i]->data[j];
		k++;
	}
	if (subset[i]->child_count != 0) {
		k = 0;
		for (int j = MINIMUM + 1; j <= MAXIMUM + 1; j++) {
			fix_set.subset[k] = subset[i]->subset[j];
		}

		fix_set.child_count = MINIMUM + 1;
		subset[i]->child_count = MINIMUM + 1;
	}
	else {
		fix_set.child_count = 0;
		subset[i]->child_count = 0;
	}
	fix_set.data_count = MINIMUM;
	subset[i]->data_count = MINIMUM;



	for (int j = (int)data_count; j > (int)i; j--) {
		data[j] = data[j - 1];
	}
	data[i] = a;
	data_count++;


	for (int j = (int)child_count; j > (int)i + 1; j--) {
		subset[j + 1] = subset[j];
	}

	subset[i + 1] = &fix_set;
	child_count++;


	std::cout << "cccsubset.0data" << subset[0]->data_count << std::endl;
	std::cout << "sssubset.1data" << subset[1]->data_count << std::endl;
}

template <class Item>
void set<Item>::fix_shortage(std::size_t i) {
	;
}


template <class Item>
void set<Item>::show_contents(int i) {
	for (int i1 = data_count - 1; i1>= 0; i1--) {
		if (child_count != 0) {
			//subset[i1+1]->show_contents(i+1);
		}
		for (int i2 = 0; i2 < i; i2++) {
			std::cout << "  ";
		}
		std::cout << data[i1] << std::endl;;
	}
	if (child_count != 0) {
		
		subset[0]->show_contents(i+1);
	}

}
