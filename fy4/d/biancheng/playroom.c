inherit ROOM;
#include <ansi.h>
string gotit();

void create()

{
        set("short", "¿ıĞÇ¸ó");
        set("long", @LONG
Ê®ÄêÇ°ÕòÉÏ³öÁË¸ö¾ÙÈË£¬Èë¾©Ç°ÔÚÕâ¶ù¾èÁË¸ö¿ıĞÇÀÏÒ¯¡£²»¹ıÕâ¾ÙÈË»¹Ã»¼ûµ½
»ÊÉÏ£¬¾Í±»Ç¿µÁ¿³ÁËÄÔ´ü£¬´Ó´ËÔÙÃ»ÈË¹â¹Ë¡£×Ô´ÓÍòÂíÌÃĞËÆğºó£¬Õâ¶ù¾Í³ÉÁËÄÁÂí
ºº×ÓÃÇºÈ¾ÆÈ¡ÀÖ£¬»òÊÇË¤õÓ±ÈÎäµÄ³¡Ëù¡£¿ıĞÇ¸óµÄÌÃÉÏÊ÷ÁËÁ½·ù´ó´óµÄÆÁ·ç£¬ÉÏÃæ
Ğ´×Å£º[33mÊéÖĞ×ÔÓĞÑÕÈçÍõ£¬ÊéÖĞ×ÔÓĞ»Æ½ğÎİ[32m
LONG
        );
        set("exits", ([ 
		"east" : __DIR__"nstreet3",
		]));
        set("objects", ([
        	
		]) );
		
		set("item_desc", ([
			"ÆÁ·ç":		YEL"ÊéÖĞ×ÔÓĞÑÕÈçÍõ£¬ÊéÖĞ×ÔÓĞ»Æ½ğÎİ\n"NOR,
			"pingfeng":		YEL"ÊéÖĞ×ÔÓĞÑÕÈçÍõ£¬ÊéÖĞ×ÔÓĞ»Æ½ğÎİ\n"NOR,
			"Íõ":		(: gotit() :),
		]));
		
        set("coor/x",-20);
        set("coor/y",30);
        set("coor/z",0);
        set("thief",1);
		set("map","zbwest");
		setup();
}

string gotit(){
	
	object me;
	
	me = this_player();
	tell_object(me,"ÄãÅÄÅÄÄÔ´üÏëÁËÏë£¬Õâ¸ö¡°Íõ¡±×ÖºÃÏñ²»¶Ô°É¡£\n");
	tell_object(me,"Äã×ß½üÆÁ·ç×ĞÏ¸¿´¿´£¬²»´í£¬Ô­À´¡°Óñ¡±×ÖÉÏµÄÄÇµãÊ±¼ä³¤ÁË±»Ä¥µôÁË¡£\n");
	me->set_temp("marks/wanma/pingfeng",1);
	if (query("thief"))
		call_out("falling",random(10)+5, me);
	set("thief",0);
	return "";
}


int falling(object me){
	object thief;
	if (!me || environment(me)!=this_object())	return 1;
	
	thief = new(__DIR__"npc/thief");
	if (!thief)	return 1;
	thief->move(this_object());
	
	message_vision("ÆËÍ¨Ò»Éù£¬ÁºÉÏºöÈ»µôÏÂ¸öÈËÀ´¡£\n", thief);
	thief->ccommand("say ¼û¹í¼û¹í£¬ÔõÃ´¶ãµ½ÕâÀï¶¼»á±»ÈË×²µ½£¡£¡");
	thief->ccommand("say Ğ¡×Ó£¬ÄãµÄÑÛÁ¦²»´íÃ´¡£\n");
	message_vision("$N¾õµÃ×Ô¼ºÄÔºó¹ÇËÆºõ±»ÈËÃşÁËÒ»ÏÂ£¬×ĞÏ¸Ò»¿´£¬$nºÃÏñÓÖÃ»¶¯¹ı¡£\n", me, thief);
	thief->ccommand("say ²»´í£¬²»´í£¬ÄãºÜÏñÎÒ£¬ÄãºÜÏñÎÒ£¡\n");
	message_vision("$NÑÛÖéÒ»×ª£¬×ª¹ıÉíÈ¥²»Ëµ»°ÁË¡£\n", thief);
	if (!REWARD_D->riddle_check(me,"ÉñÍµÌìÏÂ") && !REWARD_D->check_m_success(me,"ÉñÍµÌìÏÂ"))
		REWARD_D->riddle_set(me,"ÉñÍµÌìÏÂ",1);
	return 1;
}
	
	
void reset(){
	object sikong;
	
	sikong = present("sikong taoxing");
	if (sikong) {
		message_vision("Ë¾¿ÕÌÍĞÇÀÁÑóÑóµØËµ£ºÃ»ÊÂ¶ùÎÒ¾Í×ßÁË¡£
Ë¾¿ÕÌÍĞÇÒ»×ªÉíÌøÉÏÎİÁºÏûÊ§ÁË¡£\n",sikong);
	destruct(sikong);	
	}
	set("thief",1);
	::reset();
}
	
