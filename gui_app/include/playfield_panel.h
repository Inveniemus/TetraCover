#ifndef PLAYFIELD_PANEL_H
#define PLAYFIELD_PANEL_H

#include <playfield.h>

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class PlayfieldPanel : public wxPanel {
public:
    PlayfieldPanel(wxFrame*, const tetralib::Playfield&);

    ///@brief Called when timer is elapsed, requesting redrawing.
    void timer_elapsed() { this->Refresh(); }

private:
    const tetralib::Playfield& playfield_;

    void on_paint_(wxPaintEvent& event);

    DECLARE_EVENT_TABLE()
};

#endif // PLAYFIELD_PANEL_H