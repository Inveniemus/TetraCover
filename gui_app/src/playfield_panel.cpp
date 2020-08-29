#include <playfield_panel.h>
#include <cell.h>
#include <color_enum.h>

#include <iostream>

BEGIN_EVENT_TABLE(PlayfieldPanel, wxPanel)
    EVT_PAINT(PlayfieldPanel::on_paint_)
    EVT_KEY_DOWN(PlayfieldPanel::on_key_down_)
    EVT_KEY_UP(PlayfieldPanel::on_key_up_)
END_EVENT_TABLE()

 PlayfieldPanel::PlayfieldPanel(
        wxFrame* parent, 
        tetralib::Engine& engine) :
    wxPanel(
        parent,
        wxID_ANY,
        wxDefaultPosition,
        wxDefaultSize,
        wxFULL_REPAINT_ON_RESIZE
    ),
    engine_(engine) {

    engine.add_observer(this);
    SetBackgroundStyle(wxBG_STYLE_PAINT);
}

void PlayfieldPanel::update(const tetralib::EngineSnapshot& engine_snapshot) {
    if (engine_snapshot.playfield_changed) Refresh();
}


// PRIVATE _____________________________________________________________________
void
PlayfieldPanel::on_paint_(wxPaintEvent&) {

    wxBufferedPaintDC dc(this);
    auto playfield = engine_.get_playfield();

    const float playfield_size_ratio = (double)playfield.height() / playfield.width();
    const auto panel_size = this->GetSize();
    const auto panel_width = panel_size.GetWidth();
    const auto panel_height = panel_size.GetHeight();
    const float panel_size_ratio = (double)panel_height / panel_width;

    size_t cell_side_length = 0;
    if (playfield_size_ratio > panel_size_ratio) {
        // Constraint is the height
        cell_side_length = 
            ((size_t)panel_height * 0.90) / playfield.height();
    } else {
        // Constraint is the width
        cell_side_length = 
            ((size_t)panel_width * 0.90) / playfield.width();
    }

    const size_t x_offset = 
        (panel_width - playfield.width() * cell_side_length) / 2;
    const size_t y_offset = 
        (panel_height - playfield.height() * cell_side_length) / 2;

    for (size_t y = 0; y < playfield.height(); y++) {
        for (size_t x = 0; x < playfield.width(); x++) {
            
            switch(playfield.cell(x, y).color()) {
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

void
PlayfieldPanel::on_key_down_(wxKeyEvent& event) {
    
    auto key_code = event.GetKeyCode();
    switch(key_code) {
        case 314: // LEFT ARROW
            engine_.tetro_left();
            break;
        case 315: // UP ARROW
        break;
        case 316: // RIGHT ARROW
            engine_.tetro_right();
            break;
        case 317: // DOWN ARROW
            engine_.tetro_down();
            break;
    }
    event.Skip();
}

void PlayfieldPanel::on_key_up_(wxKeyEvent& event) {
    event.Skip();
}