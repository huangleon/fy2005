inherit NPC;
#include <ansi.h>

void smart_fight();
void check_fight();

void create()
{
	set_name("��ʤ��", ({ "jin bo"}) );
	set("gender", "����" );
	set("title",HIY"�������"NOR);
	set("age", 70+random(10));
	set("class","lama");        
	set("long",
		"���ø�ɮ���˴ξ��ڵ�������,��ͼһͳ���֡�\n"
		);
	set("class","lama");
        set("combat_exp", 4000000);
        set("score", 900);
        set("reward_npc", 1);
	set("difficulty",5);
		
	set("no_busy",4);
	
	set("NO_KILL","ʦ�����������ˣ��ɲ�������ɱ�ˡ�\n");	
	set("chat_chance", 0);
    set("chat_msg", ({
    	(: check_fight()	:),	            
                }) );
		  
	set_skill("iron-cloth", 200);
  	set_skill("unarmed", 200);
	set_skill("force", 200);
	set_skill("yue-strike", 170);
	set_skill("spells",200);
	set_skill("parry",200);
	set_skill("kwan-yin-spells",200);
	set_skill("jin-gang",200);
	set_skill("perception",180);
	
	map_skill("iron-cloth","jin-gang");
	map_skill("spells","kwan-yin-spells");
	map_skill("unarmed", "yue-strike");
	map_skill("force", "bolomiduo");
    	
/*        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );*/

	setup();
        carry_object(__DIR__"obj/lamacloth1")->wear();
        carry_object(__DIR__"obj/ring2")->wear();
        
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
		object fo3;
		command("say С�ӣ���������ô�����ӣ���ʦ�����Ը���ɣ�");	
		set("chat_chance",0);
		
		fo3 = present("pan deng");
		if (fo3)	fo3->set("chat_chance", 100);	
		
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