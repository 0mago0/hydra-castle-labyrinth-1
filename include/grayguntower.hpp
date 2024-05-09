//
// Created by Yihss on 2024/4/24.
//

#ifndef REPLACE_WITH_YOUR_PROJECT_NAME_GRAYGUNTOWER_HPP
#define REPLACE_WITH_YOUR_PROJECT_NAME_GRAYGUNTOWER_HPP
#include "enemy.hpp"
#include "physics.hpp"
#include "ammo.hpp"
class ammo ;
class grayguntower: public enemy {
public:
    explicit grayguntower(std::string Forward) ;
    void move_even() override ;
    void attack(std::shared_ptr<hero> m_hero) override ;
    std::shared_ptr<ammo> Ammo = std::make_shared<ammo>("grayguntower");
    void ammo_bomb_judge(float h_x,float h_y , float m_x , float m_y,std::shared_ptr<hero> m_hero) ;
    std::string forward = "R" ;
protected:
    float distance = 0 ;
    std::vector<std::string> Rpath = {RESOURCE_DIR"/enemy/Rgray_autotown1.png",RESOURCE_DIR"/enemy/Rgray_autotown2.png"} ;
    std::vector<std::string> Lpath = {RESOURCE_DIR"/enemy/Lgray_autotown1.png",RESOURCE_DIR"/enemy/Lgray_autotown2.png"} ;
};


#endif //REPLACE_WITH_YOUR_PROJECT_NAME_GRAYGUNTOWER_HPP
