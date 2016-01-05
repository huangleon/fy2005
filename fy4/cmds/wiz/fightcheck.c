// smash.c 2-22-95
 
#include "/doc/help.h"
#include <ansi.h>
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	string arg2, para, list;
	
	if (!arg)	return notify_fail("fightcheck <-²ÎÊý> NPCÃû\n");
	para = "all";
	
	if (sscanf(arg,"-%s %s",para,arg2)==2){
		arg = arg2;
	}
			
	ob = present(arg, environment(me));
	if (!ob) return notify_fail("ÄãÉí±ßÃ»ÓÐÕâ¸öNPC¡£\n");
	
	tell_object(me,WHT"NPC "+arg+" ×´¿ö·ÖÎö£º\n"NOR);
	
	write("======================================================\n");
	switch (para) {
		case "hate":		
					list = sprintf("Ô÷ºÞÁÐ±í£º%O\n",ob->query_hate_list());
					list += sprintf("Êµ¼ÊÔ÷ºÞÁÐ±í£º%O\n", ob->query_hate_list2());
					list += sprintf(YEL"µ±Ç°ÔÚÕ½¶·ÖÐµÄÔ÷ºÞ×î¶à¶ÔÏó£º%O\n"NOR,ob->query_max_hate());
					break;
		case "damage":	
					list = sprintf("ÉËº¦ÁÐ±í£º%O\n", ob->query_damage_list());
					list += sprintf("×ÛºÏ¶ÓÎéÉËº¦ÁÐ±í£º%O\n", ob->query_combined_damage_list());
					list += sprintf(YEL"µ±Ç°ÁìÏÈ¶ÓÎé£º%O\n"NOR,ob->query_max_damage_dealer());
					break;
		case "all":		
					list = sprintf("Ô÷ºÞÁÐ±í£º%O\n", ob->query_hate_list());
					list += sprintf("Êµ¼ÊÔ÷ºÞÁÐ±í£º%O\n", ob->query_hate_list2());
					list += sprintf(YEL"µ±Ç°ÔÚÕ½¶·ÖÐµÄÔ÷ºÞ×î¶à¶ÔÏó£º%O\n"NOR,ob->query_max_hate());
					list += sprintf("ÉËº¦ÁÐ±í£º%O\n", ob->query_damage_list());
					list += sprintf("×ÛºÏ¶ÓÎéÉËº¦ÁÐ±í£º%O\n", ob->query_combined_damage_list());
					list += sprintf(YEL"µ±Ç°ÁìÏÈ¶ÓÎé£º%O\n"NOR,ob->query_max_damage_dealer());
	}

	write(list);
	write("======================================================\n");
	return 1;
}
 
int help(object me)
{
   write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÎ×Ê¦Ö¸Áî¸ñÊ½ :  fightcheck <-²ÎÊý> NPC
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
   
µ÷ÊÔ¼à²âÖ¸Áî£¬¼ì²éNPCµÄÒ»ÏµÁÐÊÜÉË¡¢Ô÷ºÞÇé¿ö

²ÎÊý£º-hate	¼ì²éÔ÷ºÞ£»-damage ¼ì²éÉËº¦
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
HELP
   );
   return 1;
}
