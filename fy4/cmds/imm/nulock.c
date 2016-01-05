// wizlock.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int lvl;

	if( me!=this_player(1) ) return 0;
	if( wiz_level(me) < wiz_level("(wizard)") )
		return notify_fail("�����ʦ�ȼ�̫�ͣ�û��ʹ�����ָ���Ȩ����\n");
	if( !arg || arg=="" )
		return notify_fail("ָ���ʽ��nulock <0/1>\n");

	if( sscanf(arg, "%d", lvl)!=1 )
		return notify_fail("ָ���ʽ��nulock <0/1>\n");
	seteuid(getuid());
	if( LOGIN_D->set_newuser_lock(lvl) ) {
		write("���ƿ�ʼ�����������\n");
		return 1;
	} else
		return notify_fail("���ƿ�ʼ���������\n");
}

int help (object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	nulock <0/1>[0m
[0;1;37m����������������������������������������������������������������[0m    

���Ʒ����Ƿ���������

[0;1;37m����������������������������������������������������������������[0m  
HELP
);
        return 1;
}
 
