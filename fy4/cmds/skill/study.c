// study.c

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    	object ob;
    	mapping skill;
    	string  book,liter;
    	int cost, sena;
    	int amount=0;
    	int my_skill, liter_level;
    	string *att_skill = ({ "literate", "unarmed", "force", "foreknowledge", "chanting", "move" });
    
    	if(environment(me)->query("no_fight")||environment(me)->query("no_study") )
        	return notify_fail("�㲻����������ѧϰ��\n");
    	if( me->is_fighting() )
        	return notify_fail("���޷���ս����ר�������ж���֪��\n");
    	if( me->is_busy() )
        	return notify_fail("����һ��������û����ɣ������ж���֪��\n");

    	if(!arg || sscanf(arg, "%s %d", book, sena)!=2 )
        	return notify_fail("ָ���ʽ��study <��Ʒ> <������>\n");
    
    	if(!objectp(ob = present(book, me)) )
	if(!objectp(ob = present(book, environment(me))))
            	return notify_fail("��Ҫ��ʲ�᣿\n");
    
    	if( !mapp(skill = ob->query("skill")) )
        	return notify_fail("���޷�����������ѧ���κζ�����\n");

// added by tie
    	if(stringp(skill["literate"])) liter = skill["literate"];
    		else liter = "literate";
    	if( !me->query_skill(liter, 1) )
        	return notify_fail("�㿴����Ү��������ѧѧ"+SKILL_D(liter)->name()+"�ɡ�\n");

// added by silencer, require a certain level of basic skill to study certain skills.
    	if(skill["liter_level"]) {
    		liter_level = skill["liter_level"];
    		if (me->query_skill(liter,1) <liter_level)
    			return notify_fail("���"+SKILL_D(liter)->name()+"̫���ˣ���᲻��Ү����Ҫ"+liter_level+"����\n");	
		}
    
    	message("vision", me->name() + "��ר�ĵ��ж�" + ob->name()+ "��\n", environment(me), me);
    	if( (int)me->query("combat_exp") < skill["exp_required"] )
    	{
        	write("���ʵս���鲻�㣬�������Ҳû�á�\n");
        	return 1;
    	}
    	
    	notify_fail("����Ŀǰ����������û�а취ѧ������ܡ�\n");
    
        if( me->query_skill(skill["name"], 1) > skill["max_skill"] )
    	{
        	write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
        	return 1;
    	}
    
    	if( !SKILL_D(skill["name"])->valid_learn(me) ) return 0;
    
 /*   	cost = skill["sen_cost"] + skill["sen_cost"] 
        		* (skill["difficulty"] - (int)me->query_int())/20;
    	cost = cost /2;
    	if(cost < 1) cost = 1;*/
    	
    	cost = 1;		// Oh my god .. enough studying in schools already
    	
    	if( cost > sena)
		return notify_fail("����Ŀǰ��������������Ҫ��"+chinese_number(cost)+"����\n");
    
    	if( (int)me->query("sen") <= sena)
    	{
        	write("�����ڹ��ƣ�룬�޷�ר�������ж���֪��\n");
        	return 1;
    	}

	   	my_skill = me->query_skill(skill["name"], 1);
    	
    	if ( member_array(skill["name"], att_skill) == -1)
    		my_skill = my_skill * SKILL_D(skill["name"])->effective_level(me)/100;
    	else
    		my_skill = my_skill;
    	    	
    	if(my_skill * my_skill * my_skill  > (int)me->query("combat_exp")) {
        	write("�������ڵ�ʵս���飬�������Ҳ�޷���ᡣ\n");
        	return 1;
    	}
    	me->receive_damage("sen", sena);
    
    	if( !me->query_skill(skill["name"], 1) )
        	me->set_skill(skill["name"], 0);
    	
    	
    	amount = me->query_skill(liter, 1) * 10 + 1;
    	
       	if( amount < 1) amount = 1;  
       		
    	amount = amount*sena/cost;
    	
    	me->improve_skill(skill["name"], amount);
    	write("���ж��й�" + SKILL_D(skill["name"])->name() + "�ļ��ɣ��ƺ��е��ĵã�+"+ amount +"��\n");
    	return 1;
}

int help(object me)
{
    write( @HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : study <��Ʒ����> <�ķѡ����񡹵���>][0m
[0;1;37m����������������������������������������������������������������[0m

�����й������ֻ�ȡ���ܵ�;����	[1;31m���飨study��[0m
				ѧϰ��learn��
				���У�research��
				��ϰ��practice��

���ָ��ʹ����Դ����Ż�������Ʒ��ѧĳЩ����,
��ǰ����: ��һ��Ҫ�������ϵ����֣��е��鼮Ҳ����������Ҫ��
ÿ��ѧϰ����������Ķ���д�������йء�
����ѧ������ߵȼ�����ľ���ȼ���ء�

ע�⣺�������������Ե��鼮ѧϰϵ��Ϊ100

See also : learn, research, practice

[0;1;37m����������������������������������������������������������������[0m
HELP
        );
    return 1;
}
