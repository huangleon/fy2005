// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string msg;
	if(me->query_temp("proprop") && me->query_temp("block_msg/all")>=1)
	{
		me->add_temp("proprop",-1);
		me->add_temp("block_msg/all",-1);
		write(CLR);
		write("╞┴─╗╩ф╚ы╗╓╕┤╒¤│г╫┤╠мгм╟ы╝╠╨°╣д╫ўг║\n");
	} else
		write("─у├╗╙╨╩╣╙├╣¤BOSS╓╕┴юбг\n");
		
	return 1;
}

int help(object me)
{
     write(@HELP
╓╕┴ю╕ё╩╜: bossgone  

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 	╓╕┴ю╕ё╩╜: bossgone  [0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╒т╕Ў╓╕┴ю╚├─у(═ц╝╥)╘┌└╧░х╫▀║є╗╓╕┤╒¤│г╖ч╘╞╙╬╧╖бг

╙╨╣╪╓╕┴юг║boss

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m 
HELP
    );
    return 1;
}
