#pragma once
#include <sstream>
template<typename T>

class Flex_Array
{
	int size;
	T* arr;
public:
	Flex_Array() : size(1), arr(new T[size]) {};

	Flex_Array(int _size) {
		if (_size < 0)
			size = 0;
		size = _size;
		arr = new T[size];
	};

	Flex_Array(const Flex_Array& object) {
		size = object.size;
		arr = new T[size];
		for (int i = 0; i < size; i++)
			arr[i] = object.arr[i];
	};

	~Flex_Array() {
		size = -1;
		delete[] arr;
	};

	int get_size() { return size; };
	T* get_array() { return arr; };
	T& operator[](int i) { return arr[i]; };

	Flex_Array<T>* append(int id, Flex_Array<T> object) {
		Flex_Array temp;
		temp.arr = arr; temp.size = size;
		size = size + object.size;  arr = new T[size];
		//id = id - 1;
		for (int i = 0; i < id; i++)
		{
			arr[i] = temp.arr[i];
		}
		for (int i = 0; i < object.size; i++)
		{
			arr[id + i] = object.arr[i];
		}
		for (int i = id + object.size; i <= size; i++)
		{
			arr[i] = temp.arr[i - object.size];
		}
		return this;
	};

	Flex_Array<T>* remove(int a, int b) {
		Flex_Array temp;
		temp.arr = arr; temp.size = size;
		int rem_size = b - a + 1;
		size = temp.size - rem_size;
		arr = new T[size];
		for (int i = 0; i < a; i++)
		{
			arr[i] = temp.arr[i];
		}
		for (int i = b + 1; i < temp.size; i++)
		{
			arr[i - rem_size] = temp.arr[i];
		}
		return this;
	}
	Flex_Array<T>* replace(int a, int b, Flex_Array<T> object) {
		Flex_Array temp;
		temp.arr = arr; temp.size = size;
		arr = new T[size];
		for (int i = 0; i < a; i++)
		{
			arr[i] = temp.arr[i];
		}
		for (int i = 0; i < object.size; i++)
		{
			arr[a + i] = object.arr[i];
		}
		for (int i = b + 1; i < temp.size; i++)
		{
			arr[i] = temp.arr[i];
		}
		return this;
	}

	int find(T object) {
		int result = -1;
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == object)
				result = i;
		}
		return result;
	}

	int finds(Flex_Array<T> object) {
		int result = -1;
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == object.arr[0])
				result = i;
		}
		for (int i = 1; i < object.size; i++)
		{
			if (arr[result + i] != object.arr[i])
				return -1;
		}
	}

	Flex_Array<T> operator= (const Flex_Array& object) {
		delete[] arr;
		size = object.size;
		arr = new T[size];
		for (int i = 0; i < size; i++)
			arr[i] = object.arr[i];
		return *this;
	};

	friend std::ostream& operator <<(std::ostream& out, T& a) {
		for (int i = 0; i < a.size; i++)
		{
			out << a.arr[i];
		}
	};

	friend std::istream& operator >> (std::istream& in, T& a) {
		in >> a.size;
		for (int i = 0; i < a.size; i++)
		{
			in >> a.arr[i];
		};
	}
};
