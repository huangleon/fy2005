//	Silencer@fy4 workgroup
// ��������ء������ڶ��ڣ�ʮ�غ��ڣ��мܶ������е���ʽ����150��


#include <ansi.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
	object *ob;
	int extra, skill, duration, agi,atk;
	mapping buff;
	string msg;
	
	if (me->query("class")!= "fugui")
		return notify_fail("ֻ�и�����Ӳ���ʹ�á�������ء�\n");

	if (me->query_skill("xuezhan-spear",1)<190 || me->query_skill("skyforce",1) < 160)
		return notify_fail("���������Ҫ190����Ѫսǹ����160���ı̿��ķ���\n");
				
	if (ANNIE_D->check_buff(me,"feat"))
		return notify_fail("���Ѿ���ʹ�����Ƶ��书�ˡ�\n");
		
	duration = me->query("timer/pfm/fg_shield")-time()+1800-F_ABILITY->check_ability(me,"plsg_add")*60;
    if (duration>0)
       	return notify_fail("�㻹��Ҫ�ȴ�"+(int)(duration/60+1)+"�������Ҳ����ٴ�ʹ��������ء�\n");
		
	if( !me->is_fighting() )
		return notify_fail("��������ء�ֻ����ս����ʹ�á�\n");

	if (userp(me))	{
		me->set("force", 0);
		me->set("force_factor",0);
	}
	
	msg = BRED + HIY "$Nһ����Ц��Ѫսǹ��չ���������ó�����ǹӰ������һ�С�������ء���\n\n"NOR;
		
		buff =
		([
			"caster":me,
			"who":me,
			"type":"feat",
			"type2":"parryup",
			"att":"bless",
			"name":"�������",
			"buffup_name":"parry",
			"buffup_type":""+extra,
			"buffup_ratio":987654321,
			"time":20,
			"buff_msg": msg,
			"special_func":2,
		]);
		
	ANNIE_D->buffup(buff);
	me->set("timer/pfm/fg_shield",time());
	
	return 1;
}