#include "loginform.h"
#include "dashboard.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	RentATool:: dashboard  form;
	Application::Run(% form);
}