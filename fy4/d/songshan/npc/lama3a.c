inherit NPC;
#include <ansi.h>

void check_fight();

void create()
{
		set_name("�̵��ڶ�", ({ "pan deng"}) );
		set("gender", "����" );
		set("title",HIY"�������"NOR);
		set("age", 70+random(10));
		set("class","lama");        
		set("long",
			"���ø�ɮ���˴ξ��ڵ�������,��ͼһͳ���֡�\n"
			);
		set("class","lama");
	    set("combat_exp", 4500000);
	    set("score", 900);
	    set("reward_npc", 1);
		set("difficulty",5);
		
		set("NO_KILL","ʦ�����������ˣ��ɲ�������ɱ�ˡ�\n");	
		set("no_busy",5);
	        	
		set("chat_chance", 0);
    	set("chat_msg", ({
    		(: check_fight()	:),	            
        }) );
        
		set_skill("iron-cloth", 200);
	  	set_skill("unarmed", 200);
		set_skill("dragonstrike", 200);
		set_skill("force", 200);
		set_skill("dragonstrike", 200);
		set_skill("spells",200);
		set_skill("parry",200);
		set_skill("kwan-yin-spells",200);
		set_skill("jin-gang",150);
		set_skill("perception",180);
		
		map_skill("iron-cloth","jin-gang");
		map_skill("spells","kwan-yin-spells");
		map_skill("unarmed", "dragonstrike");
		map_skill("force", "bolomiduo");
    	
/*        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );*/

		setup();
        carry_object(__DIR__"obj/lamacloth1")->wear();
        carry_object(__DIR__"obj/ring1")->wear();
        
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

int accept_fight(object me)
{
       	command("say ������һ��������");
   		return 0;
}

void lose_enemy(object winner)
{
		object fo1, fo2, fo3;
		
		if (!winner)	return;
			
		set("chat_chance",0);
				
		fo1 = present("jin bo");		
		if (fo1) {
			message_vision(CYN"\n$N˵�����ס����ס��϶�����ʦ��æ��\n\n"NOR, fo1);	
		}
		
		fo2 = present("bo luo");
		if (fo2) {
			message_vision(CYN"$N��Ц����˵����ɽ���ģ���ˮ���������Ǻ�����ڣ�\n\n"NOR, fo2);
		}
		
		message_vision(YEL"�̵��ڶ���ɫ���࣬һ�ﲻ����\n"NOR, winner);
		set("chat_chance",0);
		
		REWARD_D->riddle_done( winner, "��������", 50, 1);
		
		return;		
}


void die()
{
		object fo1, fo2, fo3;
		object killer;
		
		if (!objectp(killer= query_temp("last_damage_from")))
		{
			::die();
			return;
		}
		
		set("chat_chance",0);
				
		fo1 = present("jin bo");		
		if (fo1) {
			message_vision(CYN"$N���е�����ʦ�֡���ʦ�֣�һʧ�Ŵ������ϵ�����ȥ��\n"NOR, fo1);	
			
			destruct(fo1);
		}
		
		fo2 = present("bo luo");
		if (fo2) {
			message_vision(CYN"$N��Ц����˵����ɽ���ģ���ˮ���������Ǻ�����ڣ�\n"NOR, fo2);
			destruct(fo2);
		}
				
		REWARD_D->riddle_done( killer, "��������", 50, 1);
		destruct(this_object());				
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


void init(){
		object ob;
		if (interactive(ob=this_player()))
		{
			call_out("greetings", 1, ob);		
		}	
		::init();
}		
		
		
void greetings(object ob){
	
		object fo1, fo2, fo3;
		
		if (!ob || environment(ob)!= environment())	return;
			
		fo3 = this_object();
		fo1 = present("bo luo");
		fo2 = present("jin bo");
		
		if (!fo1 || !fo2) {
			command("say hmm, something is wrong");
			return;
		}
					
		command("say ������ԭ���˲��������������úܣ���ĺ��������ֵ�"WHT"�������"CYN"���ˡ�");
		message_vision(CYN"

���޸���˵���Զ�ʤ�٣�ʤ֮���䣬���ֵ�Ҳ�����ϣ���һ�����غ�����С�

��ʤ��˵��������������ս��С�������డ��

�̵��ڶ�˵���ϻ���˵�����˱��ǣ�\n\n"NOR, ob);

		fo1->set("chat_chance", 100);
}		
		
	
	