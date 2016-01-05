#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        int extra, tmp, i, duration;
        string msg;
        object *enemy;
	
		if (me->query("family/master_id") != "master yue" || me->query("class")!="official")
			return notify_fail("������Ⱥħ�������ɵ��ӵľ��С�\n");
	
		extra = me->query_skill("yue-spear",1);
		tmp = me->query_skill("manjianghong",1);
    	    	
    	if (tmp < 140 || extra < 140 )
    		return notify_fail("������Ⱥħ����Ҫ140����������ƽǹ����140���������ķ�!\n");
    	
		if( !target ) target = offensive_target(me);
		if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
	        	return notify_fail("������Ⱥħ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	        
        duration = me->query_temp("timer/pfm/gf_qunmofuzhu")-time() + 10;
		if (duration>0)
        	return notify_fail("����Ҫ�ȴ�Ƭ�̣�"+ duration +"�룩�����ٴ�ʹ�á�����Ⱥħ��\n");
            
        msg = HIW  "\n$N"HIW"ʹ��һ�С�����Ⱥħ�����ܡ��̡����������������ܡ��գ�
ǹ������������ǹӧ����㣬�ִ�����Ҫ������\n" NOR;
	
		message_vision(msg, me);
	
		enemy = me->query_enemy();
		for (i=0;i<sizeof(enemy);i++)
		{
			if (!me->is_busy())
			{	
				me->add_temp("apply/attack",extra);
				COMBAT_D->do_attack(me,enemy[i], TYPE_PERFORM, "");
        		me->add_temp("apply/attack",-extra);
        	}
        }
        me->set_temp("timer/pfm/gf_qunmofuzhu",time());
        return 1;
}
