// Not enabled in game .. Silencer@fengyun workgroup	June.2005
				
#include <ansi.h>
inherit ITEM;

string description();

void create()
{
        set_name("��������", ({ "draft" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",(: description() :));
                set("value", 1000);
                set("no_get", 1);
                set("no_drop",1);
                set("no_sell",1);
		set("teaching", "advanced-parry");
		set("teaching_limit", 150);
		set("required_exp", 3000000);
                set("material", "paper");
        }
}

string description() {
	string msg,required ;
	
	required = query("required_class") ? F_MASTER->query_chinese_class(query("required_class"))+"���ӣ�"
			: "";
	required += query("required_level") ? " "+(string)(query("required_level"))+"��ͬ���书" 
			: "";		
	
	msg = YEL"һ�����Ƶı��ᣬ��Ȼ�Ѿ�����ͷ�ˣ���ҳ��Ȼ�������\n"NOR;
	msg += sprintf(WHT"�书�ؼ���\t\t%s��%s��\n"
			 "�ȼ���    \t\t%d��\n"
			 "ѧϰ������\t\t\%s\n"
			 "���⹦�ã�\t\t%s\n"NOR,
			query("name"),query("teaching"),
			query("teaching_limit"),
			required,
			query("perform_name")
			);
	
	return msg;
}

/*

int query_autoload() { return 1; }

void init()
{
   	add_action("do_master","master");
}
    
int do_master(string arg)
{
    	string skill, teacher, master, teaching;
    	object me, ob, *list;
    	int my_skill, gin_cost, max_skill, required_exp;
    	string target, cardname, my_class;
    	int i;
    	int amount=0, pot;
    
    	if(!arg || sscanf(arg, "%s from %s with %d", skill, teacher, pot)!=3 ) {
        	write("ָ���ʽ��master "+query("teaching")+" from book with <Ǳ�ܵ�>\n");
        	write("����ʱЯ�����书�ؼ����ܳ���һ����\n");
        	return 1;
        }
        
    	me = this_player();
    	
    	if( !(ob = present(teacher, me)) )
	        return 0;

    	if ( pot <=0 )
        	return 1;
    
    	if( me->is_fighting() ) {
    		write("ս���в��������ܡ�\n");
        	return 1;
    	}
    	
// Start learning from tutor
    	teaching = (string) query("teaching");
    	my_class = me->query("class");
    	
    	if( skill != teaching )  {
        	write("���޷����Ȿ������������ܡ�\n");
        	return 1;
        }

    	my_skill = (int) me->query_skill(skill, 1);
    	max_skill = (int) query("teaching_limit");
    	if( my_skill >= max_skill ) {
        	write("���Ѿ������������Ȿ���ϵ��书��������ֻ�п��Լ������ˡ�\n");
        	return 1;
    	}

	if (query("required_class"))
    	if (my_class != query("required_class")) {
    		write("��δ���ո����ɵ��书���޷�����"+SKILL_D(skill)->name()+"��\n");
    		return 1;
    	}
   	
   	if (query("required_level"))
   	if (my_skill < query("required_level")) {
   		write("���"+SKILL_D(skill)->name()+"��򲻹����޷���һ�����򡣣���"+query("required_level")+"����\n");
   		return 1;
   	}
   	
    	required_exp = query("required_exp");
    	if (me->query("combat_exp") < required_exp )	{
        	write("���ʵս����̫��޷���������еĸ����书��\n");
        	return 1;
    	}		
    
    	gin_cost = 100 / ( 10 + (int)me->query_int());
    	gin_cost *= pot;
    	gin_cost = gin_cost/2;

    	if( (int)me->query("potential") - (int)me->query("learned_points") < pot )    { 
    		write("���Ǳ���Ѿ����ӵ����ޣ�û�а취�ټ��������ˡ�\n");
      		return 1;
    	}

    	tell_object(me,"����鱾����ʼǱ��˼����"+SKILL_D(skill)->name() +"���Ĺؼ����ڡ�\n");

    	if( (int)me->query("gin") > gin_cost ) {
        	if((my_skill * my_skill * my_skill)/10  > (int)me->query("combat_exp") ) {
            		printf("����˼������Ҳ������Ϊȱ��ʵս���飬�����ڹؼ�֮���������ԡ�\n", ob->name() );
        	} else {
            		printf("���������е�ָ��ϸϸ��ĥ���ƺ���Щ�ĵá�\n");
            		me->add("learned_points", pot);
	            	amount = (my_skill - 75) * SKILL_D(skill)->black_white_ness()/100;
	            	if((amount < -50) && (my_skill < 75)) amount = -50;
	            	amount += SKILL_D(skill)->learn_bonus() +
	                	(int)me->query_int() * (int)me->query_int() +
	                	to_int(pow(to_float((int)me->query("combat_exp")),0.3));
		        amount = amount/50 + random(amount/50);
		    	if ((int) me->query_skill(skill, 1)>320)    amount = amount*2/3;
		    	if ((int) me->query_skill(skill, 1)>350)    amount = amount/3;		
	            	if( amount < 2) amount = 2;	
	            	amount *= pot;
	            	me->improve_skill(skill,amount);
        	}
    	} else {
        	gin_cost = me->query("gin");
        	write("�����̫���ˣ����ʲ��Ҳû�������������\n");
    	}
    
    	me->receive_damage("gin", gin_cost);
    
    	return 1;
}
*/    