
inherit NPC;

void create()
{
        set_name("��ʦ", ({ "biao shi"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "����һλ�ߴ����ߵ���ʦ��\n");
        set("combat_exp", 70000);
        set("attitude", "friendly");
        
        set_skill("hammer", 100);
	set_skill("dodge", 100);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "��ʦ�ֽ����е�ʯ��һ�����������߰�ʮ�¡�\n",
                "��ʦ�������Լ���׳�ĸ첲�����������£�����¶������֮ɫ��\n",
        }) );
	
	setup();
        carry_object(__DIR__"obj/jinzhuang")->wear();
	carry_object(__DIR__"obj/stonehammer")->wield();
}

