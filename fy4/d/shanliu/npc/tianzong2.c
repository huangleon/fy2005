// ashui.c

inherit NPC;

#include <ansi.h>
void create()
{
		set_name("����ˮ", ({ "tianwu shui","shui" }) );
		set("gender", "����" );
		set("age", 26);
    	set("title","����"+HIR" ��Ѫ�̿�"NOR);
		set("long","һ��ƽ�����ˣ��Ƿ�Ҳ��һ����ƽ���Ĺ��£�\n" );
    	set("chat_chance", 1);
    	set("chat_msg", ({
            "��ˮ��Ȼ�������ڻ���ɽ�������滹��������\n",
            }) );
	
		set("combat_exp", 2000000);
		set("attitude", "friendly");
		set("per",100);
		set("str", 40);
		set("force",2000);
		set("max_force",2000);
		set("force_factor",50);
		set_skill("dodge",300);
        set_skill("unarmed",200);
        set_skill("sword",200);
        set_skill("fall-steps",200);
        set_skill("xiaohun-sword",200);
        set_skill("meihua-shou",200);
        set_skill("parry", 200);
        map_skill("parry","xiaohun-sword");
        map_skill("dodge","hawk-steps");
        map_skill("unarmed", "meihua-shou");
        map_skill("sword", "xiaohun-sword");
        setup();
	carry_object("/obj/armor/cloth")->wear();
    carry_object("/obj/weapon/sword")->wield();
}


void die()
{
	object ob;
	
	message_vision("\n$N����һ����ҧ���гݵ��������氳����ģ�\n", this_object());
	message_vision("$N˵�꣬����һ������ȥ��\n", this_object());
	destruct(this_object());
}