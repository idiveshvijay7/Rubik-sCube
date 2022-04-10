#ifndef DrawManager_h
#define DrawManager_h

#include "ShaderProgram.h"
#include "Cubemap.h"

#pragma warning(push, 0)
#include <dependencies/imgui/imgui.h>
#include <dependencies/imgui/imgui_impl_opengl3.h>
#include <dependencies/imgui/imgui_impl_glfw.h>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#pragma warning(pop)

#include <vector>
#include <array>
#include <assert.h>


class Camera;
class Drawable;
class IWidget;
class ILightSource;

class DrawManager {
public:
    DrawManager() = default;

    void Initialize();

    void RegisterCamera(Camera* camera);
    Camera* MainCamera() const;

    void Skybox(const std::string& right, const std::string& left, const std::string& top, const std::string& bottom, const std::string& back, const std::string& front);
    void Background(const glm::vec3& background);

    void RegisterDrawCall(Drawable* component);
    void UnregisterDrawCall(Drawable* component);

    void RegisterWidget(IWidget* widget);
    void UnregisterWidget(IWidget* widget);

    void RegisterLightSource(ILightSource* light_source);
    void UnregisterLightSource(ILightSource* light_source);

    void CallDraws() const;

private:
    glm::vec3 m_Background{ 0.0f };
    std::unique_ptr<Cubemap> m_Skybox{ nullptr };

    Camera* m_Camera{ nullptr };
    std::vector<Drawable*> m_Drawables;
    std::vector<IWidget*> m_Widgets;
    std::vector<ILightSource*> m_LightSources;

    std::array<ShaderProgram, static_cast<size_t>(ShaderProgram::Type::COUNT)> m_ShaderPrograms;
};

#endif
