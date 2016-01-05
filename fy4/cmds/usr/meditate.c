#include <ansi.h>
inherit F_CLEAN_UP;
int do_recover(object me,object target);

int main(object me, string arg)
{
		object target;
			
		if (!arg)
        	return notify_fail("�������ָ������\n");
        
       	if(!objectp(target = present(arg, environment(me))))
				return notify_fail("����û�����������\n");
        	
    	if( !target->is_corpse())
			return notify_fail("�������ָ����Ч�������壩��\n");
	
		if (!target->query("victim_player"))
			return notify_fail("����ֻ��ʹ�����Լ��������ϡ�\n");
	
		if ( target->query("victim_id")!= me->query("id"))	
			return notify_fail("����ֻ�����Լ���ʬ����ʹ�á�\n");

		if (!mapp(me->query("death")) || me->query("death/half_quest")>=0)
			return notify_fail("����������ʹ������\n");
		
		if (me->query("score") < 10)
			return notify_fail("��������ʮ�����ۣ�������۲��㡣\n");
	
		if (me->is_fighting() || me->is_busy())
			return notify_fail("��������æ�ţ�����ܾ�����������\n");
		
		if (target->query_temp("in_reviving"))
			return notify_fail("�����ڲ����������ʬ�塣\n");
		
		if (target->query("already_revived")|| !target->query("real_death")
			|| me->query("death/revived"))
			return notify_fail("���Ѿ��޷������ת������������ʲô�ˡ�\n");
		
		me->start_busy(10);
		target->set_temp("in_reviving",1);
		
		message_vision(HIW"$N�������������ַ�תָ��$n�����������ڸ�ǰ�����ײ��
���Ϻ�����죬��������΢������麮����������ͷ�������£��������档\n"NOR,me,target);
		call_out("do_recover",20,me,target);
    	return 1;
}

int do_recover(object me,object target){
	
		mapping buff;
		
		if (!me )	return	1;
		
		me->stop_busy();
		
		if (!target) {
			tell_object(me,"���ʬ����ʧ�ˣ��޷�����\n");
			return 1;
		}
		target->delete_temp("in_reviving");
		
		if (environment(target)!= environment(me)) {
			tell_object(me,"������򱻴���ˡ�\n");
			return 1;
		}
		
		if (me->query("score") < 10) {
			tell_object(me,"����������ʮ�����ۣ�������۲��㡣\n");
			return 1;
		}
		
		if (me->is_fighting() || me->is_busy()){
			tell_object(me,"��������æ�ţ�����ܾ�����������\n");
			return 1;
		}
		
		if (target->query("already_revived")) {
			tell_object(me,"���Ѿ��޷������ת������������ʲô�ˡ�\n");
			return 1;
		}
		
		message_vision(WHT"$N����һ����������վ���������������á�\n"NOR, me);
		tell_object(me,"���������һЩ����֮�������������ʧ�����ˣ�\n");
						
		
		me->add("score",-10);
		target->set("already_revived",1);

		me->add("death/half_quest",me->query("death/exp_lost")*50/100);
		
		if (me->query("death/half_quest")>=0) {
			me->delete("death/half_quest");		// �������
			me->delete("death/exp_lost");
		}	

/*		me->set("force",0);
		me->set("atman",0);
		me->set("mana",0);
		me->set("death_revive",time());
		me->force_status_msg("all");
		
		// THis just serves as a timer, all checks use query(death_time), so even relogin can't bypass
		buff =
		([
			"caster":me,
			"who":me,
			"type":"revive-sickness",
			"att":"curse",
			"name":"���ꡤ��������",
			"buff1":"revive-sickness",
			"buff1_c": 1,
			"time":180,
			"buff_msg":"$N�����������˼��㣬��վ��վ�����ˡ�\n"NOR,
		]);
		ANNIE_D->buffup(buff);*/
				
		
		me->set("death/revived",1);
		me->add("marks/self_revive",1);
		me->add("marks/revived",1);
		
		
		log_file("REVIVE_LOG",
	  			sprintf("%s,%s(%s) ʹ��meditate�ָ������� %d ����ʧ��\n",
	    		ctime(time()),me->name(1), geteuid(me),
	    		me->query("death/exp_lost")/2));
	    		
		return 1;
}		
			


int help(object me)
{
    write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : ����	meditate [0m
[0;1;37m����������������������������������������������������������������[0m 

������Σ�����أ�����ż�з�����������ֻҪ���ܹ��Ӵ����������
ʲô�������ܹ�������������ʧ��������ľ��幦Ч��ο�
����𡡣�����е������趨ƪ��

���������ս����ʹ�ã�����æ�ң����֡�

[0;1;37m����������������������������������������������������������������[0m
HELP
        );
    return 1;
}
