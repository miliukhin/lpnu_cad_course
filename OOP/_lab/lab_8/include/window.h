#include "gtkmm/entry.h"
#include "gtkmm/label.h"
#include <gtkmm.h>
#include <iostream>

class MainWindow : public Gtk::Window
{
public:

	static const int yes_response = -8;
	static const int no_response = -9;
	static const int ok_response = -5;

	MainWindow();
	void menu_init();
	void on_button_calculate_clicked();
	void on_menu_item_selected(int layoutType);
	bool parse_numbers(std::vector<double> &arr);
	void clear_labels();
	void clear_entries();
	void clear_all();
	void message(std::string title, std::string desc);

protected:
	Gtk::Box m_vbox;
	Gtk::Label label_1;	Gtk::Box m_vbox_e1;
	Gtk::Label label_2;	Gtk::Box m_vbox_e2;
	Gtk::Label label_3;	Gtk::Box m_vbox_e3;
	Gtk::Box m_hbox;
	Gtk::Box m_hbox_2;
	Gtk::Button m_button;
	Gtk::MenuBar m_menu;
	Gtk::MenuItem m_menuItem1;
	Gtk::Menu m_submenu1;
	Gtk::Entry *entry_1 = Gtk::manage(new Gtk::Entry());
	Gtk::Entry *entry_2 = Gtk::manage(new Gtk::Entry());
	Gtk::Entry *entry_3 = Gtk::manage(new Gtk::Entry());
	Gtk::TextView result_textview;
	Gtk::TextView result_opt_textview;
private:
	int formula = 0;
};

