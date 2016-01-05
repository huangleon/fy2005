inherit NPC;
inherit F_VENDOR;

int tell_him();

int annie_drug()
{
	object me = this_player();


	if (me->query_temp("annie/find_herb/����") && me->query_temp("annie/find_herb/������") && me->query_temp("annie/find_herb/��С��") && me->query_temp("annie/find_herb/����") && me->query_temp("annie/find_herb/����ѩ") && me->query_temp("annie/find_herb/Ҷ��ʿ")	)
	{
		message_vision(query("name")+"�ɵ�����Ҷ���֪�����ǡ����ǡ���\n",me);
		message_vision(query("name")+"ͻ��һ��ͷЦ�����㿴������ԣ���������÷��������\n",me);
		return 1;
	}


	if (me->query_temp("annie/find_herb/������"))
	{
		message_vision(query("name")+"ҡͷ������ίʵ���ǵ��ˡ�\n",me);
		return 1;
	}
	message_vision(query("name")+"Ц�����ǲ����ǡ��������ǡ���\n",me);
	message_vision(query("name")+"ͻ����ü���������Լ��Ķ�ͷ��һ�ֲ�����\n",me);
	message_vision(query("name")+"����ȥһ���Ӳ����˶�ʮ�꣬̾���������ˣ����ˡ���\n",me);
	message_vision(query("name")+"˵������٢�����������ҽ��������������������ﹺ�����̲ݣ���ȥ���ʰɡ�\n",me);

	me->set_temp("annie/find_herb/������",1);
	return 1;
}

void create()
{
        set_name("������", ({ "zyc" }) );
        set("gender", "����" );
	set("title","��ҩ��");
        set("age", 42);
        set("long", "
����һλ����������ɽ,������ҩΪ����������С�����̤��������ɽ,����
����ٲݡ����ڳ������,������Щ�Ź�,����ҽҩ֮����������֪��������
�Ƹ��־�֢�ĸ��֡�ü�������ԼԼ͸��һ˿����,�·���˼����ʲô��\n");
        set("combat_exp", 100000);
        set("attitude", "heroism");
        
        set("skill_public",1);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
	set_skill("dodge", 100);
    	set_skill("herb",100);
    	
    	set("inquiry", ([
        	"���̲�" : 	(: annie_drug :),
	        "zhishang" : (: tell_him :),
	        "����" : (: tell_him:),
		"cure" : (: tell_him :),
        ]));
        set("chat_chance", 1);
        set("chat_msg", ({
	"��ҩ�ɼ�����ҩ���ƺ���û��ע����ĵ�����\n",
        }) );
        set("vendor_goods", ([
		"/obj/medicine/herb_a1" : 30,
		"/obj/medicine/herb_a2" : 30,
		"/obj/medicine/herb_a3" : 30,
		"/obj/medicine/herb_a4" : 30,
		"/obj/medicine/herb_a5" : 30,
		"/obj/medicine/herb_b1" : 30,
		"/obj/medicine/herb_b2" : 30,
		"/obj/medicine/herb_b3" : 30,
//		"/obj/medicine/herb_c1" : 30,
//		"/obj/medicine/herb_c2" : 30,
//		"/obj/medicine/herb_c3" : 30,
//		"/obj/medicine/herb_d1" : 30,
//		"/obj/medicine/herb_d2" : 30,
//		"/obj/medicine/herb_d3" : 30,
//		"/obj/medicine/herb_annie_buff1" : 30,
//		"/obj/medicine/herb_annie_buff2" : 30,
//		"/obj/medicine/herb_annie_buff3" : 30,
//		"/obj/medicine/herb_annie_buff4" : 30,
//		"/obj/medicine/herb_annie_buff5" : 30,
//		"/obj/medicine/herb_dcq" :30,
//		"/obj/medicine/herb_f1" : 30,
//		"/obj/medicine/herb_f2" : 30,
		
	]) );
	setup();
	add_money("coin", 1);
        carry_object("/obj/armor/cloth")->wear();
}

void init()
{	
	::init();
	add_action("do_vendor_list", "list");
}


int tell_him()
{
	object me;
	me =this_player();
	if(!me->query("attr_apply")) {
	message_vision("$N����$n���������û���˵���ǣ�Ƥ����ȥ��Щ���ϰ�ҩ�Ϳ����ˡ�\n",
			this_object(),me);
	return 1;
	} else {
	message_vision("$N����$n���������˿ɲ���ѽ�������ε���û�к�̶����ҩ����\n",
                        this_object(),me);
	}
}



int recognize_apprentice(object ob)
{
	command("say �ȣ������ˣ�ǰ�����и����������ʲô�һ�������˵��������Ϲ��ͷ�������ҵ�������\n");
	return 0;
}
		
	
/*	if(ob->query("free_learn/herb"))
	return 1;
        else {
                if (!random(2)) {
                command ("say ��ѧҩ�����Ȱ��������£�һֱ��˵�и��ڴ�ҩ�ͣ����ܲ���������һ������\n");
                } 
		return notify_fail("\n");
	}
}

int accept_object(object who, object ob)
{	
	if (ob->query("name")=="�ڴ�ҩ��")
	{
		message_vision("$N��Ц��һ̯��˵��С�϶�����ĺڴ�ҩ�Ͷ��ѳ�ɽ�ˡ�\n",this_object());		
		message_vision("$N˵���������һ���Ҫ��̶����ҩ�������ܲ���������һ�£�\n",this_object());
		return 0;
	}	
	if (ob->query("name")=="��̶��")
	{
		if (who->query_temp("well_frog")) {
			message_vision("$NЦ�Ǻǵ�˵���ã��á�\n",this_object());		
			message_vision("$N˵����ѧ�ҵ�ҩ����û���⡣\n",this_object());
			who->set("free_learn/herb",1);
			return 1;
		} else 
			{
			ccommand("say �ⲻ�����ҵ��İɣ��Ұ����鲻��Ҫ��·�����Ķ�����");
			return 0;
			}
	}	

}*/