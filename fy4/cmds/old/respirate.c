// respirate.c

#include <skill.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    	int gin_cost=30, atman_gain;
    	string magic_skill;
    
    	seteuid(getuid());
    
    	if (userp(me))
    		return notify_fail("��ָ���ѱ�exerciseȡ������help exercise \n");
    		
    	if(environment(me)->query("no_fight"))
        	return notify_fail("�㲻�������������С�\n");
    	if( me->is_fighting() )
        	return notify_fail("ս��Ҳ��һ�����У������ܺ�����������ͬʱ���С�\n");
    	if( me->is_busy() )
        	return notify_fail("����һ��������û����ɣ��������С�\n");
    
    	if( arg && !sscanf(arg, "%d", gin_cost) )
        	return notify_fail("��Ҫ�����پ������У�\n");
    
    	if( gin_cost < 10 ) return notify_fail("������Ҫ�� 10 �㾫�����ܽ������С�\n");
    
    	if( (int)me->query("gin") < gin_cost )
        	return notify_fail("�����ھ������㣬�޷�����������\n");
    
    	if( (int)me->query("kee") * 100 / (int)me->query("max_kee") < 70 )
        	return notify_fail("����������״��̫���ˣ��޷����о��񣡣���Ѫֵ������70%���ϣ�\n");
    
    	if( (int)me->query("sen") * 100 / (int)me->query("max_sen") < 70 )
        	return notify_fail("�����ھ���״��̫���ˣ��޷������Լ������飡������ֵ������70%���ϣ�\n");
    
    	write("����ϥ�����������۾���ʼ����˼����\n");
    	me->start_busy(1);
    	me->add("gin", -gin_cost);
    
    	// This function ranged from 1 to 15 when gin_cost = 30
    	atman_gain = gin_cost * ((int)me->query_skill("magic")/10 + (int)me->query_int() ) / 30;
    	atman_gain = (atman_gain + random(atman_gain))/5;
    
    	if( atman_gain < 1 ) {
        	write("������һ��С��ȴ˯���ˡ�\n");
        	return 1;
    	}
    
    	me->add("atman", atman_gain );
    
    	if( (int)me->query("atman") > (int)me->query("max_atman") * 2) {
        	if( (int)me->query("max_atman") >= ((int)me->query_skill("magic", 1) +
             					me->query_skill("magic")/5) * 5 ) {
            		write("�����һ��������ת��ͷ�ǵ���Ҫ�ѿ�һ�����ƺ������������Ѿ�������ƿ����\n");
        		me->set("atman", 2*me->query("max_atman"));	
        	} else {
            		write("�����������ˣ�\n");
            		me->add("max_atman", 1);
            		me->set("atman", me->query("max_atman"));
        	}
        }	
    	return 1;
}

int help(object me)
{
    write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : respirate [<�ķѡ�����������Ԥ��ֵ 30>][0m
[0;1;37m����������������������������������������������������������������[0m 
�������У����á������������������������项�ķ�������ľ���
ת���������

�����ĵõ����������ֵ == ���������ȼ�*5 + ��ǰ����Ч�����ȼ�
����:	 ���� (magic)                        - �����뻯  150
 	������ (magic)     �� Ǭ������         ��Ч�ȼ���275 
�������ֵ = 150*5 + 275 = 1025

ƽ��ת��Ч�ʣ� ����Ч�����ȼ������������ǣ���������

��ο� help attributes.txt
���ָ�
	��������	����������	
	���ӷ���	�����������
	
	�ָ�������	������������������
	�ָ�����	�����������������
	�ָ�������	���������������������
[0;1;37m����������������������������������������������������������������[0m
HELP
        );
    return 1;
}
