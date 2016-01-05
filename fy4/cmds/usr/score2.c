// score.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// Last modification:
//		- 06/27/2001 by Daniel Q. Yu.
// Last modification:
//		- 02/25/2002 by neon

#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;

string display_attr(int gift, int value);
string status_color(int current, int max);
int basic_damage(object me);
int basic_armor (object me);

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
	object ob;
	mapping my;
	string line, str, skill_type, parry_type, dodge_type, wptype,jiebai,word1;
	object weapon;
	int attack_points, dodge_points, parry_points, magic_points;
	int task_level, task_num, rewarded_task;
	
	seteuid(getuid(me));

	if(!arg)
		ob = me;
	else if (wizardp(me)) {
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("ÄãÒª²ì¿´Ë­µÄ×´Ì¬£¿\n");
	} else
		return notify_fail("ÄãÖ»¿ÉÒÔ²ì¿´×Ô¼ºµÄ×´Ì¬¡£\n");
			    
	   	task_level = F_LEVEL->get_level(ob->query("combat_exp"));
		task_num = F_LEVEL->level_to_pot(task_level)/10/50;
	    rewarded_task = ob->query("rewarded_task");
	    
	    
	my = ob->query_entire_dbase();

	printf(HIC"¡Ô"HIY"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤"HIC"¡Ô\n"NOR);
        printf( "   %s\n", ob->short(1) );
	printf(HIC"¡Ô"HIY"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤"HIC"¡Ô\n"NOR);
	
	
	line =  sprintf(" ¡¾Á¦Á¿¡¿%-8s\t¡¾Ãñ×å¡¿%-10s¡¾É±ËÀÈËÊý¡¿ %d£¨%d£© \n",
	           display_attr(my["str"], ob->query_str()),(ob->query("national")? ob->query("national") : "ÎÞ"),
	           	my["MKS"],my["PKS"]	           	
	        );
	line += sprintf(" ¡¾ËÙ¶È¡¿%-8s\t¡¾ÐÔ±ð¡¿%-10s¡¾±»É±´ÎÊý¡¿ %-12d \n",
	           display_attr(my["agi"], ob->query_agi()),ob->query("gender"),my["KILLED"]
	        );
	line += sprintf(" ¡¾ÌåÖÊ¡¿%-8s\t¡¾ÄêÁä¡¿%-10s¡¾É±ËÀÌì½¾¡¿ %-12d \n",
	           display_attr(my["con"], ob->query_con()),chinese_number(ob->query("age")),
	           sizeof(my["m_killer"])
	        );
	line += sprintf(" ¡¾²ÅÖÇ¡¿%-8s\t¡¾ÃÅÅÉ¡¿%-10s¡¾£Ô£Á£Ó£Ë¡¿ %-12d \n",
	           display_attr(my["int"], ob->query_int()),
	           (my["family"]?(my["family"]["family_name"]? my["family"]["family_name"]:"ÎÞ"):"ÎÞ")
	           + (my["betrayer"]? sprintf("*%d",my["betrayer"]):""),
	            my["TASK"]
	        );
	line += sprintf(" ¡¾¶¨Á¦¡¿%-8s\t¡¾Ê¦¸¸¡¿%-10s¡¾£Ô£Ë¡££Ð¡¿£¨%d/%d£© \n",
	           display_attr(my["cps"], ob->query_cps()),
	           (my["family"]?(my["family"]["master_name"]? my["family"]["master_name"]:"ÎÞ"):"ÎÞ"),
	           rewarded_task, task_num 
	        );
	if ( !my["marry"]) 
	{
			line += sprintf(" ¡¾ÔËÆø¡¿%-8s\t¡¾»éÒö¡¿%-10s¡¾£Ñ£Ó£Ô¡£¡¿ %-8d£¨%d£©\n",
		           display_attr(my["kar"], ob->query_kar()),
		           (my["divorced"]?(ob->query("gender") == "Å®ÐÔ" ? "¹Ñ¾Ó":"÷¤¾Ó"):"Î´»é")
		           	+ (my["divorced"]? sprintf("*%d",my["divorced"]):""),
		            my["FINISH_QUEST"],
		            my["cont_quest"] 
		        );
	} else
	{
		line += sprintf(" ¡¾ÔËÆø¡¿%-8s\t¡¾%s¡¿%-10s¡¾£Ñ£Ó£Ô¡£¡¿ %-8d£¨%d£© \n",
	           display_attr(my["kar"], ob->query_kar()),
	           (!ob->query("jiebai"))?(ob->query("gender") == "Å®ÐÔ"? "ÕÉ·ò":"ÆÞ×Ó")
	           	: "½áÒå",
	            my["marry_name"],
	            my["FINISH_QUEST"],
	            my["cont_quest"],		
	        );
	}
		if (me->query("death/half_quest")<0) 
			line += sprintf(CYN"\n ÄãÄ¿Ç°´óÔ¼»¹ÐèÒªÍê³É%d¸öµ¥ÈËÌì»úÈÎÎñ²ÅÄÜÇå³ýÀÛ»ýµÄËÀÍö³Í·££¬\n Äã¾àÀëÉÏ´ÎËÀÍöÊ±¼äÒÑÓÐ%dÐ¡Ê±%d·ÖÖÓ¡£\n"NOR,
		          -(me->query("death/half_quest"))/REWARD_D->quest_reward(my["level"]),
		          (time()-me->query("death/time"))/3600, ((time()-me->query("death/time"))%3600)/60
		        );		 		
	/*
	                
        line += sprintf("\n ×ÔÔìÎïÆ·£º " HIR "%d\t\t" NOR, ob->query("created_item") );
        line += sprintf("×ÔÔì·¿¼ä£º " HIR "%d\n" NOR, ob->query("created_room") );*/
	
	wptype = objectp(weapon = ob->query_temp("weapon"))?
			weapon->query("skill_type"): "unarmed";
	skill_type = ob->query_skill_mapped(wptype);
	
	parry_type = ob->query_skill_mapped("parry");
	if (!stringp(parry_type))
		parry_type = "parry";
	if (wptype == "unarmed" 
		&& (parry_type == "parry" || SKILL_D(parry_type)->type()!= "unarmed")
		&& ob->query_skill_mapped("unarmed"))
		parry_type = ob->query_skill_mapped("unarmed");
	
	dodge_type = ob->query_skill_mapped("dodge");
	if (!stringp(dodge_type))
		dodge_type = "dodge";
			
	attack_points = COMBAT_D->skill_power(ob, SKILL_USAGE_ATTACK);
	// Condition modified
	if (ob->is_busy())	attack_points = 0;
	else if (ANNIE_D->check_buff(ob,"pseudo-busy"))	attack_points = attack_points * 2/3;
		
	//	Quest buff-atk
	if (ANNIE_D->check_buff(ob,"quest_atk"))
		attack_points = attack_points * (100 + ob->query_temp("apply/quest_atk"))/100;
	
	parry_points = COMBAT_D->skill_power(ob, SKILL_USAGE_PARRY);
	//	Quest buff-parry
	if (ANNIE_D->check_buff(ob,"quest_parry"))
		parry_points = parry_points * (100 + ob->query_temp("apply/quest_parry"))/100;
	// Condition modified
	if (ob->is_busy() || ANNIE_D->check_buff(ob,"pseudo-busy"))	
		parry_points = parry_points * 2/5;
	
	dodge_points = COMBAT_D->skill_power(ob, SKILL_USAGE_DODGE);
	if (ob->is_busy() || ANNIE_D->check_buff(ob,"pseudo-busy")){
		if (ob->query_skill_mapped("dodge") == "stormdance"
				&& ob->query("class") == "moon")
			dodge_points = dodge_points * 3/5;
		else	
			dodge_points = dodge_points * 2/5;
	}	
	
	magic_points = COMBAT_D->skill_power(ob, SKILL_USAGE_PERCEPTION);
	
	if (!stringp(skill_type)){
		skill_type = wptype;		
		line += sprintf(YEL"\n ¡¾¹¥»÷£º%|12s¡¿ %-14d"WHT"¡¾É±ÉË¡¿ %-d\n" NOR,
			SKILL_D(skill_type)->name(),
			attack_points + 1,
			basic_damage(ob));
	}
	else
		line += sprintf(HIG"\n ¡¾¹¥»÷£º%|12s¡¿ %-14d"WHT"¡¾É±ÉË¡¿ %-d\n" NOR,
			SKILL_D(skill_type)->name(),
			attack_points + 1,
			basic_damage(ob));	
	if (SKILL_D(parry_type)->type() == wptype)
		line += sprintf(HIG" ¡¾ÕÐ¼Ü£º%|12s¡¿ %-14d"WHT"¡¾»¤¼×¡¿ %-s\n" NOR,
			SKILL_D(parry_type)->name(),
			parry_points + 1, 
			basic_armor(ob) + "+" + ob->query_temp("apply/armor"));
	else
		line += sprintf(YEL" ¡¾ÕÐ¼Ü£º%|12s¡¿ %-14d"WHT"¡¾»¤¼×¡¿ %-s\n" NOR,
			SKILL_D(parry_type)->name(),
			parry_points + 1, 
			basic_armor(ob) + "+" + ob->query_temp("apply/armor"));
	if (dodge_type== "dodge")
		line += sprintf(YEL" ¡¾ÉÁ¶ã£º%|12s¡¿ %-14d"WHT"¡¾»¤·¨¡¿ %-d\n" NOR,
			SKILL_D(dodge_type)->name(),
			dodge_points + 1,
			magic_points + 1);
	else
		line += sprintf(HIG" ¡¾ÉÁ¶ã£º%|12s¡¿ %-14d"WHT"¡¾»¤·¨¡¿ %-d\n" NOR,
			SKILL_D(dodge_type)->name(),
			dodge_points + 1,
			magic_points + 1);
			       
	write(line);
	printf(HIC"¡Ô"HIY"©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤"HIC"¡Ô\n"NOR);
	return 1;
}

string display_attr(int gift, int value)
{
	if( value > gift ) return sprintf( HIY "%3d /%3d" NOR, value,gift );
	else if( value < gift ) return sprintf( HIR "%3d /%3d" NOR, value,gift );
	else return sprintf("%3d /%3d", value,gift);
}

string status_color(int current, int max)
{
	int percent;

	if( max ) percent = current * 100 / max;
	else percent = 100;

	if( percent > 100 ) return HIC;
	if( percent >= 90 ) return HIG;
	if( percent >= 60 ) return HIY;
	if( percent >= 30 ) return YEL;
	if( percent >= 10 ) return HIR;
	return RED;
}


// 	Eventually.. this should be directly quoted from COMBAT_D.
int basic_damage(object attacker)
{
	int str, damage, force_factor, bounce, att_combat_exp, weapon_damage;
	int d0,d1,d2,d3,d3x,d4,d5,d6,d7,d_race, d_1, d_2, d_3;		// Debug message.
	string force_skill, attack_skill, martial_skill;
	object attweapon;
	mixed tmp;
	function f;

	attweapon = attacker->query_temp("weapon");
	
	// Strength damage bonus. --- this is the combined effect of str + enforce.
	// if use weapon, effectiveness only 4/5
	str = attacker->query_str();
	if (str<= 90)
		d1 = str*str/10;
	else
		d1 = 810 + (str-90)* 9;
	
	d1 = d1 *3/4;	// Weapon or not..damage all reduced by 1/4
		
	// Let race factor take effect. 
	d_race = d1 /10;
		if (attacker->query("national")=="ÃÉ¹Å×å")	d1 += d_race;
		if (attacker->query("national")=="Âú×å")	d1 -= d_race;
				
	// Weapon damage consists of weapon_prop/damage + apply_temp/damage.
	d2 = attacker->query_temp("apply/damage") + 2;	
	
	// skill damage -- this is defined in individual skill.
	if(objectp(attweapon)) {
		attack_skill = attweapon->query("skill_type");
	} else {
		attack_skill = "unarmed";
	}
	if(stringp(martial_skill = attacker->query_skill_mapped(attack_skill) )) {
		d3 = SKILL_D(martial_skill)->damage_level(attacker);
		d3 = d3 * (d1 + d2) / 1000;	
	}
	
		// Quest_buff
	if (ANNIE_D->check_buff(attacker,"quest_dmg")) {
		d3x = (d1+d2) * attacker->query_temp("apply/quest_dmg")/100;
	}
		
	// Let combat exp take effect
	d7 = attacker->query("level");

	// Add damage bonus.
	d_1 = d1 + d2 + d3 + d3x + d7;

	if (ANNIE_D->check_buff(attacker,"damagecurse") < 1)
	{
		d_3 = d_1 *3/4;		// normally average = 75% 
	}
	else
	{
		if ((attacker->query_temp("buff/"+ANNIE_D->check_buff(attacker,"damagecurse")))["att"] == "curse")
		{
			d_3 = d_1/2;	// curse type curse, 50%,-25%
		}
		else			
		{
			d_3 = d_1; 	// blessing type damage curse, 100%,+25%
		}
	}
	
	if (ANNIE_D->check_buff(attacker,"weaken") >= 1)
		d_3-=d_3*attacker->query_temp("buffup/weakened")/100;
		
	damage = d_3;
	
	if(damage < 0) damage = 0;
	
	// add a log here	
	if (userp(attacker) && damage > 900) {
		if (attacker->query_temp("timer/high_dmg")+ 900 < time()) 
		{	
			log_file("SKILL_POWER_LOG", 
					sprintf("(%s)%s >900 damage: query_temp damage = %d, str = %d, enforce = %d. \n",
   					ctime(time()), 
   					attacker->name(1)+"("+ attacker->query("id")+")", 
   					attacker->query_temp("apply/damage"),
   					attacker->query("str"),
   					attacker->query("force_factor"),
				));	
			if (damage >1000)
				tell_object(attacker,HIR"ÏµÍ³¼ÇÂ¼£ºÄãµÄ¹¥»÷/·ÀÊØ×´Ì¬³öÏÖÒì³£¡£ÇëÔÝÍ£ÓÎÏ·£¬ÏòÔÚÏßÎ×Ê¦»ã±¨¡£
ÈôÎÞÔÚÏßÎ×Ê¦£¬ÇëÍË³öÓÎÏ·ÖØÐÂµÇÂ½¡£¹ÊÒâÀûÓÃBUGÄ²ÀûÕß½«²»ÊÜ·çÔÆ»¶Ó­¡£\n"NOR);
			attacker->set_temp("timer/high_dmg", time());
		}
	}
		
	return damage;
}


int basic_armor(object victim){
	
	int armor, eff_ness, absorb_vic;
	string absorb_skill;
	
	if(victim->query_skill("iron-cloth")) {
		absorb_skill = victim->query_skill_mapped("iron-cloth");
		if (absorb_skill) {
			if (!(eff_ness = SKILL_D(absorb_skill)->ic_effect()))
				eff_ness = 100;	
			absorb_vic = victim->query_skill("iron-cloth",1) /2
					+ victim->query_skill(absorb_skill) * eff_ness/200
					+ victim->query_temp("apply/iron-cloth");
		}else
		{
			absorb_skill = "iron-cloth";
			absorb_vic = victim->query_skill("iron-cloth",1) /2
							+ victim->query_temp("apply/iron-cloth");
		}
	} else
			absorb_vic = victim->query_temp("apply/iron-cloth");
	
	return absorb_vic;
}

int help(object me)
{
	write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	 score[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
      
Õâ¸öÖ¸Áî¿ÉÒÔÏÔÊ¾ÄãµÄ»ù±¾×ÊÁÏ£º

¡¡ÓÐ¹ØÊôÐÔ£¨²ÅÖÇ£¬Á¦Á¿µÈ£©£º²Î¼û Help newbie

 [37m¡¾¹¥»÷¡¿[32mÊÊÓÃÓÚ³£¹æÎä¹¦£¬¹¥»÷Á¦Ô½¸ß£¬¾ÍÔ½¿ÉÄÜÔÚÕ½¶·ÖÐ»÷ÖÐ¶ÔÊÖ£¬
 	 È¡¾öÓÚÄãµÄ¾­ÑéµÈ¼¶¡¢Ê¹ÓÃµÄÎä¹¦¼¼ÄÜÒÔ¼°ÉíÌå×´¿ö£¬³¢ÊÔÊ¹
 	 ÓÃ²»Í¬µÄ£å£î£á£â£ì£åÀ´¿´¿´¹¥»÷Á¦µÄ±ä»¯¡£
 
 [37m¡¾É±ÉË¡¿[32m³£¹æÎä¹¦µÄ»ù±¾É±ÉËÄÜÁ¦£¬×¢ÒâÕâÀï½ö°üÀ¨Á¦Á¿¡¢ÎäÆ÷É±ÉË¡¢
 	 Îä¹¦ÕÐÊ½¡¢¼ÓÁ¦£¨£å£î£æ£ï£ò£ã£å£©ºÍÃñ×åÌØÐÔµÄÒòËØ£¬ÊýÖµ
 	 ½ö¹©²Î¿¼£¬Êµ¼ÊµÄÉ±ÉËÁ¦»¹°üÀ¨ÄÚ¹¦ÌØÐ§¡¢ÎäÆ÷ÌØÐ§µÈÖî¶à·½
 	 ÃæµÄÒòËØ£¬¶ø×îÖÕ¶ÔµÐÊÖÔì³ÉµÄÉËº¦»¹ÓëËûµÄ·À»¤ÄÜÁ¦Ïà¹Ø¡£
 	 Í¬Ê±´Ë´¦µÄÉËº¦Á¦ÎªÆ½¾ùÖµ¡£
 		
 [37m¡¾ÕÐ¼Ü¡¿[32m¶Ô³£¹æÎä¹¦¹¥»÷µÄÕÐ¼ÜÄÜÁ¦£¬Èô×°±¸ÎäÆ÷£¬ÔòÓÃ¸ÃÎäÆ÷ÕÐ¼Ü£¬
 	 Èô¿ÕÊÖ£¬Ôò×Ô¶¯Ê¹ÓÃ¿ÕÊÖÎä¹¦ÕÐ¼Ü£¬×¢ÒâÈç¹ûÄã£å£î£á£â£ì£å
 	 £ð£á£ò£ò£ùµÄÎä¹¦ÓëÄãÊÖÀïµÄÎäÆ÷²»Í¬£¬¿ÉÊÇ»á³Ô´ó¿÷µÄà¶¡£
 	 ÕÐ¼ÜÁ¦Ö÷ÒªÈ¡¾öÓÚ¾­ÑéµÈ¼¶¡¢ÓÐÐ§ÕÐ¼Ü¼¼ÄÜ£¨£ð£á£ò£ò£ù
 	 £å£î£á£â£ì£å£©¡¢ÉíÌå×´¿öÒÔ¼°µÐÎÒµÄÏà¶Ô¶¨Á¦ºÍÔËÆø¡£
 
 [37m¡¾ÉÁ¶ã¡¿[32mÓë¡¾ÕÐ¼Ü¡¿ÀàËÆ£¬¶Ô³£¹æÎäÆ÷¹¥»÷µÄÉÁ±ÜÄÜÁ¦£¬È¡¾öÓÚ¾­ÑéµÈ
 	 ¼¶¡¢ÓÐÐ§ÉÁ±Ü¼¼ÄÜ£¨£ä£ï£ä£ç£å¡¡£å£î£á£â£ì£å£©¡¢ÉíÌå×´¿ö¡¢
 	 µÐÎÒµÄÏà¶ÔËÙ¶ÈÒÔ¼°ÔËÆø¡£ 		  
 
 [37m¡¾»¤¼×¡¿[32m´©´÷µÄÒÂÎï¿ø¼×µÈ£¬Í¬Ê±°üÀ¨Ìú²¼ÉÀÀàÎä¹¦µÄ¹¦Ð§£¬Ò»°ãÀ´Ëµ£¬
 	¡¡»¤¼×ÄÜÖ±½Ó¼õÉÙ»òµÖÏûµÐÈËµÄÉ±ÉËÁ¦¡£ÆäÖÐÇ°Ò»¸öÊý×ÖÊÇÀ´
 	¡¡Ô´ÓÚÎä¹¦µÄ·À»¤Á¦£¬ºóÒ»¸öÊý×Ö¾ÍÊÇÒÂÊÎµÄ·À»¤Á¦¡£ 
 
 [37m¡¾»¤·¨¡¿[32m·çÔÆÖÐ³ýÁË³£¹æµÄÎä¹¦ÕÐÊ½Íâ£¬»¹ÓÃ·á¸»¶à²ÊµÄÄ§·¨ÖäÓïµÈ·Ç
 	 ³£¹æÎä¹¦£¬ÈçÈýÇåµÄ²ÔÁéÖ®¼ý£¬µÛÍõ¹ÈµÄÑª½µ¡¢¿ì»îÁÖµÄ²ÐÔÆ
 	 ±ÌµÈ¡£ÕâÐ©·Ç³£¹æÎä¹¦µÄ·ÀÓùÁ¦ÓëÇ°ÃæÌáµ½µÄ¡¾ÕÐ¼Ü¡¿ÎÞ¹Ø£¬
 	 ¶øÊÇÈ¡¾öÓÚÄãµÄ¾­ÑéµÈ¼¶¡¢¹í¹ÈÖ®µÀ¡¢ÉÁ±ÜÄÜÁ¦£¬Ò²ÓëÄãºÍµÐ
 	 ÊÖµÄÏà¶Ô²ÅÖÇÏà¹Ø¡£

[37m¡¾£Ñ£Ó£Ô¡£¡¿[32m¡¡Ö¸£Ñ£õ£å£ó£ô£¬·çÔÆÂÒÊÀ£¬Ìì»úÀÏÈË¼±ÐèÓÐÖ¾Ö®Ê¿Ð­Öú£¬
	¡¡µ½ËûÄÇ¶ùÊäÈë´ËÖ¸Áî£¬Ëû¾Í»á·Ô¸ÀÄãÒ»Ð©²îÊÂ£¬×î³õÒ²ÐíÖ»ÊÇ
	¡¡Ð©¼¦Ã«ËâÆ¤µÄÐ¡ÊÂ¶ù£¬Ëæ×ÅÄã¾­ÑéµÈ¼¶µÄÔö¸ßÌì»úµÄÈÎÎñÒ²Ô½
	¡¡À´Ô½ÄÑ¡£¡£¡£¡££Ñ£õ£å£ó£ôÊÇ·çÔÆÔö¼ÓÎä¹¦¾­ÑéµÄÖ÷ÒªÍ¾¾¶¡£
	  ºóÃæÐ¡À¨ºÅÀïµÄÊÇÄãÁ¬ÐøÍê³ÉÈÎÎñµÄ¸öÊý£¬Ã¿µ±ÄãÁ¬ÐøÍê³É
	  £µ¡¢£±£°¡¢£±£µ¸öÈÎÎñÊ±£¬¿ÉÒÔ½±ÀøÊ¹ÓÃÒ»Ð©ÌØÊâÎä¹¦£¨²Î¿´
	  £è£å£ì£ð¡¡£ç£á£í£åÖÐµÄ£±£µ£®·çÔÆ¾ø¼¼£©
	  Èç¹ûÕâÏîÊý×ÖÊÇ[36m°µÇàÉ«[32mµÄ£¬ÔòËµÃ÷Äã×î½üËÀÍö¹ý£¬ÈÎÎñ½±Àø»á
	  ÓÐÒ»¶¨½µµÍ£¬¼ÌÐø×öÒ»¶ÎÊ±¼äÑÕÉ«±ã»á»Ø¸´Õý³£¡£
		
[37m¡¾£Ô£Á£Ó£Ë¡¿[32m
[37m¡¾£Ô£Ë¡££Ð¡¿[32m²Î¿´£è£å£ì£ð¡¡£ç£á£í£åÖÐ£Ô£á£ó£ëµÄÄÚÈÝ

[37m¡¾É±ËÀÌì½¾¡¿[32m·çÔÆÖÐÔÚ¸÷¸öµÈ¼¶¶¼ÓÐÐí¶à£Î£Ð£Ã½Ð×ö¡°Ìì½¾¡±£¬É±ËÀÌì½¾
	¡¡²»½öÊÇ³É³¤Í¾ÖÐµÄÒ»¸öÀï³Ì±®£¬»¹ÄÜ»ñµÃÏàÓ¦µÄ½ðÇ®ºÍÆÀ¼Û½±Àø¡£

* ·çÔÆÖÐÓÐÁ½¸ö·Ç³£³£¼ûµÄ×´Ì¬

£¨1£©[1;32mÃ¦ÂÒ[0m£ºË×³ÆBusy£¬¿ÉÒÔÊÇ¶Ô¶Ô·½Ê¹ÓÃÌØ¼¼¶øÊÇ¶Ô·½Ã¦ÂÒ£¬Ò²¿ÉÄÜ
	ÊÇ×Ô¼ºÊ¹ÓÃÌØ¼¼ºóµÄ×ÔÎÒÃ¦ÂÒ£¬ÔÚÃ¦ÂÒ×´Ì¬ÏÂ²»ÄÜ³öÕÐ£¬Í¬Ê±·ÀÊØ
	£¨ÕÐ¼Ü¡¢ÉÁ±Ü£©ÄÜÁ¦»á´ó·ù¶ÈÏÂ½µ£¬¿ÉÓÃscoreÃüÁî²ì¿´¡£
£¨2£©[1;32m³Ù¶Û[0m£ºÏÔÊ¾Îª¡¶Éí·¨³Ù¶Û¡·£¬Í¬ÑùÒ²ÊÇ´ÓÌØ¼¼ÖÐ²úÉú£¬Èç¸»¹óÉ½
	×¯µÄÇÜÁúÊÖ£¬Ø¤°ïµÄÊ±³ËÁùÁú£¬³Ù¶ÛºÍÃ¦ÂÒÒ»Ñù»áÔì³É·ÀÊØÄÜÁ¦ÏÂ
	½µ£¬µ«ÊÇÔÚ³Ù¶Û×´Ì¬ÖÐÈÔÈ»¿ÉÒÔ³öÕÐ£¬²»¹ý¹¥»÷Á¦»áÏÂ½µÒ»Ð©¡£

Ïà¹ØÖ¸Áî : hp

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
HELP
    );
    return 1;
}
