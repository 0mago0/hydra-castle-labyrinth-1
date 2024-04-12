//
// Created by Yihss on 2024/3/1.
//

#ifndef REPLACE_WITH_YOUR_PROJECT_NAME_HERO_HPP
#define REPLACE_WITH_YOUR_PROJECT_NAME_HERO_HPP
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"
#include "Util/Animation.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "physics.hpp"
#include "map.hpp"
#include "heroattack.hpp"
class hero: public Util::GameObject{
public:
    void run();
    void chang_forward();
    explicit hero(const std::vector<std::string>& ImagePath);
    [[nodiscard]]  const glm::vec2 GetPosition() const { return m_Transform.translation; }
    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }
    void SetImage(const std::vector<std::string>& Path);
    std::string  hero_state ;
    std::string map ;
    std::string forward ;
private:
    bool attack_state = false ;
protected:
    float jump_total = 0 ;


};


#endif //REPLACE_WITH_YOUR_PROJECT_NAME_HERO_HPP
