// Silencer @ FY4 workgroup. Aug.2004
#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
    	string msg;
    	int enhance, mod;
    
    	if (!wizardp(me) && userp(me))
    		return notify_fail("�㲻��ʹ�ô��ؼ���\n");
    	 
    	if(!me->is_fighting())
		return notify_fail("���ź�����ֻ������ս����ʩչ��\n");
    	    	
    	if(me->query_skill("flame-strike", 1) < 100 )
        	return notify_fail("������ź����������ߣ�\n");
    
    	if( !target ) target = offensive_target(me);
    	if( !target
		||!target->is_character()
		||target->is_corpse()
		||target==me)
        	return notify_fail("��Ҫ��˭ʩչ���������\n");

    	if(target->query("disable_type") ==HIW "<������>" NOR)
		return notify_fail("�Է��Ѿ����ܶ����ˡ�\n");

    	msg = HIW "$N�������գ��γ�һ������ĺ�������$n������\n\n" ;
    
    	enhance = 400;
    	if (COMBAT_D->do_busy_attack(me, target, "flame-strike/freeze", "unarmed", enhance, 10))
    	{
		msg +="����ĺ�����Χ��$n��ȫ����$n���۳ɱ��飡\n";
        	target->set_temp("disable_inputs",1);
        	target->set("disable_type",HIW "<������>" NOR);
        	target->set_temp("is_unconcious",1);
        	target->start_call_out( (: call_other, __FILE__, "remove_frozen",target :),10);
    	} else  
    		msg += "���Ǳ�$n����ض㿪�ˡ�\n";
    
    	message_vision(msg+NOR, me, target);
    	target->kill_ob(me);
    	me->kill_ob(target);
    	me->perform_busy(2);
    	return 1;
}


void remove_frozen(object me)
{
    	if (!me || me->is_ghost() || !objectp(me))	return;
    	me->delete("disable_type");
    	me->delete_temp("disable_inputs");
    	me->delete_temp("is_unconcious");
    	message_vision(HIR "\n\n$N����һ��ŭ��˫��һ�񣬽��������۵ı�����÷��飡��\n\n" NOR, me);
}


