// XXDER@FY
inherit NPC;
void create()
{
	set_name("���" , ({ "yaner", "yan er", "girl" }) );
	set("long", "һλʮһ�����СѾͷ��������Ū���ϵ�һ���ݱ����ơ�\n");
	set("attitude", "friendly");

	set("age", 11);
        set("gender", "Ů��" );
	set("combat_exp", 5000);
	set_skill("dodge", 50+random(50));
	setup();
	carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/mazha");
}
