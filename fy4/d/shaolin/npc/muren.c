// teacher.c

inherit NPC;

void create()
{
	set_name("ľ��", ({ "muren" }) );
	set("gender", "����" );
	set("age", 22);
	set("int", 30);
	set("long",
		"������ľ�ˣ���ʹ������ʮ��������\n"
		);
	set("attitude", "peaceful");
	set_skill("unarmed", 200);
	set_skill("force", 80);
	set("combat_exp", 90000);
	setup();
}
