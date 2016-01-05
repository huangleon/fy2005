// smash.c 2-22-95
 
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	if (!arg) return notify_fail("÷∏¡Ó∏Ò Ω: smash <living>\n");
	ob = present(arg, environment(me));
	if (!ob) return notify_fail("’“≤ªµΩ’‚∏ˆ…˙ŒÔ°£\n");
	message_vision("$N ÷“ªª”£¨$n”¶…˘À§µπ‘⁄µÿ…œ£°£°\n",me,ob);
	ob -> unconcious();
	return 1;
}
 
int help(object me)
{
   write(@HELP
[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m
[0;1;36mŒ◊ ¶÷∏¡Ó∏Ò Ω : 	uncon <…˙ŒÔ>[0m
[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m   

 π…˙ŒÔªË√‘≤ª–—°£

[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m   

HELP
   );
   return 1;
}
