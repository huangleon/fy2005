inherit F_CLEAN_UP;

int main(object me, string arg)
{
        int time;
        if(!arg || sscanf(arg,"%d",time)!=1)
        	return notify_fail("USAGE:convtime time.\n");
        write(sprintf("�������Ϊ��%d����Ӧʱ��Ϊ��%s\n",time,ctime(time)));
        return 1;
}

int help(object me)
{
     write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	convtime [0m
[0;1;37m����������������������������������������������������������������[0m   

���ָ�mud_timeת��Ϊ������ʱ����ʾ��

[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}
