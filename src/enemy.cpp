//
// Created by a2685 on 2024/4/12.
//

#include "enemy.hpp"
void enemy::SetImage(const std::vector<std::string>& Path , int interval_number,bool loopting,bool play) {
    m_ZIndex = 5 ;
    m_Drawable = std::make_shared<Util::Animation>( Path,play,interval_number,loopting,0);
}
void enemy::bomb(){
    std::vector<std::string> s ;
    for (int j =1 ; j <= 10 ; j ++){
        s.push_back(RESOURCE_DIR"/miscellaneous/bomb" +std::to_string(j)+".png");
    }
    hp_state = "die" ;
    m_Drawable = std::make_shared<Util::Animation>( s,true,40,false,0);
}

Util::Animation::State enemy::Getplaystate() {
    auto  temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
    return temp->GetState() ;
}
