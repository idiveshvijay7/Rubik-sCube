#ifndef ThirdPersonController_h
#define ThirdPersonController_h

#include "Component.h"
#include "../Object.h"
#include "../../scenes/Scene.h"
#include "../message_system/PropertyIn.h"

#include "../../utilities/Time.h"
#include "../../utilities/Input.h"

#pragma warning(push, 0)
#include <glm/gtx/rotate_vector.hpp>
#pragma warning(pop)

constexpr auto ROTATION_LIMIT = (75.0f * 3.14f / 180.0f);

class ThirdPersonController : public Component {
public:
    ThirdPersonController(class Object* target, glm::vec3 front, glm::vec3 right, float radius = 0.0f, float mouse_sensitivity = 0.1f);
    
    void Initialize() override;
    void Update() override;
    
    void Radius(float radius);
    float Radius() const  { return m_Radius; }

private:
    class Object* m_Target;
    Transform* m_TargetTransform;
    float m_Radius;
    float m_MouseSensitivity;
    
    glm::vec3 m_Front;
    glm::vec3 m_RotationAxis;
    float m_XRotation;
    float m_YRotation;
    
    glm::quat m_RotationBeetwen(const glm::vec3& start, const glm::vec3& dest);
};

#endif
