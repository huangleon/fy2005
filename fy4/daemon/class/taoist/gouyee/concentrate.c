// concentrate.c

#include <ansi.h>

int exert(object me, object target, int amount)
{
        int mana_gain;
        if (me->query_skill("gouyee",1)<50)
        	return notify_fail("�����������Ҫ50�������ķ���\n");
        
        if( target && target!=me )
                return notify_fail("���������ֻ�������ָ��Լ��ķ�����\n");
             
        if(amount == -1) amount = 30;
        else if(amount < 30 ) 
                return notify_fail("��������ʮ������\n");

        if( (int)me->query("force") < amount )
                return notify_fail("�������������\n");
        
        if (me->query("mana") >= 2*me->query("max_mana"))
        	return notify_fail("��ķ����Ѿ������ֵ�ˡ�\n");
        
        // eff. 1.5x
        mana_gain =  (10 + (int)me->query_skill("gouyee",1))*amount/100;
        
        if( mana_gain + (int)me->query("mana") > (int)me->query("max_mana")*2 )
                me->set("mana", (int)me->query("max_mana")*2);
        else
                me->add("mana", mana_gain);
        me->add("force", -amount);
        message_vision(
                BGRN+ WHT "$N��Ŀ�����ù����ķ���������ת��һ�Ρ��������������\n"
                "һ��������$N����ɢ���������$P�Ķ��ģ�Ȼ�Ỻ����ȥ��\n" NOR, me);

        if( me->is_fighting() ) me->perform_busy(1);
        	
        me->force_status_msg("all");
        	
        return 1;
}
 
/*

������     /��              ��\      
������   ��   �ܣߣߡ�������  ��       
������   �� ����    ���������v��       
������    �M                  ��       
������    ��   /��\    /��\   ��      
������    ��   ����    ��  �� ��       
������   ��    \ /    \��/    ��      
������    ����      ��      ���M         
������    ���v��    ��   ������         
������    �q������������������           
������   ��   ��           /���\����    
������  ��____��  �� ��  �� .. ����     
������        \���/ ����ܡ�         
                       ��             
����������������- FengYun - ������
 ��������������annie 06.2005
 ��������dancing_faery@hotmail.com

*/
