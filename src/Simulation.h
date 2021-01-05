
#include <Magnum/Math/Matrix4.h>
#include <Magnum/Shaders/Phong.h>

#include <Object.h>
#include "CameraManipulator.h"

namespace MOSP
{
    class ColoredDrawable : public Drawable3D
    {
        public:
            explicit ColoredDrawable(
                Object3D& object,
                Magnum::Shaders::Phong& shader,
                Magnum::GL::Mesh& mesh,
                const Magnum::Color4& color,
                DrawableGroup3D& group):
                Drawable3D{object, &group}, _shader(shader), _mesh(mesh), _color{color} {}

        private:
            void draw(const Matrix4& transformationMatrix, Camera3D& camera) override;

            Magnum::Shaders::Phong& _shader;
            Magnum::GL::Mesh& _mesh;
            Magnum::Color4 _color;
    };

    class Simulation
    {
        MOSP::Scene3D _scene;
        MOSP::Object _root{&_scene};
        CameraManipulator m_camMan{&_root};
        DrawableGroup3D _drawables;
        Magnum::Shaders::Phong _phongShader;
    public:
        Simulation();
        Object& rootObject() { return _root; }
        CameraManipulator& cameraManipulator() { return m_camMan; }
        Camera3D& camera() { return m_camMan.camera(); }
        Object *createColoredObject(Magnum::GL::Mesh& mesh, const Magnum::Color4 color, Matrix4 transform, Object *parent = nullptr);
        void draw();
    };
}
