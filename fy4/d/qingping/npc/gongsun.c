// XXder@fy3
#include <ansi.h>
inherit SMART_NPC;
void create()
{
	set_name("���ﲻ��" , ({ "buzhi", "gongsun buzhi", "gongsun" }) );
	set("long", "����������С�������ڹ��ļơ�\n");
	set("attitude", "friendly");

	set("age", 30);
        set("gender", "����" );
        create_family("��ƽɽׯ", 1, "������");
	set("combat_exp", 130000);
	set("class","shenshui");
	
	set_skill("dodge", 199);
        set_skill("unarmed", 80);
        set_skill("sword", 65);
        set_skill("qingpingsword", 60);
        set_skill("force", 60);
        set_skill("qingpingforce", 55);
        set_skill("chaos-steps", 54);
        set_skill("parry",50);
        
        map_skill("sword", "qingpingsword");
        map_skill("force", "qingpingforce");
        map_skill("dodge", "chaos-steps");
        map_skill("parry","qingpingsword");
	
		set("perform_busy_w", "shenshui/sword/qingpingsword/fengzijue");
	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(100) :),
        }) );

	setup();
	carry_object(__DIR__"obj/cloth")->wear();
        carry_object("/obj/weapon/sword")->wield();
}
