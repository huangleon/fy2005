// wizlock.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int lvl;

	if( me!=this_player(1) ) return 0;
	if( wiz_level(me) < wiz_level("(wizard)") )
		return notify_fail("ƒ„µƒŒ◊ ¶µ»º∂Ã´µÕ£¨√ª”– π”√’‚∏ˆ÷∏¡Óµƒ»®¡¶°£\n");
	if( !arg || arg=="" )
		return notify_fail("÷∏¡Ó∏Ò Ω£∫nulock <0/1>\n");

	if( sscanf(arg, "%d", lvl)!=1 )
		return notify_fail("÷∏¡Ó∏Ò Ω£∫nulock <0/1>\n");
	seteuid(getuid());
	if( LOGIN_D->set_newuser_lock(lvl) ) {
		write("∑Á‘∆ø™ º≤ªΩ” ‹–¬»ÀŒÔ£°\n");
		return 1;
	} else
		return notify_fail("∑Á‘∆ø™ ºΩ” ‹–¬»ÀŒÔ°£\n");
}

int help (object me)
{
        write(@HELP
[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m
[0;1;36mŒ◊ ¶÷∏¡Ó∏Ò Ω : 	nulock <0/1>[0m
[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m    

œﬁ÷∆∑Á‘∆ «∑ÒΩ” ‹–¬»ÀŒÔ£Æ

[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m  
HELP
);
        return 1;
}
 
