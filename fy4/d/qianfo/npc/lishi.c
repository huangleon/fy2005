inherit NPC;
void create()
{
        set_name("��ʿ", ({ "lishi","��ʿ" }) );
        set("gender", "����" );
        set("class", "bonze");
        set("str", 26);
        set("long", "��ò��ΰ������ŭ�࣬�ϰ�����㣬�����ſ����ʽ���״��\n");
        set("combat_exp", 26000);
        set("attitude", "friendly");
        
	set("no_shown",1);
        
        set_skill("unarmed", 500);
        set_skill("dodge", 60);
        setup();
        carry_object(__DIR__"obj/hat");
        carry_object(__DIR__"obj/staff");
}

