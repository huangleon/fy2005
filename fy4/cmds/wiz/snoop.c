// snoop.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, ob1;

	if( !arg ) {
		if( objectp(ob = query_snooping(me)) )
			write("─у╧╓╘┌╒¤╘┌╝р╠¤" + ob->query("name") + "╦∙╩╒╡╜╡─╤╢╧вбг\n");
		else
			write("─у╧╓╘┌▓╗╘┌╝р╠¤╚╬║╬╨┼╧вбг\n");	
		return 1;
	} else if( arg=="none" ) {
		if( objectp(ob = query_snooping(me))
		&&	wiz_level(ob) >= wiz_level(me) )
			tell_object(ob, HIW + me->name(1) + "═г╓╣╝р╠¤─у╦∙╩╒╡╜╡─╤╢╧вбг\n" NOR);
		snoop(me);
		if (objectp(ob))
			write("─у╧╓╘┌═г╓╣╝р╠¤" + ob->query("name") + "╦∙╩╒╡╜╡─╤╢╧вбг\n");
		else
			write("─у╧╓╘┌▓╗╘┌╝р╠¤╚╬║╬╨┼╧вбг\n");
		return 1;
	}

	ob = find_player(arg);
	if(!ob) ob = find_living(arg);
	if(!ob || !me->visible(ob)) return notify_fail("├╗╙╨╒т╕Ў╚╦бг\n");

	if( wizhood(me) != "(admin)"
	&&	wiz_level(me) <= wiz_level(ob) )
		return notify_fail("─у├╗╙╨╝р╠¤" + ob->name() + "╦∙╩╒╠¤╤╢╧в╡─╚и└√бг\n");

	if( me==ob ) return notify_fail("╟ы╙├ snoop none ╜т│¤╝р╠¤бг\n");
	
	if (objectp(ob1=query_snoop(ob)))
		return notify_fail(ob1->name()+"╒¤╘┌╝р╠¤"+ob->name()+"╡─╨┼╧вбг\n");
	
	if (ob->query_temp("netdead",1))
		return notify_fail("┤╦╚╦╒¤┤ж╘┌╢╧╧▀╫┤╠мбг\n");
	
	if (!userp(ob))
		return notify_fail("├╗╖и╟╘╠¤NPC╨┼╧в╡─бг\n");
				
	snoop(me, ob);
	write("─у╧╓╘┌┐к╩╝╟╘╠¤" + ob->name(1) + "╦∙╩╒╡╜╡─╤╢╧вбг\n");
	if( userp(ob) ) log_file("SNOOP_PLAYER",
		sprintf("%s(%s) snoops %s on %s.\n", me->name(1), geteuid(me), ob->name(1),
			ctime(time()) ) );
	if( wizardp(ob) && wizhood(me) != "(admin)")
		tell_object(ob, HIW + me->name(1) + "┐к╩╝╝р╠¤─у╦∙╩╒╡╜╡─╤╢╧вбг\n" + NOR);

	return 1;
}

int help()
{
	write(@TEXT
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	snoop <─│╚╦>|none[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╝р╠¤╞ф╦√╩╣╙├╒▀╦∙╩╒╠¤╡─╤╢╧вгмsnoop none ╘Є╚б╧√╝р╠¤бг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
TEXT
	);
	return 1;
}
