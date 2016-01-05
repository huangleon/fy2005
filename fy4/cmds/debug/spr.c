
#include <skill.h>
inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
    	int gin_cost,my_skill, limit;
    	int pot, amount;
    	string skill, check, myclass;
    	mapping level;
    	
    	if( me->is_fighting() )
        	return notify_fail("��ս���и��о���\n");
    	
    	if (!arg)
    		return notify_fail("ָ���ʽ: research <����> with <Ǳ�ܵ���>\n");
    	
    	if( sscanf(arg, "%s with %d", skill, pot)!=2 ) {
    	 	if (sscanf(arg, "%s with %s", skill, check) == 2)
    	 	if ( check == "limit") {
    	 		if( !(int)my_skill=me->query_skill(skill,1) )
        			return notify_fail("��Դ����һ����֪����θ��о���\n");
    	 		
    	 		myclass = me->query("class");
    	 		me->set("class",SKILL_D(skill)->skill_class());
    	 		limit = 450 * 100 / SKILL_D(skill)->effective_level();
    			limit = (limit /5 + 1) * 5;
    			if (myclass)	me->set("class",myclass);
    				else	me->delete("class");
    				
    			tell_object( me, "������ܹ����е�����ߵȼ�Ϊ"+ limit +"��\n");
    			return 1;
    		}
    	 	return notify_fail("ָ���ʽ: research <����> with <Ǳ�ܵ���>\n");
    	}
    	
    	if( !(int)my_skill=me->query_skill(skill,1) )
        	return notify_fail("��Դ����һ����֪����θ��о���\n");
    
    	if( !SKILL_D(skill)->valid_learn(me)) return 0;
    
    	myclass = me->query("class");
    	 	me->set("class",SKILL_D(skill)->skill_class());
    	limit = 450 * 100 / SKILL_D(skill)->effective_level();
    	limit = (limit /5 + 1) * 5;
    	if (myclass)	me->set("class",myclass);
    		else	me->delete("class");
    	
    	if (my_skill >= limit )
    		return notify_fail("��Ȼ��������У��������������������Ѿ��޷���һ�����������ˡ�\n");
    	
    	if (pot <100)
    		 return notify_fail("���Ǳ�ܲ����������о�����������100�㣩\n");
    
    	if (pot > (int)me->query("potential") - (int) me->query("learned_points"))
    		 return notify_fail("���Ǳ�ܵ㲻����\n");
    	
    	gin_cost = 10000 * 3 / ((int)me->query_int()*(int)me->query_kar());
    	if((int)me->query("gin") < gin_cost)
    	{
		me->set("gin",0);
		return notify_fail("������̫���ˣ����ʲ��Ҳû���о�������\n");
    	}
    	   	

            	if (me->query_int()<= 40)
            	       	amount = 200 + me->query_int() * me->query_int();                		
            	else
            		amount = 200 + 1600 + (me->query_int()-40) * 20;
            		
            	if (me->query("national")=="����")	
            		amount = amount * 105/100;	// ��������
            	   	
            	amount = amount * pot * 2 / SKILL_D(skill)->skill_difficulty();
            	
	//	����ʵ���Ͼ���ֱ��ѧϰ����ܵ�Ч�ʣ������о���˵��/10
	amount = amount /10;	            	
    	write(sprintf("%d\n",amount));
    	
    	write("���"+SKILL_D(skill)->name()+"����һ�����׵��о���\n");
    	me->add("learned_points",pot);
    	me->receive_damage("gin", gin_cost );  	
    	me->research_skill(skill,amount);
    	
    	return 1;
}
            	
            	
int help(object me)
{
    write( @HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	research <����> with <Ǳ�ܵ���>[0m
[0;1;37m����������������������������������������������������������������[0m   

�����й������ֻ�ȡ���ܵ�;����	���飨study��
				ѧϰ��learn��
				[1;31m���У�research��[0m
				��ϰ��practice��

����ɳ���һ���̶ȣ��ᷢ���Լ��Ѿ�ѧ��������ʦ���ܴ��ڵļ��ܣ�
��Ȼ����Ȼ���Ա������أ�Ѱ���µ�ʦ�������书�ؼ������������㹻
�Ķ�����ѧ������һ���棬��Ҳ���������Լ��Ĳ�������������ѧ���
�����һ�����С�������һ����������ͷ�Ծ�Ĺ��̣��Ѷ�Ҫ����ʦ��
ѧҪ��ö࣬����Ψ������������ܳ�Խǰ�ˣ���Ϊһ����ʦ��

��һָ��������ָ����Ǳ�ܶ�ĳ�����������о���
һ����˵���о����Ѷ���ͬ����ʦ���Ƕ�ѧϰ�����10����
���ѵ��ǣ�������Ҫ�����ĵ�����ѧϰ��������

������
������������ (diesword)                  - ��ͨƤë  22/  530
�������ʦ��ѧ����һ��Ǳ����������Ϊ 23����
��������Լ����У���Ҫ��Ϊ
������������ (diesword)                  - ��ͨƤë  22/  1060
���������23����

���е�Ч��������������أ�
��1�����ǣ�Խ�������ˣ���ͬ����Ǳ�����򵽵ļ��ܾͶࡣ
��2���������ࣺ��ͬ���书�����ѶȲ�ͬ�������׵��Ǵ�����Ĺ���
��3���������ԣ����������Ч�ʱȽϸߡ�

���еľ��ޣ��������֮ʱ������ļ��ܴﵽһ������ʱ��
�����ܵȼ�xϵ��>= 450)
����������Ե���⿿���˵����о��޷���һ������ˡ�
ʹ������ Research <����> with limit ���Բ鿴����ӵ�м��ܿɴﵽ
�����ȼ���

[0;1;37m����������������������������������������������������������������[0m   
HELP
   );
    return 1;
}

