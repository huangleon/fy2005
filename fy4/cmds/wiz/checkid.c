inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object *u_list;
	int i,j;


	if(!stringp(arg))
		return notify_fail("��Ҫ��˭��\n");
	u_list=users();
	for(i=0; i<sizeof(u_list);i++)
	{
		if(u_list[i]->name(1)==arg)
	{
		write(arg+"=="+u_list[i]->query("id")+"\n");
		j=1;
	}
	}
	if(!j)
		write("û�з���������\n");
	return 1;
}       

int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	checkid <ĳ������> [0m
[0;1;37m����������������������������������������������������������������[0m   

����������Ѹ�ٷ���ĳ�������ֶ�Ӧ��id

[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}                              