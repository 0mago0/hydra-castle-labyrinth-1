//
// Created by Yihss on 2024/4/20.
//

#ifndef REPLACE_WITH_YOUR_PROJECT_NAME_CATERPILLAR_HPP
#define REPLACE_WITH_YOUR_PROJECT_NAME_CATERPILLAR_HPP
#include "enemy.hpp"
#include "physics.hpp"

class caterpillar: public enemy {
public:
    explicit caterpillar() ;
    void move_even() override ;
    void attack(const glm::vec2& hero_position) override ;
protected:
    float move_total = 0;
    bool jp = false ,aleardy = false;

    std::string forward = "R" ;
    std::vector<std::string> Rpath = {RESOURCE_DIR"/enemy/Rcaterpillar1.png",RESOURCE_DIR"/enemy/Rcaterpillar2.png",RESOURCE_DIR"/enemy/Rcaterpillar3.png"} ;
    std::vector<std::string> Lpath = {RESOURCE_DIR"/enemy/Lcaterpillar1.png",RESOURCE_DIR"/enemy/Lcaterpillar2.png",RESOURCE_DIR"/enemy/Lcaterpillar3.png"} ;

};


#endif //REPLACE_WITH_YOUR_PROJECT_NAME_CATERPILLAR_HPP
