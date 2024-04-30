//
// Created by Yihss on 2024/5/1.
//

#include "ammo.hpp"
ammo::ammo(std::string name){
    if(name == "grayguntower"){
        SetImage({RESOURCE_DIR"/ammo/gray_ammo1.png",RESOURCE_DIR"/ammo/gray_ammo2.png",RESOURCE_DIR"/ammo/gray_ammo3.png",RESOURCE_DIR"/ammo/gray_ammo4.png"},50,true,false);
    }
};
void ammo::SetImage(const std::vector<std::string>& Path , int interval_number,bool loopting,bool play) {
    m_ZIndex = 4 ;
    m_Drawable = std::make_shared<Util::Animation>( Path,play,interval_number,loopting,0);
}
void ammo::play() {
    auto  temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
    temp->Play() ;
}