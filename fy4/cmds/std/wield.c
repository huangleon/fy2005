// wield.c

inherit F_CLEAN_UP;

int do_wield(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;

	if( !arg ) return notify_fail("��Ҫװ��ʲ��������\n");
	
	if(arg=="all") {
		inv = all_inventory(me);
		for(count=0, i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("equipped") ) continue;
			if(do_wield(me, inv[i]) ) count ++;
		}
		if (!count)
			write("���õĶ������ˡ�������\n");			
		return 1;
	}
	

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");

	if( ob->query("equipped") )
		return notify_fail("���Ѿ�װ�����ˡ�\n");

	return do_wield(me, ob);
}

int do_wield(object me, object ob)
{
	string str;

	if (ANNIE_D->check_buff(me,"disarmed"))
		return notify_fail("���ֱ����飬һʱ�޷��������������\n");
		
	if (userp(me)) {
		if (ob->query("class"))
		if (ob->query("class")!= me->query("class"))
			return notify_fail("��������书���ʺ������������\n");
		
		if (ob->query("experience"))
		if (ob->query("experience")>me->query("combat_exp"))
			return notify_fail("���ʵս����̫�ͣ����Ӳ������������������\n");
		
		if (ob->query("level_required"))
		if (ob->query("level_required") > F_LEVEL->get_level(me->query("combat_exp")))
			return notify_fail("���ʵս����ȼ�̫�ͣ����Ӳ��������������������"
				+ ob->query("level_required")+"����\n");
		
		if (ob->query("strength"))
		if (ob->query("strength")>me->query_str())
			return notify_fail("��ı���̫�����ٲ������������\n");
		
		if (ob->query("agility"))
		if (ob->query("agility")>me->query_agi())
			return notify_fail("�㲻�����ݣ��޷������������ת���⡣\n");
			
		if (ob->query("score"))
		if (ob->query("score")<me->query("score"))
			return notify_fail("�������̫������������������ݵ��˲��ʺ��ðɡ�\n");	
	}
	
	if (ob->query("item_damaged") && ob->query("weapon_prop/damage") < 5)
		return notify_fail("��������Ѿ������𻵣��������á�\n");
		
	if( ob->wield() ) {
		if( !stringp(str = ob->query("wield_msg")) )
			str = "$Nװ��$n��������\n";
//		message_vision(str, me, ob);
		F_EQUIP->selective_message(str,me,ob,"equip_msg");
		ob->query("equip_fun");
		me->set_temp("timer/switch_equip",time());	
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
	
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	wield all | <װ������>[0m
[0;1;37m����������������������������������������������������������������[0m   

���ָ������װ��ĳ����Ʒ������, �����Ҫӵ��������Ʒ.

ע�⣺��ʹ��ս��������æ��״̬���㶼����ִ�д�ָ�����һ������
	���ã���ִ�д�ָ��Ļغ����мܺ͹������������½���
	
�����ʹ��set�������Լ�������װ��/��ж����Ϣ
	set equip_msg <1��2 ���� 3>	
�˲�����Ŀ����Ϊ�˼���Ƶ���Ĵ�����жˢ���������Ϊ�����㽫������
�Լ�װ����ȥ����������Ϣ������ǣ����㽫����������װ����ȥ������
����Ϣ������ǣ�������������������Ϊ��ʡϵͳ��Դ�����˵�½ʱ�Զ�
��Ϊ2��
				
�������ָ��: unwield | wear | remove

[0;1;37m����������������������������������������������������������������[0m 
 
HELP
    );
    return 1;
}
