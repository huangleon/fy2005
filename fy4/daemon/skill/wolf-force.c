#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","�����ķ�");
	set("type","force");
	set("effective_level",100);
	set("difficulty",200);
	set("usage/force",1);
	set("skill_class","wolfmount");
}

/*		in combat_d
mixed hit_ob(object me,object victim,int damage_bonus)
{
	int extra, dream;
	object weapon;
	string skill;
	
	if (damage_bonus < 1)	return 0;
	if (!extra = me->query_temp("rabie"))	return 0;
	
	if (ANNIE_D->check_buff(me,"bloodthirsty"))
		damage_bonus = damage_bonus * 2;
	
	damage_bonus = damage_bonus * (20 + F_ABILITY->check_ability(me,"shigu_add")*2)/100; 
	
	damage_bonus = COMBAT_D->magic_modifier(me, me, "kee", damage_bonus);
		
	me->receive_fulling("kee",damage_bonus,me);
	return;
}*/

mapping ob_hit(object ob, object me, int damage) {
	
	mapping data = ([]);
	int num, hit_damage, amount;
	
	if (damage <=0)	return 0;	
	if( me->query_temp("pfm/wm_preservation")<=0)
		return 0;
	
	me->add_temp("pfm/wm_preservation",-1);
	
	data["msg"] = WHT"$n����������һ�����ƺ���С�����֡�\n"NOR;
	
	hit_damage = 100 + me->query_skill("hammer")*3;	
	if (ob->query_hate(me)>0)
		ob->add_hate(me,-hit_damage);
	if ((amount = ob->query_hate(me))<0)
		ob->add_hate(me, -amount);	// 0
				
	if (me->query_temp("pfm/wm_preservation") < 1) {
			ANNIE_D->debuff(me, "wm-detaunt");
	}	
	return data;	
}



int help(object me)
{
	write(@HELP 
��Ǳ�ǡ���preservation��
ʹ�ô��ľ���ÿ�����˻���һ�Σ����˻ή�Ͷ�ʹ���ߵ����ޡ�
ÿ�μ�������Ϊ��Ч�������������ҡ�ÿ90��ʹ��һ�Ρ�
ÿ������30��򱻵��˻���3�κ�ʧЧ��
	  
��ս�ǡ���bloodthirsty��
��Ҫ160�������ķ�������90�룬ÿ10���ӿ�ʹ��һ�Ρ�
�ؼ��ڼ��ȹǷ��ص���Ѫֵ�ӱ���
	
�����ǡ���fancyfeet��
��Ҫ170�������ķ���200����������ÿ90���ӿ�ʹ��һ��
�û�����������������3�η�ħ��������10���ʧЧ��

�����ǡ���paragon��
��Ҫ170�������ķ���250����������ÿ20����ʹ��һ�Σ�ÿ�κķ�
200���������ؼ�ʹ�ú�ÿ���ָֻ�һ����Ѫ������10�֣�ÿ�ֻ�
����ѪֵΪ�����ķ��ȼ���������

�����ǡ���assassinate��
��Ҫ170�������ķ���270����������ÿ20����ʹ��һ�Σ�ÿ�κķ�
100������������16���ӣ��ڴ��ڼ䲫����ɱ���ؼ�����ʧ�֣�ͬ
ʱÿ�λ����˺�Ϊ������ֵ��

HELP
    );
    return 1;
}
