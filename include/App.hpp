#ifndef APP_HPP
#define APP_HPP
#include "map.hpp"
#include "hero.hpp"
#include "enemy.hpp"
#include "heroattack.hpp"
#include "Slime.hpp"
#include "generate_enemy.hpp"
#include "pch.hpp" // IWYU pragma: export
#include "Util/Root.hpp"
#include "Util/BGM.hpp"
#include "Prop.hpp"
class App {
public:
    enum class State {
        START,
        TRANS,
        UPDATE,
        END,
    };

    State GetCurrentState() const { return m_CurrentState; }

    void Start();
    void Update();
    void End(); // NOLINT(readability-convert-member-functions-to-static)
    void Trans() ;
private:
    void ValidTask();

private:
    generate_enemy generate_enemy ;
    std::vector<std::shared_ptr<enemy>> all_enemy;//多形
    State m_CurrentState = State::START;
    Util::Root m_Root;
    std::shared_ptr<Util::BGM> m_bgm;
    physics phy ;
    std::shared_ptr<heroattack> m_tool ;
    std::shared_ptr<hero>  m_hero ;
    std::shared_ptr<map> m_map;
    std::shared_ptr<Slime> slime;
    std::vector<std::shared_ptr<Prop>> prop ;
};

#endif