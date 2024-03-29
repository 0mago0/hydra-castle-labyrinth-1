//
// Created by a2685 on 2024/3/22.
//

#include "heroattack.hpp"

heroattack::heroattack(const std::vector<std::string>& Path) {
    SetImage(Path);
}
void heroattack::SetImage(const std::vector<std::string>& Path) {
    m_Drawable = std::make_shared<Util::Animation>( Path,false,150,false,0);
   // m_Visible = false ;
}
void heroattack::attack() {
  //  m_ZIndex = - ;
    if(Util::Input::IsKeyDown(Util::Keycode::J)){
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        temp->Play();
    }

}
void heroattack::renw_position() {
    auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
    SetPosition({m_Transform.translation[0] + stepx[temp->GetCurrentFrameIndex()],m_Transform.translation[1]+ stepy[temp->GetCurrentFrameIndex()]});
}
