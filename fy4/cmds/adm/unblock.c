#include <login.h>;
inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        object ob,link_ob;
        string id,password;

        if(!arg)
                return notify_fail("╟ы╙├help▓щ┐┤┤╦╓╕┴ю╙├╖игб\n");
        ob=find_player(arg);
        if(ob)
			return notify_fail("┤╦╓╕┴ю╓╗─▄╢╘└ы╧▀═ц╝╥╩╣╙├бг\n");

		ob = FINGER_D->acquire_login_ob(arg);
    	
        if(!ob)
             return notify_fail("├╗╙╨╒т╕Ў═ц╝╥бг\n");
			
		if (!ob->query("blocked"))
             return notify_fail("╒т╕Ў═ц╝╥▓╗╨ш╥к╓┤╨╨╜т╦°▓┘╫ўбг\n");
	
		ob->delete("blocked");
		ob->save();
		destruct(ob);
		write("UNBLOCK ═ъ▒╧ Ok.\n");
		
        return 1;
}


int help(object me)
{
        write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	unblock ID[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╒т╕Ў╓╕┴ю╙├╥╘╜т│¤▒╗╧╡═│╜√╙├╡─═ц╝╥╒╩║┼бг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m 
HELP
    );
    return 1;
}
