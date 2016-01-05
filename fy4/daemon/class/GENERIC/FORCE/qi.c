// recover.c

// 2009 FengYun
// Edit by hippo 2009.11
// ����Т��֧��

inherit SSERVER;

int exert(object me, object target, int amount)
{
        int skill=0;
        int m=0;

        if( target != me ) 
        	return notify_fail("��ֻ�����ڹ������Լ�����Ϣ��\n");

				if(amount == -1) amount = 20;
				else if(amount < 20 ) 
                return notify_fail("�����ö�ʮ������\n");

        if( (int)me->query("force") < amount )
                return notify_fail("�������������\n");

				skill = (int)me->query_skill("xiaodao",1);
				
				if (skill >= 200) {m = 130;} 
	  		else if (skill >=150) {m = 122;}
	    	else if (skill >=100) {m = 115;}
				else if (skill >=50) {m = 108;}
				else {m=100;}
				
        me->receive_heal("kee", (10 + (int)me->query_skill("force")/10)*amount/20*m/100 );
        me->add("force", -amount);

        message_vision("$N�������˼���������ɫ�������ö��ˡ�\n", me);

        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}
 
int help(object me)
{
    write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	exert qi [<�ķ�����������Ԥ��ֵ ��0>][0m
[0;1;37m����������������������������������������������������������������[0m   
ָ���ʽ : exert qi [<�ķ�����������Ԥ��ֵ ��0>]
 
�����������ָ�������

ƽ���ָ�ֵ�� �������ķ���������Ч�ڹ��ȼ���������

������� ��
	exert shen���ָ�����
	exert jing���ָ�������
[0;1;37m����������������������������������������������������������������[0m   
HELP
        );
    return 1;
}