// follow.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg ) return notify_fail("ָ���ʽ��follow <ĳ��>|none��\n");

	if( arg=="none")
		if( me->query_leader() ) {
			me->set_leader(0);
			write("Ok.\n");
			return 1;
		} else {
			write("�����ڲ�û�и����κ��ˡ�\n");
			return 1;
		}

	if( !objectp(ob = present(arg, environment(me))) )
		return notify_fail("����û�� " + arg + "��\n");

	if( !ob->is_character() )
		return notify_fail("ʲ�᣿����...." + ob->name() + "��\n");

	if( ob==me )
		return notify_fail("�����Լ���\n");

	me->set_leader(ob);
	message_vision("$N������ʼ����$nһ���ж���\n", me, ob);

	return 1;
}

int help (object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 		follow [<����>|none][0m
[0;1;37m����������������������������������������������������������������[0m   
 
���ָ�������ܸ���ĳ�˻�ĳ���
������� follow none ��ֹͣ���档
 
HELP
);
        return 1;
}
