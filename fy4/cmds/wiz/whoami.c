// whoami.c

int main()
{
	write("��� User ID = " + getuid(this_player()) + "\n" );
	write("��� Effective User ID = " + geteuid(this_player()) + "\n" );
	return 1;
}

int help (object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	whoami[0m
[0;1;37m����������������������������������������������������������������[0m   

��ʾ����� User ID �� Effective User ID ��

[0;1;37m����������������������������������������������������������������[0m   
HELP
     );
    return 1;
}
