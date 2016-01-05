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
		if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
	} else
		return notify_fail("��ֻ���Բ쿴�Լ���״̬��\n");
			    
	   	task_level = F_LEVEL->get_level(ob->query("combat_exp"));
		task_num = F_LEVEL->level_to_pot(task_level)/10/50;
	    rewarded_task = ob->query("rewarded_task");
	    
	    
	my = ob->query_entire_dbase();

	printf(HIC"��"HIY"��������������������������������������������������������������������"HIC"��\n"NOR);
        printf( "   %s\n", ob->short(1) );
	printf(HIC"��"HIY"��������������������������������������������������������������������"HIC"��\n"NOR);
	
	
	line =  sprintf(" ��������%-8s\t�����塿%-10s��ɱ�������� %d��%d�� \n",
	           display_attr(my["str"], ob->query_str()),(ob->query("national")? ob->query("national") : "��"),
	           	my["MKS"],my["PKS"]	           	
	        );
	line += sprintf(" ���ٶȡ�%-8s\t���Ա�%-10s����ɱ������ %-12d \n",
	           display_attr(my["agi"], ob->query_agi()),ob->query("gender"),my["KILLED"]
	        );
	line += sprintf(" �����ʡ�%-8s\t�����䡿%-10s��ɱ���콾�� %-12d \n",
	           display_attr(my["con"], ob->query_con()),chinese_number(ob->query("age")),
	           sizeof(my["m_killer"])
	        );
	line += sprintf(" �����ǡ�%-8s\t�����ɡ�%-10s���ԣ��ӣˡ� %-12d \n",
	           display_attr(my["int"], ob->query_int()),
	           (my["family"]?(my["family"]["family_name"]? my["family"]["family_name"]:"��"):"��")
	           + (my["betrayer"]? sprintf("*%d",my["betrayer"]):""),
	            my["TASK"]
	        );
	line += sprintf(" ��������%-8s\t��ʦ����%-10s���ԣˡ��С���%d/%d�� \n",
	           display_attr(my["cps"], ob->query_cps()),
	           (my["family"]?(my["family"]["master_name"]? my["family"]["master_name"]:"��"):"��"),
	           rewarded_task, task_num 
	        );
	if ( !my["marry"]) 
	{
			line += sprintf(" ��������%-8s\t��������%-10s���ѣӣԡ��� %-8d��%d��\n",
		           display_attr(my["kar"], ob->query_kar()),
		           (my["divorced"]?(ob->query("gender") == "Ů��" ? "�Ѿ�":"����"):"δ��")
		           	+ (my["divorced"]? sprintf("*%d",my["divorced"]):""),
		            my["FINISH_QUEST"],
		            my["cont_quest"] 
		        );
	} else
	{
		line += sprintf(" ��������%-8s\t��%s��%-10s���ѣӣԡ��� %-8d��%d�� \n",
	           display_attr(my["kar"], ob->query_kar()),
	           (!ob->query("jiebai"))?(ob->query("gender") == "Ů��"? "�ɷ�":"����")
	           	: "����",
	            my["marry_name"],
	            my["FINISH_QUEST"],
	            my["cont_quest"],		
	        );
	}
		if (me->query("death/half_quest")<0) 
			line += sprintf(CYN"\n ��Ŀǰ��Լ����Ҫ���%d��������������������ۻ��������ͷ���\n ������ϴ�����ʱ������%dСʱ%d���ӡ�\n"NOR,
		          -(me->query("death/half_quest"))/REWARD_D->quest_reward(my["level"]),
		          (time()-me->query("death/time"))/3600, ((time()-me->query("death/time"))%3600)/60
		        );		 		
	/*
	                
        line += sprintf("\n ������Ʒ�� " HIR "%d\t\t" NOR, ob->query("created_item") );
        line += sprintf("���췿�䣺 " HIR "%d\n" NOR, ob->query("created_room") );*/
	
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
		line += sprintf(YEL"\n ��������%|12s�� %-14d"WHT"��ɱ�ˡ� %-d\n" NOR,
			SKILL_D(skill_type)->name(),
			attack_points + 1,
			basic_damage(ob));
	}
	else
		line += sprintf(HIG"\n ��������%|12s�� %-14d"WHT"��ɱ�ˡ� %-d\n" NOR,
			SKILL_D(skill_type)->name(),
			attack_points + 1,
			basic_damage(ob));	
	if (SKILL_D(parry_type)->type() == wptype)
		line += sprintf(HIG" ���мܣ�%|12s�� %-14d"WHT"�����ס� %-s\n" NOR,
			SKILL_D(parry_type)->name(),
			parry_points + 1, 
			basic_armor(ob) + "+" + ob->query_temp("apply/armor"));
	else
		line += sprintf(YEL" ���мܣ�%|12s�� %-14d"WHT"�����ס� %-s\n" NOR,
			SKILL_D(parry_type)->name(),
			parry_points + 1, 
			basic_armor(ob) + "+" + ob->query_temp("apply/armor"));
	if (dodge_type== "dodge")
		line += sprintf(YEL" �����㣺%|12s�� %-14d"WHT"�������� %-d\n" NOR,
			SKILL_D(dodge_type)->name(),
			dodge_points + 1,
			magic_points + 1);
	else
		line += sprintf(HIG" �����㣺%|12s�� %-14d"WHT"�������� %-d\n" NOR,
			SKILL_D(dodge_type)->name(),
			dodge_points + 1,
			magic_points + 1);
			       
	write(line);
	printf(HIC"��"HIY"��������������������������������������������������������������������"HIC"��\n"NOR);
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
		if (attacker->query("national")=="�ɹ���")	d1 += d_race;
		if (attacker->query("national")=="����")	d1 -= d_race;
				
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
				tell_object(attacker,HIR"ϵͳ��¼����Ĺ���/����״̬�����쳣������ͣ��Ϸ����������ʦ�㱨��
����������ʦ�����˳���Ϸ���µ�½����������BUGĲ���߽����ܷ��ƻ�ӭ��\n"NOR);
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
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	 score[0m
[0;1;37m����������������������������������������������������������������[0m   
      
���ָ�������ʾ��Ļ������ϣ�

���й����ԣ����ǣ������ȣ����μ� Help newbie

 [37m��������[32m�����ڳ����书��������Խ�ߣ���Խ������ս���л��ж��֣�
 	 ȡ������ľ���ȼ���ʹ�õ��书�����Լ�����״��������ʹ
 	 �ò�ͬ�ģ�������������������ı仯��
 
 [37m��ɱ�ˡ�[32m�����书�Ļ���ɱ��������ע���������������������ɱ�ˡ�
 	 �书��ʽ���������������壩���������Ե����أ���ֵ
 	 �����ο���ʵ�ʵ�ɱ�����������ڹ���Ч��������Ч����෽
 	 ������أ������նԵ�����ɵ��˺��������ķ���������ء�
 	 ͬʱ�˴����˺���Ϊƽ��ֵ��
 		
 [37m���мܡ�[32m�Գ����书�������м���������װ�����������ø������мܣ�
 	 �����֣����Զ�ʹ�ÿ����书�мܣ�ע�������������
 	 ���������书���������������ͬ�����ǻ�Դ����ඡ�
 	 �м�����Ҫȡ���ھ���ȼ�����Ч�мܼ��ܣ�������
 	 ������壩������״���Լ����ҵ���Զ�����������
 
 [37m�����㡿[32m�롾�мܡ����ƣ��Գ�����������������������ȡ���ھ����
 	 ������Ч���ܼ��ܣ������塡������壩������״����
 	 ���ҵ�����ٶ��Լ������� 		  
 
 [37m�����ס�[32m������������׵ȣ�ͬʱ�������������书�Ĺ�Ч��һ����˵��
 	��������ֱ�Ӽ��ٻ�������˵�ɱ����������ǰһ����������
 	��Դ���书�ķ���������һ�����־������εķ������� 
 
 [37m��������[32m�����г��˳�����书��ʽ�⣬���÷ḻ��ʵ�ħ������ȷ�
 	 �����书��������Ĳ���֮���������ȵ�Ѫ��������ֵĲ���
 	 �̵ȡ���Щ�ǳ����书�ķ�������ǰ���ᵽ�ġ��мܡ��޹أ�
 	 ����ȡ������ľ���ȼ������֮��������������Ҳ����͵�
 	 �ֵ���Բ�����ء�

[37m���ѣӣԡ���[32m��ָ�ѣ�����������������������˼�����־֮ʿЭ����
	�������Ƕ������ָ����ͻ�Ը���һЩ���£����Ҳ��ֻ��
	��Щ��ë��Ƥ��С�¶��������㾭��ȼ����������������ҲԽ
	����Խ�ѡ��������ѣ������Ƿ��������书�������Ҫ;����
	  ����С����������������������ĸ�����ÿ�����������
	  ��������������������ʱ�����Խ���ʹ��һЩ�����书���ο�
	  ����𡡣�����еģ��������ƾ�����
	  �������������[36m����ɫ[32m�ģ���˵�����������������������
	  ��һ�����ͣ�������һ��ʱ����ɫ���ظ�������
		
[37m���ԣ��ӣˡ�[32m
[37m���ԣˡ��С�[32m�ο�����𡡣�����Уԣ��������

[37m��ɱ���콾��[32m�������ڸ����ȼ��������ΣУý������콾����ɱ���콾
	�������ǳɳ�;�е�һ����̱������ܻ����Ӧ�Ľ�Ǯ�����۽�����

* �������������ǳ�������״̬

��1��[1;32mæ��[0m���׳�Busy�������ǶԶԷ�ʹ���ؼ����ǶԷ�æ�ң�Ҳ����
	���Լ�ʹ���ؼ��������æ�ң���æ��״̬�²��ܳ��У�ͬʱ����
	���мܡ����ܣ������������½�������score����쿴��
��2��[1;32m�ٶ�[0m����ʾΪ�����ٶۡ���ͬ��Ҳ�Ǵ��ؼ��в������縻��ɽ
	ׯ�������֣�ؤ���ʱ���������ٶۺ�æ��һ������ɷ���������
	���������ڳٶ�״̬����Ȼ���Գ��У��������������½�һЩ��

���ָ�� : hp

[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}
