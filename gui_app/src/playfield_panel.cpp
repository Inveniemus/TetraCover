#include <playfield_panel.h>
#include <iostream>

BEGIN_EVENT_TABLE(PlayfieldPanel, wxPanel)
    EVT_PAINT(PlayfieldPanel::on_paint_)
END_EVENT_TABLE()

 PlayfieldPanel::PlayfieldPanel(wxFrame* parent, const tetralib::Playfield& playfield)
        : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE),
          playfield_(playfield) {}

void
PlayfieldPanel::on_paint_(wxPaintEvent& event) {

    std::cout << "TEST" << std::endl;

    wxPaintDC dc(this);
    dc.SetPen(*wxBLACK_DASHED_PEN);
    dc.SetBrush(*wxBLACK_BRUSH);

    wxCoord x_origin = 100, y_origin = 100;
    wxCoord width = 200, height = 400;
    dc.DrawRectangle(x_origin, y_origin, width, height);
}
