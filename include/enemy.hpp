//
// Created by a2685 on 2024/4/12.
//

#ifndef REPLACE_WITH_YOUR_PROJECT_NAME_ENEMY_HPP
#define REPLACE_WITH_YOUR_PROJECT_NAME_ENEMY_HPP
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"
#include "Util/Animation.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"

class enemy: public Util::GameObject {
public:
    [[nodiscard]]  const glm::vec2 GetPosition() const { return m_Transform.translation; }
    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }
    void SetImage(const std::vector<std::string>& Path,int interval_number = 150,bool loopting = true);
    void bomb();
    virtual void attack(const glm::vec2& hero_position) = 0;
    virtual void move_even() = 0;
    std::string state  ;
protected:
    int attack_distance = 0 ;
    int HP  = 0 ;

};


#endif //REPLACE_WITH_YOUR_PROJECT_NAME_ENEMY_HPP
