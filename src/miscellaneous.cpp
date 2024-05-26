//
// Created by Yihss on 2024/5/10.
//

#include "miscellaneous.hpp"

miscellaneous::miscellaneous(std::string m_s){
    m_ZIndex = 20 ;
    std::vector<std::string> ImagePath  ;
    if(m_s == "attack_miscellaneous"){
        for (int j =1 ; j <= 6 ; j ++){
            ImagePath.push_back(RESOURCE_DIR"/miscellaneous/attack_miscellaneous" +std::to_string(j)+".png");
        }
    }
   // m_Visible = false ;
    SetImage(ImagePath,30,false) ;
}

void miscellaneous::SetImage(const std::vector<std::string> &Path, int inter, bool loopt) {
    m_Drawable = std::make_shared<Util::Animation>( Path,loopt,inter,false,0);
    auto  temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
    temp->SetCurrentFrame(5);
}
void miscellaneous::play(const glm::vec2& Position) {
    std::default_random_engine generator( time(NULL) );
    std::uniform_real_distribution<float> unif(-20.0, 20.0);
    float dx = unif(generator);
    float dy = unif(generator);
   // m_Visible = true  ;
    SetPosition({Position[0]+dx,Position[1]+dy}) ;
    auto  temp = std::dynamic_pointer_cast<Util::Animation>(m_Drawable) ;
    temp->SetCurrentFrame(0);
    temp->Play() ;
}