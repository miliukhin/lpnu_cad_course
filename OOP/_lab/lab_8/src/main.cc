#define TESTING

#include<iostream>
#include<math.h>
#include"../include/my_math.h"

#include <gtkmm/application.h>
#include "../include/window.h"

int main(int argc, char* argv[])
{
	using namespace std;

#ifdef TESTING
	cout << cone_frustum_area(1,1,2) << endl;
	cout << celsius_to_fahrenheit(37) << endl;
	cout << arctg_taylor(0.5, 15) << endl;
	cout << atan(0.5) << endl;
	cout << sphere_volume(1) << endl;
	cout << sphere_area(1) << endl;
	cout << endl;
#endif

	auto app = Gtk::Application::create();

	MainWindow window;
	return app->run(window);
}
