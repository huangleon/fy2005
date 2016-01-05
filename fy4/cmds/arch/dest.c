// dest.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string option, target, msg;

	object obj;

	if (!arg) return notify_fail("Ö¸Áî¸ñÊ½ : dest <Îï¼şÖ®Ãû³Æ»òµµÃû>\n" );

	if( sscanf(arg, "-%s %s", option, target)!=2 ) target = arg;

	if( option == "-r" && (string)SECURITY_D->get_status(me)=="(admin)" )
		seteuid(ROOT_UID);
	else
		seteuid(geteuid(me));

	obj = find_object(target);
	if (!obj) obj = present(target, me);
	if (!obj) obj = present(target, environment(me));
	if (!obj) obj = find_object( resolve_path(me->query("cwd"), target) );
	
	if (!objectp(obj)) 
		return notify_fail("Ã»ÓĞÕâÑùÎï¼ş....¡£\n");

	if ( userp(obj) &&  (string)SECURITY_D->get_status(me)!="(admin)" )
		return notify_fail("ÄãÃ»ÓĞ´İ»Ù¶Ô·½µÄÈ¨ÏŞ¡£\n");
	
	tell_object( me, sprintf("´İ»ÙÎï¼ş£º %O\n", obj));
	
	msg = "";
	
	if( environment(me)==environment(obj) )
	{
		if( !stringp(msg = me->query("env/msg_dest")) )
			msg = "$NÕÙ»½³öÒ»¸öºÚ¶´£¬½«$nÍÌÃ»ÁË¡£\n";
		message_vision(msg + "\n", me, obj);
	}
	else {
		msg = "$NÕÙ»½³öÒ»¸öºÚ¶´£¬°ÑÖÜÎ§ÍÌÃ»ÁË¡£\n";
		message_vision(msg + "\n", me);
	}
	
	destruct(obj);
	if(obj) 
		write("ÄãÎŞ·¨½«Õâ¸öÎï¼ş´İ»Ù¡£\n");
	else 
		write("Îï¼ş´İ»Ù³É¹¦¡£\n");

	return 1;
}

int help(object me)
{
	write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÎ×Ê¦Ö¸Áî¸ñÊ½ : 	dest [-r] <Îï¼şÖ®Ãû³Æ»òµµÃû>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

ÀûÓÃ´ËÒ»Ö¸Áî¿É½«Ò»¸öÎï¼ş(object)»òÎï¼ş¶¨Òå(class)´Ó¼ÇÒäÌåÖĞÇå³ı£¬
ÈôÇå³ıÎï¼ş¶¨Òå(¼´£ºÖ¸¶¨µµÃûµÄÇé¿öÏÂ)ÔòÏÂÒ»´Î²Î¿¼µ½Õâ¸öÎï¼şµÄÊ±ºò
»áÖØĞÂ½«Ëü±àÒë¡£

¾ßÓĞ (admin) Éí·ÖµÄÎ×Ê¦¿ÉÒÔÓÃ -r Ñ¡ÏîÒÔ ROOT_UID Éí·ÖÀ´Çå³ı±»±£
»¤µÄÎï¼şÈçÊ¹ÓÃÕß¡£

²Î¿¼×ÊÁÏ£º destruct()

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
HELP
    );
    return 1;
}
