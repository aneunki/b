#include <cstdlib>

template<class Item>
class set {
public:
	set();
	~set();
	//set(const set& source);
	//void operator =(const Item& target);
	//void clear();
	bool insert(const Item& entry);
	std::size_t erase(const Item& target);
	std::size_t count(const Item& target) const;
	//bool empty() const;
	//void print(int indent) const;

	set<Item> operator=(set<Item> set_to);
	void show_contents(int i);
private:
	static const size_t MINIMUM = 2;
	static const size_t MAXIMUM = MINIMUM * 2;
	std::size_t data_count;
	Item data[MAXIMUM + 1];
	std::size_t child_count;
	set* subset[MAXIMUM + 2];

	//bool is_leaf() const { return (child_count == 0); }
	bool loose_insert(const Item& entry);
	bool loose_erase(const Item& target);
	void remove_biggest(Item& removed_entry);
	void fix_excess(std::size_t i);
	void fix_shortage(std::size_t i);
};
