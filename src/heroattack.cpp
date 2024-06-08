//
// Created by a2685 on 2024/3/22.
//

#include "heroattack.hpp"

heroattack::heroattack(const std::vector<std::string>& Path) {
    SetImage(Path);
}
void heroattack::SetImage(const std::vector<std::string>& Path) {
    m_Drawable = std::make_shared<Util::Animation>( Path,false,70,false,0);
    m_Visible = false ;
}
void heroattack::attack(std::string forward,std::vector<std::shared_ptr<enemy>> &all_enemy,Util::Root &m_Root,bool m_hero_attacked) {
    m_ZIndex = 1 ;
    if(Util::Input::IsKeyDown(Util::Keycode::J) && already && m_hero_attacked == false ){
        already = false ;
        if(forward == "Lstay" || forward == "L"){
            SetImage(std::vector<std::string>{RESOURCE_DIR"/attack_tool/Lsword1.png",RESOURCE_DIR"/attack_tool/Lsword2.png",RESOURCE_DIR"/attack_tool/Lsword3.png",RESOURCE_DIR"/attack_tool/Lsword4.png",RESOURCE_DIR"/attack_tool/Lsword5.png"});
        }else{
            SetImage(std::vector<std::string>{RESOURCE_DIR"/attack_tool/sword1.png",RESOURCE_DIR"/attack_tool/sword2.png",RESOURCE_DIR"/attack_tool/sword3.png",RESOURCE_DIR"/attack_tool/sword4.png",RESOURCE_DIR"/attack_tool/sword5.png"});
        }

        m_Visible = true ;
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        temp->Play();
    }else if(!already && !already_attack){
        auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
        if(temp->GetCurrentFrameIndex() == 1 ){
            already_attack = true;
            for(int i = all_enemy.size()-1 ; i >=0 ; i--){
                float x1,y1,x2,y2,X,Y ;
                x1 = all_enemy[i]->GetPosition()[0] ;
                y1 = all_enemy[i]->GetPosition()[1] ;
                x2 = this->GetPosition()[0] ;
                y2 = this->GetPosition()[1] ;
                X = abs(x1-x2);
                Y = abs(y1-y2) ;
                if(sqrt(X*X + Y * Y) <= 50 ){
                    m_sfx = std::make_shared<Util::SFX>(RESOURCE_DIR"/Sound effects/ok_attack.wav");
                    m_sfx->SetVolume(5);
                    m_sfx->Play(0);
                    all_enemy[i]->m_miscellaneous->play(all_enemy[i]->GetPosition()) ;
                    all_enemy[i]->HP -= 1 ;
                    //  temp = std::dynamic_pointer_cast<Util::Animation>(all_enemy[i]) ;
                   // temp->Play();
                    //   temp->SetLooping(false);
                   // all_enemy[i]->SetVisible(false) ; //後續會有問題點
                }
            }
        }
    }
    auto temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable);
    if(temp->GetState() == Util::Animation::State::ENDED){
        already = true ;
        already_attack = false ;
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
