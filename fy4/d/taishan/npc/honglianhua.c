inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name(HIR"������"NOR, ({ "hong lianhua","hong" }) );
        set("gender", "����");
        set("age", 18);
        set("long",
"һ��Ǭ����С��ȴ������ֻ���۾���������ؤ���������Ÿ���ͣ���������Ц��\n"
);
        set("inquiry", ([
        ]) );
      
      	set("chat_chance", 1);
	set("chat_msg", ({
	 	"�������૵�����������һ����һ������ı����ʲô�أ���\n",
	}) );
	  
        set("attitude", "friendly");
        set("title","������ؤ");
        set("score", random(50000));
        set("reward_npc", 1);
		set("difficulty",5);
		set("class","beggar");
        
        set("combat_exp", 4000000);        
        
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
     	}) ); 		

		auto_npc_setup("wang",200,170,0,"/obj/weapon/","fighter_w","dagou-stick1",2);
        setup();
        carry_object(__DIR__"obj/bamboo_staff")->wield();
		carry_object("/obj/armor/cloth")->wear();
		if (!random(10)) carry_object(BOOKS"staff_75");
}
