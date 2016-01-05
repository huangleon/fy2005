// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
        int skill,timer,duration;
    	string msg;
    	mapping buff;
    
    	if( target != me ) 
        	return notify_fail("������Ӣ�ۡ�ֻ�������Լ����ϡ�\n");
   	    	
    	skill = me->query_skill("skyforce",1);
    	if (skill < 160)
    		return notify_fail("������Ӣ�ۡ���Ҫ160���ı̿��ķ���\n");
    	    	
    	timer = 300;		
		duration = me->query("timer/pfm/fg_afo")+timer-time();
		if (duration>0)
    		return notify_fail("��������ɢ���ٴ�ʹ�á�����Ӣ�ۡ�����"+duration+"�룩��\n");
    		
    	if( me->query("force") < 100 )
        	return notify_fail("������Ӣ�ۡ�������Ҫ100���������\n");
    	if (userp(me)) me->add("force", -100);

		if (ANNIE_D->check_buff(me,"fg-afo"))
			return notify_fail("���Ѿ���ʹ�á�����Ӣ�ۡ��ķ��ˡ�\n");

    	msg = BGRN + HIW"$N��ȻЦ�ˣ�����һ�ֳ������ġ��������纮���ڴ�ˮ���ڻ��Ļ�Ц��\n" NOR;

    	buff =
		([
			"caster":me,
			"who": me,
			"type":"fg-afo",
			"att":"bless",
			"name":"�̿��ķ�������Ӣ��",
			"buff1":"pfm/fg-afo",
			"buff1_c":1,
			"time":  30,
			"buff_msg": msg,
		]);
		ANNIE_D->buffup(buff);
		
		me->set("timer/pfm/fg_afo",time());
    	return 1;
    	
}