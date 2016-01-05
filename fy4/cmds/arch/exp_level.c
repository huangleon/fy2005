#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_LEVEL;

int main(object me, string arg)
{
	int num;
	mapping data;
	
	if (!arg)
		return notify_fail("��ʽ������쿴�����ļ���\n");

	if (sscanf(arg, "%d/%d", num) != 1)
		return notify_fail("��ʽ������쿴�����ļ���\n");

	if ( num>0 && num <= 500)
	{
		write ("�ȼ���"+num+"��	���㾭��ֵ��"+level_to_exp(num,0)+"��\n");
		return 1;
	}
	
	if ( num > 2000 && num < 100000000)
	{
		data = exp_to_level(num);
		
		write("����ֵ��" + num + "�����㣺\n");
		write("	��ǰ�ȼ� = " + data["level"] + "\n");
		write("	�õȼ���ʼ���� = " + data["level_exp"] + "\n");
		write("	����ɰٷ��� = " + data["sub"] /10 + "." + data["sub"]%10 + "%\n");
		write("	��һ�ȼ�����Ҫ����ֵ = " + data["next_level"] + "\n");
		
		return 1;
	}	
		
	return notify_fail("��ʽ������쿴�����ļ���\n");
}
		
int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	exp_level [����][0m
[0;1;37m����������������������������������������������������������������[0m   
 
����������ʦ��龭����ȼ��Ļ��㣬��������һ�����֣�

������ַ�Χ��0-500֮�䣬��Ĭ��Ϊ���ɵȼ����㾭�飬
������ַ�Χ2000-100000000֮�䣬��Ĭ��Ϊ���ɾ��黻��ȼ���

[0;1;37m����������������������������������������������������������������[0m 
HELP	);
	return 1;
}