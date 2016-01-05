// smash.c 2-22-95
 
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	if (!arg) return notify_fail("╓╕┴ю╕ё╩╜: smash <living>\n");
	ob = present(arg, environment(me));
	if (!ob) return notify_fail("╒╥▓╗╡╜╒т╕Ў╔·╬ябг\n");
	if (userp(ob))
		return notify_fail("─у▓╗─▄╢╘═ц╝╥╩╣╙├┤╦├№┴югм╟ы▓╬┐┤╦╡├ўбг\n");
	
	message_vision("$N╩╓╥╗╗╙гм╥╗╡└╔┴╡ч┤╙╠ь╢°╜╡гм╜л$n╗п╬кь┤╖█гбгб\n",me,ob);
	
	ob ->set_temp("last_damage_from", me);
	ob -> die();
	return 1;
}
 
int help(object me)
{
   write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	smash <╔·╬я>[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

┤╦├№┴ю╜л╜Ў╧▐╙┌╖╟═ц╝╥╡─╔·╬ягм
╢╘═ц╝╥┤ж╖г╡─├№┴ю┐╔▓╬╝√ nuke, exec, imprison, ban

┤╦├№┴ю╜л░╤╬╫╩ж╔ш╬к╫ю║є╔╦║ж╔·╬я╒▀гм╚ч╣√─у╧ы▒▄├тгм╘Є▓╬┐┤dest├№┴юбг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

HELP
   );
   return 1;
}
