#include <login.h>;
inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
        object ob,link_ob;

        if(!arg)
                return notify_fail("╟ы╙├help▓щ┐┤┤╦╓╕┴ю╙├╖игб\n");
        ob=find_player(arg);
        if(!ob)
			return notify_fail("┤╦╓╕┴ю╓╗─▄╢╘╘┌╧▀═ц╝╥╩╣╙├бг\n");

        link_ob=ob->query_temp("link_ob");
        if(link_ob)
        {
			link_ob->set("blocked",1);
			link_ob->save();
			destruct(ob);
			write("BLOCKббOk.\n");
			return 1;
        }
        return notify_fail("Unknown error.\n");
}


int help(object me)
{
        write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	block ID[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╩╣╙├╒т╕Ў╓╕┴ю╜√╙├╥╗╕Ў═ц╝╥╒╩║┼гм╘┌╜т│¤╖т╜√╟░┤╦╒╦║┼╜л╬▐╖и╡╟┬╜бг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m 
HELP
    );
    return 1;
}
