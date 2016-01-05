// poison ���������¶���Sillencer@fy4 

#include <ansi.h>
inherit SSERVER;

int main (object me, string arg)
{
	object ob, herb;
    	int skill;
    	string h_name, obname;
	function f;
	
    	if(me->query("class")!="knight")
    		return notify_fail("ֻ�п���ֵ��Ӳ��ܹ��Ա���Ⱦ����\n");

	skill = me->query_skill("dream-herb",1);
	if (skill < 75 || me->query_skill("herb")< 75)
		return notify_fail("�Ա���Ⱦ��������Ҫ75���������廨����ҩ����\n");

	if(!arg)
		return notify_fail("��Ҫ��ʲô�������渽��ʲôҩ��?\n");
	
	if(sscanf(arg,"%s %s",obname,h_name)!=2)
		return notify_fail("��ʽ�� poison <������> <ҩ����> \n");
		
	if(!objectp(herb = present(h_name,me)))
		return notify_fail("������û������ҩ�ݡ�\n");
		
	if(!objectp(ob=present(obname,this_player())))
		return notify_fail("������û�����������\n");
	
	if(!ob->query("weapon_prop"))
		return notify_fail(ob->name()+"���Ǳ�����\n");
	
	if (herb->query("type")!= "poison" || herb->query("material")!="herb")
		return notify_fail("����ҩ�ݲ�����������Ⱦ����\n");
	
	if (ob->query("skill_type") == "unarmed")
		return notify_fail("Ⱦ������ʹ���ڲ����������ϡ�\n");
	
	if (herb->query("level")> skill)
		return notify_fail("��������廨���ȼ�̫�ͣ���������������ҩ�ݵ����ԡ�\n");
		
	if (ob->query_temp("hit_ob",1))
		return notify_fail(ob->name()+"���Ѿ������������ˡ�\n");
		
	if (me->query("timer/apply_poison") + 10 > time())
		return notify_fail("Ъ������Ⱦ���ɡ�\n");
	
	if (me->is_busy())
		return notify_fail("��������æ��\n");
	
		
	f = (:call_other,"/obj/proc/proc_herb","hit_ob":);
	if(!functionp(f))
		return notify_fail("����ʧ�ܣ���֪ͨ��ʦ��顣\n");
		
	ob->set_temp("hit_ob",bind(f,ob));
	ob->set_temp("herb/owner", me);
	ob->set_temp("herb/proc_rate",herb->query("proc"));
	ob->set_temp("herb/proc_amount",herb->query("effect"));
	ob->set_temp("herb/proc_type",herb->query("field"));
	
	if(ob->query_temp("hit_ob",1))
	{
		message_vision(HIB"$NС�������ץ��һƬ"+herb->name()+ HIB"Ҷ����"+ob->name()+HIB"�Ŀ��ڴ�Ĩ��һ�飬\n"
				+ob->name() + HIB"�ķ���͸������ɫ�Ĺ�â��\n"NOR, me);
	}
	else 
		tell_object(me,"����ʧ�ܣ���֪ͨ��ʦ��顣\n");
	herb->add_amount(-1);
	call_out("remove_effect",180,ob);	// 3min duration, only owner can apply
	me->set("timer/apply_poison",time());
	me->perform_busy(1);
	return 1;
}


int remove_effect(object weapon)
{
	object holder;
	if(!weapon)	return 1;
	
	holder = environment(weapon);
	if(!holder) return 1;
	
	if(interactive(holder))	
		message_vision(CYN""+weapon->name()+CYN"�ķ��������ָ��������Ĺ���\n"NOR,holder);
	else	
		message("vision",CYN""+weapon->name()+CYN"�ķ��������ָ��������Ĺ���\n"NOR,holder);
	weapon->delete_temp("herb");
	weapon->delete_temp("hit_ob");
	return 1;
}


int help(object me)
{
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	poison <������> <ҩ����> [0m
[0;1;37m����������������������������������������������������������������[0m   
����ֵ��ӵ�ר��������ҩ���ڱ������¶�������75�������廨����ҩ������
�ڴ���������жԷ�������һ�����ʣ��������������öԷ��ܵ������˺���

�������˺�ҩ�ݣ�
���ĺ��ģ�L75��-75�����ĺ��ģ�L110��-150�����ĺ��ģ�L150��-200��
���ĺ��ģ�L180��-250�����ĺ��ģ�L200��-300��

�� ��Ѫ�˺�ҩ�ݣ�
�����߲ݣ�L75��-75���̻��߲ݣ�L110��-150���׻��߲ݣ�L150��-200��
�ƻ��߲ݣ�L180��-250���컨�߲ݣ�L200��-300��

�������˺�ҩ�ݣ�
��ڷۣ�L75��-75�����Ҷ��L110��-150�����ĩ��L150��-200��
����ࣨL180��-250����ڹ���L200��-300��

����ǰһ������ʱ���������廨���ȼ�����һ�����˺���ֵ��
[0;1;37m����������������������������������������������������������������[0m   
 
HELP
    );
    return 1;
}
 