// kuliman.c

inherit NPC;

void create()
{
        set_name("���", ({ "counter jumper","jumper" }) );
        set("gender", "����" );
        set("age", 22);
        set("long", "������������æ���ҵ����ڳ���װ�ػ���. \n");
        set("combat_exp", 10000);
        set("attitude", "heroism");

        set_skill("unarmed", 10);
        set_skill("parry", 10);
	set_skill("dodge", 10);
	setup();
        carry_object(__DIR__"obj/jinzhuang")->wear();
        
}
