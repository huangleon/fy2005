// beggar.c

inherit NPC;

void create()
{
        set_name("����", ({ "huajiang" }) );
        set("gender", "����" );
        set("age", 33);
        set("long", "һ���������ڽ�������԰�Ļ�����\n");
        set("combat_exp", 45000);
        set("str", 27);
        
	set("attitude", "friendly");
        ;
        set("chat_chance", 1);
        set("chat_msg", ({
		"�������𻨺���С�ĵ�����Ʒĵ���Ͻ�ˮ\n",
                (: random_move :)
        }) );
        set("inquiry", ([
                "���ϰ˽�" : "Ŷ�����Ƕ�ס�ںɻ�����\n",
		"����ѩ" : "������������հǳ��ˣ�\n",
		"xue" : "��������ĺ����࣬���Լ���������綼���ܼ���\n",
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
}
