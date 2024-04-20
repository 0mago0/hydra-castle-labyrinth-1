//
// Created by a2685 on 2024/4/12.
//

#include "enemy.hpp"
void enemy::SetImage(const std::vector<std::string>& Path , int interval_number,bool loopting) {
    m_Drawable = std::make_shared<Util::Animation>( Path,true,interval_number,loopting,0);
}
void enemy::bomb(){
    std::vector<std::string> s ;
    for (int j =1 ; j <= 10 ; j ++){
        s.push_back(RESOURCE_DIR"/miscellaneous/bomb" +std::to_string(j)+".png");
    }
    m_Drawable = std::make_shared<Util::Animation>( s,true,40,false,0);
}
