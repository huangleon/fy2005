// 

inherit NPC;
inherit F_VENDOR;
int bamboo();
void create()
{
        set_name("С����", ({ "danfan", "dan fan" }) );
        set("gender", "����" );
        set("age", 25);
        set("long","
һ�����ŵ��ӵ���������С�������ӷ��������Եĵ�����ͷ������ɫ��Ʒ��
�����ڶ�������ʳƷ�����Ǯ��Ȼ�Թ���Щ�����Ƕ���������\n");
	set("combat_exp", 2000);
        set("chat_chance", 1);
        set("chat_msg", ({
                "С����ҡ�������еĲ��˹ġ�\n",
        }) );
		set("inquiry", ([
			"��Ͳ" : (: bamboo :),
			"zhutong" : (: bamboo :),
		]));
        set("attitude", "friendly");
        set("vendor_goods", ([
        		"/obj/food_item/dumpling" : 10,
				"/obj/food_item/chicken_leg":10,
				AREA_FY"npc/obj/yanzhi" : 3,
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();

}

void init()
{
	::init();
        add_action("do_vendor_list", "list");
}

int bamboo(){
	object me,ob;
	
	me = this_player();
	
	message_vision("\nС������ɫ���䣬����˵�������߶�����ħ�֣�����һ�٣�������ϼ�˼��ҡ�\n", me);
	message_vision("С���������������麣����һ�ۺ�ʧ�٣���ָ�������⡢�����ǵھ�ʮ�Ÿ���ͷ�ˡ�\n", me);
	return 1;
	
	/*
	if(me->query("marks/����") && environment(this_object())->query("item_bamboo")){
		message_vision("$N��$n��������Ȼ��λ" + RANK_D->query_respect(me) + "ϲ�������͸���ɡ���\n",
				this_object(), me);
		message_vision("$N��������һ��С��Ͳ�ݸ�$n��\n", this_object(), me);
		ob = new(__DIR__"obj/bamboo_cont");
		if(objectp(ob)){
			ob->move(me);
		}
		environment(this_object())->set("item_bamboo", 0);
	} else {
		message_vision("$Ņͷ����$n��������λ�͹ٻ��ǿ��������Ʒ�ɡ���\n", this_object(),me);
	}
	return 1;*/
}