#include <ansi.h>

inherit NPC;
//void backattack();
void create()
{

	set_name("����", ({ "shiwei" }) );
	set("long", "����һλ��͢�Ĵ������������ӳ�͢���ٵ�ָ�ӡ�\n");
	set("attitude", "friendly");
	set("title","��͢ ��Ʒ��������");
	set("class","baiyun");
	set("max_atman", 100);
	set("atman", 100);
	set("max_mana", 100);
	set("mana", 100);
	set("no_fly",1);
	set("no_arrest",1);
	set("combat_exp", 100000);
	
	set_skill("sword", 70);
	set_skill("parry", 70);
	set_skill("dodge", 70);
	set_skill("move", 70);
	set_skill("feixian-steps",70);
	set_skill("feixian-sword",70);
	set_skill("changquan",70);
	set_skill("unarmed",70);
	map_skill("unarmed","changquan");
	map_skill("sword","feixian-sword");
	map_skill("parry","feixian-sword");
	map_skill("dodge","feixian-steps");
	map_skill("move","feixian-steps");

	setup();

	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/weapon/sword")->wield();
}

void leave()
{
	object owner,*pros;
	if (environment())
		message("vision",name() + "����������ʧ�����ˡ�\n" , environment(),	this_object() );
    if(objectp(owner=this_object()->query("possessed")))
        {
                owner->add_temp("guard_count",-1);
                pros = owner->query_temp("protectors");
			pros -= ({ this_object() });
		owner->set_temp("protectors",pros);
	}
	// Remove all buffs to clean up annied
	ANNIE_D->debuff(this_object(),"all");                
	destruct(this_object());
}


void init()
{
	::init();
	if( !query_heart_beat(this_object()) ) set_heart_beat(1);
	add_action("do_kill","kill");
	add_action("do_dismiss","dismiss");	
}

void heart_beat()
{
	object leader;
	
	::heart_beat();

    if(!this_object()) 		return;
    if (!environment())		return;
        		
	if(query_temp("is_unconcious")||is_busy())
		return ;
		
	if(query("possessed"))
	{
		leader=query("possessed");
		if(environment(leader)!=environment()&&(!leader->is_ghost()))
		{
			message_vision("$N�Ҵ���ȥ��\n",this_object());
			move(environment(leader));
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

int do_dismiss(string arg)
{
	object who,obj;
	
	if(!arg) return 0;
	if(!obj=present(arg,environment()))
		return 0;
	if(obj!=this_object()) return 0;
	who=this_player();
	if(who!=query("possessed")) return 0;
	if (obj->is_fighting())
    {
    	tell_object(who,"��ʿ������ս���У��޷���ɢ��\n");	
    	return 1;
    }	
	
    if (query("is_leaving")) {
    	tell_object(who,"�û����Ѿ�����ɢ�ˡ�\n");
    	return 1;
    }
    
	if(who->query("sen")<200)
	{
		tell_object(who,"������񲻹����޷��Ա�ʿ�����\n");
		return 1;
	}
	who->receive_damage("sen",200);
	
	message_vision("$N��$n˵���������ﲻ��Ҫ���ˣ���ȥ�ɡ�������\n",who,obj);
	obj->ccommand("inn "+who->query("id"));
	set("is_leaving",1);
	remove_call_out("leave");
	call_out("leave",1);
	return 1;
}


int do_kill(string arg)
{
	object victim,who;
	
	who=this_player();
	if(!arg) return 0;
	if(environment()->query("no_fight"))
		return 0;
	victim=present(arg,environment());
	if(!victim) return 0;
	if( !victim->is_character() || victim->is_corpse() )
		return 0;
	
	if (query("possessed"))
	if (!COMBAT_D->legitimate_kill(query("possessed"), victim))	return 0;
	
	if(victim==who) return 0;
	if(victim->query("possessed")==who && victim->query("id")=="shiwei")
	{
		tell_object(who,"�㲻��ɱ�Լ��Ļ����������»�������µġ�\n");
		return 1;
	}
	if(victim==query("possessed") && victim->query("possessed")==query("possessed"))
	if(who->query("vendetta_mark")!="authority")
	{
		message_vision("$N�ȵ������󵨷�ͽ����Ȼ�ҼӺ���͢���٣�����\n",this_object());
		kill_ob(who);
	}
	if(who==query("possessed")&&victim->query("vendetta_mark")!="authority")
	{
		message_vision("$N��"+victim->query("name")+"�ȵ������󵨷�ͽ�������������־��ܣ���\n",this_object());
		kill_ob(victim);
	}
	return 0;
}

string *lname = ({
"��","Ǯ","��","��","��","��","֣","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��","ʩ","��",
"��","��","��","��","��","κ","��","��","��","л","��","��","��","ˮ","�","��","��","��","��","��","��","��","��","��",
"³","Τ","��","��","��","��","��","��","ɵ","��","Ԭ","��","��","��","ʷ","��","��","��","�","Ѧ","��","��","��","��",
"��","��","��","��","��","��","��","��","��","��","ʱ","��","Ƥ","��","��","��","��","��","Ԫ","��","��","ӯ","ƽ","��",
"��","��","Ф","��","Ҧ","��","տ","��","��","ë","��","��","��","��","��","��","��","��","��","��","̸","��","é","��",
"��","��","��","��","��","ף","��","��","��","��","��","��","��","��","֧","��","��","��","¬","Ӣ","��","��","˾��",
"�Ϲ�","ŷ��","�ĺ�","���","����","����","����","�ʸ�","ξ��","����","�̨","����",
"����","���","����","����","̫��","����","����","����","ԯ��","���","����","����",
"����","Ļ��","˾ͽ","ʦ��","��","��ľ","����","����","���","����","����","����",
"��ֺ","�й�","�׸�","����","����","�ַ�","��۳","Ϳ��","��ǧ","����","����","�Ϲ�",
"����","�麣","����","΢��","��","˧","��","��","��","��","��","��","����","����","����","����",
    });


void invocation(object who, int level)
{
	int i,hp,str,base;
	object *enemy,*pros;
	
	set_name(lname[random(sizeof(lname))]+"����",({ "shiwei"}) );
	set("combat_exp",100000 + who->query("combat_exp")*3/4);
	set("level", F_LEVEL->get_level(query("combat_exp")));	// around 110 cap
	
	"/feature/nada"->reset_npc(this_object());

	hp = 500 + who->query("max_kee")/2
		+ who->query("max_kee")* F_ABILITY->check_ability(who,"huwei_add")/100;
	set("max_kee",hp);
	
	if (hp> 2000) hp = 2000;	// weakness
	set("max_sen",hp/2);
	set("max_gin",hp/2);
	
	str = query_str();
	delete("force_factor");
	set("str",str/2);
	
	// level = 400 maxium for shiwei			
	base = level /4;	
	set_skill("sword", 30 + base);
	set_skill("parry", 30 + base);
	set_skill("dodge", 30 + base);
	set_skill("move",  30 + base);
	set_skill("unarmed", 30 + base);
	set_skill("feixian-steps",5+who->query_skill("puti-steps",1)/2);
	set_skill("feixian-sword",5+who->query_skill("yue-spear",1));
	set_skill("changquan",5 + who->query_skill("changquan",1));
	
	full_me();
	
	set("possessed",who);
	pros = who->query_temp("protectors");
	if(sizeof(pros))
		pros += ({ this_object() });
	else
		pros = ({ this_object() });
	who->set_temp("protectors",pros);
}


void die()
{
	object owner,*pros;
        if(objectp(owner=this_object()->query("possessed")))
        {
                owner->add_temp("guard_count",-1);
                pros = owner->query_temp("protectors");
			pros -= ({ this_object() });
		owner->set_temp("protectors",pros);
	}
	message_vision("\n$N�ҽ�һ�������ڵ��϶����ˡ�\n\n", this_object());
	destruct(this_object());
}



int attack()
{
	object opponent,owner;
	int exp,extra;	        

     opponent = select_opponent();
     if(objectp(opponent)) {
     	set_temp("last_opponent", opponent);
		owner=query("possessed");
		if(opponent==owner)
		{
			this_object()->ccommand("ah");
			message_vision("$N��$n˵��������֪�Ǵ��ˣ�С�˸ղŶ��ð���ˣ��������ˡ���\n",this_object(),owner);
			this_object()->ccommand("escape");
			leave();
			return 1;
		}
	
		exp=opponent->query("combat_exp");               		
		if (objectp(owner))
			extra = owner->query_skill("leadership",1);
		else
			extra = 1000;		// Some NPC ?
		
		if(random(extra)) 
			COMBAT_D->fight(this_object(), opponent);
		else	if(random(exp)>this_object()->query("combat_exp"))
        	{
 				message_vision("$N�����������������ƴ󣬻��Ǳ���Ϊ�Ȱɡ���\n",this_object());
 				this_object()->ccommand("escape");
 				leave();
             }
       return 1;
     } else
     	return 0;
}
