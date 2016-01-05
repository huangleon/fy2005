#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "¶¥Â¥");
    set("long", @LONG

	[45m[1;33mÎä	Ñ§	ÖØ	µØ	ÏÐ	ÈË	Äª	Èë[2;37;0m

ÏÂÃæÌù×ÅÒ»ÕÅ¸æÊ¾£¨[37m£ó£é£ç£î[32m£©

LONG
    );
    
	set("no_fight",1);
	set("no_fly",1);
	set("exits", ([
	"down" : __DIR__"jssju2",
      ]));

     set("item_desc", ([
		"sign": @TEXT
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m

Îª¹ÄÀø¹ã´óÎäÁÖÐÂÐã¶àÑ§ÎäÒÕ¡¢¶à×÷³¢ÊÔ£¬±¾´¦Ìá¹©ÒµÎñ¿É½«ËùÑ§µ½µÄÎäÑ§
¼¼ÄÜÓëËù»¨·ÑµÄÇ±ÄÜµãÈÚ»á¹áÍ¨£¬×ÔÓÉ½»»»¡£

±¾´¦½»Ò×Á¦Çó¼òÃ÷£¬ÔÚÕâÀïÄã¿ÉÒÔ¸ÉÈý¼þÊÂ£º
£±£®ÓÃcheckÃüÁî¼ì²é¸÷¸ö¼¼ÄÜÄÜ·µ»Ø¶àÉÙÇ±ÄÜ£¬¸ñÊ½Îª£ºcheck ¼¼ÄÜÓ¢ÎÄÃû
£²£®ÓÃpayÃüÁî½»¸¶ÊÖÐø·Ñ£¬»¨·ÑµÄ»Æ½ðµÈÓÚÄãµÈ¼¶¡£½»·Ñºó£¬Àë¿ª£¨°üÀ¨×ß
    ¿ª»òÕß¶ÏÏß£©Ç°¿ÉÒÔÈÎÒâÊ¹ÓÃrefundÃüÁî£¬ÎÞÐè½øÒ»²½½»·Ñ¡£
£³£®½»·Ñºó£¬¿ÉÊ¹ÓÃrefundÃüÁî£¬¸ñÊ½Îª£ºrefund ¼¼ÄÜÓ¢ÎÄÃû

×¢ÒâÊÂÏî£º1¡£Àë¿ªÒÔºó£¬ÐèÒªÖØÐÂ½»·Ñ¡£
          2¡£·µ»Ø»á°ÑÄãÔÚµ±Ç°¼¼ÄÜÉÏÑ§Ï°£¬ÑÐ¾¿Ëù»¨µÄÇ±ÄÜÍêÈ«·µ»Ø


[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
TEXT
      ]) );

    set("objects", ([
	
    ]) );
	
    set("coor/x",-40);
    set("coor/y",80);
    set("coor/z",30);
    set("map","fynorth");
    setup();
}

void init(){
	
	add_action("do_pay","pay");
	add_action("do_check","check");
	add_action("do_refund","refund");
	add_action("do_answer","answer");
}


int do_check(string arg){
	object me;
	int pot, level,i;
	string *limit;
	
	me = this_player();
		
	if (!arg)	return notify_fail("ÄãÒª²éÑ¯ÄãÑ§¹ýµÄÄÇÒ»Ïî¼¼ÄÜ£¿\n");
	
	if (me->query_skill(arg,1)<1)
		return notify_fail("¸ÃÏî¼¼ÄÜ²»´æÔÚ»òÕßÄãÃ»ÓÐÑ§¹ý¸ÃÏî¼¼ÄÜ¡£\n");
	
	pot = me->query("annie/skill_cost/"+arg);
	level = me->query_skill(arg,1);
	
	tell_object(me,WHT"ÄãÒÑ¾­ÕÆÎÕÁË"+level+"¼¶"+ SKILL_D(arg)->name()+"£¨"+arg+"£©\n"NOR);	
	tell_object(me,HIR"ÄãÔÚ¸Ã¼¼ÄÜÉÏ¹²»¨·ÑÁË"+pot+"µãÇ±ÄÜ£¬\n"NOR);
	
	if (SKILL_D(arg)->refundable()!="none"){ 
		if (SKILL_D(arg)->refundable()=="attr")
			return notify_fail("¸Ã¼¼ÄÜÉæ¼°µ½ÈËÎïÊôÐÔ±ä»¯£¬ÎÞ·¨»Ø¸´³ÉÇ±ÄÜ¡£\n");
		limit = SKILL_D(arg)->refundable();	
		for (i=0;i<sizeof(limit);i++){
			level = me->query_skill(limit[i],1);
			tell_object(me,"¸Ã¼¼ÄÜÎª"+SKILL_D(limit[i])->name()+"£¨"+limit[i]+"£©µÄ»ù´¡£ºÄãÓµÓÐ"+level+"¼¶¡£\n");
		}
		tell_object(me,HIW"Î¨ÓÐ½«ËùÓÐ¹ØÁªÎä¹¦ÏÈÐÐÏ´È¥ºó²ÅÄÜÏ´È¥´Ë¼¼ÄÜ¡£\n"NOR);
	}
	else
		tell_object(me,HIR"Èç¹ûÄãÑ¡Ôñ refund £¬Õâ½«ÊÇÄãËùÄÜ¹»ÄÃ»ØµÄÇ±ÄÜµãÊý¡£\n"NOR);
		
	return 1;
		
}


int do_pay(){
	
	object me;
	int level;
	
	me = this_player();
	
	if (me->query_temp("marks/refund_enable"))
		return notify_fail("ÄãÒÑ¾­¸¶¹ýÊÖÐø·ÑÁË£¬ÇëÊ¹ÓÃrefundÃüÁî¸Ä±ä¼¼ÄÜ¡£\n");
		
	level = F_LEVEL->get_level(me->query("combat_exp"));
	tell_object(me,"refund ÐèÒª»Æ½ð" + level + "Á½£¬×Ô¶¯´ÓÇ®×¯×ªÕË£¬ÄãÊÇ·ñÔ¸Òâ£¿£¨answer yes/no£©\n");
	
	me->set_temp("marks/jssju3_pay",1);
	
	return 1;
}


int do_answer(string arg){
	
	object me;
	int level;
	
	me= this_player();
	
	level = F_LEVEL->get_level(me->query("combat_exp"));
	
	if (!me->query_temp("marks/jssju3_pay"))
		return notify_fail("Ê²Ã´£¿\n");
	
	if (arg == "no") {
		me->delete_temp("marks/jssju3_pay");
		return notify_fail("Äã¾ö¶¨²»Ö´ÐÐ refund ÁË¡£\n");
		}
	
	if (arg !="yes" )
		return notify_fail("Çë»Øµ½answer yes »òÕß answer no\n");
	
	me->delete_temp("marks/jssju3_pay");
			
	if (me->query("deposit")< level*10000)
		return notify_fail("refund ÐèÒª»Æ½ð"+ level +"Á½£¬ÄãµÄÇ®×¯´æ¿î²»¹»Õâ¸öÊýÄ¿¡£\n");

	me->add("deposit",-level*10000);
	tell_object(me,HIR"¸¶¿îÍê±Ï£¬Ç®×¯×ª×ß"+ level + "Á½»Æ½ð£¬Äã¿ÉÒÔÊ¹ÓÃ refund ÃüÁîÁË¡£
"NOR YEL"×¢ÒâÊÂÏî£ºÖ»Òª²»Àë¿ªÕâ¸ö·¿¼ä£¬Äã¿ÉÒÔ¶à´ÎÖ´ÐÐ refund ÃüÁî£¬¸Ä±ä¶à¸ö¼¼ÄÜ£¬
µ«Ò»µ©ÄãÀë¿ª´ËµØ£¬Ôò±¾´Î½»Ò×½áÊø£¬ÏÂÒ»´Î refund ÐèÒªÖØÐÂ½»¿î¡£\n"NOR);	
	me->set_temp("marks/refund_enable",1);
	return 1;
}

int do_refund(string arg){
	
	object me;
	int pot, level, mark, i;
	string *limit;
	
	me = this_player();
	
	if (!me->query_temp("marks/refund_enable"))
		return notify_fail("ÇëÏÈÊÇÓÃpayÃüÁî½»¸¶ÊÖÐø·Ñ¡£\n");
		
	if (me->query_temp("timer/refund")+2 > time())
		return notify_fail("Ö´ÐÐ¸ÃÃüÁîÇë¼ä¸ôÁ½Ãë¡£\n");
				
	if (!arg)	return notify_fail("ÄãÒª·µ»ØÄãÑ§¹ýµÄÄÇÒ»Ïî¼¼ÄÜ£¿\n");
	
	if (me->query_skill(arg,1)<1)
		return notify_fail("¸ÃÏî¼¼ÄÜ²»´æÔÚ»òÕßÄãÃ»ÓÐÑ§¹ý¸ÃÏî¼¼ÄÜ¡£\n");
	
	if (!SKILL_D(arg)->refundable()) 
		return notify_fail(HIW"ÏµÍ³¹æ¶¨£¬´ËÏî¼¼ÄÜÎÞ·¨»Ø¸´³ÉÇ±ÄÜ¡£\n"NOR);

	mark = 0;
	if (SKILL_D(arg)->refundable()!="none"){ 
		if (SKILL_D(arg)->refundable()=="attr")
			return notify_fail("¸Ã¼¼ÄÜÉæ¼°µ½ÈËÎïÊôÐÔ±ä»¯£¬ÎÞ·¨»Ø¸´³ÉÇ±ÄÜ¡£\n");
		limit = SKILL_D(arg)->refundable();	
		for (i=0;i<sizeof(limit);i++){
			level = me->query_skill(limit[i],1);
			if (level >=1) mark = 1;
			tell_object(me,"¸Ã¼¼ÄÜÎª"+SKILL_D(limit[i])->name()+"£¨"+limit[i]+"£©µÄ»ù´¡£ºÄãÓµÓÐ"+level+"¼¶¡£\n");
		}
		if (mark)
			return notify_fail(HIW"Î¨ÓÐ½«ËùÓÐ¹ØÁªÎä¹¦ÏÈÐÐÏ´È¥ºó²ÅÄÜÏ´È¥´Ë¼¼ÄÜ¡£\n"NOR);
	}

	pot = me->query("annie/skill_cost/"+arg);
	level = me->query_skill(arg,1);
	
	tell_object(me,WHT"ÄãÔø¾­ÕÆÎÕÁË"+level+"¼¶"+ SKILL_D(arg)->name()+"£¨"+arg+"£©£¬ÏÖÒÑÇåÁã¡£\n"NOR);	
	tell_object(me,HIR"ÄãÔÚ¸Ã¼¼ÄÜÉÏ¹²»¨·ÑÁË"+pot+"µãÇ±ÄÜ£¬ÏÖÔÚÈ«²¿·µ»Ø¡£\n"NOR);
	tell_object(me,"Äã¿ÉÒÔ¼ÌÐø refund ÆäËû¼¼ÄÜ£¬Èç¹ûÄãÒÔÈÎºÎ·½Ê½Àë¿ª´ËµØ£¬Ôò¸Ã´Î¹ý³Ì½áÊø¡£\n");
	
	me->add("learned_points", -pot);
	
	me->delete("annie/skill_cost/"+arg);
	me->delete_skill(arg);
	me->reset_action();
	
	log_file("REFUND_LOG", 
					sprintf("(%s)%s refund %d¼¶%s£¬Ç±ÄÜ»Ö¸´%d¡£\n",
   					ctime(time()), 
   					me->name(1)+"("+ me->query("id")+")", 
					level,
					arg,
					pot,
				));
	me->save();			
	me->set_temp("timer/refund",time());				
	return 1;	
	
}


int valid_leave(object me, string dir)
{
	me->delete_temp("marks/jssju3_pay");
	me->delete_temp("marks/refund_enable");
	return ::valid_leave(me, dir);
}

