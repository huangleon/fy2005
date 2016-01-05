// silencer@fy
#include <ansi.h>
#include <combat.h>
#include <command.h>
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra, enhance,duration;
	object room;
	mapping buff;
	
	if(me->query("class")!="beggar")
    	return notify_fail("���ֲ��ǽл��ӣ�ʹ��������߯������˰ɡ�\n");

	extra = me->query_skill("doggiesteps",1);
	if ( userp(me) && extra < 200) 
		return notify_fail("��������ǽ����Ҫ200����Ұ��������\n");

	enhance = me->query_skill("begging",1);
	if ( userp(me) && enhance < 160) 
		return notify_fail("��������ǽ����Ҫ160��������֮����\n");

	duration = me->query("timer/pfm/gb_gjtq")-time() + 900;
    if (duration>0)
    	return notify_fail("�㻹��Ҫ�ȴ�"+(duration/60)+"�������Ҳ����ٴ�ʹ�á�������ǽ��\n");
    		
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��������ǽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	room = environment(me);
	
	me->set("timer/pfm/gb_gjtq",time());
	
// 	Let's calculate escape chance of same agility opponents
//	It shall be 1- 50%*50%*50% = 87.5%, a very good value
//	So the penalty of that 12.5% will be .... death.
//	if 1/3 chance to escape, 1- 2/3*2/3*2/3 = 70%
//	it needs a timer

	message_vision(HIW"\n$N���һ���������类�Ƽ���Ұ����˫��������$n�߳���
����δ��֮ʱ��һ�����������ȥ��\n"NOR,me,target);
	
	me->delete_temp("marks/escape");
	me->add_temp("no_flee_msg",1);
	GO_CMD->do_flee(me);
	me->add_temp("no_flee_msg",-1);
	
	if (environment(me) != room) {
		message("vision",YEL"\n"+target->name()+YEL"һ�����ֲ�������"
				+me->name()+YEL"��������˹�ȥ�� \n"NOR,room,({me,target}));
		tell_object(target,YEL"��һ�����ֲ�������"+me->name()+YEL"��������˹�ȥ�� \n"NOR);
		return 1;
	} else
//		message_vision(HIR"$N����δ����ȴ���õ�ס��$n��ȥ·�� "NOR,target,me);		
	msg = YEL "$N�����ܻ������Ƴ�$n��$l��ȥ��" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg,"����");
	
	if (me->is_busy())	return 1;
	
	message_vision(HIW"\n$N������·������˫�ְڸ����ܣ��˻����Ҷ��ӡ�\n"NOR,me,target);
	me->delete_temp("marks/escape");
	me->add_temp("no_flee_msg",1);
	GO_CMD->do_flee(me);
	me->add_temp("no_flee_msg",-1);
	if (environment(me) != room) {
		message("vision",YEL"\n"+target->name()+YEL"һ�����ֲ�������"
				+me->name()+YEL"��������˹�ȥ�� \n"NOR,room,({me,target}));
		tell_object(target,YEL"��һ�����ֲ�������"+me->name()+YEL"��������˹�ȥ�� \n"NOR);
		return 1;
	} else
//		message_vision(HIR"$N����ĳ�һ�У���$n����������"NOR,target,me);
	msg = YEL "$N���л�ʵ�У�˫��һǰһ�������߳���" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg,"����");
		 
	if (me->is_busy())	return 1;
		
	message_vision(HIW"\n$N�޼ƿ�ʩ��������$n��ȥ��ȴ��$n����һ������ս���ӣ�\n"NOR,me, target);
	me->delete_temp("marks/escape");
	
	me->add_temp("no_flee_msg",1);
	GO_CMD->do_flee(me);
	me->add_temp("no_flee_msg",-1);
	if (environment(me) != room) {
		message("vision",YEL"\n"+target->name()+YEL"һ�����ֲ�������"
				+me->name()+YEL"���������˹�ȥ�� \n"NOR,room,({me,target}));
		tell_object(target,YEL"��һ�����ֲ�������"+me->name()+YEL"���������˹�ȥ�� \n"NOR);
		return 1;
	} else
//		
	message_vision(HIR"\n$N˫�������$nֻ����Ѫһ�ͣ�����ײ����һ����ǽ��\n"NOR, target, me);

	me->perform_busy(2);	
	return 1;
}

