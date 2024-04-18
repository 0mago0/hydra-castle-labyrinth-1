#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <vector>
#include "Util/GameObject.hpp"
#include "hero.hpp"
#include <fstream>
#include <iostream>
class map : public Util::GameObject {
public:
    explicit map(const std::string& ImagePath,const std::string& dataPath);
    void SetImage(const std::string& ImagePath);
    void SetPosition(const glm::vec2& Position) { m_Transform.translation = Position; }
    void read_data(const std::string& Path) ;
    void Transitions()  ;
    int map_number = 0 ;
    glm::vec2 hero_position ;
    // const glm::vec2& GetPosition(glm::vec2  Position)
private:

    void ResetPosition() { m_Transform.translation = {0, 0}; }
    float map_data[16][12];

    std::string m_ImagePath;
};


#endif //CHARACTER_HPP