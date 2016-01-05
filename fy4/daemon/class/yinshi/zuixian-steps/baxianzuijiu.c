#include <ansi.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
        int skill;
	string msg;
	mapping buff;
	
	skill = me->query_skill("zuixian-steps", 1);
	if(skill < 100) return notify_fail("��������ơ���Ҫ100�����������²���\n");
                
        if(target && target != me )
        	return notify_fail("��ֻ�ܽ���������ơ������Լ������ϡ�\n");
	
	if (ANNIE_D->check_buff(me, "dodgeup")
        	|| ANNIE_D->check_buff(me, "powerup"))
               	return notify_fail("���Ѿ���ʩչ���Ƶ��书�ˡ�\n");
	
	if( (int)me->query("force") < 100 )     
        	return notify_fail("���������Ҫ����100��������\n");
        if (userp(me))	me->add("force", -100);
	
	skill = skill/2;
	
	msg = BGRN + HIW "$N���Ӷ������ᣬ��������˾ƣ�վ�����ȡ���������Ʈ�ݲ�����
ٲȻ���������²��еġ�������ơ�\n\n" NOR;

        buff =
		([
			"caster": me,
			"who":  me,
			"type": "dodgeup",
			"att":	"bless",
			"name":	"���ɲ����������",
			"buff1":"apply/dodge",
			"buff1_c":skill,
			"time":  900 ,
			"buff_msg": msg,
		]);
		
        ANNIE_D->buffup(buff);
		me->perform_busy(1);
        return 1;
        
}
