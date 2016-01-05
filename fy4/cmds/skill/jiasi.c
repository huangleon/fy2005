// Silencer@fengyun	June.2005
// 5 mins per use.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int main(object me, string arg)
{
	int skill, duration;
	object target;
	string msg;
	
 	seteuid(getuid());
	if(me->query("class") != "shenshui") 
		return	notify_fail("╝┘╦└╩╟╔ё╦о╣м╡─╛°╝╝гб\n");
	
	if (me->is_ghost())
		return notify_fail("─у╥╤╛н▓╗╩╟╗ю╚╦┴╦бг\n");
		
	//  normally it's 900-600 = 300=5 min, 
	skill = me->query_skill("nine-moon-spirit",1);	
	duration = me->query("timer/jiasi") - time() + 900 - F_ABILITY->check_ability(me, "jiasi_add")*60;
	if (duration > 0)
	   	return notify_fail(WHT"╨ш╥к╡╚┤¤" + duration + WHT"├ы╫є╙╥гм╧╓╘┌╛╔╝╝╓╪╤▌╗с▒╗┐┤┤й╡─гб\n");
    	  	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("─у▓╗╘┌╒╜╢╖╓╨гм▓╗╨ш╥к╝┘╦└бг\n");

	message_vision(WHT"\n$N"NOR+WHT"▓╥╜╨╥╗╔∙гм╥╗═╖╘╘╡╣╘┌╡╪╧┬бгбгбгбгбг\n"NOR,me);
        
    // Some attacks don't set this mark... mostly spells.    
    if (me->query_temp("last_damage_time") + 4 < time())
    {
		message_vision(HIR"$N"HIR"┤є╨ж╡└г║б░├╗┼Ў╡╜╛═╦└┴╦гм┼х╖■┼х╖■гбгбгбб▒\n"NOR, target);
		me->perform_busy(1);
		me->set("timer/jiasi",time());
		tell_object(me, RED"ги─у╝┘╦└╡─░╤╧╖▒╗╚╦╩╢╞╞┴╦гбгбгбгй\n"NOR);
		return 1;
	}
	message_vision("\n$N╦└┴╦бг\n",me);	
	
    me->set("disable_type",HIG "<╝┘╦└╓╨>" NOR);
    me->remove_all_killer();
	me->remove_all_enemy();
    me->start_call_out( (: call_other, __FILE__, "remove_dazuo", me :), 60);
    me->set_temp("disable_inputs",1);
    me->set_temp("block_msg/all",1);
	me->set_temp("is_unconcious",1);
	me->set_temp("in_jiasi",1);
	return 1;
}

void remove_dazuo(object me)
{
   	me->delete_temp("in_jiasi");
   	me->delete_temp("is_unconcious",1);
   	me->delete_temp("disable_inputs");
   	me->delete("disable_type");
   	me->delete_temp("block_msg/all");
   	message_vision("$N╘┌╡╪╔╧╟─╟─╡╪╖н┴╦╕Ў╔эгм╨б╨─╥э╥э╡╪╒Ў┐к┴╦╤█бг\n",me);
	me->set("timer/jiasi",time());
}




int help(object me)
{
        write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 	jiasi[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╔ё╦о╣м╛°╝╝гм╘┌╛°╛│╓╨╝┘╫░╦└═Ў╞█╞н╢╘╩╓гм┤┤╘ь╠╙╔·╡─╗·╗сбг
╫в╥тг║─у╡─╢╘╩╓╥▓▓╗╩╟╔╡╫╙гм╘╦╙├┤╦╛°╝╝╨ы╫е╫╝╩▒╗·гм╬и╙╨
╘┌▒╗╡╨╚╦╔╦║ж║є╡─2╗╪║╧─┌▓┼─▄╔·╨згм╖ё╘Є─к├√╞ф├ю╦└┴╦┐╔╞н
▓╗╡╜╚╦бг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

HELP
        );
        return 1;
}
 
