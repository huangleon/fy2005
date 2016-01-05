// home.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string msg;

//	if( file_size(user_path(geteuid(me)) + "workroom.c") <= 0 )
//		return notify_fail("─у├╗╙╨╫╘╝║╡─╣д╫ў╩╥бг\n");

	if( stringp(msg = me->query("env/msg_home")) )
		message_vision(msg + "\n", me);
//	me->move(user_path(geteuid(me)) + "workroom");
        me->move("d/wiz/jobroom"); 
        	return 1;
}

int help(object me)
{
  write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╬╫╩ж╓╕┴ю╕ё╩╜ : 	home[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

└√╙├┤╦╥╗╓╕┴ю┐╔╓▒╜╙╗╪╡╜╫╘╝║╡─╣д╫ў╩╥бг
╚ч╣√─у╙╨ 'msg_home' ╒т╕Ў╔ш╢и, ╘Є╘┌│б╡─╚╦╢╝╗с┐┤╡╜─╟╕Ў╤╢╧вбг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m 
HELP
    );
    return 1;
}
