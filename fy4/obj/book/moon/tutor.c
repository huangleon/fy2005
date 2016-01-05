// ���ĵ�Ϊ6.28.2003�汾��fycycle tutor.

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("��֪ѧϰ����", ({ "tutor" }));
	set_weight(6000000);
	if( clonep() )
			set_default_object(__FILE__);
	else {
	set("unit", "��");
	set("long",
			"һ��ѧϰ���壬���ƺ����Դ�������ѧ��ʲô��\n��ϸ��֮�£�����������������Ǹ�������\n");
	set("value", 0);
	set("no_drop", 1);
	set("no_get", 1);
	set("no_sell", 1);
	set("teaching", "nonsense");
	set("teaching_limit", 400);
	set("material", "paper");
	}
}

void init()
{
   	add_action("do_learn","learn");
}
    
int do_learn(string arg)
{
    	string skill, teacher, master, teaching;
    	object me, ob, *list;
    	int my_skill, gin_cost, max_skill, required;
    	string target, cardname, my_class;
    	int i;
    	int amount=0, pot;
    
    	if(!arg || sscanf(arg, "%s from %s with %d", skill, teacher, pot)!=3 )
        	return notify_fail("ָ���ʽ��learn <����> from <ĳ��> with <Ǳ�ܵ�>\n");
    
    	me = this_player();
    	if( me->is_fighting() )
        	return 0;
    
    	if( !(ob = present(teacher, me)) )
        	return 0;

    	if ( pot <=0 )
        	return 0;
    
// Start learning from tutor
    	teaching = (string) query("teaching");
    	my_class = me->query("class");
    	if( skill != teaching )  {
        	write("���������±����ұ���ѧ�ˡ�\n");
        	return 1;
        }

    	my_skill = (int) me->query_skill(skill, 1);

    	max_skill = (int) query("teaching_limit");
    	if( my_skill >= max_skill ) {
        	write("�������ĳ̶��Ѿ��������ϵļ��ص��ˡ�\n");
        	return 1;
    	}
  
    	required = query("teaching_require");
    		
    	if (my_skill < required ) {
        	write("����Ŀǰ��������û�а취ѧϰ���ּ��ܣ���"+required+"����\n");
        	return 1;
    	}		
    
       	if( (int)me->query("potential") - (int)me->query("learned_points") < pot )   	{ 
    		write("���Ǳ���Ѿ����ӵ������ˣ�û�а취�ٳɳ��ˡ�\n");
      		return 1;
    	}

    	tell_object(me,"����"+ob->name()+"���Ķ��йء�"+ SKILL_D(skill)->name() +"����ѶϢ��\n");

    	if((my_skill * my_skill * my_skill)/10  >(int)me->query("combat_exp") ) {
            	printf("Ҳ������Ϊȱ�����飬���%s�ϵ����������޷���ᡣ\n", ob->name() );
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
				a_amount = (400+30* me->query_int()) *2 * 100;
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

	          	printf("�㿴��%s���������ƺ���Щ�ĵá�\n",ob->name());
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
			write("learning efficiency is: 1 point Ǳ�� == " + amount + "\n");
		}
// DEBUG off
            	            	
            	me->improve_skill(skill,amount);
        }
    	
    	return 1;
}
    
    