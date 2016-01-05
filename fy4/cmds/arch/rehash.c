// rehash.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !arg )
		return notify_fail("ָ���ʽ��rehash <·��>\n");

	if( arg[strlen(arg)-1]!='/' ) arg += "/";
	if(  file_size(arg)!=-2 )
		return notify_fail("û�����Ŀ¼��\n");

	write("����ָ���" + arg + "\n");
	COMMAND_D->rehash(arg);
	return 1;
}

int help(object me)
{
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	rehash <Ŀ¼����>[0m
[0;1;37m����������������������������������������������������������������[0m   

���ָ������ϵͳ�ڲ���ָ��������������ɾ����ĳ��Ŀ¼�µ�
ָ����������ָ����¸�Ŀ¼����ʹ�á�

[0;1;37m����������������������������������������������������������������[0m   
HELP
	);
	return 1;
}
