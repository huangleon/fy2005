// version.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string output;
//	write(__VERSION__+"\n");
	output = read_file("/doc/help/version.txt");
	write(output);
	return 1;
}
int help(object me)
{
  write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	version[0m
[0;1;37m����������������������������������������������������������������[0m   

���ָ�����ʾ��ϷĿǰ���õ�MudOS�Լ�MudLIB�汾.

[0;1;37m����������������������������������������������������������������[0m 
HELP
    );
    return 1;
}
 
