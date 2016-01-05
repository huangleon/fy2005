// task.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
#include <ansi.h>
int main(object me, string str)
{
	string output;
	
	if (me->query_temp("timer/big_cmd")+5 > time())
		return notify_fail("┤╦└р├№┴ю▒╚╜╧║─╖╤╧╡═│╫╩╘┤гм├┐╬х├ы▓┼─▄╓┤╨╨╥╗┤╬бг\n");
	else
		me->set_temp("timer/big_cmd",time());
		
        me->add("sen",-5);
	output =  HIY"й░йдйдйдйдйдйдйдйдйдйдйдйдйдйдйдй┤"NOR + HIR"бб╖ч╘╞2005╩╣├№░ёбб"NOR + HIY"й░йдйдйдйдйдйдйдйдйдйдйдйдйдйдйдй┤\n"NOR;
	output += HIY"й╕йдйдйдйдйдйдйдйдйдйдйдйдйдйдйдй╝"NOR + HIR"блблблблблблблбл"NOR + HIY"й╕йдйдйдйдйдйдйдйдйдйдйдйдйдйдйдй╝\n"NOR;
	output += TASK_D->dyn_quest_list();
	output += HIY"й░йдйдйдйдйдйдйдйдйдйдйдйдйдйдйдй┤"NOR + HIR"бббббббббббббббб"NOR + HIY"й░йдйдйдйдйдйдйдйдйдйдйдйдйдйдйдй┤\n"NOR;
	output += HIY"й╕йдйдйдйдйдйдйдйдйдйдйдйдйдйдйдй╝"NOR + HIR"блблблблблблблбл"NOR + HIY"й╕йдйдйдйдйдйдйдйдйдйдйдйдйдйдйдй╝\n"NOR;

	me->start_more("", output, 0);
	return 1;
}

int help(object me)
{
	write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 	task[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╒т╕Ў╓╕┴ю╩╟╙├└┤╡├╓к─┐╟░╡─╦∙╙╨╩╣├№гм╙╔╙┌▒╚╜╧║─╖╤╧╡═│╫╩╘┤гм
├┐╬х├ы▓┼─▄╩╣╙├╥╗┤╬бг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
HELP
	);
	return 1;
}
