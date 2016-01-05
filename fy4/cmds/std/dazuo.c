// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	int wimpy;
	int attr, max_attr;
	object room;
    seteuid(getuid());
    
    if( me->is_fighting() )
    	return notify_fail("╒╜╢╖╓╨▓╗─▄┤Є╫°гм╗с╫▀╗Ё╚ы─з╡─бг\n");
    if( me->is_busy() )
        return notify_fail("─у╔╧╥╗╕Ў╢п╫ў╗╣├╗╙╨═ъ│╔гм▓╗─▄┤Є╫°бг\n");
	room = environment(me);
	if(room->query("NONPC") || room->query("no_fight") || room->query("no_pk")
		|| room->query("no_magic") || room->query("no_preach")
      	|| room->query("no_beg") || room->query("no_dazuo") || room->query("no_death_penalty")
		|| room->query("no_steal") || room->query("no_spells"))
		return notify_fail("─у▓╗┐╔╥╘╘┌╒т└я┤Є╫°бг\n");
	if(me->is_ghost())
		return notify_fail("╣э╗ъ▓╗─▄┤Є╫°бг\n");
	
	if (me->query("death_revive")+ 180 > time())
		return notify_fail("─у╧╓╘┌╡─╔э╠х╫┤┐Ў╬▐╖и═┬─╔┴╖╣жбг\n");
	
	if (me->query("food") <= 0 || me->query("water") <=0)
		return notify_fail("─у╡─╩│╬я╗Є╥√╦о╬к┴угм┤Є╫°╩╟▓╗╗с╙╨╨з╣√╡─бг\n");
	
	wimpy = (int)me->query("env/wimpy");
	message_vision("$N┼╠═╚╡°╫°╘┌╡╪╔╧гм▒╒╔╧╤█╛ж┐к╩╝╡ў╧в┤Є╫°бг\n",me);
    me->set_temp("disable_inputs",1);

   	me->add_temp("block_msg/all", 1);
	me->set_temp("is_unconcious",1);
    me->set("disable_type",HIG "<┤Є╫°╓╨>" NOR);
	me->set_temp("in_dazuo",1);
    me->start_call_out( (: call_other, __FILE__, "remove_dazuo", me:), 4+ random(6));
	return 1;
}

void remove_dazuo(object me)
{
   	int attr, max_attr;
   	
   	me->delete_temp("disable_inputs");
   	me->delete("disable_type");


	if (me->query_temp("block_msg/all")>=1)
	    	me->add_temp("block_msg/all", -1);


	me->delete_temp("in_dazuo");
   	me->delete_temp("is_unconcious");
   if(!me->is_ghost() && (int) me->query("food") > 0 && (int)me->query("water") > 0)
  {
	attr = (int) me->query("food");
	attr = attr  /10 * 5;
	me->set("food",attr);

        attr = (int) me->query("water");
        attr = attr  /10 * 5;
        me->set("water",attr);

	attr = (int)me->query("kee");
	max_attr = (int)me->query("eff_kee");
	if( 2*attr > max_attr) attr = max_attr;
	else attr *=2;
	me->set("kee",attr);
        attr = (int)me->query("gin");
        max_attr = (int)me->query("eff_gin");
        if( 2*attr > max_attr) attr = max_attr;
        else attr *=2;
        me->set("gin",attr);
        attr = (int)me->query("sen");
        max_attr = (int)me->query("eff_sen");
        if( 2*attr > max_attr) attr = max_attr;
        else attr *=2;
        me->set("sen",attr);

        attr = (int)me->query("mana");
        max_attr = (int)me->query("max_mana");
	if(attr < max_attr)
        {
	        if( 2*attr > max_attr) attr = max_attr;
	        else attr *=2;
        	me->set("mana",attr);
        }
        attr = (int)me->query("force");
        max_attr = (int)me->query("max_force");
        if(attr < max_attr)
        {
                if( 2*attr > max_attr) attr = max_attr;
                else attr *=2;
                me->set("force",attr);
        }
        attr = (int)me->query("atman");
        max_attr = (int)me->query("max_atman");
        if(attr < max_attr)
        {
                if( 2*attr > max_attr) attr = max_attr;
                else attr *=2;
                me->set("atman",attr);
        }
	me->status_msg("all");
	me->force_status_msg("all");
 	message_vision("$N┤╙═№╬╥╡─╛│╜ч╓╨╗╪╔ё┴▓╞°гм╒Ў┐к┴╦╤█╛жбг\n",me);
  }

}

int help(object me)
{
        write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 	dazuo[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╩╣─у╜°╚ы═№╬╥╡─┤Є╫°╫┤╠м╓╨гм┐╔╥╘╘Ў┐ь╛л┴жгм╞°╤кгм╨─╔ёгм┴щ┴жгм
─┌┴жгм╖и┴ж╡─╗╓╕┤╦┘╢╚бг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

HELP
        );
        return 1;
}
 
