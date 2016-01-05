/* ¹¦ÄÜ -- by Silencer@fy4
	Ñ²²¶ÈÎÃâÊÂÏî£¬²éÔÄÑ²²¶Ãûµ¥¡£
*/

inherit NPC;
#include <ansi.h> 


int info1();
int info2();
int reward;
mapping *hunter;

void create()
{
        set_name("ĞÏÈñ", ({ "xing rui","rui" }) );
        set("long","
²¶Í·ĞÏÈñÔ­À´ÊÇ¾©³Ç´óïÚ¾ÖµÄ×ÜïÚÍ·£¬×ÔºÓË·ÖĞÔ­µ½¹Ø¶«ÕâÌõÏßÉÏ×îÖØÒª
µÄÈıÊ®¾ÅÂ·ÂÌÁÖºÀ½Ü£¬¶¼ÔøÔÚËûÊÖÏÂ×éÖ¯³ÉÒ»¸ö½­ºşÖĞ¿ÕÇ°Î´ÓĞµÄ³¬¼¶´ó
ïÚ¾Ö¡£½üÄêÀ´·çÔÆ³ÇÀï½­ºş³ğÉ±ÈÕÁÒ£¬¹Ù¸®ÊÆÁ¦Ê½Î¢£¬¹ÊÖØ½ğÆ¸ÇëĞÏÈñÕÆ
¹ÜÖ÷³ÖÑÃÃÅÊÂÎñ¡£¶øÌúÊÖÎŞÇéÉÏÈÎºó¶À³öÒ»ÖÄ£¬³ıÑÏÁî½ûÖ¹Ğµ¶·Íâ£¬¸ü´ó
µ¨ÈÎÓÃ½­ºşºÀ½Ü£¬ĞüÉÍ¼©²¶Ğ×·¸¡£ÄãÈôÓĞÒâ²ÎÓë£¬¿ÉÏòËûÑ¯ÎÊ[33m¼©ÄÃ[32mÖ®ÊÂ¡£
Èç¹ûÄãÒÑ¾­ÊÇÑ²²¶¶øÏëÍË³ö£¬¿ÉÏòËûÑ¯ÎÊ[33m½âÖ°[32mÒ»ÊÂ¡£ÄãÒ²¿ÉÓÃXUNBUÀ´²é¿´
µ±Ç°µÄÑ²²¶Ãûµ¥¡£\n\n");
        set("gender","ÄĞĞÔ");
	set("title", HIR"ÌúÊÖÎŞÇé"NOR);
        set("age",53);
                
        set("NO_KILL",1);
        set("combat_exp", 5000000);
	set("no_arrest",1);
	
	set("inquiry", ([
		"°ì°¸":	(: info1() :),
		"Ñ²²¶": (: info1() :),
		"xunbu":(: info1() :),
		"¼©ÄÃ": "Ñ§ÎäÖ®ÈËµ±±¨Ğ§³¯Í¢£¬Ö÷ÖÎÕıÒå£¬ÈôÄãÓĞÒâ£¬¿ÉÏòÎÒ×ÉÑ¯Ñ²²¶
Ö®ÊÂ¡£Ñ²²¶²¢·ÇÑÃÃÅ¹ÙÖ°£¬µ«Æ¾´ËÉí·İÔò¿É×·É±Ğ×·¸¡£\n",
		"jina": "Ñ§ÎäÖ®ÈËµ±±¨Ğ§³¯Í¢£¬Ö÷ÖÎÕıÒå£¬ÈôÄãÓĞÒâ£¬¿ÉÏòÎÒ×ÉÑ¯Ñ²²¶
Ö®ÊÂ¡£Ñ²²¶²¢·ÇÑÃÃÅ¹ÙÖ°£¬µ«Æ¾´ËÉí·İÔò¿É×·É±Ğ×·¸¡£\n",
		"½âÖ°": (: info2() :),
		"Ğ¶ÈÎ": (: info2() :),
		"retire": (: info2() :),
	]));
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
}
 
void init(){
	add_action("do_list","xunbu");
	::init();
}


int do_list(){
	if (this_player()->query("timer/list_hunter")+2 > time())
		return notify_fail("ĞÏÈñ²»ÄÍ·³µØËµ£ºÄã²»ÊÇ¸ÕÀ´¿´¹ıÃ´£¿\n");
	this_player()->set("timer/list_hunter",time());
	PK_D->print_hunter_list();
	return 1;
}

int info1() {
	object me, ob;
	ob = this_object();
	me = this_player();
	if (PK_D->check_list(me->query("id"),"HUNTER_LIST")) {
		message_vision("ĞÏÈñËµ£ºÄãÒÑ¾­ÊÇ¹Ù·âµÄÑ²²¶ÁË£¬»¹²»¿ìÈ¥°ì°¸£¿\n",ob);
		return 1;
	}
	
	if (PK_D->check_list(me->query("id"),"PK_LIST")) {
		message_vision("ĞÏÈñÑöÌì´ò¸ö¹ş¹şËµ£ºÇ¿µÁÏëµ±Ñ²²¶£¬×öÃÎÀ´×Å£¿\n",ob);
		return 1;
	}
	
	message_vision(CYN"
ĞÏÈñËµ£ºÑ²²¶²¢·ÇÑÃÃÅ¹ÙÖ°£¬µ«Æ¾´ËÉí·İ¿É×·É±Ğ×·¸£¬»ñÈ¡ÉÍ½ğ£¬µ«ÊÇ
Òà»áÒò´Ë¾íÈë½­ºş¶÷Ô¹£¬ÉúËÀÄÑÁÏ£¬ÄãÒªÉ÷ÖØ¿¼ÂÇ¡£\n\n"NOR,ob);
	
	if (F_LEVEL->get_level(me->query("combat_exp"))< 20) {
		message_vision(CYN"
ĞÏÈñËµ£ºÄãÑ§ÒÕÎ´¾«£¬¿ÖÅÂ²»ÄÜµ£µ±Èç´ËÖØÈÎ£¬¹ı¼¸ÄêÔÙÀ´°É£¨ÖÁÉÙĞèµÈ¼¶£²£°£©\n"NOR,ob);
		return 1;
	}
	if (PK_D->count_number("HUNTER_LIST")>=50) {
		message_vision(CYN"
ĞÏÈñËµ£ºÎÒÃÇÒÑ¾­ÓĞ×ã¹»µÄÈËÊÖÁË£¬ÄãÓÂÆø¿É¼Î£¬¹ıÒ»Õó×ÓÔÙÀ´ÉêÇë°É¡£\n"NOR,ob);
		return 1;
	}
	
	tell_object(me,"ÄãÊÇ·ñÏÂ¶¨¾öĞÄ¼ÓÈëÑ²²¶£¿£¨answer yes/no£©\n");
	me->set_temp("answer_sima",1);
	add_action("do_answer","answer");
	return 1;
}

int info2() {
	object me, ob;
	mapping player;
	me = this_player();
	ob = this_object();
	if (!(player=PK_D->check_list(me->query("id"),"HUNTER_LIST"))) {
		message_vision("ĞÏÈñËµ£ºÄãÓÖ²»ÊÇ¹Ù·âµÄÑ²²¶£¬ÕâÊÂ¶ùºÍÄãÃ»¹ØÏµ¡£\n",ob);
		return 1;
	}
	if (player["join_time"]+86400*7 >time()) {
		message_vision("ĞÏÈñËµ£ºÏëÀ´¾ÍÀ´£¬Ïë×ß¾Í×ß£¬Äã°ÑÕâ¶ùµ±Ê²Ã´µØ·½£¿£¨µ±Ñ²²¶ÖÁÉÙÒ»ÖÜ£©\n",ob);
		return 1;
	} else	{
		message_vision(CYN"
ĞÏÈñËµ£ºàÅ£¬ÄãÒ²ĞÁ¿à¶àÈÕÁË£¬ÔİÇÒÒşÍËÊıÈÕÒ²ºÃ£¬²»¹ı£¬ÄãÔÚÈÎÊ±
½á³ğÌ«¶à£¬Ê÷Óû¾²¶ø·ç²»Ö¹°¡£¬½ñºóÈÔµÃĞ¡ĞÄ¡£\n\n"NOR,ob);
		PK_D->remove_member("HUNTER_LIST",player->query("id"));
	}
	return 1;
}


int do_answer(string arg){
	object me, hunted;
	object ob;
	mapping member =([
		"name":			"unknown",
		"id":			"unknown",
		"join_time":		0,
		"rewarded":		0,
	]);
	
	me= this_player();
	ob= this_object();
	
	if (!me->query_temp("answer_sima"))
		return 0;
	
	if (!arg || (arg!="yes" && arg!="no"))
		return notify_fail("answer yes/no \n");
	
	if (arg == "yes") {
		
		if (me->query("combat_exp")<= 500000) {
			message_vision(CYN"
ĞÏÈñËµ£ºÄãÑ§ÒÕÎ´¾«£¬¿ÖÅÂ²»ÄÜµ£µ±Èç´ËÖØÈÎ£¬¹ı¼¸ÄêÔÙÀ´°É¡££¨Ğè£±£¸¼¶£©\n"NOR,ob);
			me->delete_temp("answer_sima");
			return 1;
		}
		message_vision(YEL"$N¼á¶¨µØµãÁËµãÍ·£º¿ï·öÕıÒåÄËÎÒ±²Ñ§ÎäÖ®ÈËÙíÔ¸£¬ÔÚÏÂÔ¸µ±´ËÖØÈÎ¡£\n\n"NOR,me);
		me->delete_temp("answer_sima");
		member["name"]= me->query("name");
		member["id"] = me->query("id");
		member["join_time"] = time();
		member["rewarded"]= 0;
		
		if (PK_D->count_number("HUNTER_LIST")>=50) {
		message_vision(CYN"
ĞÏÈñËµ£ºÎÒÃÇÒÑ¾­ÓĞ×ã¹»µÄÈËÊÖÁË£¬ÄãÓÂÆø¿É¼Î£¬¹ıÒ»Õó×ÓÔÙÀ´ÉêÇë°É¡£\n"NOR,ob);
		return 1;
		}
		
		PK_D->add_member("HUNTER_LIST",member);
		me->save();
		ob->ccommand("spank "+me->query("id"));
		message_vision(CYN"
ĞÏÈñÔÚ¹«ÎÄÖ½ÉÏĞ´ÏÂ$NµÄÃû×Ö£ººÃ£¬´ÓÏÖÔÚ¿ªÊ¼Äã¾Í¿ÉÒÔ¼©ÄÃ¸ñÉ±
·¸ÈËÁË¡£°ì°¸Ê¦Ò¯ÄÇ¶ùÓĞÏêÏ¸µÄÃûµ¥¡£¼Ç×¡£¬½­ºşÏÕ¶ñ£¬Äã×Ô¼ºÒ²¿ÉÄÜ»áÔâ
µ½°µÉ±£¬²»ÒªÇáÒ×ÏàĞÅÈÎºÎÈË£¬°üÀ¨ÄãµÄÍ¬ÁÅ£¡\n"NOR,me);		
		return 1;
	}
	
	tell_object(me,"ÄãÓÌÔ¥°ëÉÎ£¬Ò¡ÁËÒ¡Í·¡£\n");
	me->delete_temp("answer_sima");
	return 1;
}

