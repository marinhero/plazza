//
// Graphics.cpp for plazza in /home/hero/Dropbox/plazza
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Sat Apr 20 00:03:39 2013 Marin Alcaraz
// Last update Sat Apr 20 11:25:57 2013 Marin Alcaraz
//

#include "Graphics.hh"

Graphics::Graphics(std::string n)
{
    this->name = n;
}

Graphics::~Graphics()
{

}

void    Graphics::init_screen_mode() const
{
   initscr();
}

void    Graphics::update(void) const
{
    refresh();
}


void    Graphics::display_menu() const
{
    std::string     line;
    std::ifstream   menu("menu.txt");

    if (menu.is_open())
    {
        while (menu.good())
        {
            getline(menu, line);
            printw(line.c_str());
            printw("\n");
        }
        this->update();
        return ;
    }
    throw (new BadFileException("Error: Can't open file"));
}

void    Graphics::output(const std::string m) const
{
    printw(m.c_str());
}

void    Graphics::read_order() const
{
    char    order[1024];

    printw("pizza_prompt> ");
    scanw("%[^\t]", order);
    std::string orderstr(order);
    if (orderstr.compare("quit") == 0)
        this->exit_screen_mode();
    orderstr = orderstr + ";";
    std::istringstream input(orderstr);
    Order   items(input);
    try
    {
        items.parse();
        this->output("Thank you! Your order is being processed\n");
        this->update();
    }
    catch (OrderException *e)
    {
        this->output("Error: ");
        this->output(e->what());
        this->output("\n");
        this->update();
    }
    this->update();
    getch();
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
