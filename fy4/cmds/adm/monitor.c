#include <login.h>;
inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        object ob,link_ob;
        int num;
        string name;

        if(!arg)
        	return notify_fail("╟ы╙├help▓щ┐┤┤╦╓╕┴ю╙├╖игб\n");
        
        if(sscanf(arg,"%s %d", name,num)!=2)
        	return notify_fail("╟ы╙├help▓щ┐┤┤╦╓╕┴ю╙├╖игб\n");
                
        ob=find_player(name);
        if(!ob)
			return notify_fail("┤╦╓╕┴ю╓╗─▄╢╘╘┌╧▀═ц╝╥╩╣╙├бг\n");

		if (num>5 || num<0)
			return notify_fail("╟ы╙├help▓щ┐┤┤╦╓╕┴ю╙├╖игб\n");
			
        ob->set("MONITORING", num);
		if (!num)
			ob->delete("MONITORING");
		
		write(sprintf("┐к╩╝╢╘%s(%s)╜°╨╨%d╝╢╝═┬╝бг\n", ob->name(1),ob->query("id"),num));
		return 1;
		        
}


int help(object me)
{
        write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	monitor ID 0/1/2/5 [0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╩╣╙├╒т╕Ў╓╕┴ю╢╘─│ID╡─╨╨╬к╫ў╝╟┬╝гм╕├╓╕┴ю─┐╡─╩╟╫╖╫┘╥╗╨й▓╗├ў╨╨╬кгм
║─╖╤╧╡═│╫╩╘┤ги╗·╩▒бв╙▓┼╠┐╒╝фгйгм╝╚▓╗╥к╟с╥╫╩╣╙├гм╥▓▓╗╥к│д╞┌╩╣╙├бг
╝═┬╝╬─╝■╘┌/log/backup/─┌

monitor xxx 0	═г╓╣╢╘─│ID╡─╝═┬╝
monitor xxx 1	╢╘╕├ID╘Ў╝╙combat_exp/potential/saved_quest
		╡─▓┘╫ў╝╙╥╘╝╟┬╝
monitor xxx 2	╢╘╕├ID╘Ў╝╙╜╗╠╕╝═┬╝
monitor xxx 3	(undecided)
monitor xxx 4	(undecided)
monitor xxx 5   ╢╘╕├ID╦∙╙╨╖╟╨╨╫▀╡─╨╨╬к╝╙╥╘╝╟┬╝ги╫у╣╗╙▓┼╠г┐гй

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m 
HELP
    );
    return 1;
}
