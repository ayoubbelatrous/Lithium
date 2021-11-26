#include "isotope.h"

int main(void)
{
	isotope iso;
	Application app;
	app.Init();
	iso.SetWindow(app.GetWindow());
	
	iso.Init();

	while (!app.shouldClose())
	{

		iso.Render();
		iso.UIrender();
		app.Render();
	}
	
	app.Delete();
	iso.Delete();
	std::cout << " running" << std::endl;
	return 0;
	exit(0);
}
