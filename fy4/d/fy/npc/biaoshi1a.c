
inherit NPC;

void create()
{
        set_name("������", ({ "tangzi shou", "tangzi"}) );
        set("gender", "����" );
        set("age", 32);
        set("long", "����һλ��̬��ӯ�������֡�\n");
        set("combat_exp", 50000);
        set("attitude", "friendly");
        set("NO_KILL",1);
        set_skill("unarmed", 90);
		set_skill("dodge", 100);
		set_skill("parry", 100);
		set_skill("move",800);
		set_skill("changquan",100);
		map_skill("unarmed","changquan");
		set("chat_chance", 1);
        set("chat_msg", ({
                "������˵������������⵶ͷ����Ѫ�����ӡ�\n",
                "������˵���⼸��·�ϲ�̫ƽ��ǧ��Ҫ���²źá�\n",
                "������˵�����ӱ�����ô���꣬��ûɱ�����ء�\n",
        }) );
	
		setup();
        carry_object(__DIR__"obj/jinzhuang")->wear();
}

void die(){
	object ob;
	
	if (ob = present("li biaotou",environment()))
		ob->add_temp("bandit/biaotou",1);
	
	::die();
}