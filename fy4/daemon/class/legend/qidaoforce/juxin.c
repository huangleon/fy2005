
#include <ansi.h>
inherit F_CLEAN_UP;

int exert(object me,object target,int amount)
{
        int level, fix, duration, add;
        mapping buff;
        string msg;

		if(me->query("class")!="legend" && userp(me))
			return notify_fail("ֻ����ѩɽׯ�ĵ��Ӳ��ܹ�ʹ�þ��ľ���\n");

	 	level = me->query_skill("dormancy",1);
	 	if( level < 150 || me->query_skill("qidaoforce",1)< 150)
			return notify_fail("�����ľ�����Ҫ150����Ϣ��������150������ķ���\n");
              
        if (target && target!= me)
 			return notify_fail("���ķ�ֻ�������Լ����ϡ�\n");
             
        if (level< 200)
        	duration = me->query("timer/pfm/tx_juxin")-time() + 180;
        else
        	duration = me->query("timer/pfm/tx_juxin")-time() + 150;
        
        if (duration>0)
        	return notify_fail("�㻹��Ҫ�ȴ�"+(int)(duration)+"�������Ҳ��ܹ��ٴ�ʹ�þ��ľ���\n");
        
		me->set_temp("marks/pfm/tx_juxin",time());
		me->delete_temp("last_damage_from");
		message_vision(HIR"$N��������ס����������������ʢ��һ����ȣ�����Ԫ�����棬������\n"NOR, me);	  
		tell_object(me,RED"�������������һ���֡�\n"NOR, me);	
	
		amount = 30;	
		amount = COMBAT_D->magic_modifier(me, me, "kee",me->query("max_kee")*amount/100);

		me->receive_fulling("kee",amount);
		me->receive_curing("kee",me->query("max_kee"),me);
			
		amount = 50;
		amount = me->query("max_force")*amount/100 ;
		if (me->query("force") + amount < me->query("max_force")*2)
				me->add("force", amount);	
			else
				me->set("force", me->query("max_force")*2);	

		me->force_status_msg("force");
		me->set("timer/pfm/tx_juxin",time());
		return 1;
}