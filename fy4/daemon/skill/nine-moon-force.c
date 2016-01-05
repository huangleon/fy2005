// nine-moon-force.c
inherit SKILL;
#include <ansi.h>

void setup(){
	set("name","�����ľ�");
	set("type","force");
	set("effective_level",100);
	set("usage/force",1);
	set("skill_class","shenshui");
	set("difficulty",200);
	set("no_refund",({"nine-moon-claw","nine-moon-steps"}));
}
 
mixed hit_ob(object me,object victim, int damage_bonus)
{
	int extra, damage,ratio, rec;
	object weapon;
	string msg;
	
/*	if ((ratio=me->query_temp("pfm/9moon_huaxue"))) {		// ��Ѫ�񹦡�
		rec = COMBAT_D->magic_modifier(me, victim, "kee", 
			damage_bonus *(ratio + F_ABILITY->check_ability(me,"huaxue_add")*5)/100);
		if (ratio==20) msg =RED"\n$N"NOR RED"����ȫ����Ѫ������һ�Ρ�\n"NOR;
		else if (ratio=30)	msg = RED"\n$N"NOR RED"��ͷһ������Ѫ������ֹ��\n"NOR;
		else 		msg = RED"\n$N"NOR RED"����ȫ����Ѫ��к������\n"NOR;	
		me->receive_fulling("kee",rec, me);
		message_vision(msg, victim);
	}*/
		
	if(!extra=me->query_temp("nine-moon-force_poison")) return ;
	
	damage = COMBAT_D->magic_modifier(me, victim, "kee", extra);
	if (weapon=me->query_temp("weapon")){
		if (weapon->query("skill_type")=="sword" && 
			me->query_skill_mapped("sword") == "nine-moon-sword")
		{	
			victim->receive_damage("kee",damage, me);
			victim->receive_wound("kee", damage, me);
			return MAG"$n"NOR MAG"ֻ��˿˿����͸�ǣ��ƺ���һ�����ư��������$N"NOR MAG"�����ϴ�����\n"NOR;
		}
		if ((weapon->query("skill_type")=="unarmed" && 
			me->query_skill_mapped("unarmed") == "nine-moon-claw"))
		{	
			victim->receive_damage("kee",damage, me);
			victim->receive_wound("kee", damage, me);
			return MAG"һ�����ư������һ����$n"NOR MAG"ֻ�����������������׶���$N"NOR MAG"ָ�⴫����\n"NOR;
		}	
			
	} else if (me->query_skill_mapped("unarmed") == "nine-moon-claw")
		{
			victim->receive_damage("kee",damage, me);
			victim->receive_wound("kee", damage, me);
			msg=MAG"һ�����ư������һ����$n"NOR MAG"ֻ�����������������׶���$N"NOR MAG"ָ�⴫����\n"NOR;
			return msg;
		}
	return 0;
}


int help(object me)
{
	write(@HELP   
���Ի�������mihunshu��
��ʽ��50���Ů�񹦷���ʹ�ã������æ��һ�ֲ���������Ѫ����
�ɹ��ʼ��ߣ����۳ɰܶ�û������æ�ҡ�
ÿ14��ʹ��һ�Σ�ÿ�κķѣ��Ů��/2������50����������
�����˺�����Ѫ�˺����Ů�񹦵ȼ���random(�Ů�񹦵ȼ�)
�Ի�������æ�ҷ�����18��ɹ����½�������

������������powerup��
��60�������ľ���������Ψһһ��ͬʱ��߹��������������ؼ������
��ĿΪ�����ľ��ȼ���һ�룬�ķ�100��������
   
������������powerfade��   
��80�������ľ��������Լ���ɱ����

������������refine��   
��100�������ľ���100���Ů�񹦣�������ת��Ϊ������
ת����������Ϊ�����ķ��������Ů�񹦵ȼ�����������
���ؼ���ָ��������exert refine 200 ����ת��200�㷨��

��������������chill��
��Ҫ150�������ľ���135���Ů�񹦣�ÿ�κķ�300����������������
�ӡ����ؼ�Ϊ��ˮ����ƽ�书�ľ���������Ͷ��䣬��ˮ�书��ÿһ��
����ÿһ���мܶ��ܲ��������˺�����������ƽ�ڹ���150�������˹���
ÿմ��һ�Σ������з������˺���
�˺���Ŀ��������ȼ�����
   
����Ѫ�񹦡���huaxue��
��Ҫ160�������ľ���160���Ů�񹦣����Ե��˷�ħ���˺���50%ת��
Ϊ�Լ�����Ѫ��ÿ10����ʹ��һ�Σ�ÿ�γ���120�롣

����������(chillbreath)
��Ҫ180�������ľ����Ů�񹦣���������120�룬�ܶ���Ӱ�죬����ÿ��
����һ���������ٴ죬Ϊ�����׹�ץ��­�ĵڶ�������ս����
�˼����澭��ȼ�����߶���ߡ�

�Ӱ����տ�ѧϰ��ƽ�ڹ�����90���Ů��
L100 ������֮�����ľ�����jingxin����������ķ�
L150 �������������ڱ����˻���ʱ�����Ч

HELP
    );
    return 1;
}
