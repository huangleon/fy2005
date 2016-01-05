// scribe.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string spells, name, ob_name;
        object ob;

        // We might need to load new objects.
        seteuid(getuid());

        if( me->is_busy() )
                return notify_fail("( ─у╔╧╥╗╕Ў╢п╫ў╗╣├╗╙╨═ъ│╔гм▓╗─▄╗н╖√гб\n");

        if( (int)me->query("sen") < 15 )
                return notify_fail("─у╡─╛л╔ё╠л▓ю┴╦гм╬▐╖и╗н╖√бг\n");

        if( !arg
        ||      sscanf(arg, "%s on %s", name, ob_name)!= 2 )
                return notify_fail("╓╕┴ю╕ё╩╜г║scribe <╖√╓ф> on <╬я╞╖>\n");

        if( !objectp(ob = present(ob_name, me)) )
                return notify_fail("─у╔э╔╧├╗╙╨╒т╤∙╢л╬ўбг\n");

        if( stringp(spells = me->query_skill_mapped("scratching")) ) {
               if (me->is_fighting()) me->start_busy(1);
               return( SKILL_D(spells)->scribe_spell(me, ob, name) );         
        } 
        return notify_fail("─у╟ы╧╚╙├ enable scratching ╓╕┴ю╤б╘ё─у╥к╩╣╙├╡─╖√╓ф╧╡бг\n");
}

int help (object me)
{
        write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 	scribe <╖√╓ф├√│╞> on <╬я╞╖├√│╞>[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╘┌╗н╖√╙├╡─╠╥╖√╓╜(paper seal)╗Є╞ф╦√╬я╞╖╔╧╗н╖√гм╝┤╩╣╩╟╧р═м╡─╖√╓фгм
╗н╘┌▓╗═м╡─╬я╞╖╔╧╥▓╙╨┐╔─▄╙╨▓╗═м╡─╨з╣√бг

╘┌─у╗н╖√╓о╟░гм─у▒╪╨ы╧╚╙├ enable ╓╕┴ю└┤╓╕╢и─у╥к╩╣╙├╡─╓ф╬─╧╡бг

╫вг║╗н╖√╗с╧√║─╚Ї╕╔╞°(╥к╥з╞╞╩╓╓╕╙├╧╩╤к╗н)╙ы╔ёгм╗н│╔╡─╖√╓ф┐╔╥╘╙├
	attach╓╕┴ю╜л╦№╠∙╘┌─┐▒ъ╬я╔э╔╧бг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m 
HELP
        );
        return 1;
}
