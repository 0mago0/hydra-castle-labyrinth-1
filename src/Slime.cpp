//
// Created by a2685 on 2024/4/12.
//

#include "Slime.hpp"
Slime::Slime() {
    //m_ZIndex = -1 ;
    SetImage(path,100,false) ;
    HP = 1 ;
  //  SetPosition({0,-60}) ;
    state = "on_ground" ;
}
void Slime::jump() {
    jump_total += 5 ;
    SetPosition({GetPosition()[0] , GetPosition()[1] + 5 }) ;
}
void Slime::move_even() {
    if(jump_total >= 120) {
        jp =false ;
        state = "sky_down" ;
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        temp->SetCurrentFrame(6) ;
        jump_total = 0 ;
        return ;
    }
    if(jp){
        aleardy = false ;
        this->jump() ;
        state = "one_jump" ;
        return ;
    }
    if(state == "on_ground" ){
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
       // temp->SetCurrentFrame(0) ;
       temp->Play() ;
    }
    auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
    if( temp->GetCurrentFrameIndex() == 5){
        temp->Pause() ;
        jp = true ;
    }
}
void Slime::attack(std::shared_ptr<hero> m_hero) {
    float x1,y1,x2,y2,x,y,distance ;
    x1 = m_hero->GetPosition()[0] ;
    y1 = m_hero->GetPosition()[1] ;
    x2 = GetPosition()[0] ;
    y2 = GetPosition()[1] ;
    x = x1-x2 ;
    y = y1-y2 ;
    distance = sqrt(x*x + y*y) ;
    if(distance < 30 && m_hero->HP > 0 && m_hero->nocontrol == false){
        m_hero->hero_state = "attacked" ;
        m_hero->HP -= 1 ;
        if (x2 > x1){
            m_hero->forward = "R" ;
        }else {
            m_hero->forward = "L" ;
        }
    }
}