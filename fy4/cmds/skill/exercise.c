// exe ÍÂÄÉÁ·Ï°£¬ Ìá¸ßÄÚÁ¦¡¢·¨Á¦¡¢ÁéÁ¦ 
//	±¾ÃüÁîÊÇexercise, meditate, respirate µÄ×ÛºÏ£¬
//	Ä¿µÄÊÇ¼õÉÙÍæ¼Ò¼ÇÒä·±ËöµÄÃüÁî----- Silencer @ fy4


#include <skill.h>
inherit F_CLEAN_UP;

string *add = ({ "qi", "jing", "shen" });
mapping *type = ({
	([      "add":                	"force",
                "add_c":		"ÄÚÁ¦",
                "cost":           	"kee",
                "cost_c":            	"ÆøÑª",
                "skill":		"force",
                "u_msg":		"Äã×øÏÂÀ´ÔËÆøÓÃ¹¦£¬Ò»¹ÉÄÚÏ¢¿ªÊ¼ÔÚÌåÄÚÁ÷¶¯¡£\n",
                "l_msg":		"µ«ÊÇµ±ÄãĞĞ¹¦Íê±Ï£¬Ö»¾õµÃÈ«Éí·¢Âé¡£\n",
                "f_msg":		"µ±ÄãµÄÄÚÏ¢±é²¼È«Éí¾­ÂöÊ±È´Ã»ÓĞ¹¦Á¦ÌáÉıµÄ¼£Ïó£¬ËÆºõÄÚÁ¦ĞŞÎªÒÑ¾­Óöµ½ÁËÆ¿¾±£¡\n",
        ]),
	([      "add":                	"atman",
                "add_c":		"ÁéÁ¦",
                "cost":           	"gin",
                "cost_c":            	"¾«Á¦",
                "skill":		"magic",
                "u_msg":		"ÄãÅÌÏ¥¶ø×ø£¬±ÕÉÏÑÛ¾¦¿ªÊ¼Äı¾ÛË¼Ğ÷¡£\n",
                "l_msg":		"µ«ÊÇÄãÒ»²»Ğ¡ĞÄÈ´Ë¯ÖøÁË¡£\n",
                "f_msg":		"Äã¾õµÃÒ»ÕóÌìĞıµØ×ª£¬Í·ÕÇµÃÏñÒªÁÑ¿ªÒ»Ñù£¬ËÆºõÁéÁ¦µÄĞŞĞĞÒÑ¾­Óöµ½ÁËÆ¿¾±¡£\n",
        ]),
        ([      "add":                	"mana",
                "add_c":		"·¨Á¦",
                "cost":           	"sen",
                "cost_c":            	"ĞÄÉñ",
                "skill":		"spells",
                "u_msg":		"ÄãÅÌÏ¥¶ø×ø£¬¾²×øÚ¤Ë¼ÁËÒ»»á¶ù¡£\n",
                "l_msg":		"µ«ÊÇµ±ÄãÕö¿ªÑÛ¾¦£¬Ö»¾õµÃÄÔÖĞÒ»Æ¬¿Õ°×¡£\n",
                "f_msg":		"ÄãºöÈ»¾õµÃÄÔÖĞÒ»Æ¬»ìÂÒ£¬ËÆºõ·¨Á¦µÄÌáÉıÒÑ¾­µ½ÁËÆ¿¾±¡£\n",
        ]),
});

int main(object me, string arg)
{
    	int kee_cost=30;
    	int n, amount, gain , i;
    	string add_1, h_cost, h_gain;
    	
    	seteuid(getuid());
        
    	if(environment(me)->query("no_fight"))
        	return notify_fail("Äã²»¿ÉÒÔÔÚÕâÀïÍÂÄÉÁ·¹¦¡£\n");
               	
    	if( me->is_fighting() )
        	return notify_fail("Õ½¶·ÖĞ²»ÄÜÍÂÄÉÁ·¹¦£¬»á×ß»ğÈëÄ§¡£\n");
    	if( me->is_busy() )
        	return notify_fail("ÄãÉÏÒ»¸ö¶¯×÷»¹Ã»ÓĞÍê³É£¬²»ÄÜÍÂÄÉÁ·¹¦¡£\n");
    
    	if (!arg || sscanf(arg, "%s %d", add_1, amount) != 2)
    		return notify_fail("Ö¸Áî¸ñÊ½£ºexercise <jing/qi/shen> <ÊıÄ¿> \n");
    	
     	n = member_array(add_1, add);
    	if ( n == -1)
    		return notify_fail("¸ñÊ½£ºexercise <jing/qi/shen> <ÊıÄ¿> \n");
    	   	   	
    	if (amount < 10)
    		return notify_fail(type[n]["add_c"]+"µÄĞŞĞĞ×îÉÙĞèÒªºÄ·Ñ10µã"+ type[n]["cost_c"]+ "¡£\n");
    		
//	write ("add_1 is "+  type[n]["cost"] + " amount is "+ amount +"\n");
 
		h_cost = type[n]["cost"];
		h_gain = type[n]["add"]; 
 
 		if( me->query(h_cost) < amount )
        	return notify_fail("ÄãÏÖÔÚµÄ"+ type[n]["cost_c"]+ "Ì«ÉÙÁË£¬ÎŞ·¨ÍÂÄÉÁ·Ï°¡£\n");

		if (me->query("death_revive")+ 180 > time())
			return notify_fail("ÄãÏÖÔÚµÄÉíÌå×´¿öÎŞ·¨ÍÂÄÉÁ·¹¦¡£\n");
	
		for (i=0;i<sizeof(type); i++) {
		if (i == n)	continue;
		if ( me->query( type[i]["cost"]) * 100 / me->query ("max_"+ type[i]["cost"]) < 70 )
        		return notify_fail("ÄãÏÖÔÚÉíÌå×´¿öÌ«²îÁË£¬ÎŞ·¨ÍÂÄÉÁ·¹¦£¡£¨" + 
        			type[i]["cost_c"] + "ÖµÖÁÉÙÔÚ70%ÒÔÉÏ£©\n");
    	}
        	
        	
		write(type[n]["u_msg"]);
        	
 		me->add(h_cost, -amount);
    	me->start_busy(1);

	// (500/10 + 40 )/30 = 3 , (3 + random (3))/ 5= 60% - 120% Ğ§ÂÊ maxium at enable= 500, att = 40¡£
    	
    	gain = me->query_skill(type[n]["skill"]) /10;
    	switch (h_cost) {
    		case "kee":	gain =  amount * (gain + me->query_con()) / 30; break;
    		case "sen":	gain =  amount * (gain + me->query_spi()) / 30; break;
    		case "gin":	gain =  amount * (gain + me->query_int()) / 30; break;
    		default:	write(" Äã·¢ÏÖÁËÒ»¸ö³ô³æ£¬ÇëÁ¢¼´±¨¸æÎ×Ê¦¡£\n"); return 1;
    	}
    		
    	gain = (gain + random(gain))/5;

    	if( gain < 1 ) {
        	write(type[n]["l_msg"]);
        	return 1;
    	}

//	write ("amount is "+ amount + " gain is "+ gain + "\n");
    	me->add( h_gain, gain );

		if( me->query(h_gain) > me->query("max_" + h_gain) * 2) {
        	if( me->query("max_" + h_gain) >= ( me->query_skill( type[n]["skill"], 1) + 
             						me->query_skill(type[n]["skill"])/5 ) * 5 ) {       		
            		write(type[n]["f_msg"]);
			me->set(h_gain, 2 * me->query("max_" + h_gain));	
		} else {
            		write("ÄãµÄ"+ type[n]["add_c"] + "ÔöÇ¿ÁË£¡\n");
            		me->add("max_" + h_gain, 1);
            		me->set(h_gain, me->query("max_"+h_gain ));
        	}
        }
        me->status_msg("all");
        me->force_status_msg("all");
    	return 1;
}


int help(object me)
{
    write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	exercise <jing|qi|shen> <ÊıÁ¿>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
·çÔÆ2005ÖĞµÄÍÂÄÉÁ·¹¦Ö¸Áî±ÈÔçÆÚ°æ±¾ÓĞ¼«´ó¸Ä½ø£¬½«Ô­À´µÄexercise¡¢
meditate¡¢respirateÃüÁî×ÛºÏÎªÍ¬Ò»¸ö£¬±ãÓÚÍæ¼ÒÉÏÊÖ¼ÇÒä¡£

¸ù¾İÖ¸Áîºó²ÎÊıµÄ²»Í¬£¬ÍÂÄÉÁ·¹¦ÓĞÈıÖÖ£¬·Ö±ğÌá¸ßÁéÁ¦¡¢ÄÚÁ¦¡¢·¨Á¦¡£

exercise jing <ÊıÁ¿> 	´ò×øĞŞĞĞ£¬ÀûÓÃ¡¸Á¶¾«»¯Æø£¬Á¶Æø»¯Éñ£¬
			Á¶Éñ»¹Ğé¡¹µÄ·½·¨½«ÄãµÄ¾«Á¦×ª±ä³É[0;1;31mÁéÁ¦[0m¡£

exercise qi <ÊıÁ¿> 	ÔËÆøÁ·¹¦£¬¿ØÖÆÌåÄÚµÄÆøÔÚ¸÷¾­Âö¼äÁ÷¶¯£¬
			½åÒÔÑµÁ·ÈËÌå¼¡Èâ¹Ç÷ÀµÄÄÍÁ¦¡¢±¬·¢Á¦£¬
			²¢ÇÒÓÃ[0;1;31mÄÚÁ¦[0mµÄĞÎÊ½½«ÄÜÁ¿´¢±¸ÏÂÀ´¡£
			
exercise shen <ÊıÁ¿>	¾²×øÚ¤Ë¼£¬½«ÓÎÀëµÄ¾«ÉñÁ¦ÓĞĞ§µØ¼¯ÖĞÄı
			¾Û³ÉÄÜ¹»ÓÃÀ´Ê©Õ¹·¨ÊõµÄÄÜÁ¿£¬½åÒÔÔö¼Ó
			×Ô¼ºµÄ[0;1;31m·¨Á¦[0m¡£


´ò×øµÃµ½µÄÄÚÁ¦×î´óÖµ == »ù±¾ÄÚ¹¦µÈ¼¶*5 + µ±Ç°µÄÓĞĞ§ÄÚ¹¦µÈ¼¶
¾ÙÀı:¡¡ÄÚ¹¦ĞÄ·¨ (force)                      ¡¡ -Éî²»¿É²â  200
¡¡¡¡ ¡¡ÄÚ¹¦ (force)          £º »ìãç¹¦           ÓĞĞ§µÈ¼¶£º295 
ÄÚÁ¦×î´óÖµ = 200*5 + 295 = 1295

Æ½¾ù×ª»¯Ğ§ÂÊ£½ £¨ÓĞĞ§ÄÚ¹¦µÈ¼¶£¯£±£°£«ÌåÖÊ£©£¯£±£°£°

ÁéÁ¦¡¢·¨Á¦µÄ¼ÆËãÓëÄÚÁ¦ÍêÈ«ÏàÍ¬¡£

Ïà¹ØÖ¸Áî£º
	»Ö¸´ÌåÁ¦£º	£å£ø£å£ò£ô¡¡£ñ£é
	»Ö¸´ĞÄÉñ£º	£å£ø£å£ò£ô¡¡£ó£è£å£î
	»Ö¸´¾«Á¦£º	£å£ø£å£ò£ô¡¡£ê£é£î£ç
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
HELP
        );
    return 1;
}
 
