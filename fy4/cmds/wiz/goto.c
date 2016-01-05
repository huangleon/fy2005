// goto.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int goto_inventory = 0;
	object obj,obj1;
	string msg;

	if( !arg ) return notify_fail("ÄãÒªÈ¥ÄÄÀï£¿\n");

	if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;

	if (wiz_level(me)<4 && goto_inventory)
		return notify_fail("ÄãµÄ¹ÜÀíÈ¨ÏŞÎŞ·¨½øÈëÎïÌåÄÚ²¿¡£\n");
			
	if( !arg ) return notify_fail("ÄãÒªÈ¥ÄÄÀï£¿\n");

	obj = find_player(arg);
	if(!obj) obj = find_living(arg);
	if(!obj || !me->visible(obj)) {
		arg = resolve_path(me->query("cwd"), arg);
		if( !sscanf(arg, "%*s.c") ) arg += ".c";
		if( !(obj = find_object(arg)) ) {
			if( file_size(arg)>=0 )
				return me->move(arg);
			return notify_fail("Ã»ÓĞÕâ¸öÍæ¼Ò¡¢ÉúÎï¡¢»òµØ·½¡£\n");
		}
	}
	
	if (wiz_level(me)<4 && !environment(obj) && obj->query("id"))
		return notify_fail("ÄãµÄ¹ÜÀíÈ¨ÏŞÎŞ·¨½øÈë´ËÎïÌåÄÚ²¿¡£¡£\n"); 
		
	if(!goto_inventory && environment(obj))
		obj = environment(obj);

	if( !obj ) return notify_fail("Õâ¸öÎï¼şÃ»ÓĞ»·¾³¿ÉÒÔ goto¡£\n");
	
	if( stringp(msg = me->query("env/msg_mout")) ) {
	        if (msg!="none") message_vision(msg+"\n",me);		
	} else	{
			message("vision","ÄãÑÛÇ°Ò»»¨£¬"+me->name()+"µÄÉíÓ°ÒÑ¾­²»¼ûÁË¡£\n",environment(me),me);
			if (environment(me)->query("name"))
				tell_object(me,"ÄãÀë¿ªÁË"+environment(me)->query("name")+"¡£\n");
			else tell_object(me,"ÄãÀë¿ªÁË"+environment(me)->query("short")+"¡£\n");
	}
						
	if(me->move(obj)) {
		if ( obj->name(1))
		/*log_file("static/GOTO_LOG",
			sprintf("%s(%s) goto -i %s(%s) on %s\n",
				me->name(1), geteuid(me), obj->name(1), geteuid(obj),
				ctime(time()) ) );*/
		
		if( stringp(msg = me->query("env/msg_min")) ) {
	        	if (msg!="none") message_vision(msg+"\n",me);
		} else	{
			message("vision","ÄãÑÛÇ°Ò»»¨£¬"+me->name()+"µÄÉíÓ°³öÏÖÔÚÃæÇ°¡£\n",environment(me),me);
			if (goto_inventory || !environment(me)->query("short")) tell_object(me,YEL"ÄãÉíÓ°Ò»ÉÁ£¬À´µ½ÁË"+obj->name()+NOR+YEL"µÄÌåÄÚ¡£\n"NOR);
				else tell_object(me,YEL"ÄãÉíÓ°Ò»ÉÁ£¬À´µ½ÁË"+environment(me)->query("short")+"¡£\n"NOR, me);	
		}
		return 1;
	}
	return 0;
}

int help(object me)
{
write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÎ×Ê¦Ö¸Áî¸ñÊ½ : 	goto [-i] <Ä¿±ê>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
 
Õâ¸öÖ¸Áî»á½«Äã´«ËÍµ½Ö¸¶¨µÄÄ¿±ê. Ä¿±ê¿ÉÒÔÊÇÒ»¸öliving »ò·¿¼ä
µÄµµÃû. Èç¹ûÄ¿±êÊÇliving , Äã»á±»ÒÆµ½¸úÄÇ¸öÈËÍ¬ÑùµÄ»·¾³.
Èç¹ûÓĞ¼ÓÉÏ -i ²ÎÊıÇÒÄ¿±êÊÇ living, ÔòÄã»á±»ÒÆµ½¸Ã living µÄ
µÄ inventory ÖĞ.

set msg_min/msg_mout <ÃèÊö> ¿É¹©Äã×Ô¼ºÑ¡Ôñ½øÈë/Àë¿ª·¿¼äµÄÃèÊö¡£
set msg_min/msg_mout none ½«²»ÏÔÊ¾½øÈë/Àë¿ª·¿¼äµÄĞÅÏ¢¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m 
HELP
    );
    return 1;
}
