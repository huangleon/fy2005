// status.c

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	string msg;

	msg = (string)mud_status(arg=="detail" ? 1 : 0);
	if( stringp(msg) ) write(msg);

	return 1;
}

int help(object me)
{
  write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	status [detail][0m
[0;1;37m����������������������������������������������������������������[0m   

���ָ�������ʾ��Ŀǰ��Ϸ��һЩ������ϼ�״��.

[0;1;37m����������������������������������������������������������������[0m  
HELP
    );
    return 1;
}
 
