// weitianpeng.c
#include <ansi.h>

inherit SMART_NPC;

void create()
{
        set_name("������", ({ "wei tianpeng","wei" }) );
        set("gender", "����" );
        set("long",
                "�����磬�������������м��������й��������е���\n"
                );
        set("nickname", HIC"ŭ����ն��"NOR);
        set("attitude", "peaceful");
		set("age", 38);
        set("per", 5);
        set("combat_exp", 900000);

        set("chat_chance", 5);
        set("chat_msg", ({
                "��������������˭�ҵ�����������ү�����Ӷ�����˵�Ͱ���һ�����ˡ�\n",
                }) );

        set_skill("unarmed", 100);
        set_skill("parry", 150);
        set_skill("dodge", 100);
        set_skill("blade", 100);
        set_skill("shenji-blade",100);
        set_skill("shenji-steps",100);
        map_skill("dodge", "shenji-steps");
		map_skill("parry", "shenji-blade");
        map_skill("blade", "shenji-blade");

		set("perform_busy_d", "npc/dodge/shenji-steps/shenjimiaosuan");
		set("perform_weapon_attack","npc/blade/shenji-blade/jichulianhuan");
	
		set("chat_chance_combat", 40);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
        
        setup();
        carry_object(__DIR__"obj/heipifeng")->wear();
        carry_object(__DIR__"obj/ghostblade")->wield();
}
