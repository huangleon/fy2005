// practice.c �����书��Practice������100����
//	ͳһ������practice���Ѷȣ�ֻ��������ܵĸߵ��й�
//	ȥ���˵�һ��practice��ǿ�����ʹ�ý�ʡϵͳ��Դ��;����
//		--- by Silencer@fy

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    	string p_skill, skillname;
    	int skill, skill_basic, skill_level, skill_prac_limit;
    	int amount, times, num;
    	int o_kee, o_gin, o_sen, o_force, o_mana, o_atman;
    	int c_kee, c_gin, c_sen, c_force, c_mana, c_atman;    
    	int p_kee, p_gin, p_sen, p_force, p_mana, p_atman;
    
    	seteuid(getuid());
    	if(environment(me)->query("no_fight")||environment(me)->query("no_practice"))
        	return notify_fail("�㲻������������ϰ��\n");
    
    	if( me->is_fighting() )
        	return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");
    
    	if(!arg)
        	return notify_fail("ָ���ʽ��practice <����> <��ϰ����>\n");    
    	
    	if (sscanf(arg, "%s %d", p_skill, times)!=2)
    	    		return notify_fail("ָ���ʽ��practice <����> <��ϰ����>\n");    
    	
    	if( !p_skill ) 
    		return (__DIR__"enable")->main(me, p_skill);
    
    	if( !stringp(skillname = me->query_skill_mapped(p_skill)) )
        	return notify_fail("��ֻ����ϰ�������ܣ�ͬʱ������ָ����enable��
һ�����⼼�ܵ�Ҫ��ϰ�Ļ��������ϡ�\n");

	if (times < 1)
		return notify_fail("��ϰ����������ڵ���һ��\n");
		
    	skill_basic = me->query_skill(p_skill,1)/2 + 1;
    	skill = me->query_skill(skillname) + 1;
    	skill_prac_limit = SKILL_D(skillname)->practice_limit() > 99 ? 99 : SKILL_D(skillname)->practice_limit();

//      skill_prac_limit = SKILL_D(skillname)->practice_limit();
        	
    	if( skill < 1 )
        	return notify_fail("�����ûѧ������ܰɣ������ȥ��̱��ˡ�\n");
    	if( skill_basic < 1 )
        	return notify_fail("����ⷽ��ļ��ܻ���һ�ϲ�ͨ������ȴӻ���ѧ��\n");
        	
    	if( me->query_skill(skillname,1) > skill_prac_limit)
    		return notify_fail( SKILL_D(skillname)->name()+"������ֻ�ܿ�ѧϰ���о�������ˡ�\n");
  
    	if( !SKILL_D(skillname)->valid_learn(me) ) return 0;
    
    	skill_level= (int) me->query_skill(skillname, 1);

    	notify_fail("��������ϰ" + SKILL_D(skillname)->name() + "�����ǲ�û���κν�����\n");
    
//    	if ( times >1) {
    		o_kee = me->query("kee");
    		o_gin = me->query("gin");
    		o_sen = me->query("sen");
    		o_force = me->query("force");
    		o_mana = me->query("mana");
    		o_atman = me->query("atman");
    		//<- get status before 1 practicing
    	
    		//-> Start multi-practicing
	    	if(SKILL_D(skillname)->practice_skill(me)) {
		    	c_kee = me->query("kee");
	    		c_gin = me->query("gin");
	    		c_sen = me->query("sen");
	    		c_force = me->query("force");
	    		c_mana = me->query("mana");
	    		c_atman = me->query("atman");
	    		//<- immediately get current status after 1 practicing
		    	p_kee = o_kee - c_kee;
	    		p_gin = o_gin - c_gin;
	    		p_sen = o_sen - c_sen;
	    		p_force = o_force - c_force;
	    		p_mana = o_mana - c_mana;
	    		p_atman = o_atman - c_atman;
	    		//<- get the consumption
	    		if (p_kee) times = (times > c_kee/p_kee) ? c_kee/p_kee: times;
	    		if (p_gin) times = (times > c_gin/p_gin) ? c_gin/p_gin: times;
	    		if (p_sen) times = (times > c_sen/p_sen) ? c_sen/p_sen: times;
	    		if (p_force) times = (times > c_force/p_force) ? c_force/p_force: times;
	    		if (p_mana) times = (times > c_mana/p_mana) ? c_mana/p_mana: times;
	    		if (p_atman) times = (times > c_atman/p_atman) ? c_atman/p_atman: times;
			// <- get the least numbers allowed to practice
	    		if (p_kee) me->add("kee", -p_kee * (times-1));
	    		if (p_gin) me->add("gin", -p_gin * (times-1));
	    		if (p_sen) me->add("sen", -p_sen * (times-1));
	    		if (p_force) me->add("force", -p_force * (times-1));
	    		if (p_mana) me->add("mana", -p_mana * (times-1));
	    		if (p_atman) me->add("atman", -p_atman * (times-1));
	    		// <- receive the practice damage
			//write("times:" + (string) times + "|"+(string) p_kee + "|"+(string)p_gin + "|"+(string)p_sen + "|"+(string)p_force + "|"+(string)p_mana + "|"+(string)p_atman);
	    		if (times > 0) {
	        		amount = skill_basic*20 + 10; 
	        	//	write("amount is"+ amount + "\n");		
	        		// here changed by akuma on 2003-4-10
	        		// for those who have researched to pink :)
	        		if(me->query_learned()[skillname]<=(skill_level+1) * (skill_level+1)+1)
	        		{
	        			me->improve_skill(skillname, amount*times + random(1 + times/5), skill_basic > skill? 0: 1);
	        		}
	        		// <- random(1 + times/5) ***** giving a bit bonus for saving system resource
		        	write( HIY "���" + SKILL_D(skillname)->name() + "�����ˣ�\n" NOR);
	        		me->status_msg("all");
	        		me->force_status_msg("all");
	        		return 1;
	        	}
	        	else 
	        		return notify_fail("�������״���޷�ǿ����ϰ" + SKILL_D(skillname)->name() + "��\n");
	    	}
/*    	}
    	else {
	    	if(SKILL_D(skillname)->practice_skill(me)) {
	        	amount = (skill - 75) * SKILL_D(skillname)->black_white_ness()/100;
	        	if((amount < -25) && (skill < 75)) amount = -25;
	        	amount +=SKILL_D(skillname)->practice_bonus() + skill_basic/5 + 1;
	        	if( amount < 1) amount = 1;
	       		
	       		if (skill_level <30 && amount <3) amount =3;	
	       		if (skill_level >100) amount = amount*2;
	       		else if (skill_level >75) amount = amount*5;
	       		else amount = amount*10;
	       		
			if(me->query_learned()[skillname]<=(skill_level+1) * (skill_level+1)+1)
			{
	        		me->improve_skill(skillname, amount, skill_basic > skill? 0: 1);
	        	}
	        	write( HIY "���" + SKILL_D(skillname)->name() + "�����ˣ�\n" NOR);
	        	return 1;
	    	}
    	}*/
    	return 0;    
}

int help(object me)
{
    write(@TEXT
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	practice <����> <��ϰ����>[0m
[0;1;37m����������������������������������������������������������������[0m   

�����й������ֻ�ȡ���ܵ�;����	���飨study��
				ѧϰ��learn��
				���У�research��
				[1;31m��ϰ��practice��[0m
				
��ָ��������ϰĳ������ļ��ܣ���ϰʱ������Ǳ�ܣ�ֻ�ķ�һ����
���ľ�����ֵ��������ܱ����Ǿ��� enable ��רҵ���ܡ�

ÿһ����ϰ�ĵ��� = �������ܵȼ�*10 + 10

������ⷽ��Ļ������ܹ��ߣ����Ծ�����ϰֱ������������������
ֻ����������ܵĵȼ��йأ���Ȼ������֮ǰ������ʵ�������л�
���㹻�ľ�����������Ļ������ܡ�

����ֱ����������ߵȼ� = �������ܵȼ�/2/���⼼�ܵ�ϵ��

������

��1����ԯ���书ϵ�� = 2
�����Ļ�������Ϊ100����������ϰ��ԯ������100/2/2 = 25
��������ͻᷢ�ּ���Ϊ
[35m����ԯ���� (xuanyuan-axe)[0m     - ��ͨƤë  25/  677
��ʱ������Ҫ��ʦ������һ��Ǳ��ѧϰ����������

��2������������ϵ��Ϊ2.3��
�������100������������������ϰ������߼���Ϊ100/2/2.3 = 22

�������ᳫ���ٲ���Ҫ�Ļ����������������书����ϰ�Ѷȴ������
�������⼼���ڵȼ�100��ǰ���Ժܿ����ϰ�����ޣ�������100����
�������ܿ���ϰ��ߣ�����ʹ��ʵս�еõ���Ǳ������ʦ��ѧϰ����
���о���

������	learn  study  research

[0;1;37m����������������������������������������������������������������[0m   
TEXT
	);
    return 1;
}
