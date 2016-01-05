
// set.c

#define MAX_ENV_VARS    20
#include <ansi.h> 
inherit F_CLEAN_UP;

int help(object me);
int main(object me, string arg)
{
    int i;
    string term, *terms, *wiz_only;
    mixed data;
    mapping env;

    if (arg) arg = replace_string(arg, "/", "");
    wiz_only = ({"invisibility", "immortal"});

    if( me != this_player(1) ) return 0;

    env = me->query("env");

    if( !arg || arg=="" ) {
	write("ÄãÄ¿Ç°Éè¶¨µÄ»·¾³±äÊıÓĞ£º\n");
	if( !mapp(env) || !sizeof(env) )
	    write("\tÃ»ÓĞÉè¶¨ÈÎºÎ»·¾³±äÊı¡£\n");
	else {
	    terms = keys(env);
	    for(i=0; i<sizeof(terms); i++)
		printf("%-20s  %O\n", terms[i], env[terms[i]]);
	}
	return 1;
    }

    if( sscanf(arg, "%s %s", term, data)!=2 ) {
		term = arg;
		data = "YES";
    }

    //      if(term == "wimpy") return notify_fail("ÇëÓÃWIMPYÕâ¸öÖ¸Áî¡£\n"); 

    if( term && term!="" ) {
		if( mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS )
		    return notify_fail("ÄãÉèµÄ»·¾³±äÊıÌ«¶àÁË£¬ÇëÏÈÓÃ unset É¾µô¼¸¸ö°É¡£\n");
		sscanf(data, "%d", data);
		if(!wiz_level(me) && (member_array(term, wiz_only) != -1))
		    return notify_fail("Ö»ÓĞÎ×Ê¦²ÅÄÜÊ¹ÓÃÕâ¸öÉè¶¨¡£\n");
		    
		if (term=="msg_mout" || term=="msg_min"){
		    if (!stringp(data)) return 0;
		    data = replace_string(data, "$BLK$", BLK);
		    data = replace_string(data, "$RED$", RED);
		    data = replace_string(data, "$GRN$", GRN);
		    data = replace_string(data, "$YEL$", YEL);
		    data = replace_string(data, "$BLU$", BLU);
		    data = replace_string(data, "$MAG$", MAG);
		    data = replace_string(data, "$CYN$", CYN);
		    data = replace_string(data, "$WHT$", WHT);
		    data = replace_string(data, "$HIR$", HIR);
		    data = replace_string(data, "$HIG$", HIG);
		    data = replace_string(data, "$HIY$", HIY);
		    data = replace_string(data, "$HIB$", HIB);
		    data = replace_string(data, "$HIM$", HIM);
		    data = replace_string(data, "$HIC$", HIC);
		    data = replace_string(data, "$HIW$", HIW);
		    data = replace_string(data, "$NOR$", NOR);
		    data+= NOR;
		}
		if (term && data)			
		if (term == "savemyass"){
			if (!stringp(data))	
				return notify_fail("savemyass ºóÃæÖ»ÄÜ¸úÃüÁî£¬¸úÊı×ÖÃ»ÓĞÒâÒå¡£\n");
			if (strsrch(data,"quit")!=-1)
				return notify_fail("·çÔÆÕ½¶·ÖĞ²»ÄÜÍË³ö£¬´Ë²ÎÊıÃ»ÓĞÒâÒå¡£\n");
		}
		
		if(term == "wimpy") //return notify_fail("ÇëÓÃWIMPYÕâ¸öÖ¸Áî¡£\n"); 
		    if( !intp(data) || data <0 || data >99  )
			return notify_fail("WIMPYºóµÄ²ÎÊıÇëÉèÖÃ0-99ÄÚµÄÄ³Ò»ÊıÖµ¡£\n");
		
		if (term == "e_money" && !REWARD_D->check_m_success(me,"ËÄº£½ğ¿¨"))
			return notify_fail("Äã»¹²»³ÖÓĞËÄº£½ğ¿¨£¬ÎŞ·¨ÏíÊÜ¸ÃÏîÒµÎñ¡£\n");
		
		if (term == "target" && me->query_temp("timer/lost_target")+ 20 > time())
			return notify_fail("ÄãÄÔÖĞÒ»Æ¬»ìÂÒ£¬ÔİÊ±ÎŞ·¨ÕıÈ·µØËø¶¨Ä¿±ê¡£\n");
			
		me->set("env/" + term, data);
		printf("Éè¶¨»·¾³±äÊı£º%s = %O\n", term, data);
		return 1;
    }
    return 1;
}


int help(object me)
{
	write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : set ±äÊıÃû [±äÊıÖµ][0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
Äã¿ÉÒÔÓÃ set Ö¸ÁîÉè¶¨Ò»Ğ©ÓĞÓÃµÄ»·¾³±äÊı£¬ÕâĞ©±äÊıÒ²»áËæÖøÄãµÄ
ÈËÎï±»´¢´æÏÂÀ´£¬Èç¹ûÓĞ²»ĞèÒªµÄ»·¾³±äÊı£¬¿ÉÒÔÓÃ unset É¾³ı¡£
ÏêÏ¸µÄÊ¹ÓÃ·½·¨Çë¿´ help set ¼° help unset¡£

ÒÔÏÂÊÇÄ¿Ç°ÓĞÓÃµÄ»·¾³±äÊı£º

brief		<ÈÎºÎ·ÇÁãµÄÖµ>	ÒÆ¶¯Ê±Ö»¿´ËùÔÚµØ¼ò¶ÌµÄÃû³Æ£¬Èç¹û
				ÄúµÄÍøÂ·ËÙ¶È²»ÊÇºÜ¿ì£¬»òÕßÊÇ¶ÔÇøÓò
				ÒÑ¾­Ê®·ÖÊìÏ¤£¬½¨ÒéÄú´ò¿ª briefÒÔ¼õ
				ÇáÍøÂ·¸ºµ£¡£
brief2				ÒÆ¶¯Ê±Ö»¿´ËùÔÚµØ¼ò¶ÌµÄÃû³ÆºÍÈËºÍÎï¡£
brief3				ÒÆ¶¯Ê±Ö»¿´ËùÔÚµØ¼ò¶ÌµÄÃû³ÆºÍÈËÎï¼°³ö¿Ú¡£
				
wimpy		<°Ù·Ö±È>	µ±ÄúµÄ¾«ÆøÉñµÍì¶Õâ¸ö°Ù·Ö±ÈÊ±¾Í»á×Ô¶¯Ö´
				ĞĞsavemyassËùÖ¸¶¨µÄÃüÁî¡£Èç¹ûsavemyass
savemyass	<ÈÎºÎÖ¸Áî>	Ã»ÓĞÉèÖÃ£¬Ôò×Ô¶¯ÈÃÄã³¢ÊÔÌÓÀëµ±Ç°Î»ÖÃ¡£
				
no_tell		<id/all>	Ê¹Íæ¼Ò£¨id£©»òËùÓĞÍæ¼Ò£¨all£©¶¼ÎŞ·¨
				ºÍÄãËµ»°¡£

no_give         <1 »ò 0>	Èç¹ûÊÇ1£¬½«²»½ÓÊÜÈÎºÎÀ´×ÔÓÚÆäËûÍæ¼ÒµÄÍâ
				À´ÎïÆ·¡£È±Ê¡ÖµÎª0¡£				
				
revive          <1 »òÕß 0>      Èç¹ûÊÇ1£¬ËûÈË¿ÉÀûÓÃĞÄÊ¶ÉñÍ¨µÈ°ïÖú
				Äã¸´»î£¬Èç¹ûÊÇ0Ôò²»ÄÜ¡£È±Ê¡ÉèÖÃ0£¬
				Ã¿´Î¸´»îºó¸´Áã¡£
	
equip_msg 	<1£¬2 »òÕß 3>	´ËÖ¸ÁîµÄÄ¿µÄÊÇÎªÁË¼õÉÙÆµ·±µÄ´©´÷
				ÍÑĞ¶Ë¢ÆÁ¡£Èç¹ûÉèÎª£±£¬Äã½«¿´²»µ½×Ô
				¼º×°±¸£¯È¥³ıÎäÆ÷×°±¸µÄĞÅÏ¢£»Èç¹ûÊÇ
				£²£¬Äã½«¿´²»µ½±ğÈË×°±¸£¯È¥³ıÎäÆ÷×°
				±¸µÄĞÅÏ¢£»Èç¹ûÊÇ3£¬Á½¸ö¶¼¿´²»µ½¡£
				Îª½ÚÊ¡ÏµÍ³×ÊÔ´£¬ĞÂÈËµÇÂ½Ê±×Ô¶¯ÉèÎª2¡£
							
savemymoney     <1 »ò 0>	Èç¹ûÊÇ1£¬É±Ìì½¾µÄ½±Àø½«Ö±½Ó´æÈëÄãµÄ
				ÒøĞĞÕËºÅ¡£	

ability				½«QuestµÄ½±Àø×ªÎªÄÜÁ¦µã

e_money		<1 »ò 0>	Èç¹ûÊÇ1£¬ÂòÂô½«Ö±½Ó´ÓÒøĞĞ×ªÕË£¬¸Ã¹¦ÄÜ
				Ö»ÄÜÔÚËÄº£½ğ¿¨¼¤»îºóÊ¹ÓÃ¡£

target		<id>		Éè¶¨¹¥»÷¶ÔÏó

dmg_msg		<1 »ò 0>	Èç¹ûÊÇ1£¬ÏµÍ³½«Êä³öÒ»ÏµÁĞ×´Ì¬ĞÅÏ¢

no_cbm		<1 »ò 0>	ÆÁ±ÎËùÓĞ´ò¶·ĞÅÏ¢

no_others_cbm   <1 »ò 0>	ÆÁ±ÎËûÈË´ò¶·ĞÅÏ¢

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
HELP
		);
	return 1;
}
