// enhancesave.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int points, num;

	if( !arg ) 
	return notify_fail("�����Ѵ�����"+(string)(me->query("enhance/pot_save"))+"��Ǳ�ܡ�\n");
	
	points = me->query("potential") - me->query("learned_points");
	
	if (sscanf(arg,"%d",num)!=1)
		return notify_fail("Enhancesave <Ǳ����Ŀ>\n");
		
	if( num<0 )
		return notify_fail("�����Ǳ�ܱ�����������\n");
	
	if( points < num )
		return notify_fail("�����е�Ǳ���������������Ŀ��\n");

	if(me->is_busy())
		return notify_fail("���ϸ�������û��ɡ�\n");

	me->add("enhance/pot_save", num);
	me->add("potential",-num);
	write("��ɹ��ش�����" + (string)(num)+ "��Ǳ�ܣ�\n");
	me->start_busy(1);
	return 1;
}

int help(object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	enhancesave <Ǳ��ֵ>[0m
[0;1;37m����������������������������������������������������������������[0m   

���ָ��������㽫Ǳ�ܴ洢���������Ժ��Enhance��
�洢���Ǳ�ܽ������ٷ��أ�ֻ������Enhance��
ʹ���޲�����Enhancesave�ɲ쿴��ǰ�Ѵ洢��Ǳ��ֵ��

[0;1;37m����������������������������������������������������������������[0m  

HELP
        );
        return 1;
}
