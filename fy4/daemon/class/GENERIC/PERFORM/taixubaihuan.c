// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;

int perform(object me, object target)
{
        int skill, ratio, amount, atman;
        
        skill = me->query_skill("ghosty-steps", 1);
		if(skill < 150) 
			return notify_fail("̫��ٻ���Ҫ150����̫��ò���\n");
	
        if (!target) target = me;
        if( target != me ) 
        	return 	notify_fail("��ֻ�ܽ�̫��ٻ������Լ������ϡ�\n");
        
        atman = me->query("atman");
        if (atman<10)
        	return notify_fail("��ħ��������̫��ٻ��޹�������\n");
	
        message_vision( BGRN + HIW "$N��Хһ��������������Ӱ����̫��ٻ�֮����������Ϣ��\n" NOR, me);
        
        ratio = skill * 100 /300;        
        
        amount = atman * ratio /100;
        
//      write ("amount is "+ amount +"\n");
        
        call_out("take_effect", 2, me, amount);
        me->set("atman",0);	
        me->perform_busy(1);     
        return 1;
}

int	take_effect(object me, int amount)	{
		
		if (!me || me->is_ghost())	return 1;
		
		if (me->query("force")+ amount > me->query("max_force")*2)
       	me->set("force",me->query("max_force")*2);
        else
        	me->add("force",amount);
		tell_object(me, "�����Ϣ������ϣ��ָ��˲���������\n"); 
		me->force_status_msg("force");       	
		return 1;
}
	