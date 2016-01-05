// enchant.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int pts;

	if( !arg || !sscanf(arg, "%d", pts) ) 
		return notify_fail("ָ���ʽ��enchant <��������>\n");

                if( pts < 0 || pts > (int)me->query_skill("spells")/3)
		return notify_fail("����������㣬����������ǿ��������\n");

	if( pts < 0 ) return notify_fail("��������������������\n");	
	me->set("mana_factor", pts);
	write("Ok.\n");
	return 1;
}

int help (object me)
{
	write(@HELP
ָ���ʽ: enchant <��������>
 
���ָ�������趨ʹ��ħ������ʱҪ������������ħ�����õ�����ǿ�ȡ�
��ͬ�����������������ͬ������Ҳ��һ������Щħ��ǿ����������ʹ����
�޷��������Լ�Ԧ�������������п��ܲ������µ������

HELP
	);
	return 1;
}
