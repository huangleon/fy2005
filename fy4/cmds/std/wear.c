// wear.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_wear(object me, object ob);

int main(object me, string arg)
{
	object ob, *inv;
	int i, count;

	if( !arg ) return notify_fail("��Ҫ����ʲ�᣿\n");

	if(arg=="all") {
		inv = all_inventory(me);
		for(count=0, i=0; i<sizeof(inv); i++) {
			if( inv[i]->query("equipped") ) continue;
			if(do_wear(me, inv[i]) ) count ++;
		}
	if (!count)
		write("�ܴ��Ķ������ˡ�������\n");
		return 1;
	}

	if( !objectp(ob = present(arg, me)) )
		return notify_fail("������û������������\n");

	if( ob->query("equipped") )
		return notify_fail("���Ѿ��������ˡ�\n");

	return do_wear(me, ob);
}

int do_wear(object me, object ob)
{
	string str;

	if( ob->query("female_only")
	&&	(string)me->query("gender") != "Ů��" )
		return notify_fail("����Ů�˵����Σ���һ��������Ҳ�봩������Ҳ���ߣ�\n");

	if( ob->query("male_only")
	&&	(string)me->query("gender") == "Ů��" )
		return notify_fail("���Ǵ����˵������һ��Ů��Ҳ�봩�����������˰ɣ�\n");

	if (userp(me)) {
		if (ob->query("level_required"))
		if (ob->query("level_required") > F_LEVEL->get_level(me->query("combat_exp")))
			return notify_fail("���ʵս����ȼ�̫�ͣ������ܴ����������"
				+ ob->query("level_required")+"����\n");
		
		if (ob->query("strength"))
		if (ob->query("strength")>me->query("str"))
			return notify_fail("�㲻��ǿ׳�����ʺϴ�������ס�\n");
		
		if (ob->query("agility"))
		if (ob->query("agility")>me->query("agi"))
			return notify_fail("�㲻�����ݣ�����������׻�ٲ�ά��ġ�\n");	
	}
		
	if( ob->wear() ) {
		if( !stringp(str = ob->query("wear_msg")) )
			switch( ob->query("armor_type") ) {
				case "cloth":
				case "armor":
				case "boots":
					str = YEL "$N����һ" + ob->query("unit") + "$n��\n" NOR;
					break;
				case "head":
				case "neck":
				case "wrists":
				case "finger":
				case "hands":
					str = YEL "$N����һ" + ob->query("unit") + "$n��\n" NOR;
					break;
				case "waist":
					str = YEL "$N��һ" + ob->query("unit") + "$n"YEL"�������䡣\n" NOR;
					break;
				default:
					str = YEL "$Nװ��$n��\n" NOR;
			}
//		message_vision(str, me, ob);
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
[0;1;36mָ���ʽ : 	wear all | <װ������>[0m
[0;1;37m����������������������������������������������������������������[0m   

���ָ������װ��ĳ�����ߡ�

ע�⣺��ʹ��ս��������æ��״̬���㶼����ִ�д�ָ�����һ������
	���ã���ִ�д�ָ��Ļغ����мܺ͹������������½���
	
�����ʹ��set�������Լ�������װ��/��ж����Ϣ
	set equip_msg <1��2 ���� 3>	
�˲�����Ŀ����Ϊ�˼���Ƶ���Ĵ�����жˢ���������Ϊ�����㽫������
�Լ�װ����ȥ����������Ϣ������ǣ����㽫����������װ����ȥ������
����Ϣ������ǣ�������������������Ϊ��ʡϵͳ��Դ�����˵�½ʱ�Զ�
��Ϊ2��

�������ָ��: remove | wield | unwield

[0;1;37m����������������������������������������������������������������[0m    
HELP
    );
    return 1;
}
