// kickout.c

#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg || sscanf(arg, "%s", arg) != 1 )
		return notify_fail("─у╥к┤▌╗┘╩▓├┤г┐\n");

	if( !objectp(ob = present(arg, me)) )
        return notify_fail("─у╔э╔╧├╗╙╨╒т╤∙╢л╬ўбг\n");
	if(me->query("id") != ob->query("owner"))
		return notify_fail("╒т╤∙╢л╬ў▓╗╩╟─у╡─гм─у▓╗┐╔╥╘┤▌╗┘╦№бг\n");
	seteuid(ROOT_UID);
	rm(ob->query_save_file()+".o");
	rm(base_name(ob) + ".c");
	ob->move(environment(me));
	destruct(ob);
	me->add("created_item",-1);
	me->delete("ji");		
	me->delete("ji2_times");
	seteuid(getuid());
	write("╬я╞╖╧·╗┘═ъ▒╧бг\n");
	return 1;

}

int help(object me)
{
write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 	destroy <─│╬я╝■>[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

┤╦╓╕┴ю╩╟╙├└┤┤▌╗┘─у▓╗╧ы╘┘╥к╡─╫╘╘ь╬я╞╖гм▒╗┤▌╗┘╡─╬я╝■╜л
╙└╘╢┤╙╖ч╘╞╓╨╧√╩збг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

HELP
    );
    return 1;
}

