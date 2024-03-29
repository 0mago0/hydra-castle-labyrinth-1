//
// Created by a2685 on 2024/3/22.
//

#include "heroattack.hpp"

heroattack::heroattack(const std::vector<std::string>& Path) {
    SetImage(Path);
}
void heroattack::SetImage(const std::vector<std::string>& Path) {
    m_Drawable = std::make_shared<Util::Animation>( Path,false,100,false,0);
    m_Visible = false ;
}
void heroattack::attack(std::string forward) {
  //  m_ZIndex = - ;
    if(Util::Input::IsKeyDown(Util::Keycode::J) && already){
        already = false ;
        if(forward == "Lstay" || forward == "L"){
            SetImage(std::vector<std::string>{RESOURCE_DIR"/attack_tool/" + forward +"sword1.png",RESOURCE_DIR"/attack_tool/"+ forward +"sword2.png",RESOURCE_DIR"/attack_tool/"+ forward +"sword3.png",RESOURCE_DIR"/attack_tool/"+ forward +"sword4.png",RESOURCE_DIR"/attack_tool/"+ forward +"sword5.png"});
        }else{
            SetImage(std::vector<std::string>{RESOURCE_DIR"/attack_tool/sword1.png",RESOURCE_DIR"/attack_tool/sword2.png",RESOURCE_DIR"/attack_tool/sword3.png",RESOURCE_DIR"/attack_tool/sword4.png",RESOURCE_DIR"/attack_tool/sword5.png"});
        }
        m_Visible = true ;
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        temp->Play();
    }
    auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);

    if(temp->GetState() == Util::Animation::State::ENDED){
        already = true ;
    }
}
void heroattack::renw_position(std::string forward) {
    auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
    if(forward == "stay"  || forward == "R"){
        SetPosition({m_Transform.translation[0] + stepx[temp->GetCurrentFrameIndex()],m_Transform.translation[1]+ stepy[temp->GetCurrentFrameIndex()]});
    }else{
        SetPosition({m_Transform.translation[0] + -stepx[temp->GetCurrentFrameIndex()],m_Transform.translation[1]+ stepy[temp->GetCurrentFrameIndex()]});

    }


}
