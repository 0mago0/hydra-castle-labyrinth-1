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
    m_map = std::make_shared<map>("p1.png","map1.txt");
    m_Root.AddChild(m_map);
    m_CurrentState = State::UPDATE;
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

void App::End() { // NOLINT(this method will mutate members in the future)
    LOG_TRACE("End");
}
