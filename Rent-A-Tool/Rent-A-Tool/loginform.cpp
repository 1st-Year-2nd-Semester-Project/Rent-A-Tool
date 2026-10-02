#include "loginform.h"
#include "dashboard1.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	RentATool:: loginform  form;
	Application::Run(% form);
}