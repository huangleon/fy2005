
#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me, object target, int amount)
{
		int skill, add, duration;
		mapping buff;
	
		if(me->query("class")!="beggar")
	    	return notify_fail("ֻ��ؤ����ӲŻ᡺����������\n");
		
		skill = me->query_skill("huntunforce", 1);
		if(skill < 150) return notify_fail("������������Ҫ150���Ļ��繦��\n");

        if( target != me ) 
        	return	notify_fail("����������ֻ����������\n");
		
        duration = me->query("timer/pfm/gb_douhan")-time() + 300;
    	if (duration>0)
    		return notify_fail("�㻹��Ҫ�ȴ�"+(duration/60)+"�������Ҳ����ٴ�ʹ�á���������\n");
    	       
        if (ANNIE_D->check_buff(me, "hurtless"))
        	return notify_fail("���Ѿ���ʹ�����Ƶ��ؼ��ˡ�\n");  
        
        buff =
		([
			"caster":me,
			"who": me,
			"type":"hurtless",
			"att":"bless",
			"name":"���繦��������",
			"buff1":"hurtless",
			"buff1_c":1,
			"time":  180,
			"buff_msg":BGRN+HIW"$N��������˼��������˻�Ԫ������סȫ��\n"NOR,			
		]);
		ANNIE_D->buffup(buff);
		me->set("timer/pfm/gb_douhan",time());
		
        return 1;
}

