/*	ABILITY2

str/int/comp/agi/karma/con
mana/force/atman
gin/kee/sen

shaolin/lama/legend: con, composure, str, kee/gin/sen 150+

taoist/yinshi: int, karma, agi,  mana/force/atman 50+

huashan/bonze: comp, int, con, mana/force/atman 50+

officer/beggar/wolfmount/moon/knight/fugui agi, str, karma, mana/force/atman 50+

*/

#include <ansi.h>
inherit F_ABILITY;

int main(object me, string arg)
{
	string *lists,temp,id;
	
	int i, a_num, total_count, saved_book, saved_task, saved_count, saved_ability3, learned_ability3, n;
	object ob;
	string arg1, myclass;
	string *done_class = ({"huashan", "official", "beggar", "lama", "shenshui", "fugui", "shaolin", "wolfmount", "knight", "taoist", "yinshi", "bonze", "moon", "legend"});
	
	if( wizardp(me) ) {
		if( arg && sscanf(arg, "-%s", id) == 1 ) {
			ob = present(id, environment(me));
			if( !ob ) {
				ob = find_player(id);
			}
			if( !ob ) {
				ob = find_living(id);
			}
			if( !ob ) {
				return notify_fail("��Ҫ�쿴˭��������\n");
			}
		} else {
			ob = me;
		}
	} else {
		ob = me;
	}
	n = 300; // 300 task --> 1 ability3
	total_count = ob->query("TASK");
	saved_book = ob->query("marks/book_task");
	saved_task = total_count - saved_book;
	saved_count = saved_task + saved_book/2;
	saved_ability3 = saved_count/n;
	learned_ability3 = ob->query("learned_ability3");
	
	if( arg && ob == me ) {
		if( !sscanf(arg, "+ %d", a_num) ) {
			return notify_fail("��������ĸ�ʽ��ability3 + �������� \n");
		}
		if( member_array(ob->query("class"), done_class) != -1 ) {
			if (a_num < 1 || a_num > 10) {
				return notify_fail("û�д˴����������������1-10��\n");	
			}
		} else {
			if( a_num < 1 || a_num > 6 ) {
				return notify_fail("û�д˴����������������1-6��\n");
			}
		}
		if( F_LEVEL->get_level(ob->query("combat_exp")) < 40 ) {
			return notify_fail("�������������Ҫ����ȼ�40��\n");
		}			
		if( !stringp(myclass=ob->query("class")) ) {
			return notify_fail("���������ɣ�����ܹ���������书�ľ��裿\n");
		}
		if( !arrayp(m_ability[myclass]) ) {
			return notify_fail("OOPS�������ڵ����ɵ���ɫ��ûд��Ү��\n");
		} else {	
			arg1 = m_ability3[myclass][a_num-1];
			if( !check_ability_improve(ob, arg1, 3) ) {
				return notify_fail("��ľ���ȼ������������ո��ߵĸ���������\n");
			}
			if( !deduct_ability_cost(ob, arg1, 3) ) {
					return notify_fail("��û���㹻�������㴢������ߴ���������\n");
			}
			improve_ability(ob, arg1, 3);
			tell_object(ob, "�õ�"+ (a_num) + "���������ϡ�\n");
		}
		return 1;
	}

	write(sprintf(WHT"\t����	TASK %s��������\n"NOR,"/std/char/master"->query_chinese_class(ob->query("class"))));
	write(HIR BLK"����������������������������������������������������������������\n"NOR);
	write(WHT    "���		��Ч			  �ȼ�	    	��������\n"NOR);	
	write(HIR BLK"����������������������������������������������������������������\n"NOR);

//	if( ob->query("betrayer") ) {
//		write("������ʦǰ�ƣ��޷���������ɵľ��衣\n");
//	}
	if( !stringp(myclass=ob->query("class")) ) {
		write("������������ɫ��\n");
	} else if( !arrayp(m_ability[myclass]) ) {
		write("OOPS�������ڵ����ɵ���ɫ��ûд��Ү��\n");
	} else {
		for( i = 0; i < 6; i++) {
			write(WHT + (i+1)+ NOR"\t"+ get_ability_info(ob, m_ability3[myclass][i], 3) + NOR);		
		}
		if( member_array(myclass,done_class) != -1 ) {
			for( i = 6; i < 10; i++) {
				write(WHT + (i+1)+ NOR"\t"+ get_ability_info(ob, m_ability3[myclass][i], 3) + NOR);
			}
		}
	}
	write(HIR BLK"����������������������������������������������������������������\n"NOR);

	write("�������ܹ������"YEL + saved_task + NOR"��TASK��"YEL + saved_book + NOR"������������������"YEL + saved_count + NOR"TASK������
�ϼ�"WHT + saved_ability3 + NOR"��߼�������
���Ѿ���ȥ��" RED+ learned_ability3 +NOR "��߼���������ʣ��"HIG+ (saved_ability3-learned_ability3) + NOR"��ɹ����䡣\n");

	write(HIR BLK"����������������������������������������������������������������\n"NOR);
	
	return 1;
}


int help(object me)
{
write(@HELP

[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	ability3 [0m
[0;1;37m����������������������������������������������������������������[0m   

ability3 	����֪����Ŀǰ��ѧ����һ��������
ability3 + n	��ߵڣ��������ļ���

�߼������Ƿ����г�����ֵ������ֵ������������һ����Ҫ;����
��ͬ����ȼ��ģ������ߵ��˻��и������Ѫ����ɸ�����˺�����
���߿����и��ߵ�ѧϰЧ�ʡ���κ�������������ǳ�Ϊ���ֵ�һ
�����Ҫ��

��ϰ�����ĵ��������������Ǵ�TASK������ÿ300��TASK��������ת
��Ϊһ���߼������㹩����䡣
ÿ���һ��TASK�����׸��ι�����ҳ���������������Ի��һ����
����

����ľ��鼶�𵽴�40ʱ���Ϳ����������ĸ��������ˣ�
����ability3�Ϳ��Կ���һ���������б���ͬ���ɵĸ߼�������
��ͬ�ġ�Ŀǰÿ�����ɹ�������ѡ�񣬺ܿ콫�и�������ݼ��롣

ÿ����������ʮ����ÿ���Ĺ�Ч������ϸ˵����

����ϰʲô�أ�������ɸ�����ͬ���ɵ��ص���߸���ϲ��������
�ˡ����������ս���г־ã��Ͷ����Щ��������������������
��Ҫ���ɱ�����������Щ����������������÷��������ɣ���ô
��߲��ǿ������������ʣ����߶��Щ������������

ע������ͨ����ABILITY��ͬ���߼������е�ħ������������������
�߲�����������Ӧ�ľ�������ֵ��

[0;1;37m����������������������������������������������������������������[0m  
HELP
    );

    return 1;
}
 
