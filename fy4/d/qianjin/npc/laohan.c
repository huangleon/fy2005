// beggar.c

inherit NPC;

void create()
{
        set_name("�Ϻ�", ({ "laohan" }) );
        set("gender", "����" );
        set("age", 53);
        set("long", "һ�����ڷ���������������Ϻ���\n");
        set("combat_exp", 30000);
        set("str", 27);
        
	set("attitude", "friendly");
        
        
        set("chat_chance", 5);
        set("chat_msg", ({
		"�Ϻ�ͣ�����������ϵ���������������\n",

        }) );
        set("inquiry", ([
                "���ϰ˽�" : "Ŷ�����Ƕ�ס�ںɻ�����\n",
		"������" : "������������հǳ��ˣ�\n",
		"yue" : "������������հǳ��ˣ�\n",
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
}
