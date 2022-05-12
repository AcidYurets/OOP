//
// Created by ivaaahn on 26.05.2021.
//

#include <memory>
#include <implementation/exceptions/load_exceptions.hpp>


#include "registration_maker.hpp"
#include "implementation/load/loaders/model/file_model_loader/file_model_loader.hpp"
#include "implementation/load/loaders/camera/file_camera_loader/file_camera_loader.hpp"


void RegistrationMaker::makeRegistration(Solution &solution) {
    if (!solution.registerLoaderCreator(0, std::make_shared<ConObjectLoaderCreator<FileModelLoader>>()))
        throw ConfigError(__FILE__, __LINE__, "failed to register source loader");

    if (!solution.registerLoaderCreator(1, std::make_shared<ConObjectLoaderCreator<FileCameraLoader>>()))
        throw ConfigError(__FILE__, __LINE__, "failed to register source loader");
}
