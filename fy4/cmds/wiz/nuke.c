// smash.c 2-22-95
 
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	if (!arg) return notify_fail("╓╕┴ю╕ё╩╜: nuke <living>\n");
	ob = find_player(arg);
	if (!ob) return notify_fail("╒╥▓╗╡╜╒т╕Ў═ц╝╥бг\n");
	message_vision("$N╦л╩╓╥╗╛┘гм╥╗╕Ў╜╣└╫╜л$n┼№╬к╖╔╗╥гбгб\n",me,ob);
	ob->set("kickout_time",time());
	ob -> save();
	seteuid(ROOT_UID);
	destruct(ob);
	return 1;
}
 
int help(object me)
{
   write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	nuke <═ц╝╥>[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
   
╜л─│╕Ў═ц╝╥╠▀│Ў╖ч╘╞гм▓в╟╥╩╣╞ф╘┌╥╗╕Ў╨б╩▒─┌▓╗┐╔╥╘┴к╧▀бг

╧р╣╪├№┴ю	ban, imprison

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
HELP
   );
   return 1;
}
