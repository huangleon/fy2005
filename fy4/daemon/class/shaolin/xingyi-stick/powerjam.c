// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i;
	string *style = ({
"���Σ���$N�ն�����$w�������Х������$n��$l��",
"���Σ���$N����$w������Ӱ���أ���$n����Χס��",
"���Σ���$N��ǰһ�ݣ�����$w���裬��$n���˹�ȥ��",
"���Σ���$N������������$wͷβ������ִ�$n������Ҫ����",
"���Σ���$N����$wһ�٣���������������$n��$l��",
"Գ�Σ���$N����������Ծ������$w���ƶ�����������$n��ȥ��",
"���Σ���$N��Ӱ����$n�����ζ�������$w������ɨ��$n��$l��",
"ӥ�Σ���$N������������$w���϶��£�Ѹ���ޱȣ�����$n��$l��"});
	object ob,*obs;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������˪�쾺���ɣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(!pointerp(obs=me->query_team()) || !me->is_team_leader())
		return notify_fail("ֻ�ж�������ſ��Է�����ʽ��\n");
// this loop just checking, make sure everyone use �������Ϲ�
	if(sizeof(obs) > 8 )
		return notify_fail("�������˸��ˣ���\n");
	
	for(i=0;i<sizeof(obs);i++)
	{
		if(!obs[i]) return notify_fail("����Ҫ������϶��顣\n");
		if(environment(obs[i]) != environment(me)) return notify_fail("������Ա��ȫ������ߡ�\n");
		if(!obs[i]->query_skill("xingyi-stick")) return notify_fail("����������˲����������Ϲ�����\n");
		if(!objectp(ob=obs[i]->query_temp("weapon"))) return notify_fail("��Ķ���������û�б�����\n");
		if(ob->query("skill_type") != "staff") return notify_fail("��Ķ���������û���ù�����\n");
		if(obs[i]->query_skill_mapped("staff") != "xingyi-stick") return notify_fail("��Ķ���������û�����������Ϲ�����\n");
	}	
	
	message_vision(HIY+"\n\n$N�ߺ�һ�����򣭣��࣭��˪�����죭�����������ɣ���\n��ʱ�������������Ϲ���\n\n",me);
	
	for(i=0;i<sizeof(obs);i++)
    {
		if (!obs[i]->is_fighting(target))	
			obs[i]->kill_ob(target);	
		
		msg = HIR +  style[i] + NOR;
		extra = obs[i]->query_skill("staff");
		extra *= (i+1);	
        obs[i]->add_temp("apply/attack", extra);
        obs[i]->add_temp("apply/damage", extra);
		
		COMBAT_D->do_attack(obs[i],target, TYPE_PERFORM,msg);
	
		obs[i]->add_temp("apply/attack", -extra);
		obs[i]->add_temp("apply/damage", -extra);
		obs[i]->start_busy(2);
	}
	
	return 1;
}
