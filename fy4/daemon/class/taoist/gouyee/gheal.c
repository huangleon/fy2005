// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
#include <combat.h>

int exert(object me, object target, int amount)
{
	int level, i, n;

	if( me->query("class")!="taoist" ) {
		return notify_fail("ֻ��������Ӳ���ʹ�ô��ķ���\n");
	}
	if( userp(me) && me->query("scroll/gouyee_heal") < 2 ) {
		return notify_fail("�㻹û�����������Ϣ����Ҫ�ҵ����ܼ����С�\n");
	}
	level = me->query_skill("gouyee", 1);
	if( level < 100 || me->query_skill("necromancy",1) < 120 ) {
		return notify_fail("��������Ϣ����Ҫ100���Ĺ����ķ���120�������������\n");
	}
	if( !target ) {
		return notify_fail("��Ҫ��˭ʩ�ô��ķ���\n");
	}
	if( target->query("possessed") != me || target->query("animated") ) {
		return notify_fail("��ֻ��������ʹ�Ĺ��ʹ�ô��ķ���\n");
	}
	if( (int)me->query("gin") <= 400 ) {
		return notify_fail("��������Ϣ����Ҫ400��ľ�����\n");
	}
	if( userp(me) ) {
		me->receive_damage("gin", 400);
	}
	message_vision(WHT"$N˫�ֻ���һ�������İ뻡��ҧ����⣬��һ��Ѫĭ�ӻ�������$n��\n"NOR, me, target);
	call_out("heal_him", 4, me, target, level);
	me->perform_busy(2);
	return 1;
}


int heal_him(object me, object target, int level)
{
	int i, amount;
	amount = 1200;
	if( !me || !target ) {
		return 1;
	}
	if( !target || environment(target) != environment(me) ) {
		tell_object(me, "ʩ���Ķ����Ѿ����������ˡ�\n");
		return 1;
	}
	message_vision(HIY"$n����һ��������Ѫ�����֣��˿��漣��������ȥ��\n"NOR, me, target);
	target->receive_fulling("kee", amount, me);
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
