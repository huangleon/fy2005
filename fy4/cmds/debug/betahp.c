/* 	�ȼ�ϵͳ�����ڣ����������壯�����ߣ�����죮��
			���� by Silencer
	
*/
 
#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_LEVEL;

//	Some Reference for wizards.
//  100k (L34)��500k (L61)��1M(L78)��2M(L97)��3M(L109)
//  4M(L118)��5M(L128)��6M(L133),7M(L139),8M(L144),9M(L147),10M(L150)

string status_color(int current, int max);	//��ɫ 
 
int main(object me, string arg)
{
    	object ob;
    	mapping my, exp_data;
 	int level, old_level, pot_reward;
 	
    	seteuid(getuid(me));
 
    	if(!arg) ob = me;
    	else 
    	{
	        ob = present(arg, environment(me));
	        if (!ob) ob = find_player(arg);
	        if (!ob) ob = find_living(arg);
	        if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
    	}
    	     
    	my = ob->query_entire_dbase();
/*    	    printf(HIC"��"HIY"��������������������������������������������������������"HIC"��\n"NOR);	
    	    printf(CYN"    			"+ my["name"] + "\n"NOR);	
    	    printf(HIC"��"HIY"��������������������������������������������������������"HIC"��\n"NOR);	*/
	    printf(" ��������%s%5d/ %5d %s(%3d%%)" NOR "    ��ʳ�%s%3d%%\n" NOR,
	           status_color(my["gin"], my["eff_gin"]),	my["gin"],	my["eff_gin"],
	           status_color(my["eff_gin"], my["max_gin"]),	my["eff_gin"] * 100 / my["max_gin"],
	           status_color(my["food"], ob->max_food_capacity()),
	           my["food"] * 100/ob->max_food_capacity()	
	        );
	    printf(" ����Ѫ��%s%5d/ %5d %s(%3d%%)" NOR "    ����ˮ��%s%3d%%\n" NOR,
	           status_color(my["kee"], my["eff_kee"]), my["kee"], my["eff_kee"],
	           status_color(my["eff_kee"], my["max_kee"]),     my["eff_kee"] * 100 / my["max_kee"],
	           status_color(my["water"], ob->max_water_capacity()),
	           my["water"] * 100/ob->max_water_capacity()
	        );
	    printf(" ������%s%5d/ %5d %s(%3d%%)" HIW "    �����ۡ� %d\n" NOR,
	           status_color(my["sen"], my["eff_sen"]), my["sen"], my["eff_sen"],
	           status_color(my["eff_sen"], my["max_sen"]),     my["eff_sen"] * 100 / my["max_sen"],
	           my["score"]
	        );
	    printf(" ��������%s%5d/ %5d (%4d)" HIR "    ��ɱ���� %d\n" NOR,
	           status_color(my["atman"], my["max_atman"]),     my["atman"], my["max_atman"],
	           my["atman_factor"],
	           my["bellicosity"]
	        );
	    printf(" ��������%s%5d/ %5d (%4d)"  HIG "    ��Ǳ�ܡ� %d\n" NOR,
	           status_color(my["force"], my["max_force"]),     my["force"], my["max_force"],
	           my["force_factor"],
	           (my["potential"] - my["learned_points"])
	        );
	    exp_data = exp_to_level(my["combat_exp"]);    
	    
	    if (wizardp(me) && me->query("oldexp")) {	// ��������Wiz�þ��еľ�����ϵ�쿴��
	    	printf(" ��������%s%5d/ %5d (%4d)"HIM "    �����顿%d\n" NOR,
	           status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],
	           my["mana_factor"],
	           my["combat_exp"]		    		
	        );
	    } else 
	    	    printf(" ��������%s%5d/ %5d (%4d)"HIM "    ���ȼ��� ��%d ��%d.%d����\n" NOR,
		           status_color(my["mana"], my["max_mana"]), my["mana"], my["max_mana"],
		           my["mana_factor"],
				exp_data["level"],
		    		exp_data["sub"]/10,
		    		exp_data["sub"]%10,
		    	);
//	printf(HIC"��"HIY"��������������������������������������������������������"HIC"��\n"NOR);
   	level = exp_data["level"];
	if (ob == this_player() && level > ob->query("achieved_level")) {
    		
    		old_level = ob->query("achieved_level");
    		me->set("level",level);
    		me->set("achieved_level",level);
    		
    		write(HIR"\n��ϲ����ľ���ȼ�������"+chinese_number(me->query("level"))+"����\n"NOR);
		
		// ÿ�ȼ�����һ��Ǳ��ֵ��
		pot_reward = level_to_pot(level) - level_to_pot(old_level);
		me->add("potential",pot_reward);
		write(HIR"��õ���"+pot_reward+"��Ǳ�ܡ�\n"NOR);
		
		write (WHT"��������ѧ��������ľ�����ֵ�����ˡ�\n\n"NOR);

		me->save();
		if (me->query("gender")==("Ů��")) 
			message_vision(CYN"$N���ֵ����������� �� �������������ˣ���\n"NOR,me);
		else 
			message_vision(CYN"$N���������ʤ�������� �� V ��  ˵: �� �������������ˣ���\n"NOR,me);
			
	}    	
    	return 1;
}
 
string status_color(int current, int max)
{
    int percent;
 
    if( max>0 ) percent = current * 100 / max;
    else percent = 100;
    if( percent > 100 ) return HIC;
    if( percent >= 90 ) return HIG;
    if( percent >= 60 ) return HIY;
    if( percent >= 30 ) return YEL;
    if( percent >= 10 ) return HIR;
    return RED;
}
 
int help(object me)
{
    write(@HELP
    write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : hp [0m
[0;1;37m����������������������������������������������������������������[0m 
���ָ����ʾ��(���)��һЩ����״̬��

 �������� 4086/  4086 (100%)    ��ʳ�  0%
 ����Ѫ�� 5001/  5001 (100%)    ����ˮ��  0%
 ������ 4081/  4086 (100%)    �����ۡ� 946454
 �������� 1125/  1125 (   0)    ��ɱ���� 12
 �������� 1385/  1385 (  70)    ��Ǳ�ܡ� 3168879
 �������� 1109/  1109 (   0)    ���ȼ��� ��34 ��85.1����


[37m���ȼ���[32m��������������һ���������������Ҫ��������������ѧ��
	�书���ܵĸߵ��Լ���ս���е��������ȼ���İٷֱȱ�ʾ
	��һ�ȼ�����ɶȣ���������ʱ�����������Ľ�����
	������Ǳ�ܣ���������ѧϰ���ּ���
	������������ֵ��������

[37m��ʳ���ˮ��[32m	���ɿ�ջ���򲹳䣨�����������룩��

[37m�����ۡ�[32m���ۿ������Quest/Task������̽�յ���ߣ��ǰ�ʦѧ�ա�
	���÷��ݡ�������ɵȵı���������
	
[37m��ɱ����[32m����ɱ����Ŀ�����������̫���˻���ҹ����ڳ����ˣ���
	��ɱ����ȥ���Ƴ����ϴ��أ�����ʹ��һЩ������ڹ���
	����
	
[37m��Ǳ�ܡ�[32m����ѧϰ���ּ���

[37m��������[32m��������ο�����𡡣�������

��������ο� : score
[0;1;37m����������������������������������������������������������������[0m 

HELP
    );
    return 1;
}
