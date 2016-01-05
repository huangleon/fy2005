//About conditions types : ��see condition.h ���壩�����еĽⶾ���������С�
//NO_CURE				- ����ҽ�ε�Conditions��һ���������ض��ĳ��ϡ�
//SPECIFIC_POISON		- �߼��� -- ���඾���ձ�ⷨ��Ψ�ж�֢��ҩ�﷽�С�
//MID_POISON			- �м��� -- �ض����ɵĽⶾ�ķ�����������ҩ� 
//LOW_POISON			- �ͼ��� -- һ�����ѧ�����ķ���������ͨҩ�
//GENERIC				- �˷���ԣ���ƻ����ࡣ
//	--- Silencer@fy4  in 12/21/2002

inherit "/daemon/condition/generic_condition";
inherit SSERVER;

#include <ansi.h>
#include <condition.h>


int cast(object me, object target)
{
	int extra;
	object *mem;

	if( me->query("class")!="lama" ) {
		return notify_fail("ֻ�д����µĵ��Ӳ���ʹ�ù����������䡣\n");
	}
	extra = me->query_skill("kwan-yin-spells", 1);
	if( extra < 70 ) { 
		return notify_fail("���䡻��Ҫ70���Ĺ����������䡣\n");
	}
	if( (int)me->query("mana") < 100 ) {
		return notify_fail("���䡻��Ҫ100��ķ�����\n");
	}
	if( !target ) {
		target = me;
	}
	if( target == me ) {
		message_vision(HIC "$N�����������֮ɫ��˫�ֺ�ʮ��Ը��������������䡻\n\n"NOR
+HIM"һ����ʥ�Ĺ��������$N��Χ������ԴԴ������ת��\n\n"NOR,me,target);
	} else {
		mem = me->query_team();
		if( !pointerp(mem) || member_array(target, mem) == -1 ) {
			return notify_fail("��ֻ�ܸ�ͬһ�����е���������\n");
		}
		message_vision(HIC "$N�����������֮ɫ��˫�ֺ�ʮ��Ը��������$n��������䡻 \n\n"NOR
	HIM"һ����ʥ�Ĺ��������$N��Χ��$N�����ն������Ĵȱ�֮ɫ������ԴԴ
��������$n���ڡ�$n�е�����������������$N����ɫȴ������ή��\n\n"NOR, me, target);
	}

	if( userp(me) ) {
		me->add("mana",-100);
	}
	if( extra < 200 ) {
 		target->clear_condition_type(LOW_POISON);
	} else {
 		target->clear_condition_type(MID_POISON);
	}
	return 1;
}
