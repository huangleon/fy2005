#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra,bonus,a,b;

	if (userp(me) //&& !wizardp(me) 
		&& me->query_temp("timer/pfm/longlife_pangu")+30 < time())
		return notify_fail("�̹ſ���Բ�Ա���أ��㿪��ô��\n");
		
	extra = me->query_skill("xuanyuan-axe",1);
	if ( extra < 180) 
		return notify_fail("���̹ſ��졻��Ҫ180����ԯ������\n");
	bonus = me->query_skill("axe",1);
//	if ( bonus < 300) return notify_fail("��Ի������������ճ̶Ȳ�����ʹ�����̹ſ��졻��\n");

//	if (me->query("force") < 1200 && userp(me))
//		return notify_fail("�������������ʹ�����̹ſ��졻��\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(HIB"�̹ſ���"NOR"ֻ�ܶ�ս���еĶ���ʹ�á�\n");

//	if (me->query("age") - me->query("annie/pangoaxe") < 1 && userp(me))
//		return notify_fail("��ľ��û�����ϴ�ʩչ���̹ſ��졻������лָ��������޷��ٴ�ʹ�á�\n");

//	me->set("annie/pangoaxe",me->query("age"));

	
	me->delete_temp("timer/pfm/longlife_pangu");
	
	a=1000;
	b=3500;

	me->add_temp("apply/attack", a);	
	me->add_temp("apply/damage", b);

	msg = HIW"\n$N"HIW"����������һ˲�侫�������۷壬����"+me->query_temp("weapon")->query("name")+HIW"���޻��ɵ���$n"HIW"��ͷ���䣬

����������������"HIW"������"HIY"��һʽ"HIW"��"HIB"�̹ſ���"HIW"��"HIY"�Ѿ�û���κα仯��Ҳ�Ѳ����κα仯����

"NOR;

	message_vision(msg, me, target);
	
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");

	me->add_temp("apply/attack", -a);	
	me->add_temp("apply/damage", -b);

	return 1;
}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
