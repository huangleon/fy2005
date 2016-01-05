// abandon.c
#include <ansi.h>
inherit F_CLEAN_UP;
void abandon_skill(string confirm, object me, string skill);
int zero_skill(object me, string arg);
mapping valid_types = ([
//		"array":        "Õó·¨",
		"animal-training":  "ÑµÊŞÊõ",
		"axe":    	"¸«·¨",
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
		"perception":   "Ìı·çÊõ",
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
]);



int main(object me, string arg)
{
	string err;
	
	if( !arg || arg=="" ) return notify_fail("ÄãÒª·ÅÆúÄÄÒ»Ïî¼¼ÄÜ£¿\n");

	if(!find_object(SKILL_D(arg)) && file_size(SKILL_D(arg)+".c")<0) {
		return notify_fail("¡¸" + arg + "¡¹£¬ÓĞÕâÖÖ¼¼ÄÜÂğ£¿\n");	
	}
	/*if(!load_object(SKILL_D(arg)+".c")) 
		return notify_fail("¡¸" + arg + "¡¹£¬ÓĞÕâÖÖ¼¼ÄÜÂğ£¿\n");
	*/	
    seteuid(getuid());
    err = catch( call_other(SKILL_D(arg)+".c", "???") );
    if (err)
       printf( "·¢Éú´íÎó£º\n%s\n", err );
	
	if( !me->query_skill(arg,1) && !zero_skill(me,arg))
		return notify_fail("Äã²¢Ã»ÓĞÑ§¹ıÕâÏî¼¼ÄÜ¡£\n");
		
	if (arg == "magic" || arg == "force" || arg == "spells")
		return notify_fail("ÕâÏî»ù±¾¼¼ÄÜÓ°ÏìÄãµÄ¾«ÆøÉñÊıÖµ£¬ÎŞ·¨·ÅÆú¡£\n");
		
	write(HIY"\n¡¸·ÅÆú¡¹ÊÇÖ¸½«ÕâÏî¼¼ÄÜ´ÓÄãÈËÎïµÄ×ÊÁÏÖĞÉ¾³ı£¬Èç¹ûÄãÒÔºó»¹ÒªÁ·£¬±ØĞë´ÓÁã¿ª
Ê¼ÖØÁ·£¬ÇëÎñ±Ø¿¼ÂÇÇå³ş¡£\n\n"NOR);
	
	if (me->query("annie/skill_cost/"+arg)>0) {
		write(HIY"ÄãÒÑ¾­ÔÚÕâÃÅ¼¼ÄÜÉÏ»¨·ÑÁË"+me->query("annie/skill_cost/"+arg)+"µãÇ±ÄÜ£¬½¨ÒéÄãÊ¹ÓÃ£ò£å£æ£õ£î£äµÄ·½Ê½ÊÕ»ØÕâĞ©Ç±
ÄÜÑ§ÆäËû¶«Î÷£¬£ò£å£æ£õ£î£äµÄ·½Ê½Çë²Î¿´£è£å£ì£ğ¡¡£î£å£÷£â£é£åµÄµÚ£±£´Ìõ£¬±¾
´ÎÖ¸ÁîÖĞ¶Ï¡£\n\n"NOR);
		return 1;
	}
	
	write("ÄãÈ·¶¨·ÅÆú¼ÌĞøÑ§Ï°£Û"HIR + SKILL_D(arg)->name() + NOR"£İ£¬ÊÇ·ñÒª¼ÌĞø£¿(yes/no)\n");
	input_to( (: abandon_skill :), me, arg);
	return 1;
}

void abandon_skill(string confirm, object me, string skill) 
{
	if (! (confirm == "yes" || confirm == "YES")) 
		write("Äã³öÁËÒ»ÉíÀäº¹£¬ºÃÏÕ£¡\n");
	else    {
        	if(me->query_skill(skill,1)>50)
        	log_file("skills/ABANDON",
        	  sprintf("%s(%s)ÔÚ%s·ÅÆúÁË%d¼¶%s¡£\n",
        	  me->name(1),geteuid(me),ctime(time()),me->query_skill(skill,1),skill));
		me->delete_skill(skill);
		me->reset_action();
		write("Äã¾ö¶¨·ÅÆú¼ÌĞøÑ§Ï°" + SKILL_D(skill)->name() + "¡£\n");
	}
}


int zero_skill(object me, string arg) {
	mapping learned_skill_points;
	
	learned_skill_points=me->query_learned();
	if (!mapp(learned_skill_points))	return 0;
	if (!learned_skill_points[arg]) return 0;
	return 1;
}


	
	
	

int help()
{
	write(@TEXT
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½£ºabandon <¼¼ÄÜÃû³Æ>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m

·ÅÆúÒ»ÏîÄãËùÑ§µÄ¼¼ÄÜ£¬×¢ÒâÕâÀïËùËµµÄ¡¸·ÅÆú¡¹ÊÇÖ¸½«ÕâÏî¼¼ÄÜ´ÓÄãÈË
ÎïµÄ×ÊÁÏÖĞÉ¾³ı£¬Èç¹ûÄãÒÔºó»¹ÒªÁ·£¬±ØĞë´Ó0¿ªÊ¼ÖØÁ·£¬ÇëÎñ±Ø¿¼ÂÇÇå
³ş¡£

Õâ¸öÖ¸ÁîÊ¹ÓÃµÄ³¡ºÏÍ¨³£ÊÇÓÃÀ´É¾³ıÒ»Ğ©¡¸²»Ğ¡ĞÄ¡¹Á·³öÀ´µÄ¼¼ÄÜ£¬ÓÉì¶
ÎÒÃÇ¼ÙÉèÄãµÄÈËÎïËæÊ±¶¼»á´ÓËû£¯ËıµÄ¸÷ÖÖ¶¯×÷¡¢Õ½¶·ÖĞÑ§Ï°£¬Òò´ËÓĞĞ©
¼¼ÄÜ»áÒòÎªÄã¾­³£µØÊ¹ÓÃ¶ø³öÏÖÔÚÄãµÄ¼¼ÄÜÁĞ±íÖĞ£¬Õâ¸öÈËÎï¾Í±ØĞë»¨·Ñ
Ò»Ğ©¾«ÉñÈ¥¡¸¼Ç×¡¡¹ËùÑ§¹ıµÄÒ»ÇĞ£¬È»¶ø£¬ÈËµÄ×ÊÖÊ¸÷ÓĞ²»Í¬£¬ÁéĞÔ¸ßµÄ
ÈËÄÜ¹»Ñ§Ï°Ğí¶à¼¼ÄÜ¶ø³ÉÎª¶à²Å¶àÒÕµÄ²Å×Ó£¬ÁéĞÔ½Ï²îµÄÈË¾ÍÖ»ÄÜ×¨ĞÄì¶
ÌØ¶¨¼¸Ïî¼¼ÄÜ£¬Èç¹ûÄãÑ§µÄ¼¼ÄÜÖÖÀàÌ«¶à£¬³¬¹ıÄãµÄÁéĞÔ£¬Äã»á·¢ÏÖÈËÎï
µÄÑ§Ï°ËÙ¶È½«±ÈÖ»Ñ§¼¸ÖÖ¼¼ÄÜµÄÈËÂı£¬³¬¹ıÔ½¶à£¬Ñ§Ï°Ğ§¹ûµÍÂäµÄÇé¿öÔ½
ÑÏÖØ£¬ÕâÖÖÇéĞÎ¾ÍÏñÊÇÒ»¸öÑ§ÆÚÍ¬Ê±Ñ¡ĞŞÌ«¶àÑ§·Ö£¬ËäÈ»ÄãÈÔÈ»¿ÉÒÔÆ¾Öø
³¬ÈËµÄÒâÖ¾Á¦Á·ÏÂÈ¥£¬²»¹ıÕâ½«»á¶à»¨·ÑÄãĞí¶à±¦¹óµÄÊ±¼ä¡£

×¢£ºÑ§Ï°¼¼ÄÜ×ÜÊı£¾ÁéĞÔ£«£±Ê±Ñ§Ï°Ğ§ÂÊ½«½µµÍ¡£
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
TEXT
	);
	return 1;
}
