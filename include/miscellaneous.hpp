//
// Created by Yihss on 2024/5/10.
//

#ifndef REPLACE_WITH_YOUR_PROJECT_NAME_MISCELLANEOUS_HPP
#define REPLACE_WITH_YOUR_PROJECT_NAME_MISCELLANEOUS_HPP
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
#include <random>
class miscellaneous: public Util::GameObject {
public:
    explicit miscellaneous(std::string m_s);
    [[nodiscard]]  const glm::vec2 GetPosition() const { return m_Transform.translation; }
    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }
    void SetImage(const std::vector<std::string>& Path , int inter = 150,bool loopt = false);
    void play(const glm::vec2& Position);
};


#endif //REPLACE_WITH_YOUR_PROJECT_NAME_MISCELLANEOUS_HPP
