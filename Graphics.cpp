//
// Graphics.cpp for plazza in /home/hero/Dropbox/plazza
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Sat Apr 20 00:03:39 2013 Marin Alcaraz
// Last update Sat Apr 20 17:30:33 2013 Marin Alcaraz
//

#include "Graphics.hh"

Graphics::Graphics(std::string n)
{
	initscr();
    cbreak();
    this->name = n;
	this->my_wins[MENU] = newwin(40, 40, 0, 0);
	this->my_wins[KITCHENS] = newwin(40, 80, 0, 42);
	this->my_wins[ORDERS] = newwin(40, 30, 0, 124);
    box(my_wins[1], 0, 0);
    box(my_wins[2], 0, 0);
	my_panels[MENU] = new_panel(my_wins[MENU]);
	my_panels[KITCHENS] = new_panel(my_wins[KITCHENS]);
	my_panels[ORDERS] = new_panel(my_wins[ORDERS]);
}

Graphics::~Graphics()
{

}

void    Graphics::update(void) const
{
    update_panels();
    doupdate();
    refresh();
}


void    Graphics::display_menu() const
{
    int             y;
    std::string     line;
    std::ifstream   menu("menu.txt");

    y = 0;
    if (menu.is_open())
    {
        while (menu.good())
        {
            getline(menu, line);
            mvwprintw(this->my_wins[0], y, 0, "%s\n", line.c_str());
            y = y + 1;
        }
        this->update();
        return ;
    }
    throw (new BadFileException("Error: Can't open file"));
}

void    Graphics::output(int WINDOW, const std::string m) const
{
    wprintw(my_wins[WINDOW], m.c_str());
}

void    Graphics::wipe(char *buf) const
{
    int     i;

    i = 0;
    while (i < 1023)
    {
        buf[i] = '\0';
        i = i + 1;
    }
}

void    Graphics::read_order() const
{
    char    order[1024];

    this->wipe(order);
    this->output(MENU, "pizza_prompt> ");
    wscanw(my_wins[MENU], "%[^\t]", order);
    std::string orderstr(order);
    std::transform(orderstr.begin(), orderstr.end(), orderstr.begin(), ::tolower);
    if (orderstr.compare("quit") == 0)
        this->exit_screen_mode();
    refresh();
    if (orderstr.empty())
        return ;
    orderstr = orderstr + ";";
    std::istringstream input(orderstr);
    Order   items(input);
    try
    {
        items.parse();
        this->output(MENU, "Thank you! Your order is being processed");
        this->update();
    }
    catch (OrderException *e)
    {
        this->output(MENU, "Error: ");
        this->output(MENU, e->what());
        this->output(MENU, "\n");
        this->update();
    }
    this->update();
}

void    Graphics::display_widgets(std::vector<Kitchen> v) const
{
    (void) v;
    return ;
}

void    Graphics::exit_screen_mode(void) const
{
    endwin();
    exit(EXIT_SUCCESS);
}
