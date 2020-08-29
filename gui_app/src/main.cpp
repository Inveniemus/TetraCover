#include <main_window.h>
#include <engine.h>

// wxWidgets library
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include <memory>

class TestApp : public wxApp
{
public:
    virtual bool OnInit();
private:
    std::unique_ptr<MainWindow> window_;
    tetralib::Engine engine_;
};

wxIMPLEMENT_APP(TestApp);

bool TestApp::OnInit()
{
    window_ = std::unique_ptr<MainWindow>{new MainWindow(engine_)};
    window_->Show(true);

    engine_.step();


    return true;
}
