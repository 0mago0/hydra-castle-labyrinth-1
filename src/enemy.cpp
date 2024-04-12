//
// Created by a2685 on 2024/4/12.
//

#include "enemy.hpp"
void enemy::SetImage(const std::vector<std::string>& Path) {
    m_Drawable = std::make_shared<Util::Animation>( Path,false,150,true,0);
}