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
#include "enemy.hpp"
#include "map.hpp"
#include<algorithm>
#include "Util/Root.hpp"

class heroattack: public Util::GameObject {
public:
    [[nodiscard]]  const glm::vec2 GetPosition() const { return m_Transform.translation; }
    explicit heroattack(const std::vector<std::string>& Path);
    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }
    void SetImage(const std::vector<std::string>& Path);
    void attack(std::string forward,std::vector<std::shared_ptr<enemy>> &all_enemy,Util::Root &m_Root,bool m_hero_attacked) ;

    //void Draw(const Util::Transform &transform, const float zIndex) override;
    void renw_position(std::string forward) ;
private:
    bool already = true ;
    float stepx[5] = {-10,30,30,0,0} ;
    float stepy[5] = {20,0,-15,0,0} ;
};


#endif //REPLACE_WITH_YOUR_PROJECT_NAME_HEROATTACK_HPP
