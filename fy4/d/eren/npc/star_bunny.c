#include <ansi.h>
inherit SMART_NPC;


void create()
{
	set_name("��ҩʦ",({"hu yaoshi","hu"}));
    	set("title",HIG"ʮ������֮"NOR);
	set("long", "��
ʮ�������еġ���ҩ��������׷��Բԣ�����º���ȴû�м�����һ˫
�۾���Բ�����������������޴�����顣����ͷ�󣬶�����󣬶�����
���ּ⣬�����ӵĶ��伸����ȫһģһ����ֻ��������������\n");
	set("age",33);
	set("combat_exp", 5500000);
	
	set("reward_npc",5);
	
	set("chat_chance", 1);
        set("chat_msg", ({
                "��ҩʦ���������΢Ц�š�\n"
     }) );
	
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        	(: auto_smart_fight(30) :),    
     }) );
	
	auto_npc_setup("guardian",250,160,0,"/obj/weapon/","fighter_w","xinyue-dagger",1);
	
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/spader")->wield();
}

