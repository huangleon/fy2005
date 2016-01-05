// kickout.c

#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if( !arg || sscanf(arg, "%s", arg) != 1 )
		return notify_fail("��Ҫ�ݻ�ʲô��\n");

	if( !objectp(ob = present(arg, me)) )
        return notify_fail("������û������������\n");
	if(me->query("id") != ob->query("owner"))
		return notify_fail("��������������ģ��㲻���Դݻ�����\n");
	seteuid(ROOT_UID);
	rm(ob->query_save_file()+".o");
	rm(base_name(ob) + ".c");
	ob->move(environment(me));
	destruct(ob);
	me->add("created_item",-1);
	me->delete("ji");		
	me->delete("ji2_times");
	seteuid(getuid());
	write("��Ʒ������ϡ�\n");
	return 1;

}

int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	destroy <ĳ���>[0m
[0;1;37m����������������������������������������������������������������[0m   

��ָ���������ݻ��㲻����Ҫ��������Ʒ�����ݻٵ������
��Զ�ӷ�������ʧ��

[0;1;37m����������������������������������������������������������������[0m   

HELP
    );
    return 1;
}

