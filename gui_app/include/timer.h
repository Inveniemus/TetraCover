#include <playfield_panel.h>

#include <engine.h>
#include <observer.h>

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <memory>

class Timer : public wxTimer, public tetralib::Observer {
public:
    ///@brief Construct a new Timer object
    ///@param ptr a shared_ptr to the wxPanel that need to be refreshed.
    Timer(tetralib::Engine& engine, std::shared_ptr<PlayfieldPanel> ptr) : 
        engine_(engine), playfield_panel_ptr(ptr) {}
    
    ///@brief Notifies the engine and the playfield panel that time has elapsed
    void Notify();

    ///@brief (Re)start the timer with the passed interval in milliseconds
    void start(size_t);

    // Observer implementation
    void update(const tetralib::EngineSnapshot&);

private:
    tetralib::Engine& engine_;
    std::shared_ptr<PlayfieldPanel> playfield_panel_ptr;
};
