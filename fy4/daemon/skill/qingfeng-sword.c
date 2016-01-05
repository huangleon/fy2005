// qingfeng-sword.c

//	���ʮ��ʽ����Ч
//  ��ɽ���书����������ߣ�������ÿ��������ߣ�������
// 	��ɽ���书: qingfeng-sword, tanzhishentong, zhaixin-claw


#include <combat.h>
#include <ansi.h>
inherit SKILL;

int perform(object me, object target);
int do_yuexie(object me,object target,int count,object weapon);

string *qf_dance = ({
//"$N"NOR CYN"���ֺ�ü��$w"NOR CYN"б�������������������ޣ������ƿ���������·��ʵ���飬��ʽ����
//δ�䡣���ǡ����ʮ��ʽ���еĵ�һʽ�����������",
"������ө��-- $N"NOR CYN"�ؽ�������Ʈ��Ľ����������ͬҹ������ө���裬Ϯ��$n��",
"������ɽᰡ�-- $N"NOR CYN"�����ᶶ�ὣ������ֻ������������Ʈҡ����! ",
"���Ƶ����᡻-- $N����$w"NOR CYN"���ӣ��ƺ���̬���У�Ȼ�����Ʋ�����ı��֮���ѷ���$n!",
"����Ѩ���硻-- $N"NOR CYN"�������ӻ���һ���뻡������$w"NOR CYN"���㣬�����Ľ�����Ȼ������˷�����$n��",
"���������-- $N"NOR CYN"����$w"NOR CYN"�������𣬽���Ʈ������������������������֯��һ��������",
"��˪��������-- $N"NOR CYN"���$w"NOR CYN"����б�Ӷ��£�����һת��$w"NOR CYN"ƽƽ�Ƴ���˿˿����ƮȻ����!",
"���綯ǧ�塻-- $N"NOR CYN"��������������������˷���ȴ�ֲ��嵽����һ�����죡",
"�����Ǵ��硻-- $N"NOR CYN"����$w"NOR CYN"���ƺ�����ң�������ǰƮ����Ȼ������ȴ���������紺���Ⱦ����!",
"����÷��ѩ��-- $N"NOR CYN"�������裬�������䣬������÷�ڷ���Ʈ��$n��",
"������ƫ����-- $N"NOR CYN"���$w"NOR CYN"�������������޼�бƮ����!\n",
"�����͸�Ƽ��-- $N"NOR CYN"����$w"NOR CYN"��ת��һ�����̶̵Ļ��⸡����ǰ��ֻ������Ʈ��������$n!��",
"����ϼ��ɢ��-- $N"NOR CYN"��紵������΢΢�������ֻӳ�$w"NOR CYN"��������ƬƬ��ϼƮ��!\n",
});



void setup() {
	set("name","���ʮ��ʽ");
	set("type","sword");
	set("effective_level",160);
	set("usage/sword",1);
	set("usage/parry",1);
	set("skill_class","huashan");
	set("difficulty",200);
	set("practice_limit",100);
	set("unarmed_parry_msg",({
		"$n����$v�������𣬽���Ʈ�������������������𣬡����ʮ��ʽ����
����ʽ���������ʹ������������֯��һ��������\n",
		"$n���$v�������������޼�бƮ������ʹ�������ʮ��ʽ���е�ʮһʽ
������ƫ��������$N���ƻ������Ρ�\n",
		"$n��紵������΢΢�������ֻӳ�$v��������ƬƬ��ϼƮ�����ԡ����
ʮ��ʽ���� ��ʮ��ʽ����ϼ��ɢ����$N�����\n",
					})	
	);
	action = ({
        ([      "action":               
"$N���ֺ�ü��$wб�������������������ޣ������ƿ���������·��ʵ���飬��ʽ 
����δ�䡣���ǡ����ʮ��ʽ���еĵ�һʽ�����������",
                "dodge":                100,
                "damage":               33,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�������ʮ��ʽ���еڰ�ʽ���綯ǧ�塱����������������������˷���ȴ 
�ֲ��嵽����һ������"NOR,
                "dodge":                120,
                "damage":               40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�������ʮ��ʽ���еڶ�ʽ������ө�𡱣��ؽ�������Ʈ��Ľ����������ͬ
ҹ������ө���裬Ϯ��$n$l",
                "dodge":                100,
                "damage":               50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�����ᶶ�ὣ������ֻ������������Ʈҡ������ȴ�ǡ����ʮ��ʽ���е���ʽ
������ɽᰡ� ",
                "dodge":                270,
                "damage":		40,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w���ӣ��ƺ���̬���У�ͣ�в�����Ȼ�����Ʋ�����ı��֮���ѷ���$n$l��
���ǡ����ʮ��ʽ���е���ʽ���Ƶ����ᡱ",
                "dodge":                150,
                "damage":		100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�������ӻ���һ���뻡������$w���㣬ʹ�������ʮ��ʽ���е���ʽ����Ѩ���硱�� 
�����Ľ�����Ȼ������˷�����$n",
                "dodge":                100,
                "damage":		10,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$w�������ǰ������б�Ӷ��£�����һת��$wƽƽ�Ƴ���˿˿����ƮȻ������ 
���ǡ����ʮ��ʽ���е���ʽ��˪��������",
                "dodge":                195,
                "damage":		70,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w���ƺ�����ң�������ǰƮ�������˷ֲ��巽��Ȼ������ȴ���� 
�����紺���Ⱦ���֡����ǡ����ʮ��ʽ���еھ�ʽ�����Ǵ��硱",
                "dodge":                110,
                "damage":		30,
                "damage_type":  "����"
        ]),                       
        ([      "action":               
"$Nʹ�������ʮ��ʽ���е�ʮʽ����÷��ѩ����ֻ���������裬�������䣬 
������÷�ڷ���Ʈ��$n$l",
                "dodge":                195,
                "damage":		120,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w��ת��һ�����̶̵Ļ��⸡����ǰ�����ǡ����ʮ��ʽ���� 
��ʮ��ʽ�����͸�Ƽ����ֻ������Ʈ��������$n$l��",
                "dodge":                260,
                "damage":		130,
                "damage_type":  "����"
        ]),     
                   
	});
}


mapping query_action(object me, object weapon)
{
	int attack_act;
	int level;
	object *victims,victim;
	mapping act;
	
	level = F_LEVEL->get_level(me->query("combat_exp"));
	
	attack_act=random(sizeof(action));
	me->set_temp("qingfeng-act",attack_act);
    
    if (level >= 110 && attack_act==0) {
    	act = 
        ([      "action":               
CYN"�����������-- $N"NOR CYN"���ֺ�ü��$w"NOR CYN"б�������������������ޣ������ƿ���������·��ʵ
���飬��ʽ����δ��!"NOR,
                "dodge":                100,
                "damage":               33,
                "damage_type":  "����"
        ]);
        
    	return act;
    }	
    return action[attack_act];
}



mixed hit_ob(object me, object victim)
{	int act;
        int pro, level;
        int dam;
        int level_bonus;
        string *type = ({ "gin","kee","sen"});
        string damtype;
		object weapon;
		
		if (userp(me) && me->query("class")!= "huashan")
			return ("");
			
		if (me->query_skill_mapped("force") != "hanmei-force")
			return ("");
				
		act=me->query_temp("qingfeng-act");			
		level = F_LEVEL->get_level(me->query("combat_exp"));
		
		CHANNEL_D->do_sys_channel("sys", sprintf("level = %d, act = %d", level, act));
         
		// 9 in 10 acts. 90% chance to have extra damage. 
		// 10% to start dancing attack
		switch(act) {
			case 2:
				damtype="kee";
				break;
			case 5:
				damtype="gin";
				break;
			case 8:
				damtype="gin";
				break;
			case 9:
				damtype="sen";
				break;
			case 1:	
				if (level < 48) break;
				damtype="kee";
				break;
			case 3: 
				if (level < 58) break;
				damtype="kee";
				break;
			case 4: 
				if (level < 74) break;
				damtype="kee";
				break;
			case 6: 
				if (level < 84) break;
				damtype="sen";
				break;
			case 7:
				if (level < 100) break;
				damtype = "kee";
				break;				
		}
		
		dam = me->query("force_factor")
				+ me->query_skill("qingfeng-sword",1)
				+ F_LEVEL->get_level(me->query("combat_exp"));
		
		if(damtype && me->query("class")=="huashan")
		{
			// dmg = 95+ 200 + 139 = 434 maximum			
			dam = COMBAT_D->magic_modifier(me, victim, damtype, dam);		
			victim->receive_damage(damtype,dam,me);
			return (YEL"$n"NOR YEL"����һ�飬�ƺ��ѱ�$N"NOR YEL"���ھ����ˡ�\n" NOR);
		}
		
		if (ANNIE_D->check_buff(me,"swordshield")
			|| me->query_temp("annie/perform_sworddance"))	return 0;
		
		if (level >= 200 && act == 0 )	// ��һʽ		still need more test, so set level to be 200
			perform(me, victim);
		return "";				
}

int accuracy_level(object me){
	if (me && me->query_skill("qingfeng-sword",1)>=100) 
		return (me->query_skill("qingfeng-sword",1)-100);
	return 0;
}

int damage_level(object me){
	if (me && me->query_skill("zhaixin-claw",1)>=100)
		return (me->query_skill("zhaixin-claw",1)-100);
	return 0;
}


int perform(object me, object target)
{
	object weapon;
	mapping buff;

	if( !target ) return 0;
	
	buff =
	([
		"caster":me,
		"who": me,
		"type":"swordshield",
		"att":"bless",
		"name":"���ʮ��ʽ������",
		"shield_type":"force",
		"shield_amount":10000,
		"shield_desc":WHT"$Nһ�й�ȥ��ȴ�繥�벨���Ӱ��ʧȥ��$n�����٣�\n"NOR,
		"time":  40,
		"buff_msg": " ",
		"disa_msg": " ",
	]);
				
	ANNIE_D->buffup(buff);
	weapon = me->query_temp("weapon");
	message_vision( WHT"
��ɫ��������þ���һ��΢�磬��þ���һĨ��ɫ��
��������$N�����ӳ$N��������ϣ�
$N���齣�������裬����ɫ������Ӷ�����ӯ��ʫ���������Ρ�\n\n" NOR, me,target);
    call_out("do_yuexie", 1, me,target,0,weapon);
	me->perform_busy(2);
	return 1;
}

int do_yuexie(object me,object target,int count,object weapon)
{
	int i;
	string msg;
	if (!me)	return 0;
	
	if(!target||!me->is_fighting(target)||environment(target)!=environment(me))
	{
		ANNIE_D->debuff(me,"swordshield");
		return 0;
	}
	if(!present(weapon,me)||weapon->query("equipped")!="wielded")
	{
		ANNIE_D->debuff(me,"swordshield");
		return 0;
	}
	
	me->stop_busy();
	me->set_temp("annie/perform_sworddance",1);
//	i=me->query_skill("qingfeng-sword",1);
//	me->add_temp("apply/damage",i*(count+1));
   	msg = qf_dance[count];
   	COMBAT_D->do_attack(me,target, TYPE_PERFORM, CYN+msg+NOR);
//	me->add_temp("apply/damage",-i*(count+1));
	me->delete_temp("annie/perform_sworddance");
	me->perform_busy(2);
	if (count < 11 && ( count<3 || random(2)))
	{
		count++;
	    call_out("do_yuexie", 1, me,target,count,weapon);
	}
	else
	{
		ANNIE_D->debuff(me,"swordshield");
		message_vision(WHT"\n$N�������ƣ���һֻС�������ں�Ҷ�ϣ�������һ��¶�顣\n"NOR,me);
		me->start_busy(1);	// immune to parry busy
	}
	return 1;
}



int help(object me)
{
	write(@HELP   
��罣��������Ϻ�÷�ķ�������Ч
��罣������û�����⼼�ܣ���������ж��֣��������ɵ��˶���ľ�
�����˺�������������ȼ������ߣ�������Ч���ļ���Ҳ��������

�˺���ֵ = ������enforce��+��罣���ȼ�+������ȼ�

��罣��100�����ϣ�ÿ10����߻�ɽ�书��ժ���֡���罣����ָ��ͨ��
���еȼ�+10��
HELP
    );
    return 1;
}
