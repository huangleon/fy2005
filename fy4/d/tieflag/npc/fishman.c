#include <ansi.h>
inherit NPC;  
void create()
{
        set_name("���", ({ "fishman" }) );
        set("gender", "����");
        set("age", 52);
		set("long",
		"����һ��������˪�������\n");
		set("combat_exp", 5000);
		set("attitude", "friendly");
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

