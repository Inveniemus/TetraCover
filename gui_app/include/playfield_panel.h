#ifndef PLAYFIELD_PANEL_H
#define PLAYFIELD_PANEL_H

#include <engine.h>
#include <observer.h>

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
    #include<wx/dcbuffer.h>
#endif

class PlayfieldPanel : public wxPanel {
public:
    PlayfieldPanel(wxFrame*, tetralib::Engine&);

    ///@brief Called when timer is elapsed, requesting redrawing.
    void timer_elapsed() { this->Refresh(); }

private:
    tetralib::Engine& engine_;

    void on_paint_(wxPaintEvent&);
    void on_key_down_(wxKeyEvent&);
    void on_key_up_(wxEvent&);

    DECLARE_EVENT_TABLE()
};

#endif // PLAYFIELD_PANEL_H