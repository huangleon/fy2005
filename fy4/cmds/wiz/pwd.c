// pwd.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if( !arg ) {
		write("Cwd: " + (string)me->query("cwd") +  "\n");
		write("Cwf: " + (string)me->query("cwf") +  "\n");
		return 1;
	}
}

int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	pwd[0m
[0;1;37m����������������������������������������������������������������[0m   

���ָ�����ʾ����Ŀǰ�Ĺ���Ŀ¼ (cwd) ���������� (cwf).
'update' ���Ӳ���ʱ��������� cwf.

[0;1;37m����������������������������������������������������������������[0m 
HELP
    );
    return 1;
}
