// localcmds.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	mixed *cmds;
	int i;
    
#ifdef	ENCRYPTED_WRITE	
		return notify_fail("������ֻ���ڣ���վ�����Ҫ���С�\n");
#endif      
       
    if(!me->query("env/yesiknow")) return notify_fail("���ָ���Ѿ����ϳ��ˣ�\n");
		
	cmds = me->query_commands();
	write("�����ϼ����ܵ���Ʒ�����ڵĻ����ṩ����ָ�\n");
	for(i = 0; i<sizeof(cmds); i++) {
		if( cmds[i][2]==me ) continue;
		printf("%-15s  %2d %O\n", cmds[i][0], cmds[i][1], cmds[i][2]);
	}
	return 1;
}

int help()
{
	write(@TEXT
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	localcmds[0m
[0;1;37m����������������������������������������������������������������[0m   

�г������ϼ����ܵ���Ʒ�����ڵĻ����ṩ������ָ�

[0;1;37m����������������������������������������������������������������[0m   
TEXT
	);
	return 1;
}

