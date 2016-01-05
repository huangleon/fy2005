// snoop.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob, ob1;

	if( !arg ) {
		if( objectp(ob = query_snooping(me)) )
			write("���������ڼ���" + ob->query("name") + "���յ���ѶϢ��\n");
		else
			write("�����ڲ��ڼ����κ���Ϣ��\n");	
		return 1;
	} else if( arg=="none" ) {
		if( objectp(ob = query_snooping(me))
		&&	wiz_level(ob) >= wiz_level(me) )
			tell_object(ob, HIW + me->name(1) + "ֹͣ���������յ���ѶϢ��\n" NOR);
		snoop(me);
		if (objectp(ob))
			write("������ֹͣ����" + ob->query("name") + "���յ���ѶϢ��\n");
		else
			write("�����ڲ��ڼ����κ���Ϣ��\n");
		return 1;
	}

	ob = find_player(arg);
	if(!ob) ob = find_living(arg);
	if(!ob || !me->visible(ob)) return notify_fail("û������ˡ�\n");

	if( wizhood(me) != "(admin)"
	&&	wiz_level(me) <= wiz_level(ob) )
		return notify_fail("��û�м���" + ob->name() + "������ѶϢ��Ȩ����\n");

	if( me==ob ) return notify_fail("���� snoop none ���������\n");
	
	if (objectp(ob1=query_snoop(ob)))
		return notify_fail(ob1->name()+"���ڼ���"+ob->name()+"����Ϣ��\n");
	
	if (ob->query_temp("netdead",1))
		return notify_fail("���������ڶ���״̬��\n");
	
	if (!userp(ob))
		return notify_fail("û������NPC��Ϣ�ġ�\n");
				
	snoop(me, ob);
	write("�����ڿ�ʼ����" + ob->name(1) + "���յ���ѶϢ��\n");
	if( userp(ob) ) log_file("SNOOP_PLAYER",
		sprintf("%s(%s) snoops %s on %s.\n", me->name(1), geteuid(me), ob->name(1),
			ctime(time()) ) );
	if( wizardp(ob) && wizhood(me) != "(admin)")
		tell_object(ob, HIW + me->name(1) + "��ʼ���������յ���ѶϢ��\n" + NOR);

	return 1;
}

int help()
{
	write(@TEXT
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	snoop <ĳ��>|none[0m
[0;1;37m����������������������������������������������������������������[0m   

��������ʹ������������ѶϢ��snoop none ��ȡ��������

[0;1;37m����������������������������������������������������������������[0m   
TEXT
	);
	return 1;
}
