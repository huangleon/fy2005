// enable.c
//      07/20/2003-- added all kinds of temp parameters
//                      -- Silencer@fengyun.com

#include <ansi.h>
inherit F_CLEAN_UP;

mapping valid_types = ([
//              "array":        "Õó·¨",
                "animal-training":  "ÑµÊŞÊõ",
                "axe":          "¸«·¨",
                "blade":        "µ¶·¨",
                "dagger":       "¶Ì±øÈĞ",
                "dodge":        "ÉÁ¶ãÊõ",
                "force":        "ÄÚ¹¦",
                "fork":         "²æ·¨",
                "hammer":       "´¸·¨",
                "iron-cloth":   "Ó²¹¦",
                "literate":     "¶ÁĞ´",
                "magic":        "·¨Êõ",
                "move":         "Çá¹¦",
                "parry":        "ÕĞ¼Ü",
        //      "perception":   "Ìı·çÊõ",
                "scratching":   "·ûÖ®Êõ",
                "cursism" :     "½µÍ·Êõ",
                "spells":       "ÖäÎÄ",
                "staff":        "ÕÈ·¨",
                "stealing":     "ÃîÊÖÊõ",
                "sword":        "½£·¨",
                "throwing":     "°µÆ÷",
                "unarmed":      "È­½Å",
                "whip":         "±Ş·¨",
                "herb":         "Ò©µÀ",
                "spear":        "Ç¹·¨",
                "musket":				"»ğÇ¹",
]);

int main(object me, string arg) {
        mapping skill_map;
        string *types, *skill_o, *skill, *usr_skill, ski, map_to;
        int i, j, modify, skill_level;
        string s, skill_name,enable_skill, attack_skill;
        object weapon;
        object who;
        
        if (!arg)
			return notify_fail("¸ñÊ½£ºenable ĞÕÃû\n");

        seteuid(getuid());
        who = find_player(arg);
        if (!who)
        	who = find_living(arg);
        if (!who)
            return notify_fail("ÕÒ²»µ½Ò®¡­¡­\n");
        
                skill_map = who->query_skill_map();
                if(!mapp(skill_map) || sizeof(skill_map)==0 ) {
                        return notify_fail("ÄãÏÖÔÚÃ»ÓĞÊ¹ÓÃÈÎºÎÌØÊâ¼¼ÄÜ¡£\n");
                }
                skill_o = keys(valid_types);
                skill  = sort_array( skill_o, (: strcmp :) );
                
                if (who->query_temp("apply/attack")) {
                        if (weapon = who->query_temp("weapon")) 
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
                        if(!who->query_skill(skill[i])) {
                                continue;
                        }
                        modify = who->query_skill_modifier(skill[i]);
                        if (skill[i] == attack_skill)
                                modify += who->query_temp("apply/attack");
                        
                        printf("  %-24s£º %-15s  ÓĞĞ§µÈ¼¶£º%3d%5s\n" NOR, 
                                valid_types[skill[i]] + " (" + skill[i] + ")",
                                undefinedp(skill_map[skill[i]]) ? "ÎŞ" : 
                                        SKILL_D(skill_map[skill[i]])->name(),
                                who->query_skill(skill[i]),
                                modify==0? "": (modify>0? HIG"+"+(string)(modify): HIR""+(string)(modify))
                        );
                }
                write("\nÓĞĞ§µÈ¼¶ = »ù±¾¼¼ÄÜ/2 + ÌØÊâ¼¼ÄÜ*Îä¹¦ÏµÊı\n");
                write("ÁÁÂÌÉ«»òºìÉ«µÄÊı×Ö±íÊ¾À´×ÔÓÚÎäÆ÷¡¢Perform¡¢»òAdvanced-skillµÄĞŞÕıÖµ¡£\n\n");
                write("¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª\n");
                return 1;
        
        
        return 1;
}



int help(object me)
{
write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÎ×Ê¦Ö¸Áî¸ñÊ½ : 	enable2 ÈËÃû[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
 
´ËÃüÁîÈÃÄã¼ì²éNPCµÄEnableÇé¿ö£¬ÒÔÀûÓÚ²âÊÔ¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m 
HELP	);
	return 1;
}