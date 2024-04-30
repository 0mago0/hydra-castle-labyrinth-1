#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <vector>
#include "Util/GameObject.hpp"
#include "Util/Root.hpp"
#include "hero.hpp"
#include "enemy.hpp"
#include "generate_enemy.hpp"
#include <fstream>
#include <iostream>
class generate_enemy ;

class map : public Util::GameObject {
public:
    explicit map(const std::string& ImagePath,const std::string& dataPath);
    void SetImage(const std::string& ImagePath);
    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }
    void read_data(const std::string& Path) ;
    void Transitions(std::vector<float> &jump_total,Util::Root &m_Root,std::vector<std::shared_ptr<enemy>> &all_enemy)  ;
    void clean(Util::Root &m_Root,std::vector<std::shared_ptr<enemy>> &all_enemy);
    int map_number = 0 ;
 //   generate_enemy* Generate_enemy ;
    glm::vec2 hero_position ;

private:

    void ResetPosition() { m_Transform.translation = {0, 0}; }
    float map_data[16][12];

    std::string m_ImagePath;
};


#endif //CHARACTER_HPP