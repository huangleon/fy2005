// Silencer @ FY4 workgroup. Aug.2004
/*	��׷������zhuiya�������ߵ�һ���س���׷�ٺͰ�ɱ�����̼���
���ܲ���Ѫ����������������׷�ٶ��֣�������������ڶԷ�������
ͨʱ��ʹ�������Ρ�����100���� */


#include <ansi.h>
inherit SSERVER;

int conjure(object me, object target)
{
	
	object *inv;
	int lvl, i, num;
	
	lvl = me->query_skill("ninjitsu",1);	
	if (lvl < 100)
    	return notify_fail("׷����Ҫ100��������\n");
	
	if( me->query("atman") < 300 )
		return notify_fail("׷����Ҫ300���������\n");
        if (userp(me))	me->add("atman", -300);
	
	message_vision(RED"һ��Ѫ���$N����������������Ϣ���ڰ����ը������\n"NOR,me);
	
	inv = all_inventory(environment(me));
	for (i=0;i<sizeof(inv);i++)
	{
		if( inv[i]==me ) continue;
		if( inv[i]->is_corpse() ) continue;
		if( !inv[i]->is_character()) continue;
		if(!COMBAT_D->legitimate_kill(me,inv[i]))	continue;
     	if( wizardp(inv[i]) && inv[i]->query("wiz_invis"))	continue;
        if (ANNIE_D->check_buff(inv[i],"invisible")>0) 
           {
           		message_vision(RED"$Nδ�����ܣ��ѽ���������Ѫ�飬һ����ѣ��\n"NOR,inv[i]);
                inv[i]->perform_busy(3);
                ANNIE_D->debuff(inv[i],"invisible");
           	    inv[i]->set("timer/no_shade",time());
           }	
    }
    return 1;
}        
                
                
	
	
	
	