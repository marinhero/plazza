//
// Graphics.cpp for plazza in /home/ignatiev/Projects/plazza
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Sun Apr 21 01:33:26 2013 Marin Alcaraz
// Last update Mon Apr 22 11:49:46 2013 ivan ignatiev
//

#include "Graphics.hh"

Graphics::Graphics(std::string n)
{
	initscr();
    cbreak();
    this->name = n;
    this->init_wins();
    this->init_panels();
    this->init_scroll();
    this->output(KITCHENS, "\t\t\tKITCHEN STATUS\n\n\n");
    this->output(ORDERS, "\tORDER STATUS\n\n\n");
}

Graphics::~Graphics()
{

}

void    Graphics::init_wins()
{
	this->my_wins[MENU] = newwin(55, 40, 0, 0);
	this->my_wins[KITCHENS] = newwin(55, 80, 0, 42);
	this->my_wins[ORDERS] = newwin(55, 30, 0, 124);
}

void    Graphics::init_panels()
{
	my_panels[MENU] = new_panel(my_wins[MENU]);
	my_panels[KITCHENS] = new_panel(my_wins[KITCHENS]);
	my_panels[ORDERS] = new_panel(my_wins[ORDERS]);
}

void    Graphics::init_scroll()
{
    scrollok(my_wins[MENU], true);
    scrollok(my_wins[KITCHENS], true);
    scrollok(my_wins[ORDERS], true);
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

std::string  const   &Graphics::read_order()
{
    char    order[1024];
    char    fmt[100] = "%[^\t]";

    this->wipe(order);
    this->output(MENU, "pizza_prompt> ");
    wscanw(my_wins[MENU], fmt, order);
    this->orderstr = order;
    (orderstr.empty()) ? (orderstr = "empty") : orderstr = orderstr + ";";
    return (this->orderstr);
}

void    Graphics::display_kitchens(std::vector<Kitchen*> v) const
{
   int  i;
   std::vector<Kitchen*>::iterator   it;

   i = 0;
   it = v.begin();
   while (it != v.end())
   {
       this->output(KITCHENS, (*it)->getReport());
       i = i + 1;
       it++;
    }
}

void    Graphics::display_orders() const
{
    this->output(ORDERS, "Order registered\n");
}

void    Graphics::clear(int w)
{
    wclear(my_wins[w]);
}

void    Graphics::exit_screen_mode(void) const
{
    endwin();
}
