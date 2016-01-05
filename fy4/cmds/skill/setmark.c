#include <ansi.h>
inherit SSERVER;

int main(object me, string arg)
{
	object room;
	int marktime;
	if((int) me->query_skill("incarnation",1) < 160)
    	return notify_fail("╨ш╥кг▒г╢г░╝╢╨▐╧╔╩ї▓┼─▄╩╣╙├б║х╨╥г╙╬б╗гб\n");
	if( me->is_fighting() )
		return notify_fail("╒╜╢╖╓╨╬▐╖и╩╣╙├╧╔╖игб\n");

	if( me->query("atman") < 200 )
		return notify_fail("─у╡─┴щ┴ж▓╗╣╗гб\n");

	if (me->is_busy())
		return notify_fail("─у╧╓╘┌╒¤├жгб\n");
	if( me->is_ghost())
		return notify_fail("╣э╗ъ╬▐╖и╩╣╙├╧╔╖игб\n"); 	
        if (environment(me))
        if (environment(me)->query("no_fly_in"))
    		return notify_fail("┤╦╡╪▓╗─▄╩╣╙├б║х╨╥г╙╬б╗бгбг\n");
    	if(environment(me)->query("no_fly")||environment(me)->query("no_death_penalty")
    		|| environment(me)->query("no_fly"))
    		return notify_fail("┤╦╡╪▓╗─▄╩╣╙├б║х╨╥г╙╬б╗бг\n");

	me->add("atman", -200);
	me->force_status_msg("atman");
	
	me->start_busy(1);
	message_vision( HIM "$N╗╖╣╦╦─╖╜гм╦л╩╓╥╗╗╙гм╔┴│Ў╥╗╡у╫╧╔л╗Ё╗и┬ф╚ы╡╪╔╧╧√╩з┴╦ бгбгбгбг\n" NOR, me);
	room = environment(me);
	marktime=900+random((me->query_skill("incarnation",1)-80)*100);
	me->set_temp("timespacemark",base_name(room));
    	me->set_temp("timespacemark_time",time()+marktime);
	return 1;
}

int help(object me)
{
write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ :		setmark
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╠ь╡╪х╨╥г╙╬г║╨ш╥к160╝╢╨▐╧╔╩їгм┐╔╘┌╥╗╕Ў╡╪╖╜╔ш╢и╡└▒ъгиsetmarkгйгм
	╢°║є╘┌╥╗╢и╩▒╝ф─┌┐ь╦┘╖╡╗╪гиusermarkгй
	├┐┤╬║─╖╤200╡у┴щ┴жбг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
HELP
    );
    return 1;
}
