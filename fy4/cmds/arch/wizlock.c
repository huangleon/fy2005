// wizlock.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int lvl;

	if( me!=this_player(1) ) return 0;
	if( wiz_level(me) < wiz_level("(arch)") )
		return notify_fail("�����ʦ�ȼ�̫�ͣ�û��ʹ�����ָ���Ȩ����\n");
	if( !arg || arg=="" )
		return notify_fail("ָ���ʽ��wizlock <��ʦ�ȼ�>\n");

	if( sscanf(arg, "%d", lvl)!=1 ) lvl = wiz_level(arg);
	seteuid(getuid());
	if( LOGIN_D->set_wizlock(lvl) ) {
		write(sprintf("\n������Ϸ�ȼ�������%s\n",chinese_number(lvl)));
		return 1;
	} else
		return notify_fail("����Ȩ���趨ʧ�ܡ�\n");
}

int help (object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	wizlock <��ʦ�ȼ�>[0m
[0;1;37m����������������������������������������������������������������[0m   

����ĳ���ȼ����µ�ʹ���߽�����Ϸ��
������ʦ�ȼ��ֱ�Ϊ (immortal) (wizard) (arch) (admin), ��Ҫȡ
������, ������ (player).

[0;1;37m����������������������������������������������������������������[0m  
HELP
);
        return 1;
}
 
