// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra=0,extra2=0,i;
	object ob,*obs;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����צ������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(!pointerp(obs=me->query_team()) || !me->is_team_leader())
		return notify_fail("ֻ�ж�������ſ��Է�����ʽ��\n");
// this loop just checking, make sure everyone use  tianlongwhip
	for(i=0;i<sizeof(obs);i++)
	{
	if(!obs[i]) return notify_fail("����Ҫ������϶��顣\n");
	if(environment(obs[i]) != environment(me)) return notify_fail("������Ա��ȫ������ߡ�\n");
	if(!obs[i]->query_skill("tianlongwhip")) return notify_fail("����������˲������������޷���\n");
	if(!objectp(ob=obs[i]->query_temp("weapon"))) return notify_fail("��Ķ���������û�б�����\n");
	if(ob->query("skill_type") != "whip") return notify_fail("��Ķ���������û���ñ޷���\n");
	if(obs[i]->query_skill_mapped("whip") != "tianlongwhip") return notify_fail("��Ķ���������û�������������޷���\n");
	}	
	if(sizeof(obs) !=4) return notify_fail("����צ������ֻ���ĸ��˵Ķ���ſ��Է�����\n");

 	msg = HIR "\n\n"+
	obs[0]->name()+"���е�"+(obs[0]->query_temp("weapon"))->name()+"�����������³����\n"+
        obs[1]->name()+"���е�"+(obs[1]->query_temp("weapon"))->name()+"չ����������ɨ��\n"+
        obs[2]->name()+"���е�"+(obs[2]->query_temp("weapon"))->name()+"���������������̣�\n"+
        obs[3]->name()+"���е�"+(obs[3]->query_temp("weapon"))->name()+"����ֱ�̣�\n"+
"ͬʱʹ�����������޷����ߺȵ����ģ���צ�����죭��������\n���еļһ�ͬʱ��������" NOR;
	for(i=0;i<sizeof(obs);i++)
        {
	extra += (int)obs[i]->query_skill("whip");
	extra2 += (int)obs[i]->query_temp("apply/damage") + ((int)obs[i]->query_str())*((int)obs[i]->query_str()) / 10;
	}
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra2);
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra2);
	for(i=0;i<sizeof(obs);i++)
	{
	obs[i]->start_busy(2);
	target->kill_ob(obs[i]);
	}
	return 1;
}
