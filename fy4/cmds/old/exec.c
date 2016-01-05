// smash.c 2-22-95
 
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	if (!arg) return notify_fail("÷∏¡Ó∏Ò Ω: exec <living>\n");
	ob = find_player(arg);
	if (!ob) return notify_fail("’“≤ªµΩ’‚∏ˆÕÊº“°£\n");
	message_vision("$NÀ´ ÷“ªæŸ£¨“ª∏ˆΩπ¿◊Ω´$n≈¸Œ™∑…ª“£°£°\n",me,ob);
	ob -> save();
        BAN_D->dynamic_add(query_ip_number(ob));
	seteuid(ROOT_UID);
	destruct(ob);
	return 1;
}
 
int help(object me)
{
   write(@HELP
[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m
[0;1;36mŒ◊ ¶÷∏¡Ó∏Ò Ω : 	exec <ÕÊº“>[0m
[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m   

Ω´ƒ≥∏ˆÕÊº“Ãﬂ≥ˆ∑Á‘∆≤¢Ω´∆‰IP‘› ±BANµÙ
µ±∑Á‘∆÷ÿ–¬REBOOT∫Û£¨’‚∏ˆIP≤≈ø…“‘‘Ÿ¡¨œﬂ

œ‡πÿ÷∏¡Ó ban, nuke

[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m 
HELP
   );
   return 1;
}
