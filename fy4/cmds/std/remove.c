// remove.c

#include <ansi.h>
inherit F_CLEAN_UP;

int 	do_remove(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;

	if( !arg ) return notify_fail("��Ҫ�ѵ�ʲ�᣿\n");

	if(arg=="all") {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
			if (do_remove(me, inv[i])) count++;
		if (!count)
			write("��û��װ���κ����\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");
	return do_remove(me, ob);
}

int do_remove(object me, object ob)
{
	string str;

	if( (string)ob->query("equipped")!="worn" )
		return notify_fail("�㲢û��װ������������\n");

	if( ob->unequip() ) {
		str = ob->query("unequip_msg")? ob->query("unequip_msg") : ob->query("unwield_msg");
		if( !stringp(str) )
			switch(ob->query("armor_type")) {
				case "cloth":
				case "armor":
				case "surcoat":
				case "boots":
					str = YEL "$N��$n"YEL"����������\n" NOR;
					break;
				case "bandage":
					str = YEL "$N��$n"YEL"���˿ڴ�����������\n" NOR;
					break;
				default:
					str = YEL "$Nж��$n"YEL"��װ����\n" NOR;
			}
		me->set_temp("timer/switch_equip",time());
		F_EQUIP->selective_message(str,me,ob,"equip_msg");			
		
		return 1;
	} else
		return 0;
}

	

int help(object me)
{
  write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	remove all | <��Ʒ����>[0m
[0;1;37m����������������������������������������������������������������[0m   
	
���ָ�������ѵ�����ĳ�����ߡ�

ע�⣺��ʹ��ս��������æ��״̬���㶼����ִ�д�ָ�����һ������
	���ã���ִ�д�ָ��Ļغ����мܺ͹������������½���
	
�����ʹ��set�������Լ�������װ��/��ж����Ϣ
	set equip_msg <1��2 ���� 3>	
�˲�����Ŀ����Ϊ�˼���Ƶ���Ĵ�����жˢ���������Ϊ�����㽫������
�Լ�װ����ȥ����������Ϣ������ǣ����㽫����������װ����ȥ������
����Ϣ������ǣ�������������������Ϊ��ʡϵͳ��Դ�����˵�½ʱ�Զ�
��Ϊ2��

�������ָ��: wear | wield | unwield

[0;1;37m����������������������������������������������������������������[0m   
 
HELP
    );
    return 1;
}
 
