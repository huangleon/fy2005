// XXDER
inherit NPC;
void create()
{
	set_name("����" , ({ "laner" }) );
	set("long", "����һλüĿ�����СѾͷ����������ɨ���䡣\n");
	set("attitude", "friendly");

	set("age", 13);
        set("gender", "Ů��" );
        set("chat_chance", 5);
        set("chat_msg", ({
           "��������������������������������Ҫ��ɨԺ�ӣ��� \n",
        }) );
        set("inquiry", ([
          "���": "������������������ᣬ����������Ҫ��ɨԺ�ӣ���\n",
          "bird": "������������������ᣬ����������Ҫ��ɨԺ�ӣ���\n",
        ]) );
	set("combat_exp", 5000);
	set_skill("dodge", 50+random(50));
	setup();
	carry_object("/obj/armor/cloth")->wear();
}
