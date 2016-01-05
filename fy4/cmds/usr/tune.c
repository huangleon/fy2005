// tune.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    string *tuned_ch;
    //considerate for bt and tt.
    if(arg=="bt") arg="bangtalk";
    else if(arg=="tt") arg="teamtalk";
	if (arg == "announce")
		return notify_fail("��ʾƵ���޷����رա�\n");   

    tuned_ch = me->query("channels");
    if( !arg )
    {
        if( !pointerp(tuned_ch) || !sizeof(tuned_ch) )
            write("�����ڲ�û�������κ�Ƶ����\n");
        else
            write("������������Ƶ����" + implode(tuned_ch, ", ") + "��\n");
    }
    else if( pointerp(tuned_ch) && member_array(arg, tuned_ch)!=-1 )
    {
        write("�ر� " + arg + " Ƶ����\n");
        tuned_ch -= ({ arg });
        me->set("channels", tuned_ch);
    }
    else if(CHANNEL_D->valid_channel(me, arg))
    {
        write("�� " + arg + " Ƶ����\n");
        tuned_ch += ({ arg });
        me->set("channels", tuned_ch);
    }
    else return notify_fail("û�����Ƶ����\n");

    return 1;
}

int help(object me)
{
    write(@HELP

[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	tune [<Ƶ������>][0m
[0;1;37m����������������������������������������������������������������[0m   

���ָ������ѡ���Ƿ�Ҫ����ĳһƵ����ѶϢ�����û��ָ��Ƶ�����ƣ�
�ͻ��г���Ŀǰ�����е�Ƶ�������ָ����Ƶ����ԭ�������еľͻ�ص���
��֮�򿪡�

������һ��û�������е�Ƶ�����������Զ������򿪡�
Ҫ��һ��Ƶ��������ֻҪ�ã�

<Ƶ������> <ѶϢ> ....

���ӣ�
  chat hello everyone!
  
����������Ƶ���У�
    info �����š�
    vote ��ͶƱ��
    chat �����ġ�
    fy   �����ơ�
    new  �����֡�
    gab  ���о���
    rumor��ҥ�ԡ�
    bangtalk/bt����᡿
    teamtalk/tt�����顿
    
[0;1;37m����������������������������������������������������������������[0m 
HELP
	);
    if(wizardp(me))
        write(@HELP
��ʦ����������Ƶ���У�
    sys  ��ϵͳ��
    qst  ������
    wiz  ����ʦ��

HELP
            );
	return 1;
}

