//
// Created by Yihss on 2024/3/1.
//
#include "physics.hpp"
#include "hero.hpp"
void hero::run() {
    chang_forward() ;
    float  x =floor((8 * 60 + this->GetPosition()[0]) / 60) ;
    float  y =floor((6*60 - this->GetPosition()[1]+30) / 60)  ;
    float  topy =floor((6*60 - this->GetPosition()[1]-30) / 60)  ;
    physics physics ;
    physics.set_data(map) ;
    auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
    if (Util::Input::IsKeyPressed(Util::Keycode::S) && hero_state == "climb_ladder") {
         if(physics.climb_ladder(x,y)){
             hero_state = "climb_ladder";
            this->SetPosition({x*60 - 8 * 60 + 30,this->GetPosition()[1]}) ;
            glm::vec now_XY = this->GetPosition() ;
            now_XY[1] = now_XY[1] - 4 ;
            this->SetPosition(now_XY) ;
        }
        if(hero_state == "climb_ladder" && !physics.climb_ladder(x,y) ){
            hero_state = "sky_down" ;
        }
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::W)) {
        physics.set_data(map);
        if (physics.climb_ladder(x, abs(topy)) && hero_state == "climb_ladder") {
            hero_state = "climb_ladder";
            this->SetPosition({x * 60 - 8 * 60 + 30, this->GetPosition()[1]});
            glm::vec now_XY = this->GetPosition();
            now_XY[1] = now_XY[1] + 4;
            this->SetPosition(now_XY);
        }
        if (hero_state == "climb_ladder" && !physics.climb_ladder(x, abs(topy))) {
           hero_state = "sky_down";
        }
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::A) && hero_state != "climb_ladder"  && hero_state != "attack_ground") {
        glm::vec now_XY = this->GetPosition() ;
        now_XY[0] = now_XY[0] - 4 ;
        this->SetPosition(now_XY) ;
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::D)&& hero_state != "climb_ladder"  && hero_state != "attack_ground") {
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

}

hero::hero(const std::vector<std::string>& ImagePath) {
    m_ZIndex =10 ;
    SetImage(ImagePath);
}

void hero::chang_forward(){
    if(hero_state == "attack_ground" ){
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
        if(temp->GetState() == Util::Animation::State::ENDED){
            if (Util::Input::IsKeyPressed(Util::Keycode::A) && this->forward == "L"){
                this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/Lstay.png" ,RESOURCE_DIR"/hero/Lrun.png" }) ;
            }else if(Util::Input::IsKeyPressed(Util::Keycode::D) && this->forward == "R") {
                this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/stay.png" ,RESOURCE_DIR"/hero/Rrun.png" }) ;
            }else{
                if (this->forward == "Lstay" || this->forward == "L" ){
                    this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/Lstay.png" }) ;
                }else{
                    this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/stay.png" }) ;

                }

            }
           auto temp2 = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
            temp2->SetLooping(true) ;
            temp2->Play() ;
            hero_state = "on_ground" ;
            attack_state = false ;
            return ;
        }else{
            return ;
        }
    }else if(attack_state){
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;

        if(temp->GetState() == Util::Animation::State::ENDED){
            attack_state = false ;
            if (this->forward == "Lstay" || this->forward == "L" ){
                this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/Lstay.png" ,RESOURCE_DIR"/hero/Lrun.png" }) ;
            }else{
                this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/stay.png" ,RESOURCE_DIR"/hero/Rrun.png" }) ;

            }            temp->Play() ;
            temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;

            temp->Play() ;
        }
    }
    if ((Util::Input::IsKeyUp(Util::Keycode::S) || Util::Input::IsKeyUp(Util::Keycode::W)) && hero_state =="climb_ladder"    ) {
        if(!Util::Input::IsKeyPressed(Util::Keycode::S) && !Util::Input::IsKeyPressed(Util::Keycode::W) ){
            std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->Pause() ;
        }
    }
    if ((Util::Input::IsKeyUp(Util::Keycode::D) || Util::Input::IsKeyUp(Util::Keycode::A)) && hero_state!= "climb_ladder"  ) {
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
    if (Util::Input::IsKeyDown(Util::Keycode::D) && hero_state!= "climb_ladder") {
        this->forward = "R" ;
        this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/stay.png" ,RESOURCE_DIR"/hero/Rrun.png" }) ;
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
        temp->Play() ;
    }
    if (Util::Input::IsKeyDown(Util::Keycode::A) && hero_state!= "climb_ladder" ) {
        this->forward = "L" ;
        this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/Lstay.png" ,RESOURCE_DIR"/hero/Lrun.png" }) ;
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
        temp->Play() ;
    }
    float  x =floor((8 * 60 + this->GetPosition()[0]) / 60) ;
    float  y =floor((6*60 - this->GetPosition()[1]+30) / 60)  ;
    float  topy =floor((6*60 - this->GetPosition()[1]-30) / 60)  ;
    if (Util::Input::IsKeyDown(Util::Keycode::S)  ) {
        physics physics ;
        physics.set_data(map) ;
        if(physics.climb_ladder(x,y)){
            hero_state = "climb_ladder";
            this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/climb1.png" ,RESOURCE_DIR"/hero/climb2.png",RESOURCE_DIR"/hero/climb3.png",RESOURCE_DIR"/hero/climb4.png",RESOURCE_DIR"/hero/climb5.png" }) ;
            auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
            temp->Play() ;
        }
    }
    if (Util::Input::IsKeyDown(Util::Keycode::W)){
        physics physics ;
        physics.set_data(map) ;
        if(physics.climb_ladder(x,topy)){
            hero_state = "climb_ladder";
            this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/climb1.png" ,RESOURCE_DIR"/hero/climb2.png",RESOURCE_DIR"/hero/climb3.png",RESOURCE_DIR"/hero/climb4.png",RESOURCE_DIR"/hero/climb5.png" }) ;
            auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
            temp->Play() ;
        }
    }
    if (Util::Input::IsKeyDown(Util::Keycode::J) && hero_state != "attack_ground"  && hero_state != "attack_jump"  ){
        if(hero_state == "one_jump" || hero_state == "sky_down" ){

        }else{
            hero_state = "attack_ground";
        }
        if(forward == "Lstay" || forward == "L"){
            this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/Lattack1_hero.png" ,RESOURCE_DIR"/hero/Lattack2_hero.png",RESOURCE_DIR"/hero/Lattack3_hero.png",RESOURCE_DIR"/hero/Lattack3_hero.png"}) ;
        }else{
            this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/attack1_hero.png" ,RESOURCE_DIR"/hero/attack2_hero.png",RESOURCE_DIR"/hero/attack3_hero.png",RESOURCE_DIR"/hero/attack3_hero.png"}) ;
        }
        attack_state = true ;
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
        temp->SetLooping(false) ;
        temp->Play() ;
    }
}
void hero::SetImage(const std::vector<std::string>& Path) {
    m_Drawable = std::make_shared<Util::Animation>( Path,false,150,true,0);
}
