#include <ansi.h>
inherit ROOM;
int done_jiqi(object me);

//	void load_item(object me);
int	do_update(object me);
void	reset_player(object ob);

void create()
{
    set("short", HIY"·çÔÆÌì½¾ÃÅ"NOR);
    set("long", @LONG
ÕâÊÇÒ»×ù¹ÅÀÏ¶øÉñÊ¥µÄ´óÀíÊ¯ÃÅ£¬´óÔ¼½¨ÓÚ°ÙÄêÇ°¡£ÃÅÉÏ°ß°ßµãµã£¬·ç»¯²»¿°¡£
´«ËµÖĞÊÇÓñ»Ê´óµÛÁÙ·²¼Î½±ÌìÏÂ¶ùÅ®Ó¢ĞÛµÄµØ·½£¬·²ÊÇ±»¼Î½±µÄÓ¢ĞÛ¶¼³ÉÎª²»ËÀÖ®
Éí£¬ËûÃÇµÄÊÂ¼£Ç§ÍòÄêÎªÊÀÈË´«ËÌ¡£Î¢·çÏ°Ï°·÷Ãæ£¬Èç¹ûÔÚÕâÀïÍÂÄÉ£¨[37m£ô£õ£î£á[32m£©
ÌìµØÖ®ÁéÆø£¬±Ø½«¶ÔÄãµÄÎäÑ§ĞŞÑøÓĞ¼«´óÌá¸ß¡£ÓÉ´ËÏòÉÏ£¬±ãÊÇÌìÏÂÓ¢ĞÛÏòÍùµÄÕù
¶áÎäÁÖµÚÒ»ÈËµÄËùÔÚ¡ª¡ª[1;31mÌìÏÂÓ¢ĞÛ°ñ[0;32m¡£
LONG
    );
    set("exits", ([ 
	"south" : __DIR__"nwind4",
	"north" : __DIR__"jinshuihe",
	"up" : __DIR__"mirrorgallery",
      ]));
	set("no_fight",1);
	set("no_fly",1);
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",240);
    set("coor/z",0);
    set("map","fynorth");
    setup();

}

void init(){
	add_action("do_jiqi","tuna");
}

int do_jiqi(){
        object me;
        mapping buff_list, condition;
  		string *a;
  		int i;
  	      
        me = this_player();
		if (me->is_busy())	
			return notify_fail("ÄãÏÖÔÚÕıÃ¦¡£\n");
	
		"/cmds/std/remove.c"->main(me,"all");
    	
    	condition = me->query_all_condition();
    	buff_list = me->query_temp("buff");
    	if (sizeof(condition))
    		return notify_fail("ÄãÉíÓĞÒì×´£¬ÎŞ·¨¾²ĞÄÍÂÄÉ¡£\n");


		if (sizeof(buff_list)) {
			a = keys(buff_list);
			for (i=0;i<sizeof(buff_list);i++) {
				if (buff_list[a[i]])
					return notify_fail("ÄãÉíÓĞÒì×´£¬ÎŞ·¨¾²ĞÄÍÂÄÉ¡£\n");
    		}
    	}	
    	
    	if (me->query_temp("jiqi/in_tuna"))
    		return notify_fail("ÄãÕıÔÚÍÂÄÉÖĞ¡£\n");
    			
	message_vision(HIG"\nÁ¹·çÏ°Ï°£¬$NË«ÊÖĞé±§£¬ØùÁ¢ÔÚ·çÔÆÌì½¾ÃÅ£¬»º»ºÍÂÄÉµ¤ÌïÖ®Æø¡£\n"NOR,me);
	me->set_temp("jiqi/in_tuna",1);
	me->add_temp("jiqi/num",1);
	me->perform_busy(3);
	call_out("done_jiqi",4, me);
//	done_jiqi(me);
	return 1;
}

int done_jiqi(object me) {
	
	string msg;
	
	if (!me || me->is_ghost() || environment(me)!= this_object())
		return 1;
		
	if (me->query_temp("jiqi/num")>=3) {
		msg = HIR"
Ò»ÖÜÌìºó£¬ÄãÖ»¾õÄÚÄÚÍâÍâµÄÕæÆø¼¤µ´£¬È«ÉíÂöÂçÖ®ÖĞ£¬ÓĞÈçÒ»ÌõÌõ
Ë®ÒøÔÚµ½´¦Á÷×ª£¬ÊæÊÊÎŞ±È¡£Ç¡ÈçË®»ğÏà¼Ã£¬Áú»¢½»»á£¬ÉíÉÏÊıÊ®´¦
Ğş¹ØÒ»Ò»³åÆÆ£¬¾¹ÊÇ´ó¹¦¸æ³ÉÁË¡£\n\n"NOR;
		me->delete_temp("jiqi");
		do_update(me);
		if (me->query("eff_kee")>me->query("max_kee")) me->set("eff_kee",me->query("max_kee"));
		if (me->query("eff_gin")>me->query("max_gin")) me->set("eff_gin",me->query("max_gin"));
		if (me->query("eff_sen")>me->query("max_sen")) me->set("eff_sen",me->query("eff_sen"));
		if (me->query("kee")>me->query("eff_kee")) me->set("kee",me->query("eff_kee"));
		if (me->query("gin")>me->query("eff_gin")) me->set("gin",me->query("eff_gin"));
		if (me->query("sen")>me->query("eff_sen")) me->set("sen",me->query("eff_sen"));
	} else {
		msg = YEL"
Ò»ÖÜÌìºó£¬ÄãÖ»¾õÄÚÄÚÍâÍâµÄÕæÆø¼¤µ´£¬È«ÉíÂöÂçÖ®ÖĞ£¬ÓĞÈçÒ»ÌõÌõ
Ë®ÒøÔÚµ½´¦Á÷×ª£¬ÊæÊÊÎŞ±È¡£\n\n"NOR;
		me->delete_temp("jiqi/in_tuna");
	}
	tell_object(me,msg);
	me->stop_busy();
	return 1;
}


int	do_update(object me){
	
        if (!objectp(me) 
        	|| me->is_ghost())
        	return 1;
        
// ÖØĞÂ¼ÆËã¾«ÆøÉñÖµ£¬Õâ¸öÓëlogindÖĞµÄ¼ÆËãÏàÍ¬¡£	

// ĞŞ¸Äºô½Ğº¯Ê½Í³Ò»´¦Àí :: annie
		"/cmds/std/unwield.c"->main(me,"all");
		"/cmds/std/remove.c"->main(me,"all");
        "/feature/nada.c"->reset_player_status(me);
        me->save();	
        return 1;

}



