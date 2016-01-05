#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string msg;
	int num, num1;
	
	if (me->query_temp("timer/lotto100")+ 2 > time())
		return notify_fail("┤╦╓╕┴ю├┐г▓├ы╓╙╩╣╙├╥╗┤╬бг\n");
		
	if (arg)	
		num = atoi(arg);
	
	if (!num || num >100)
		return notify_fail("─у╓╗─▄╦ц╗·▓·╔·╥╗╕Ў0╡╜100╓о╝ф╡─╒√╩¤гм╕ё╩╜г║lotto <number>\n");
	
	num1 = random(num);
	
	message_vision(WHT"$N╘┌0╡╜"+ num + "╓о╝ф╓└│Ў┴╦"HIY + num1 + NOR+WHT"╡убг\n"NOR, me);
	me->set_temp("timer/lotto100", time());
	
	return 1;
}

int help(object me)
{
     write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ :		lotto <number>[0;32m	
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

╒т╕Ў╓╕┴ю╚├─у╦ц╗·▓·╔·╥╗╕Ўг░гнгюгїгэгтгхгЄ╓о╝ф╡─╒√╩¤

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
HELP
    );
    return 1;
}
