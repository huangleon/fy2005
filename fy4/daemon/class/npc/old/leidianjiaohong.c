// annie 07.2003
// �����߾� 
// ��Щ�ر��team perform *snicker
// �������ã�����

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra, bonus;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���׵罻�䡻ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (me->query_skill("chillblade",1) < 20)
		return notify_fail("���׵罻�䡻��Ҫ����20���ı����߾���\n");
	
	if (me->query("gender") == "Ů��")
		return notify_fail("Ů�Ӳ��ʺ�ʩչ���������ġ��׵罻�䡻��\n");

	weapon = me->query_temp("weapon");
	extra = me->query_skill("blade");

	msg = HIY"\n$N����"+weapon->name()+HIY+"�����ػӳ������Ҳ����ĵ������$n������һƬ�ڳ��ĵ��ơ�\n"NOR;
	me->set_temp("annie/perform_ldjh",1);
	message_vision(msg,me,target);
    call_out("do_ldjh", 2, me,target,0,weapon,extra);
	me->perform_busy(2);

	return 1;
}

//  This is a no-busy extra hit
int do_team_perform(object me,object mate,object target,object weapon,object w2,int extra,int extra2)
{
	int a,b,ex;
	a = me->query_busy();
	b = mate->query_busy();
	me->stop_busy();
	mate->stop_busy();

	ex = extra + extra2;
	ex = ex/4;

	me->add_temp("apply/attack", ex);
	me->add_temp("apply/damage", ex);
	mate->add_temp("apply/attack", ex);
	mate->add_temp("apply/damage", ex);

	message_vision(HIW"\n��Ļ�뵶����������ɲʱ��϶�Ϊһ��Ѹ����ҹ�׵磬���������磬ֱֱ��"+target->name()+"������\n"NOR,me,mate);
	COMBAT_D->do_attack(me,target, TYPE_PERFORM," ");
	COMBAT_D->do_attack(mate,target, TYPE_PERFORM," ");

	mate->add_temp("apply/attack", -ex);
	mate->add_temp("apply/damage", -ex);
	me->add_temp("apply/damage", -ex);
	me->add_temp("apply/attack", -ex);

	me->perform_busy(a);
	mate->perform_busy(b);

	return 1;
}

int do_ldjh(object me,object target,int count,object weapon,int extra)
{
	int i,extra2;
	object *team;
	object teammate,tweapon;
	if (me)
		me->set_temp("annie/perform_ldjh",0);
	if(!me||!target||!me->is_fighting(target)||environment(target)!=environment(me))
		return 0;
	if(!present(weapon,me)||weapon->query("equipped")!="wielded")
		return 0;

	if (me->query("class") != "moon")
		extra /= 2;

	if( pointerp(team = me->query_team()) )
		for (i=0; i<sizeof(team); i++)
		{
			if (!team[i]) continue;
			if (team[i] == me) continue;
			if (team[i]->query_temp("annie/perform_yhch_ldjh"))
			{
				teammate=team[i];
				if(teammate->is_fighting(target) && environment(target)==environment(teammate) && (tweapon = teammate->query_temp("annie/perform_yhch_ldjh_param1")) && present(tweapon,teammate) && weapon->query("equipped")=="wielded" && target == teammate->query_temp("annie/perform_yhch_ldjh_param2"))
				{
					extra2=team[i]->query_temp("annie/perform_yhch_ldjh");
					do_team_perform(me,teammate,target,weapon,tweapon,extra,extra2);
					return 1;
				}
			}
			if (team[i]->query_temp("annie/perform_yhch"))
			{
				me->set_temp("annie/perform_yhch_ldjh",extra);
				me->set_temp("annie/perform_yhch_ldjh_param1",weapon);
				me->set_temp("annie/perform_yhch_ldjh_param2",target);
				return 1;
			}
		}

/*
		while ( remove_call_out( "data_write_callback" ) != -1 ) {
			  TP( "Killing callout.\n" );
		}
*/
	//	+atk 225*3/4 = 169, +dmg = 150.
	i = me->query_busy();
	me->stop_busy();
	me->add_temp("apply/attack", extra*3/4);
	me->add_temp("apply/damage", extra*2/3);
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,HIR"������ͻ���Ѳ�֮����һ������������"+weapon->name()+HIR"��Ȼ������������$n��ȥ��\n"NOR);
	me->add_temp("apply/damage", -extra*2/3);
	me->add_temp("apply/attack", -extra*3/4);
	me->perform_busy(i);
	return 1;
}
