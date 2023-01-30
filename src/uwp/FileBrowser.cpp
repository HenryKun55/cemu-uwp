#include <future>

#include "pch.h"
#include "FileBrowser.h"

#include <winrt/Windows.ApplicationModel.Activation.h>
#include <winrt/Windows.ApplicationModel.Core.h>
    
#include <winrt/Windows.System.h>   
#include <winrt/Windows.Storage.h>
#include <winrt/Windows.Storage.Pickers.h>

using namespace uwp;

using namespace winrt::Windows::System;
using namespace winrt::Windows::Storage;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Storage::Pickers;

using winrt::Windows::UI::Core::CoreWindow;

winrt::fire_and_forget InitFileBrowser::openFileBrowser()
{
    FileOpenPicker openPicker;
    openPicker.ViewMode(PickerViewMode::List);
    openPicker.SuggestedStartLocation(PickerLocationId::HomeGroup);
    openPicker.FileTypeFilter().Append(L".rpx");

    auto file = co_await openPicker.PickSingleFileAsync();
}