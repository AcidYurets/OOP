#pragma once

# include <iostream>
# include <memory>

using namespace std;

template <typename Type>
class Singleton
{
public:
	template <typename ...Args>
	static Type& instance(Args ...args)
	{
		static unique_ptr<Type> myInstance = make_unique<Type>(args...);

		return *myInstance;
	}

	Singleton() = delete;
	Singleton(const Singleton<Type>&) = delete;
	Singleton<Type>& operator=(const Singleton<Type>&) = delete;
};
