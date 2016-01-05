// zhuzao.c
#include <ansi.h>
inherit NPC;

void create()
{
    	set_name("ҹ��",({"ye di","ye","di"}));
    	set("long","���ݹ�������뷢�������������ᣬ\n������������Ʈ�ݣ��ִ���һ�ֲ��ɿ���֮���ϡ�\n");
    	set("title","");
    	set("gender","����");
    	set("no_arrest",1);
    	set("age",42);

    	set("combat_exp",9500000);  
    	set("reward_npc", 1);
    	set("difficulty", 5);
    	set("no_busy",2);
	
    	set_skill("unarmed", 300);
    	set_skill("sword", 200);
    	set_skill("force", 200);
    	set_skill("parry", 200);
    	set_skill("dodge", 200);
    	set_skill("ill-quan", 200);
    	set_skill("jiayiforce", 150);
    	set_skill("tie-steps", 200);
    	
    	map_skill("unarmed", "ill-quan");
    	map_skill("force", "jiayiforce");
    	map_skill("dodge", "tie-steps");  
    
    	set("attitude", "heroism");
    
    	set("chat_chance",1);     
    	set("chat_msg",({
          	"ҹ�ۿ�����Ц��\n",
          }) );

    	setup();
    	carry_object(__DIR__"obj/sicloth")->wear();   
//    	add_money("gold", random(10));
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

int greeting(object me)
{
 
    if( !me || environment(me) != environment() ) return 1;
    
    command("say �㾹���߹��ҵ��Թ������˲����㿴���Ϸ���ط���Σ�");
    
    if (QUESTS_D->verify_quest(me,"�����Թ�"))
		QUESTS_D->special_reward(me,"�����Թ�");
    
    REWARD_D->riddle_done(me,"�����Թ�",10,1);
    
    return 1;
}
 
