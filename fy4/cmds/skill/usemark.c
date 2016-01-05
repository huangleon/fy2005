#include <ansi.h>
inherit SSERVER;

int main(object me, string arg)
{
	string roomname;
	object room;
	int skill,atman;
	if( (skill=me->query_skill("incarnation",1)) < 160 )
       		return notify_fail("╨ш╥кг▒г╢г░╝╢╨▐╧╔╩ї▓┼─▄╩╣╙├б║х╨╥г╙╬б╗гб\n");
	if( me->is_fighting() )
		return notify_fail("╒╜╢╖╓╨╬▐╖и╩╣╙├╧╔╖игб\n");
	
	if (me->is_busy())
		return notify_fail("─у╧╓╘┌╒¤├жгб\n");
	if( me->is_ghost())
		return notify_fail("╣э╗ъ╬▐╖и╩╣╙├╧╔╖игб\n");
		
	if (stringp(me->query_temp("no_move")))
		return notify_fail(me->query_temp("no_move"));	
		 	
	if( !(roomname=me->query_temp("timespacemark")))
		return notify_fail("─у├╗╙╨╔ш╢и╡└▒ъбг\n");
	if( time()>me->query_temp("timespacemark_time"))
		return notify_fail("─у╔ш╢и╡─╡└▒ъ╥╤╛н╩з╨з┴╦бг\n");
	if(environment(me)->query("no_death_penalty") || environment(me)->query("no_fly")
		|| environment(me)->query("no_magic") )
    		return notify_fail("┤╦╡╪▓╗─▄╩╣╙├б║х╨╥г╙╬б╗\n");
	
	if( (atman=me->query("atman")) < 200 )
		return notify_fail("─у╡─┴щ┴ж▓╗╣╗гб\n");
	me->add("atman", -200);
	me->force_status_msg("atman");
	
	if( random(atman/5+(skill-90)/2+180) <100)	{
		 message_vision( HIY "$N╩╓╓╕╞■╛ўгм┐┌╓╨─м─югм╡л╩▓├┤╩┬╥▓├╗╖в╔·бг\n" NOR, me);
		 return notify_fail("─у╡─б║х╨╥г╙╬б╗╩з░▄┴╦бг\n");	
		}
	message_vision( HIC "$N╩╓╓╕╞■╛ўгм┐┌╓╨─м─югм║Ў╚╗╗п╫ў╥╗╣╔╟р╤╠╧√╩з┴╦ ....\n" NOR, me);
	TASK_D->flying_risk(me);
	room = load_object(roomname);
	me->move(room);
	message( "vision", HIC "\n║Ў╚╗╥╗╣╔╟р╤╠┤╙╡╪╔╧├░│Ўгм"+me->query("name")+"┤╙╤╠╬э╓╨│Ў╧╓гб\n\n" NOR,
		room, ({ me }) );
	return 1;
}


int help(object me)
{
write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ :		usemark
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╠ь╡╪х╨╥г╙╬г║╨ш╥к160╝╢╨▐╧╔╩їгм┐╔╘┌╥╗╕Ў╡╪╖╜╔ш╢и╡└▒ъгиsetmarkгйгм
	╢°║є╘┌╥╗╢и╩▒╝ф─┌┐ь╦┘╖╡╗╪гиusermarkгй
	├┐┤╬║─╖╤200╡у┴щ┴жбг
			
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
HELP
    );
    return 1;
}
