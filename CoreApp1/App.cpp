#include "pch.h">

using namespace winrt;

using namespace Windows;
using namespace Windows::Foundation;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::UI;
using namespace Windows::UI::Core;
using namespace Windows::UI::Composition;

using namespace winrt::Windows::Storage::Pickers;

struct App : implements<App, IFrameworkViewSource, IFrameworkView>
{
    IFrameworkView CreateView()
    {
        return *this;
    }

    void Initialize(CoreApplicationView const& v)
    {
        v.Activated({ this, &App::OnActivate });
        CoreApplication::EnteredBackground({ this, &App::EnteredBackground });
        CoreApplication::Suspending({ this, &App::Suspending });
    }

    void Load(hstring const&)
    {
    }

    void Uninitialize()
    {
    }

    void Run()
    {
        CoreWindow window = CoreWindow::GetForCurrentThread();
        window.Activate();

        CoreDispatcher dispatcher = window.Dispatcher();
        dispatcher.ProcessEvents(CoreProcessEventsOption::ProcessUntilQuit);
    }

    void SetWindow(CoreWindow const& w) { w.Closed({ this, &App::OnClosed }); }

    winrt::fire_and_forget InitializeCemuFromFile(std::string path)
    {
        if (path.empty())
        {
            FileOpenPicker openPicker;
            openPicker.ViewMode(PickerViewMode::List);
            openPicker.SuggestedStartLocation(PickerLocationId::HomeGroup);
            openPicker.FileTypeFilter().Append(L".rpx");
            openPicker.FileTypeFilter().Append(L".wux");

            auto file = co_await openPicker.PickSingleFileAsync();
            winrt::hstring Title = L"Agora estudar pra funcionar o core do Cemu!";
            winrt::Windows::UI::Popups::MessageDialog dialog(file.Path().data(), Title);
            dialog.ShowAsync();
           
            /*MainWindow mainWindow;
               mainWindow.FileLoad(file.Path().data(), wxLaunchGameEvent::INITIATED_BY::GAME_LIST);*/
        }
    }

    void OnActivate(const winrt::Windows::ApplicationModel::Core::CoreApplicationView&,
        const winrt::Windows::ApplicationModel::Activation::IActivatedEventArgs& args)
    {
        std::stringstream filePath;

        // Defaults to file picker if no path is present.
        InitializeCemuFromFile(filePath.str());
    }

    void EnteredBackground(const IInspectable&,
        const winrt::Windows::ApplicationModel::EnteredBackgroundEventArgs& args)
    {
    }

    void OnClosed(const IInspectable&, const winrt::Windows::UI::Core::CoreWindowEventArgs& args)
    {
        exit(0);
    }

    void Suspending(const IInspectable&,
        const winrt::Windows::ApplicationModel::SuspendingEventArgs& args)
    {
        // The Series S/X quits fast, so let's immediately shutdown to ensure all the caches save.

    }
};

int __stdcall wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
{
    CoreApplication::Run(make<App>());
}
