inherit NPC;
void create()
{
        set_name("��ԯ����", ({ "san cheng" }) );
        set("gender", "����" );
        set("age", 53);
        set("reward_npc", 1);
	set("difficulty", 4);
	
        set("long", "һ���ܿ��µ�����书�߾������ٹ��أ����ۺڰ������Ľ��ף�
ֻҪ����֪������Ҫ�����ɣ������˲��ϴ�Ӧ���������죬�ͻ�ʬ���޴档\n");
        
        set("combat_exp", 4000000);
	set("attitude", "friendly");
                   
        set("chat_chance", 1);
        set("chat_msg", ({
"��ԯ����Χ����ת��һȦ�������������н����ˣ�\n",
"��ԯ����Ц���������ʮһ���治��������Ҫ�����߳ɣ�\n",
                (: random_move :),
        }) );
        set("inquiry", ([
                "��ʮһ��" : "Ŷ����Ҳ����������\n",
		"xiao 11" : "Ŷ����Ҳ����������\n",
		"ϴǮ"	  : "��ֻ�����ɡ�\n",	
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

int accept_object(object me, object ob)
{
	int value,amt;
	object painting;
	mapping paint;
	
	if(!ob->query("illegal"))
	{
	        command("grin");
	        command("say ��λ" + RANK_D->query_respect(me) + 
"����͹�����������");
        	return 1;
        }
        value=ob->query("base_value");
        amt=ob->query_amount();
        value=value*amt;
        value=value*7/10;
	command("hmm "+me->query("id"));
	command("say �����������ȥ�ɡ�");        
	painting=new(__DIR__"obj/painting");
	paint=painting->query_paint();
	painting->set("name",paint["author"]+"��"+paint["name"]);
	painting->set("long",paint["long"]);
	painting->set("real_value",value);
	painting->move(me);
	return 1;
}
        

