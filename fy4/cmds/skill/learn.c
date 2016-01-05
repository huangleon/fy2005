// learn.c
/*	-- Modified by Silencer for FY4.1

(1)	Using Difficulty instead of learn_bonus to describe skill learning.
(2)	Removed Randomness in learning .

*/

#include <skill.h>
#include <ansi.h>

inherit F_CLEAN_UP;

string *reject_msg = ({
        "˵������̫�����ˣ�������ҵ���\n",
        "�����ܳ�����һ����˵������̣�������ҵ���\n",
        "Ц��˵��������Ц�ˣ��������С�������ʸ�ָ�㡹��ʲ�᣿\n",
});

int couple_learn(object me, object couple, string skill);
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
    	string skill, teacher, master;
    	string target, cardname;
    	object ob, *list, marry_card;
    	int master_skill, my_skill, gin_cost;
    	int i,marry_flag, level;
    	int amount=0, pot;
    	
		string *att_skill = ({ "literate", "unarmed", "force", 
							"foreknowledge", "chanting", "move" });

    	if(!arg || sscanf(arg, "%s from %s with %d", skill, teacher, pot)!=3 )
        	return notify_fail("ָ���ʽ��learn <����> from <ĳ��> with <Ǳ�ܵ�>\n");

    	if( me->is_fighting() )
        	return notify_fail("����ĥǹ������������\n");
    
    	if( !(ob = present(teacher, environment(me))) || !ob->is_character())
        	return notify_fail("��Ҫ��˭��̣�\n");
    
    	if( !living(ob) )
        	return notify_fail("��....����Ȱ�" + ob->name() + "Ū����˵��\n");
    	if ( pot <=0 )
        	return notify_fail("Ǳ�ܵ�������һ��\n");
		
		if (userp(ob))
        	return notify_fail("����ͬ������֮�±ȱȽ��ǣ�����\n���ǲ�Ҫָ��������ѧ��ʲô�˰ա�\n");
        	
    	target = (string)me->query("marry");
    
    	if( !me->is_apprentice_of(ob) && !me->is_couple_of(ob)){
	        // 	Basically, if you are not his apprentice, you can't learn  
	        //   from NPC unless he returns   recognize_apprentice = 1
	        if( !(ob->recognize_apprentice(me)) && ob->query("race") == "����") {
	            return notify_fail( ob ->name() + 
					reject_msg[random(sizeof(reject_msg))] );
			} else if(ob->query("race") != "����"){
				return notify_fail(ob->name() + "��Ȼ��������Ļ���\n");
			}
		}
// until here we deicde that me can learn from ob!
   	
    	if(!me->is_couple_of(ob)){ 
    		// Prevent_learn can be either from inheritance from F_MASTER
    		// Or a function in npc files. it allows you to set individual skills.
    		// But, if you override it to in a F_MASTER to play tricks 
    		// 		it will override the betrayal in F_MASTER
    		if(ob->prevent_learn(me, skill)) 
        	return notify_fail(ob->name() + "��Ը���������ܡ�\n");
    	}
    	
    	if( ob->is_couple_of(me) )    		
//		if( couple_learn(me,ob,skill))
            	return notify_fail(ob->name() + "��Ը���������ܡ�\n");
    
    	if( !master_skill = ob->query_skill(skill,1) )
        	return notify_fail("���������±����ұ���ѧ�ˡ�\n");

    	my_skill = me->query_skill(skill, 1);
    	if( my_skill >= master_skill )
        	return notify_fail("�������ĳ̶��Ѿ���������ʦ���ˡ�\n");
    	
    	// ���������������Ӧ�Ļ���������ѧϰʱϵ����1.5���㡣
    	if ( member_array(skill, att_skill) == -1)
    		my_skill = my_skill * SKILL_D(skill)->effective_level(me)/100;
    	else
    		my_skill = my_skill * 150 /100;
    
    	notify_fail("����Ŀǰ��������û�а취ѧϰ���ּ��ܡ�\n");
    	if( !SKILL_D(skill)->valid_learn(me) )  return 0;

//	casue problem under query-skill-eff-lvl
    	if( (int)me->query_skill(skill,1) == 0 ) {
        	me->set_skill(skill,0);
    	}

    	if(pot >10000)	
    		return notify_fail("Ϊ��ֹ�����ÿ��ѧϰ��Ǳ�ܵ㲻�ܳ��������������㡣\n");
    	
    	if( (int)me->query("potential") - (int)me->query("learned_points") < pot )
        	return notify_fail("��û����ô���Ǳ�ܡ�\n");

    	if (me->query("gin")< 10)
    		return notify_fail("��ľ�����������������Ϣ��Ϣ�ɡ�\n");
    	
    	tell_object(me,"����"+ob->name()+"����йء�"+ SKILL_D(skill)->name() +"�������ʡ�\n");
    
    	if( ob->query("env/no_teach") )
        	return notify_fail("����" + ob->name() +"���ڲ���׼���ش�������⡣\n");
    
    	tell_object(ob, sprintf("%s��������йء�%s�������⡣\n",me->name(), SKILL_D(skill)->name()));
    	    	
		if((my_skill * my_skill * my_skill)/10  > (int)me->query("combat_exp") ) {
            	printf("Ҳ������Ϊȱ�����飬���%s�Ļش������޷���ᡣ\n", ob->name() );
        } else {

// WARNING ON	Seperated set of variables so it won't mess up with the old thing =============

			mapping learned_skill_points;
			int leftover, j, a_cost,a_amount, a_total;
						
			learned_skill_points=me->query_learned();
			if (mapp(learned_skill_points))
				leftover = learned_skill_points[skill];
			else
				leftover = 0;
			j = me->query_skill(skill,1);
			
			if (me->query_int()<=40)
				a_amount = (400+30*me->query_int())*2*100;
			else
				a_amount = to_int((pow(to_float(me->query_int()*10),0.03)*871-950)*173/5*100) ;
			
	        if (me->query("national")=="����")	
	        	a_amount = a_amount + a_amount/20;	// ��������      	            	    	
	        a_amount = a_amount / SKILL_D(skill)->skill_difficulty();        	                 	
	       	if( a_amount < 1) a_amount = 1;		// ����1��1 
	       	          
	        a_total = (j+1)*(j+1)+1 - leftover;
	        a_cost = a_total*100/a_amount+1;
			
			if (a_cost < 0)
				a_cost = 1;
				
			if (a_cost < pot) { 
				tell_object(me, HIR"�����Ѻ���ʾ�����������Ǳ������"+pot+"�������������裨"+a_cost+"���㣡\n"NOR);
				tell_object(me,HIR"ϵͳ�Զ���������Ǳ����Ϊ"+a_cost+"�㡣\n"NOR);
				pot = a_cost;
			}
			
// WARNING OFF =================================================================================

            	printf("������%s��ָ�����ƺ���Щ�ĵá�\n", ob->name());
            	
            	me->add("learned_points", pot); 
				me->add("annie/skill_cost/"+skill,pot);
    	         
    	        if (me->query_int()<=40)
    	        	amount = (400+30* me->query_int()) *2 * pot;
    	        else
    	        	amount = to_int((pow(to_float(me->query_int()*10),0.03)*871-950)*173/5*pot) ;
                       		
            	if (me->query("national")=="����")	
            		amount = amount + amount/20;	// ��������
            	            	    	
            	amount = amount / SKILL_D(skill)->skill_difficulty();
            	            	           	                 	
            	if( amount < 1) amount = 1;		// ����1��1            	

// DEBUG on
		if (wizardp(me) && me->query("env/debug")) {
			write("skill difficulty is "+ SKILL_D(skill)->skill_difficulty() + "\n");
			write("learning efficiency is: 1 point Ǳ�� == " + amount/pot + "\n");
		}
// DEBUG off

            	me->improve_skill(skill,amount);
        }
	return 1;
}


int help(object me)
{
    write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	learn <����> from <ĳ��> with <Ǳ�ܵ�>[0m
[0;1;37m����������������������������������������������������������������[0m   

�����й������ֻ�ȡ���ܵ�;����	���飨study��
				[1;31mѧϰ��learn��[0m
				���У�research��
				��ϰ��practice��

���ָ������������������й�ĳһ�ּ��ܵ��������⣬��Ȼ������
�̵Ķ�����������ϵ�����������ߣ����㾭�����ַ�ʽѧϰ����
�ļ���Ҳ�����ܸ��������̵��ˣ�Ȼ����Ϊ����ѧϰ��ʽ�൱�һ��
����Ĵ��У����ѧϰ����˵����Ϥһ���¼������ķ�����

ͨ����һ���˸�ѧ��һ���¼����ǲ�����ʲ����������ģ����Ǿ���ʵ
���ϵ�Ӧ�����������⣬��Щ������ѧϰһ���¼��ܵĹ����Ǻ���Ҫ
�ģ������Ǹ�����Ϊ�������ܻ����Ļ������ܣ�����Ҫ���ɡ���������
��������⡹�Ĺ��̲��ܵõ��Ϻõ�Ч��������ǽ����ַ�������Ĺ�
���á�Ǳ�ܡ��Ĺ����ʾ��һ�����ܹ��Լ�����ĳЩ���⣬��ʾ��(��)
�н�����������Ǳ�ܣ��������������Ǳ��ʱ�Ϳ����������ָ����
����������̣�����ý�����

FY2005��ѧϰ�������ľ�����

������֪�����ܴӶԷ�ѧ��ʲ�Ἴ�ܣ�����Է������ʦ����������
 skills ָ��ֱ�Ӳ鿴��

ÿN��Ǳ�ܶ�Ӧ�ļ������Ӷ�Ӧ�ľ��幫ʽΪ��
��1�����ǡ�=40ʱ��
	= N *��400 + 30*���ǣ�*2 /ѧϰ�Ѷ� 
��2�����ǡ�40ʱ�� 
	= N*((��int*10��^0.03)*871-950)*173/5/ѧϰ�Ѷ�

��ѧ����ֵ�ڼ�������һ��ȡ����
�󲿷ּ��ܵ�ѧϰ�Ѷ��ڣ���������������

ѧϰ��Ч��������������أ�
��1���������ࣺ��ͬ���书ѧϰ�ѶȲ�ͬ������skills����쿴��
��2���������ԣ������ѧϰЧ�ʱȽϸߣ����湫ʽ��+5%��

ѧϰ���ܵ����ƣ�
��1��û��ʦ��ϲ�����Ķ��⡢����ĺ�صĵ��ӣ���ÿ��ʦһ�Σ���һ��
ʦ��Ը�����ļ��ܵȼ��ͻ���ٶ�ʮ����ͬʱ��ʦ��ר�е��书����
�����������������ʦ��Ҳ��û���ˡ�

����������
�����ѧϰ����������һ����ƽ����һʱ������
Ҳ����˵�������ļ��ܵȼ�Ϊn����ѧϰ������ע�⣬����Ǳ�ܵ�����
����(n+1)*(n+1)+1ʱ������

����
������������ (diesword)                  - ��ͨƤë  22/  530
�˵� 530 = 23*23 + 1�� �����ٻ���һ��Ǳ��ѧϰʱ������Ϊ
������������ (diesword)                  - ��ͨƤë  23/  0

** ����������Զ�Ӧ����ؼ��ܣ�����ʶ�֡��о����˻��񶷡�����
�Ṧ��ռ��ѧ�������ڹ�����ѧϰ��ʱ��ϵ������Ϊ150��

�������ָ�� : practice��study��research

[0;1;37m����������������������������������������������������������������[0m   
HELP
        );
    return 1;
}


int couple_learn(object me, object couple, string skill)
{
	int i, div,div1,mylvl, herlvl, ratio=0;
	if(!userp(couple)) return 0;
	mylvl = me->query_skill(skill,1);
	herlvl = couple->query_skill(skill,1);
	div = (int) me->query("divorced");
	div1 = (int) couple->query("divorced");
	for(i=1; i<=div1; i++) 
		ratio+=25;
	if(div1&&(mylvl>=herlvl-ratio)){
		message_vision("$N����$n��ǰ�����£���Ȼ��������ܲ������һʱɥʧ��ѧϰ����Ȥ��\n",me,couple);
		return 1;
	}
	if(div&& (mylvl >= herlvl / 2) ){
		message_vision("$N��ɫ���ƺ���$n����ʮ�����Σ�Ҳ��������$p��ǰ��������...��\n", couple, me );	
		return 1;	
	}
	return 0;
}
