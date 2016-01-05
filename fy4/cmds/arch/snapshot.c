
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	if (!arg) return notify_fail("╓╕┴ю╕ё╩╜: snapshot <living>\n");
	ob = find_player(arg);
	if (!ob) return notify_fail("╒╥▓╗╡╜╒т╕Ў╔·╬ябг\n");
	if (!userp(ob))
		return notify_fail("─у▓╗─▄╢╘╖╟═ц╝╥╩╣╙├┤╦├№┴югм╟ы▓╬┐┤╦╡├ўбг\n");
	"/feature/nada.c"->snapshot(ob);	
	write("Ok.\n");
	return 1;
}
 
int help(object me)
{
   write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	snapshot <╔·╬я>[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

┤╦├№┴ю╜л╕°═ц╝╥╡─╫╩┴╧╫Ў╥╗╕Ўб░╒╒╧рб▒гм▓в╡╟╝╟╘┌░╕бг
╢┴╨┤├№┴югм║─╖╤╫╩╘┤бг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

HELP
   );
   return 1;
}
