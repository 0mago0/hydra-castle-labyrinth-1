//
// Created by Yihss on 2024/5/1.
//

#ifndef REPLACE_WITH_YOUR_PROJECT_NAME_AMMO_HPP
#define REPLACE_WITH_YOUR_PROJECT_NAME_AMMO_HPP
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"
#include "Util/Animation.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "physics.hpp"
#include "map.hpp"
#include "heroattack.hpp"
#include "Util/Time.hpp"
#include <iostream>

class ammo: public Util::GameObject {
public:
    explicit ammo(std::string name) ;
    [[nodiscard]]  const glm::vec2 GetPosition() const { return m_Transform.translation; }
    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }
    void SetImage(const std::vector<std::string>& Path,int interval_number = 150,bool loopting = true,bool play = true);
    void play();
};


#endif //REPLACE_WITH_YOUR_PROJECT_NAME_AMMO_HPP
