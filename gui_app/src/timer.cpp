#include <timer.h>

void Timer::Notify() {
    engine_.step();
    playfield_panel_ptr->timer_elapsed();
}

void Timer::start(size_t ms) {
    wxTimer::Start(ms);
}

void Timer::update(const tetralib::EngineSnapshot& snapshot) {
    start(snapshot.timer_interval);
}