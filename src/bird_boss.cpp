//
// Created by Yihss on 2024/6/9.
//

#include "bird_boss.hpp"
//
// Created by Yihss on 2024/4/20.
//

bird_boss::bird_boss() {
    //m_ZIndex = -1 ;
    bird_state = "stay" ;
    if(forward == "R"){
        SetImage(Rpath,200,true) ;
    }else{
        SetImage(Lpath,200,true) ;
    }
    HP = 20 ;
    //  SetPosition({0,-60}) ;
    state = "on_ground" ;
}
void bird_boss::change_forward(int interval) {
    if(forward == "R") {
        forward = "L";
        SetImage(Lpath,interval,true) ;
    }else{
        forward = "R" ;
        SetImage(Rpath,interval,true) ;

    }
}
bool bird_boss::prevent_out_border(){
    if(forward == "R"){
        if(GetPosition()[0] >= 340 ){
            return false ;
        }
    }else if(GetPosition()[0] <= -232){
        return false ;
    }

return true ;
}
void bird_boss::run() {
    if(bird_state == "run_attack"){
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
        if(temp->GetCurrentFrameIndex() > Rindex){
            temp->SetCurrentFrame(Lindex) ;
        }
        if(forward == "R" && prevent_out_border()){
            SetPosition({GetPosition()[0]+5,GetPosition()[1]}) ;
        }else if(forward == "L" && prevent_out_border()){
            SetPosition({GetPosition()[0]-5,GetPosition()[1]}) ;
        }
        x_total += 5 ;
        move_total += 5  ;
        if(x_total >= 500){
            x_total = 0 ;
            int temp_index = temp->GetCurrentFrameIndex() ;
            change_forward(150);
            auto temp2 = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;

            temp2->SetCurrentFrame(temp_index) ;
        }
        if(move_total >= 1000){
            start_time = false ;
            move_total = 0 ;
            change_forward(200);
            change_forward(200);
            bird_state = "stay" ;
            Lindex = 0 ;
            Rindex = 5 ;
        }
    }
    if(bird_state == "jump_attack"){
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
        if(temp->GetCurrentFrameIndex() == 9 && y_total <= 180 ){
            state = "one_jump" ;
            if(forward == "R" && prevent_out_border()){
                SetPosition({GetPosition()[0]+4,GetPosition()[1]+5}) ;
            }else if(forward == "L" && prevent_out_border()){
                SetPosition({GetPosition()[0]-4,GetPosition()[1]+5}) ;
            }
            y_total += 5 ;
        }
        if(state == "one_jump"){

            temp->SetCurrentFrame(Rindex) ;
        }
        if(state == "sky_down"){
            temp->SetCurrentFrame(Lindex) ;
        }
        if(state == "on_ground" && y_total > 180){
                jump_sfx = std::make_shared<Util::SFX>(RESOURCE_DIR"/Sound effects/bossjump.mp3");
                jump_sfx->SetVolume(5);
                jump_sfx->Play(0);
                start_time = false ;
                temp->SetLooping(true);
                temp->SetInterval(150) ;
                y_total = 0 ;
                bird_state = "stay" ;
                Lindex = 0 ;
                Rindex = 5 ;
                jump_interval = 0 ;
        }else if(y_total > 180 && state != "sky_down"){
            temp->SetCurrentFrame(Lindex) ;
            state = "sky_down" ;
        }
    }
    if(bird_state == "stay"){
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
        if(temp->GetCurrentFrameIndex() > Rindex){
            temp->SetCurrentFrame(Lindex) ;
        }
    }
}
void bird_boss::move_even() {
    std::random_device rd; // 種子產生器
    std::mt19937 gen = std::mt19937(rd()); //使用mt19937引擎
    std::uniform_int_distribution<int> dis(1, 2); //使用平均分佈
    auto randfun = std::bind(dis, gen);
    if(bird_state == "stay" && !start_time){
        start_time = true ;
        attack_interval = Util::Time::GetElapsedTimeMs() ;
    }
    if(bird_state == "stay" && Util::Time::GetElapsedTimeMs() - attack_interval > 3000 && start_time){
        if(randfun() == 1){
            Lindex = 5 ;
            Rindex = 7 ;
            auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
            temp->SetLooping(true) ;
            temp->SetCurrentFrame(Lindex) ;
            temp->SetInterval(150) ;
            bird_state = "run_attack" ;
            x_total = 0 ;
            y_total = 0 ;
        }else if(randfun() == 2){
            Lindex = 8;
            Rindex = 9 ;
            auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
            temp->SetCurrentFrame(Lindex) ;
            temp->SetInterval(400) ;
            temp->SetLooping(true) ;
            x_total = 0 ;
            y_total = 0 ;
            bird_state = "jump_attack" ;
        }
    }
    run() ;


}
void bird_boss::attack(std::shared_ptr<hero> m_hero) {
    float x1,y1,x2,y2,x,y,distance ;
    x1 = m_hero->GetPosition()[0] ;
    y1 = m_hero->GetPosition()[1] ;
    x2 = GetPosition()[0] ;
    y2 = GetPosition()[1] ;
    x = x1-x2 ;
    y = y1-y2 ;
    distance = sqrt(x*x + y*y) ;
    if(bird_state == "stay") {
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
        if(GetPosition()[0] > m_hero->GetPosition()[0] && forward != "L"){
            int temp_index = temp->GetCurrentFrameIndex() ;
            change_forward(200) ;
            temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
            temp->SetCurrentFrame(temp_index) ;
        }else if(GetPosition()[0] < m_hero->GetPosition()[0] && forward != "R"){
            int temp_index = temp->GetCurrentFrameIndex() ;
            change_forward(200) ;
            temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
            temp->SetCurrentFrame(temp_index) ;
        }
    }
    if(distance < 70 && m_hero->HP > 0 && !m_hero->Invincible){
        m_hero->hero_state = "attacked" ;
        m_hero->HP -= 5 ;
        m_hero->Invincible = true  ;
        if (x2 > x1){
            m_hero->forward = "R" ;
        }else {
            m_hero->forward = "L" ;
        }
    }
}
