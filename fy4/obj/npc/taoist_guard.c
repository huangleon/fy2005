// hell_guard.c

#include <ansi.h>

inherit NPC;

void backattack();
void smart_fight();

string *poet = ({
"�����������������ף�Ψ������ͬ���١�
����˫���߷������ˣ�һ�絣���Ž�",
"����������ʥ�����ɣ�ͨ���ŵ���ͨ�͡�
�������������ò�����ͳϽ�������졣",
"�����׷���ǧ����̬����Ǳ����ݲ�񷡣
��������Թ�����գ�����һ��Ц��ӹ��",
"����������ؾ����ģ�����Ⱦ�������֡�
�����������˳���⣬������ɴ�����顣",
"�����Ѷ��׷׼����꣬ǧħ���������졣
��������ּ��������������Ϸ����ߡ�"});

void create()
{
	string *order = ({YEL"����",MAG"̫��",WHT"����"});

	set_name((order[random(3)]) + "����"NOR, ({ "sanqing taoist" }) );
	set("long", "�����������������������\n");
	set("attitude", "friendly");
	set("no_fly",1);
	set("no_arrest",1);
	
	set("combat_exp", 100000);
	set("chat_msg_combat", ({
        	 (: smart_fight() :),

	}) );

	set_skill("fork", 90);
	set_skill("parry", 70);
	set_skill("dodge", 50);
	set_skill("move", 70);
	set_skill("hunting-fork",70);
	set_skill("notracesnow",70);
	map_skill("dodge","notracesnow");
	map_skill("fork","hunting-fork");
	map_skill("parry","hunting-fork");
	setup();

	carry_object(__DIR__"obj/golden_armor",
    		([	"name"	:	CYN"�ɼҵ���"NOR,
			"id":"cloth",
    			"value"	:	0,
				"long"	: "",
			"armor_prop/armor"	: 20, ])
    		)->wear();

	carry_object(__DIR__"obj/golden_sword",
			([	"name"	:	WHT"�������"NOR,
				"id"	: "fuchen",
				"long"	: "",
    				"value"	:	0,	])
		)->wield();
}



int heal_up()
{
	if( environment() && !is_fighting() && !query("is_leaving")) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object owner,*pros;
	if (environment())
	message("vision",
		HIY + name() + "����һ��������ʧ�ˡ�\n\n" NOR, environment(),		this_object() );
    if(objectp(owner=this_object()->query("possessed")))
    {
            if (owner->query_temp("max_guard")>0)
            	owner->add_temp("max_guard",-1);
	}
	// Remove all buffs to clean up annied
	ANNIE_D->debuff(this_object(),"all");                
	destruct(this_object());
}

void init()
{
        ::init();
        add_action("do_dismiss","dismiss");	
}  

int do_dismiss(string arg)
{
        object who,obj;
        if(!arg) return 0;
        if(!obj=present(arg,environment()))
        	return 0;
        if(obj!=this_object()) return 0;
       
       	who=this_player(); 
                
        if(who!=obj->query("possessed")) 
        	return 0;

		if (obj->is_fighting())
        {
        	tell_object(who,"���ٻ�������ս���У��޷���ɢ��\n");	
        	return 1;
        }
        
        if (query("is_leaving")) {
        	tell_object(who,"���Ѿ�ʹ���˴˷����ˡ�\n");
        	return 1;
        }
        	
        if(who->query("sen")<300)
        {
        	tell_object(who,"�˾��ķ���Ҫ300������\n");
            return 1;
        }
        who->receive_damage("sen",300);
        message_vision(HIB"$N������������֣�һ�ƺ�����ϸ���̳�����ָ�˵���$n��\n"NOR,who,obj);
        set("is_leaving",1);
        remove_call_out("leave");
        call_out("leave",1);
        return 1;
} 


void smart_fight()
{
	object me = this_object();
	object owner = this_object()->query("possessed");
	int i,type,duration,amount;
	string typ,msg;

	if (!owner)
		return;

	if (is_busy())
		return;	

	type=owner->query_temp("last_sqpfm_used");

	switch (type)
	{
		case 2:
			typ = "drainerbolt";
			break;
		case 1:
			typ = "feeblebolt";
			break;
		case 3:
			typ = "netherbolt";
			break;
		default: 
			typ = "netherbolt";
	}


	ccommand("cast "+typ);
	return;
}

void invocation(object who, int level)
{
	int i, bonus_skill;
	object *enemy,*pros;

	int exp = 20000 + level/8*level/2*level/2 *33/20;

	if (exp > who->query("combat_exp"))
		exp = who->query("combat_exp");
		
	exp = exp/100 * (100 + F_ABILITY->check_ability(who,"shangjun_add"));
	
	set("combat_exp", exp);
	set("level", F_LEVEL->get_level(query("combat_exp")));

	set("class","taoist");

	set_skill("sword", who->query_skill("sword",1));
	set_skill("parry", who->query_skill("parry",1));
	set_skill("dodge", who->query_skill("dodge",1));
	set_skill("move", who->query_skill("move",1));
	set_skill("spells", who->query_skill("spells",1));
	set_skill("force", who->query_skill("force",1));
	set_skill("unarmed", who->query_skill("unarmed",1));
	set_skill("scratching", who->query_skill("scratching",1));

	set_skill("notracesnow",who->query_skill("notracesnow",1)+1);
	set_skill("snowshade-sword",who->query_skill("snowshade-sword",1)+1);
	set_skill("necromancy",who->query_skill("necromancy",1)+1);
	set_skill("gouyee",who->query_skill("gouyee",1)+1);
	set_skill("tenderzhi",who->query_skill("tenderzhi",1)+1);
	set_skill("scratmancy",who->query_skill("scratmancy",1)+1);

	map_skill("dodge","notracesnow");
	map_skill("move","notracesnow");
	map_skill("spells","necromancy");
	map_skill("force","gouyee");
	map_skill("unarmed","tenderzhi");
	map_skill("parry","hunting-fork");
	map_skill("sword","snowshade-sword");
	map_skill("scratching","scratmancy");

	set("chat_chance_combat",level/6+random(level/6));
	"/feature/nada"->reset_npc(this_object());
	set("max_kee",who->query("max_kee")*5/10);
	set("max_gin",who->query("max_gin")*5/10);
	set("max_sen",who->query("max_sen")*5/10);
	set("force_factor",0);
	set("str",level/10);

	if (who->query_skill("taoism",1)>200) 
		add("resistance/kee", (who->query_skill("taoism",1)-200)/2);
			
	full_me();
	
	message("vision",
		CYN "\n
��ͥ��ͻ���ӹ�����������һλ���ˣ�����������������޶��£��ֳ�
һ��������������Ի������λ���֣���������һ��֮����
˵��������
"+poet[random(5)]+"    ����"+name()+CYN"��Ҳ��\n" NOR,
		environment(who), this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else {
				enemy[i]->kill_ob(this_object());
				enemy[i]->kill_ob(who);
			}	
		}
	}
	set_leader(who);
	set("possessed",who);
	reset_action();
}


void unconcious() {
	die();
}

void die()
{
	object *pros,owner,*enemy;
	int i;
        if(objectp(owner=this_object()->query("possessed")))
        {
            if (owner->query_temp("max_guard")>0)
              	owner->add_temp("max_guard",-1);
			
			// backfire a little bit hate to prevent chain pets.
			enemy = query_enemy();
			if (enemy && sizeof(enemy)>0){
				for (i=0;i<sizeof(enemy);i++){
					if (!userp(enemy[i]))
						enemy[i]->add_hate(owner,enemy[i]->query_hate(this_object()));
				}
			}
	}                
    message_vision("\n$N����һ��������ʧ�ˡ�\n\n", this_object());
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



/*

������     /��              ��\      
������   ��   �ܣߣߡ�������  ��       
������   �� ����    ���������v��       
������    �M                  ��       
������    ��   /��\    /��\   ��      
������    ��   ����    ��  �� ��       
������   ��    \ /    \��/    ��      
������    ����      ��      ���M         
������    ���v��    ��   ������         
������    �q������������������           
������   ��   ��           /���\����    
������  ��____��  �� ��  �� .. ����     
������        \���/ ����ܡ�         
                       ��             
����������������- FengYun - ������
 ��������������annie 06.2005
 ��������dancing_faery@hotmail.com

*/
