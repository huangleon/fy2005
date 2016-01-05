// whisper.c

#include <ansi.h>
#define NEW_PERIOD 32400
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string dest, msg;
	object ob;
	
	if((int)me->query("mud_age") < NEW_PERIOD)
		return notify_fail("─у╓╗┐╔╥╘╩╣╙├гиsayгйбг\n");
	
	if( !arg || sscanf(arg, "%s %s", dest, msg)!=2 )
		return notify_fail("─у╥к╢╘╦н╢·╙я╨й╩▓ўсг┐\n");

	ob = present(dest, environment(me));
	if( !ob || !ob->is_character() )
		return notify_fail("─у╥к╢╘╦н╢·╙яг┐\n");

	write( GRN "─у╘┌" + ob->name() + "╡─╢·▒▀╟─╔∙╦╡╡└г║" + msg + "\n" NOR);
	tell_room( environment(me), me->name() + "╘┌" + ob->name()
		+ "╢·▒▀╨б╔∙╡╪╦╡┴╦╨й╗░бг\n", ({ me, ob }) );
	if( !userp(ob) ) ob->relay_whisper(me, msg);
	else
		tell_object( ob, GRN + me->name() + "╘┌─у╡─╢·▒▀╟─╔∙╦╡╡└г║" + msg + "\n" NOR);
	return 1;
}

int help(object me)
{
	write( @TEXT
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 	whisper <─│╚╦> <╤╢╧в>[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╒т╕Ў╓╕┴ю┐╔╥╘╙├└┤║══м╥╗╖┐╝ф╓╨╡─╚╦╢·╙ягм░№└и NPC ╘┌─┌бг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
TEXT
	);
	return 1;
}
