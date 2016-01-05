//mimicat@fy4

#include <ansi.h>

int cast(object me, object target)
{
	int i, rate, amount, stage;
	object *enemy, *mem;

	if( me->query("class") != "lama" ) {
		return notify_fail("ֻ�д����µĵ��Ӳ���ʹ�ù����������䡣\n");
	}
	if( me->query_skill("kwan-yin-spells",1) < 90 ) {
		return notify_fail("�˷���������Ҫ90�������������䡣\n");
	}
	if( !target ) {
		target=me;		
	}
	if( !living(target) ) {
		return notify_fail(target->name() + "�Ѿ��޷�������ĺ����ˡ�\n");
	}
	if( !COMBAT_D->legitimate_heal(me,target) ) {
		return notify_fail("�㲻�����ƴ��ˣ�������ɱ���ƣ�\n");
	}
	if( target != me ) {
		mem = me->query_team();
		if( !pointerp(mem) || member_array(target,mem) == -1 ) {
			 return notify_fail("��ֻ�ܸ�ͬһ�����е������ˡ�\n");
		}
	}

	stage = me->query("scroll/kwan-yin-spells_ma");
	switch( stage ) {
		// This cast is actully an instant Hate generator, with gin/sen x2 amount hate generated, against all .
		case 0:
		case 1:
			{
				rate = 200;
				amount = 800;
			}
			break;	
		case 2:
			{
				rate = 300;
				amount = 1200;
			}
			break;	// 1.6M		2x = 400->2400 (4SB), 3x=500->3600 (6SB)
	}
	if( (int)me->query("mana") < rate ) {
		return notify_fail("������Ҫ"+ rate +"��ķ�����\n");
	}
	if( !me->query("possessed") ) {
		if( random(100) < F_ABILITY->check_ability(me, "3_ma_add", 3)*2 ) {
			amount = amount*2;
		}
	}
	amount = COMBAT_D->magic_modifier(me, target, "gin", amount);
	if( userp(me) ) {
		me->add("mana", -rate);
	}
	if( target == me ) {
		message_vision(
		YEL "\n$N"NOR+YEL"˫���������裬£����ǰ����������ȵ������\n"
		MAG "���Ƶ�������$N"NOR+MAG"˫�Ƽ�ӿ����������$N"NOR+MAG"ͷ����Ȼ��������ʧ�� \n\n" 
		WHT "����ɢȥ��$N"NOR+WHT"��ͷ�Ǻ�ˮ�����ƽ������ϡ� \n"NOR, me); 
	} else {
		message_vision(
		YEL "\n$N"NOR+YEL"˫���������裬£����ǰ����������ȵ������\n"
		MAG "���Ƶ�������$N"NOR+MAG"˫�Ƽ�ӿ����������$n"NOR+MAG"ͷ����Ȼ��������ʧ�� \n\n" 
		WHT "����ɢȥ��$N"NOR+WHT"��ͷ�Ǻ�ˮ��$n"NOR+WHT"�����ƽ������ϡ� \n"NOR, me, target ); 
	}
	target->receive_fulling("sen", amount,me);
	target->receive_fulling("gin", amount,me);
	if( target->is_fighting() ) {
		enemy = target->query_enemy();
		for( i = 0; i < sizeof(enemy); i++) {
			if( !enemy[i]->is_fighting(me) ) {
				enemy[i]->kill_ob(me);
				me->kill_ob(enemy[i]);
			}
		}	
	}
	me->perform_busy(2);
	return 1;
}
