//XXder@fy3
#include <ansi.h>
inherit SMART_NPC;
void create()
{
	set_name("Ī����" , ({ "buqu", "mo buqu", "mo" }) );
	set("long", "��ƽ���͵Ĵ���ӡ�\n");
	set("attitude", "friendly");
	set("age", 30);
        set("gender", "����" );
        create_family("��ƽɽׯ", 1, "����");
	set("combat_exp", 1200000);

		set_skill("dodge", 150);
        set_skill("sword", 160);
        set_skill("parry",120);
        set_skill("qingpingsword", 150);
        set_skill("force", 160);
        set_skill("qingpingforce", 150);
        set_skill("chaos-steps", 150);

        map_skill("parry","qingpingsword");
        map_skill("sword", "qingpingsword");
        map_skill("force", "qingpingforce");
        map_skill("dodge", "chaos-steps");

		set("perform_busy_w", "shenshui/sword/qingpingsword/fengzijue");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );
        
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}
