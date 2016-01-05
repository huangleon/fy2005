//	Silencer@fy4 workgroup
/*L100	¡ºÒ»×Ö³¤ÉßÕó¡»Ð¥¾¯£¬ÍÑÀëÕ½¶·£¬CDT30·ÖÖÓ
L150	¡º¶þÁú¼³Ë®Õó¡»*»¤ÎÀ¹¥»÷Á¦Ôö¼Ó£¨£«±ø·¨£¯£³£©£¬³ÖÐø20·ÖÖÓ
L160	¡ºÈý²ÅÌìµØÈËÕó¡»ÕÙ»½»¤ÎÀ£¬·ÇÕ½¶·ÖÐÊ¹ÓÃ£¬CDT1·ÖÖÓ
L170	¡ºËÄ³µ¶µµ×Õó¡»*»¤ÎÀµÄÕÐ¼ÜÔö¼Ó£¨£«±ø·¨£¯£³£©£¬³ÖÐø20·ÖÖÓ
L180	¡ºÎå»¢ÔÜÑòÕó¡»ËùÓÐ»¤ÎÀ¸÷×Ô¹¥³öÒ»ÕÐ£¬Ö÷ÈË×ÔÎÒÃ¦ÂÒÒ»»ØºÏ
L200	¡ºÁù×ÓÁ¬·¼Õó¡»»¤ÎÀÎþÉü×Ô¼ºÀ´ÊÔÍ¼À§×¡¶ÔÊÖ£¬
		Èô³É¹¦µÐÈËÃ¦ÂÒÈý»ØºÏ£¬ÈôÊ§°ÜÔò»¤ÎÀËÀÍö
		´ËÌØ¼¼²»ÊÜ£Â£Õ£Ó£Ù·¨ÔòÖÐ£¹»ØºÏÐ§ÂÊÏÂ½µµÄÓ°Ïì£¬
L210	¡ºÆßÐÇÕ¶½«Õó¡»ËùÓÐ»¤ÎÀºÏÁ¦»÷³öÒ»ÕÐ£¬Ö÷ÈË×ÔÎÒÃ¦ÂÒÒ»»ØºÏ
		¶îÍâ¹¥»÷Á¦£½±ø·¨£ª£µ£¯£²
		¶îÍâÉËº¦Á¦£½²ÎÓë´ËÕÐ»¤ÎÀÊý£ª±ø·¨µÈ¼¶
		´ËÕÐÉ±ÉËÁ¦²»ÊÜ¶Ô·½Ìú²¼ÉÀµÄÓ°Ïì
L220	¡º°ËØÔ½ðËøÕó¡»* »¤ÎÀÎªÖ÷ÈËµ²×¡µÐÈËÉËº¦£¬CDT 30·ÖÖÓ£¬
		Ö÷ÈËËùÊÜÉËº¦£ª£³×ª¼Þµ½»¤ÎÀÉíÉÏ£¬³ÖÐø£²·ÖÖÓ
L230	¡º¾Åê×ÐÇŒmÕó¡»Ê¹³öÓñ»·£¬×ÔÉíÎÞÃ¦ÂÒ£¬CDT 15·ÖÖÓ
L250	¡ºÊ®ÃæÂñ·üÕó¡»ÔÚÒ»·ÖÖÓÄÚÔö¼ÓÁ½¸ö¶îÍâµÄ»¤ÎÀ£¬CDT 30·ÖÖÓ
ÆäÊ¹ÓÃ·½·¨·Ö±ðÎªdodge.yi£»dodge.er£»dodge.san£»dodge.si£»
dodge.wu£»dodge.liu£»dodge.qi£»dodge.ba£»dodge.jiu£»dodge.shi
*/

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform_1(object me, object target)
{
    int skill, num, i, duration,title,hate;
	object *team, *team1, *shiwei;
	mapping buff;
	string msg;
	
	object soldier,*enemy;
	int strategy,leadership;
	int timer;
		
	skill = me->query_skill("strategy",1);

    timer = 1800 - F_ABILITY->check_ability(me,"yi_add")*60;
    duration = me->query("timer/pfm/alert")-time() + timer;
    if ( duration >0) {
		tell_object(me,"Äã»¹ÐèÒªµÈ´ý"+(int)(duration/60)+"·ÖÖÓ×óÓÒ²ÅÄÜÔÙ´Î·¢¶¯Ò»×Ö³¤ÉßÕó¡£\n");
 		return 1;
 	}
 	
    if (ANNIE_D->check_buff(me,"lockfield") >= 1) {
		tell_object(me,"´ËµØµØÊÆ²»Àû£¬ÎÞ·¨·¢¶¯Ò»×Ö³¤ÉßÕó¡£\n");
		return 1;
	}
	
	if( !me->is_fighting() ){
        tell_object(me,"Ò»×Ö³¤ÉßÕóÖ»ÄÜÔÚÕ½¶·ÖÐ·¢¶¯£¡\n");
        return 1;
    }		
	
	if( me->query_temp("max_guard") > 1 ){
    	tell_object(me,"Ò»×Ö³¤ÉßÕóÕýÔÚ·¢¶¯£¡\n");
		return 1;
	}
	
	msg = BGRN + HIY "$N»Ó¶¯ÊÖÖÐÒøÇ¹£¬µ«¼ûÉíºó»¤ÎÀÒÆÐÎ»»Î»£¬ìºÆìÆ®Ò¡£¬¹ÄÉùÕóÕó£¬Ë²¼äÁÐ³ö"HIW"Ò»×Ö³¤ÉßÖ®Õó£¡\n" NOR HIB"
¹ö¹öÑÌÔÆÖÐ£¬Ò»ÈËºÚÒÂ¡¢ºÚÂí¡¢ºÚÆì£¬¾íÖÁ$NÉíÇ°½ÐµÀ£ºÕó·¨ÒÑ¶¯£¬½«¾üËÙÍË£¬´ýÄ©½«¶Ïºó£¡\n\n"NOR; 	

  	message_vision(msg, me);
  	me->set("timer/pfm/yue_array",time());
  	
  	seteuid(getuid());
	soldier= new("/obj/npc/danei_guard");
	soldier->set("possessed", me);
    soldier->set_leader(me);
      	   	
    soldier->set_name(WHT"ËÀÊ¿"NOR,({ "sishi" })); 
	soldier->move(environment(me));	
	soldier->invocation(me, (skill+ me->query_skill("leadership",1)));
		
	if (soldier) {       	
		    enemy = me->query_enemy();
		    if (enemy)
	    	for (i=0;i<sizeof(enemy);i++)
	    	{
	       		hate = enemy[i]->query_hate(me);
	       		enemy[i]->add_hate(soldier, hate);     	
	    	}   	
  			me->remove_all_killer();
        	me->add_temp("max_guard",1);
    }

    me -> set("timer/pfm/alert",time());      	        
    return 1;
}
	
int perform_2(object me, object target)
{
    int skill, num, i, duration;
	object *team, *team1, *shiwei;
	mapping buff;
	string msg;
		
	skill = me->query_skill("strategy",1);

    duration = me->query("timer/pfm/yue_array")-time() + 10;
	if (duration>0) {
        tell_object(me,"ÄãÐèÒªµÈ´ýÆ¬¿Ì£¨"+ duration +"Ãë£©²ÅÄÜÔÙ´Î±ä»ÃÕó·¨¡£\n");
        return 1;
    }
        
	if (me->query_temp("guard_count")<2) {
       	tell_object(me, "ÄãµÄ»¤ÎÀÌ«ÉÙ£¬ÁÐ²»³öÕó·¨Ò®¡£\n");
        return 1;
    }
    	
	msg = BGRN + HIY "$N"BGRN + HIY "»Ó¶¯ÊÖÖÐÒøÇ¹£¬µ«¼ûÉíºó»¤ÎÀÒÆÐÎ»»Î»£¬ìºÆìÆ®Ò¡£¬¹ÄÉùÕóÕó£¬Ë²¼äÁÐ³ö"HIW"¶þÁú¼³Ë®Ö®Õó£¡\n" NOR; 	
  	message_vision(msg, me);
  	me->set("timer/pfm/yue_array",time());
  	
	skill = skill/3;	
		
    if (ANNIE_D->check_buff(me,"array-iron"))
			ANNIE_D->debuff(me,"array-iron");
    
    shiwei = filter_array(all_inventory(environment(me)),
        		(: $1->query("possessed")==$2 && $1->query("id")=="huwei" :),me);
    num = sizeof(shiwei);	
	
	for (i=0; i<num; i++) {
		if (ANNIE_D->check_buff(shiwei[i],"yue_array"))
			ANNIE_D->debuff(shiwei[i],"yue_array");
		buff =
			([
				"caster":me,
				"who": shiwei[i],
				"type":"yue_array",
				"att": "bless",
				"name":"±ø·¨¡¤¶þÁú¼³Ë®Õó",
				"buff1":"apply/attack",
				"buff1_c":skill,
				"time": 1200,
				"buff_msg": "",		
				"disa_type":1,	
			]);
		ANNIE_D->buffup(buff);		
    }

    return 1;
}

int perform_3(object me, object target)
{
        int skill, num, i, duration;
	object *shiwei;
	mapping buff;
	string msg;
	
	int extra, maximum, gcount;
	object recruit;
	
	object *enemy;
		
        	
	skill = me->query_skill("strategy",1);

    duration = me->query("timer/pfm/yue_array")-time() + 10;
	if (duration>0) {
        tell_object(me, "ÄãÐèÒªµÈ´ýÆ¬¿Ì£¨"+ duration +"Ãë£©²ÅÄÜÔÙ´Î±ä»ÃÕó·¨¡£\n");
        return 1;
    }
    
    maximum = 2;
	if (me->query_skill("leadership",1)>= 250)	maximum = 4;
	else if (me->query_skill("leadership",1)>= 175) maximum = 3;
        	
    gcount=me->query_temp("guard_count");
	if(gcount>=maximum) {
		tell_object(me,"ÄãÏÖÔÚ²»ÐèÒªÁÐÈý²ÅÌìµØÈËÕó¡£\n",me);
        return 1;
   	}
   	        	
    if (userp(me) && me->is_fighting()) {
       	tell_object(me, "¸ÃÕó·¨ÔÚÕ½¶·ÖÐÊ¹ÓÃÃ»ÓÐÐ§¹ûµÄ¡£\n");
        return 1;
    }
    	
    duration = me->query_temp("timer/pfm/gf_san")-time() + 60;
	if (userp(me))
        if (duration>0) {
        	tell_object(me,"¡ºÈý²ÅÌìµØÈËÕó¡»Ã¿·ÖÖÓÖ»ÄÜÅÅÁ·Ò»´Î¡£\n");
        	return 1;
    }
    
	msg = BGRN + HIY "$N"BGRN + HIY "»Ó¶¯ÊÖÖÐÒøÇ¹£¬µ«¼ûÉíºó»¤ÎÀÒÆÐÎ»»Î»£¬ìºÆìÆ®Ò¡£¬¹ÄÉùÕóÕó£¬Ë²¼äÁÐ³ö"HIW"Èý²ÅÌìµØÈËÖ®Õó£¡\n" NOR YEL"
ºö¼ûÕóÍâÌÚÌÚÌÚ×ßÀ´Ò»Ãû×³Ê¿£¬ÆËµØ°Ýµ¹ÔÚ$N"NOR+YEL"ÉíÇ°£¬ÀÊÉùËµµÀ£º½«¾üÖ®Òå£¬Ìì¸ßË®³¤£¬
ÔÚÏÂ$nÔ¸ÔÚÕÊÇ°Ð§Á¦£¬ÎÀ¹úÉ±µÐ£¬ÍòËÀ²»´Ç¡£\n\n"NOR; 	
  	
  	extra=me->query_skill("strategy",1)+ me->query_skill("leadership",1);
	seteuid(getuid());
	recruit=new("/obj/npc/huwei");
	recruit->invocation(me,extra);
	recruit->move(environment(me));
	
  	message_vision(msg, me, recruit);
  	me->set("timer/pfm/yue_array",time());
  	me->set_temp("timer/pfm/gf_san",time());	 		
	me->add_temp("guard_count",1);
	if (!userp(me))
	{
		enemy = me->query_enemy();
		i = sizeof(enemy);
		while(i--) {
			if( enemy[i] && living(enemy[i]) ) {
				recruit->kill_ob(enemy[i]);
				if( userp(enemy[i]) ) enemy[i]->fight_ob(shiwei);
				else enemy[i]->kill_ob(recruit);
			}
		}
	}
        return 1;
}

int perform_4(object me, object target)
{
    int skill, num, i, duration;
	object *team, *team1, *shiwei;
	mapping buff;
	string msg;
		
	skill = me->query_skill("strategy",1);

    duration = me->query("timer/pfm/yue_array")-time() + 10;
	if (duration>0) {
        	tell_object(me,"ÄãÐèÒªµÈ´ýÆ¬¿Ì£¨"+ duration +"Ãë£©²ÅÄÜÔÙ´Î±ä»ÃÕó·¨¡£\n");
        	return 1;
    }
    
	if (me->query_temp("guard_count")<2) {
        	tell_object(me, "ÄãµÄ»¤ÎÀÌ«ÉÙ£¬ÁÐ²»³öÕó·¨Ò®¡£\n");
        	return 1;
    }
    
	msg = BGRN + HIY"$N"BGRN + HIY"»Ó¶¯ÊÖÖÐÒøÇ¹£¬µ«¼ûÉíºó»¤ÎÀÒÆÐÎ»»Î»£¬ìºÆìÆ®Ò¡£¬¹ÄÉùÕóÕó£¬Ë²¼äÁÐ³ö"HIW"ËÄ³µ¶µµ×Ö®Õó£¡\n" NOR; 	
  	message_vision(msg, me);
  	me->set("timer/pfm/yue_array",time());
  	
	skill = skill/3;	// 250/3 = 83
		
	if (ANNIE_D->check_buff(me,"array-iron"))
			ANNIE_D->debuff(me,"array-iron");
    
	// Well: SHiwei = shiwei + friend + myself:)
    shiwei = filter_array(all_inventory(environment(me)),
       		(: $1->query("possessed")==$2 && $1->query("id")=="huwei" :),me);
    
    num = sizeof(shiwei);	
	for (i=0; i<num; i++) {
		if (ANNIE_D->check_buff(shiwei[i],"yue_array"))
			ANNIE_D->debuff(shiwei[i],"yue_array");
		buff =
			([
				"caster":me,
				"who": shiwei[i],
				"type":"yue_array",
				"att": "bless",
				"name":"±ø·¨¡¤ËÄ³µ¶µµ×Õó",
				"buff1":"apply/parry",
				"buff1_c":skill,
				"time": 1200,
				"buff_msg": "",
				"disa_type":1,			
			]);
		ANNIE_D->buffup(buff);		
    }
    return 1;
}

int perform_5(object me, object target)
{
        int skill, num, i, duration, mod;
	string msg, name;
	object *env, *huwei, weapon;
	string *poem = ({"¡ºÁ¢ÂíÁÖ¸Ú»íÕ½íø£¬ÕóÔÆ¿ª´¦Ò»ÏªÁ÷¡»"HIY"Õó¶«×ª³öÒ»½«£¬",
"¡º»úô©Ë®Õ´ÓÌ´«½ú£¬ÊòÀë¹¬Í¥ÊëÃõÖÜ¡»"HIY"ÕóÎ÷×ª³öÒ»½«£¬",
"¡ºÄÏ·þÖ»½ñ¼ßÐ¡³ó£¬±±Ô¯ºÎÈÕ·µÉñÖÝ¡»"HIY"ÕóÄÏ×ª³öÒ»½«£¬",
"¡ºÊÄ½«Æß³ß³êÃ÷Ê¥£¬Å­Ö¸ÌìÑÄÀá²»ÊÕ¡»"HIY"Õó±±×ª³öÒ»½«£¬",
"¡º´ý´ÓÍ·£¬ÊÕÊ°¾ÉÉ½ºÓ¡»"HIY"ÕóÇ°×ª³öÒ»½«£¬",
"¡º³¯ÌìãÚ£¡¡»"HIY"Õóºó×ª³öÒ»½«£¬"
	});

	skill = me->query_skill("strategy",1);
             
    env = all_inventory(environment(me));
	huwei = filter_array(env, (: living($1) && $1->query("possessed")== $2
		&& $1->query("id")!="bodyguard" && $1->query("id")!="sishi"  :), me);
	if (!sizeof(huwei)) {
		tell_object(me, "ÄãµÄ»¤ÎÀ²»ÔÚ×ó½ü£¬ÎÞ·¨·¢¶¯¡ºÎå»¢ÔÜÑòê‡¡»\n");
		return 1;
	}
	
	msg = "\n"BGRN + HIY"$N"BGRN + HIY"»Ó¶¯ÊÖÖÐÒøÇ¹£¬µ«¼ûÉíºó»¤ÎÀÒÆÐÎ»»Î»£¬ìºÆìÆ®Ò¡£¬¹ÄÉùÕóÕó£¬Ë²¼äÁÐ³ö"HIW"Îå»¢ÔÜÑòÖ®Õó£¡"NOR HIR" 	

$N"HIR"×ÝÉùºÈµÀ£ºÐÛÆøÌÃÌÃ¹á¶·Å££¬ÊÄ½«Ö±½Ú±¨¾ý³ð¡£Õ¶³ýÍç¶ñ»¹³µ¼Ý£¬²»ÎÊµÇÌ³Íò»§ºî£¡
»°ÒôÎ´Âä£¬ÉíºóÖÚ½«ÆëÉùÓ¦ºÍ£¬ÉùÕðÔÆÏö¡£\n"NOR;
  	message_vision(msg, me);
  	me->set("timer/pfm/yue_array",time());
  	
  	for (i=0;i<sizeof(huwei);i++) {
  		if (huwei[i]->query_temp("is_unconcious") 
  			|| !huwei[i]->is_fighting(target)
  			|| huwei[i]->is_busy())	continue;
  			msg = HIW+poem[i]+ "ÅÄÂíÉÏÇ°Ö±È¡$n£¬"HIY"ÕýÊÇ" + huwei[i]->name()+"£¡\n"NOR;
  		if (huwei[i]->query("skill")== "spear" || huwei[i]->query("skill")=="hammer") {
  			huwei[i]->add_temp("apply/attack", skill*2);
  			huwei[i]->add_temp("apply/damage", skill);

  			COMBAT_D->do_attack(huwei[i],target, TYPE_PERFORM,msg);

  			huwei[i]->add_temp("apply/attack", -skill*2);
  			huwei[i]->add_temp("apply/damage", -skill);
  			
  			huwei[i]->perform_busy(1);
		}
  	}

	me->perform_busy(1);	
    return 1;
}

	
int main (object me, string arg1)
{
	
	int num,stra,lead,duration;
	string *zheng = ({ "¡ºÒ»×Ö³¤ÉßÕó¡»","¡º¶þÁú¼³Ë®Õó¡»","¡ºÈý²ÅÌìµØÈËÕó¡»","¡ºËÄ³µ¶µµ×Õó¡»","¡ºÎå»¢ÔÜÑòê‡¡»",
						"¡ºÁù×ÓÁ¬·¼Õó¡»","¡ºÆßÐÇÕ¶½«Õó¡»","¡º°ËØÔ½ðËøÕó¡»","¡º¾Åê×ÐÇŒmÕó¡»","¡ºÊ®ÃæÂñ·üÕó¡»"});
	int *zheng_r = ({100,150,160,170,180,200,210,220,230,250});
	string arg;
	object obj,target;
	
	if (userp(me))
    if (me->query("family/master_id")!="master yue" 
        || me->query("class")!="official")
        return notify_fail("Ö»ÓÐÔÀ·ÉµÄµÜ×Ó²ÅÄÜÊ¹ÓÃÕó·¨¡£\n");
    
    if (me->is_busy())
    	return notify_fail("ÄãÏÖÔÚÕýÃ¦£¬ÎÞ·¨Ê¹ÓÃÕó·¨¡£\n");
    	
   	if( environment(me)->query("no_fight"))
		return notify_fail("ÕâÀïÎÞ·¨Ê¹ÓÃÕó·¨¡£\n");

	if (!arg1)
		return notify_fail("ÄãÒªÊ¹ÓÃÄÄÒ»ÖÖÕó·¨£¿\n");

	if (sscanf(arg1,"%d on %s", num, arg)!= 2) {
		num = atoi(arg1);	
		if (num>10 || num <0)
			return notify_fail("Õó·¨ÕýÈ·Ê¹ÓÃ¸ñÊ½Îªzheng Êý×Ö(1-10) on ¶ÔÏó\n");
	}
	
	if (num>10 || num <0)
		return notify_fail("Õó·¨Ö»ÓÐ1-10ÖÖ£¬ÕýÈ·Ê¹ÓÃ¸ñÊ½Îªzheng Êý×Ö on ¶ÔÏó\n");

    stra = me->query_skill("strategy",1);
    lead = me->query_skill("leadership",1);
    
    if (stra < zheng_r[num-1] || lead < zheng_r[num-1])
    	return notify_fail(zheng[num-1]+"ÖÁÉÙÐèÒª"+ zheng_r[num-1]+"¼¶±ø·¨ºÍÓÃÈËÖ®¼¼¡£\n");
    	
    if (me->query_skill_mapped("force")!= "manjianghong")
    	return notify_fail(zheng[num]+"ÐèÒªÂú½­ºìÐÄ·¨Îª»ù´¡¡£\n");
    
    if (arg) {
    	if (!objectp(obj = present(arg, environment(me))))
			return notify_fail("´ËÈË²»ÔÚÄãµÄÖÜÎ§¡£\n");
		if (! obj->is_character())
			return notify_fail("¿´Çå³þÒ»µã£¬ÄÇ²¢²»ÊÇÉúÎï¡£\n");
		if (!living(obj))
			return notify_fail("¿´Çå³þÒ»µã£¬ÄÇ²¢²»ÊÇÉúÎï¡£\n"); 
	}
	
    if( (int)me->query("force") < 50 )    
       	return notify_fail("ÑÝ»¯Õó·¨ÖÁÉÙÐèÒª50µãÄÚÁ¦¡£\n");   	
    if (userp(me))
        	me->add("force", -50);

	// ±ä»¯Õó·¨ÖÁÉÙÐèÒª10ÃëÖÓµÄ¼ä¸ô
	duration = me->query("timer/pfm/yue_array")-time() + 10;
	if (duration>0 && num !=1)
       	return notify_fail("ÄãÐèÒªµÈ´ýÆ¬¿Ì£¨"+ duration +"Ãë£©²ÅÄÜÔÙ´Î±ä»ÃÕó·¨¡£\n");
    
    //	²¿·ÖÕó·¨ÖÁÉÙÐèÒª2¸ö»¤ÎÀ
    if (me->query_temp("guard_count")<2 && num == 5)
       	return notify_fail("ÄãµÄ»¤ÎÀÌ«ÉÙ£¬ÁÐ²»³öÕó·¨Ò®¡£\n");
    
    //	¹¥»÷ÐÔµÄÕó·¨Ö»ÄÜÔÚÕ½¶·ÖÐÊ¹ÓÃ
    target = obj;
    if (num == 5) {	    	    	
		if( !target ) target = offensive_target(me);
		if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
			return notify_fail(zheng[num-1]+"ÐèÒªÔÚÕ½¶·ÖÐÊ©Õ¹£¬Ä¿Ç°Äã²»ÔÚÕ½¶·ÖÐ£¬»òÊÇÄãÖ¸¶¨µÄ¶ÔÏóºÍÄã²¢²»ÔÚÕ½¶·ÖÐ¡£\n");
	}
	
	/*
	env = all_inventory(environment(me));
	huwei = filter_array(env, (: living($1) && $1->query("possessed")== $2
		&& $1->query("id")!="bodyguard" && $1->query("id")!="sishi"  :), me);
	if (!sizeof(huwei)) {
		tell_object(me, "ÄãµÄ»¤ÎÀ²»ÔÚ×ó½ü£¬ÎÞ·¨·¢¶¯¡ºÎå»¢ÔÜÑòê‡¡»\n");
		return 1;
	}*/
	
	CHANNEL_D->do_sys_channel("sys",sprintf("num= %O, target=%O",num, obj));

	switch (num) {
		case 1:	perform_1(me, target);break;
		case 2: perform_2(me, target);break;
		case 3:	perform_3(me, target);break;
		case 4: perform_4(me, target);break;
		case 5:	perform_5(me, target);break;
/*		case 6: perform_6(me, obj);break;
		case 7:	perform_7(me, obj);break;
		case 8: perform_8(me, obj);break;
		case 9:	perform_9(me, obj);break;
		case 10: perform_10(me, obj);break;	
	*/}
			
/*	
	if (userp(me))
	if (!COMBAT_D->legitimate_kill(me, obj)) {
		if (stringp(obj->query("NO_KILL")))
			return notify_fail(obj->query("NO_KILL"));
		if (stringp(obj->query("NO_PK")))
			return notify_fail(obj->query("NO_PK"));	
		else 
			return notify_fail("ÄãÎÞ·¨ÍµÏ®´ËÈË¡£\n");
	}*/
		
    
	return 1;
}


int help(object me)
{
write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	2word[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

´óÕÑ¸ßÉ®ÐÞÁ¶¹ÛÒôÃ÷Öäµ½170¼¶ÒÔÉÏºó£¬¿ÉÍ¬Ê±ËÌ³öÊý×ÖÕæÑÔ£¬
µ«ÊÇ£¬ÔÚÊ¹ÓÃÖ®Ç°±ØÐë¾²Ë¼Æ¬¿Ì¼ÇÒä¡£

¸ñÊ½¾ÙÀý£º¡¡2word an+an
ÓÖÈç£º	   2word an+ni

Ê¹ÓÃcast 2word ±ã¿É½«¼ÇÒä×¡µÄÕæÑÔÍ¬Ê±ËÌ³ö¡£

¶ÔÓÚ¶þ×ÖÕæÑÔÀ´Ëµ£¬ºÄ·ÑµÄ·¨Á¦×î¶à²»³¬¹ý400£¬Ôì³ÉµÄ×ÔÎÒÃ¦ÂÒ
×î¶à²»³¬¹ý4¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
HELP
    );
    return 1;
}