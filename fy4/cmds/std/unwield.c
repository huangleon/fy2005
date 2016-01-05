// unwield.c

inherit F_CLEAN_UP;

int do_unwield(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	string str;
	int i, count;

	if( !arg ) return notify_fail("��Ҫ����ʲ�᣿\n");

	if (me->is_busy())
		me->set_temp("timer/switch_inbusy",time());

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if (do_unwield(me, inv[i])) count++;
		if (!count)
			write("��û��װ���κ�������\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");
	return do_unwield(me, ob);
}

int do_unwield(object me, object ob){
	string str;

	if( (string)ob->query("equipped")!="wielded" )
		return notify_fail("�㲢û��װ������������Ϊ������\n");

	if( ob->unequip() ) {
		if( !stringp(str = ob->query("unwield_msg")) )
			str = "$N�������е�$n��\n";
		me->set_temp("timer/switch_equip",time());
//		message_vision(str, me, ob);
		F_EQUIP->selective_message(str,me,ob,"equip_msg");
		return 1;
	} else
		return 0;
}

int help(object me)
{
  write(@HELP

[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	unwield all | <��Ʒ��>[0m
[0;1;37m����������������������������������������������������������������[0m   
	
���ָ������������е�������

ע�⣺��ʹ��ս��������æ��״̬���㶼����ִ�д�ָ�����һ������
	���ã���ִ�д�ָ��Ļغ����мܺ͹������������½���
	
�����ʹ��set�������Լ�������װ��/��ж����Ϣ
	set equip_msg <1��2 ���� 3>	
�˲�����Ŀ����Ϊ�˼���Ƶ���Ĵ�����жˢ���������Ϊ�����㽫������
�Լ�װ����ȥ����������Ϣ������ǣ����㽫����������װ����ȥ������
����Ϣ������ǣ�������������������Ϊ��ʡϵͳ��Դ�����˵�½ʱ�Զ�
��Ϊ2��

�������ָ��: wield | wear | remove

[0;1;37m����������������������������������������������������������������[0m    
HELP
    );
    return 1;
}
 
