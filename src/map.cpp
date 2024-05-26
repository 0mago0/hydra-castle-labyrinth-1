#include "map.hpp"
#include "Util/Image.hpp"


map::map(const std::string& ImagePath,const std::string& dataPath) {
    SetImage(ImagePath);
    read_data(dataPath) ;
    ResetPosition();
}
void map::SetImage(const std::string& ImagePath) {
    m_ImagePath = ImagePath;
    m_Drawable = std::make_shared<Util::Image>(RESOURCE_DIR"/background/" + m_ImagePath);
    m_Drawable->Draw({{0,0},0,{2,2}},-50);
}
void map::read_data(const std::string& Path){
    std::ifstream inputfile(RESOURCE_DIR"/map_data/" + Path);
    for(int y =0;y<16;y++)
    {
        for(int x=0;x<13;x++)
        {
            inputfile >> map_data[y][x];
        }
    }
}
void  map::Transitions(std::vector<float> &jump_total,Util::Root &m_Root,std::vector<std::shared_ptr<enemy>> &all_enemy) {
    if(hero_position[0] > 476){
        hero_position = {-420 , hero_position[1]} ;
        this->map_number +=1 ;
        SetImage("p" + std::to_string(map_number) + ".png" ) ;
        std::vector<float>().swap(jump_total);
        clean(m_Root,all_enemy) ;

    }
    if(hero_position[0] < -470){
        hero_position = {420 , hero_position[1]} ;
        this->map_number -=1 ;
        SetImage("p" + std::to_string(map_number) + ".png" ) ;
        std::vector<float>().swap(jump_total);
        clean(m_Root,all_enemy) ;
      //  GenerateEnemy->generat(m_Root,all_enemy) ;

    }
    if(hero_position[1] < -340){
        hero_position = {hero_position[0] ,340 } ;
        this->map_number +=8 ;
        SetImage("p" + std::to_string(map_number) + ".png" ) ;
        std::vector<float>().swap(jump_total);
        clean(m_Root,all_enemy) ;
       // GenerateEnemy->generat(m_Root,all_enemy) ;

    }
    if(hero_position[1] > 340){
        hero_position = {hero_position[0] ,-340 } ;
        this->map_number -=8 ;
        SetImage("p" + std::to_string(map_number) + ".png" ) ;
        std::vector<float>().swap(jump_total);
        clean(m_Root,all_enemy) ;
      //  GenerateEnemy->generat(m_Root,all_enemy) ;
    }
}
void map::clean(Util::Root &m_Root,std::vector<std::shared_ptr<enemy>> &all_enemy){
    clsglobal::bricks_x.clear();
    clsglobal::bricks_y.clear();
    clsglobal::bricks_number.clear();
    for(int i =all_enemy.size() -1 ; i >= 0 ;i--){
        m_Root.RemoveChild(all_enemy[i]);
    }
    std::vector<std::shared_ptr<enemy>>().swap(all_enemy);
    generate_enemy Generate_enemy ;
    Generate_enemy.setpath("enemy" + std::to_string(map_number) + ".txt");
    Generate_enemy.generat(m_Root,all_enemy);
}