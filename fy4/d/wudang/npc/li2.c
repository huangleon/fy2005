inherit NPC;
#include <ansi.h>
void smart_fight();
void smart_attack();


void create()
{
        set_name("���໪", ({ "li ehua" }) );
        set("gender", "Ů��");
        set("age", 25);
        set("title",HIY"��������"NOR);
        set("nickname",HIG"���ڽ���"NOR);
        set("long",
"һ����������Ů�����Ű��£�ӭ�����������һ���������������ᡣ
�ഫ���������������۵Ĺ��ŵ��ӣ�һ��̫�����������޵У���Ƿֻ
�ǻ����ѡ�˫����赣��������˵���ɵ��ߴ����������Ͻ��ݡ�����
�������Ŵ�ѩ������������ý���֮�������ſ�˼���գ���Ի�����似
�ۣ�������и�ɻ���Ψ��ƾ���������������������\n\n"
);
	  
        set("attitude", "friendly");
        set("reward_npc", 1);
	set("difficulty",1);
	set("class","wudang");
        
        set("combat_exp", 1600000);        
        
         set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) ); 
        
        set_skill("perception",200);  
        set_skill("move", 120);
        set_skill("force", 120);
        set_skill("unarmed", 180);
        set_skill("sword", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("spells",100);
        set_skill("qixing",100);                         
        set_skill("taijiforce", 150);
	set_skill("five-steps",150);
	set_skill("taiji",170);
        set_skill("taiji-sword",160);
        
        map_skill("spells","qixing");
        map_skill("unarmed","taiji");
        map_skill("force", "taijiforce");
        map_skill("dodge","five-steps");
        map_skill("move","five-steps");
        map_skill("parry","taiji-sword");
        map_skill("sword","taiji-sword");
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup();

        carry_object(__DIR__"obj/heavysword")->wield();
	carry_object("/obj/armor/cloth")->wear();
}

 
void init()
{
        object ob;
        ::init();
	add_action("do_killing","kill");
}

int do_killing(string arg)
{
    object player, victim;
    string id;
    int sen;

    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
                return notify_fail("����û������ˡ�\n");
    if(living(victim))
    {
        id= victim->query("id");
        if( id == "li zhihua" && player->query("combat_exp")>3400000)
        {
            message_vision(
"$N߳����ǿ������,��������,�����ǽ���\n", this_object());
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            return 0;
        }
    }
    return 0;
}

smart_fight()
{
	int j,i;
	object *enemy, who;
	who = this_object();
	enemy = this_object()->query_enemy();
	
	for(j=0;j<sizeof(enemy);j++)
	{
		if (enemy[j]->is_zombie() && random(2))
		{	who->cast_spell("zombie-bolt");
			return;
		}		
	}
	who->smart_attack();
	return;
}

smart_attack() {
	if (this_object()->query_temp("weapon"))
		this_object()->perform_action("sword.chanzijue");	
		else this_object()->perform_action("unarmed.nianzijue");	
	return;
	}
