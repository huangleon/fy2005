// Silencer@fengyun workgroup	June.2005

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string output;
	object *ob;
	int i;
	
	seteuid(getuid());
	
	if (arg == "-refresh"){
		ob = users();	
		for (i=0;i<sizeof(ob);i++) {
			if (!ob[i] || !objectp(ob[i])) continue;
			if (!(i%10))
				reset_eval_cost();
			STATUS_D->compare_status(ob[i]);
		}
		write("����"+ sizeof(ob)+"�����󣬸�����ϡ�\n");
		return 1;
	}
		
	if (arg == "-rich")
	{
		output = STATUS_D->show_rich();
		me->start_more("", output, 0);		
	}	
	else if (arg == "-riddle")
	{
		output = STATUS_D->show_riddle();
		me->start_more("", output, 0);		
	}
	else {
		output = STATUS_D->show_top();
        me->start_more("", output, 0);
    }
    return 1;
}

int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	showtop [<����> .... ][0m
[0;1;37m����������������������������������������������������������������[0m  
���ָ����ʾ��TOP��ҵĽ����ٶȡ�

showtop 		��ʾtop15 ����ֵ�����
showtop -riddle:	��ʾtop15 ���ܵ����
showtop -rich:	��ʾtop15 �������

showtop -refresh ǿ��ϵͳ���µ�ǰ������ҵļ�¼���ķ���Դ��

ע����������Դ�ڵ�½���˳�ʱ�ļ�¼��

[0;1;37m����������������������������������������������������������������[0m
HELP
    );
    return 1;
}
