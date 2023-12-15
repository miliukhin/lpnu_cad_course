#include "../include/window.h"
#include "gtkmm/box.h"
#include "gtkmm/enums.h"
#include "sigc++/functors/mem_fun.h"
#include "../include/my_math.h"
#include <vector>
#include <iomanip>

#define TESTING

void MainWindow::clear_labels()
{
	label_1.set_text("-");
	label_2.set_text("-");
	label_3.set_text("-");
}

void MainWindow::clear_entries()
{
	entry_1->set_text("");
	entry_2->set_text("");
	entry_3->set_text("");
}
void MainWindow::clear_all()
{
	clear_labels();
	clear_entries();
	result_opt_textview.hide();
}

void MainWindow::on_menu_item_selected(int layoutType)
{
    switch (layoutType)
    {
        case 1:
		formula = 1;
		entry_1->set_editable(true);
		entry_2->set_editable(true);
		entry_3->set_editable(true);
		label_1.set_text("Small Base Radius");
		label_2.set_text("Large Base Radius");
		label_3.set_text("Generatrix");
		m_menuItem1.set_label("Cone Frustum Area");
		break;
        case 2:
		formula = 2;
		entry_1->set_editable(true);
		entry_2->set_editable(false);
		entry_3->set_editable(false);

		clear_all();
		label_1.set_text("Temperature (•C)");
		m_menuItem1.set_label("Celsius to Fahrenheit");
		break;
        case 3:
		formula = 3;
		entry_1->set_editable(true);
		entry_2->set_editable(true);
		entry_3->set_editable(false);

		clear_all();
		label_1.set_text("Tangent value");
		label_2.set_text("Iterations");
		m_menuItem1.set_label("Arctangent");

		m_hbox_2.pack_end(result_opt_textview, true, true, 4);
		show_all_children();
		break;
        case 4:
		formula = 4;
		entry_2->set_editable(false);
		entry_3->set_editable(false);

		clear_all();
		label_1.set_text("Radius");
		m_menuItem1.set_label("Sphere Area");
		break;
        case 5:
		formula = 5;
		entry_2->set_editable(false);
		entry_3->set_editable(false);

		clear_all();
		label_1.set_text("Radius");
		m_menuItem1.set_label("Sphere Volume");
		break;
    }
}

MainWindow::MainWindow()
	: m_vbox(Gtk::ORIENTATION_VERTICAL),
	m_vbox_e1(Gtk::ORIENTATION_VERTICAL),
	m_vbox_e2(Gtk::ORIENTATION_VERTICAL),
	m_vbox_e3(Gtk::ORIENTATION_VERTICAL),
	m_button("Calculate"),
	m_menuItem1("Select Mode"),
	label_1("-"),
	label_2("-"),
	label_3("-")
{
	set_title("MiniCalc GUI");
	set_default_size(300, 300);
	set_position(Gtk::WIN_POS_CENTER);
	gtk_entry_new();

	menu_init();

	m_button.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_button_calculate_clicked));

	entry_1->set_editable(false);
	entry_2->set_editable(false);
	entry_3->set_editable(false);

// populate boxes
	m_vbox_e1.pack_start(label_1, Gtk::PACK_SHRINK, 0);
	m_vbox_e1.pack_start(*entry_1, Gtk::PACK_SHRINK, 0);
	m_vbox_e2.pack_start(label_2, Gtk::PACK_SHRINK, 0);
	m_vbox_e2.pack_start(*entry_2, Gtk::PACK_SHRINK, 0);
	m_vbox_e3.pack_start(label_3, Gtk::PACK_SHRINK, 0);
	m_vbox_e3.pack_start(*entry_3, Gtk::PACK_SHRINK, 0);

/* result box */
	result_textview.set_editable(false);
  	auto result_buffer = result_textview.get_buffer();
  	result_buffer->set_text("Result");

	result_opt_textview.set_editable(false);
  	result_opt_textview.get_buffer()->set_text("libm function");

/* Add all elements to the horizontal box */
	m_hbox.pack_start(m_vbox_e1, true, true, 4);
	m_hbox.pack_start(m_vbox_e2, true, true, 4);
	m_hbox.pack_start(m_vbox_e3, true, true, 4);

	m_hbox_2.pack_end(result_textview, true, true, 4);
	m_hbox_2.pack_start(m_button, false, false, 4);

/* Add the menu and horizontal boxes to the verticial box */
	m_vbox.pack_start(m_menu, false, false, 0);
	m_vbox.pack_start(m_hbox, false, false, 4);
	m_vbox.pack_start(m_hbox_2, false, false, 4);

	add(m_vbox);
	show_all_children();
}

void MainWindow::on_button_calculate_clicked()
{
#ifdef TESTING
	std::cout << "click" << std::endl;
#endif
	double result, result_opt;
	std::vector<double> arr;
	std::ostringstream oss_2;
	if(parse_numbers(arr))
	{
		try{
		switch (formula)
		{
			case 0:
				break;
			case 1:
				result = cone_frustum_area(arr[0], arr[1], arr[2]);
				break;
			case 2:
				result = celsius_to_fahrenheit(arr[0]);
				break;
			case 3:
				result = arctg_taylor(arr[0], (int)arr[1]);
				result_opt = atan(arr[0]);
				oss_2 << std::fixed << std::setprecision(7) << result_opt;
				result_opt_textview.get_buffer()->set_text(oss_2.str());
				break;
			case 4:
				result = sphere_area(arr[0]);
				break;
			case 5:
				result = sphere_volume(arr[0]);
				break;
    		}
		std::ostringstream oss;
		oss << std::fixed << std::setprecision(7) << result; // конвертація з точністю 2
		std::string text = oss.str(); // отримання стрічки
		result_textview.get_buffer()->set_text(text);
		}
		catch (std::exception &e)
		{
			message("Error", e.what());
		}
		std::cout << result << std::endl;
		std::cout << result_opt << std::endl;

	}
	else
	{
		result_textview.get_buffer()->set_text("Result");
		result_opt_textview.get_buffer()->set_text("libm function");
	}
};


bool MainWindow::parse_numbers(std::vector<double> &arr)
{
	try
	{
		std::string previousLocale = std::setlocale(LC_NUMERIC, "C");
		if(entry_1->get_editable())
		{
			double num_1 = std::stod(entry_1->get_text());
			arr.push_back(num_1);
			if(entry_2->get_editable())
			{
				double num_2 = std::stod(entry_2->get_text());
				arr.push_back(num_2);
				if(entry_3->get_editable())
				{
					double num_3 = std::stod(entry_3->get_text());
					arr.push_back(num_3);
				}
			}
		}
		else
			return false;
		std::setlocale(LC_NUMERIC, previousLocale.c_str());
#ifdef TESTING
		std::cout << "values:\n";
		std::cout << '\t' << arr[0] << '\n';
		std::cout << '\t' << arr[1] << '\n';
		std::cout << '\t' << arr[2] << '\n';
		std::cout << "\n";
#endif
		return true;
	}
	catch (std::exception& err)
	{
#ifdef TESTING
		std::cout << err.what() << std::endl;
#endif
		message("Only numbers!!!", "Please don't input non-numeric data");
		return false;
	}
}

void MainWindow::menu_init()
{
	auto menuItem1 = Gtk::manage(new Gtk::MenuItem("Cone Frustum Area"));
	auto menuItem2 = Gtk::manage(new Gtk::MenuItem("Celsius to Fahrenheit"));
	auto menuItem3 = Gtk::manage(new Gtk::MenuItem("Arctangent"));
	auto menuItem4 = Gtk::manage(new Gtk::MenuItem("Sphere Area"));
	auto menuItem5 = Gtk::manage(new Gtk::MenuItem("Sphere Volume"));

	m_submenu1.append(*menuItem1);
	m_submenu1.append(*menuItem2);
	m_submenu1.append(*menuItem3);
	m_submenu1.append(*menuItem4);
	m_submenu1.append(*menuItem5);

    	menuItem1->signal_activate().connect([=]() { on_menu_item_selected(1); });
    	menuItem2->signal_activate().connect([=]() { on_menu_item_selected(2); });
    	menuItem3->signal_activate().connect([=]() { on_menu_item_selected(3); });
    	menuItem4->signal_activate().connect([=]() { on_menu_item_selected(4); });
    	menuItem5->signal_activate().connect([=]() { on_menu_item_selected(5); });

	m_menuItem1.set_submenu(m_submenu1);
	m_menu.append(m_menuItem1);
}

void MainWindow::message(std::string title, std::string desc)
{
         	Gtk::MessageDialog message
		(desc,
			false,
			Gtk::MESSAGE_ERROR,
			Gtk::BUTTONS_OK,
			true
		);
            	message.set_title(title);
            	int result = message.run();
        	switch(result)
		{
            		case(ok_response):
				message.hide();
				break;
            	}
}
