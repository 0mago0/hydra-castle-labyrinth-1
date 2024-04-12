#include "App.hpp"
#include "map.hpp"
#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
void App::Start() {
    LOG_TRACE("Start");
    m_hero = std::make_shared<hero>(std::vector<std::string>{RESOURCE_DIR"/hero/stay.png",RESOURCE_DIR"/hero/Rrun.png",RESOURCE_DIR"/hero/Rrun.png"});
    m_hero->SetPosition({0,-30});
    m_hero->hero_state = "on_ground" ;
    m_Root.AddChild(m_hero);
    phy.set_data("map1.txt");
    m_hero->map = "map1.txt" ;
    m_map = std::make_shared<map>("p1.png","map1.txt");
    m_map->map_number = 1 ;
    m_Root.AddChild(m_map);
    m_CurrentState = State::UPDATE;
    m_tool = std::make_shared<heroattack>(std::vector<std::string>{RESOURCE_DIR"/attack_tool/sword1.png",RESOURCE_DIR"/attack_tool/sword2.png",RESOURCE_DIR"/attack_tool/sword3.png",RESOURCE_DIR"/attack_tool/sword4.png",RESOURCE_DIR"/attack_tool/sword5.png"});
    m_Root.AddChild(m_tool) ;
    slime = std::make_shared<Slime>() ;
    auto temp = std::dynamic_pointer_cast<Util::GameObject>(slime) ;
    m_Root.AddChild(temp) ;

}

void App::Update() {
    m_hero->run() ;
    phy.object_position.push_back(m_hero->GetPosition()) ;
    phy.jump_total.push_back(0);
    phy.state.push_back(m_hero->hero_state) ;
    phy.in_sky_down();
    m_hero->hero_state = phy.get_state();
    phy.state.clear() ;
    m_hero->SetPosition(phy.object_position[0]);
    m_map->hero_position = m_hero->GetPosition() ;
    m_map->Transitions() ;
    m_hero->SetPosition(m_map->hero_position) ;
    phy.set_data("map" + std::to_string(m_map->map_number) + ".txt");
    m_hero->map = "map" + std::to_string(m_map->map_number) + ".txt" ;
    m_tool->SetPosition(m_hero->GetPosition()) ;
    m_tool->renw_position(m_hero->forward) ;
    m_tool->attack(m_hero->forward) ;
    m_Root.Update() ;


    //m_map.SetImage("p1.png") ;
    //TODO: do your things here and delete this line <3

    /*
     * Do not touch the code below as they serve the purpose for
     * closing the window.
     */
    /*
    Util::Image map(RESOURCE_DIR"/background/p1.png");
    map.Draw({{0,0},0,{2,2}},-10) ;
     */
}
void App::Trans(){
    m_CurrentState = State::UPDATE ;
    m_Root.Update() ;
};
void App::End() { // NOLINT(this method will mutate members in the future)
    LOG_TRACE("End");
}