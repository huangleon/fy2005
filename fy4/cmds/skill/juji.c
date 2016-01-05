#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int main(object me, string arg)
{
	object obj;
	int skill, i, count, myexp, yourexp, lvl;
	string gender,msg;
	
	if (me->query("class")!="beggar")
		return notify_fail("╓╗╙╨╪д░я╡▄╫╙▓┼─▄╩╣╙├═╡╧обг\n");
	
	lvl = me->query_skill("begging",1);
	if (lvl < 90)
		return notify_fail("╛╤╗ў╓┴╔┘╨ш╥к90╝╢╡─╞Є╠╓╓о╩їбг\n");
		
	if (environment(me)->query("no_fight"))
		return notify_fail("╒т└я╜√╓╣╒╜╢╖бг\n");

	if (! arg || ! objectp(obj = present(arg, environment(me))))
		return notify_fail("─у╧ы═╡╧о╦нг┐\n");

	if (! obj->is_character())
		return notify_fail("┐┤╟х│■╥╗╡угм─╟▓в▓╗╩╟╔·╬ябг\n");

	if (obj->is_fighting(me))
		return notify_fail("─у╥╤╛н╘┌╒╜╢╖╓╨┴╦гм╗╣╧ы═╡╧ог┐\n");

	if (!living(obj))
		return notify_fail(obj->name() + "╢╝╥╤╛н╒т╤∙┴╦гм─у╗╣╙├╡├╫┼═╡╧о┬Ёг┐\n"); 

	if (obj == me)
		return notify_fail("═╡╧о╫╘╝║г┐▒Ё╒т├┤╧ы▓╗┐кбг\n");

	if (userp(me))
	if (!COMBAT_D->legitimate_kill(me, obj)) {
		if (stringp(obj->query("NO_KILL")))
			return notify_fail(obj->query("NO_KILL"));
		if (stringp(obj->query("NO_PK")))
			return notify_fail(obj->query("NO_PK"));	
		else 
			return notify_fail("─у╬▐╖и═╡╧о┤╦╚╦бг\n");
	}
		
	if (me->is_busy())
		return notify_fail("─у╒¤├ж╫┼гм▓╗─▄═╡╧обг\n");

	if (obj->query_temp("juji_alert")+ 60 > time())
		return notify_fail("╢╘╖╜╒¤┤ж╙┌╕▀╢╚╛п╠ш╓о╓╨гм╬▐╖и═╡╧о│╔╣жбг\n");	
		
	gender = obj->query("gender")=="─╨╨╘" ? "╦√" : "╦¤";
	
	tell_object(me, CYN"─у╟─╟─╫▀╡╜"+obj->name()+CYN"▒│║єгм╖╔╔э╫▌╞Ёгм├═╚╗╧Є"+gender+"╞╦╚егб"NOR);
	tell_object(obj, BLU"─у╔э║є║Ў╚╗╠°│Ў╥╗╕Ў╚╦╙░гм┘┐╚╗╧Є─у╖в╞Ё╣е╗ўгб\n" NOR);
	
	message("vision",CYN""+me->name()
		+CYN"╟─╟─╫▀╡╜"+obj->name()+CYN"▒│║єгм╖╔╔э╫▌╞Ёгм├═╚╗╧Є"
		+obj->name()+CYN"╞╦╚егб" NOR, environment(me), ({me, obj}));

	skill = me->query_skill("betting",1);
	myexp = me->query("combat_exp");
	yourexp = obj->query("combat_exp");
	
	count = me->query_agi()/10;
//	me->ccommand("kill "+obj->get_id());
	
	me->kill_ob(obj);
	obj->kill_ob(me);
	i = 0;
	
	if ( myexp/2 + random(myexp*4) <  yourexp)
	{
		message_vision(YEL"$N▓╗╓к║╬╩▒╚┤╥╤╫к╡╜┴╦$n╡─╔э║єгм$n╞╦┴╦╕Ў┐╒бг\n"NOR,obj,me);
	} else
	{
		while (count--) { 
			if (me->is_busy())	continue;
			msg = BLU"╥ї╙░╓╨╖╔│Ў╡┌"+chinese_number(i+1)+"╒╨\n"NOR;
			me->add_temp("apply/damage",lvl);
			COMBAT_D->do_attack(me,obj,TYPE_PERFORM,msg);
			me->add_temp("apply/damage",-lvl);
			i++;
		}
	}
	
	me->perform_busy(1);
	if (obj)
		obj->set_temp("juji_alert",time());
	return 1;
}


int help(object me)
{
  write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 	juji <╚╦╬я>[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
 
╛╤╗ўгм╞ф╩╡╛═╩╟│├╚╦▓╗▒╕╡─═╡╧огм╬к╪д░я╡▄╫╙╫и╙├бг╛╤╗ў╡─│╔╣ж┬╩╙ы
╛╤╗ў╒▀╡─╛н╤щ╧р╣╪гм╛╤╗ў┤╬╩¤=╫╘╔э╦┘╢╚/10

╛╤╗ў╓┴╔┘╨ш╥к90╝╢╡─╞Є╠╓╓о╩їбг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
HELP
    );
    return 1;
}
