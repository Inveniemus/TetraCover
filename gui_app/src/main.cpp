#include <main_window.h>

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
};

wxIMPLEMENT_APP(TestApp);

bool TestApp::OnInit()
{
    window_ = std::unique_ptr<MainWindow>{new MainWindow()};
    window_->Show(true);

    return true;
}
