// avatar buff


#include <ansi.h>
void remove_effect(object me, object caster);

int exert(object me, object target, int amount)
{
	int skill,duration, am1, ess;
	mapping buff;
	object *mem;
	string msg;
	
	if(me->query("class")!="bonze")
		return notify_fail("ֻ���˹����µĵ��Ӳ����̡����¹�𡻣�\n");

	skill = me->query_skill("lotusforce", 1);
	ess = me->query_skill("essencemagic",1);
	
	if(skill < 150 || ess < 220) 
		return notify_fail("�����¹��������Ҫ150�������ķ���220����ʶ��ͨ��\n");

    duration = me->query("timer/pfm/xg_avatar")-time() + 1200;
	if (duration>0)
		return notify_fail("�㻹��Ҫ�ȴ�"+(duration/60)+"�������Ҳ����ٴ�ʹ�á����¹��\n");
    		
	if(!target ) target=me;
	if(target!= me) {
		mem = me->query_team();
		if (!pointerp(mem) || member_array(target,mem) == -1)
			 return notify_fail("��ֻ�ܸ�ͬһ�����е���ʹ�á����¹�𡻡�\n");
	}
	
	if (ANNIE_D->check_buff(target,"xg-avatar"))
		return notify_fail("�����Ѿ������Ƶ��ؼ��ˡ�\n");

	if( (int)me->query("force") < 500 )   
		return	notify_fail("�����¹��������Ҫ500���������\n");
	me->add("force", -500);
	
	msg = BRED +HIY"$N"BRED +HIY"˫�ֺ�ʮ���Ƽ�֮����˲���貣�����������â����$n"BRED +HIY"������У�$n"BRED +HIY"����ɫ
�ƴȱ�������ɱ���ȱ����������������ɱΪ��ħ�׺�ɱ¾����\n" NOR;
	
	message_vision(msg, me, target);
	
	amount = 20 + F_ABILITY->check_ability(me,"avatar_add");
	
	buff=
		([
			"caster":	me,
			"who": 		target,
			"type":		"xg-avatar",
			"att":		"bless",
			"name":		"�����ķ������¹��",
			"time":  	180,
			"buff_msg": "",
			"buff1": "apply/strength",
			"buff1_c": amount,
			"buff2": "apply/agility",
			"buff2_c": amount,
			"buff3": "apply/composure",
			"buff3_c": amount,
		]);
		
	ANNIE_D->buffup(buff);
	me->perform_busy(1);
	me->set("timer/pfm/xg_avatar",time());
	return 1;
}
