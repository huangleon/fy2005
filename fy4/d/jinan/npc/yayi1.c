// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����С����", ({ "yayi", "ya" }) );
        set("long",
                "�������õ����ۣ�ǧ��Ҫ������\n");

        set("attitude", "heroism");
	set("vendetta_mark", "authority");

        set("cor", 40);
        set("cps", 25);

        set("combat_exp", 1500000);

        set_skill("unarmed", 150);
        set_skill("staff", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("move", 150);
	set_skill("fumostaff",150);
	set_skill("meihua-shou",150);
	set_skill("puti-steps",150);
	
	map_skill("dodge","puti-steps");
	map_skill("staff","fumostaff");
	map_skill("unarmed","meihua-shou");
	map_skill("parry","fumostaff");
	
        set("chat_chance", 1);
        set("chat_msg", ({
"�������۵��������������������䡫������\n"
        }) );

        setup();

        carry_object(__DIR__"obj/yafu")->wear();
        carry_object(__DIR__"obj/sawei")->wield();
}

