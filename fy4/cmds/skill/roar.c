//	Silencer@fy4 workgroup

#include <ansi.h>
inherit F_CLEAN_UP;

int main (object me, object target)
{
	object *ob;
	int skill, iron, duration;
	mapping buff;
	string msg;
	
	if (me->query("class")!= "lama")
		return notify_fail("ֻ�д��ѵ��Ӳ�������������\n");
		
	if (me->query_skill_mapped("force")!="bolomiduo")
		return notify_fail("���������������۶��ľ������⹦�ܡ�\n");
	skill = me->query_skill("bolomiduo",1);
	if (skill < 160)
		return notify_fail("����������Ҫ160�������۶��ľ���150����ղ�������\n");
	
	iron = me->query_skill("jin-gang",1);
	if (iron < 150)
		return notify_fail("����������Ҫ160�������۶��ľ���150����ղ�������\n");
		
	if (ANNIE_D->check_buff(me,"invul"))
		return notify_fail("���Ѿ���ʹ�����Ƶ��书�ˡ�\n");
		
	duration = me->query("timer/pfm/dz_roar")-time() + 1800 - F_ABILITY->check_ability(me,"mz_add")* 60;     
	if (duration>0)
      	return notify_fail("�㻹��Ҫ�ȴ�"+(int)(duration/60+1)+"�������Ҳ����ٴ�ʹ�á���������\n");
		
	if( !me->is_fighting() )
		return notify_fail("��������ֻ����ս����ʹ�á�\n");
	
	me->set("timer/pfm/dz_roar",time());
	
	msg = BRED + HIY "$N����ָ�죬����ָ�أ������߲������������Ȼӽ���ͳ������ķ�ţ�\n";
	msg += BRED + HIY"�����������ӡ��ӡ��¡�������է�䣬��ɢ��⣬����ϼ�ޣ�\n\n"NOR;
	
	buff = 
		([
			"caster":me,
			"who":me,
			"type":"invul",
			"att":"bless",
			"name":"�����۶��ľ���������",
			"time":	20,
			"buff_msg":msg,
			"buff1": "resistance/kee",
			"buff1_c":100,
			"buff2": "pfm/dz_roar",
			"buff2_c": 1,
		]);
	ANNIE_D->buffup(buff);
	return 1;
}


int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	roar[0m
[0;1;37m����������������������������������������������������������������[0m   

���Ϸ���Ǵ��Ѹ�ɮ��ר��ָ������۶��ľ����ղ������������£�
һ���Ϻȣ������壬�˲����ˡ���ʽ����Ԫ����ÿ30����ʹ��һ�Σ�
ÿ������20���ӣ��ڼ䲻����Ѫ�˺�����Ҫ160�������۶��ľ���150��
��ղ�������

[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}