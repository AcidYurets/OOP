#ifndef __LAB_03_DRAW_VISITOR_HPP__
#define __LAB_03_DRAW_VISITOR_HPP__


#include <memory>
#include "implementation/objects/model/wireframe_model/model_details/point/point.hpp"
#include "implementation/objects/camera/camera.hpp"
#include "implementation/objects/composite/composite.hpp"
#include "implementation/drawer/drawer.hpp"
#include "implementation/visitor/visitor.hpp"


class DrawVisitor : public Visitor {
public:
    DrawVisitor(const std::shared_ptr<Drawer> &drawer, const std::shared_ptr<Camera> &camera);

    void visit(const Camera &camera) override;
    void visit(const Composite &composite) override;
    void visit(const WireframeModel &model) override;

private:
    std::shared_ptr<Drawer> drawer;
    std::shared_ptr<Camera> camera;

    Point projectPoint(const Point &point);
};


#endif //__LAB_03_DRAW_VISITOR_HPP__
