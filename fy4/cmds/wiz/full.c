#include <ansi.h>
inherit F_CLEAN_UP;

string *gifts=({ "gin","kee","sen" });
string *gifts1=({"atman","force","mana"});

int main(object me, string str)
{
        int i;
        object obj;

        if( !str || str == "")
                obj = me;
        else if ( !obj = present(str,environment(me)))
            return notify_fail("╢╘╧є┤э╬є: ╒╥▓╗╡╜"+str+"\n");

        if (!wizardp(me) && me->is_fighting())
        	return notify_fail(HIG"╟х╖ч╢╘─у╥б┴╦╥б╨б╓╕г║╨б┼є╙╤гм╒т╤∙╩╟▓╗╢╘╡─р▐гб\n"NOR);
    
    	if (wiz_level(me)<4 && obj!=me )
			return notify_fail("─у╓╗─▄╗╓╕┤╫╘╝║╡─╞°╤кбг\n");    		
    
        for( i = 0; i < sizeof(gifts); i++ )
        {
                obj->set(gifts[i],obj->query("max_"+gifts[i]));
                obj->set("eff_"+gifts[i],obj->query("max_"+gifts[i]));
        }
        for( i = 0; i < sizeof(gifts1); i++ )
        {
             obj->set(gifts1[i],obj->query("max_"+gifts1[i])*2);
        }
        obj->set("food",obj->max_food_capacity());
        obj->set("water",obj->max_water_capacity());
        obj->status_msg("all");
        obj->force_status_msg("all");
        obj->clear_condition();
        write("╗╓╕┤│╔╣жбг\n");
        return 1;
}

int help(object obj)
{
  write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	full	[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m  

└√╙├┤╦╓╕┴ю┐╔═ъ╚л╗╓╕┤╔·╬я╡─╫┤╠м▓в╟х│¤╥╗╨йconditionбг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
HELP
    );
    return 1;
}


