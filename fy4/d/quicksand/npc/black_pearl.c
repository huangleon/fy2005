// TIE@FY3
inherit NPC;
int give_letter();
void create()
{
		set_name("������", ({ "black pearl", "pearl" }) );
		set("title", "��Į��ӥ");
		set("gender", "����" );
		set("age", 22);
		set("long","�ڷ�����ɴ�����ۣ���ѥ���ڱޣ������ˡ�\n");
        set("chat_chance", 2);
        set("chat_msg", ({
                "������˵����������ôת��תȥ������ɳĮ����������ſ���ô�죡\n",
        }) );

		set("inquiry", ([
			"����": (: give_letter :),
			"��": (: give_letter :),
			"letter": (: give_letter :),
			"��˭":		"�ϻ����ŷ��ϲ���д��ô��",
		]) );
	
		set("attitude", "peaceful");
	
		set_skill("whip", 100);
		set_skill("thunderwhip", 60);
		set_skill("parry",60);
		set_skill("dodge",60);
		set_skill("move",100);
		set_skill("zuixian-steps",100);
	
		map_skill("whip","thunderwhip");
		map_skill("parry","thunderwhip");
		map_skill("dodge","zuixian-steps");
		map_skill("move","zuixian-steps");
	
		set("combat_exp", 120000);
		setup();
        carry_object(__DIR__"obj/shenxue")->wear();
        carry_object(__DIR__"obj/baojia")->wear();
        carry_object(__DIR__"obj/zhiai")->wear();
        carry_object(__DIR__"obj/sidai")->wield();
}


int give_letter()
{
        object obj;
		if( !query("given"))
        {
			command("say ���ܰ�æ�������ͳ�ô���ɱ��ˣ�\n");
			obj = new(__DIR__"obj/letter");
			obj->move(this_player());
			set("given",1);
        }
		else
		{
			command("say �ף����Ƿ�����ô�����ˣ��ǲ�����͵�ˣ������ң�\n");
			fight_ob(this_player());
		}
        return 1;
}

void reset()
{
	delete("given");
}
