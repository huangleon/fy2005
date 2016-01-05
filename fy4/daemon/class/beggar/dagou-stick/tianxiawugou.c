// mimicat@fy4

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i, bonus, exp_bonus;
	
	object weapon, *enemy;
	
	if (me->query("class")!= "beggar")
		return notify_fail("�������޹�����ؤ�������\n");
	
	if((int)me->query_skill("dagou-stick",1) < 125 && userp(me))
		return notify_fail("�������޹�����Ҫ125���Ĵ򹷰�����\n");	

	if (me->query_skill_mapped("force") != "huntunforce")
		return notify_fail("�������޹�����Ҫ�����ķ�����ϡ�\n");

	enemy=me->query_enemy();
	if(!sizeof(enemy))
		return notify_fail("�������޹���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(target)
		return notify_fail("������в���Ҫָ��ʹ�ö��󣡣�\n");
		
	weapon = me->query_temp("weapon");

	extra = me->query_skill("dagou-stick",1);
		
	// Similar to Chuozijue, but no chance for ����
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra*2);
	
	msg = HIR  "$N�ͺ�һ���������޹����������������е�"+ weapon->name() +"��"
+ weapon->name() + HIR"���������Ӱ��\n����ڵظ�����Χÿһ���ˣ�\n" NOR;
	message_vision(msg,me);
	
	for(i=0;i<sizeof(enemy);i++)
	{
		msg=HIY"$N"HIY"���е�$w"HIY"ֱȡ$n"HIY"��$l����"NOR;
		me->set_temp("marks/pfm_dagou",1);
		COMBAT_D->do_attack(me,enemy[i], TYPE_PERFORM,msg);
		me->delete_temp("marks/pfm_dagou");
	}
	
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra*2);
	
	if (ANNIE_D->check_buff(me, "fastcast")>0)
		me->perform_busy(1);
	else
		me->perform_busy(2);

	return 1;
}

/*

������     /��              ��\      
������   ��   �ܣߣߡ�������  ��       
������   �� ����    ���������v��       
������    �M                  ��       
������    ��   /��\    /��\   ��      
������    ��   ����    ��  �� ��       
������   ��    \ /    \��/    ��      
������    ����      ��      ���M         
������    ���v��    ��   ������         
������    �q������������������           
������   ��   ��           /���\����    
������  ��____��  �� ��  �� .. ����     
������        \���/ ����ܡ�         
                       ��             
����������������- FengYun - ������
 ��������������annie 06.2005
 ��������dancing_faery@hotmail.com

*/
