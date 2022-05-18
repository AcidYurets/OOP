#ifndef __LAB_03_LOAD_MANAGER_HPP__
#define __LAB_03_LOAD_MANAGER_HPP__


#include <memory>
#include <implementation/load/directors/load_director.hpp>
#include "implementation/managers/manager.hpp"
#include "implementation/objects/object.hpp"

class LoadManager : public Manager {
public:
    LoadManager() = default;

    LoadManager(const LoadManager &) = delete;

    LoadManager &operator=(const LoadManager &) = delete;

    ~LoadManager() override = default;

    virtual std::shared_ptr<Object> load(const std::string &name);

    void setDirector(const std::shared_ptr<LoadDirector> &director);


private:
    std::shared_ptr<LoadDirector> director;
};


#endif //__LAB_03_LOAD_MANAGER_HPP__
