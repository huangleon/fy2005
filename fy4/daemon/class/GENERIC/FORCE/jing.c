// regenerate.c

// 2009 FengYun
// Edit by hippo 2009.11
// ����Т��֧��


inherit SSERVER;

int exert(object me, object target, int amount)
{
        int skill=0;
        int m=0;

        if( target != me ) 
        	return notify_fail("��ֻ�����ڹ��ָ��Լ��ľ�����\n");

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

        me->receive_heal("gin", (10 + (int)me->query_skill("force")/10)*amount/20*m/100 );
        me->add("force", -amount);
       
	message_vision("$N�������˿������ֽŻ�˼��£������˿������л������ˡ�\n", me);
        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}
 
int help(object me)
{
    write(@HELP
ָ���ʽ : exert jing [<�ķ�����������Ԥ��ֵ ��0>]
 
�����������ָ�������

ƽ���ָ�ֵ�� �������ķ���������Ч�ڹ��ȼ���������

������� ��
	exert qi	���ָ�������
	exert shen	���ָ�����

HELP
        );
    return 1;
}