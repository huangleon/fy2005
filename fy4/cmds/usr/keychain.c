#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{

	object room,ob,coin;
	string rname,str;
	string *driddle = ({"ÇÉÈëÍòÃ·","ÓÄÁéÉ½×¯","³¤´ºÃÔ¹¬","ÆßÏÉÅ®Õó",
		"ÊØ¾­Â¥","ÀÇÉ½Ì½ÏÕ","ÎíÁýÀÇÉ½","É³Ä®ÍÕÂÃ","ÎåÐÐÍ­ÈË","ÓÂ´³òùòðµº","Ì½¶ö»¢¸Ú","ÉñË®Ì½ÓÄ","Áú»¢Õ¯ÍÁ·Ë"});
	string *content = ({"ÍòÃ·É½×¯µÄÇÙÉù",
						"ÓÄÁéÉ½×¯µÄÉÚÉù",
						"³¤´ºµºµÄÉÚÉù",
						"´óÆì¹ÈµÄÊ÷Ò¶",
						"½øÈëÉÙÁÖËÂ",
						"½øÈëÀÇÉ½Ç°É½",
						"½øÈëÀÇÉ½ºóÉ½",
						"ÀÏÔÆÕ¯µÄÉÚÉù",
						"½øÈëÐË¹úìøËÂ",
						"´î³ËòùòðµºµÄ¶É´¬",
						"½øÈë¶ö»¢¸ÚµÄ´óÃÅ",
						"Î¢ÐÍ·çóÝ",
						"¸øÇ®¾ÍÐÐ",
					});
	int i;
	
	seteuid(getuid());	
	if (!REWARD_D->check_m_success(me,"ÈçÒâìÝÁ´"))
		return notify_fail("Äã»¹Ã»ÓÐ¼¤»îÈçÒâìÝÁ´£¬¸ÃÎï¿ÉÔÚðÐðÄ¸ó¹ºÂò¡£\n");
	
	if (arg == "-coin") {
		if (me->query("deposit")< 100)
			return notify_fail("ÄãÃ»ÓÐ×ã¹»µÄ´æ¿îÀ´Ö´ÐÐ´ËÖ¸Áî¡£\n");
		if (me->query("timer/keychain_coin")+ 300 > time())
			return notify_fail("´ËÃüÁîÃ¿Èý·ÖÖÓ²ÅÄÜÖ´ÐÐÒ»´Î¡£\n");
		coin = new("/obj/money/coin");
		coin->set_amount(50);
		if (!coin->move(me)){
			destruct(coin);
			return notify_fail("ÄãÐ¯´øÎïÆ·¹ý¶à£¬ÎÞ·¨Ö´ÐÐ´ËÖ¸Áî¡£\n");
		}
		write(WHT"ÈçÒâìÝÁ´»©»©×÷Ïì£¬Ìø³öÎåÊ®¸öÍ­°åÀ´¡£\n"NOR);
		me->add("deposit",-50);
		me->set("timer/keychain_coin",time());
		return 1;
	}
	
	if (arg=="-list") {
		write(WHT"    ·çÔÆµØÇø³öÈëµÄÍ¾¾¶¼°¶ÔÓ¦ÃÕÌâ
=======================================\n\n"NOR);		
		for (i=0;i<sizeof(driddle);i++){
			str = (REWARD_D->check_m_success(me,driddle[i]))?
					CYN""+ driddle[i]+""NOR	: driddle[i];
			write(sprintf(YEL"  %-20s"NOR"%-20s\n",
				content[i],
				str,
				));
		}
		write(WHT"
=======================================\n"NOR);
		return 1;
	}		
		
	if (arg)	 
		return notify_fail("´ËÃüÁî²»ÐèÒªÆäËû²ÎÊý£¬»á¸ù¾ÝÄãËù´¦µÄ»·¾³×Ô¶¯ÅÐ¶Ï¡£\n");
		
	room = environment(me);
	rname = file_name(environment(me));
	
//	write(" it is "+ file_name(environment(me))+"\n");
	
	if (me->query("deposit")<100)
		return notify_fail("Ê¹ÓÃÈçÒâìÝÁ´ÐèÒªÖÁÉÙÓÐÒ»¶¨µÄÊµÁ¦£¨´æ¿î£©\n");
	me->add("deposit",-100);	
		
	switch (rname) {
		
		case "/d/wanmei/gate":
			if (REWARD_D->check_m_success(me,"ÇÉÈëÍòÃ·")) {
				message_vision("$N´ÓÉíÉÏ½âÏÂ¹ÅÇÙ£¬ÐÅÊÖÒ»»®£¬ÈªË®°ãµÄÇÙÉù´ÓÖ¸¼âÁ÷Ðº¶ø³ö¡£
ÂþÉ½µÄÃ·ÁÖÉ³É³×÷Ïì£¬ËÆºõÒ²ÔÚÎªÄã°é³ª£¬×¯ÄÚµÄÉ±Æø¶ÙÊ±ÏûÉ¢ÁË¡£\n",me);
				me->set_temp("played_qin",1);
				return 1;
			}
			break;
		case "/d/ghost/forest9":
			if (REWARD_D->check_m_success(me,"ÓÄÁéÉ½×¯")){
				message_vision("$N´ÓÉí±ßÌÍ³öÒ»¸öÁ½´ç¶à³¤µÄÍ­ÉÚ´µÁËÒ»Éù¡£\n",me);
        		room->pipe_notify();
        		return 1;
        	}
        	break;
		case "/d/eastcoast/seaside":
		case "/d/eastcoast/seaside2":
		case "/d/changchun/island":
			if (REWARD_D->check_m_success(me,"³¤´ºÃÔ¹¬")){
				message_vision("$N´ÓÉí±ßÌÍ³öÒ»¸öÁ½´ç¶à³¤µÄÍ­ÉÚ´µÁËÒ»Éù¡£\n",me);
        		room->pipe_notify();
        		return 1;
        	}
        	break;
		case "/d/eastcoast/troad3":
			if(REWARD_D->check_m_success(me,"ÆßÏÉÅ®Õó")){
				me->set_temp("mark/cat",1);
				message_vision("$NÏòÐ¡Ã¨ßäÕ£ÁËÕ£ÑÛ¾¦£¬Ð¡Ã¨ßäËÆºõ¼ÇÆðÁË$N£¬ÅÜ¹ýÀ´ÔÚ$NµÄ½ÅÉÏ²äÁË²ä£¬
Éì³ö¸ö×¦×ÓÏòÎ÷±ßµÄÉ½±ÚÖ¸ÁËÖ¸ÓÖÅÜ¿ªÁË¡£\n",me);
				return 1;
			}
			break;
		case "/d/shaolin/ye1":
		case "/d/shaolin/ye2":
			if (REWARD_D->check_m_success(me,"ÊØ¾­Â¥")){
				message_vision("$N³ÁÉùµÀ£ºÔÚÏÂÎª¹óËÂÕÒ»¹ÁËÊ§ÂäµÄ¾­Êé£¬ÖÚÎ»Ê¦ÐÖÄª·Ç²»¼ÇµÃÁËÃ´£¿\n",me);
				me->set_temp("shaolin",1);
				return 1;
			}
			break;
		case "/d/wolfmount/bigstage":
			if (REWARD_D->check_m_success(me,"ÀÇÉ½Ì½ÏÕ")){
				if(objectp(ob=present("fighter wolf",room))) {
					message_vision("$NÅÄÁËÅÄ$nµÄ¼çËµ£¬ÕâÎ»ÐÖµÜ£¬ÉÏ´ÎµÄÒ°Î¶²»´í°É¡£
$n´óÐ¦µÀ£º²»´í¡¢²»´í¡¢¹ûÕæÊÇ¼ÒÍÃ²»ÈçÒ°ÍÃÏã°¡£¡\n", me, ob);
					me->set_temp("marks/ÀÇÉ½ÓÎ¿Í",1);
					return 1;
				}
			}
			break;
		case "/d/wolfmount/brook":
			if (REWARD_D->check_m_success(me,"ÎíÁýÀÇÉ½")){
				me->set_temp("annie/wolf_conch",1);
				message_vision("$N´ÓÉí±ßÌÍ³öÒ»¸öÐ¡º£ÂÝ£¬à½ààààµØ´µÁË¼¸Éù¡£\n",me);
				return 1;
			}
			break;
		case "/d/oldpine/keep2":
			if (REWARD_D->check_m_success(me,"É³Ä®ÍÕÂÃ")){
				message_vision("$N¼âÆðÉ¤ÃÅ¶ù£¬Ñ§×ÅÐ¡ÍÁ·ËµÄÉùµ÷ßººÈÁË¼¸Éù¡£\n",me);
				room->pipe_notify();
				return 1;
			}
			break;

		case "/d/qianfo/dadian":
			if (REWARD_D->check_m_success(me,"ÎåÐÐÍ­ÈË")){
				message_vision("$N´ÓÉíÅÏÌÍ³öÎåÃ¶Ð¡Õë·ÅÈëÍ­ÈËÖÐ¡£\n",me);
				me->set_temp("marks/copperman",1);
				return 1;
			}
			break;
		case "/d/eastcoast/bfd1":
			if (REWARD_D->check_m_success(me,"ÓÂ´³òùòðµº")) {
				tell_object(me, "ÕýÇÉ£¬º£±ßÍ£×ÅÒ»Ìõ´ó´¬£¬Äã´óÏ²¹ýÍû£¬µÃÒâÑóÑóµÄ×ßÉÏÁË´óº£´¬.......\n\n" NOR ) ;
	  			message_vision("´¬·òÒ»¼û$NÉÏ´¬£¬Ã¦½ÐÁËÒ»Éù£º¿ª´¬à¶£¡\n", me);
	  			message_vision("´¬·òÉýÆð·«£¬´¬¾ÍÏò¶«·½º½ÐÐ¡£\n\n", me);
	  			room = find_object(AREA_BAT"dahai");
	  			if (!room)	room = load_object(AREA_BAT"dahai");
	  			me->move(room);
				return 1;
			}
			break;
		case "/d/bawang/ehugang":
			if (REWARD_D->check_m_success(me,"Ì½¶ö»¢¸Ú")) {
				message_vision("$N´ÓµØÉÏ×¥ÆðÐ©ºÚÍÁÍùÁ³ÉÏÄ¨ÁËÄ¨£¬ÓÖ°ÑÒÂ·þÀ­ÁË¼¸¸ö¿Ú×Ó£¬Ò»È³Ò»¹ÕµØ×ßÏòÁ½¸öà¶ÂÞ¡£
´óà¶ÂÞÀÁÑóÑóµØËµ£ºÐ¡É½¶«°¡£¿ÉÏ´ÎµÄÉÕ¼¦²»´í£¬ÒÔºó¶àÉÓ¼¸¸ö¸ø´óÒ¯¡£
Ð¡à¶ÂÞµÍÍ·¿Ð×Å¼¦³á£¬²»ÄÍ·³µØÏòºóÃæÖ¸ÁËÖ¸¡£\n",me);
				me->set_temp("marks/keychain_ehg",1);
				return 1;
			}
			break;
		case "/d/laowu/baishui":
			if (REWARD_D->check_m_success(me,"ÉñË®Ì½ÓÄ")){
				ob = new(AREA_QINGPING"npc/obj/kite");
				room->kite_notify(ob,1);
				return 1;
			}
		case "/d/zangbei/wild3":
			if (ob=present("bandit",room)){
				if (me->query("deposit")>10000) {
					message_vision("$N´ÓÑü°üÀïÌÍ³öÒ»ÕÅÒøÆ±£¬ÂúÁ³¶ÑÐ¦µØµÝ¸ø$n\n",me,ob);
					me->add("deposit",-10000);
					if (me->query_temp("wild4_pass") || me->query("combat_exp")<1000000)
						ob->ccommand("say ÕâÃ´Ö÷¶¯£¿ÓÖËÍ±£Â··ÑÀ´ÁË£¿");
					me->set_temp("wild4_pass", 1);
					ob->ccommand( "say ¹þ¹þ£¬¿´ÔÚÄãÐ¢Ë³µÄ·ÝÉÏ£¬¾Í¸øÄã¸ö·½±ã°É¡£");
					return 1;
				} else
					message_vision("$NËµ£ºÇî½Ð»¨×Ó£¬Ã»Ç®¾ÍÈ¥È¡£¡\n",ob);
				return 1;
			}
			break;
					
	}

	me->add("deposit",100);	// Ã»Æð×÷ÓÃ£¬»¹Ç®
	
//	write ("not exec \n");
	return notify_fail("ÈçÒâìÝÁ´Ã»ÓÐÊ²Ã´·´Ó¦£¬´ó¸ÅÊÇµØ·½²»¶Ô£¬»òÕßÄãÃ»Íê³ÉÏàÓ¦µÄÃÕÌâ¡£\n");
}


int help(object me)
{
	write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½£º keychain [-list | -coin ][0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m

ÈçÒâìÝÁ´ÊÇ·çÔÆ£²£°£°£µ¼ÌÐþÁéÓñºÐºóÍÆ³öµÄÓÖÒ»Ïî½µµÍ·´¸´²Ù×÷£¬
ÔöÇ¿ÓÎÏ·È¤Î¶ÐÔµÄ±¦Îï¡£

·çÔÆÖÐÓÐÐí¶àµØÇøÐèÒª½âÃÕºó·½ÄÜ½øÈë£¬¶øÃ¿´Î½âÃÕÐèÒªÊÕ¼¯¸÷Ïî
ÎïÆ·£¬¸øÒ»Ð©²»ÄÜ³¤¾ÃÔÚÏßµÄÍæ¼Ò´øÀ´ÁËÀ§ÄÑ¡£

ÓÐÁËÈçÒâìÝÁ´¾Í²»ÓÃÔÙÎªÕâ¸ö·¢³îÁË£¡

Ö»ÒªÄãÍê³ÉÁËÕâ¸öµØÇøËù¶ÔÓ¦µÄÃÕÌâ£¬ÈçÒâìÝÁ´¾Í»á½«ÓÐ¹ØÎïÆ·×Ô
¶¯ÊÕ²ØÆðÀ´£¬¼È²»Õ¼µØ·½£¬Ò²Ã»ÓÐÖØÁ¿£¬Òà²»»áÒòÎªÄãÏÂÏß¶øÏûÊ§¡£
µÈÄãÔÙ´ÎÉÏÏßÐèÒª½øÈëÄÇÐ©µØÇøÊ±£¬Ö»ÐèÔÚÔ­À´½âÃÕµÄ³¡ËùÊäÈë
£ë£å£ù£ã£è£á£é£î£¬ÈçÒâìÝÁ´¾Í»á×ö³öÏàÓ¦µÄ·´Ó¦£¬ÖÁÓÚÔÚÊ²Ã´µØ
·½Ê¹ÓÃ£¬¾Í¿¿Äã×Ô¼º×ÁÄ¥ÁË¡£

Ê¹ÓÃ£ë£å£ù£ã£è£á£é£î¡¡£­£ì£é£ó£ôÃüÁî¿É²ì¿´ÄãµÄÈçÒâìÝÁ´ÉÏÒÑ
¾­¾ßÓÐµÄÃÕÌâÎïÆ·¡£ÊÇ·ñÍê³É¿É´Ó²»Í¬µÄÑÕÉ«¿´³ö¡£

×¢£±£ºÈç¹ûÒ»Ð©µØÇøÒÑ¾­ÓÐÁËÓÀ¾ÃÐÔ³öÈëµÄÃÕÌâ£¬¾ÍÃ»ÓÐÊ¹ÓÃÈçÒâ
ìÝÁ´µÄ±ØÒª£¬±ÈÈçËµ¿ì»îÁÖ¡¢¸»¹óÉ½×¯¡¢ÍòÂíÌÃµÈµÈ¡£Ò»Ð©¿ÉÒÔ·Ç
³£ÈÝÒ×³öÈë²»ÒªÃÕÌâÎïÆ·µÄµØÇøÈçÒâìÝÁ´Ò²²»ÊÊÓÃ¡£

×¢£²£ºÃ¿´Î³É¹¦Ê¹ÓÃÈçÒâìÝÁ´ÃüÁî»á´ÓÄãµÄÕË»§Àï×ª×ß£±Á½ÎÆÒø£¬
²»¹ý£¬ÏñÐË¹ú¡¢ÉÙÁÖ¡¢ÀÇÉ½¡¢ÍòÃ·µÈºÜ¶àµØ·½ÉÏÏßºóÖ»ÐèÒªÊ¹ÓÃÒ»
´Î±ã¿É¸ßÕíÎÞÓÇ£¬Èç´ËËãÀ´£¬»¹ÊÇ´ó´ó»®ËãµÄ£¬

×¢£³£ºÈç¹ûÊ¹ÓÃ -coin ²ÎÊý£¬Ôò¿É´ÓÒøÐÐÀïµÃµ½ÎåÊ®¸öÍ­°å£¬ÔÙÒ²
²»ÓÃµ£ÐÄÀ§ÔÚÄ³¸öÃÔ¹¬ÀïÁË¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
HELP
	);
	return 1;
}
