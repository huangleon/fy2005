// promote.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string old_status, new_status;
	int my_level, ob_level, level;

#ifdef	ENCRYPTED_WRITE	
		string *allowed = ({ "(wizard)","(immortal)","(player)" });
#endif   

#ifdef	NONENCRYPTED_WRITE	
		string *allowed = ({ "(admin)","(arch)","(wizard)","(immortal)","(player)" });
#endif   

	if( me!=this_player(1) ) return 0;

	if( !arg || sscanf(arg, "%s %s", arg, new_status)!=2 )
		return notify_fail("Ö¸Áî¸ñÊ½£ºpromote <Ê¹ÓÃÕß> <µÈ¼¶>\n");

	if( member_array(new_status,allowed) == -1) 
		return notify_fail("Ã»ÓĞÕâÖÖµÈ¼¶¡£\n");
	
	if( !objectp(ob = present(arg, environment(me))) 
	||	!userp(ob) )
		return notify_fail("ÄãÖ»ÄÜ¸Ä±äÊ¹ÓÃÕßµÄÈ¨ÏŞ¡£\n");

	if( wiz_level(me) < wiz_level(new_status) )
		return notify_fail("ÄãÃ»ÓĞÕâÖÖÈ¨Á¦¡£\n");

	old_status = wizhood(ob);

	seteuid(getuid());
	if( !(SECURITY_D->set_status(ob, new_status)) )
		return notify_fail("ĞŞ¸ÄÊ§°Ü¡£\n");

	message_vision("$N½«$nµÄÈ¨ÏŞ´Ó " + old_status + " ¸ÄÎª " + new_status + " ¡£\n", me, ob);
	log_file( "static/promotion", getuid(me)+" promoted " + getuid(ob) 
		+ " from "+ old_status + " to " + new_status + " on " + ctime(time()) + "\n" );
	seteuid(getuid());
	ob->setup();

	return 1;
}

int help(object me)
{
write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÎ×Ê¦Ö¸Áî¸ñÊ½ : 	promote <Ä³ÈË> (È¨ÏŞµÈ¼¶)[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

ÓÃÀ´ÌáÉıÈ¨ÏŞµÈ¼¶, (player) (immortal) (wizard) (arch) (admin)
Ò»¸ö admin ÄÜÌáÉıÈ¨ÏŞÖÁÈÎºÎµÈ¼¶, ¶ø arch Ö»ÄÜÌáÉıÖÁ arch¡£

×¢£º¼ÓÃÜÕ¾µãpromoteÖ»ÄÜÓÃÓÚwizard¡¢immortal¡¢player£¬¶ÔÆäËûµÈ¼¶
µÄÌáÉı±ØĞëÍ¨¹ıwizlist½øĞĞ¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m 

HELP
    );
    return 1;
}
