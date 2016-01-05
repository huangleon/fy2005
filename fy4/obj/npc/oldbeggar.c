// TIE@FY3
inherit NPC;
void create()
{
        set_name("����ؤ", ({ "old beggar","beggar" }) );
        set("gender", "����" );
        set("age", 53);
        set("long", "һ��������˪֮ɫ������ؤ��\n");
        set("combat_exp", 4000);
	create_family("ؤ��", 12, "����");
	set("title","ؤ��һ������");
	
	set("class","beggar");
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "����ؤ˵�������ĵĴ�ү�ġ� ����Ҫ���ļ���Ǯ�ɡ�\n",
                (: random_move :),
        }) );
              
       	set_skill("begging",150);
        
        setup();
        carry_object(BOOKS"force_11");
        carry_object("obj/armor/cloth")->wear();
}


int accept_object(object me, object obj)
{
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) + "��������һ�����кñ��ģ�");
        return 1;
}

int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + "������С������뿪��\n");
        return 0;
}
 
void init()
{
	object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}

void greeting(object ob)
	{
		command("beg silver from "+ob->get_id());
	}
