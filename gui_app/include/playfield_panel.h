#ifndef PLAYFIELD_PANEL_H
#define PLAYFIELD_PANEL_H

#include <engine.h>
#include <observer.h>
#include <engine_snapshot.h>

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
    #include<wx/dcbuffer.h>
#endif

class PlayfieldPanel : public wxPanel, public tetralib::Observer {
public:
    PlayfieldPanel(wxFrame*, tetralib::Engine&);

    /// tetralib::Observer implementation
    void update(const tetralib::EngineSnapshot&);

private:
    tetralib::Engine& engine_;

    void on_paint_(wxPaintEvent&);
    void on_key_down_(wxKeyEvent&);
    void on_key_up_(wxKeyEvent&);

    DECLARE_EVENT_TABLE()
};

#endif // PLAYFIELD_PANEL_H