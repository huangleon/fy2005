// Silencer@FY4

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ÄÎºÓÇÅ");
        set("long", @LONG
Ðí¶àÈËÖ»ÖªµÀÄÎºÎÇÅ£¬È´²»ÖªµÀÄÎºÓÇÅ£¬ÆäÊµÄÎºÓÇÅÃûÀ´×ÔÄÎºÓ£¬ÄÎºÓ¹á´©µØ
¸®£¬µ½Õâ¶ùÉÏÃæÓÐÒ»×ùÊ¯ÇÅ£¬ÇÅµÄÒ»¶ËÁ¬×ÅÆ½°²µÀ£¬ÁíÒ»¶Ë[37mÃÔÎí[32mçÔÈÆ£¬¾¹ÒÑÎÞÁËÈ¥
Â·¡£Ê«ÔÆ¡º·çÃÖ»ÆÈªÂ·£¬ÈË¹ýÄÎºÎÇÅ£¬ÈýÉúÊ¯ÁôºÞ£¬ÍûÏçÌ¨ÔµÈÆ¡»£¬ÕâÀïÊÇµØ¸®Óë
ÈË¼äµÄ½»½ÓÖ®´¦£¬¹ýÁËÄÎºÎÇÅ£¬±ãÊÇÀ´ÉúÁË¡£
LONG
        );
        set("exits", ([
		"north" : __DIR__"pingan",
		
        ]) );
        
        set("item_desc", ([
        	"ÃÔÎí": "ÄÎºÎÇÅµÄ¾¡Í·ÃÔÎíçÔÈÆ£¬ÈôÊÇÄãÏÂ¶¨¾öÐÄ£¬¾Í×ß½øÈ¥°É(dash mist)¡£\n",
        	"mist":  "ÄÎºÎÇÅµÄ¾¡Í·ÃÔÎíçÔÈÆ£¬ÈôÊÇÄãÏÂ¶¨¾öÐÄ£¬¾Í×ß½øÈ¥°É(dash mist)¡£\n",
        ]));
        
        set("objects", ([
                __DIR__"npc/yurui" : 1,
        ]) );
        
	set("coor/x",0);
	set("coor/y",-100);
	set("coor/z",-190);
	set("no_fight",1);
	set("no_meal","ÄãºöÈ»·¢ÏÖ¿ÚÖÐµÄÊ³ÎïÒûË®³ÉÁË¿àÉ¬µÄ×ÇÄà£¬¸Ï¿ìÍÛÍÛµØÍÂÁË³öÀ´¡£\n");
	setup();
}


void	init()
{
	add_action("do_dash","dash");
	return;
}


int	do_dash(string arg)
{
	string *revive_loc= ({   AREA_FY"church",   AREA_GUANWAI"tower",});
	object me, cloth;
	mapping buff;
	
	if (!arg)
		return notify_fail("ÄãÒªÍùÄÄ¶ù´³£¿\n");
	
	if (arg!= "mist" && arg!= "ÃÔÎí")
		return notify_fail("Äã²»ÄÜ×ß½ø"+arg+"È¥¡£\n");
			  	   	
   	me = this_player();
	
	if (!me->query_temp("marks/ready_incar"))
		return notify_fail("Äã»¹Ã»ºÈÃÏÆÅÌÀ£¬ÄÇÀïÄÜ¹»»¹ÑôÄØ£¿\n");
		
	if (ANNIE_D->check_buff(me,"mengpo-soup")>0)
		return notify_fail("ÄãÉÏÊÀµÄ¶÷Ô¹Î´¾¡£¬»¹ÊÇÔÙµÈÒ»Õó¶ù°É¡££¨ÐèÒªµÈµ½"HIB"µØÓòÓÄ»ê"NOR"µÄ×´Ì¬ÏûÊ§£©\n");
			
	me->delete_temp("marks/ready_incar");  	
   	message_vision(WHT"\n$NºÝÁËºÝÐÄ£¬Ò»Í·´³½øÁËÃÔÎíÖ®ÖÐ£¬Ö»Ìý¹í¿ÞÀÇº¿£¬Õ£ÑÛ¼äÊ§ÁË×ÙÓ°¡£¡£¡£¡£\n"NOR,me);
   	
   	if (!REWARD_D->check_m_success(me,"åÛÓÎµØ¹¬")) {
   		REWARD_D->riddle_done(me,"åÛÓÎµØ¹¬",50,1);
   		me->add("combat_exp",1500);
   		tell_object(me,WHT"ÄãµÄ½­ºþÀúÁ·Ìá¸ßÁË¡£\n"NOR);
   	}
   	   	
   	if(me->is_ghost()){
		me->reincarnate();
		cloth = new("/obj/armor/cloth");
		if(objectp(cloth)) {
			cloth->move(me);
			cloth->wear();
		}
		
		// 5 mins NO_PK mark
/*		buff =
			([
				"caster":me,
				"who": 	 me,
				"type":	"no-pk",
				"att":	"bless",
				"name":	"ÒþÍË½­ºþ",
				"buff1": "NO_PK",
				"buff1_c":1,
				"time":  300,
				"buff_msg":""NOR,
			]);
		ANNIE_D->buffup(buff);*/
				
//		me->unconcious();
		if (F_LEVEL->get_level(me->query("combat_exp"))< 11)
			me->move(AREA_FY"church");
		else
			me->move(revive_loc[random(sizeof(revive_loc))]);
		me->set("startroom", base_name(environment(this_player())));
		me->perform_busy(1);
		message("vision",
        	        "ÄãºöÈ»·¢ÏÖÇ°Ãæ¶àÁËÒ»¸öÈËÓ°£¬²»¹ýÄÇÈËÓ°ÓÖºÃÏñÒÑ¾­ÔÚÄÇÀï\n"
            	    "ºÜ¾ÃÁË£¬Ö»ÊÇÄãÒ»Ö±Ã»·¢¾õ¡£\n", environment(this_player()), this_player());
   	
   		me->set("kee",10);
   		me->set("gin",10);
   		me->set("sen",10);
   		me->set("force",0);
		me->set("atman",0);
		me->set("mana",0);
		me->set("death_revive",time());
		me->force_status_msg("all");
		me->status_msg("all");
			
		// THis just serves as a timer, all checks use query(death_time), so even relogin can't bypass
		buff =
		([
			"caster":me,
			"who":me,
			"type":"revive-sickness",
			"att":"curse",
			"name":"»¹»ê¡¤ÐéÈõ²»¿°",
			"buff1":"revive-sickness",
			"buff1_c": 1,
			"time":180,
			"buff_msg":"$NÉí×ÓÐéÈõµ½ÁË¼«µã£¬Á¬Õ¾¶¼Õ¾²»ÎÈÁË¡£\n"NOR,
		]);
		ANNIE_D->buffup(buff);
   	   	
   	}	
  	return 1;
		
}
	