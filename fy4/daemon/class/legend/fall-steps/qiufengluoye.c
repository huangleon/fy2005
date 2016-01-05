#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	
	string msg, type;
	int extra;
	int mod, i, n, t, skill, rate;	
	object *enemy, *enemy_all;
	
	if (me->query("class")!="legend")
		return notify_fail("�����ҶΪ��ѩ�ؼ���\n");
		
	if(me->query_temp("pfm/luoyeqiufeng")+ 2 > time())
		return notify_fail("��ո�ʩչ����粽���ؼ�����û����������\n");
	
	extra = me->query_skill("fall-steps",1);
	
	skill = me->query_skill("six-sense",1);
	
	if (skill < 200 || extra <150) 
		return notify_fail("�������Ҷ����Ҫ200�������鰵ʶ��150������粽��\n");
	
	if (ANNIE_D->check_buff(me,"tx-turtle-stance"))
		return notify_fail("�����ڵ����������ƣ��޷�ʹ�������������Ҷ��\n");
		
	if (!me->is_fighting())
		return notify_fail("�������Ҷ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	enemy_all = me->query_enemy();
	
	enemy = filter_array(enemy_all, (: !$1->is_busy():));
	
	if (!(n = sizeof(enemy)))
		return notify_fail("���˶��Ѿ���æ�����ˣ���ץ��ʱ�乥���ɡ�\n");
	else
		n = ( skill>= 230) ? 5: ((skill-190)/10+1) ;
	
	rate = 250; 
	if (me->query_temp("pfm/legend_berserk")) rate = 200;
	
	message_vision(HIY"$N"+HIY"��̤�˷�������������е���Ҷ��Ʈ�첻����\n"NOR,me,target);
		
	for (i=0; i<n ; i++)
	{
		if (i>sizeof(enemy)-1)	continue;
		if(enemy[i]->is_busy()) continue;
		
		mod = COMBAT_D->can_busy(me, enemy[i], "fall-steps");	
		if (!mod)	mod = 10000;
		
		if (COMBAT_D->do_busy_attack(me, enemy[i], "fall-steps/luoyeqiufeng", "step", rate, mod))
		{
			message_vision(YEL"���$N���ŵ��ۻ����ң�Ӧ�Ӳ�Ͼ��\n"NOR,enemy[i]);
			enemy[i]->force_busy(3);
			enemy[i]->set_temp("busy_timer/fall-steps",time());
		} else
		{
			msg = HIR"��ϧ$N"+HIR"������$n"+HIR"��������$p"+HIR"ٿȻ������"NOR;
			me->add_temp("cant_dodge",1);
			me->add_temp("cant_parry",1);
			COMBAT_D->do_attack(enemy[i],me,TYPE_PERFORM,msg); 
			me->add_temp("cant_dodge",-1);
			me->add_temp("cant_parry",-1);
		}
	}	
	me->set_temp("pfm/luoyeqiufeng",time());
		
	return 1;
}
