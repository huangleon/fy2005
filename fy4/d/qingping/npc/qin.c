#include <ansi.h>

inherit NPC;
void create()
{
	set_name("�ٶ�" , ({ "qiner", "qin er", "girl" }) );
	set("long", "һλʮ�������СѾͷ��\n");
	set("attitude", "friendly");

	set("age", 13);
        set("gender", "Ů��" );
        set("inquiry", ([
        ]) );

	set("combat_exp", 5000);
	set_skill("dodge", 50+random(50));
	setup();
	carry_object("/obj/armor/cloth")->wear();
        carry_object(AREA_CHUENYU"npc/obj/yellow_flower")->wear();
}
