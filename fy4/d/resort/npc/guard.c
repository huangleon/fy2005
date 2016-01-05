inherit NPC;

void create()
{
        set_name("����", ({ "lao zhang","lao" }) );
        set("gender", "����" );
        set("age", 68);

        set("attitude", "peaceful");

        set("long","����һλ�þ���˪�����ˡ�\n");

        set("combat_exp", 200000);
        set("score", 50);
        
        set_skill("unarmed", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("literate", 100);
        set_skill("meihua-shou", 100);
        set_skill("qidaoforce", 150);
        set_skill("fall-steps", 100);

        map_skill("unarmed", "meihua-shou");
        map_skill("force", "qidaoforce");
        map_skill("dodge", "fall-steps");

	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
{
	::init();
	add_action("do_gogo", "go");
}


int do_gogo(string arg)
{
	object me;
	me = this_player();
	if( arg == "north" )
	{
	if( me->query("class") ) 
		if( me->query("class") != "legend" && me->query("family") 
			&& !me->query_temp("resort_qin")) {
		command("sigh");
		command("say ���������ڽ�����������Ī�����");
		write("��������·�����ŵ�ס�� ��\n");
		return 1;
		}
		else
			return 0;		
	}
	return 0;
}
