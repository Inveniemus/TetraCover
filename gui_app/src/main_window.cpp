#include <main_window.h>

MainWindow::MainWindow()
    : wxFrame(NULL, wxID_ANY, WINDOW_TITLE, DEFAULT_POSITION, DEFAULT_SIZE)
{
    
    build_menus_();

    CreateStatusBar();
    SetStatusText("Welcome to TetraCover!");
    
    Bind(wxEVT_MENU, &MainWindow::on_about_, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainWindow::on_exit_, this, wxID_EXIT);
    Bind(wxEVT_MENU, &MainWindow::on_new_game_, this, ID_MENU_NEW_GAME);
    Bind(wxEVT_MENU, &MainWindow::on_debug_, this, ID_MENU_DEBUG);

    this->Connect(wxEVT_PAINT, wxPaintEventHandler(MainWindow::on_paint_));
}

void MainWindow::build_menus_() {
    menu_file_ptr_ = std::unique_ptr<wxMenu>{new wxMenu()};
    menu_file_ptr_->Append(
        ID_MENU_NEW_GAME, "New Game", "Start a new game!"
    );
    menu_file_ptr_->Append(wxID_EXIT);
    
    menu_help_ptr_ = std::unique_ptr<wxMenu>{new wxMenu()};
    menu_help_ptr_->Append(wxID_ABOUT);

    menu_debug_ptr_ = std::unique_ptr<wxMenu>{new wxMenu()};
    menu_debug_ptr_->Append(
        ID_MENU_DEBUG, "TEST 1");

    menubar_ptr_ = std::unique_ptr<wxMenuBar>{new wxMenuBar()};
    menubar_ptr_->Append(menu_file_ptr_.get(), "&File");
    menubar_ptr_->Append(menu_debug_ptr_.get(), "&Debug");
    menubar_ptr_->Append(menu_help_ptr_.get(), "&Help");

    SetMenuBar(menubar_ptr_.get());
}

void MainWindow::on_exit_(wxCommandEvent& event)
{
    Close(true);
}
void MainWindow::on_about_(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}

void MainWindow::on_new_game_(wxCommandEvent& event) {

}

void MainWindow::on_paint_(wxPaintEvent& event) {
    wxPaintDC dc(this);
    dc.SetPen(*wxBLACK_DASHED_PEN);
    dc.SetBrush(*wxBLACK_BRUSH);

    wxCoord x_origin = 100, y_origin = 100;
    wxCoord width = 200, height = 400;
    dc.DrawRectangle(x_origin, y_origin, width, height);
}

void MainWindow::on_debug_(wxCommandEvent &event) {
    
}