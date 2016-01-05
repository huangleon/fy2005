// annie 07.2003 && Silencer @ FY4 workgroup. Oct.2004


#include <ansi.h>
inherit F_ABILITY;

int main(object me, string arg)
{
	string *lists,temp,id;
	
	int i, a_num, saved_quest, saved_quest1, saved_ability, learned_ability;
	object ob;
	string arg1, myclass;
	
	if (wizardp(me))
	{
		if(arg && sscanf(arg, "-%s", id) == 1)
		{
			ob = present(id, environment(me));
			if (!ob) ob = find_player(id);
			if (!ob) ob = find_living(id);
			if (!ob) return notify_fail("��Ҫ�쿴˭��������\n");			
		} else
			ob = me;					
	} else
		ob = me;

	saved_quest = ob->query("saved_quest")/60;
	saved_quest1 = (ob->query("saved_quest")*100/60)%100;
	saved_ability = saved_quest/100;			// 100��Quest��һ��ability
	learned_ability = ob->query("learned_ability");
	
	if (arg && ob==me)
	{
		if (!sscanf(arg,"+ %d",a_num))
			return notify_fail("��������ĸ�ʽ��ability + �������� \n");
		if (a_num <1 || a_num > 20)
			return notify_fail("û�д˴����������������1-20��\n");
		if (F_LEVEL->get_level(ob->query("combat_exp"))< 80)
			return notify_fail("�������������Ҫ����ȼ�80��\n");
			
		if (a_num<16)
		{
			arg1 = g_ability[a_num-1];
			
			if (!check_ability_improve(ob, arg1,0))
				return notify_fail("��ľ���ȼ������������ո��ߵĸ���������\n");
			if (!deduct_ability_cost(ob, arg1,0))
				return notify_fail("��û���㹻�������㴢������ߴ���������\n");
			improve_ability( ob, arg1, 0);
			tell_object(ob, "�õ�"+ (a_num) + "���������ϡ�\n");
			return 1;
		}
		
		if (!stringp(myclass = ob->query("class")))
			return notify_fail("���������ɣ�����ܹ���������书�ľ��裿\n");
		
		if (!arrayp(m_ability[myclass]))
		{
			return notify_fail("OOPS�������ڵ����ɵ���ɫ��ûд��Ү��\n");
		} else
		{	
			arg1 = m_ability[myclass][a_num-16];
			if (!check_ability_improve(ob, arg1,1))
				return notify_fail("��ľ���ȼ������������ո��ߵĸ���������\n");
			if (!deduct_ability_cost(ob, arg1,1))
				return notify_fail("��û���㹻�������㴢������ߴ���������\n");
			improve_ability( ob, arg1, 1);
			tell_object(ob, "�õ�"+ (a_num) + "���������ϡ�\n");
		}
				
		return 1;
	}
	
	write(WHT"\t����		������������\n"NOR);
	write(HIR BLK"����������������������������������������������������������������\n"NOR);
	write(WHT    "���		��Ч			  �ȼ�	    	��������\n"NOR);	
	write(HIR BLK"����������������������������������������������������������������\n"NOR);
	
	for(i=0; i<sizeof(g_ability); i++)
		write(WHT + (i+1)+ NOR"\t"+ get_ability_info(ob, g_ability[i],0) + NOR);		
	write(HIR BLK"����������������������������������������������������������������\n"NOR);

		
	write(WHT"\t����		������������\n"NOR);
	write(HIR BLK"����������������������������������������������������������������\n"NOR);
	
	if (!stringp(myclass = ob->query("class")))	write("������������ɫ��\n");
//	else if (ob->query("betrayer"))
//		write("������ʦǰ�ƣ��޷���������ɵľ��衣\n");
	else if (!arrayp(m_ability[myclass]))
		write("OOPS�������ڵ����ɵ���ɫ��ûд��Ү��\n");
	else
		for(i=0; i<5; i++)
			write(WHT + (i+16)+ NOR"\t"+ get_ability_info(ob, m_ability[myclass][i],1) + NOR);		

	write(HIR BLK"����������������������������������������������������������������\n"NOR);

	write("�������ܹ������"YEL+ saved_quest + "."+ saved_quest1+ NOR"������Quest���ϼ�"WHT + saved_ability + NOR"��������
���Ѿ���ȥ��" RED+ learned_ability +NOR "����������ʣ��"HIG+ (saved_ability-learned_ability) + NOR"��ɹ����䡣\n");

	write(HIR BLK"����������������������������������������������������������������\n"NOR);
	
	return 1;
}


int help(object me)
{
write(@HELP

[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	ability [0m
[0;1;37m����������������������������������������������������������������[0m   

ability 	����֪����Ŀǰ��ѧ����һ��������
ability + n	��ߵڣ��������ļ���

�����Ƿ���2005�г�����ֵ������ֵ������������һ����Ҫ;����
��ͬ����ȼ��ģ������ߵ��˻��и������Ѫ����ɸ�����˺�����
���߿����и��ߵ�ѧϰЧ�ʡ���κ�������������ǳ�Ϊ���ֵ�һ
�����Ҫ��

����ľ��鼶�𵽴�80ʱ���Ϳ����������ĸ��������ˣ�
�������������Ϳ��Կ���һ���������б��������࣬��һ
�๲�У�����������ɶ�������ϰ���������߻������Եģ���
������������������书�ľ������ڣ���ͬ���ɸ�����ɫ��

ÿ����������ʮ����ÿ���Ĺ�Ч������ϸ˵������ϰ��һ��������
Ҫ��Ϊ�ȼ�80����ϰ�ڶ���������Ҫ��Ϊ�ȼ�100��һ��ʼ��ʱ��
��Ҳ�����ֻ����ϰ���ڶ����������㱾��ȼ�����ߣ�����ÿ��
���弶����Զ���ϰһ����������

����ϰʲô�أ�������ɸ�����ͬ���ɵ��ص���߸���ϲ��������
�ˡ����������ս���г־ã��Ͷ����Щ��������������������
��Ҫ���ɱ�����������Щ����������������÷��������ɣ���ô
��߲��ǿ������������ʣ����߶��Щ������������

��ϰ�����ĵ��������������ܼ򵥣�Ҳ�Ǵ����������˵�Quest��
�õ�������ľ���ȼ��ﵽ80ʱ�������趨һ������
		set ability 1
�ڴ�����£�Quest������������ľ���ֵ������ת���������д���
������ÿ100��Quest����ת��Ϊһ�������㹩����䡣���������
��߾���ʱ��ֻ��Ҫ set ability 0 �Ϳ����ˡ�

ע�⣬���������ABILITY�������ֻ�ܴ���6�㣬����6���Quest
�������Զ����䵽�����ϡ�

[0;1;37m����������������������������������������������������������������[0m  
HELP
    );

    return 1;
}
 
