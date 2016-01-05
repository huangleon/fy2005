// promote.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string old_status, new_status;
	int my_level, ob_level, level;

#ifdef	ENCRYPTED_WRITE	
		string *allowed = ({ "(wizard)","(immortal)","(player)" });
#endif   

#ifdef	NONENCRYPTED_WRITE	
		string *allowed = ({ "(admin)","(arch)","(wizard)","(immortal)","(player)" });
#endif   

	if( me!=this_player(1) ) return 0;

	if( !arg || sscanf(arg, "%s %s", arg, new_status)!=2 )
		return notify_fail("ָ���ʽ��promote <ʹ����> <�ȼ�>\n");

	if( member_array(new_status,allowed) == -1) 
		return notify_fail("û�����ֵȼ���\n");
	
	if( !objectp(ob = present(arg, environment(me))) 
	||	!userp(ob) )
		return notify_fail("��ֻ�ܸı�ʹ���ߵ�Ȩ�ޡ�\n");

	if( wiz_level(me) < wiz_level(new_status) )
		return notify_fail("��û������Ȩ����\n");

	old_status = wizhood(ob);

	seteuid(getuid());
	if( !(SECURITY_D->set_status(ob, new_status)) )
		return notify_fail("�޸�ʧ�ܡ�\n");

	message_vision("$N��$n��Ȩ�޴� " + old_status + " ��Ϊ " + new_status + " ��\n", me, ob);
	log_file( "static/promotion", getuid(me)+" promoted " + getuid(ob) 
		+ " from "+ old_status + " to " + new_status + " on " + ctime(time()) + "\n" );
	seteuid(getuid());
	ob->setup();

	return 1;
}

int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	promote <ĳ��> (Ȩ�޵ȼ�)[0m
[0;1;37m����������������������������������������������������������������[0m   

��������Ȩ�޵ȼ�, (player) (immortal) (wizard) (arch) (admin)
һ�� admin ������Ȩ�����κεȼ�, �� arch ֻ�������� arch��

ע������վ��promoteֻ������wizard��immortal��player���������ȼ�
����������ͨ��wizlist���С�

[0;1;37m����������������������������������������������������������������[0m 

HELP
    );
    return 1;
}
