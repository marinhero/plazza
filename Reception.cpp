//
// Reception.cpp for plazza in /home/ignatiev/Projects/plazza
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Wed Apr 17 15:28:37 2013 Marin Alcaraz
// Last update Sun Apr 21 23:39:20 2013 ivan ignatiev
//

#include "Reception.hh"


Reception::Reception(int m, int c, int r) : multiplier(m),
cooks(c), refresh(r), inspecthread_(* new Thread(* this)), win(* new Graphics("plazza"))
{
}

Reception::~Reception()
{
    win.exit_screen_mode();
    delete &this->inspecthread_;
    delete &win;
}

void    *Reception::run()
{
   int  i;
   std::vector<Kitchen*>::iterator   it;

   i = 0;
   it = this->kitchens.begin();
   while (it != this->kitchens.end())
   {
       if ((*it)->active() == false)
       {
           this->kitchens.erase(it);
           delete kitchens[i];
       }
       i = i + 1;
       it++;
   }
   this->win.display_kitchens(this->kitchens);
   return (NULL);
}

int     Reception::load_balancer(Pizza const &p)
{
   int  i;
   std::vector<Kitchen*>::iterator   it;

   i = 0;
   it = this->kitchens.begin();
   while (it != this->kitchens.end())
   {
       if (this->kitchens[i]->acceptPizza(p))
           return (i);
       i = i + 1;
       it++;
   }
   return (-1);
}

int    Reception::request_order(std::string orderstr, Graphics &win)
{
    int     kid;
    std::istringstream input(orderstr);

    try
    {
        Order   items(input);
        while (items.getPizzaCount())
        {
            Pizza &pizza = items.popPizza();
            if ((kid = this->load_balancer(pizza)) == -1)
            {
                win.output(MENU, "Kitchens Busy, creating new kitchen\n");
                Kitchen *k = new Kitchen(cooks, multiplier,  refresh);
                kitchens.push_back(k);
            }
            else
                win.output(MENU, "Pizza sent to kitchen\n");

        }
        return (items.getOrderNumber());
    }
    catch (OrderException *e)
    {
        win.output(MENU, e->what());
        win.output(MENU, "\n");
        return (-1);
    }
    return (1);
}

void    Reception::in_business()
{
    std::vector<int>        commandsids;
    std::string             orderstr;
    std::istringstream      items;

    win.display_menu();
    while (1)
    {
        orderstr.assign(win.read_order());
        if ((orderstr != "empty") && (this->request_order(orderstr, win) != -1))
            win.output(MENU, "Thank you! Your order is being processed");
        win.display_kitchens(kitchens);
        win.display_orders();
        win.update();
    }
    win.exit_screen_mode();
}
