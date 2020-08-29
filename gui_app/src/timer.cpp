#include <timer.h>

Timer::Timer(tetralib::Engine& engine, std::shared_ptr<PlayfieldPanel> ptr) : 
        engine_(engine), playfield_panel_ptr(ptr) {
    engine_.add_observer(this);
}

void Timer::Notify() {
    std::cout << "Timer notifies" << std::endl;
    engine_.step();
}

void Timer::start(size_t ms) {
    std::cout << "Timer: " << ms << " ms" << std::endl;
    wxTimer::Start(ms);
}

void Timer::update(const tetralib::EngineSnapshot& snapshot) {
    if (snapshot.timer_interval != 0) {
        start(snapshot.timer_interval);
    }
}