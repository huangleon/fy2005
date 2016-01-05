inherit ITEM;
//inherit __DIR__"tutor";
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
                set("no_get", 1);
		set("no_shown", 1);
		set("teaching", "nonsense");
		set("teaching_limit", 400);
                set("material", "steel");
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
    
    	if( !(ob = present(teacher, environment(me))) )
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
        	write("�������ĳ̶��Ѿ�������ʦ���ˡ�\n");
        	return 1;
    	}

    
    	required = 200;
    	if ( teaching == "sword" && my_class =="taoist") required = 120;
    	if ( teaching == "spear" && my_class =="official") required = 120;
    	if ( teaching == "xingyi-stick") required = 0;
    	if ( teaching == "tigerstrike") required = 0;
    		
    	if (my_skill < required ) {
        	write("����Ŀǰ��������û�а취ѧϰ���ּ��ܡ�\n");
        	return 1;
    	}		
    
    	gin_cost = 100 / ( 10 + (int)me->query_int());

    	gin_cost *= pot;
    	gin_cost = gin_cost/2;

    	if( (int)me->query("potential") - (int)me->query("learned_points") < pot )   	{ 
    		write("���Ǳ���Ѿ����ӵ������ˣ�û�а취�ٳɳ��ˡ�\n");
      		return 1;
    	}

    	tell_object(me,"����"+ob->name()+"����йء�"+ SKILL_D(skill)->name() +"�������ʡ�\n");

    	if( (int)me->query("gin") > gin_cost ) {
        if((my_skill * my_skill * my_skill)/10  >(int)me->query("combat_exp") ) {
            	printf("Ҳ������Ϊȱ�����飬���%s�Ļش������޷���ᡣ\n", ob->name() );
        } else {
            	printf("������%s��ָ�����ƺ���Щ�ĵá�\n",ob->name());
            	me->add("learned_points", pot);
            	amount = (my_skill - 75) * SKILL_D(skill)->black_white_ness()/100;
            	if((amount < -50) && (my_skill < 75)) amount = -50;

            	amount += SKILL_D(skill)->learn_bonus() +
                	(int)me->query_int() * (int)me->query_int() +
                	to_int(pow(to_float((int)me->query("combat_exp")),0.3));

            	amount = amount/50 + random(amount/50);
            	if (me->query("national")!="����")
			amount = amount *97/100;
	    	if ((int) me->query_skill(skill, 1)>320)    amount = amount*2/3;
	    	if ((int) me->query_skill(skill, 1)>350)    amount = amount/3;		
            	if( amount < 2) amount = 2;	
            	amount *= pot;
            	me->improve_skill(skill,amount);
        }
    	} else {
        	gin_cost = me->query("gin");
        	write("�����̫���ˣ����ʲ��Ҳû��ѧ����\n");
    	}
    
    	me->receive_damage("gin", gin_cost );
    
    	return 1;
}
    