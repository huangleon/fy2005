#include <ansi.h>
inherit SMART_NPC;

void create()
{
    	set_name("���", ({"ma feng","ma"}) );
    	set("gender", "����" );
    	set("nickname", BLU"���꽣"NOR);
    	set("title", "������ �ֶ滤��");
    	set("long", "���˵����ǲ���ɫ���������⣬����ӥ�����۾�Ҳ����ר����ʬ��أӥ��\n");
    	set("attitude", "friendly");
    	set("combat_exp", 1000000);
    	set("class","shenshui");
    	
    	set("age", 35);

    	set("reward_npc", 1);
    	set("difficulty", 2);
    
    	set_skill("sword", 100);
    	set_skill("nine-moon-sword", 150);
    	set_skill("parry", 150);
    	set_skill("dodge", 150);
    	set_skill("move", 150);
    	set_skill("nine-moon-steps",120);
    	set_skill("force",150);
    	set_skill("nine-moon-force",150);
    	set_skill("unarmed",150);
    	set_skill("nine-moon-claw",100);
    	set_skill("qingpingsword", 120);
    	
    	map_skill("force","nine-moon-force");
    	map_skill("dodge","nine-moon-steps");
    	map_skill("move","nine-moon-steps");
    	map_skill("sword", "nine-moon-sword");
    	map_skill("unarmed", "nine-moon-claw");
    		
		set("perform_busy_w", "shenshui/sword/nine-moon-sword/yanduhantan");
		set("perform_weapon_attack", "shenshui/sword/nine-moon-sword/shuanglengcanxia");
		
		set("chat_chance_combat", 20);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
    
    	set("chat_chance", 1);
    	set("chat_msg", ({
    		"��������վ�ţ��·�ľͷ��һ��������\n",
    	}) );

        setup();
        carry_object(__DIR__"obj/duansword")->wield();
        carry_object("/obj/armor/cloth")->wear();    
        if (!random(5)) carry_object(__DIR__"obj/stone_1");

}

void init()
{
    object ob;

    ::init();
    if( interactive(ob = this_player()) && !is_fighting() ) 
    {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
}

void greeting(object ob)
{   
	string where, location;
	if( !interactive(ob) || environment(ob) != environment() )
		return;
	if (!ob->query("vendetta/authority") ){
            message_vision("$N�ٺٵ�����������˽��������ĵ�ͷ���������ɣ�\n", this_object() );
      		this_object()->kill_ob(ob);
      		ob->kill_ob(this_object());
	}
   	return;
}
