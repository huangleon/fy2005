// beggar.c

inherit NPC;

void create()
{
        set_name("�Ź���", ({ "gongzi" }) );
        set("gender", "����" );
        set("age", 20);
        set("long", "һ����ҡߡ�ȣ����������ļһ�\n");
        set("combat_exp", 10000);
        set("str", 27);
 		set("attitude", "friendly");
 
        set("chat_chance", 5);
        set("chat_msg", ({
"�Ź������������µĻ�������������һ�㽿������ٻӰ�������кۣ�\n",
"�Ź���ҡͷ��̾��������Ů���Ҳ²���������\n",
        }) );
        set("inquiry", ([
                "���ϰ˽�" : "Ŷ�����Ƕ�ס�ںɻ�����\n",
		"����Ů" : "�������������������ʫ֮ʱȥ������\n",
		"nu" : "�������������������ʫ֮ʱȥ������\n",
        ]) );
	set_skill("dodge",50);
	set_skill("parry",50);
	set_skill("dagger",50);
        setup();
        carry_object(__DIR__"obj/fycloth")->wear();
	carry_object(__DIR__"obj/zheshan")->wield();
}
