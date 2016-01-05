/*	ABILITY2
	mapping pfm_r1_data = ([
		"jichulianhuanjue":	([
			"e_id":	"jichulianhuan",
			"c_id":	"¼Æ³öÁ¬»·",
			"fixed_atk":	500,	// Enable = 500	
			"fixed_dmg":	640,	// str = 80
			"self_busy":	4,
			"cdt":			180,	// individual_cdt
			"g_cdt":		60,		// global_cdt
			"weapon":		1,
		]),
	]);

	¾øÕÐÃû	pfm_r1_data[pfm_name[i]]["c_id"]
	Ó¢ÎÄÃû	pfm_name[i]
	ÊìÁ·¶È	me->query("pfm_r1/"+pfm_name[i]+"/expertise");
	¼ÇÒäÊý	me->query("pfm_r1/"+pfm_name[i]+"/memorized");
		
	Ê±ÏÞ	
	dur1 = ob->query("timer/pfm/pfm_r1") + r1_pfm_data[pfm_name[i]]["g_cdt"] -time();		// global timer
	dur2 = ob->query("timer/pfm/"+ pfm_name[i]) + r1_pfm_data[pfm_name[i]]["cdt"] -time();	// individual timer

	dur = dur1>dur2 ? dur1: dur2
	dur = dur>0: dur: 0;	


*/

#include <ansi.h>
inherit F_ABILITY;

int main(object me, string arg)
{
	string *pfm_name = ({"tiandirenmojue","jichulianhuanjue","tianwaifeixianjue","luorijue","hantianjue","miwujue",
						"soulflamejue", "jixingjue", "jiemaijue", "mengyanjue" });
	mapping pfm_details = ([
		"tiandirenmojue":
"È«Ãû¡ºÌìµØÈËÄ§Á¬»·°Ëµ¶¡»£¬µ±ÄêÄ§½ÌÓðÌì°×Æ¾´Ëß³ßåÎäÁÖ¶þÊ®Äê¡£´ËÕÐÒ»
¾­Ê©Õ¹£¬ÔòÎÞ¾¡ÎÞÐÝ£¬µ¶µ¶ÏàÁ¬£¬Ò»µ¶¿ì¹ýÒ»µ¶¡£

Ê¹ÓÃ£ºperform tiandirenmojue
ËµÃ÷£º×ÔÎÒÃ¦ÂÒÈýÂÖ£¬CDT300Ãë\n",

		"jichulianhuanjue":
"ÓÖÃû¡ºÉñ»ú°Ëµ¶¡»£¬Ð»ÕÆ¹ñËù´´£¬ÎôÈÕ·çÔÆÓÐÔÆ£º¡°ÎªÈË²»Ê¶Éñ»úµ¶£¬×ÝÊÇ
Ìì½¾Ò²Í÷È»¡±£¬Ò»Ê±Âú³ÇÉÙÄê£¬ÈËÊÖÒ»µ¶¡£

Ê¹ÓÃ£ºperform jichulianhuanjue
ËµÃ÷£º×ÔÎÒÃ¦ÂÒÈýÂÖ£¬CDT300Ãë£¬²»ÊÜ¶Ô·½ÁéÏ¬Ö¸Ó°Ïì\n",

		"tianwaifeixianjue":
"ÔÂÔ²Ö®Ò¹£¬×Ï½ûÖ®µß£¬Ò»½£Î÷À´£¬ÌìÍâ·ÉÏÉ£¬±ãÎªÕâÒ»¾ä»°£¬²»ÖªÓÐ¶àÉÙÈË
°ÝÔÚ°×ÔÆ³ÇÖ÷Ò¶¹Â³ÇÃÅÏÂ¡£

Ê¹ÓÃ£ºperform tianwaifeixianjue
ËµÃ÷£º×ÔÎÒÃ¦ÂÒÈýÂÖ£¬CDT300Ãë£¬²»ÊÜ¶Ô·½»¤ÌåÉñ¹¦×è¸ô\n",

		"luorijue":
"³¤ºÓÂäÈÕÔ²£¬~³¤~~ºÓ~~~~Âä~~~~~ÈÕ~~~~~~Ô²£¬Ö»ÓÐ¼û¹ý³þÏãË§ÕâÒ»ÕÐµÄÈË£¬
²ÅÄÜÏë¼û´óÉ³Ä®ÖÐµÄ×³Àö¡£

Ê¹ÓÃ£ºperform luorijue
ËµÃ÷£º×ÔÎÒÃ¦ÂÒÁ½ÂÖ£¬CDT300Ãë¡£\n",

		"hantianjue":
"½£ºÎÔÚ£¿ÈË¼´ÊÇ½££¬Ö»ÒªÈËÔÚ£¬ÌìµØÍòÎï£¬½ÔÎª½£¡£Î÷ÃÅ´µÑ©µÄ½£·¨ÒÑÖÁáÛ
·å£¬¿ÉÔÚÈÎÒ»ÕÐÊ½ÖÐµÝ³ö¡£

Ê¹ÓÃ£ºperform hantianjue
ËµÃ÷£º×ÔÎÒÃ¦ÂÒÒ»ÂÖ£¬CDT300Ãë¡£\n",

		"miwujue":
"Ê®ÀïÃÔÎí£¬½­É½Èç»­£¬ÓàÒôôÁôÁ£¬Éù¾°½»ÈÚ£¬ÀîÓñº¯µÄÎä¹¦Ô¶Ô¶²»ÊÇÌìÏÂµÚ
Ò»£¬µ«ÓÐÐí¶à×ÔÒÔÎªÌìÏÂµÚÒ»µÄÈË½øÁË»ÆÉ½½£Â®¾ÍÃ»ÓÐÔÙ»î×Å³öÀ´¡£

Ê¹ÓÃ£ºperform miwujue
ËµÃ÷£º¿ÕÊÖÃ¦ÂÒ¼¼£¬CDT180Ãë¡£\n",

		"soulflamejue":
"ÇàÄ§ÈÕ¿Þ£¬³àÄ§Ò¹¿Þ£¬¶þÄ§Æë¿Þ£¬ÌìµØ±äÉ«¡£Èô°ÙÏþÉúµÄ±øÆ÷Æ×ÉÏÁÐµÄ²»½ö
ÊÇÎäÆ÷»¹ÊÇÎä¼¼µÄ»°£¬ÒÁ¿ÞµÄÄ§»ðÁ¶»êÅÅÃûÖ»ÅÂ»¹ÔÚËûµÄÇàÄ§ÊÖÖ®ÉÏ¡£

Ê¹ÓÃ£ºcast soulflamejue
ËµÃ÷£ºÍ¬Ê±¹¥»÷ËùÓÐ¶ÔÊÖµÄ¾«Á¦ºÍÐÄÉñ£¬×ÔÎÒÃ¦ÂÒÒ»ÂÖ£¬CDT180Ãë¡£\n",

		"jixingjue":
"Ê©·½ÒÇµÀµä£¬½èÓñºâ¡¢Ò¡¹â»ÔÃ¢£¬ÉÏ¾Û¾ÅÌìÖ®Æø£¬ÏÂ¼°Ê®µØÖ®¾«¡£µ±ÄêÎäµ±
ÀÏÕÆÃÅÔÚÕæÎäµÛ¾ýÏñÇ°ßµ°ÝÆßÈÕÆßÒ¹·½µÃ´«ÊÚ¡£

Ê¹ÓÃ£ºcast jixingjue
ËµÃ÷£ºÌá¸ßËùÓÐ·¨Êõ¡¢Ä§Êõ¡¢Öä·¨µÄ¹¥»÷Á¦£¬³ÖÐø20Ãë£¬CDT180Ãë¡£\n",

		"jiemaijue":
"½­ºþÉÏµÀ£ºÑàÄÏÌìµÄ½££¬Íò´ºÁ÷µÄÊÖ¡£Ç°Õßµ±ÕßÅûÃÒ£¬Ã»ÓÐÉ±²»ËÀµÄ¶ñÍ½£¬
ºóÕß¿É°×¹ÇÉú¼¡£¬Ã»ÓÐ¾È²»»ØµÄ²¡ÈË¡£

Ê¹ÓÃ£ºperform jiemaijue
ËµÃ÷£ºÕ½¶·ÍâÖÎÁÆ¾«Á¦¡¢ÆøÑª¡¢ÐÄÉñµÄËðÉË£¬×ÔÎÒÃ¦ÂÒÒ»ÂÖ£¬CDT300Ãë¡£\n",

		"mengyanjue":
"¶¡°×ÔÆÉíÊÀ¿²¿À£¬ÔÚËýÉú´æµÄÊÀ½çÀï£¬Ò»Ïò¶¼ÈÏÎª±¨¸´Ô¶±È¿íË¡¸üÕýÈ·£¬Ö±
µ½Ëý¼ûµ½Ò¶¿ª£¬²ÅÖªµÀ£¬³ðºÞ±ãÈçÃÎ÷Ê£¬Ô­ÊÇÓ¦¸ÃÒÅÍüµÄ¡£

Ê¹ÓÃ£ºcast mengyanjue
ËµÃ÷£ºÕÙ»½ÃÎ÷ÊÖ®ÊÞÀ´¸¨ÖúÕ½¶·£¬³ÖÐø20Ãë£¬CDT300Ãë¡£\n",

		]);
				
			
	string p_name,id,msg;
	int i,num, dur1, dur2, dur;
	object ob;
	
	if (wizardp(me))
	{
		if(arg && sscanf(arg, "-%s", id) == 1)
		{
			ob = present(id, environment(me));
			if (!ob) ob = find_player(id);
			if (!ob) ob = find_living(id);
			if (!ob) return notify_fail("ÄãÒª²ì¿´Ë­µÄ·çÔÆ¾ø¼¼£¿\n");			
		} else
			ob = me;					
	} else
		ob = me;
			
	if (arg && member_array(arg, pfm_name)!=-1) {
		
		if (ob->query("pfm_r1/"+arg+"/expertise")
				|| ob->query("pfm_r1/"+arg+"/memorized"))
		{
			write(HIG"\t¡¡¡¡		"+pfm_r1_data[arg]["c_id"]+"\n"NOR);
			write(HIR BLK"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"NOR);
			write(pfm_details[arg]);
			write(HIR BLK"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"NOR);
			return 1;
		}
	}
		
	num = sizeof(pfm_name);
		
	write(HIG"\t¡¡¡¡		·çÔÆ¾ø¼¼½ø½×\n"NOR);
	write(HIR BLK"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"NOR);
	write(WHT    "ÐòºÅ	¾øÕÐÃû		Ó¢ÎÄÃû		ÊìÁ·¶È	 ¼ÇÒä	 Ê±ÏÞ	\n"NOR);	
	write(HIR BLK"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"NOR);
	
	for(i=0; i<num; i++) {
		if (ob->query("pfm_r1/"+pfm_name[i]+"/expertise")
				|| ob->query("pfm_r1/"+pfm_name[i]+"/memorized"))
		{		
			dur1 = ob->query("timer/pfm/pfm_r1") + pfm_r1_data[pfm_name[i]]["g_cdt"] -time();		// global timer
			dur2 = ob->query("timer/pfm/"+ pfm_name[i]) + pfm_r1_data[pfm_name[i]]["cdt"] -time();	// individual timer
			dur = dur1>dur2 ? dur1: dur2;
			dur = dur>0? dur: 0;			
			msg = sprintf(WHT"%d"GRN"	%-12s"NOR" %-20s%d	£¨%d/3£©	%3d	\n"NOR,
				i+1,
				pfm_r1_data[pfm_name[i]]["c_id"],
				pfm_name[i],
				ob->query("pfm_r1/"+pfm_name[i]+"/expertise"),
				ob->query("pfm_r1/"+pfm_name[i]+"/memorized"),
				dur,
				);
		} else
			msg = sprintf(WHT"%d\n"NOR,i+1);
		write(msg);
	}
				
	write(HIR BLK"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤\n"NOR);


	return 1;
}


int help(object me)
{
write(@HELP

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	ability2 [0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

ability2 			ÄãÏÖÔÚÕÆÎÕµÄ·çÔÆ¾øÕÐ			
ability2 ¾øÕÐÓ¢ÎÄÃû	¹ØÓÚ¸Ã¾øÕÐµÄÒ»Ð©¾ßÌåËµÃ÷

ÊìÁ·¶È£ºÃ¿Ê¹ÓÃÒ»´ÎÊìÁ·¶ÈÌá¸ß1µã£¬Ò»¿ªÊ¼ÕâÐ©¾øÕÐÒ²Ðí²¢²»ÆðÑÛ£¬Ëæ×Å
ÊìÁ·¶ÈµÄÔö¼ÓÍþÁ¦»áÖð²½Ìá¸ß£¬µ±Ôö³¤µ½100ºó²»ÔÙÐèÒªÇë½Ì¿Ú¾÷¡£
	
¼ÇÒä£ºÀ¨ºÅÖÐÇ°ÖµÎªµ±Ç°¼ÇÒäµÄ¿Ú¾÷Êý£¬Ò²¾ÍÊÇÄã¿ÉÒÔÊ¹ÓÃ¸Ã¾øÕÐµÄ´ÎÊý
À¨ºÅÖÐºóÖ°Îª¿ÉÍ¬Ê±¼ÇÒäµÄ×î¶à¿Ú¾÷Êý

Ê±ÏÞ£ºÏÂÒ»´ÎÊ¹ÓÃ¸Ã¾øÕÐµÄ¼ä¸ô£¬²»Í¬¾øÕÐÓÐ×Ô¼ºµÄÊ±¼äÏÞÖÆ£¬²»Í¬¾øÕÐ
Ö®¼äµÄ¼ä¸ôÎª60Ãë¡£

Ê¹ÓÃ·çÔÆ¾ø¼¼ÐèµÈ¼¶100ÒÔÉÏ¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m  
HELP
    );

    return 1;
}
 
