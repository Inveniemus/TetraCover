#include <playfield_panel.h>
#include <cell.h>
#include <color_enum.h>

#include <iostream>

BEGIN_EVENT_TABLE(PlayfieldPanel, wxPanel)
    EVT_PAINT(PlayfieldPanel::on_paint_)
END_EVENT_TABLE()

 PlayfieldPanel::PlayfieldPanel(wxFrame* parent, const tetralib::Playfield& playfield)
        : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxFULL_REPAINT_ON_RESIZE),
          playfield_(playfield) {}

void
PlayfieldPanel::on_paint_(wxPaintEvent& event) {

    wxPaintDC dc(this);

    const float playfield_size_ratio = (double)playfield_.height() / playfield_.width();
    const auto panel_size = this->GetSize();
    const auto panel_width = panel_size.GetWidth();
    const auto panel_height = panel_size.GetHeight();
    const float panel_size_ratio = (double)panel_height / panel_width;

    size_t cell_side_length = 0;
    if (playfield_size_ratio > panel_size_ratio) {
        // Constraint is the height
        cell_side_length = 
            ((size_t)panel_height * 0.90) / playfield_.height();
    } else {
        // Constraint is the width
        cell_side_length = 
            ((size_t)panel_width * 0.90) / playfield_.width();
    }

    const size_t x_offset = 
        (panel_width - playfield_.width() * cell_side_length) / 2;
    const size_t y_offset = 
        (panel_height - playfield_.height() * cell_side_length) / 2;

    for (size_t y = 0; y < playfield_.height(); y++) {
        for (size_t x = 0; x < playfield_.width(); x++) {
            
            switch(playfield_.cell(x, y).color()) {
                case tetralib::BLACK:
                    dc.SetBrush(*wxGREY_BRUSH);
                    break;
                case tetralib::LIGHT_BLUE:
                    dc.SetBrush(*wxCYAN_BRUSH);
                    break;
                case tetralib::YELLOW:
                    dc.SetBrush(*wxCYAN_BRUSH);
                    break;
                case tetralib::PURPLE:
                    dc.SetBrush(*wxCYAN_BRUSH);
                    break;
                case tetralib::GREEN:
                    dc.SetBrush(*wxCYAN_BRUSH);
                    break;
                case tetralib::RED:
                    dc.SetBrush(*wxCYAN_BRUSH);
                    break;
                case tetralib::BLUE:
                    dc.SetBrush(*wxCYAN_BRUSH);
                    break;
                case tetralib::ORANGE:
                    dc.SetBrush(*wxCYAN_BRUSH);
                    break;                                                                                                    
            }

            dc.DrawRectangle(
                x_offset + x * cell_side_length,
                panel_height - y_offset - (y + 1) * cell_side_length,
                cell_side_length,
                cell_side_length
            );
        }
    }
}
