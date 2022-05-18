    //

//

#ifndef __LAB_03_LOAD_DIRECTOR_HPP__
#define __LAB_03_LOAD_DIRECTOR_HPP__


#include <memory>
#include <utility>

#include "implementation/load/loaders/object_loader.hpp"
#include "implementation/objects/object.hpp"


class LoadDirector {
public:
    LoadDirector() = default;

    ~LoadDirector() = default;

    virtual std::shared_ptr<Object> load(const std::string &name) = 0;

protected:
    std::shared_ptr<ObjectLoader> loader;
};

#endif //__LAB_03_LOAD_DIRECTOR_HPP__