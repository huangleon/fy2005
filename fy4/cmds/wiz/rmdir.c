// rmdir.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string dir;

	if(!arg) return help(me);

	dir = resolve_path(me->query("cwd"), arg);

	seteuid(geteuid(me));
	if( rmdir(dir) )
		write("Ok.\n");
	else
		write("ɾ��ʧ�ܡ�\n");
	return 1;	
}

int help(object me)
{
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	rmdir <��Ŀ¼��>[0m
[0;1;37m����������������������������������������������������������������[0m   

ָ���ʽ : rmdir <��Ŀ¼��>

ɾ��һ���յ���Ŀ¼��

[0;1;37m����������������������������������������������������������������[0m 
HELP
	);
	return 1;
}
