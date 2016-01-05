// dest.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string option, target, msg;

	object obj;

	if (!arg) return notify_fail("ָ���ʽ : dest <���֮���ƻ���>\n" );

	if( sscanf(arg, "-%s %s", option, target)!=2 ) target = arg;

	if( option == "-r" && (string)SECURITY_D->get_status(me)=="(admin)" )
		seteuid(ROOT_UID);
	else
		seteuid(geteuid(me));

	obj = find_object(target);
	if (!obj) obj = present(target, me);
	if (!obj) obj = present(target, environment(me));
	if (!obj) obj = find_object( resolve_path(me->query("cwd"), target) );
	
	if (!objectp(obj)) 
		return notify_fail("û���������....��\n");

	if ( userp(obj) &&  (string)SECURITY_D->get_status(me)!="(admin)" )
		return notify_fail("��û�дݻٶԷ���Ȩ�ޡ�\n");
	
	tell_object( me, sprintf("�ݻ������ %O\n", obj));
	
	msg = "";
	
	if( environment(me)==environment(obj) )
	{
		if( !stringp(msg = me->query("env/msg_dest")) )
			msg = "$N�ٻ���һ���ڶ�����$n��û�ˡ�\n";
		message_vision(msg + "\n", me, obj);
	}
	else {
		msg = "$N�ٻ���һ���ڶ�������Χ��û�ˡ�\n";
		message_vision(msg + "\n", me);
	}
	
	destruct(obj);
	if(obj) 
		write("���޷����������ݻ١�\n");
	else 
		write("����ݻٳɹ���\n");

	return 1;
}

int help(object me)
{
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	dest [-r] <���֮���ƻ���>[0m
[0;1;37m����������������������������������������������������������������[0m   

���ô�һָ��ɽ�һ�����(object)���������(class)�Ӽ������������
������������(����ָ�������������)����һ�βο�����������ʱ��
�����½������롣

���� (admin) ��ֵ���ʦ������ -r ѡ���� ROOT_UID ������������
���������ʹ���ߡ�

�ο����ϣ� destruct()

[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}
