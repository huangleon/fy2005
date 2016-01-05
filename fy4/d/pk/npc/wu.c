// wulaoda.c

inherit NPC;

string ask_me();

void create()
{
	set_name("���ϴ�", ({ "wu laoda", "wu" }));
	set("gender", "����");
	set("age", 47);

        set("inquiry", ([
                "���˴���" : (: ask_me :),
                "���˱���" : (: ask_me :),
                "������"   : (: ask_me :),
                "����"     : (: ask_me :),
        ]));

	setup();
	//carry_object("/clone/cloth/cloth")->wear();
}

void init()
{
        add_action("do_sign", "sign");
        add_action("do_join", "join");
}

void unconcious()
{
        die();
}

void die()
{
        message_vision("$N���˸����磬�漴�ָ�������\n", this_object());
}

string ask_me()
{
        object me;

        me = this_player();
        if ("/adm/daemons/pk1d"->is_pking())
                return "�������˴������ھ����أ������ʲô��";

        if ("/adm/daemons/pk1d"->is_ready())
                return "�ܺã��������˴�����Ҫ��ʼ����Ҫ����ô(sign)��";

        return "���˴��������������Űɡ�Ҫ�����ģ�����Ҫ�����ȥ����(join)Ҳ�С�";
}

int do_join()
{
        if ("/adm/daemons/pk1d"->is_pking())
                return notify_fail("���ϴ��۾�һ�����ȵ��������������������أ�����Щ�˵ȵȰɡ���\n");

        if ("/adm/daemons/pk1d"->is_ready())
                return notify_fail("���ϴ�����������Ҫ����ʽ�����ͽ�ȥ���������ȵ��š���\n");

        message_vision("$N��Ц��$n�������ҽ�ȥ��������пɺã���\n",
                       this_player(), this_object());

        if ("/adm/daemons/pk1d"->join_competition(this_player()))
        {
                message("vision", this_player()->name() + "һ��С�ܽ������˳���\n",
                        environment());
                return 1;
        }

        return 0;
}

int do_sign()
{
        object me;
        string msg;
        object ob;

        me = this_player();
        message_vision("$N����Ц����$n���������ã����ã���Ҳ��ǩ��������\n",
                       me, this_object());
        if (me->query("combat_exp") < 1000)
        {
                message_vision("$ņͷ���˿�$N����м����������"
                               "��㱾�£�ֻ�òμӱ�����������\n",
                               me, this_object());
                return 1;
        }

        if (stringp(msg = "/adm/daemons/pk1d"->reject_join(me)))
        {
                command("say " + msg);
                return 1;
        }

        foreach (ob in deep_inventory(me))
                if (ob->is_character())
                {
                        command("say �㱳��˭��ȥ�������ϼҴ��ڵģ�����ҹ���");
                        message_vision("$N����һ�ţ���$n�ߵ��ڵأ�\n",
                                       this_object(), me);
                        me->receive_damage("qi", 50);
                        return 1;
                }

        message_vision("$n���ͷ����$N�������ðɣ����Ƚ�"
                       "ȥ׼���ɡ���\n$N���ͷ�������"
                       "׼������ȥ��\n", me, this_object());
        me->move("/d/pk/ready");
        message("vision", me->name() + "�����ӵ����˽�����\n",
                environment(me), ({ me }));
        return 1;
}

