// save.c
inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object link_ob;

				if ( !wizardp(me) && me->query_temp("timer/big_cmd")+60 > time())
					return notify_fail("¥À¿‡√¸¡Ó±»Ωœ∫ƒ∑—œµÕ≥◊ ‘¥£¨√ø¡˘ Æ√Î≤≈ƒ‹÷¥––“ª¥Œ°£\n");
				else
					me->set_temp("timer/big_cmd",time());

        seteuid(getuid());

        if( !objectp(link_ob = me->query_temp("link_ob")) )
                return notify_fail("ƒ„≤ª «”…’˝≥£¡¨œﬂΩ¯»Î£¨≤ªƒ‹¥¢¥Ê°£\n");
  
        if( environment(me)->query("valid_startroom") ) {
                me->set("startroom", base_name(environment(me)));
                write("µ±ƒ„œ¬¥Œ¡¨œﬂ ±£¨ª·¥”’‚¿ÔΩ¯»Î°£\n");
        } 
                	
// change save to fake
// for decrease harddisk operate
// 2002-11-1 
// akuma

      	if( (int)link_ob->save() && (int)me->save() ) {
        write("µµ∞∏¥¢¥ÊÕÍ±œ°£\n");
                return 1;
       	} else {
                write("¥¢¥Ê ß∞‹°£\n");
                return 0;
        }
}

int help(object me)
{
        write(@HELP
[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m
[0;1;36m÷∏¡Ó∏Ò Ω : 	save[0m
[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m   

¥Ê¥¢ ˝æ›“‘º∞…Ë∂®ƒ„œ¬“ª¥Œ¡™œﬂΩ¯»Îµƒµÿµ„°£

[0;1;37m©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§©§[0m   
HELP
        );
        return 1;
}
