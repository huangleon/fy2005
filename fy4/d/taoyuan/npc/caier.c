
inherit NPC;

void create()
{
	set_name("�ʶ�", ({ "cai er" }) );
	set("gender", "Ů��" );
	set("age", 16);
	set("long",
"һ��ü��Ŀ���С��������æµ���޲���������
��˵����������һ�죬����������ץ��һ�����������С�㣬���Ծͽ����ʶ���\n");

	set("combat_exp", 100);
	set("attitude", "friendly");
	set("per",17);
	set("chat_chance", 3);
	set("title", "���Ů");
	set("chat_msg", ({
        "�ʶ��������������ϣ�������ܹ�ץ�����С�㡣��\n",
        "�ʶ���ͷ��˼��\n",
    	"�ʶ��ɿ��֯����������\n",
    }));	
	set("inquiry", ([
		"rainbow fish" : "���С����ѵ����ˣ�����һ��ˮ�Ϳ�ʼ���á�\n",
		"���С��" : "���С����ѵ����ˣ�����һ��ˮ�Ϳ�ʼ���á�\n",
	]) );
	setup();

    carry_object("/obj/armor/cloth")->wear();
    add_money("coin", 30);
}

int accept_fight(object me)
{
        command("say �����������Ķ��֣�");
        return 0;
}

