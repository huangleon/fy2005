// tail.c

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string file;

	seteuid(geteuid(me));
    if (!arg) return help(me);
	file = resolve_path(me->query("cwd"), arg);
	if( file_size(file)<0 ) return notify_fail("û�����������\n");
	tail(file);
	return 1;
}

int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	tail <����>[0m
[0;1;37m����������������������������������������������������������������[0m   

��ָ�������ֱ�Ӷ�ȡĳ������ĩβ�ļ��С�

[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}
