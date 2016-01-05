// wizlock.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int lvl;

	if( me!=this_player(1) ) return 0;
	if( wiz_level(me) < wiz_level("(arch)") )
		return notify_fail("�����ʦ�ȼ�̫�ͣ�û��ʹ�����ָ���Ȩ����\n");
	
	if( !arg || arg=="" ) {
		return notify_fail("��ǰ���ƿɵ�½���������Ϊ��"+ LOGIN_D->query_max_users()+" \n");	
	}
	
	if( sscanf(arg, "%d", lvl)!=1 ) 
		return notify_fail("�μ�HELP��ʽ˵����\n");
		
	seteuid(getuid());
	
	if (lvl>0 && lvl<10) {
		LOGIN_D->set_dummy_number(lvl-1);
		write(sprintf("\n��ǰÿ��ip����������������Ϊ%d\n", lvl));
		return 1;
	}
		
	if( LOGIN_D->set_max_users(lvl)) {
		write(sprintf("\n������Ϸ��������Ϊ%d	\n",lvl));
		return 1;
	} else
		return notify_fail("���������趨ʧ�ܡ�\n");
}

int help (object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	loginlock <����>[0m
[0;1;37m����������������������������������������������������������������[0m   

����������������

��1��������<10ʱ�����趨��ǰ��Ϸ��ÿ��ip���Ե�½����������ϷĬ��Ϊ3��

loginlock 1	��˼����ÿ��ipֻ��Ϊһ����

��2�����ƹ��ж���ʹ���߿��Խ�����Ϸ��
ÿ��������������logind����ȱʡ��½����Ϊ����������ָ��ɶ�̬����

loginlock 300		����ͬʱ��½����Ϊ300

ע�������Ҫ��ĳ��ip��һЩ��½�����Ļ���ʹ��netbar����

Ŀǰnetbar��������
��1��������Ϸȡ��ip-id����
��2����ĳ��ip�ӱ�login����

[0;1;37m����������������������������������������������������������������[0m  
HELP
);
        return 1;
}
 
