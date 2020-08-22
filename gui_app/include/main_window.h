#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <memory>
#include <string>

constexpr size_t DEFAULT_WIDTH = 800;
constexpr size_t DEFAULT_HEIGHT = 600;
const std::string WINDOW_TITLE{"Tetra Cover"};

const auto DEFAULT_SIZE = wxSize{DEFAULT_WIDTH, DEFAULT_HEIGHT};
const auto DEFAULT_POSITION = wxPoint{100, 100};

///@brief Main Window of the application, includes menus stuff and a panel
/// to draw the game.
class MainWindow : public wxFrame
{
public:
    MainWindow();

    // Event IDs
    enum IDs {
        ID_MENU_NEW_GAME,
        ID_MENU_DEBUG,
    };

private:
    // Menu bar
    std::unique_ptr<wxMenuBar> menubar_ptr_;
    std::unique_ptr<wxMenu> menu_file_ptr_;
    std::unique_ptr<wxMenu> menu_help_ptr_;
    std::unique_ptr<wxMenu> menu_debug_ptr_;

    ///@brief Build menu objects and update related pointers of the main window
    /// It is called by the constructor of MainWindow.
    void build_menus_(); 

    // Panel of the playfield
    std::unique_ptr<wxPanel> playfield_panel_;

    // Event handlers
    // Menus
    void on_exit_(wxCommandEvent& event);
    void on_about_(wxCommandEvent& event);
    void on_new_game_(wxCommandEvent& event);
    void on_debug_(wxCommandEvent& event);
    // Painting
    void on_paint_(wxPaintEvent& event);
};