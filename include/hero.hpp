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
#include "Util/BGM.hpp"
#include "physics.hpp"
#include "map.hpp"
#include "heroattack.hpp"
#include "Util/Time.hpp"
#include <iostream>
#include "Util/SFX.hpp"
class hero: public Util::GameObject{
public:
    void run();
    void chang_forward();

    explicit hero(const std::vector<std::string>& ImagePath);
    void bomb() ;
    [[nodiscard]]  const glm::vec2 GetPosition() const { return m_Transform.translation; }
    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }
    void SetImage(const std::vector<std::string>& Path , int inter = 150,bool loopt = false);
    bool judge_HP() ;
    std::string  hero_state ;
    std::string map ;
    std::string forward ;

    int HP = 100 ;

    bool nocontrol = false;
    bool Invincible = false,over_trans = false  ;

private:
    bool two_jump_shoes = true , two_jump = true ;
    std::shared_ptr<Util::SFX> jump_sfx,attack_sfx;
    std::shared_ptr<Util::SFX> m_bgm;
    float move_ytotal ,move_xtotal ;
    bool attack_state = false,R_run = false , L_run = false  ;
    bool judge_keybord =false,judge_die = false;
    int phase_strike_fly =0 ;
    unsigned long inter = 0 ;
protected:
    float jump_total = 0 ;


};


#endif //REPLACE_WITH_YOUR_PROJECT_NAME_HERO_HPP
