
#include <ansi.h>

inherit SMART_NPC;
void create()
{

    	set_name("Ѳ������", ({ "xunluo shiwei", "shiwei"}) );
	set("long", "����һλ����ר�ŵ���Ѳ��֮���������\n");
//   	set("attitude", "aggressive");
   	set("class","bat");
	
	set("combat_exp", 500000);
	set_skill("bat-blade", 80+random(100));
	set_skill("blade", 80+random(100));
	set_skill("parry", 80+random(100));
	set_skill("dodge", 80+random(100));
	set_skill("move", 80+random(100));
      	set_skill("meng-steps",100);
      	map_skill("move",	"meng-steps");
      	map_skill("dodge",   "meng-steps");
      	map_skill("parry"  , "bat-blade");
      	map_skill("blade"  , "bat-blade");
      	
		set("perform_busy_u", "bat/dodge/meng-steps/huanyinqianchong");
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );

	setup();

	carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/bblade")->wield();
}


/*void init()
{
        object ob;
        if( interactive(this_player()) && !is_fighting() && this_player()->query("class")!="bat") {
 message_vision("\n$N��Ȼ��$n��ɭɭһЦ���Ҵ�������������������ô��\n",
this_object(),this_player());
	kill_ob(this_player());
        }
        ::init();
}*/