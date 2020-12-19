
#include <Magnum/Shaders/Phong.h>
#include <Magnum/Math/Matrix4.h>
#include "SceneGraph.h"

namespace MOSP
{
    class ColoredDrawable : public SceneGraph::Drawable3D
    {
        public:
            explicit ColoredDrawable(
                SceneGraph::Object3D& object,
                Magnum::Shaders::Phong& shader,
                Magnum::GL::Mesh& mesh,
                const Magnum::Color4& color,
                SceneGraph::DrawableGroup3D& group):
                SceneGraph::Drawable3D{object, &group}, _shader(shader), _mesh(mesh), _color{color} {}

        private:
            void draw(const SceneGraph::Matrix4& transformationMatrix, SceneGraph::Camera3D& camera) override;

            Magnum::Shaders::Phong& _shader;
            Magnum::GL::Mesh& _mesh;
            Magnum::Color4 _color;
    };

    class Simulation
    {
        SceneGraph::Scene3D _root;
        SceneGraph::Object3D _camObject{&_root};
        SceneGraph::Camera3D _camera{_camObject};
        SceneGraph::DrawableGroup3D _drawables;
        Magnum::Shaders::Phong _phongShader;
    public:
        Simulation();
        SceneGraph::Scene3D& rootObject() { return _root; }
        SceneGraph::Object3D& cameraObject() { return _camObject; }
        SceneGraph::Camera3D& camera() { return _camera; }
        SceneGraph::Object3D *createColoredObject(Magnum::GL::Mesh& mesh, const Magnum::Color4 color, SceneGraph::Matrix4 transform, SceneGraph::Object3D *parent = nullptr);
        void draw();
    };
}
