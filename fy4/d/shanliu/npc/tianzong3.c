// ashui.c

inherit NPC;

#include <ansi.h>
void create()
{
		set_name("������", ({ "tianwu yan","yan" }) );
		set("gender", "����" );
		set("age", 31);
        set("title","����"+HIC" ����̿�"NOR);
		set("long","���ϡ��㲣��ƺ����ϸ����͵����ˡ�\n" );
        set("chat_chance", 1);
        set("chat_msg", ({
            "��������������Ҫɱ���ˣ�\n",
            "���Ժٺ���Ц����˭�����������᣿��һ����������\n",
            "����̾�˿�������ɱ�������Σ��������߾��簡��\n",    
        }) );
		set("combat_exp", 2000000);
		set("attitude", "friendly");
	
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
	//command("cry");
	message_vision("\n$N����Х�����Ҿ�������֮��.,�������Ŀ��!�һ����ٻ�����.\n", this_object());
	message_vision("˵�꣬����һ������ȥ��\n", this_object());
	//this_object()->move("/d/fy/church");
	//create();
	destruct(this_object());
}