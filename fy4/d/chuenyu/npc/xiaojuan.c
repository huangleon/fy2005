// xiaojuan.c

inherit NPC;

void create()
{
	set_name("С��", ({ "xiao juan","juan" }) );
	set("title", "��Ů");
	set("gender", "Ů��" );
	set("age", 16);
	set("str", 1);
	set("per", 30);
	set("long", @LONG
С������������������ũ�Ķ���Ů������ʮ���꣬�˳���Ư���ִ󷽡�
��������ϴ���ѡ���Ҳ�������̸̸(talk)��
LONG
);
	set("combat_exp", 1);
	set("attitude", "friendly");
/*        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
		"���� û�ϵ������Щ������һ��ģ�\n",
	}) );*/

	setup();
	carry_object(__DIR__"obj/pink_cloth")->wear();
}


int accept_fight(object me)
{
	command("say СŮ�����������Ķ��֣�");
	return 0;
}


void init()
{
        add_action("do_contact", "talk");
}

int do_contact(string arg)
{
        write(" С��ҲŤ��ͷ������������΢Ц����¶������ǳǳ�ľ��Ѷ���\n");
	command( "say  ������������ѽ��");
        call_out("kidnaping", 10);
        return 1;
}

void kidnaping()
{
        object room;
        if( room = find_object(AREA_CHUENYU"sunnyroad"))
        	room->set("exits/north",AREA_CHUENYU"base_b_mtn");
        else 
        	return;
        message("vision", " ͻȻ�䣡 �ӱ���ܳ�������������������С�ꡭ�� \n", room );
        message("vision", " ������������Ц�����������������е������ˡ��� \n", room );
        message("vision", " С�������������ţ�����߽��ţ�������������������\n ", room);
        message("vision", " �����˽�С��װ��󲼴��������ɽ��ȥ��\n", room );
	destruct( this_object());
}

