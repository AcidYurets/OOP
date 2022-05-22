#pragma once

# include <iostream>
# include <memory>
# include "manager.hpp"


using namespace std;

class BaseManagerCreator
{
public:
	shared_ptr<Manager> getManager() {
		if (!manager)
		{
			manager = createManager();
		}

		return manager;
	}

protected:
	virtual shared_ptr<Manager> createManager() = 0;

private:
	shared_ptr<Manager> manager;
};

template <typename ConManager>
class ManagerCreator : public BaseManagerCreator
{
protected:
	virtual shared_ptr<Manager> createManager() override 
	{
		return shared_ptr<Manager>(make_shared<ConManager>());
	}
};
