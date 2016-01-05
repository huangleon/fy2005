
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object room,room2,who,*mem;
	int pwd, i, j,mm,count, max_exp, combatexp;
	string name; 
	object *dungeon_list;
	
	seteuid(getuid());
	
	// ÓÉÓÚÎÒÃÇ²»ÔÚÊµ¼Ê£Ò£ï£ï£íÖÐÁô¼ÇºÅ£¬ËùÓÐ½øÈë²Ù×÷±ØÐëÓÉÖ÷ÈË½øÐÐ
	// This is the primary quest owner 
	if (me->query("private_maze/destination") == base_name(environment(me))+".c"
		 && me->query("quest/quest")== "´¹óÒÀÏÉ®µÄÈÎÎñ" ) {
		
		if (me->query("quest_time")+ me->query("quest/duration")< time()) {
			tell_object(me,"Ì«ÍíÁË£¬µÐÈËÒÑ¾­ÎÅ·ç×ªÒÆ£¬Õâ¸öÈÎÎñÊ§°ÜÁË¡£\n");
			return 1;
		}
		
		if (!arg)
			who = me;
			else who = present(arg, environment(me));
		if (!who)
			return notify_fail("ÄãµÄÖÜÎ§Ã»ÓÐÕâ¸öÈË¡£\n");
		
		if (!userp(who))
			return notify_fail("´ËÈË²»Ô¸Òâ³ÉÎªÄãµÄ»ï°é¡£\n");
				
		// If it's the first time, prepare the instance parameters for other people's entry.
		if (me->query("private_maze/create"))	{
			
		// ½«Ô­À´µÄDungeonÏú»Ù
			dungeon_list = children("/obj/dungeon/standardmaze");
//		CHANNEL_D->do_sys_channel("sys",sprintf("%O\n", dungeon_list));
			mm = sizeof(dungeon_list);
			for (i=0;i<mm;i++){
				if (dungeon_list[i]->query_owner()== me->query("id")) {
					dungeon_list[i]->refresh_maze();
				}
			}
						
			room2=load_object("/obj/dungeon/standardmaze/"+me->query("id")+"/entry");			
			if (!room2)	
				room2="/obj/dungeon/standardmaze"->query_maze_room(me->query("id")+"/entry");
			if (!room2) 
				return notify_fail("Oops.Please report to wizards. \n");	
		
			me->set("private_maze/create",0);	// ÒòÎªÔÚÏú»Ù£í£á£ú£åÊ±ÎÒÃÇÔÊÐíownerÍË³ö£¬ËùÒÔ±ØÐëÏÞÖÆcreateµÄ´ÎÊý£®
						
			// Maze_exp ¾ö¶¨ÓÚ¶ÓÎéÖÐ×î¸ßµÄ¾­ÑéÖµ£¬ÕâÑù¶ÓÎéÖÐµÄÈË¿Ï¶¨ÄÜ°ïÃ¦
			mem = pointerp(me->query_team()) ? me->query_team() : ({ me });
    		j = sizeof (mem);
    		while (j--)	{
				if (mem[j]) {
		    		max_exp = mem[j]->query("combat_exp");
		    		if (max_exp > 15000000) max_exp = 15000000;
		    		combatexp = (max_exp>combatexp) ? max_exp : combatexp;
				}
    		}
			room2->set("maze/exp", 	combatexp); 			

			room2->set("maze/type", me->query("private_maze/type"));
			room2->set("maze/exit", me->query("private_maze/destination"));
			room2->set("maze/name", me->query("private_maze/orig_name"));
			room2->set("maze/sig",	me->query("private_maze/maze"));
			room2->set("maze/npc_killed",me->query("private_maze/carried_npc"));
				me->delete("private_maze/carried_npc");
			
					room2->query("maze/sig")->set_link_exit_room(room2->query("maze/exit"));
					room2->query("maze/sig")->set_link_entry_room(room2->query("maze/exit"));

			room2->set("maze/boss",		"/obj/dungeon/boss");	
			room2->set("maze/blocker",	"/obj/dungeon/blocker");	
			room2->set("maze/npc_pfm_chance", me->query("private_maze/difficulty"));
			
			tell_object(me,sprintf("ÈÎÎñÇøÓò%s´´½¨³É¹¦£¬ÔÊÐí½øÈë×î¸ßµÈ¼¶Îª%s£¬×î¶àÈËÊý%sÈË¡£\n",
						me->query("private_maze/orig_name"),
						chinese_number(F_LEVEL->get_level(room2->query("maze/exp")) +5),
						chinese_number(room2->query("maze/type"))));
							
		}
		
		room2 = find_object("/obj/dungeon/standardmaze/"+me->query("id")+"/entry");
		if (!room2 && !me->query("private_maze/create"))
			return notify_fail("ÄãµÄÈÎÎñÒÑ¾­½áÊø»òÕß¹ýÊ±£¬ÎÞ·¨ÔÙ½øÈë£¯´´½¨ÐÂµØÇø¡£\n");
	
		if (F_LEVEL->get_level(who->query("combat_exp")) > F_LEVEL->get_level(room2->query("maze/exp")) +5)
			return notify_fail("½øÈë¸ÃÈÎÎñÇøµÄ×î¸ßµÈ¼¶²»ÄÜ³¬¹ý"+ (F_LEVEL->get_level(room2->query("maze/exp"))+5)+"¡£\n");
		
		count = sizeof(room2->get_players());
		if (count >= room2->query("maze/type"))
			return notify_fail("´ËÈÎÎñÉõÎª»úÃÜ£¬²»ÒËÈË¶à£¬ÒÑ²»ÄÜÔÙ½øÈëÁË¡£\n");
		
//		me->set_temp("maze_entry",environment(me));	
		
		if (who->is_busy()|| who->is_fighting())
			return notify_fail("´ËÈËÕý´¦ÔÚÃ¦ÂÒÖÐ£¬ÎÞ·¨ÒÆ¶¯¡£\n");
					
		who->move(room2);
		tell_object(who, WHT"\n½øÈë"+me->name()+"µÄÇøÓò£º" + me->query("private_maze/orig_name")+ "£¬ÄãµÄÈÎÎñÊÇ³¹µ×´Ý»ÙÕâÀï¡£\n"NOR);
		if (who!=me)
			tell_object(me,WHT+who->name()+"ÒÑ½øÈëÄãµÄÈÎÎñÇøÓò¡£\n"NOR);
		
//		tell_object(me,"file name is " + base_name(room2));		
		return 1;	
	}
	
	return 0;	
	
}

int help (object me)
{
	write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[1;36m		entermaze [name] 	
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
 
¸ÃÃüÁî¿É½øÈë½øÈë×Ô¼º»òËûÈËµÄÈÎÎñÇøÓò£¬ÈÎÎñÓÉ´¹óÒÀÏÈË¸ø³ö¡£
½Óµ½ÈÎÎñºóÑ°ÕÒµ½Ïà¹ØµØµã£¬Ê¹ÓÃ¸ÃÃüÁîºó±ãÄÜ½øÈëÒ»¸ö¶ÀÁ¢µÄÇøÓò

¶ÔÓÚ³ÖÓÐÈÎÎñÕßÀ´Ëµ£¬Ö»ÐèÊäÈë entermaze ±ãÄÜ½øÈë

²»Í¬µÄÈÎÎñÇø¿ÉÄÜÓÐ²»Í¬µÄÈËÊýÏÞÖÆ£¬ÔÚ¸ø³öÈÎÎñÊ±»áÓÐÏà¹ØËµÃ÷¡£
ÈËÊýÉÏÏÞ¸ßµÄ£¬ÄÑ¶È¾Í»á´óÒ»Ð©£¬×ÔÈ»½±ÀøÒ²¸ü¸ß¡£

Èç¹ûÄã¾õµÃÈÎÎñÌ«ÄÑ£¬Ïë½ÐÉÏÐ©ÅóÓÑÀ´ÖúÕó£¬¿ÉÒÔÔÚÈë¿Ú´¦Ö´ÐÐÖ¸Áî
entermaze id	ÆäÖÐidÊÇÅóÓÑµÄÓ¢ÎÄÃû×Ö

´ËÈÎÎñÃ»ÓÐ×é¶ÓÏÞÖÆ£¬Èç¹û·¢ÏÖÌ«ÄÑ£¬¿ÉÒÔËæÊ±À­¸öÅóÓÑÀ´°ïÃ¦£¬ÔÚ
Èë¿Ú´¦Ö´ÐÐÖ¸Áî
entermaze id	ÆäÖÐidÊÇÅóÓÑµÄÓ¢ÎÄÃû×Ö
µ±È»£¬ÅóÓÑµÄ¾­ÑéµÈ¼¶²»ÄÜ±ÈÄãµÄÈÎÎñÒªÇó¸ßÌ«¶à¡£
Íê³ÉÈÎÎñºó£¬½±Àø½«ÓÉµ±Ê±´¦ÔÚ¸ÃÈÎÎñÇøµÄËùÓÐÈË·ÖÏí£¬ÈôÊÇµ¥ÈËÈÎ
Îñ£¬Ò²¿ÉÒÔÈÃÈË°ïÃ¦£¬µ±È»£¬Äã×Ô¼º¾ÍµÃ²»µ½½±ÀøÁË¡£

ÈÎÎñÇøÒ»°ã´æÔÚ£±£µ£­£³£°·ÖÖÓ£¬Ê±¼äµ½»òÕßÍê³Éºó×Ô¶¯Ïú»Ù£¬Ïú»Ù
ºóËùÓÐÈË¡¢Ê¬ÌåÒÆ¶¯µ½Èë¿Ú·¿¼ä¡£


[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m    
HELP
	);
	return 1;
}

