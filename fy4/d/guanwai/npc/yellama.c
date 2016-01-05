inherit NPC;
inherit F_MASTER;
#include <ansi.h>


void smart_fight();
void smart_busy();
void smart_attack();


void create()
{
       	set_name("����", ({ "master yunsong", "master","yunsong" }) );
       	set("nickname", RED"��������"NOR);
	set("gender", "����" );
        set("long","
�������Ǹ��׸�ɮ�Ĺ���С���ӣ��������ڡ�������֮Ϊ�����ڵ��Ӱ�����\n");

        set("age", 32);
		set("class","lama");
	
        create_family("������", 21, YEL"���"NOR);
    	set("rank_nogen",1);
    	    	set("ranks",({"��ɮ","�޺�","���","��ɮ","����","��ʿ","��ʦ",
    		"��ʦ","��ɮ","ʥɮ","����","ʥ����",YEL"�󱦷���"NOR,
    		YEL"��»��"NOR,YEL"���ڴ���"NOR,HIY"��������"NOR}));
		set("rank_levels",({ 16000, 32000,64000, 128000,
					256000,512000,1024000,1536000,2048000,
					3064000,4096000, 5120000,6144000,8192000,
					9999999}));
		
        set("reward_npc", 1);
		set("difficulty", 2);
        
        set("chat_chance", 1);
       	set("chat_msg", ({
                "����̾�˿����������ɴ�ʦ�֣���֪��������ô���ˡ���\n",
        }) );

		set("inquiry", ([
			"������": "��....������һ������ʦ�����ɵ��ߵġ�\n",
			"����": "�����ڲ��������ǵĴ������",
		]) );
	
	set("attitude", "peaceful");
	set("combat_exp", 3500000);
	
	set_skill("staff", 150);
    	set_skill("fengmo-staff", 150);
	set_skill("unarmed", 150);
	set_skill("bloodystrike", 150);
	set_skill("force", 150);
	set_skill("bolomiduo", 150);
	set_skill("spells",150);
	set_skill("parry",150);
	set_skill("kwan-yin-spells",150);
	set_skill("perception", 100);
	set_skill("literate", 100);
	set_skill("jin-gang",150);
	set_skill("iron-cloth", 150);
	set_skill("lamaism", 150);
	set_skill("foreknowledge", 100);
	set_skill("chanting", 150);
	
	map_skill("spells","kwan-yin-spells");
	map_skill("parry","fengmo-staff");
	map_skill("unarmed", "bloodystrike");
	map_skill("force", "bolomiduo");
    	map_skill("staff", "fengmo-staff");
    	map_skill("iron-cloth","jin-gang");
    	
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
        	(: smart_fight() :),
        }) );
        
		setup();
        carry_object(__DIR__"obj/redclothh")->wear();
        carry_object(__DIR__"obj/7staff")->wield();
}



void attempt_apprentice(object ob)
{
	    if(ob->query("marry") && !ob->query("jiebai")){
			message_vision("$N΢΢Ц������ʩ���쳾���ˣ������������š���\n", this_object(), ob);
			return;
    	}	
        command("smile");
        command("say �ϟo�����oҮ���űR�ɵۡ��q����Ү�������_�ʡ�");
        command("recruit " + ob->query("id") );        
}



smart_fight()
{
	int i;
	object *enemy, who;
	who = this_object();
	if (who->is_busy()) return;
	enemy = this_object()->query_enemy();
	i = sizeof(enemy);
	if (i>2) {
		who->cast_spell("ni");
		return;
	}
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			if (enemy[i]->query_skill("iron-cloth")>300 
				|| enemy[i]->query("combat_exp")>who->query("combat_exp")) {
				who->cast_spell("an");
				switch( random(3) ) {
					case 0: command("grin");
						break;
					case 1: command("smile");
						break;
					case 2: command("smug");
						break;
					}
				return;
			}		
			this_object()->smart_attack();
			}
	}
	return;
}


smart_attack() {
	this_object()->ccommand("perform fuhu");	
	return;
}


void die()
{
    object killer, owner;
    if(objectp(killer = query_temp("last_damage_from")))
    {
    	if ( objectp(owner = killer->query("possessed")))
    		killer = owner;
    	REWARD_D->riddle_set( killer, "��������",1);
    }    	
    ::die();
}
