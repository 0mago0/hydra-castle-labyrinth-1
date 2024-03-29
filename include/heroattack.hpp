//
// Created by a2685 on 2024/3/22.
//

#ifndef REPLACE_WITH_YOUR_PROJECT_NAME_HEROATTACK_HPP
#define REPLACE_WITH_YOUR_PROJECT_NAME_HEROATTACK_HPP
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"
#include "Util/Animation.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "physics.hpp"
#include "map.hpp"

class heroattack: public Util::GameObject {
public:
    explicit heroattack(const std::vector<std::string>& Path);
    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }
    void SetImage(const std::vector<std::string>& Path);
    void attack() ;
    //void Draw(const Util::Transform &transform, const float zIndex) override;
    void renw_position() ;
private:
    float stepx[5] = {-30,30,30,0,0} ;
    float stepy[5] = {30,0,0,0,0} ;
};


#endif //REPLACE_WITH_YOUR_PROJECT_NAME_HEROATTACK_HPP
