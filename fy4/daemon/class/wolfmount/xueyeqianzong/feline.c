// Silencer @ FY4 workgroup. Aug.2004
//  add some kee, but shorter duration than dwg's buffup.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    	int skill, amount, wolf;
    	string msg;
    	mapping buff;
    
    	if (me->query("class")!="wolfmount")
    		return notify_fail("�����᡻����ɽ�����书��\n");
    	
    	skill = me->query_skill("xueyeqianzong",1);
    	if (skill < 130)
    		return notify_fail("�����᡻��Ҫ130����ѩҰǱ�١�\n");

		if(!target ) target=me;    			
    	if( target != me )
        	return notify_fail("��ֻ����ѩҰǱ�������Լ�����Ѫֵ��\n");
    	    	
    	if (ANNIE_D->check_buff(me,"gks"))
    	       	return notify_fail("���Ѿ����������Ƶ��书�ˡ�\n");

	
		if (me->query_temp("pfm/wm_stance"))
			return notify_fail("���޷�ͬʱʹ�ò�ͬ��ѩҰǱ�ٵ�����\n");
		  	
    	msg = BBLU + HIW"$N����һ�������������������������������֮�䣬���Ʋ�ŭ������\n" NOR;

		wolf = me->query_skill("summonwolf",1);
		amount = 400;
		
		if (skill >=160){
			if (me->query("scroll/xueyeqianzong_feline")==3)		amount = 1300;
			else if (me->query("scroll/xueyeqianzong_feline")==2)	amount = 800;
		}
	
		buff =
			([
				"caster": me,
				"who":  target,
				"type": "kee",
				"att":	"bless",
				"name":	"ѩҰǱ�١�����",
				"buff1":"kee",
				"buff1_c":amount,
				"buff0": "pfm/wm_stance",
				"buff0_c": 1,			
				"time":  600 ,
				"buff_msg": msg,
				"special_func":1,
			]);
			
		ANNIE_D->buffup(buff);
	
    	return 1;
}