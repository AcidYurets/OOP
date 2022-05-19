#include "solution_drawer_factory.hpp"
#include <implementation/exceptions/load_exceptions.hpp>

template <typename Tprod>
bool SolutionDrawerFactory::registration(std::string id)
{
	return callbacks.emplace(id, std::make_shared<Tprod>()).second;
}

std::shared_ptr<DrawerFactory> SolutionDrawerFactory::createFactory(std::string id)
{
	CallBackMap::const_iterator it = callbacks.find(id);

	if (it == callbacks.end())
	{
	    throw ConfigError(__FILE__, __LINE__, "wrong id");
	}

	return it->second;
}

