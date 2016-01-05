inherit NPC;
#include <ansi.h>
void smart_fight();

void check_fight();

void create()
{
	set_name("���޸���", ({ "bo luo"}) );
	set("gender", "����" );
	set("title",HIY"�������"NOR);
	set("age", 70+random(10));
	set("class","lama");        
	set("long",
		"���ø�ɮ���˴ξ��ڵ�������,��ͼһͳ���֡�\n"
		);
	set("class","lama");
    set("combat_exp", 4300000);
    set("score", 900);
    set("reward_npc", 1);
	set("difficulty",5);
		
	set("no_busy",6);
	
	set("chat_chance", 0);
    set("chat_msg", ({
    	(: check_fight()	:),	            
                }) );
    
    set("NO_KILL","ʦ�����������ˣ��ɲ�������ɱ�ˡ�\n");	    
    set_skill("perception",180);
	set_skill("iron-cloth", 200);
  	set_skill("unarmed", 200);
	set_skill("dragonstrike", 200);
	set_skill("force", 200);
	set_skill("lingxi-zhi", 160);
	set_skill("spells",200);
	set_skill("parry",200);
	set_skill("kwan-yin-spells",200);
	set_skill("jin-gang",150);
	set_skill("move",400);
		
	map_skill("iron-cloth","jin-gang");
	map_skill("spells","kwan-yin-spells");
	map_skill("unarmed", "lingxi-zhi");
	map_skill("force", "bolomiduo");
    	
	setup();
    carry_object(__DIR__"obj/lamacloth1")->wear();
    carry_object(__DIR__"obj/ring3")->wear();
        
}

void win_enemy(object loser)
{
		object room;
		
		if (!loser || environment(loser) != environment())
				return;
				
		command( "say С�ӣ�Ҫ���ۺ�������Ƕ��£��㻹��Զ�ˡ�");
		
		if (!room = find_object("/d/songshan/talin"))
			room = load_object("/d/songshan/talin");
		
		message_vision(YEL"\n$Nһ�Ű�$n������������ȥ��\n"NOR, this_object(), loser);
		
		set("chat_chance",0);
		loser->move(room);
//		loser->unconcious();
		message_vision(YEL"��ͨһ����$N�������ŵشӾ͹���������������\n"NOR, loser	);
		
		return;
		
}


void lose_enemy(object winner)
{
		object fo2;
		command("say С�ӣ���������ô�����ӣ���ʦ�����Ը���ɣ�");	
		set("chat_chance",0);
		
		fo2 = present("jin bo");
		if (fo2)	fo2->set("chat_chance", 100);	
		
}

int accept_fight(object me)
{
       	command("say ������һ��������");
   		return 0;
}


void 	check_fight()	{
		
		object *inv, ob;
		int i;
		
		inv= all_inventory(environment());
		for (i=0;i<sizeof(inv);i++){
			if (userp(inv[i]))
			{
				ob = inv[i];
				ob->fight_ob(this_object());
				this_object()->fight_ob(ob);
				return;
			}
		}
		
		set("chat_chance", 0);
		return;
}


void  die(){
		object fo2;
		command("say ���ã���С������ͷ��ʦ��������С�ģ�");	
		set("chat_chance",0);
		
		fo2 = present("jin bo");
		if (fo2)	fo2->set("chat_chance", 100);	
			
		::die();
}	