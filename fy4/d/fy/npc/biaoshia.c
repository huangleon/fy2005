
inherit NPC;

void create()
{
        set_name("��ʦ", ({ "biao shi"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "����һλ�ߴ����ߵ���ʦ��\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("NO_KILL",1);
        set_skill("hammer", 90);
	set_skill("dodge", 100);
	set_skill("move",800);
	set_skill("parry",100);
	set_skill("force",100);
	
        set("chat_chance", 1);
        set("chat_msg", ({
                "��ʦ˵���ڼҿ��ֵܣ����ſ����ѣ����е����ľ��ǽ��顣\n",
                "��ʦ˵����ʨ�ھ��������ӣ�������˭�����������ӣ�\n",
                "��ʦ�������Լ���׳�ĸ첲�����������£�����¶������֮ɫ��\n",
        }) );
	
	setup();
        carry_object(__DIR__"obj/jinzhuang")->wear();
	carry_object(__DIR__"obj/stonehammer")->wield();
}

void die(){
	object ob;
	
	if (ob = present("li biaotou",environment()))
		ob->add_temp("bandit/biaotou",1);
	
	::die();
}