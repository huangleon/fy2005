// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra, step;
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������ħ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	step = 200;
	extra = 200;
	
	target->set_temp("no_check_pfm_win",1);
	me->add_temp("apply/attack",step);
	me->add_temp("apply/damage",extra);	
	
	msg =  BLU"\n��������������֮��"NOR CYN" �� $N�Ľ��ƺ��������裬���������������ͻȻ������ָ������$n��" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	target->set_temp("skip_damage_record",1);

    msg =  MAG  "����׹���Ƴݷ�����"NOR CYN" �� $N�з�һ�䣬��ʽ��Ȼ������ɭ�ϣ������ޱߵ�û������ѹ��$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg =  HIR BLK  "��С¥һҹ�����꡹"NOR CYN" �� $N����һ�������������������������ó�һƬѩɫ��������$n��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg =  WHT  "������һ�ʻ����ѡ�"NOR CYN" �� $N������Ȼ���գ�����Բת������һ�������İ뻡����$n��ȥ����" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
/*        msg =  WHT "����д���顡�������������ң�\n"NOR CYN"$N���еĽ��ڿ��л���һ�������İ뻡�����޴��$n��ȥ��" NOR;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        msg =  WHT "�Ļ����翡���ͥ��į����Σ�\n"NOR CYN"$N���еĽ��ڿ��л���һ�������İ뻡�����޴��$n��ȥ��" NOR	;
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
*/        me->add_temp("apply/attack",-step);
	me->add_temp("apply/damage",-extra);	
	
		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}

	
	return 1;
}
