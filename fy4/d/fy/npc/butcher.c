// butcher.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("�����", ({ "beard butcher", "butcher" }) );
        set("title", "��������");
        set("gender", "����" );
        set("age", 35);
        set("long", "һ����������Ӻͺ���ļһ\n");
        set("str", 29);
        set("int", 14);
        set("combat_exp", 25000);
        set("attitude", "heroism");
        set_skill("unarmed", 200);
        set("vendor_goods", ([
                __DIR__"obj/yangtou": 120,
                __DIR__"obj/zhutou" : 120,
                __DIR__"obj/niutou" : 120,
        ]) );

        setup();
        carry_object("/obj/armor/cloth")->wear();

}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
	add_action("do_spare","spare");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(4) ) {
                case 2:
                        say( "������ֿ�����, Ц�ŵ�����λ"  
                                + RANK_D->query_respect(ob)
                                + "��Ҫ��������? \n");
                        break;
        }
}

 
int do_spare(string arg)
{
	object me;
	object obj;
	string file;
	me = this_player();
	if(!arg) return notify_fail("ָ�spare <name>\n");
	        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("����û��"+arg+"��\n");
	if(base_name(obj) == "/obj/npc/pet" && obj->query("owner") == me->query("id")
	&& obj->query("possessed") == me)
	{
	message_vision("$N�Դ����˵�������Ҵ����$n�����Լ����̶��֣���\n",me,obj);
	message_vision("$N����һ���������꣢һ��Ť����$n�Ĳ��ӣ�\n",this_object(),obj);
	seteuid(ROOT_UID);
	file = obj->query_save_file()+".o";
	obj->die();	
	rm(file);
	seteuid(getuid());
	return 1;
	}	
	return notify_fail("�㲻������ô����\n");
}

void reset(){
    set("vendor_goods", ([
            __DIR__"obj/yangtou": 120,
            __DIR__"obj/zhutou" : 120,
            __DIR__"obj/niutou" : 120,
    ]) );	
}
