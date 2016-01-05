#include <ansi.h>
#include <combat.h>
inherit NPC;
void create()
{
	set_name("����", ({ "pet" }) );
	set("race", "Ұ��");
	set("age", 3);
	set("str",5);
	set("cor",5);
	set("int",5);
	set("spi",0);
	set("cps",5);
	set("per",5);
	set("con",5);
	set("agi",5);
	set("dur",5);
	set("fle",5);
	set("tol",5);
	set("no_fly",1);
	set("no_arrest",1);
	set("long", "һֻСССС���\n");
	set("owner","R");
	set("limbs", ({ "ͷ��", "����", "ǰ��", "�ᱳ", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );
        set("obedience",2);
	set("combat_exp",100);
	set("deathstamp",1);
        setup();
}
string query_save_file()
{
        string id;

        id = query("owner");
        if( !stringp(id) ) return 0;
        return sprintf(DATA_DIR "user/%c/%s/%s", id[0],id, id+".pet");
}

int save()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) ) {
                assure_file(file+ __SAVE_EXTENSION__);
                return save_object(file);
        }
        return 0;
}

int restore()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) )
                return restore_object(file);
        return 0;
}

void die()
{	
        int i;
        object owner, *enemy;
	int gin,kee,sen,exp;
	set("deathstamp",time());
	exp = (int) query("combat_exp");
	gin = (int) query("max_gin");
        kee = (int) query("max_kee");
        sen = (int) query("max_sen");
	if(!environment()->query("no_death_penalty"))
		set("combat_exp",exp/10 * 9);
	set("eff_kee",kee);
	set("eff_gin",gin);
	set("eff_sen",sen);
        set("kee",kee);
        set("gin",gin);
        set("sen",sen);
        if(objectp(owner=query("possessed")))
        {
                enemy = query_enemy();
        	i = sizeof(enemy);
        	while(i--) {
                	if( enemy[i] && living(enemy[i]) ) {
                        	owner->kill_ob(enemy[i]);
                        	enemy[i]->kill_ob(owner);
                }
        }

        }

	save();	
	::die();
}

int heal_up()
{
        if(!objectp(this_object()->query("possessed")))
	{
		save();
		message_vision("$Nһ���Ͳ����ˡ�\n",this_object());
	        destruct(this_object());
		return 1;
	}
	set_heart_beat(1);
        return ::heal_up() ;
}

void init()
{
	if(this_player() == query("possessed"))
	{
		add_action("do_order","order");
		add_action("do_modify","modify");
		add_action("do_gongji","gongji");
		add_action("do_teach","teach");
		add_action("do_shape","shape");
	}

}
int do_order(string arg)
{
	int obedience;
	object me = this_player();
	me->add("sen",-5);
	obedience = query("obedience") + me->query_skill("animal-talk", 1)/2;
	set_heart_beat(1);
	if(random(100) < obedience )
		command( "emote " + arg);
	else
		command("emote �ܲ���Ը�غ���һ����");
	return 1;
}
int do_modify(string arg)
{
	string item, msg;
        object me = this_player();
	if(!arg || sscanf(arg,"%s %s",item,msg) != 2)
	return notify_fail("SYNTAX: modify ���� ����\n");
	if(item == "flee")
	{
		set("env/wimpy", atoi(msg));
                write("�ϣ�\n");
		save();
		return 1;
	}

		
                if(CHINESE_D->check_control(msg))
                return notify_fail("���������п��Ʒ���\n");
                if(!CHINESE_D->check_chinese(msg))
                return notify_fail("�������������ģ�\n");
                if(CHINESE_D->check_space(msg))
                return notify_fail("�������費���ո�\n");
                if(CHINESE_D->check_return(msg))
                return notify_fail("�������費���س�����\n");
	me->add("sen",-10);
	switch(item)
	{
	case "desc":
		if(CHINESE_D->check_length(msg) > 100)
		return notify_fail("����̫����\n"); 
		set("long",msg+"\n");
		write("�ϣ�\n");
		save();
		return 1;
	case "nickname" :
		if(CHINESE_D->check_length(msg) > 20)
                return notify_fail("����̫����\n");
		set("nickname",msg);
		write("�ϣ�\n");
		save();
                return 1;
	case "title" :
                if(CHINESE_D->check_length(msg) > 10)
                return notify_fail("����̫����\n");
                set("title",msg);
                write("�ϣ�\n");
		save();
                return 1;
	case "arrive_msg" :
                if(CHINESE_D->check_length(msg) > 30)
                return notify_fail("����̫����\n");
                set("arrive_msg",msg);
                write("�ϣ�\n");
		save();
                return 1;
        case "leave_msg" :
                if(CHINESE_D->check_length(msg) > 30)
                return notify_fail("����̫����\n");
                set("leave_msg",msg);
                write("�ϣ�\n");
		save();
                return 1;

	}
	return notify_fail("��Ҫ�޸�ʲô��\n");

}


int do_gongji(string arg)
{
	object me,obj;
	me = this_player();
        if( environment(me)->query("no_fight") )
                return notify_fail("���ﲻ׼ս����\n");

        if( !arg )
                return notify_fail("����ɱ˭��\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("����û������ˡ�\n");

        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
	message_vision(
	sprintf("$N��$nһָ����%s����������ϣ���\n",this_object()->name()),me,obj);
        me->add("sen",-5);
	add("sen",-10);
        if(random(100) > query("obedience")+ me->query_skill("animal-talk", 1)/2 )
        command("emote �ܲ���Ը�غ���һ����");
	else {
		kill_ob(obj);
	}
	return 1;
	
}

int do_teach(string arg)
{
	object me;
	int gin_cost,amount;
        int myskill, itskill;
    	set_heart_beat(1);
	me = this_player();
	if(!myskill = me->query_skill(arg,1))
		return notify_fail("���������󻹲����أ�\n");
	if(arg != "unarmed" && arg != "move" && arg != "dodge")
		return notify_fail("��ѧ��������ܵģ�\n");
	itskill = query_skill(arg,1);
	if(myskill <= itskill)
		return notify_fail(name()+"�Գ�Ц��Ŀ�������㡣\n");
	if((int)me->query("potential")-(int)me->query("learned_points") < 1)
		return notify_fail("���Ǳ�ܲ�����\n");
	gin_cost = 100/ (int) query_int();
	if((int)me->query("gin") < gin_cost)
		return notify_fail("����Ȼ̫����û�а취�̣�\n");
	me->receive_damage("gin",gin_cost);
	me->add("potential",-1);
	amount = (int)me->query_int() * (int) query_int()/50;
	if (amount<1)	amount = 1;
	message_vision(sprintf("$N�����䷳�ؽ�$n��%s����\n",to_chinese(arg)),me,this_object());
        if(random(100) > query("obedience") + me->query_skill("animal-talk", 1)/4)
        command("emote �ܲ���Ը�غ���һ����");
	else 
	{
	        improve_skill(arg,amount);
		message_vision(sprintf("$N�ƺ����ѧ����һЩ��%s����\n",to_chinese(arg)),this_object());
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



int do_shape(string arg)
{	mapping my;
	string shape;
	int at_pt,pa_pt,do_pt;
	object owner;
	my = query_entire_dbase();
	owner=query("possessed");
	if (owner)
		printf("\n\t\t%s��%s  %s\n\n",owner->name(),my["title"],my["name"]);
	
	printf("����%s%3d/ %3d %s(%3d%%)\t"NOR"����%s%3d/ %3d %s(%3d%%)\t"NOR"��%s%3d/ %3d %s(%3d%%)\n"+NOR,
                status_color(my["gin"], my["eff_gin"]), my["gin"],my["eff_gin"],
                status_color(my["eff_gin"], my["max_gin"]),     my["eff_gin"] * 100 / my["max_gin"],
                status_color(my["kee"], my["eff_kee"]), my["kee"], my["eff_kee"],
                status_color(my["eff_kee"], my["max_kee"]),     my["eff_kee"] * 100 / my["max_kee"],
                status_color(my["sen"], my["eff_sen"]), my["sen"], my["eff_sen"],
                status_color(my["eff_sen"], my["max_sen"]),     my["eff_sen"] * 100 / my["max_sen"]
	);		
	printf("���ˣ� %s\t\t���飺 %d\t\tɱ���� %d\n",
		my["owner"], my["combat_exp"],my["bellicosity"]
		);
        printf("���ǣ� %d\t\t���ʣ� %d\t\t�ٶȣ� %d\n",
        	query_int(), query_con(),query_agi()
        	);
        printf("���ԣ� %d\t\t������ %d\t\t������ %d\n",
        	query_cor(), query_str(),query_dur()
        	);        
	at_pt=COMBAT_D->skill_power(this_object(), SKILL_USAGE_ATTACK);
	pa_pt=COMBAT_D->skill_power(this_object(), SKILL_USAGE_PARRY);
	do_pt=COMBAT_D->skill_power(this_object(), SKILL_USAGE_DODGE);
        printf("�������� %d\t\t\t\t�������� %d\n",
        	at_pt+1, pa_pt/2+do_pt/2+1
        	);
        printf("�����̶ȣ�%d\n\n",my["obedience"]
        	+((objectp(owner))?owner->query_skill("animal-talk")/2: 0));
	printf("/cmds/usr/skills"->pet_skill(this_object()));
	return 1;
}



void unconcious()
{
die();
}

