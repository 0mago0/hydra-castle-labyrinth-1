//
// Created by Yihss on 2024/3/1.
//

#include "hero.hpp"
void hero::run() {
    chang_forward() ;
    if (Util::Input::IsKeyPressed(Util::Keycode::D)) {
        glm::vec now_XY = this->GetPosition() ;
        now_XY[0] = now_XY[0] + 4 ;
        this->SetPosition(now_XY) ;
    }
    if (Util::Input::IsKeyDown(Util::Keycode::SPACE) && hero_state == "on_ground") {
        jump_total = 0 ;
        hero_state = "one_jump" ;
    }
     if(Util::Input::IsKeyPressed(Util::Keycode::SPACE) && jump_total <= 130 && hero_state == "one_jump"){
        glm::vec now_XY = this->GetPosition() ;
         jump_total += 8  ;
        now_XY[1] = now_XY[1] + 8 ;
        this->SetPosition(now_XY) ;
     }else if(jump_total > 130 && hero_state == "one_jump" ){
         hero_state = "sky_down" ;
     }
    if(Util::Input::IsKeyUp(Util::Keycode::SPACE)&& hero_state == "one_jump" ){
        hero_state = "sky_down" ;
    }

    if (Util::Input::IsKeyPressed(Util::Keycode::A)) {
        glm::vec now_XY = this->GetPosition() ;
        now_XY[0] = now_XY[0] - 4 ;
        this->SetPosition(now_XY) ;
    }
}
hero::hero(const std::vector<std::string>& ImagePath) {
    m_ZIndex =10 ;
    SetImage(ImagePath);
}
void hero::chang_forward(){
    if (Util::Input::IsKeyUp(Util::Keycode::D) || Util::Input::IsKeyUp(Util::Keycode::A)) {
        if(!Util::Input::IsKeyPressed(Util::Keycode::D) && !Util::Input::IsKeyPressed(Util::Keycode::A) ){
            if(this->forward == "L"){
                this->forward = "Lstay" ;
            }else{
                this->forward = "stay" ;
            }
            std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->Pause() ;
            this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/" + this->forward + ".png" }) ;
            auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
            temp->Play() ;
        }
    }
    if (Util::Input::IsKeyDown(Util::Keycode::D)) {
        this->forward = "R" ;
        this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/stay.png" ,RESOURCE_DIR"/hero/Rrun.png" }) ;
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
        temp->Play() ;
    }
    if (Util::Input::IsKeyDown(Util::Keycode::A)) {
        this->forward = "L" ;
        this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/Lstay.png" ,RESOURCE_DIR"/hero/Lrun.png" }) ;
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
        temp->Play() ;
    }
}
void hero::SetImage(const std::vector<std::string>& Path) {
    m_Drawable = std::make_shared<Util::Animation>( Path,false,150,true,0);
}
