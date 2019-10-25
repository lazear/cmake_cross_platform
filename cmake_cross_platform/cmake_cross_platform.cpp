#include "cmake_cross_platform.h"
#include "testfile.h"

#include <iostream>
#include <map>
#include <iterator>
#include <optional>
#include <vector>
#include <functional>
#include <initializer_list>
#include <string>


using namespace std;

template <typename K, typename V>
class HashMap {
public:
	HashMap() {
		inner = new map<K, V>();
	}

	void insert(const K& key, V val) {
		inner->insert({ key, val });
	}

	optional<reference_wrapper<V>> lookup(const K& key) {
		auto search = inner->find(key);
		if (search != inner->end()) {
			return { search->second };
		}
		else {
			return std::nullopt;
		}
	}

private:
	std::map<K, V>* inner;
};

template<typename T>
class Vec : public vector<T> {
public:
	using vector<T>::vector;

	std::optional<T&> operator[](int i) {
		if (i < vector<T>::size())
			return std::optional<T&> { vector<T>::at(i) };
		else
			return std::nullopt;
	}
};

double sum(const vector<double>& v) {
	double s = 0.0;
	for (auto elem : v)
		s += elem;
	return s;

}

int main()
{
	std::cout << "Hello World!\n";
	HashMap<char, int> map;

	map.insert('c', 10);
	auto res = map.lookup('c');
	if (res)
		std::cout << "found!";
	else
		std::cout << "not found";
	std::cout << std::endl;


	Vec<double> b{ 1, 2, 3 };
	for (auto x : b) {
		std::cout << x << std::endl;
	}

	Test t;
	t.bar();

	std::string str{ "hello, world" };
	vector<string> strs;
	strs.push_back(str);
	for (string& s : strs) {
		std::cout << s << '\n';
	}

	std::cout << str << '\n';;
	strs.push_back(std::move(str));
	std::cout << "unspecified behavior! " << str.size() << '\n';
	str = std::move(strs[1]);
	std::cout << "unspecified behavior! " << strs.at(1) << '\n';
}
