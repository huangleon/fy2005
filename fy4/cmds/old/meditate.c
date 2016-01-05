// meditate.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    	int sen_cost=30, mana_gain;
    
    	seteuid(getuid());
	
	if (userp(me))
    		return notify_fail("��ָ���ѱ�exerciseȡ������help exercise \n");
	
    	if(environment(me)->query("no_fight"))
        	return notify_fail("�㲻����������ڤ˼��\n");
    	if( me->is_fighting() ) return notify_fail("ս����ڤ˼����������\n");
    	if( me->is_busy() )
        	return notify_fail("����һ��������û����ɣ�����ڤ˼��\n");
    
    	if( arg && !sscanf(arg, "%d", sen_cost) )
        	return notify_fail("��Ҫ�����پ���ڤ˼��\n");
    
    	if( sen_cost < 10 ) return notify_fail("������Ҫ�� 10 �㡸�񡹲���ڤ˼��\n");
    
    	if( (int)me->query("sen") < sen_cost )
        	return notify_fail("�����ھ���̫���ˣ�����ڤ˼������ʧ����Զ�Ѳ�������\n");
    
    	if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 70 )
        	return notify_fail("����������״��̫���ˣ��޷����о��񣡣���Ѫֵ������70%���ϣ�\n");
    
    	if( (int)me->query("gin") * 100 / (int)me->query("max_gin") < 70 )
        	return notify_fail("����������״��̫�����ˣ��޷�����ڤ˼��״̬��������ֵ������70%���ϣ�\n");
    
    	write("����ϥ����������ڤ˼��һ�����\n");
    
    	me->add("sen", -sen_cost);
    	me->start_busy(1);
    // This function ranged from 1 to 15 when sen_cost = 30
    	mana_gain = sen_cost * ((int)me->query_skill("spells")/10 
                            + (int)me->query_spi() ) / 30;
    	mana_gain = (mana_gain + random(mana_gain))/5;
    
    	if( mana_gain < 1 ) {
        	write("���ǵ��������۾���ֻ��������һƬ�հס�\n");
        	return 1;
    	}
    
    	me->add("mana", mana_gain );
    
    	if( (int)me->query("mana") > (int)me->query("max_mana") * 2) {
        	if( (int)me->query("max_mana") >=  ((int)me->query_skill("spells", 1) +
             			me->query_skill("spells")/5) * 5 ) {
            		write("���Ȼ��������һƬ���ң��ƺ������������Ѿ�����ƿ����\n");
            		me->set("mana", 2*me->query("max_mana"));
        	} else {
            		write("��ķ�������ˣ�\n");
			me->add("max_mana", 1);
			me->set("mana", me->query("max_mana"));
        	}
    	}	
    	return 1;
}


int help(object me)
{
    write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : meditate [<�ķѡ��񡹵�����Ԥ��ֵ 30>][0m
[0;1;37m����������������������������������������������������������������[0m 
����ڤ˼��������ľ�������Ч�ؼ������۳��ܹ�����ʩչ����������
�����������Լ��ķ�����

�����õ��ķ������ֵ == ���������ȼ�*5 + ��ǰ����Ч�����ȼ�
����:������ (spells)                           - ��ɲ� 200
  ���� ���� (spells)         �� ���ź�����       ��Ч�ȼ���500  
�������ֵ = 200*5 + 500 = 1500

ƽ��ת��Ч�ʣ� ����Ч�����ȼ������������ԣ���������

��ο� help attributes.txt 
���ָ�
	��������	����������	
	��������	�����������
	
	�ָ�������	������������������
	�ָ�����	�����������������
	�ָ�������	���������������������
[0;1;37m����������������������������������������������������������������[0m
HELP
        );
    return 1;
}
