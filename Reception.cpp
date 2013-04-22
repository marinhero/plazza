//
// Reception.cpp for plazza in /home/ignatiev/Projects/plazza
//
// Made by Marin Alcaraz
// Login   <alcara_m@epitech.net>
//
// Started on  Wed Apr 17 15:28:37 2013 Marin Alcaraz
// Last update Mon Apr 22 12:01:36 2013 ivan ignatiev
//

#include "Reception.hh"


Reception::Reception(int m, int c, int r) : win(* new Graphics("plazza")) ,
multiplier(m),
cooks(c), refresh(r),threadrun_(true)
 {
}

Reception::~Reception()
{
    win.exit_screen_mode();
    this->threadrun_ = false;
    delete &win;
    delete inspecthread_;
    while (!this->kitchens.empty())
    {
        delete this->kitchens.back();
        this->kitchens.pop_back();
    }
}

void    *Reception::run()
{
    while (this->threadrun_)
    {
        std::vector<Kitchen*>::iterator     it;
        std::vector< std::vector<Kitchen *>::iterator>               rm;

        it = this->kitchens.begin();
        while (it != this->kitchens.end())
        {
            if ((*it)->active() == false)
                rm.push_back(it);
            it++;
        }
        while (!rm.empty())
        {
            delete *(rm.back());
            this->kitchens.erase( rm.back() );
            rm.pop_back();
        }
        this->win.display_kitchens(this->kitchens);
        this->win.update();
        sleep(1);
    }
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
    inspecthread_ = new Thread(* this);

    while (1)
    {
        orderstr.assign(win.read_order());
        if (orderstr.compare(0, 4, "quit") == 0)
            return ;
        if ((orderstr != "empty") && (this->request_order(orderstr, win) != -1))
            win.output(MENU, "Thank you! Your order is being processed");
        win.display_kitchens(kitchens);
        win.display_orders();
        win.update();
    }
}
