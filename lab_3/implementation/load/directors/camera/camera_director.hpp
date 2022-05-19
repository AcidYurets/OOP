#ifndef __LAB_03_CAMERA_DIRECTOR_HPP__
#define __LAB_03_CAMERA_DIRECTOR_HPP__

#include "../load_director.hpp"

class CameraDirector : public LoadDirector {
public:
    CameraDirector(std::shared_ptr<ObjectBuilder> builder);
    ~CameraDirector() = default;

    std::shared_ptr<Object> load(const std::string &src_name) override;
};


#endif //__LAB_03_CAMERA_DIRECTOR_HPP__
