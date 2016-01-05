// say.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if (!arg) {
		write("─у╫╘╤╘╫╘╙я▓╗╓к╡└╘┌╦╡╨й╩▓ўсбг\n");
		message("sound", me->name() + "╫╘╤╘╫╘╙я▓╗╓к╡└╘┌╦╡╨й╩▓ўсбг\n",
			environment(me), me);
		return 1;
	}
	if( (int)me->query("kee") < (int)me->query("max_kee") / 5 ) {
		arg = replace_string(arg, " ", " ... ") + " ...";
	}

	write( CYN "─у╦╡╡└г║" + arg + "\n" NOR);
	message("sound", CYN + me->name() + "╦╡╡└г║" +  arg + "\n" NOR,
		environment(me), me);

	// The mudlib interface of say
	all_inventory(environment(me))->relay_say(me, arg);

	return 1;
}

int help (object me)
{
	write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 	 say <╤╢╧в>[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
 
╦╡╗░гм╦∙╙╨╕·─у╘┌═м╥╗╕Ў╖┐╝ф╡─╚╦╢╝╗с╠¤╡╜─у╦╡╡─╗░бг
 
╫в: ▒╛╓╕┴ю┐╔╙├ ' ╚б┤·.

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m    
HELP
	);
	return 1;
}
