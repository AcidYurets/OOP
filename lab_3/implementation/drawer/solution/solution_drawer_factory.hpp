#pragma once

#include <map>
#include <string>
#include "../drawer.hpp"

class SolutionDrawerFactory
{
	using CallBackMap = std::map<std::string, std::shared_ptr<DrawerFactory>> ;

public:
	SolutionDrawerFactory() = default;

	template <typename Tprod>
	bool registration(std::string id);
	bool check(std::string id) { return callbacks.erase(id) == 1; }

	std::shared_ptr<DrawerFactory> createFactory(std::string id);

private:
	CallBackMap callbacks{};
};


