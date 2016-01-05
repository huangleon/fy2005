// hell_guard.c

#include <ansi.h>

inherit NPC;
void backattack();
void create()
{
	set_name(YEL"�������"NOR, ({ "sq-taoist"}) );
	set("long", "һλ���ߣ�������ڣ������ư����£������������һ��ִ��֥���⡣\n");
	set("attitude", "friendly");
	set("no_fly",1);
	set("no_arrest",1);
	
	set("combat_exp", 100000);
	
	set_skill("sword", 90);
	set_skill("parry", 70);
	set_skill("dodge", 50);
	set_skill("move", 70);
	set_skill("three-sword",70);
	set_skill("notracesnow",70);
	map_skill("dodge","notracesnow");
	map_skill("sword","three-sword");
	map_skill("parry","three-sword");
	setup();

	carry_object("/obj/armor/armor",
    		([	"name"	:	HIY"���ư�����"NOR,
    			"value"	:	0,
			"armor_prop/armor"	: 20 ])
    		)->wear();
	carry_object("/obj/weapon/sword",
		([	"name"	:	"��֥����",
    			"value"	:	0,	])
		)->wield();
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object owner,*pros;
	if (environment())
	message("vision",CYN"������˻���һ��������ʧ�ˡ�\n" NOR, environment(),this_object() );
        if(objectp(owner=this_object()->query("possessed")))
        {
                owner->add_temp("max_guard",-1);
                owner->add_temp("sanqing/sq2",-1);
                pros = owner->query_temp("protectors");
			pros -= ({ this_object() });
		owner->set_temp("protectors",pros);
	}
	// Remove all buffs to clean up annied
	ANNIE_D->debuff(this_object(),"all");                
	                
	destruct(this_object());
}

void invocation(object who, int level)
{
	int i, bonus_skill;
	object *enemy,*pros;

	set("str",10+level/16+random(level/16));
	set("agi",10+random(level/12));
	set("cor",15+random(level/12));
	
	set("max_kee",300+random(level*level/60));
	set("eff_kee",query("max_kee"));
	set("kee",query("max_kee"));
	set("max_gin",query("max_kee")/2);
	set("gin",query("max_kee")/2);
	set("eff_gin",query("max_kee")/2);
	set("max_sen",query("max_kee")/2);
	set("eff_sen",query("max_kee")/2);
	set("sen",query("max_kee")/2);
	
	set("max_force",300+random(level*level/200));
	set("force",query("max_force"));

	
	bonus_skill = 50 + level/4 + random(level/4);
	set_skill("sword", 50 + level/4 + random(level/4));
	set_skill("parry", 50 + level/4 + random(level/4));
	set_skill("dodge", 50 + level/4 + random(level/4));
	set_skill("move", 50 + level/4 + random(level/4));
	set_skill("notracesnow",20 + level/4 + random(level/4));
	set_skill("three-sword",30 + level/4 + random(level/4));
	
	set("combat_exp", 20000 + level/8*level*level/2+random(level/8*level*level/2)); 
	

	pros = who->query_temp("protectors");
	if(sizeof(pros))
		pros += ({ this_object() });
	else
		pros = ({ this_object() });
	who->set_temp("protectors",pros);
	
    	message_vision(YEL"
ֻ�����������������죬����һλ���ߣ�������ڣ������ư����£��������
����һ��ִ��֥���⣬���Ի������λ���֣��������㹲����������
˵��������
    ���س��������أ�һͳ���������š�
    ���屾ͬ����ϣ�����ɽ���Ի��档	�������������Ҳ��\n"NOR,this_object());
    					
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
		}
	}
	set_leader(who);
	set("possessed",who);
}


void unconcious() {
	die();
}

void die()
{
	object *pros,owner;
        if(objectp(owner=this_object()->query("possessed")))
        {
                owner->add_temp("max_guard",-1);
                owner->add_temp("sanqing/sq2",-1);
                pros = owner->query_temp("protectors");
			pros -= ({ this_object() });
		owner->set_temp("protectors",pros);
	}                
	message("vision",MAG"������˻���һ��������ʧ�ˡ�\n" NOR, environment(),this_object() );
	destruct(this_object());
}


void heart_beat()
{
	object leader;
	
	::heart_beat();
        if(!this_object()) 		return;
	
	if(query_temp("is_unconcious")||is_busy())
		return ;
	if(query("possessed"))
	{
		leader=query("possessed");
		if(objectp(leader) && environment(leader)!=environment()&&(!leader->is_ghost()))
		{
			message_vision("$N�Ҵ���ȥ��\n",this_object());
			this_object()->move(environment(leader));
			message_vision("$N���˹�����\n",this_object());
			delete("leave_room");
		}
	}
	
	else
	{
		if(!query("leave_room"))
			set("leave_room",1);
		else
			add("leave_room",1);
		if(query("leave_room")==5)
			leave();
	}
}

