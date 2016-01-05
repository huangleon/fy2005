// who.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// Last modification:
//		- 07/13/2001 by Daniel Q. Yu.
//
// Modified so wizard can be invisible to players.
//		- 12/02/2003 by Silencer


#include <ansi.h>
#include <net/dns.h>
#include <mudlib.h>
inherit F_CLEAN_UP;

int sort_user(object,object);
int help();

private void create() { 
	seteuid(getuid()); 
}

mixed main(object me, string arg, int remote) {
	string name, str, rule, *option;
	object *list, *ob, ob1;
	int i, opt_long,opt_number, numPlayer;
	if( (int)me->query("sen") < 50 ) {
		return notify_fail("ÄãµÄ¾«ÉñÎŞ·¨¼¯ÖĞ¡£\n");
	}
	
	if ( !wizardp(me) && me->query_temp("timer/big_cmd")+5 > time())
		return notify_fail("´ËÀàÃüÁî±È½ÏºÄ·ÑÏµÍ³×ÊÔ´£¬Ã¿ÎåÃë²ÅÄÜÖ´ĞĞÒ»´Î¡£\n");
	else
		me->set_temp("timer/big_cmd",time());
		
	if( !wizardp(me) ){
		me->receive_damage("sen", 50);
	}
	
	if(remote && sizeof(arg)<2) arg="";
	ob = filter_array(children(USER_OB),(: userp :));
	ob = filter_array(ob, (: environment($1) :));
	ob = filter_array(ob, (: $2->visible($1) :), me);
	numPlayer = sizeof(ob);
	str = HIY"\n¡ò ¡¸"+ MUD_NAME+"¡¹"HIW"Ä¿Ç°";
	rule = "";
	if(arg) {
		option = explode(arg, " ");
		i = sizeof(option);
		while( i-- ) {
			switch(option[i]) {
				case "-h": 
					return help();
				case "-l": 
					opt_long = 1;
					break;
				case "-w": 
					rule += "Î×Ê¦";
					if (wizardp(me))
						ob = filter_array(ob, (: wizardp($1) || wizhood($1) == "(immortal)" :));
					else
						ob = filter_array(ob, (: (wizardp($1) || wizhood($1) == "(immortal)") 
						&& !$1->query("wiz_invis") :));
					break;
				case "-p": 
					if(me->query("family/family_name")) {
						rule += me->query("family/family_name");
					} else {
						rule += "ÆÕÍ¨°ÙĞÕ";
					}
					ob = filter_array(ob, (: $1->query("family/family_name") == $2->query("family/family_name") :), me);
					break;
				case "-f": 
					rule += "Å®ĞÔ";
					ob = filter_array(ob, (: $1->query("gender") =="Å®ĞÔ" :));
					break;
				case "-m": 
					rule += "ÄĞĞÔ";
					ob = filter_array(ob, (: $1->query("gender") == "ÄĞĞÔ" :));
					break;
				case "-a": 
					opt_number = 1;
					break;
				case "-d": 
					rule += "¶ÏÏß";
					ob = filter_array(ob, (: $1->query_temp("netdead") :));
					break;
				default:
					if(option[i][0]=='@'){
			        	RWHO_Q->send_rwho_q(option[i][1..sizeof(option[i])],me, opt_long);
			        	write("ÍøÂ·Ñ¶Ï¢ÒÑËÍ³ö£¬ÇëÉÔºò¡£\n");
			        	return 1;
					}
					ob1 = present(option[i], environment(me));
					if(!ob1) {
						ob1 = find_player(option[i]);
					}
					if(!ob1) {
						ob1 = find_living(option[i]);
					}
					if((!ob1) && (option[i] =="me")) {
						ob1=me;
					}
					if(!ob1) {
						return notify_fail("Ã»ÓĞÕâ¸öÍæ¼Ò»ò²ÎÊı´íÎó¡£\nÖ¸Áî¸ñÊ½ : who [-h] [-l] [-w] [-p] [-f] [-m] [-a] [-d][<ID>]\n");
					}
					me = ob1; 
					if(me->query("family/family_name")) {
						rule += me->query("family/family_name");
					} else {
						rule += "ÆÕÍ¨°ÙĞÕ";
					}
					ob = filter_array(ob, (: $1->query("family/family_name") == $2->query("family/family_name") :), me);
				}
			}
		}
		str += rule + "Íæ¼ÒÓĞ£º";
        str += HIY"\n©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"NOR;      
        list = sort_array(ob,"sort_user");
        if(!sizeof(list)) {
        	str = "Ä¿Ç°ÓÎÏ·ÖĞ²¢Ã»ÓĞ" + rule + "Íæ¼Ò¡£\n";
        } else if(opt_number) {
        	str = HIY"¡¸"+ MUD_NAME+"¡¹"NOR + WHT"Ä¿Ç°¹²ÓĞ"+chinese_number(sizeof(ob))+ "Î»" + rule + "Íæ¼Ò¡£\n"NOR;
		} else if(opt_long) {
			i = sizeof(list);
			while(i--) {
				str += sprintf("%s%s%s%s %s\n",
						interactive(list[i])?(query_idle(list[i]) > 120? HIG "*" NOR:" "):HIR "#" NOR,
						list[i]->is_ghost() ? HIB"@"NOR : " ",
						list[i]->query("gender") == "Å®ĞÔ" ? "¡â" : "¡á",
						list[i]->short(1),
						list[i]->query_temp("team_name")? WHT"<"+list[i]->query_temp("team_name")+">"NOR : ""
				);				
			}
			
        	str += HIY"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"NOR;
        	str += sprintf("¹²ÓĞ%sÎ»Ê¹ÓÃÕßÁ¬ÏßÖĞ£¬ÏµÍ³¸ºµ££º%s\n\n", 
        			CHINESE_D->chinese_number(numPlayer), query_load_average());
        } else {
			i = sizeof(list);
			while(i--){
				str += sprintf("%s%s%s%-20s ", 
						interactive(list[i])?(query_idle(list[i]) > 120? HIG "*" NOR:" "):HIR "#" NOR,
						list[i]->is_ghost() ? HIB"@"NOR : " ",
						list[i]->query("gender") == "Å®ĞÔ" ? "¡â" : "¡á",
						sprintf("%s(%s)", list[i]->name(1), capitalize(list[i]->query("id")))
					);
				
				if(i%3 == sizeof(list)%3) {
					str += "\n";
				}
			}
			if(sizeof(list)%3) {
				str += "\n";
        	}
        	str += HIY"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"NOR;
        	str += sprintf("¹²ÓĞ%sÎ»Ê¹ÓÃÕßÁ¬ÏßÖĞ£¬ÏµÍ³¸ºµ££º%s\n\n", 
        			CHINESE_D->chinese_number(numPlayer), query_load_average());
        }
        
        if(remote) {
        	return str;
        } else {
        	me->start_more("", str, 0);
		}
        return 1;
}

int sort_user(object ob1, object ob2) {
	string name1, name2;
	if(wiz_level(ob1) != wiz_level(ob2)) {
		return wiz_level(ob2) - wiz_level(ob1);
	}
	name1 = ob1->query("family/family_name");
	name2 = ob2->query("family/family_name");
	if(intp(name1)) {
		name1 = "";
	}
	if(intp(name2)) {
		name2 = "";
	}
	if(name1 > name2) {
		return -1;
	}
	if(name1 < name2) {
		return 1;
	}
	return (int)ob2->query("family/generation") - (int)ob1->query("family/generation");
}

int help() {
	write("

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	who [-h] [-l] [-w] [-p] [-f] [-m] [-a] [-d] [<ID>][0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

Õâ¸öÖ¸Áî¿ÉÒÔÁĞ³öËùÓĞÔÚÓÎÏ·ÖĞµÄÍæ¼Ò¼°ÆäµÈ¼¶¡£

-h ÁĞ³ö°ïÖúÆÁÄ»¡£
-l Ñ¡ÏîÁĞ³ö½Ï³¤µÄÑ¶Ï¢¡£
-p Ö»ÁĞ³öÍ¬ÃÅÅÉµÄÍæ¼Ò¡£
-w Ö»ÁĞ³öÓÎÏ·ÖĞµÄÎ×Ê¦¡£
-f Ö»ÁĞ³öÓÎÏ·ÖĞµÄÅ®Íæ¼Ò¡£
-m Ö»ÁĞ³öÓÎÏ·ÖĞµÄÄĞÍæ¼Ò¡£
-a Ö»ÁĞ³öµ±Ç°ÓÎÏ·ÖĞÍæ¼ÒµÄ×ÜÈËÊı¡£
-d Ö»ÁĞ³öµ±Ç°ÓÎÏ·ÖĞ´¦ÓÚ¶ÏÏß×´Ì¬ÖĞµÄÍæ¼Ò¡£

<ID> ÁĞ³ö<ID>´ú±íÍæ¼ÒËùÊôÃÅÅÉµÄÍæ¼Ò¡£

"HIG"*"NOR" ±íÊ¾"HIG"·¢´ô"NOR"ÖĞ£¬"HIR"#"NOR" ±íÊ¾"HIR"¶ÏÏß"NOR"ÖĞ£¬"HIB"@"NOR" ±íÊ¾"HIB"¹íÆø"NOR"ÖĞ¡£

Îª½ÚÊ¡ÏµÍ³×ÊÔ´£¬´ËÃüÁîÃ¿ÎåÃë²ÅÄÜÖ´ĞĞÒ»´Î¡£

Ïà¹ØÖ¸Áî£º finger 
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m 

");
	return 1;
}
