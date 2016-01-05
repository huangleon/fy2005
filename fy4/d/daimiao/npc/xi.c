#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("������", ({ "xi wei", "xi"}) );
        set("title",YEL"�������"NOR" �廤��֮ ");
        set("gender", "����" );
        set("age", 32);
        set("long", "
������̸��ֽ���������������ϣ��Ľ�գ�����ͭ�����廤����
����������������֮һ����������������ΧѲ������\n");
        set("combat_exp", 5600000);
        set("attitude", "friendly");
        set("reward_npc",1);
        set("difficulty",2);
        set("group", "demon");
        set("vendetta_mark","demon");
        
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     	(: auto_smart_fight(30) :),
        }) );
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "����������ȵ�������Ŀ����\n",
                "����������ȵ���վס����������ƣ� û���ƾ�����Ѫ��������\n",
        }) );
	
	setup();
	auto_npc_setup("wang",200,180,0,"/obj/weapon/","fighter_w","illusionstick2",4);
	carry_object("/obj/weapon/staff")->wield();
	carry_object(__DIR__"obj/blackrobe",([	
    						"name":  "������",
    						"long": "һ���Ұ�ɫ�ĳ��ۣ���������һ���������֡�\n",
    						 ]))->wear();
}

void init(){
	::init();
	add_action("do_answer","answer");
}


int do_answer(string arg){
	object room;
	string *code = ({"��ӡ���","��������","��������","�°�����","�ɺ�չ��","�����躮","�ƻ�����","������̨" });
	if (this_player()->query_temp("daimiao/passwd"))
		return notify_fail(this_object()->name()+"˵�������ڵĵ��֣���ʲô��Ц����\n");
	if (this_player()->is_fighting())
		return notify_fail("�Ƚ����ǰ��ս����˵�ɣ���\n");
	if (this_player()->query_temp("daimiao/spy"))
		return notify_fail(this_object()->name()+"˵�������Ҳ£���ϧ��û�л����ˣ���\n");
	if (!arg)
		return notify_fail(this_object()->name()+"˵�����ٺ�˵�˵�С���ҿ����㣡��\n");
	if (member_array(arg,code)==-1)
		return notify_fail(this_object()->name()+"˵�����ٺ�˵�˵�С���ҿ����㣡��\n");
	if (arg != AREA_DAIMIAO"e_peidian"->pass_wd()) {
		message_vision("\n$N˫Ŀŭ���ȵ������������ļ�ϸ������������־��ܣ���\n",this_object());
		message_vision("������̵���һӵ���ϰ�$N�����ڵ�����������\n",this_player());
		message("vision",this_player()->name()+"�������ˡ�\n",environment(this_object()),this_player());
		tell_object(this_player(),"��������ر�Ѻ����һ���\n\n");
		room = find_object(AREA_DAIMIAO"w_peidian");
		if (!room) room = load_object(AREA_DAIMIAO"w_peidian");
		this_player()->move(AREA_DAIMIAO"w_peidian");
		this_player()->set_temp("daimiao/spy",1);
		this_player()->unconcious();
		return 1;
	}
	message_vision("$N����һ��˵���ã���ȥЪϢ�ɣ���Ҫ���Ž�����\n",this_object());
	this_player()->set_temp("daimiao/passwd",1);
	return 1;
}