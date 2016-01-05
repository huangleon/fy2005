
#include <ansi.h>

inherit SMART_NPC;
void create()
{

      set_name("����ͳ��", ({ "shiwei"}) );
	set("long", "����һλ����ר�ŵ���Ѳ��֮�������ͳ�졣\n");
      set("attitude", "aggressive");
      set("class","bat");
	
	set("no_arrest",1);
	set("combat_exp", 1000000);
	set_skill("bat-blade", 110);
	set_skill("blade", 120);
	set_skill("parry", 120);
	set_skill("dodge", 120);
	set_skill("move", 120);
      	set_skill("meng-steps",100);
      	map_skill("dodge",   "meng-steps");
      	map_skill("parry"  , "bat-blade");
      	map_skill("blade"  , "bat-blade");
    	
    	set("perform_busy_d", "bat/dodge/meng-steps/huanyinqianchong");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
        
	
	setup();

	carry_object("/obj/armor/cloth")->wear();
    carry_object("/obj/weapon/blade",
    		([	"name"	:	RED"��Ѫ��"NOR,
    			"long"	: 	"����һ�ѳ���а����ɱ���ĸֵ���\n" ])
    		)->wield();
}

void init()
{
        object ob;
        if( interactive(this_player()) && !is_fighting() && !random(3)&& this_player()->query("class")!="bat") {
 message_vision("\n$N��Ȼ��$n��ɭɭһЦ���Ҵ�������������������ô��\n",
this_object(),this_player());
	kill_ob(this_player());
        }
        ::init();
}

void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
		} 
        if (me)
        if(me->query_temp("quicksand/route_bandit") == "����")
        {
                me->set_temp("quicksand/route_notice",1);
                me->delete_temp("quicksand/route_bandit");
                tell_object(me,WHT"\n��ϲ��ƽ�������𵺵ķ˻�!\n"NOR);
                tell_object(me,WHT"�����ȥ����С���������Ϣ�ˡ�\n\n"NOR);
        }
        ::die();
}
