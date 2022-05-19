#ifndef __LAB_03_WIREFRAME_MODEL_DIRECTOR_HPP__
#define __LAB_03_WIREFRAME_MODEL_DIRECTOR_HPP__

#include "../model_director.hpp"

class WireframeModelDirector : public ModelDirector {
public:
    WireframeModelDirector(std::shared_ptr<ObjectBuilder> builder);
    ~WireframeModelDirector() = default;

    std::shared_ptr<Object> load(const std::string &src_name) override;
};


#endif //__LAB_03_WIREFRAME_MODEL_DIRECTOR_HPP__
