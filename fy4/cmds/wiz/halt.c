// halt.c

#include "/doc/help.h"
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !me->is_fighting() )
		return notify_fail("─у╧╓╘┌▓в├╗╙╨╘┌╒╜╢╖бг\n");
	me->remove_all_killer();
	message_vision("$N╙├╬╫╩ж╡─╔ё┴ж═г╓╣┴╦╒т│б┤Є╢╖бг\n", me);
	write("Ok.\n");
	return 1;
}

int help(object me)
{
   write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	halt[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

═г╓╣╦∙╙╨╙ы─у╙╨╣╪╡─╒╜╢╖бг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
HELP
   );
   return 1;
}
