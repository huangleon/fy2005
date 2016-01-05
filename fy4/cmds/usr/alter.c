// TIE@FY3
//	½«nicknameºÍdescribe²¢Èë´ËÖ¸Áî --- Silencer@fy4

#include <ansi.h>

inherit F_CLEAN_UP;

int do_nickname(object me, string arg);
int do_describe(object me, string arg);

int main(object me, string arg)
{
	object obj;
	string id, verb,replace;
	string tmp;
	if( !arg ) 
		return notify_fail("Ö¸Áî¸ñÊ½ : alter <Óû¸ÄµÄ¶«Î÷> <Óû¸ÄµÄ¿îÏî> <¸Ä±äµÄÄÚÈİ>\n");
	
	if( sscanf(arg, "%s %s %s", id, verb, replace)!=3 )
		return notify_fail("Ö¸Áî¸ñÊ½ : alter <Óû¸ÄµÄ¶«Î÷> <Óû¸ÄµÄ¿îÏî> <¸Ä±äµÄÄÚÈİ>\n");
	
	if (id == "self") {
		if (verb == "nickname")	{
			if (do_nickname( me, replace))
				write("¸Ä±ä³É¹¦£¡\n");
			return 1;
		}
		if (verb == "description")	{
			if (do_describe( me, replace))
				write("¸Ä±ä³É¹¦£¡\n");
			return 1;
		}
		return notify_fail("Ö¸Áî¸ñÊ½ : alter self <nickname »ò description> <¸Ä±äµÄÄÚÈİ>\n");
	}
	
	if (me->query_temp("timer/big_cmd")+1 > time())
		return notify_fail("´ËÀàÃüÁî±È½ÏºÄ·ÑÏµÍ³×ÊÔ´£¬Ã¿Ò»Ãë²ÅÄÜÖ´ĞĞÒ»´Î¡£\n");
	else
		me->set_temp("timer/big_cmd",time());
	
	if( !objectp(obj = present(id, me)) )
		return notify_fail("ÄãÉíÉÏÃ»ÓĞÕâÑù¶«Î÷¡£\n");
	if(obj->query("owner") != me->query("id"))
		return notify_fail("ÄãÖ»ÄÜ¸Ä±ä×ÔÔìÎïÆ·ÉÏµÄÃèÊöĞÅÏ¢¡£\n");
	switch(verb) {
		case "desc":
			if(!CHINESE_D->check_chinese(replace)) return notify_fail("ÃèÊö±ØĞëÊÇÖĞÎÄ¡£\n");
			obj->set("long",replace+"\n");
			break;
		case "wield_msg" :
			if(strsrch(replace,"$N") == -1 || strsrch(replace,"$n") == -1)
			return notify_fail("ÃèÊö±ØĞëº¬ÓĞ$NºÍ$n¡£\n");
			tmp = replace_string(replace,"$N","");
			tmp = replace_string(tmp,"$n", "");
			if(!CHINESE_D->check_chinese(tmp)) return notify_fail("ÃèÊö±ØĞëÊÇÖĞÎÄ¡£\n");		
			obj->set("wield_msg",replace+"\n");
			break;
		case "unwield_msg" :
			if(strsrch(replace,"$N") == -1 || strsrch(replace,"$n") == -1)
                        return notify_fail("ÃèÊö±ØĞëº¬ÓĞ$NºÍ$n¡£\n");
                        tmp = replace_string(replace,"$N","");
                        tmp = replace_string(tmp,"$n", "");
                        if(!CHINESE_D->check_chinese(tmp)) return notify_fail("ÃèÊö±ØĞëÊÇÖĞÎÄ¡£\n");
                        obj->set("unwield_msg",replace+"\n");
                        break;
		case "wear_msg" :
                        if(strsrch(replace,"$N") == -1 || strsrch(replace,"$n") == -1)
                        return notify_fail("ÃèÊö±ØĞëº¬ÓĞ$NºÍ$n¡£\n");
                        tmp = replace_string(replace,"$N","");
                        tmp = replace_string(tmp,"$n", "");
                        if(!CHINESE_D->check_chinese(tmp)) return notify_fail("ÃèÊö±ØĞëÊÇÖĞÎÄ¡£\n");
                        obj->set("wear_msg",replace+"\n");
                        break;
		case "remove_msg" :
                        if(strsrch(replace,"$N") == -1 || strsrch(replace,"$n") == -1)
                        return notify_fail("ÃèÊö±ØĞëº¬ÓĞ$NºÍ$n¡£\n");
                        tmp = replace_string(replace,"$N","");
                        tmp = replace_string(tmp,"$n", "");
                        if(!CHINESE_D->check_chinese(tmp)) return notify_fail("ÃèÊö±ØĞëÊÇÖĞÎÄ¡£\n");
                        obj->set("unequip_msg",replace+"\n");
                        break;
		default: 
			return notify_fail("Ö¸Áî¸ñÊ½ : alter <Óû¸ÄµÄ¶«Î÷> <Óû¸ÄµÄ¿îÏî> <¸Ä±äµÄÄÚÈİ>\n");
		
	}
	obj->save();
	write("¸Ä±ä³É¹¦£¡\n");
	me->add("sen",-10);
	return 1;
}


int do_nickname(object me, string arg)
{
	if( !arg ) {
		write("Ö¸Áî¸ñÊ½ : alter self nickname <ÄÚÈİ>\n");
		return 0;
	}
		
	if( strlen(arg) > 40 ) {
		write("ÄãµÄ´ÂºÅÌ«³¤ÁË£¬ÏëÒ»¸ö¶ÌÒ»µãµÄ¡¢ÏìÁÁÒ»µãµÄ¡£\n");
		return 0;
	}

	if (arg=="none") {
		me->delete("nickname");
		return notify_fail("ÄãÈ¡ÏûÁË×Ô¼ºµÄ´ÂºÅ¡£\n");
	}

	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);

	me->set("nickname", arg + NOR);
//	write("Ok.\n");
	return 1;
}

int do_describe(object me, string arg)
{
	string *txt;

	if( !arg ) {
		write("Ö¸Áî¸ñÊ½ : alter self description <ÄÚÈİ>\n");
		return 0;
	}
	
	if( arg=="none")
	{
		me->delete("long");
		write("ÃèÊöÉ¾³ıÍê±Ï¡£\n");
		return 1;
	}
	
	if (sizeof(arg)>140)	{
		write("Äã¶Ô×Ô¼ºµÄÃèÊöÌ«³¤ÁË£¬Çë¿ØÖÆÔÚ140¸ö×ÖÖ®ÄÚ¡£\n");
		return 0;
	}
	
	txt = explode(arg, "\n");
	if( sizeof(txt) > 8 ) {
		write("Çë½«Äú¶Ô×Ô¼ºµÄÃèÊö¿ØÖÆÔÚ°ËĞĞÒÔÄÚ¡£\n");
		return 0;
	}
	arg = implode(txt, "$NOR$\n") + "\n";

	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);

	me->set("long", arg + NOR);
//	write("Ok.\n");
	return 1;
}


int help (object me)
{
	write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	alter <Óû¸ÄµÄ¶«Î÷> <Óû¸ÄµÄ¿îÏî> <¸Ä±äµÄÄÚÈİ>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

´ËÖ¸ÁîÊÇÒÔÍù°æ±¾ÖĞalter¡¢nick¡¢describeµÄ×ÛºÏ£º

<Ò»>
Èç¹ûÒª¸ÄµÄÊÇ×Ô¼ºµÄ´ÂºÅ£º	alter self nickname 	<ÄÚÈİ>
Èç¹ûÒª¸ÄµÄÊÇ±ğÈË¿´×Ô¼ºÊ±µÄÃèÊö£ºalter self description 	<ÄÚÈİ>
Èç¹ûÄãÏëÈ¥³ı×Ô¼ºµÄ´ÂºÅ/ÃèÊö£¬¿ÉÒÔÊ¹ÓÃ 
alter self nickname none  »ò   alter self description none	

ÄãÈç¹ûÏ£ÍûÔÚ´ÂºÅ/ÃèÊöÖĞ
Ê¹ÓÃ ANSI µÄ¿ØÖÆ×ÖÔª¸Ä±äÑÕÉ«£¬¿ÉÒÔÓÃÒÔÏÂµÄ¿ØÖÆ×Ö´®£º

$BLK$ - ºÚÉ«		$NOR$ - »Ö¸´Õı³£ÑÕÉ«
$RED$ - ºìÉ«		$HIR$ - ÁÁºìÉ«
$GRN$ - ÂÌÉ«		$HIG$ - ÁÁÂÌÉ«
$YEL$ - ÍÁ»ÆÉ«		$HIY$ - »ÆÉ«
$BLU$ - ÉîÀ¶É«		$HIB$ - À¶É«
$MAG$ - Ç³×ÏÉ«		$HIM$ - ·ÛºìÉ«
$CYN$ - À¶ÂÌÉ«		$HIC$ - ÌìÇàÉ«
$WHT$ - Ç³»ÒÉ«		$HIW$ - °×É«
 
ÆäÖĞÏµÍ³×Ô¶¯»áÔÚ×Ö´®Î²¶Ë¼ÓÒ»¸ö $NOR$¡£

<¶ş>
Èç¹ûÒª¸ÄµÄÊÇ×ÔÖÆÎïÆ·ÉÏµÄĞÅÏ¢£º
	alter <Óû¸ÄµÄ¶«Î÷> <Óû¸ÄµÄ¿îÏî> <¸Ä±äµÄÄÚÈİ>			
	
	¿ÉÒÔ¸ÄµÄ¿îÏî°üÀ¨£º
		desc  		ÎïÆ·µÄÃèÊö
		wield_msg 	×°±¸±øÆ÷µÄÃèÊö
		unwield_msg	·ÅÏÂ±øÆ÷µÄÃèÊö
		wear_msg	´©ÉÏ¿ø¼×µÄÃèÊö
		remove_msg	ÍÑÏÂ¿ø¼×µÄÃèÊö

±ÈÈçÄãÓĞÒ»°ÑÑª½£(redsword)£º
	alter redsword wield_msg Ö»¼ûºì¹âÒ»ÏÖ£¬$NÒÑ°Ñ$nÎÕÔÚÊÖÖĞ	

	ÒÔºóÃ¿µ±Äã×°±¸redsword(wield redsword)£¬´ó¼Ò¶¼»á¿´µ½£º
	£¢Ö»¼ûºì¹âÒ»ÏÖ£¬°¢ÌúÒÑ°ÑÑª½£ÎÕÔÚÊÖÖĞ£¢	

Òª×¢ÒâµÄÊÇ£º²»Òª°Ñ×ÔÖÆÎïÆ·µÄÃû×Ö½Ğ×ö¡°self¡±¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
HELP

);
        return 1;
}
