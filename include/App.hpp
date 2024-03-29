#ifndef APP_HPP
#define APP_HPP
#include "map.hpp"
#include "hero.hpp"
#include "heroattack.hpp"
#include "pch.hpp" // IWYU pragma: export
#include "Util/Root.hpp"
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
    State m_CurrentState = State::START;
    Util::Root m_Root;
    physics phy ;
    std::shared_ptr<heroattack> m_tool ;
    std::shared_ptr<hero>  m_hero ;
    std::shared_ptr<map> m_map;
};

#endif