#ifndef ENGINE_SNAPSHOT_H
#define ENGINE_SNAPSHOT_H

#include <cstddef>

namespace tetralib {

///@brief Simple struct to pass Engine state to its observers
struct EngineSnapshot {
    /// New timer interval. If no change, stays equal to zero.
    /// To use it, first make a test in the implemented update() function,
    /// then change the timer value only if it is not zero.
    size_t timer_interval = 0;

    /// Boolean to update observers if the playfield state has changed.
    bool playfield_changed = false;
};

} // namespace tetralib

#endif // ENGINE_SNAPSHOT_H