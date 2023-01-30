//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"

#include <FileBrowser.h>

using namespace uwp;

MainPage::MainPage()
{
	InitializeComponent();
    InitFileBrowser fileBrowser;

	fileBrowser.openFileBrowser();
}