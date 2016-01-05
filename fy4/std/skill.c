// Skill.c
// Copyright (C) 1995 - 2005, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
// 
// This is the standard skill daemon object. All objects defining a skill
// should inherit this as its skeleton.
// 
// Last modification:
//		- 08/08/2001 by Daniel Q. Yu.
//			* Rewriten the whole thing.			
//		- 07/16/2004
//			* Moved force effect in hit_ob() to combatd.c
//			* (*)means this coeffience is no longer used in 4.1+ version
/*		- 7/24/2004
		fy4.1 �� skill �ı䶯: --- by Silencer

		- 9.1.2004
		eff_level �ޜʞ�eff_level��eff_learn_level��eff_parry_level

		-6.2005
		Remove shiled restriction
		���޶�����ǰ�����Ķ� /doc/wiz/fy41_skills.txt	

*/

inherit F_CLEAN_UP;

mapping skill_attr = ([
	"name" 				: "�书",
	"type" 				: "martial",
	"usage/animal-training" 	: 0,
	"usage/axe"			: 0,
	"usage/blade"			: 0,
	"usage/cursism"			: 0,
	"usage/dagger"			: 0,
	"usage/dodge"			: 0,
	"usage/force"			: 0,
	"usage/fork"         		: 0,
	"usage/hammer"      		: 0,
	"usage/herb"			: 0,
	"usage/iron-cloth"		: 0,
	"usage/literate"		: 0,
	"usage/magic"			: 0,
	"usage/move"			: 0,
	"usage/parry"			: 0,
	"usage/scratching"		: 0,
	"usage/spear"			: 0,
	"usage/spells"			: 0,
	"usage/staff"			: 0,
	"usage/stealing"		: 0,
	"usage/sword"			: 0,
	"usage/throwing"		: 0,
	"usage/unarmed" 		: 0,
	"usage/whip"			: 0,
	"usage/musket"			: 0,
		
	"effective_level" 		: 100,	// �书ϵ��
	"eff_learn_level" 		: -1,	// ѧϰϵ��
	"eff_parry_level" 		: -1,	// �м�ϵ��

	"skill_class"			: 0,	// �书����
	"difficulty"			: 100,	// �书ѧϰ�Ѷ�
	"difficulty_r"			: 0,	// �书�о��Ķ����Ѷȣ���
	"damage_level"			: 0,	// ���˺����Ͽ��˼��ܵĵȼ�������ԭ����action[damage]
							 // (0-100������ʽ�Ķ����˺�= level/100)
	"accuracy_level"		: 0, 	// ���������Ͽ��˼��ܵĵȼ�������ԭ����action[dodge/parry]
							 // (0-100������ʽ�Ķ��⹥����=level/100)
	
	"practice_damage" 		: 10,	// practice �ķѵ�����
	"practice_force"		: 5,	// practice �ķѵ�����
	"practice_limit"		: 1,	// ��ߵ� practice �ȼ�
	
	"bounce_ratio"			: 0,	// �����ķ���ָ��
	"ic_effect"			: 100,	// ������ʵ����Чָ��

/*
	"learn_bonus" 			: 0,	// how easy the skill can be learned	 (*)
        "practice_bonus" 		: 0,	// how easy the skill can be practiced . (*)
	"black_white_ness" 		: 0,	// whether the skill is good or evil 	 (*)
						 (*) No longer exists in FY4.1+ */						
	"no_refund":			"none",
]);



mapping *action;

void set(string prop, mixed value);
void setup();

void create() {
	seteuid(getuid());
	setup();
}

void setup() {
	
}

void set(string prop, mixed value) {
	skill_attr[prop] = value;
}

int valid_effect(object me, object weapon, string action_name, int skill) 
{ 
	return 1;
}


// 	�书��
string name() {
	return (string)skill_attr["name"];
}

// type() == "knowledge", "martial"���������书�ģ�, "force", "spells", "magic", "iron-cloth",
//		"spear/sword/...", "herb", "cursism", etc.
string type() { 
	return (string)skill_attr["type"]; 
}

// 	Default 100, �书ϵ��
int effective_level(object me) {
	return (int)skill_attr["effective_level"];
}

// 	Default 100, �书ѧϰϵ��
int eff_learn_level(object me) {
	if ((int)skill_attr["eff_learn_level"] > 0 )
		return (int)skill_attr["eff_learn_level"];
	else
//		return (int)skill_attr["effective_level"];
		return effective_level(me);	
}

// 	Default 100, �书�м�ϵ��
int eff_parry_level(object me) {
	if ((int)skill_attr["eff_parry_level"] > 0)
		return (int)skill_attr["eff_parry_level"];
	else
//		return (int)skill_attr["effective_level"];	It could be changed in individual file.
		return effective_level(me);
}

//	ѧϰ�Ѷȣ���������--�������书�������书Ϊ100�������书Ϊ200�����׾���Ⱦ��Լ�����
int skill_difficulty() {
	return (int)skill_attr["difficulty"];
}

//	�о��˼��ܵ��Ѷȣ�������skill_difficulty��defaultΪ�㣬
int skill_difficulty_r(){
	return skill_attr["skill_difficulty_r"];
}

//	������������Ϊ��ȡ��ԭ�����������ļ��в�ͬ��ʽ��action[dodge/parry/force/damage]
//	ԭ�����������ɵ���ʵ��--������û��֪��������ܵ����Ǽ����ģ�
//	���ڲ�����������������martial skills��
//	damage_level ���Ǹü�����ÿ�еĸ����˺�����һ�������ձ������ڸ����������У�
//		0-100����0--�޸�����ʽ�˺���100==����100%��������enforce�������ۺϣ����˺�
//	accuracy_level�ǶԹ����ʵ�������һ���ᳫ��effect_level�����ƣ������򲻵��Ѳ��ô˲�����
//		��Ȼ�����д��effect_level=50�ļ�����accuracy����ߣ�������ܻ��ҡ�

int damage_level(object me){
	return skill_attr["damage_level"];
}

int accuracy_level(object me){
	return skill_attr["accuracy_level"];
}

//	������书�ķ���ϵ��
int bounce_ratio()
{
	return skill_attr["bounce_ratio"];
}

// 	������书��ʵ��Ч������Ҫ��������nerfϴ���
int ic_effect() {
	return (int)skill_attr["ic_effect"];
}

// 	�Ƿ���� refund ��Ǳ��
string refundable(){
	return (skill_attr["no_refund"]);
}

// 	���书����ϰ����߼���defaultΪ0����Ҫ����Լ���
int practice_limit() {
	return (int)skill_attr["practice_limit"];
}

/*	�书�������ɱ𣬻���Ϊ4��
	1.���һ�����ɣ���ninja/tieflag/huangshan��
	2.task	���ǿ��ܽ��ܵõ���
	3.npc	NPCר�õģ����ñȽ�����
	4.basic Ϊ��������
*/
string skill_class() {
	return (string)skill_attr["skill_class"];
}

//
// valid_learn()
//
// This function is to check if a character should be able to 
// learn/study/practice the skill. The default function just
// returns 1 to allow any characters improve the skill. However,
// a good skill should has its own feature and restriction. Redefine
// this function in your skill object and make it reasonable 
// according to the power of the skill.

int valid_learn(object me) { 
	object weapon, s_weapon;
	string* w_skills = ({ "axe", "blade", "dagger", "fork", "hammer", "spear", 
			"staff", "sword", "throwing", "whip", "musket" }); 
	int i;

	weapon = me->query_temp("weapon");
	s_weapon = me->query_temp("secondary_weapon");
	if(skill_attr["usage/unarmed"] || base_name(this_object()) == SKILL_D("unarmed")) {
		if(weapon || s_weapon) {
			return notify_fail("ѧϰ����ϰ" + skill_attr["name"] + "������֡�\n");
		}
	} 
	for(i=0; i<sizeof(w_skills); i++) {
		if(skill_attr["usage/" + w_skills[i]] 
				|| base_name(this_object()) == SKILL_D(w_skills[i])) {			
			if(!objectp(weapon) && !objectp(s_weapon)) {
				return notify_fail("�����޷�ѧϰ����ϰ" + skill_attr["name"] + "��\n");
			} 
			if((!objectp(weapon) || weapon->query("skill_type") != w_skills[i])
				&& (!objectp(s_weapon) || s_weapon->query("skill_type") != w_skills[i])) {
				return notify_fail("����ʹ��" + weapon->name() + "ѧϰ����ϰ" + skill_attr["name"] + "��\n");
			}
		}
	}
	return 1;
}

//
// skill_improved()
//
// This function is called when a character's skill has gained a new level.
// You can make some modify to a character according to the skill.

void skill_improved(object me) {}

mapping query_action(object me, object weapon) {
	if(sizeof(action) > 0) {
		return action[random(sizeof(action))];
	}
}

string query_absorb_msg() {
	mapping msg;

	msg = skill_attr["absorb_msg"];
	
	if(sizeof(msg) > 0) {	
		return msg[random(sizeof(msg))];
	}
	
	return 0;
}

string query_dodge_msg() {
	mapping msg;

	msg = skill_attr["dodge_msg"];
	
	if(sizeof(msg) > 0) {	
		return msg[random(sizeof(msg))];
	}
	
	return 0;
}

string query_parry_msg(object weapon) {
	mapping msg;
	
	if(objectp(weapon)) {
		msg = skill_attr["parry_msg"];
	}
	
	if(sizeof(msg) == 0) {
		msg = skill_attr["unarmed_parry_msg"];
	}
	
	if(sizeof(msg) > 0) {
		return msg[random(sizeof(msg))];
	}
	
	return 0;
}


int valid_enable(string usage) {
	return skill_attr["usage/" + usage];
}


int practice_skill(object me) {
	object weapon;

	if(skill_attr["type"] == "knowledge" 
		|| skill_attr["type"] == "force" 
		|| skill_attr["type"] == "iron-cloth"
		) {
		return notify_fail(skill_attr["name"] + "�������⣬ֻ����Ǳ����ѧϰ��\n");
	}
	
	if((int)me->query("kee") < skill_attr["practice_damage"]) {
		return notify_fail("�������������" + skill_attr["name"] + "����������Ϣ��Ϣ�ɡ�\n");
	}
	
	if((int)me->query("force") < skill_attr["practice_force"]) {
		return notify_fail("�������������" + skill_attr["name"] + "����������Ϣ��Ϣ�ɡ�\n");
	}
	
	me->receive_damage("kee", skill_attr["practice_damage"]);
	me->add("force", -skill_attr["practice_force"]);
	return 1;
}

//
// exert_function()
//
//     This function is used by the "exert" command as specific skill's 
// command parser. This function parses the arguments in the standard form
// (that is, exert <function> [<target>] [<amount>]). When <target> is not 
// present, use the character himself as default. When amount is not present
// use default amount which is different for each function.
//     In order to use this default exert command parser, you must define
// a function called exert_function_file(string func) in the skill object
// that takes the function name as argument and return the file name that
// defines the specified function. 

int exert_function(object me, string arg) {
	string func, target, file;
	object target_ob;
	int    amount;

	amount = -1;
/*	if(sscanf(arg, "%s %s %d", func, target, amount)==3) {
		target_ob = present(target, environment(me));
		if(!target_ob) {
			return notify_fail("����û�� " + target + "��\n");
		}
	} else */
		
	if(sscanf(arg, "%s %d", func, amount)==2) {
		target_ob = me;
	} else if(sscanf(arg, "%s %s", func, target)==2) {
		target_ob = present(target, environment(me));
		if(!target_ob) {
			return notify_fail("����û�� " + target + "��\n");
		}
		if (!COMBAT_D->legitimate_buff(me, target_ob))
    			return notify_fail("�㲻�������ʹ�ô��ķ���������ɱ���ƣ�\n");
	} else {
		func = arg;
		target_ob = me;
	}
	
	notify_fail("����ѡ�õ��ڹ���û�����ּ��ܡ�\n");
/*	if((func == "heal") 		-- No more check... let player decide it.
			&& target_ob->query("eff_kee") == target_ob->query("max_kee")) {
		return notify_fail("�������Ҫ���˵Ķ���û�������ˡ�\n");
	}
	if((func == "lifeheal") 
			&& target_ob->query("kee") == target_ob->query("max_kee")) {
		return notify_fail("�������Ҫ���˵Ķ���û�����ˡ�\n");
	}*/
	
	if(stringp(skill_attr["skill_class"])) {
		file = replace_string(file_name(this_object()), SKILL_D(""), 
				CLASS_D(skill_attr["skill_class"] + "/")) + "/" + func + ".c";
		if(file_size(file) > 10) {
			return (int)call_other(file, "exert", me, target_ob, amount);
		}
	}
	file = CLASS_D("GENERIC/FORCE/") + func + ".c";
	if(file_size(file) > 10) {
		return (int)call_other(file, "exert", me, target_ob, amount);
	}
	return 0;
}

int perform_action(object me, string arg) {
	string action, target, file, msg, mate;
	object target_ob,friend_ob;
	object weapon;
	int i;
	
	if( sscanf(arg, "%s %s with %s", action, target, mate) == 3) { 
		target_ob = present(target, environment(me));
		if( !target_ob ) 
			return notify_fail("����û��Ŀ�� " + target + "��\n");
		friend_ob = present(mate, environment(me));
		if (!friend_ob) 
			return notify_fail("����û��ͬ�� " + mate + "��\n");
		if (!COMBAT_D->legitimate_buff(me, target_ob))
    			return notify_fail("�㲻�������ʹ�ô��ؼ���������ɱ���ƣ�\n");
		if (!COMBAT_D->legitimate_buff(me, friend_ob))
    			return notify_fail("�㲻�ܺʹ���һ��ʹ�ô��ؼ���������ɱ���ƣ�\n");
	} else if ( sscanf(arg, "%s with %s", action, mate)==2 ) {
		friend_ob = present(mate, environment(me));
		if (!friend_ob) 
			return notify_fail("ͬ�� " + mate + " ������ߡ�\n");
		if (!COMBAT_D->legitimate_buff(me, friend_ob))
    			return notify_fail("�㲻�ܺʹ���һ��ʹ�ô��ؼ���������ɱ���ƣ�\n");
	} else if(sscanf(arg, "%s %s", action, target)==2 ) {
		target_ob = present(target, environment(me));
		if( !target_ob ) {
			return notify_fail("Ŀ�� " + target + " �������\n");
		}
		if (!COMBAT_D->legitimate_buff(me, target_ob))
    			return notify_fail("�㲻�������ʹ�ô��ؼ���������ɱ���ƣ�\n");
	} else {
		action = arg;
	}
	
	notify_fail("����ѡ�õ��书��û�����ֱ�ɱ����\n");
	
	if (me->query_temp("till_death/lockup")==1)
    	{	
    		if (stringp(msg = me->query_temp("till_death/lockup_msg")))
    			return notify_fail (msg);
    		else
    			return notify_fail("����Ѫ���������������ͣ�һʱ��Ȼ�˲����⹦����\n");  
	}
//	if (me->query_temp("till_death/shield_lock")==1)
//    		return notify_fail(" ��ʹ�û�������ʱ���ܷ��ġ���\n"); 

	if( me->is_busy() )
        	return notify_fail("����������æ���ء��� \n");
	
	if(stringp(skill_attr["skill_class"])) {
		file = replace_string(file_name(this_object()), SKILL_D(""), 
				CLASS_D(skill_attr["skill_class"] + "/")) + "/" + action + ".c";
		if(file_size(file) > 10) {
			return (int)call_other( file, "perform", me, target_ob, friend_ob);
		}
	}
	file = CLASS_D("GENERIC/PERFORM/") + action + ".c";
	if(file_size(file) > 10) {
		return (int)call_other( file, "perform", me, target_ob, friend_ob);
		
	}
	return 0;
}

int perform_target(object me,string perform,object target)
{
	string file;
	string s_type;
	object weapon;
	
	notify_fail("����ѡ�õ��书��û�����ֱ�ɱ����\n");

	
	weapon=me->query_temp("weapon");
	if(objectp(weapon))
		s_type=weapon->query("skill_type");
	else
		s_type="unarmed";
	if(!skill_attr["usage/"+s_type]&&!skill_attr["usage/dodge"])
		return notify_fail(" skill not matched\n");
  	if (me->query_temp("till_death/lockup")==1)
    		return notify_fail(" ����Ѫ���������������ͣ�һʱ��Ȼ�˲����⹦����\n");  
//	if (me->query_temp("till_death/shield_lock")==1)
//    		return notify_fail(" ��ʹ�û�������ʱ���ܷ��ġ���\n"); 
    if( me->is_busy() )
       	return notify_fail("����������æ���ء��� \n");  		
	
	if(stringp(skill_attr["skill_class"])) {
		file = replace_string(file_name(this_object()), SKILL_D(""), 
				CLASS_D(skill_attr["skill_class"] + "/")) + "/" + perform + ".c";
		if(file_size(file) > 10) {
			return (int)call_other(file, "perform", me, target);
		}
	}
	file = CLASS_D("GENERIC/PERFORM/") + perform + ".c";
	if(file_size(file) > 10) {
		return (int)call_other(file, "perform", me, target);
	}
	return 0;
}

int cast_spell(object me, string spell, object target) {
	string file, msg;

  	if (me->query_temp("till_death/lockup")==1)
  	{	
    		if (stringp(msg = me->query_temp("till_death/lockup_msg")))
    			return notify_fail (msg);
    		else
    			return notify_fail(" ����Ѫ���������������ͣ�һʱ��Ȼ���������ġ���\n");  
	}		
//	if (me->query_temp("till_death/shield_lock")==1)
//    		return notify_fail(" ��ʹ�û�������ʱ���ܷ��ġ���\n"); 
    	if( me->is_busy() )
        	return notify_fail("����������æ���ء��� \n");  		
	
	if (objectp(target))
	if (!COMBAT_D->legitimate_buff(me, target))
    		return notify_fail("�㲻�������ʹ�ô����ģ�������ɱ���ƣ�\n");

	notify_fail("����ѡ�õ�����ϵ��û���������ġ�\n");
		    			
	if(stringp(skill_attr["skill_class"])) {
		file = replace_string(file_name(this_object()), SKILL_D(""), 
				CLASS_D(skill_attr["skill_class"] + "/")) + "/" + spell + ".c";
		if(file_size(file) > 10) {
			return (int)call_other(file, "cast", me, target);
		}
	}
	file = CLASS_D("GENERIC/CAST/") + spell + ".c";
	if(file_size(file) > 10) {
		return (int)call_other(file, "cast", me, target);
	}
	return 0;
}

int curse_curses(object me, string curse, object target) {
	string file, msg;
	
	notify_fail("����ѡ�õĽ�ͷ����û�����ֽ�ͷ��\n");
	
	if (me->query_temp("till_death/lockup")==1)
  	{	
    		if (stringp(msg = me->query_temp("till_death/lockup_msg")))
    			return notify_fail (msg);
    		else
    			return notify_fail(" ����Ѫ���������������ͣ�һʱ��Ȼ�²��˽�ͷ����\n");  
	}		
    		
//	if (me->query_temp("till_death/shield_lock")==1)
//    		return notify_fail(" ��ʹ�û�������ʱ���ܷ��ġ���\n"); 
    	if( me->is_busy() )
        	return notify_fail("����������æ���ء��� \n");
    	
    	if (objectp(target))
	if (!COMBAT_D->legitimate_buff(me, target))
    		return notify_fail("�㲻�������ʹ�ô˽�ͷ��������ɱ���ƣ�\n");
    				
	if(stringp(skill_attr["skill_class"])) {
		file = replace_string(file_name(this_object()), SKILL_D(""), 
				CLASS_D(skill_attr["skill_class"] + "/")) + "/" + curse + ".c";
		if(file_size(file) > 10) {
			return (int)call_other(file, "curse", me, target);
		}
	}
	file = CLASS_D("GENERIC/CURSE/") + curse + ".c";
	if(file_size(file) > 10) {
		return (int)call_other(file, "curse", me, target);
	}
	return 0;
}

int conjure_magic(object me, string spell, object target) {
	string file, msg;

	notify_fail("����ѡ�õķ���ϵ��û�����ַ�����\n");
	
	if (me->query_temp("till_death/lockup")==1)
  	{	
    		if (stringp(msg = me->query_temp("till_death/lockup_msg")))
    			return notify_fail (msg);
    		else
    			return notify_fail(" ����Ѫ���������������ͣ�һʱ��Ȼ����ʩչ��ͨ����\n");  
	}			
//	if (me->query_temp("till_death/shield_lock")==1)
//    		return notify_fail(" ��ʹ�û�������ʱ���ܷ��ġ���\n"); 
    	if( me->is_busy() )
        	return notify_fail("����������æ���ء��� \n");
    	if (objectp(target))
	if (!COMBAT_D->legitimate_buff(me, target))
    		return notify_fail("�㲻�������ʹ�ô���ͨ��������ɱ���ƣ�\n");
    			
	if(stringp(skill_attr["skill_class"])) {
		file = replace_string(file_name(this_object()), SKILL_D(""), 
				CLASS_D(skill_attr["skill_class"] + "/")) + "/" + spell + ".c";
		if(file_size(file) > 10) {
			return (int)call_other(file, "conjure", me, target);
		}
	}
	file = CLASS_D("GENERIC/CONJURE/") + spell + ".c";
	if(file_size(file) > 10) {
		return (int)call_other(file, "conjure", me, target);
	}
	return 0;
}

int scribe_spell(object me, object ob, string spell) {
	string file;

	notify_fail("����ѡ�õķ�֮����û�����ַ�����\n");
	
	if(stringp(skill_attr["skill_class"])) {
		file = replace_string(file_name(this_object()), SKILL_D(""), 
				CLASS_D(skill_attr["skill_class"] + "/")) + "/" + spell + ".c";
		if(file_size(file) > 10) {
			return (int)call_other( file, "scribe", me, ob );
		}
	}
	file = CLASS_D("GENERIC/CONJURE/") + spell + ".c";
	if(file_size(file) > 10) {
		return (int)call_other( file, "scribe", me, ob );
	}
	return 0;
}

varargs mixed hit_ob(object me, object victim, int damage_bonus, int factor) {
	return 0;
}


//	�ο�����
mapping query_skill_prop(){
	return skill_attr;
}
