#pragma once
#include <vector>
#include <queue>

template<typename T>
struct Handle
{
	int index;
	Handle(int i = -1) : index(i), dataref(&GlobalData<T>::getData()) {}

	T *operator->()       { return &GlobalData<T>::at(index); }
	T *operator->() const { return &GlobalData<T>::at(index); }

	T  operator*()       { return GlobalData<T>::at(index); }
	T &operator*() const { return GlobalData<T>::at(index); }

	T *operator&() { return &GlobalData<T>::at(index); }

	operator int()       { return index; }
	operator int() const { return index; }

private:
	std::vector<T> *dataref;
};

template<typename T>
class GlobalData
{
	int index;
	bool isEmpty;

	static std::queue<int> &getQueue() { static std::queue<int> q; return q; }

public:
	static std::vector<T> &getData() { static std::vector<T> d; return d; }

	static T &at(int i) { return getData()[i]; }

	static void free(int i)
	{
		if (i > -1 && !at(i).isEmpty)
		{
			at(i).onFree();
			getQueue().push(i);
			at(i).isEmpty = true;
			at(i).index = -1;
		}
	}

	static Handle<T> make()
	{
		int i = -1; //Sets a default invalid index of -1

		//Check if there's any empty spots in the queue to use
		if (getQueue().size() > 0)
		{
			i = getQueue().front();
			getQueue().pop();
		}
		else { i = getData().size();; getData().emplace_back(); }

		at(i).index = i;
		at(i).isEmpty = false;
		return Handle<T>{i};
	}

	int getIndex() { return index; }
	bool isValid() { return !isEmpty; }
	virtual void onFree(){}
};