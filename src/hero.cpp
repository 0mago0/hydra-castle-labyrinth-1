//
// Created by Yihss on 2024/3/1.
//
#include "physics.hpp"
#include "hero.hpp"
void hero::run() {
    if(judge_die){
        return ;
    }
    if(hero_state == "attacked"){
        Invincible = true  ;
        if((forward == "L" ||forward == "Lstay") && phase_strike_fly == 0){
            attack_sfx = std::make_shared<Util::SFX>(RESOURCE_DIR"/Sound effects/hit02.wav");
            attack_sfx->SetVolume(5);
            attack_sfx->Play(0);
            SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/Lattacked1.png",RESOURCE_DIR"/hero/Lattacked2.png"},5,true);
            this->SetPosition({GetPosition()[0]+5,GetPosition()[1]+3}) ;
        }else if((forward == "R" ||forward == "stay") && phase_strike_fly == 0 ) {
            attack_sfx = std::make_shared<Util::SFX>(RESOURCE_DIR"/Sound effects/hit02.wav");
            attack_sfx->SetVolume(5);
            attack_sfx->Play(0);
            this->SetPosition({GetPosition()[0]-5,GetPosition()[1]+3}) ;
            SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/Rattacked1.png",RESOURCE_DIR"/hero/Rattacked2.png"},5,true);
        }
        if(forward == "L" ||forward == "Lstay"){
            this->SetPosition({GetPosition()[0]+5,GetPosition()[1]+3}) ;
        }else{
            this->SetPosition({GetPosition()[0]-5,GetPosition()[1]+3}) ;
        }
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
        temp->Play();
        move_xtotal +=5 ;
        move_ytotal += 3 ;
        if(move_xtotal >= 80 && move_ytotal >= 60){
            move_xtotal = 0 ;
            move_ytotal = 0 ;
            hero_state = "sky_down" ;
        }
        phase_strike_fly = 1 ;
        judge_keybord = false ;
        return ;
    }
    if(phase_strike_fly == 1  &&  move_xtotal == 0){
        nocontrol = true ;
        phase_strike_fly = 2 ;
        return;
    }else if(phase_strike_fly == 2) {
        inter =  Util::Time::GetElapsedTimeMs();
        if((forward == "L" ||forward == "Lstay") && phase_strike_fly == 2){
            SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/Lattacked3.png",RESOURCE_DIR"/hero/hide.png"},5,true);
        }else if((forward == "R" ||forward == "stay") && phase_strike_fly == 2) {
            SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/Rattacked3.png",RESOURCE_DIR"/hero/hide.png"},5,true);
        }
        phase_strike_fly = 3  ;
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
        temp->Play();
    }
    if(nocontrol){
        unsigned  int sa = Util::Time::GetElapsedTimeMs() -1000 ;
        if(inter < sa ){
            judge_die = judge_HP() ;
            if(judge_die) return ;
            if (this->forward == "Lstay" || this->forward == "L" ){
                this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/Lstay.png" ,RESOURCE_DIR"/hero/Lrun.png" }) ;
            }else{
                this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/stay.png" ,RESOURCE_DIR"/hero/Rrun.png" }) ;
            }
            auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
            phase_strike_fly = 0 ;
            nocontrol = false ;
            Invincible = false ;
        }else{
            return ;
        }
    }
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
            R_run =false ;
            L_run =false ;
            this->SetPosition({x * 60 - 8 * 60 + 30, this->GetPosition()[1]});
            glm::vec now_XY = this->GetPosition();
            now_XY[1] = now_XY[1] + 4;
            this->SetPosition(now_XY);
        }
        if (hero_state == "climb_ladder" && !physics.climb_ladder(x, abs(topy))) {
           hero_state = "sky_down";
        }
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::A) && judge_keybord && hero_state != "climb_ladder"  && hero_state != "attack_ground" && L_run) {
        glm::vec now_XY = this->GetPosition() ;
        now_XY[0] = now_XY[0] - 4 ;
        this->SetPosition(now_XY) ;
    }
    if (Util::Input::IsKeyPressed(Util::Keycode::D) &&   judge_keybord && hero_state != "climb_ladder"  && hero_state != "attack_ground" && R_run) {
        glm::vec now_XY = this->GetPosition() ;
        now_XY[0] = now_XY[0] + 4 ;
        this->SetPosition(now_XY) ;
    }
    if (Util::Input::IsKeyDown(Util::Keycode::SPACE) && hero_state == "on_ground") {
        jump_sfx = std::make_shared<Util::SFX>(RESOURCE_DIR"/Sound effects/jump01.wav");
        jump_sfx->SetVolume(5);
        jump_sfx->Play(0);
        jump_total = 0 ;
        glm::vec now_XY = this->GetPosition() ;
        jump_total += 15  ;
        now_XY[1] = now_XY[1] + 15 ;
        this->SetPosition(now_XY) ;
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
    m_ZIndex =100 ;
    SetImage(ImagePath);
}

void hero::chang_forward(){
    if(hero_state == "attack_ground" ){
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
        if(temp->GetState() == Util::Animation::State::ENDED){
            if(R_run)this->forward = "R"  ;
            if(L_run)this->forward = "L"  ;
            if (Util::Input::IsKeyPressed(Util::Keycode::A) ){
                this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/Lstay.png" ,RESOURCE_DIR"/hero/Lrun.png" }) ;
            }else if(Util::Input::IsKeyPressed(Util::Keycode::D) ) {
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
            if (Util::Input::IsKeyDown(Util::Keycode::D) && hero_state!= "climb_ladder" ) {
                judge_keybord = true ;
                R_run = true ;
                L_run =false ;
            }
            if (Util::Input::IsKeyDown(Util::Keycode::A) && hero_state!= "climb_ladder" ) {
                judge_keybord = true ;
                R_run = false  ;
                L_run = true ;
            }
            return ;
        }
    }else if(attack_state){
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;

        if(temp->GetState() == Util::Animation::State::ENDED){
            attack_state = false ;
            if (this->forward == "Lstay" || this->forward == "L" ){
                if (Util::Input::IsKeyPressed(Util::Keycode::A) ){
                    this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/Lstay.png" ,RESOURCE_DIR"/hero/Lrun.png" }) ;
                }else{
                    this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/Lstay.png"}) ;
                }
            }else{
                if (Util::Input::IsKeyPressed(Util::Keycode::D) ){
                    this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/stay.png" ,RESOURCE_DIR"/hero/Rrun.png" }) ;
                }else{
                    this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/stay.png" }) ;
                }
            }
            temp->Play() ;
            temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;

            temp->Play() ;
        }
    }
    if ((Util::Input::IsKeyUp(Util::Keycode::S) || Util::Input::IsKeyUp(Util::Keycode::W)) && hero_state =="climb_ladder"    ) {
        if(!Util::Input::IsKeyPressed(Util::Keycode::S) && !Util::Input::IsKeyPressed(Util::Keycode::W) ){
            std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->Pause() ;
        }
    }
    if(Util::Input::IsKeyUp(Util::Keycode::D) && R_run && hero_state!= "climb_ladder" ){
        R_run = false ;
        this->forward = "stay" ;
        this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/stay.png" }) ;
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
        temp->Play() ;
    }
    if(Util::Input::IsKeyUp(Util::Keycode::A)&& L_run && hero_state!= "climb_ladder" ){
        this->forward = "Lstay" ;
        L_run = false ;
        this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/Lstay.png" }) ;
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
        temp->Play() ;
    }
//    if ((Util::Input::IsKeyUp(Util::Keycode::D) || Util::Input::IsKeyUp(Util::Keycode::A)) && hero_state!= "climb_ladder"  ) {
//        if(!Util::Input::IsKeyPressed(Util::Keycode::D) && !Util::Input::IsKeyPressed(Util::Keycode::A) ){
//            if(this->forward == "L"){
//                this->forward = "Lstay" ;
//            }else{
//                this->forward = "stay" ;
//            }
//            std::dynamic_pointer_cast<Util::Animation>(m_Drawable)->Pause() ;
//            this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/" + this->forward + ".png" }) ;
//            auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
//            temp->Play() ;
//        }
//    }
    if (Util::Input::IsKeyDown(Util::Keycode::D) && hero_state!= "climb_ladder" ) {
        judge_keybord = true ;
        R_run = true ;
        L_run =false ;
        this->forward = "R" ;
        this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/stay.png" ,RESOURCE_DIR"/hero/Rrun.png" }) ;
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
        temp->Play() ;
    }
    if (Util::Input::IsKeyDown(Util::Keycode::A) && hero_state!= "climb_ladder" ) {
        judge_keybord = true ;
        R_run = false  ;
        L_run = true ;
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
        m_bgm = std::make_shared<Util::SFX>(RESOURCE_DIR"/Sound effects/hero_hit.wav");
        m_bgm->SetVolume(4);
        m_bgm->Play(0);
        if(hero_state == "one_jump" || hero_state == "sky_down" ){

        }else{
            hero_state = "attack_ground";
        }
        if(forward == "Lstay" || forward == "L"){
            this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/Lattack1_hero.png" ,RESOURCE_DIR"/hero/Lattack2_hero.png",RESOURCE_DIR"/hero/Lattack3_hero.png",RESOURCE_DIR"/hero/Lattack3_hero.png"},70) ;
        }else{
            this->SetImage(std::vector<std::string>{RESOURCE_DIR"/hero/attack1_hero.png" ,RESOURCE_DIR"/hero/attack2_hero.png",RESOURCE_DIR"/hero/attack3_hero.png",RESOURCE_DIR"/hero/attack3_hero.png"},70) ;
        }
        attack_state = true ;
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
        temp->SetLooping(false) ;
        temp->Play() ;
    }
}
void hero::SetImage(const std::vector<std::string>& Path,int inter,bool loopt) {
    m_Drawable = std::make_shared<Util::Animation>( Path,loopt,inter,true,0);
}
void hero::bomb() {
    std::vector<std::string> s ;
    for (int j =1 ; j <= 10 ; j ++){
        s.push_back(RESOURCE_DIR"/miscellaneous/bomb" +std::to_string(j)+".png");
    }
    m_Drawable = std::make_shared<Util::Animation>( s,true,40,false,0);

}
bool hero::judge_HP() {
    if(this->HP <= 0){
        this->bomb() ;
        return true ;
    }
    return  false ;
}
