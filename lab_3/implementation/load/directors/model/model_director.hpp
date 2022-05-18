#ifndef __LAB_03_MODEL_DIRECTOR_HPP__
#define __LAB_03_MODEL_DIRECTOR_HPP__

#include "../load_director.hpp"

class ModelDirector : public LoadDirector {
public:
    ModelDirector();
    ~ModelDirector() = default;

    std::shared_ptr<Object> load(const std::string &src_name) override;
};


#endif //__LAB_03_MODEL_DIRECTOR_HPP__
