// enable.c
//	07/20/2003-- added all kinds of temp parameters
//			-- Silencer@fengyun.com

#include <ansi.h>
inherit F_CLEAN_UP;

mapping valid_types = ([
//		"array":        "Õó·¨",
		"animal-training":  "ÑµÊŞÊõ",
		"axe":     	"¸«·¨",
		"blade":        "µ¶·¨",
		"dagger":       "¶Ì±øÈĞ",
		"dodge":        "ÉÁ¶ãÊõ",
		"force":        "ÄÚ¹¦",
		"fork":         "²æ·¨",
		"hammer":       "´¸·¨",
		"iron-cloth": 	"Ó²¹¦",
		"literate": 	"¶ÁĞ´",
		"magic":        "·¨Êõ",
		"move":         "Çá¹¦",
		"parry":        "ÕĞ¼Ü",
	//	"perception":   "Ìı·çÊõ",
		"scratching":   "·ûÖ®Êõ",
		"cursism" :	"½µÍ·Êõ",
		"spells":       "ÖäÎÄ",
		"staff":        "ÕÈ·¨",
		"stealing":     "ÃîÊÖÊõ",
		"sword":        "½£·¨",
		"throwing":     "°µÆ÷",
		"unarmed":      "È­½Å",
		"whip":     	"±Ş·¨",
		"herb":		"Ò©µÀ",
		"spear":        "Ç¹·¨",
		"musket":				"»ğÇ¹",

		"theorem":        "ÎŞÓĞÖ®Êõ",

]);

int main(object me, string arg) {
	mapping skill_map;
	string *types, *skill_o, *skill, *usr_skill, ski, map_to;
	int i, j, modify, skill_level;
	string s, skill_name,enable_skill, attack_skill;
	object weapon;
	
	seteuid(getuid());
	
	if(!arg) {
		skill_map = me->query_skill_map();
		if(!mapp(skill_map) || sizeof(skill_map)==0 ) {
			return notify_fail("ÄãÏÖÔÚÃ»ÓĞÊ¹ÓÃÈÎºÎÌØÊâ¼¼ÄÜ¡£\n");
		}
		skill_o = keys(valid_types);
		skill  = sort_array( skill_o, (: strcmp :) );
		
		if (me->query_temp("apply/attack")) {
			if (weapon = me->query_temp("weapon")) 
				attack_skill = weapon->query("skill_type");
			else
				attack_skill = "unarmed";
		}
				
		write("ÒÔÏÂÊÇÄãÄ¿Ç°Ê¹ÓÃÖĞµÄÌØÊâ¼¼ÄÜ¡£\n");
		write("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
		for(i=0; i<sizeof(skill); i++) {
			if(undefinedp(valid_types[skill[i]])) {
			    	map_delete(skill_map, skill[i]);
			    	continue;
			}
			if(!me->query_skill(skill[i])) {
				continue;
			}
			modify = me->query_skill_modifier(skill[i]);
			if (skill[i] == attack_skill)
				modify += me->query_temp("apply/attack");
			
			printf("  %-24s£º %-15s  ÓĞĞ§µÈ¼¶£º%3d%5s\n" NOR, 
		    		valid_types[skill[i]] + " (" + skill[i] + ")",
		    		undefinedp(skill_map[skill[i]]) ? "ÎŞ" : 
					SKILL_D(skill_map[skill[i]])->name(),
				me->query_skill(skill[i]),
		    		modify==0? "": (modify>0? HIG"+"+(string)(modify): HIR""+(string)(modify))
		    	);
		}
		write("\nÓĞĞ§µÈ¼¶ = »ù±¾¼¼ÄÜ/2 + ÌØÊâ¼¼ÄÜ*Îä¹¦ÏµÊı\n");
		write("ÁÁÂÌÉ«»òºìÉ«µÄÊı×Ö±íÊ¾À´×ÔÓÚÎäÆ÷¡¢Perform¡¢»òAdvanced-skillµÄĞŞÕıÖµ¡£\n\n");
		write("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
		return 1;
	}
	
	if(arg=="?") {
		write("ÒÔÏÂÊÇ¿ÉÒÔÊ¹ÓÃÌØÊâ¼¼ÄÜµÄÖÖÀàºÍÄã»áµÄÌØÊâ¼¼ÄÜ£º\n");
		skill = sort_array(keys(valid_types), (: strcmp :) );
		if (me->query_skills())
			usr_skill = keys(me->query_skills());
		for(i=0; i<sizeof(skill); i++) {
			s = sprintf("%6s (%s)", valid_types[skill[i]], skill[i]);
			if (me->query_skills())
				usr_skill = filter_array(keys(me->query_skills()), (: SKILL_D($1)->valid_enable($2) :), skill[i]);
			if(sizeof(usr_skill)) {
				for(j=0; j<sizeof(usr_skill); j++) {
					printf("  %-20s : %s (%s)\n", s, SKILL_D(usr_skill[j])->name(), usr_skill[j]);
					s = " ";
				}  
			} else {
				printf("  %-20s\n", s);	
			}
		}
		return 1;
	}

	if (arg)
	if (sscanf(arg, "%s %s", ski, map_to)!=2)
	if (sscanf(arg,"%s",skill_name)==1 && skill_name!="none") {
		if(!find_object(SKILL_D(skill_name)) && file_size(SKILL_D(skill_name)+".c")<0) 
			return notify_fail("¡¸" + skill_name + "¡¹£¬ÓĞÕâÖÖ¼¼ÄÜÂğ£¿\n");	
		if( !(skill_level=me->query_skill(skill_name,1)))
			return notify_fail("Äã²¢Ã»ÓĞÑ§¹ıÕâÏî¼¼ÄÜ»òÊÇ¼¼ÄÜµÈ¼¶ÎªÁã¡£\n");
		
		if(undefinedp(valid_types[skill_name])) 
			return notify_fail("´ËÏî¼¼ÄÜ²»ÊÇ»ù±¾¼¼ÄÜÖÖÀà£¬ÓÃ enable ? ¿ÉÒÔ²é¿´ÓĞÄÄĞ©ÖÖÀà¡£\n");
		enable_skill=me->query_skill_mapped(skill_name);
					
		write("ÒÔÏÂÊÇÄã²éÑ¯µÄÌØÊâ¼¼ÄÜ×´¿ö¡£\n\n");
		modify = me->query_skill_modifier(skill_name);
		
		if (me->query_temp("apply/attack")) {
			if (weapon = me->query_temp("weapon")) 
				attack_skill = weapon->query("skill_type");
			else
				attack_skill = "unarmed";
			if ( skill_name == attack_skill)
				modify += me->query_temp("apply/attack");
		}
		
		printf("  %-24s£º %-15s  ÓĞĞ§µÈ¼¶£º%3d%5s\n\n" NOR, 
		    		valid_types[skill_name] + " (" + skill_name + ")",
		    		(!me->query_skill_mapped(skill_name)) ? "ÎŞ" : 
					SKILL_D(enable_skill)->name(),
				me->query_skill(skill_name),
				modify==0? "": (modify>0? HIG"+"+(string)(modify): HIR""+(string)(modify))
		    	);
		return 1;
	}

	
	if(sscanf(arg, "%s %s", ski, map_to)!=2) {
		return notify_fail("Ö¸Áî¸ñÊ½£ºenable <¼¼ÄÜÖÖÀà> <¼¼ÄÜÃû³Æ>|none\n");
	}
	
	if(undefinedp(valid_types[ski])) {
		return notify_fail("Ã»ÓĞÕâ¸ö¼¼ÄÜÖÖÀà£¬ÓÃ enable ? ¿ÉÒÔ²é¿´ÓĞÄÄĞ©ÖÖÀà¡£\n");
	}
	
	if(map_to=="none") {
		me->map_skill(ski);
		me->reset_action();
		write("Í£Ö¹Ê¹ÓÃ¡¸" + valid_types[ski] + "¡¹µÄÌØÊâ¼¼ÄÜ¡£\n");
		return 1;
	} else if(map_to==ski) {
		write("¡¸" + SKILL_D(ski)->name() + "¡¹ÊÇËùÓĞ" + valid_types[ski] + "µÄ»ù´¡£¬²»ĞèÒª enable¡£\n");
		return 1;
	}
	
	if(!find_object(SKILL_D(map_to)) && !load_object(SKILL_D(map_to))) {
		return notify_fail("¡¸" + map_to + "¡¹£¬ÓĞÕâÖÖ¼¼ÄÜÂğ£¿\n");	
	}

	if(!me->query_skill(map_to, 1)) {
		return notify_fail("Äã²»»áÌØÊâ¼¼ÄÜ¡¸" + SKILL_D(map_to)->name() + "¡¹¡£\n");
	}

	if(!me->query_skill(ski, 1)) {
		return notify_fail("ÄãÁ¬¡¸" + SKILL_D(ski)->name() + "¡¹¶¼Ã»Ñ§»á£¬ÈçºÎÊ¹ÓÃÌØÊâ¼¼ÄÜ¡¸" + SKILL_D(map_to)->name() + "¡¹£¿\n");
	}
/*	if (map_to == "tanzhi-shentong" && ski=="parry" && !me->query("fy41/hs_tz_parry") ) {
		return notify_fail("ÄãÏÖÔÚ»¹Î´ÔøÁìÎò°Ñµ¯Ö¸ÉñÍ¨ÔËÓÃÔÚÕĞ¼ÜÉÏµÄ¿Ú¾÷¡£\n");
	}*/
	if(!SKILL_D(map_to)->valid_enable(ski)) {
		return notify_fail("ÌØÊâ¼¼ÄÜ¡¸" + SKILL_D(map_to)->name() + "¡¹²»ÄÜÓÃÔÚ¡¸" + valid_types[ski] + "¡¹ÉÏ¡£\n");
	}
		
	if(ski=="dodge" && ANNIE_D->check_buff(me,"dodgeup"))
		return notify_fail("ÄãÕıÔÚÊ¹ÓÃÉÁ¶ãÊõµÄÌØÊâ¼¼ÄÜ£¬±ØĞëµÈÆäĞ§¹ûÏûÊ§ºó²ÅÄÜ×ª»»´ËÎä¹¦¡£\n");
	
	if(ski=="parry" && ANNIE_D->check_buff(me,"parryup"))
		return notify_fail("ÄãÕıÔÚÊ¹ÓÃÕĞ¼ÜµÄÌØÊâ¼¼ÄÜ£¬±ØĞëµÈÆäĞ§¹ûÏûÊ§ºó²ÅÄÜ×ª»»´ËÎä¹¦¡£\n");
	
	if(ski=="iron-cloth" && ANNIE_D->check_buff(me,"ironup"))
		return notify_fail("ÄãÕıÔÚÊ¹ÓÃÓ²¹¦µÄÌØÊâ¼¼ÄÜ£¬±ØĞëµÈÆäĞ§¹ûÏûÊ§ºó²ÅÄÜ×ª»»´ËÎä¹¦¡£\n");
	
	if(ski=="force" && (ANNIE_D->check_buff(me,"gks") || ANNIE_D->check_buff(me,"powerup")))
		return notify_fail("ÄãÕıÔÚÊ¹ÓÃÄÚ¹¦µÄÌØÊâ¼¼ÄÜ£¬±ØĞëµÈÆäĞ§¹ûÏûÊ§ºó²ÅÄÜ×ª»»´ËÎä¹¦¡£\n");

	if (ski == "theorem")
	{
		if(me->query("timer/last_theorem") + 1800 > time())
			return notify_fail(CYN"ÎŞÓĞÖ®ÊõÃ¿ÈıÊ®·ÖÖÓÖ»ÄÜÇĞ»»Ò»´Î¡£\n"NOR);
		me->set("timer/last_theorem",time());
	}
		
	me->map_skill(ski, map_to);
	me->reset_action();
	write("¿ªÊ¼Ê¹ÓÃ¡¸" + valid_types[ski] + "¡¹µÄÌØÊâ¼¼ÄÜ¡¸" + SKILL_D(map_to)->name() + "¡¹¡£\n");
	
	if( ski=="magic" ) {
		write("Äã¸ÄÓÃÁíÒ»ÖÖÄ§·¨Ïµ£¬ÁéÁ¦±ØĞëÖØĞÂ¶ÍÁ¶¡£\n");
		me->set("atman", 0);
		me->force_status_msg("atman");
	} else if( ski=="force" ) {
		write("Äã¸ÄÓÃÁíÒ»ÖÖÄÚ¹¦£¬ÄÚÁ¦±ØĞëÖØĞÂ¶ÍÁ¶¡£\n");
		me->set("force_factor",0);
		me->set("force", 0);
		me->force_status_msg("force");
	} else if( ski=="spells" ) {
		write("Äã¸ÄÓÃÁíÒ»ÖÖÖäÎÄÏµ£¬·¨Á¦±ØĞëÖØĞÂĞŞÁ¶¡£\n");
		me->set("mana", 0);
		me->force_status_msg("mana");
	}
	
	return 1;
}



int help(object me) {
	write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	enable
		enable ?
		enable <¼¼ÄÜÖÖÀà>
		enable <¼¼ÄÜÖÖÀà> <¼¼ÄÜÃû³Æ> | none[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

Õâ¸öÖ¸ÁîÈÃÄãÖ¸¶¨ËùÒªÓÃµÄ¼¼ÄÜ£¬ĞèÖ¸Ã÷¼¼ÄÜÖÖÀàºÍ¼¼ÄÜÃû³Æ¡£
Èç¹û²»¼Ó²ÎÊıÔò»áÏÔÊ¾³ö¼¼ÄÜÖÖÀà¼°ÄãÄ¿Ç°ËùÊ¹ÓÃµÄ¼¼ÄÜÃû³Æ £¬
Èç¹û¼ÓÒ»¸ö ? »áÁĞ³öËùÓĞÄÜÊ¹ÓÃÌØÊâ¼¼ÄÜµÄ¼¼ÄÜÖÖÀà£¬
Èç¹ûÖ±½Ó¸ú¼¼ÄÜÖÖÀà»áÁĞ³öÄ¿Ç°¸Ã¼¼ÄÜµÄ£å£î£á£â£ì£å×´Ì¬¡£
 
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
 
HELP
        );
        return 1;
}
 
